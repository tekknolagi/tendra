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

/*
 * dalloc.h - Memory allocation and deallocation.
 *
 * This file specifies the interface to a dynamic memory allocation facility.
 * All dynamically allocated objects are initialised with zeroes, but
 * non-integer typed fields will still need to be initialised explicitly.
 *
 * This depends on:
 *
 *  <exds/common.h> (because exception.h does)
 *  <exds/exception.h>
 *
 *
 * If the macro ``PO_DALLOC_DEBUG_ALIGN'' is defined, then extra debugging
 * information is added into the space allocated to help detect errors in
 * memory management.  If this macro is defined, it requires two functions to
 * be provided:
 *
 *	void				E_dalloc_multi_deallocate
 *			(void *, char *, unsigned, char *,
 *				  unsigned);
 *	void				E_dalloc_corrupt_block
 *			(void *, char *, unsigned);
 *
 * The first function will be called if a block is deallocated more than once.
 * It takes the block's address, and the file and line number of the
 * deallocation and allocation of the block as arguments.  The second function
 * is called if a block is corrupt when deallocated.  It takes the address of
 * the block and the file and line number of the deallocation of the block as
 * arguments.  Neither of these functions should return.
 *
 * This debugging mode should not be used on software that is shipped.  It has
 * machine specific implementations, and may be quite inefficient.
 *
 * Exception:	XX_dalloc_no_memory
 *
 * This exception is raised if there is not enough memory to allocate an
 * object (or a vector of objects).
 */

#ifndef H_DALLOC
#define H_DALLOC

#include <stddef.h>
#include <stdlib.h>


extern ExceptionT *		XX_dalloc_no_memory;

#ifdef PO_DALLOC_DEBUG_ALIGN

extern void	E_dalloc_multi_deallocate(void *, char *, unsigned,
					  char *, unsigned);
extern void	E_dalloc_corrupt_block(void *, char *, unsigned);
extern void *	X__dalloc_allocate(size_t, size_t, char *, unsigned);
extern void	X__dalloc_deallocate(void *, char *, unsigned);

#else

extern void *	X__dalloc_allocate(size_t, size_t);

#endif /* defined (PO_DALLOC_DEBUG_ALIGN) */

#ifdef PO_DALLOC_DEBUG_ALIGN

#define ALLOCATE(type)\
((type *)X__dalloc_allocate(sizeof(type), (size_t)1, __FILE__, \
			     (unsigned)__LINE__))

#define ALLOCATE_VECTOR(type,length)\
((type *)X__dalloc_allocate(sizeof(type), (size_t)(length), __FILE__, \
			     (unsigned)__LINE__))

#define DEALLOCATE(pointer)\
X__dalloc_deallocate((pointer), __FILE__, (unsigned)__LINE__)

#else

/*
 * This macro allocates an object of the specified type.  A pointer to the
 * object is returned.
 */
#define ALLOCATE(type)\
((type *)X__dalloc_allocate(sizeof(type), (size_t)1))

/*
 * This macro allocates a vector of the specified length containing objects of
 * the specified type.  A pointer to the first element in the vector is
 * returned.
 */
#define ALLOCATE_VECTOR(type,length)\
((type *)X__dalloc_allocate(sizeof(type), (size_t)(length)))

/*
 * This macro deallocates the specified pointer.  If the pointer is a null
 * pointer (``NULL''), this does nothing.
 */
#define DEALLOCATE(pointer) free(pointer);

#endif /* defined (PO_DALLOC_DEBUG_ALIGN) */

#endif /* !defined (H_DALLOC) */
