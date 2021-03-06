/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#ifndef SHARED_XALLOC_H
#define SHARED_XALLOC_H

#include <stddef.h>

void *xmalloc(size_t);
void *xcalloc(size_t, size_t);
void *xrealloc(void *, size_t);
void xfree(void *);

#define xmalloc_nof(T, N) (xmalloc((N) * sizeof(T)))
#define xcalloc_nof(T, N) (xcalloc((N), sizeof(T)))
#define xrealloc_nof(P, T, N) (xrealloc((P), (N) * sizeof(T)))
#define xfree_nof(P) xfree((P))

#endif

