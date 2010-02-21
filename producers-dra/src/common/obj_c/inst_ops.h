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

#ifndef INST_OPS_H_INCLUDED
#define INST_OPS_H_INCLUDED

/* Operations for union INSTANCE */

#define TAG_inst(P)			(CHECK_NULL(P)->ag_tag)


/* Operations for component form of union INSTANCE */

#define inst_form(P)			(CHECK_NULL(P) + 1)


/* Operations for component alias of union INSTANCE */

#define inst_alias(P)			(CHECK_NULL(P) + 2)


/* Operations for component next of union INSTANCE */

#define inst_next(P)			(CHECK_NULL(P) + 3)


/* Operations for field templ of union INSTANCE */

#define inst_templ_tag			((unsigned)0)
#define IS_inst_templ(P)		(CHECK_NULL(P)->ag_tag == 0)

#define inst_templ_id(P)		(CHECK_TAG((P), 0) + 4)
#define inst_templ_spec(P)		(CHECK_TAG((P), 0) + 5)
#define inst_templ_access(P)		(CHECK_TAG((P), 0) + 6)
#define inst_templ_mode(P)		(CHECK_TAG((P), 0) + 7)
#define inst_templ_mems(P)		(CHECK_TAG((P), 0) + 8)
#define inst_templ_prev(P)		(CHECK_TAG((P), 0) + 9)

#define MAKE_inst_templ(form_, next_, id_, access_, prev_, c_class_inst)\
    {\
	c_class *x851_ = GEN_c_class(10, TYPEID_inst);\
	x851_->ag_tag = 0;\
	COPY_type(x851_ + 1, (form_));\
	COPY_inst(x851_ + 2, x851_);\
	COPY_inst(x851_ + 3, (next_));\
	COPY_id(x851_ + 4, (id_));\
	COPY_type(x851_ + 5, NULL_type);\
	COPY_dspec(x851_ + 6, (access_));\
	COPY_pptok(x851_ + 7, NULL);\
	COPY_list(x851_ + 8, NULL_list ( IDENTIFIER ));\
	COPY_inst(x851_ + 9, (prev_));\
	(c_class_inst) = x851_;\
    }

#define DECONS_inst_templ(form_, alias_, next_, id_, spec_, access_, mode_, mems_, prev_, c_class_inst)\
    {\
	c_class *x852_ = CHECK_TAG((c_class_inst), 0);\
	(form_) = DEREF_type(x852_ + 1);\
	(alias_) = DEREF_inst(x852_ + 2);\
	(next_) = DEREF_inst(x852_ + 3);\
	(id_) = DEREF_id(x852_ + 4);\
	(spec_) = DEREF_type(x852_ + 5);\
	(access_) = DEREF_dspec(x852_ + 6);\
	(mode_) = DEREF_pptok(x852_ + 7);\
	(mems_) = DEREF_list(x852_ + 8);\
	(prev_) = DEREF_inst(x852_ + 9);\
    }

#define DESTROY_inst_templ(destroyer_, form_, alias_, next_, id_, spec_, access_, mode_, mems_, prev_, c_class_inst)\
    {\
	c_class *x853_ = CHECK_TAG((c_class_inst), 0);\
	(form_) = DEREF_type(x853_ + 1);\
	(alias_) = DEREF_inst(x853_ + 2);\
	(next_) = DEREF_inst(x853_ + 3);\
	(id_) = DEREF_id(x853_ + 4);\
	(spec_) = DEREF_type(x853_ + 5);\
	(access_) = DEREF_dspec(x853_ + 6);\
	(mode_) = DEREF_pptok(x853_ + 7);\
	(mems_) = DEREF_list(x853_ + 8);\
	(prev_) = DEREF_inst(x853_ + 9);\
	(destroyer_)(x853_, (unsigned)10);\
    }


/* Operations for field token of union INSTANCE */

#define inst_token_tag			((unsigned)1)
#define IS_inst_token(P)		(CHECK_NULL(P)->ag_tag == 1)

#define inst_token_no(P)		(CHECK_TAG((P), 1) + 4)

#define MAKE_inst_token(form_, next_, c_class_inst)\
    {\
	c_class *x854_ = GEN_c_class(5, TYPEID_inst);\
	x854_->ag_tag = 1;\
	COPY_type(x854_ + 1, (form_));\
	COPY_inst(x854_ + 2, x854_);\
	COPY_inst(x854_ + 3, (next_));\
	COPY_ulong(x854_ + 4, LINK_NONE);\
	(c_class_inst) = x854_;\
    }

#define DECONS_inst_token(form_, alias_, next_, no_, c_class_inst)\
    {\
	c_class *x855_ = CHECK_TAG((c_class_inst), 1);\
	(form_) = DEREF_type(x855_ + 1);\
	(alias_) = DEREF_inst(x855_ + 2);\
	(next_) = DEREF_inst(x855_ + 3);\
	(no_) = DEREF_ulong(x855_ + 4);\
    }

#define DESTROY_inst_token(destroyer_, form_, alias_, next_, no_, c_class_inst)\
    {\
	c_class *x856_ = CHECK_TAG((c_class_inst), 1);\
	(form_) = DEREF_type(x856_ + 1);\
	(alias_) = DEREF_inst(x856_ + 2);\
	(next_) = DEREF_inst(x856_ + 3);\
	(no_) = DEREF_ulong(x856_ + 4);\
	(destroyer_)(x856_, (unsigned)5);\
    }


#endif
