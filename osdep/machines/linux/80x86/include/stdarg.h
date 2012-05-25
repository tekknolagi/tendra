/* $Id$ */

#ifndef __HACKED_STDARG_H
#define __HACKED_STDARG_H

/*
 * glibc does not provide this header; it is expected to be provided by gcc.
 * The definitions here must be compatible.
 */
#ifdef _GLIBC2_14
#ifndef __BUILDING_TDF_ANSI_STDARG_H_VA_ARGS

/*
 * The definition of va_list is compatible with the system header.
 * We define __gnuc_va_list because various headers rely on it.
 */

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
#define __gnuc_va_list void *
typedef __gnuc_va_list va_list;
#endif

/*
 * The tokens __va_t, __va_start, va_arg and va_end are as in the
 * ansi:stdarg header. The only difference is that va_list is defined
 * as its implementation type, rather than being a tokenised type.
 */

#pragma token TYPE __va_t # ~__va_t
#pragma token PROC ( EXP rvalue : __va_t : ) EXP rvalue : va_list : __va_start # ansi.stdarg.__va_start
#pragma token PROC ( EXP lvalue : va_list : e , TYPE t ) EXP rvalue : t : va_arg # ansi.stdarg.va_arg
#pragma token PROC ( EXP lvalue : va_list : ) EXP rvalue : void : va_end # ansi.stdarg.va_end
#pragma interface __va_t __va_start va_arg va_end
 
#pragma TenDRA ident ... allow

#define va_start(ap, arg) ((void) (ap = __va_start(...)))

#else

/*
 * Implementation of stdarg
 */

/* note char * is compatible to void * above */
typedef char *va_list;

#define __va_round(T)     (((sizeof (T) + 3) / 4) * 4)
#define va_start(ap, arg) (ap = &(arg) + __va_round(arg))
#define va_end(ap)        ((void) 0)
#define va_arg(ap, T)     (ap += __va_round(T), *((t *) ((ap) - __va_round(T))))

#endif
#endif

#endif
