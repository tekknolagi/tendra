/*
 * Copyright (c) 2002-2006 The TenDRA Project <http://www.tendra.org/>.
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
    AUTOMATICALLY GENERATED FROM ALGEBRA c_class (VERSION 1.1)
    BY calculus (VERSION 1.3)
*/

#ifndef ERR_OPS_H_INCLUDED
#define ERR_OPS_H_INCLUDED

/* Operations for union ERROR */

#pragma token PROC(EXP : ERROR :) EXP : unsigned : TAG_err #
#pragma interface TAG_err


/* Operations for component severity of union ERROR */

#pragma token PROC(EXP : ERROR :)\
    EXP : PTR(int) : err_severity #
#pragma interface err_severity

/* Operations for field simple of union ERROR */

#pragma token EXP const : unsigned : err_simple_tag #
#pragma token PROC(EXP : ERROR :) EXP : int : IS_err_simple #
#pragma interface err_simple_tag IS_err_simple

#pragma token PROC(EXP : ERROR :)\
    EXP : PTR(int) : err_simple_number #
#pragma interface err_simple_number

#pragma token PROC(EXP : ERROR :)\
    EXP : PTR(unsigned) : err_simple_size #
#pragma interface err_simple_size

#pragma token PROC(\
	EXP : int :,\
	EXP : int :,\
	EXP lvalue : ERROR :\
    ) STATEMENT MAKE_err_simple #
#pragma interface MAKE_err_simple

#pragma token PROC(\
	EXP lvalue : int :,\
	EXP lvalue : int :,\
	EXP lvalue : unsigned :,\
	EXP : ERROR :\
    ) STATEMENT DECONS_err_simple #
#pragma interface DECONS_err_simple

#pragma token PROC(\
	EXP : DESTROYER :,\
	EXP lvalue : int :,\
	EXP lvalue : int :,\
	EXP lvalue : unsigned :,\
	EXP : ERROR :\
    ) STATEMENT DESTROY_err_simple #
#pragma interface DESTROY_err_simple


/* Operations for field compound of union ERROR */

#pragma token EXP const : unsigned : err_compound_tag #
#pragma token PROC(EXP : ERROR :) EXP : int : IS_err_compound #
#pragma interface err_compound_tag IS_err_compound

#pragma token PROC(EXP : ERROR :)\
    EXP : PTR(ERROR) : err_compound_head #
#pragma interface err_compound_head

#pragma token PROC(EXP : ERROR :)\
    EXP : PTR(ERROR) : err_compound_tail #
#pragma interface err_compound_tail

#pragma token PROC(\
	EXP : int :,\
	EXP : ERROR :,\
	EXP : ERROR :,\
	EXP lvalue : ERROR :\
    ) STATEMENT MAKE_err_compound #
#pragma interface MAKE_err_compound

#pragma token PROC(\
	EXP lvalue : int :,\
	EXP lvalue : ERROR :,\
	EXP lvalue : ERROR :,\
	EXP : ERROR :\
    ) STATEMENT DECONS_err_compound #
#pragma interface DECONS_err_compound

#pragma token PROC(\
	EXP : DESTROYER :,\
	EXP lvalue : int :,\
	EXP lvalue : ERROR :,\
	EXP lvalue : ERROR :,\
	EXP : ERROR :\
    ) STATEMENT DESTROY_err_compound #
#pragma interface DESTROY_err_compound


#endif
