/*
 * Copyright (c) 2002-2004, The Tendra Project <http://www.ten15.org/>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice unmodified, this list of conditions, and the following
 *    disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 *    		 Crown Copyright (c) 1997
 *
 *    This TenDRA(r) Computer Program is subject to Copyright
 *    owned by the United Kingdom Secretary of State for Defence
 *    acting through the Defence Evaluation and Research Agency
 *    (DERA).  It is made available to Recipients with a
 *    royalty-free licence for its use, reproduction, transfer
 *    to other parties and amendment for any purpose not excluding
 *    product development provided that any such use et cetera
 *    shall be deemed to be acceptance of the following conditions:-
 *
 *        (1) Its Recipients shall ensure that this Notice is
 *        reproduced upon any copies or amended versions of it;
 *
 *        (2) Any amended version of it shall be clearly marked to
 *        show both the nature of and the organisation responsible
 *        for the relevant amendment or amendments;
 *
 *        (3) Its onward transfer from a recipient to another
 *        party shall be deemed to be that party's acceptance of
 *        these conditions;
 *
 *        (4) DERA gives no warranty or assurance as to its
 *        quality or suitability for any purpose and DERA accepts
 *        no liability whatsoever in relation to any use to which
 *        it may be put.
 *
 * $TenDRA$
 */


/**** dalloc.c --- Memory allocation and deallocation.
 *
 ** Author: Steve Folkes <smf@hermes.mod.uk>
 *
 **** Commentary:
 *
 * This file implements the dynamic memory management facility specified in
 * the file "dalloc.h".  See that file for more information.
 */

/****************************************************************************/

#include "dalloc.h"
#include "fmm.h"
#include "msgcat.h"

/*--------------------------------------------------------------------------*/

#ifdef PO_DALLOC_DEBUG_ALIGN

#define DALLOC_MAGIC 0x21436587
#define ALIGN(x) (((int) (((x) + (PO_DALLOC_DEBUG_ALIGN) - 1) / \
			  (PO_DALLOC_DEBUG_ALIGN))) * (PO_DALLOC_DEBUG_ALIGN))

/*--------------------------------------------------------------------------*/

typedef struct DallocDataT {
	char *			file;
	unsigned		line;
	size_t			size;
	int				magic;
} DallocDataT, *DallocDataP;

/*--------------------------------------------------------------------------*/

static size_t dalloc_data_size = ALIGN (sizeof (DallocDataT));

/*--------------------------------------------------------------------------*/

void *
X__dalloc_allocate(size_t size, size_t length, char *file, unsigned line)
{
	void *tmp;
	
	ASSERT (size != 0);
	if (length == 0) {
		tmp = NULL;
	} else {
		size_t       real_size = ((size * length) + dalloc_data_size);
		ByteP       base;
		DallocDataP data;
		
		if ((tmp = fmm_malloc (real_size, fmm_detype)) == NULL) {
			MSG_no_memory ();
			UNREACHED;
		}
		(void) memset (tmp, 0, real_size);
		data        = tmp;
		base        = tmp;
		tmp         = (base + dalloc_data_size);
		data->file  = file;
		data->line  = line;
		data->magic = DALLOC_MAGIC;
	}
	return (tmp);
}

void
X__dalloc_deallocate(void *ptr, char *file,
					 unsigned line)
{
	if (ptr) {
		ByteP       pointer = (ByteP) ptr;
		DallocDataP data    = (DallocDataP) (pointer - dalloc_data_size);
		
		if (data->magic == 0) {
			MSG_dalloc_multi_deallocate (ptr, file, line, data->file,
									   data->line);
			UNREACHED;
		} else if (data->magic != DALLOC_MAGIC) {
			MSG_dalloc_corrupt_block (ptr, file, line);
			UNREACHED;
		}
		data->magic = 0;
		fmm_free (data, fmm_deftype);
	}
}

#else

void *
X__dalloc_allocate(size_t size, size_t length)
{
	size_t realsize;
	void *tmp;
	
	ASSERT (size != 0);
	realsize = length * size;
	if (length == 0) {
		tmp = NULL;
	} else if ((tmp = fmm_malloc (realsize, fmm_deftype)) == NULL) {
		MSG_no_memory ();
		UNREACHED;
	}
	memset (tmp, 0, realsize);
	return (tmp);
}

#endif /* defined (PO_DALLOC_DEBUG_ALIGN) */