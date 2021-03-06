/*
 * Copyright 2002-2014, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#ifndef LEXI_ARG_H
#define LEXI_ARG_H

#include <shared/bool.h>

enum arg_kind {
	ARG_CHARP,
	ARG_CHAR_NUM,
	ARG_CHAR_COUNT,
	ARG_IDENT,
	ARG_TERMINAL,
	ARG_IGNORE,
	ARG_RETURN
};

struct arg {
	enum arg_kind kind;
	struct arg *next;

	union {
		unsigned int digit;
		char *literal;
	} u;

	bool is_ref;
};

struct arg *add_arg(enum arg_kind, unsigned int);
struct arg *add_ident(char *);
struct arg *add_ref(char *);
struct arg *add_terminal(char *);
void arg_out(struct arg *, bool, int, FILE *);
struct arg *arg_index(struct arg *, int);
char *arg_first_duplicate_ident(struct arg *args);
unsigned arg_return_count(struct arg *args);

#endif

