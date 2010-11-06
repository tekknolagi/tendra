/*
 * Copyright (c) 2002-2005 The TenDRA Project <http://www.tendra.org/>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of The TenDRA Project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific, prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 */
/*
		 Crown Copyright (c) 1997

    This TenDRA(r) Computer Program is subject to Copyright
    owned by the United Kingdom Secretary of State for Defence
    acting through the Defence Evaluation and Research Agency
    (DERA).  It is made available to Recipients with a
    royalty-free licence for its use, reproduction, transfer
    to other parties and amendment for any purpose not excluding
    product development provided that any such use et cetera
    shall be deemed to be acceptance of the following conditions:-

        (1) Its Recipients shall ensure that this Notice is
        reproduced upon any copies or amended versions of it;

        (2) Any amended version of it shall be clearly marked to
        show both the nature of and the organisation responsible
        for the relevant amendment or amendments;

        (3) Its onward transfer from a recipient to another
        party shall be deemed to be that party's acceptance of
        these conditions;

        (4) DERA gives no warranty or assurance as to its
        quality or suitability for any purpose and DERA accepts
        no liability whatsoever in relation to any use to which
        it may be put.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "config.h"
#include "list.h"
#include "environ.h"
#include "flags.h"
#include "main.h"
#include "options.h"
#include "suffix.h"
#include "utility.h"
#include "path_subs.h"


/*
 * ERROR VARIABLES
 *
 * The value exit_status gives the overall status of the program. It can be
 * EXIT_SUCCESS or EXIT_FAILURE. The variable progname gives the name of the
 * program, which is used in error reports.
 */
int exit_status = EXIT_SUCCESS;
const char *progname = PROGNAME_TCC;


/*
 * Static function prototypes.
 */
static int	key_match(const char *, const char *);


/*
 * PRINT AN ERROR MESSAGE
 *
 * This routine prints an error message s (a printf-style string, which may be
 * followed by any number of arguments) of severity e (see utility.h).
 */
void
error(int e, char *s, ...)
{
	va_list args;
	char *errtype = NULL;

	va_start(args, s);

	switch (e) {
	case FATAL:
		exit_status = EXIT_FAILURE;
		errtype = "Fatal";
		break;

	case INTERNAL:
		exit_status = EXIT_FAILURE;
		errtype = "Internal";
		break;

	case SERIOUS:
		exit_status = EXIT_FAILURE;
		errtype = "Error";
		break;

	case OPTION:
		exit_status = EXIT_FAILURE;
		errtype = "Option interpreter";
		break;

	case WARNING:
		if (!warnings) {
			va_end(args);
			return;
		}
		errtype = "Warning";
		break;

	case INFO:
		errtype = "Information";
		break;
	}

	if (checker) {
		progname = PROGNAME_TCHK;
	}

	IGNORE fprintf(stderr, "%s: ", progname);
	if (errtype) {
		IGNORE fprintf(stderr, "%s: ", errtype);
	}
	IGNORE vfprintf(stderr, s, args);
	IGNORE fprintf(stderr, ".\n");
	va_end(args);

	if (e == FATAL) {
		main_end();
	}
}


/*
 * HASH TABLE
 *
 * These functions provide access to a hash table of tccenv(5) keys and values.
 * When created, the hash table is populated with tccenv keys taken from the
 * environ_optmap[] array, and flaged as tccenv-derived instead of
 * user-created.
 */
hashtable *
init_table(size_t tblsize, size_t keysize, int (*hashfcn)(const char *, size_t, size_t))
{
	size_t i;
	hashtable* ht;
	htnode *hn;
	optmap *t;

	ht = malloc(sizeof *ht);	/* XXX: check */

	ht->tblsize = tblsize;
	ht->keysize = keysize;
	ht->hashfcn = hashfcn;
	ht->node = malloc(sizeof(htnode*) * tblsize);

	for (i = 0; i < tblsize; i++) {
		ht->node[i] = NULL;
	}

	for (t = environ_optmap; t->in != NULL; t++) {
		/* initialize hash table with tccenv keys */
		hn = update_table(ht, t->in, NULL, TCCENV, NULL, -1);
	}

	return ht;
}

htnode *
lookup_table(hashtable *ht, const char *key)
{
	int hashval;
	htnode *hn;

	if (!key) {
		error(WARNING, "Looking up NULL key in tccenv hashtable");

		return NULL;
	}

	hashval = ht->hashfcn(key, ht->tblsize, ht->keysize);
	hn = ht->node[hashval];

	while (hn != NULL && !key_match(key, hn->key)) {
		hn = hn->next;
	}

	if (hn) {
		hn->flag |= READ;
	}

	return hn;
}

static int
key_match(const char *key, const char *keyfield)
{
	int i;

	if (!key || !keyfield) {
		return 0;
	}

	/* advance pointers past command chars */
	while (key && !is_alphanum(*key)) {
		key++;
	}

	while (keyfield && !is_alphanum(*keyfield)) {
		keyfield++;
	}

	for (i = 0; i < strlen(key); i++) {
		if (key[i] != keyfield[i]) {
			return 0;
		}
	}

	return 1;
}

htnode *
update_table(hashtable *ht, const char *key, const char *val, unsigned int flag,
	     const char *file, int line_num)
{
	int hashval;
	htnode *hn;

	hashval = ht->hashfcn(key, ht->tblsize, ht->keysize);
	hn = ht->node[hashval];

	/* locate matching node */
	while (hn != NULL && !key_match(key, hn->key)) {
		hn = hn->next;
	}

	/* Case 1.  Node was not found; push */
	if (hn == NULL) {
		hn = malloc(sizeof(htnode));	/* XXX: check */
		hn->flag = flag;
		hn->key = key;
		hn->val = val;
		hn->file = file;
		hn->line_num = line_num;
		hn->next = ht->node[hashval];
		ht->node[hashval] = hn;
		return hn;
	}

	/* Case 2.  Remove */
	if (!val) {
		hn->val = NULL;
		return hn;
	}

	/* Case 3.  Update with a value */
	switch (*key) {
	case '+':
		/* assignment */
		hn->val = val;
		break;

	case '>':
		/* append */
		if (hn->val) {
			hn->val =
			    string_append(hn->val, val, ' ');
		}
		hn->val = val;
		break;

	case '<':
		/* prepend */
		if (hn->val) {
			hn->val =
			    string_append(val, hn->val, ' ');
		}
		hn->val = val;
		break;

	default:
		/*
		 * This should never happen, since read_env_aux
		 * screens for this.
		 */
		error(FATAL, "Attempt to update hashtable with"
		      " invalid key %s\n", key);
	}

	return hn;
}

/*
 * Hash function. The function takes in a char * to a key, presumed to be in
 * the form of <cmd><tccenv_var>, e.g., "+AS /usr/bin/as". The hash calculated
 * skips over the leading command char, either +, <, >, or ?.
 */
int
hash(const char *key, size_t tblsize, size_t keysize)
{
	int i;
	int hashval;

	i = 1;
	hashval = 0;

	/* skip leading +, <, >, ?, / chars */
	while (key && !(is_alphanum(*key))) {
		key++;
	}

	if (!key) {
		error(FATAL, "hash operation requested on empty key");
	}

	while (*key && !is_whitespace(*key) && i < keysize) {
		hashval += (hashval * 37) + (int) *key;
		key++;
		i++;
	}

	hashval %= tblsize;
	if (hashval < 0) {
		hashval += tblsize;
	}

	return hashval;
}


/*
 * PRINT A COMMENT
 *
 * This routine prints the comments (a printf-style string, which may be
 * followed by any number of arguments) to the standard output.
 */
void
comment(int e, char *s, ...)
{
	FILE *f;
	va_list args;

	va_start(args, s);
	f = (e ? stdout : stderr);
	IGNORE fflush(f);
	IGNORE vfprintf(f, s, args);
	IGNORE fflush(f);
	va_end(args);
}


/*
 * ALLOCATE A BLOCK OF MEMORY
 *
 * This routine allocates a block of memory of size sz and returns the result.
 */
void *
xalloc(size_t sz)
{
	void *p;

	p = malloc(sz);
	if (p == NULL) {
		error(FATAL, "Memory allocation error");
	}

	return p;
}


/*
 * REALLOCATE A BLOCK OF MEMORY
 *
 * This routine reallocates the block of memory p to have size sz.
 * xrealloc(*null, sz) is equivalent to xalloc(sz).
 */
void *
xrealloc(void *p, size_t sz)
{
    void *q;

    if (p == NULL) {
	    return xalloc(sz);
    }

    q = realloc(p, sz);
    if (q == NULL) {
	    error(FATAL, "Memory reallocation error");
    }

    return q;
}


/*
 * Takes in a substitution variable as an argument, and returns its
 * corresponding value. This routine is used by the env substitution function
 * (see format_path) to map variables to paths.
 *
 * For example, input is "<TCCDIR_BASE>", and return value is
 * "/usr/local/share/". Variable lookup is prioritized:
 *
 *   a) command line args have highest priority,
 *   b) environment variables are used next,
 *   c) for a select group of variables, sane defaults are used.
 */
const char *
find_path_subst(const char *var)
{
	char *ret;
	char **subs;
	int i;

	i = 0;
	subs = PATH_SUBS;
	while (*subs) {
		if (0 == strcmp(var, *subs)) {
			if (env_paths[i] == NULL){
				error(FATAL, "The env variable <%s> is NULL.\n"
				      "Check your environment or edit your env"
				      " files", PATH_SUBS[i]);
			}
			return env_paths[i];
		}
		i++;
		subs++;
	}
	if (!*subs) {
		error(WARNING, "Expected command line option -y%s=[value]; "
		      "trying environment", var);
	}
	ret = getenv(var);

	/* XXX: Perhaps this should not be fatal? */
	if (!ret) {
		error(FATAL, "Unknown environment variable %s", var);
	}

	return ret;
}


/*
 * ALLOCATE SPACE FOR A STRING
 *
 * This routine allocates n characters of memory for use in the string memory
 * allocation routines.
 */
/* TODO: this is an unneccessary optimisation */
static char *
string_alloc(int n)
{
	char *r;
	if (n >= 1000) {
		/* Long strings are allocated space by alloc_nof */
		r = alloc_nof(char, n);
	} else {
		/* Short strings are allocated space from a buffer */
		static int no_free;
		static char *free_chars;

		no_free = 0;
		free_chars = NULL;
		if (n >= no_free) {
			no_free = 4000;
			free_chars = alloc_nof(char, no_free);
		}
		r = free_chars;
		no_free -= n;
		free_chars += n;
	}

	return r;
}


/*
 * COPY A STRING
 *
 * This routine allocates space for a copy of the string s and copies the
 * string into this space. This copy is returned.
 */
/* TODO rename to xstrdup(), move to shared/ */
char *
string_copy(const char *s)
{
	size_t n;
	char *r;

	n = strlen(s);
	r = string_alloc(n + 1);
	IGNORE strcpy(r, s);

	return r;
}


/*
 * COPY TWO STRINGS
 *
 * This routine allocates space for a copy of the string s followed by a copy
 * of the string t and concatenates the strings into this space. This copy is
 * returned.
 */
char *
string_concat(const char *s, const char *t)
{
	size_t n, m;
	char *r;

	n = strlen(s);
	m = strlen(t);

	r = string_alloc(n + m + 1);
	IGNORE strcpy(r, s);
	IGNORE strcpy(r + n, t);

	return r;
}


/*	
 * APPEND TWO STRINGS	
 *   
 * This routine allocates space for a copy of the string s followed by a copy
 * of the string t and concatenates the strings into this space, placing the
 * delimiter character between them. The copy is returned.  E.g.,:	
 *   
 * Given:    "foo" + "bar" + ':'	
 * Returns:  "foo:bar"	
 */	
 	 	
char *	
string_append(const char *s, const char *t, char delimeter)	
{	
	int n = (int)strlen(s);	
	int m = (int)strlen(t);	
	char *r = string_alloc(n + m + 2);	
	IGNORE strcpy(r, s);	
	*(r + n) = delimeter;	
	IGNORE strcpy(r + n + 1, t);	
	return (r);
}


/*
 * TEMPORARY WORK SPACE
 *
 * This variable gives a temporary work space of size buffer_size (see
 * utility.h) which is used as a scratch work area.
 */
char *buffer;
