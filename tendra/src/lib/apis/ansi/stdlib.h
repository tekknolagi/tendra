#
# Copyright (c) 2002-2005 The TenDRA Project <http://www.tendra.org/>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#
#   		 Crown Copyright (c) 1997
#   
#   This TenDRA(r) Computer Program is subject to Copyright
#   owned by the United Kingdom Secretary of State for Defence
#   acting through the Defence Evaluation and Research Agency
#   (DERA).  It is made available to Recipients with a
#   royalty-free licence for its use, reproduction, transfer
#   to other parties and amendment for any purpose not excluding
#   product development provided that any such use et cetera
#   shall be deemed to be acceptance of the following conditions:-
#   
#       (1) Its Recipients shall ensure that this Notice is
#       reproduced upon any copies or amended versions of it;
#   
#       (2) Any amended version of it shall be clearly marked to
#       show both the nature of and the organisation responsible
#       for the relevant amendment or amendments;
#   
#       (3) Its onward transfer from a recipient to another
#       party shall be deemed to be that party's acceptance of
#       these conditions;
#   
#       (4) DERA gives no warranty or assurance as to its
#       quality or suitability for any purpose and DERA accepts
#       no liability whatsoever in relation to any use to which
#       it may be put.
#
# $Id$
#

+IMPLEMENT "ansi", "stddef.h", "null" (!?) ;
+IMPLEMENT "ansi", "stddef.h", "size_t" (!?) ;
+IMPLEMENT "ansi", "stddef.h", "wchar_t" (!?) ;

+SUBSET "bottom" := {
    +TYPEDEF ~special ( "bottom" ) ~bottom ;
} ;

+CONST int EXIT_FAILURE, EXIT_SUCCESS ;
+CONST int RAND_MAX ;

+FUNC ~bottom abort ( void ) ;
+FUNC int abs ( int ) ;
+FUNC double atof ( const char * ) ;
+FUNC int atoi ( const char * ) ;
+FUNC long atol ( const char * ) ;
+FUNC ~bottom exit ( int ) ;
+SUBSET "free" := { +FUNC void free ( void * ) ; } ;
+FUNC char *getenv ( const char * ) ;
+FUNC int rand ( void ) ;
+FUNC void srand ( unsigned int ) ;

+IFNDEF __JUST_POSIX
+FUNC double strtod ( const char *, char ** ) ;
+FUNC long strtol ( const char *, char **, int ) ;
+SUBSET "system" := { +FUNC int system ( const char * ) ; } ;

+IFNDEF __JUST_XPG3
+EXP int MB_CUR_MAX ;
+FIELD ( struct ) div_t { int quot, rem ; } ;
+FIELD ( struct ) ldiv_t { long quot, rem ; } ;
+FUNC int atexit ( void (*) ( void ) ) ;
+FUNC div_t div ( int, int ) ;
+FUNC long labs ( long ) ;
+FUNC ldiv_t ldiv ( long, long ) ;
+FUNC unsigned long strtoul ( const char *, char **, int ) ;
+FUNC int wctomb ( char *, wchar_t ) ;
+ENDIF
+ENDIF

+SUBSET "alloc" := {
    +USE "ansi", "stddef.h", "size_t" (!?) ;
    +FUNC void *calloc ( size_t, size_t ) ;
    +FUNC void *malloc ( size_t ) ;
    +FUNC void *realloc ( void *, size_t ) ;
} ;

+FUNC void *bsearch ( const void *, const void *, size_t, size_t,
		      int (*) ( const void *, const void * ) ) ;
+FUNC void qsort ( void *, size_t, size_t,
		   int (*) ( const void *, const void * ) ) ;

+IFNDEF __JUST_POSIX
+IFNDEF __JUST_XPG3
+FUNC int mblen ( const char *, size_t ) ;
+FUNC size_t mbstowcs ( wchar_t *, const char *, size_t ) ;
+FUNC int mbtowc ( wchar_t *, const char *, size_t ) ;
+FUNC size_t wcstombs ( char *, const wchar_t *, size_t ) ;
+ENDIF
+ENDIF

# vim:set filetype=tspec:
