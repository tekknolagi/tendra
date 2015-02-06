/* $Id$ */

/* TODO: interface for diag/ to call hppa local stabs */

#include <reader/exp.h>

#include <construct/shape.h>
#include <construct/installtypes.h>

#include <diag3/diag_reform.h>

diag_descriptor *
NEW_DIAG_GLOBAL(diag_descriptor *d)
{
	return d;
}

void
OUTPUT_GLOBALS_TAB(void)
{
	stab_typedefs();
}

void
OUTPUT_DIAG_TAGS(void)
{
	stab_tagdefs();
}

void
INSPECT_FILENAME(filename f)
{
	stab_collect_files(f);
}

