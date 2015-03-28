/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 * Copyright 1993, Open Software Foundation, Inc.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#ifndef NDEBUG

#include <stdio.h>

#include <shared/bool.h>
#include <shared/check.h>

#include <local/ash.h>

#include <tdf/tag.h>

#include <reader/exp.h>

#include <construct/installtypes.h>
#include <construct/dec.h>
#include <construct/exp.h>
#include <construct/shape.h>

#include "localexpmacs.h"
#include "addrtypes.h"
#include "locate.h"
#include "translate.h"

#include "pp.h"

/*
 * This file contains debugging tools used in debugging a translator
 */

void properties(int);
exp show_bro(int);
exp show_son(int);
exp show_current(int);
exp show_father(int);
exp show_pt(int);
exp recurse(int);
exp infotag(exp, int);
void showme(exp, int, int);
static exp last_exp_seen = NULL;
static exp last_exp_seen1 = NULL;
static exp last_exp_seen2 = NULL;
static exp last_exp_seen3 = NULL;
static exp last_exp_seen4 = NULL;
static exp last_exp_seen5 = NULL;

static void exp_show(exp, int, int, int);
char *find_test_name(exp);
static void myprint(char *);
char *shape_name(int);
char *getname(int);
void ident_props(exp);
void proc_tag_props(exp);
void general_proc_tag_props(exp);
void solve_props(exp);
void movecont_props(exp);
void cont_props(exp);
void labst_props(exp);
void name_props(exp);
void string_props(exp);
void val_props(exp);
void rep_props(exp);
void apply_props(exp);

static exp stored_idents[1000];
static exp stored_labsts[1000];
static int store_ident(exp);
static int store_labst(exp);
static int no_of_idents_stored = 0;
static int no_of_labsts_stored = 0;
static int ident_no(exp);
static int labst_no(exp);

static int
store_ident(exp e)
{
	no_of_idents_stored++;
	stored_idents[no_of_idents_stored] = e;
	return no_of_idents_stored;
}

static int
store_labst(exp e)
{
	no_of_labsts_stored++;
	stored_labsts[no_of_labsts_stored] = e;
	return no_of_labsts_stored;
}

static int
ident_no(exp e)
{
	int i;

	for (i = no_of_idents_stored; i > 0; i--) {
		if (stored_idents[i] == e) {
			return i;
		}
	}

	return 0;
}

static int
labst_no(exp e)
{
	int i;

	for (i = no_of_labsts_stored; i > 0; i--) {
		if (stored_labsts[i] == e) {
			return i;
		}
	}

	return 0;
}

static void
scan_for_labsts(exp e)
{
	if (e == NULL) {
		return;
	}

	switch (name(e)) {
	case labst_tag:
		store_labst(e);
		break;

	case ident_tag:
		store_ident(e);
		break;

	/* don't scan sons of these tags */
	case name_tag:
	case env_offset_tag:
		if (!last(e)) {
			scan_for_labsts(bro(e));
		}
		return;

	/* don't scan bros of these tags */
	case case_tag:
		scan_for_labsts(son(e));
		return;
	}

	scan_for_labsts(son(e));
	if (!last(e)) {
		scan_for_labsts(bro(e));
	}
}

void
showme(exp e, int depth_of_recursion, int flag)
{
	no_of_labsts_stored = 0;
	no_of_idents_stored = 0;

	if (name(e) == labst_tag) {
		store_labst(e);
	}

	if (name(e) == ident_tag) {
		store_ident(e);
	}

	scan_for_labsts(son(e));
	exp_show(e, 0, depth_of_recursion, flag);
}

exp
show_current(int i)
{
	exp l;

	switch (i) {
	case 0: l = last_exp_seen;  break;
	case 1: l = last_exp_seen1; break;
	case 2: l = last_exp_seen2; break;
	case 3: l = last_exp_seen3; break;
	case 4: l = last_exp_seen4; break;
	case 5: l = last_exp_seen5; break;
	}

	if (l == NULL) {
		printf("No current exp for stored exp no %d\n", i);
	} else {
		infotag(l, i);
	}

	return l;
}

exp
show_bro(int i)
{
	exp l;

	switch (i) {
	case 0: l = last_exp_seen;  break;
	case 1: l = last_exp_seen1; break;
	case 2: l = last_exp_seen2; break;
	case 3: l = last_exp_seen3; break;
	case 4: l = last_exp_seen4; break;
	case 5: l = last_exp_seen5; break;
	}

	if (l == NULL) {
		printf("No current exp\n");
		return NULL;
	}

	if (bro(l) != NULL) {
		infotag(bro(l), i);
	} else {
		printf("No brother field to stored exp no %d\n", i);
	}

	return l;
}

exp
show_son(int i)
{
	exp l;

	switch (i) {
	case 0: l = last_exp_seen;  break;
	case 1: l = last_exp_seen1; break;
	case 2: l = last_exp_seen2; break;
	case 3: l = last_exp_seen3; break;
	case 4: l = last_exp_seen4; break;
	case 5: l = last_exp_seen5; break;
	}

	if (l == NULL) {
		printf("No current exp\n");
		return 0;

	}

	if (son(l) != NULL) {
		infotag(son(l), i);
	} else {
		printf("No son field to stored exp no %d\n", i);
	}

	return l;
}

exp
show_father(int i)
{
	exp l;

	switch (i) {
	case 0: l = last_exp_seen;  break;
	case 1: l = last_exp_seen1; break;
	case 2: l = last_exp_seen2; break;
	case 3: l = last_exp_seen3; break;
	case 4: l = last_exp_seen4; break;
	case 5: l = last_exp_seen5; break;
	}

	if (l == NULL) {
		printf("No current stored exp no %d\n", i);
		return NULL;
	}

	if (father(l) != NULL) {
		infotag(father(l), i);
	} else {
		printf("Cannot find father of stored exp no %d\n", i);
	}

	return l;
}

exp
show_pt(int i)
{
	exp l;

	switch (i) {
	case 0: l = last_exp_seen;  break;
	case 1: l = last_exp_seen1; break;
	case 2: l = last_exp_seen2; break;
	case 3: l = last_exp_seen3; break;
	case 4: l = last_exp_seen4; break;
	case 5: l = last_exp_seen5; break;
	}

	if (l == NULL) {
		printf("No current exp\n");
		return 0;

	}

	if (pt(l) != NULL) {
		infotag(pt(l), i);
	} else {
		printf("No pt field to stored exp no %d\n", i);
	}

	return l;
}

exp
recurse(int i)
{
	exp l;

	switch (i) {
	case 0: l = last_exp_seen;  break;
	case 1: l = last_exp_seen1; break;
	case 2: l = last_exp_seen2; break;
	case 3: l = last_exp_seen3; break;
	case 4: l = last_exp_seen4; break;
	case 5: l = last_exp_seen5; break;
	}

	if (l == NULL) {
		printf("No current exp for no %d (Use infotag)\n", i);
	} else {
		showme(l, -1, 1);
	}

	return l;
}

char *
getname(int n)
{
	switch (n) {
	case 0:                       return "zero";
	case ident_tag:               return "ident";
	case seq_tag:                 return "seq";
	case cond_tag:                return "cond";
	case labst_tag:               return "labst";
	case rep_tag:                 return "rep";
	case goto_tag:                return "goto";
	case test_tag:                return "test";
	case ass_tag:                 return "ass";
	case apply_tag:               return "apply";
	case res_tag:                 return "res";
	case goto_lv_tag:             return "goto_lv";
	case solve_tag:               return "solve";
	case assvol_tag:              return "assvol";
	case compound_tag:            return "compound";
	case nof_tag:                 return "nof";
	case local_free_all_tag:      return "local_free_all";
	case local_free_tag:          return "local_free";
	case last_local_tag:          return "last_local";
	case long_jump_tag:           return "long_jump";
	case concatnof_tag:           return "concatnof";
	case ncopies_tag:             return "ncopies";
	case case_tag:                return "case";
	case movecont_tag:            return "movecont";
	case testbit_tag:             return "testbit";
	case alloca_tag:              return "alloca";
	case diagnose_tag:            return "diagnose";
	case prof_tag:                return "prof";
	case ignorable_tag:           return "ignorable";
	case bfass_tag:               return "bfass";
	case bfassvol_tag:            return "bfassvol";
	case condassign_tag:          return "condassign";
	case apply_general_tag:       return "apply_general";
	case tail_call_tag:           return "tail_call";
	case untidy_return_tag:       return "untidy_return";
	case same_callees_tag:        return "same_callees";
	case plus_tag:                return "plus";
	case neg_tag:                 return "neg";
	case shl_tag:                 return "shl";
	case mod_tag:                 return "mod";
	case rem2_tag:                return "rem2";
	case abs_tag:                 return "abs";
	case round_tag:               return "round";
	case offset_pad_tag:          return "offset_pad";
	case offset_div_tag:          return "offset_div";
	case offset_max_tag:          return "offset_max";
	case minptr_tag:              return "minptr";
	case fpower_tag:              return "fpower";
	case fplus_tag:               return "fplus";
	case fminus_tag:              return "fminus";
	case fmult_tag:               return "fmult";
	case fdiv_tag:                return "fdiv";
	case fabs_tag:                return "fabs";
	case fneg_tag:                return "fneg";
	case float_tag:               return "float";
	case chfl_tag:                return "chfl";
	case and_tag:                 return "and";
	case or_tag:                  return "or";
	case xor_tag:                 return "xor";
	case not_tag:                 return "not";
	case component_tag:           return "component";
	case max_tag:                 return "max";
	case min_tag:                 return "min";
	case bitf_to_int_tag:         return "bitf_to_int";
	case bfcont_tag:              return "bfcont";
	case fmax_tag:                return "fmax";
	case shr_tag:                 return "shr";
	case fmin_tag:                return "fmin";
	case div0_tag:                return "div0";
	case bfcontvol_tag:           return "bfcontvol";
	case absbool_tag:             return "absbool";
	case addptr_tag:              return "addptr";
	case chvar_tag:               return "chvar";
	case minus_tag:               return "minus";
	case mult_tag:                return "mult";
	case subptr_tag:              return "subptr";
	case realpart_tag:            return "realpart";
	case div1_tag:                return "div1";
	case div2_tag:                return "div2";
	case offset_add_tag:          return "offset_add";
	case offset_div_by_int_tag:   return "offset_div_by_int";
	case offset_mult_tag:         return "offset_mult";
	case offset_negate_tag:       return "offset_negate";
	case offset_subtract_tag:     return "offset_subtract";
	case rem0_tag:                return "rem0";
	case rotl_tag:                return "rotl";
	case rotr_tag:                return "rotr";
	case power_tag:               return "power";
	case imag_tag:                return "imag";
	case make_complex_tag:        return "make_complex";
	case int_to_bitf_tag:         return "int_to_bitf";
	case hold_tag:                return "hold";
	case hold2_tag:               return "hold2";
	case cont_tag:                return "cont";
	case field_tag:               return "field";
	case val_tag:                 return "val";
	case reff_tag:                return "reff";
	case name_tag:                return "name";
	case proc_tag:                return "proc";
	case top_tag:                 return "top";
	case contvol_tag:             return "contvol";
	case current_env_tag:         return "current_env";
	case env_offset_tag:          return "env_offset";
	case make_lv_tag:             return "make_lv";
	case clear_tag:               return "clear";
	case null_tag:                return "null";
	case real_tag:                return "real";
	case string_tag:              return "string";
	case general_proc_tag:        return "general_proc";
	case env_size_tag:            return "env_size";
	case give_stack_limit_tag:    return "give_stack_limit";
	case general_env_offset_tag:  return "general_env_offset";
	case caller_tag:              return "caller";
	case caller_name_tag:         return "caller_name";
	case make_dynamic_callee_tag: return "make_dynamic_callee";
	case make_callee_list_tag:    return "make_callee_list";
	case set_stack_limit_tag:     return "set_stack_limit";
	case formal_callee_tag:       return "formal_callee";
	case trap_tag:                return "trap_tag";

	/* Powertrans specific */
	case locptr_tag:              return "locptr_tag";
	default:                      return "undefined"; 
	}
}

exp
infotag(exp e, int i)
{
	switch (i) {
	case 0: last_exp_seen = e;  break;
	case 1: last_exp_seen1 = e; break;
	case 2: last_exp_seen2 = e; break;
	case 3: last_exp_seen3 = e; break;
	case 4: last_exp_seen4 = e; break;
	case 5: last_exp_seen5 = e; break;
	}

	if (e == NULL) {
		printf("Error 'NULL'\n");
		return e;
	}

	printf("-------------------------------------------------------------------------------\n");
	printf("| %-17s 0x%-8x         | SHAPE information                    |\n", getname(name(e)), (unsigned int)e);
	printf("-------------------------------------------------------------------------------\n");
	printf("| no(e)        = %-15d       ", no(e));
	if (sh(e) != NULL) {
		printf("| name(sh(e))        = %-15s |\n", shape_name(name(sh(e))));
	} else {
		printf("| No shape                             |\n");
	}
	printf("| props(e)     = ");
	{
		int i;
		unsigned short mask;
		for (i = 15; i >= 0; i--) {
			mask = 1 << i;
			if (mask & props(e)) {
				printf("1");
			} else {
				printf("0");
			}

			if (i % 4 == 0) {
				printf(" ");
			}
		}
	}

	if (sh(e) != NULL) {
		printf("  | shape_size(sh(e))  = %-8d        |\n", shape_size(sh(e)));
	} else {
		printf("  |                                      |\n");
	}

	printf("| bro(e)       = 0x%-8x            ", (unsigned int)bro(e));

	if (sh(e) != NULL) {

		printf("| shape_align(sh(e)) = %-8d        |", (int)shape_align(sh(e)));

	} else {
		printf("|                                      |");
	}
	if (bro(e) != NULL) {
		if (last(e)) {
			printf("-->father:%s\n", getname(name(bro(e))));
		} else {
			printf("-->brother:%s\n", getname(name(bro(e))));
		}
	} else {
		printf("-->NULL\n");
	}

	printf("| sh(e)        = 0x%-8x            ", (unsigned int)sh(e));

	if (sh(e) != NULL) {
		printf("| is_signed(sh(e))   = %-2d              |\n", is_signed(sh(e)));
	} else {
		printf("|                                      |\n");
	}
	printf("| pt(e)        = 0x%-8x            ", (unsigned int)pt(e));

	if (sh(e) != NULL) {
		printf("| al1(sh(e))         = %-2d              |\n", (int)al1(sh(e)));
	} else {
		printf("|                                      |\n");
	}

	printf("| last(e)      = %d                     ", last(e));

	if (sh(e) != NULL) {
		printf("| al2(sh(e))         = %-2d              |\n", (int)al2(sh(e)));
	} else {
		printf("|                                      |\n");
	}

	printf("-------------------------------------------------------------------------------\n");
	if (son(e) != NULL) {
		int finished = 0;
		exp point = son(e);
		if (name(e) == name_tag) {
			printf("son is ident 0x%-8x\n", (unsigned int)son(e));
			return e;
		}

		printf("                |\n");

		/* first line */
		while (!finished) {
			finished = last(point);
			printf("------------------------------   ");
			point = bro(point);
		}
		printf("\n");

		/* second line */
		point = son(e);
		finished = 0;
		while (!finished) {
			finished = last(point);
			printf("| %-17s0x%-8x|   ", getname(name(point)), (unsigned int)point);
			point = bro(point);
		}
		printf("\n");

		point = son(e);
		finished = 0;
		while (!finished) {
			finished = last(point);
			printf("------------------------------   ");
			point = bro(point);
		}
		printf("\n");

		/* new line */
		point = son(e);
		finished = 0;
		while (!finished) {
			finished = last(point);
			printf("| no          = %-10d   |   ", no(point));
			point = bro(point);
		}
		printf("\n");

		/* new line */
		point = son(e);
		finished = 0;
		while (!finished) {
			finished = last(point);
			printf("| pt          = 0x%-8x   |   ", (unsigned int)pt(point));
			point = bro(point);
		}
		printf("\n");

		/* third line */
		point = son(e);
		finished = 0;
		while (!finished) {
			finished = last(point);
			if (sh(point) != NULL) {
				printf("| name(sh) = %-15s |", shape_name(name(sh(point))));
			} else {
				printf("|                            |");
			}
			if (finished == 0) {
				printf("-->");
			}
			point = bro(point);
		}
		printf("\n");

		/* fourth line */
		point = son(e);
		finished = 0;
		while (!finished) {
			finished = last(point);
			if (sh(point) != NULL) {
				printf("| shape_size  = %-4d         |   ", shape_size(sh(point)));
			} else {
				printf("|                            |   ");
			}
			point = bro(point);
		}
		printf("\n");

		point = son(e);
		finished = 0;
		while (!finished) {
			finished = last(point);
			if (sh(point) != NULL) {
				printf("| shape_align = %-4d         |   ", (int)shape_align(sh(point)));
			} else {
				printf("|                            |   ");
			}
			point = bro(point);
		}
		printf("\n");

		/* fifth_line */
		point = son(e);
		finished = 0;
		while (!finished) {
			finished = last(point);
			if (sh(point) != NULL) {
				printf("| is_signed   = %-4d         |   ", is_signed(sh(e)));
			} else {
				printf("|                            |   ");
			}

			point = bro(point);
		}
		printf("\n");

		point = son(e);
		finished = 0;
		while (!finished) {
			finished = last(point);
			printf("------------------------------   ");
			point = bro(point);
		}
		printf("\n");

		/* last line */
		point = son(e);
		finished = 0;
		while (!finished) {
			finished = last(point);
			if (son(point) == NULL) {

				printf("                                 ");
			} else {
				printf("                |                ");
			}

			point = bro(point);
		}
		printf("\n");
	}

	return e;
}

static void print_spaces(int n)
{
	int i;
	int j = 0;
	for (i = 0; i < n; i++) {
		switch (j) {
		case 0: printf(" "); break;
		case 1: printf(" "); break;
		case 2: printf("|"); break;
		}

		j++;
		if (j == 3) {
			j = 0;
		}
	}

}

void
exp_show(exp e, int depth, int depth_of_recursion, int flag)
{
	char *tagname;

	if (e == NULL || depth == depth_of_recursion) {
		return;
	}

	printf("(0x%x)", (int)e);
	tagname = getname(name(e));

	print_spaces(depth);

	/*
	 * Don't want to look down son's of name_tag's or env_offset_tag
	 * because this will take you to ident_tag's and thus into an infinite loop
	 */

	switch (name(e)) {
	case proc_tag:
	case general_proc_tag: {
		if (done_scan == 1) {
			baseoff b = boff(father(e));
			char *ext;
			ext = main_globals[(-b.base) - 1] ->dec_id;
			printf("%s:\"%s\"\n", tagname, ext);
		} else {
			printf("%s:\n", tagname);
		}

		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;
	}

	case name_tag: {
		int l = ident_no(son(e));
		if (l) {
			printf("%s:<%s> no=%d obtain {tag~%04d}\n", tagname, shape_name(name(sh(e))), no(e), l);
		}
#if 1
		else if (name(sh(e)) == prokhd && (name(son(son(e))) == proc_tag || son(son(e)) == NULL || name(son(son(e))) == general_proc_tag) && done_scan == 1) {
			baseoff b = boff(son(e));
			char *ext;
			ext = main_globals[(-b.base) - 1] ->dec_id;
			printf("%s:<%s> function \"%s\"(0x%x)\n", tagname, shape_name(name(sh(e))), ext, (int)(son(e)));
		}
#endif
		else {
			printf("%s:<%s> no=%d obtain (0x%x)\n", tagname, shape_name(name(sh(e))), no(e), (int)son(e));
		}
		break;
	}

	case trap_tag:
		printf("%s:no=%d\n", tagname, no(e));
		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;

	case general_env_offset_tag:
	case env_offset_tag: {
		int l = ident_no(son(e));
		if (l) {
			printf("%s:<%s> for ident {tag~%04d}\n", tagname, shape_name(name(sh(e))), l);
		} else {
			printf("%s:<%s> for ident (0x%x)\n", tagname, shape_name(name(sh(e))), (int)son(e));
		}
		break;
	}

	case caller_name_tag:
		printf("%s:<%s> for caller NO_%d\n", tagname, shape_name(name(sh(e))), no(e));
		break;

	case case_tag:
		printf("%s:<%s>\n", tagname, shape_name(name(sh(e))));
		exp_show(son(e), depth + 1, depth_of_recursion, 1);
		{
			exp s = son(e);
			do {
				int label;
				s = bro(s);
				printf("(0x%x)", (int)s);
				print_spaces(depth + 1);
				printf("(%d", no(s));
				if (son(s) != NULL) {
					printf("-%d)", no(son(s)));
				} else {
					printf(")");
				}
				label = labst_no(pt(s));
				if (label) {
					printf(" ----> {label~%04d}\n", label);
				} else {
					printf(" ----> (0x%x)\n", (int)pt(s));
				}
			} while (!last(s));
		}
		break;
	case goto_tag: {
		int label = labst_no(pt(e));
		if (label) {
			printf("%s:<%s> ---->{label~%04d}\n", tagname, shape_name(name(sh(e))), label);
		} else {
			printf("%s:<%s> ----> (0x%x)\n", tagname, shape_name(name(sh(e))), (int)pt(e));
		}
		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;
	}

	case fdiv_tag:
	case fplus_tag:
	case fminus_tag:
	case fneg_tag:
	case fpower_tag:
	case mult_tag:
	case neg_tag:
	case plus_tag:
	case power_tag:
	case rem0_tag:
	case rem2_tag:
	case mod_tag:
	case round_tag:
	case shl_tag:
	case shr_tag:
		if (optop(e)) {
			printf("%s:<%s>\n", tagname, shape_name(name(sh(e))));
		} else {
			int label = labst_no(pt(e));
			if (label) {
				printf("%s:<%s> error_jump=>{label~%04d}\n", tagname, shape_name(name(sh(e))), label);
			} else {
				printf("%s:<%s> error_jump=>0x%x\n", tagname, shape_name(name(sh(e))), (unsigned int)pt(e));
			}
		}
		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;

	case last_local_tag:
		printf("%s: pt=0x%x\n", tagname, (unsigned int)pt(e));
		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;

	case make_lv_tag: {
		int label = labst_no(pt(e));
		if (label) {
			printf("%s: {label~%04d}\n", tagname, label);
		} else {
			printf("%s: Label=0x%x\n", tagname, (unsigned int)pt(e));
		}
		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;
	}

	case seq_tag:
	case rotl_tag:
	case rotr_tag:
	case realpart_tag:
	case nof_tag:
	case not_tag:
	case null_tag:
	case offset_add_tag:
	case offset_div_tag:
	case offset_max_tag:
	case offset_mult_tag:
	case offset_negate_tag:
	case offset_pad_tag:
	case offset_subtract_tag:
	case or_tag:
	case minptr_tag:
	case ignorable_tag:
	case imag_tag:
	case float_tag:
	case fmax_tag:
	case fmin_tag:
	case fabs_tag:
	case div2_tag:
	case div1_tag:
	case div0_tag:
	case current_env_tag:
	case concatnof_tag:
	case abs_tag:
	case addptr_tag:
	case alloca_tag:
	case and_tag:
	case apply_tag:
	case int_to_bitf_tag:
	case bitf_to_int_tag:
	case cont_tag:
	case cond_tag:
	case chfl_tag:
	case caller_tag:
		printf("%s:<%s>\n", tagname, shape_name(name(sh(e))));
		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;

	case bfass_tag:
	case bfcont_tag:
		if (name(sh(e)) == bitfhd) {
			printf("%s:<%s> %s %d bit bitfield , bit_offset=%d\n", tagname, shape_name(name(sh(e))), is_signed(sh(e)) ? "Signed" : "Unsigned", shape_size(sh(e)), no(e));
		} else {
			printf("%s:<%s> bit_offset=%d\n", tagname, shape_name(name(sh(e))), no(e));
		}

		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;

	case chvar_tag:
		if (name(sh(e)) == bitfhd) {
			printf("%s:<%s> %s %d bit bitfield\n", tagname, shape_name(name(sh(e))), is_signed(sh(e)) == 0 ? "Unsigned" : "Signed", shape_size(sh(e)));
		} else {
			printf("%s:<%s>\n", tagname, shape_name(name(sh(e))));
		}
		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;

	case make_callee_list_tag:
		if (call_has_vcallees(e)) {
			printf("%s:has_vcallees no=%d\n", tagname, no(e));
		} else {
			printf("%s: no=%d\n", tagname, no(e));
		}
		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;

	case clear_tag:
		printf("%s:<%s> no=%d\n", tagname, shape_name(name(sh(e))), no(e));
		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;

	case labst_tag:
		printf("%s:<%s> {label~%04d}\n", tagname, shape_name(name(sh(e))), labst_no(e));
		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;

	case diagnose_tag:
		printf("%s:<%s> dno=0x%x\n", tagname, shape_name(name(sh(e))), (unsigned int)dno(e));
		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;

	case val_tag:
		if (is_signed(sh(e))) {
			printf("%s:<%s> no=%d (0x%08x)\n", tagname, shape_name(name(sh(e))), no(e), no(e));
		} else {
			printf("%s:<%s> no=%u (0x%08x)\n", tagname, shape_name(name(sh(e))), no(e), no(e));
		}

		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;

	case reff_tag:
	case field_tag:
	case real_tag:
	case ncopies_tag:
		printf("%s:<%s> no=%d\n", tagname, shape_name(name(sh(e))), no(e));
		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;

	case test_tag: {
		int label = labst_no(pt(e));
		if (label) {
			printf("%s: (f_%s) fails---->{label~%04d}\n", tagname, find_test_name(e), label);
		} else {
			printf("%s: (f_%s) fails----> (0x%x)\n", tagname, find_test_name(e), (int)pt(e));
		}
		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;
	}

	case ident_tag:
		printf("%s:<%s> {tag~%04d}", tagname, shape_name(name(sh(e))), ident_no(e));
		if (isvar(e))    printf(" VAR");
		if (isvis(e))    printf(" VIS");
		if (isenvoff(e)) printf(" ENVOFF");
		if (iscaonly(e)) printf(" CAONLY");
		if (isparam(e))  printf(" PARAM");
		if (isglob(e))   printf(" GLOB");
		printf("\n");

		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;


	case string_tag:
		myprint(nostr(e));
		printf("\"\n");
		exp_show(son(e), depth + 1, depth_of_recursion, 0);
		break;

	default:
		/* default action will be */
		printf("%s:\n", tagname);
		exp_show(son(e), depth + 1, depth_of_recursion, 0);
	}

	/* always look at brother unless told not to or it is last */
	if (last(e) || flag) {
		return;
	} else {
		exp_show(bro(e), depth, depth_of_recursion, 0);
		return;
	}
}

char *
find_test_name(exp e)
{
	switch (test_number(e)) {
	case 1:  return "greater_than";
	case 2:  return "greater_than_or_equal";
	case 3:  return "less_than";
	case 4:  return "less_than_or_equal";
	case 5:  return "equal";
	case 6:  return "not_equal";
	case 7:  return "not_less_than_or_equal";
	case 8:  return "not_less_than";
	case 9:  return "not_greater_than_or_equal";
	case 10: return "not_greater_than";
	case 11: return "less_than_or_greater_than";
	case 12: return "not_less_than_and_not_greater_than";
	case 13: return "comparable";
	case 14: return "not_comparable";
	default: return "unknown";
	}
}

static void
myprint(char *word)
{
	char *k;
	k = word;
	while (*k != 0) {
		switch (*k) {
		case '\n': printf("\\n"); break;
		case '\t': printf("\\t"); break;

		default:
			printf("%c", *k);
		}
		k++;
	}
}

char *
shape_name(int n)
{
	switch (n) {
	case 1:  return "bothd";
	case 2:  return "tophd";
	case 3:  return "scharhd";
	case 4:  return "ucharhd";
	case 5:  return "swordhd";
	case 6:  return "uwordhd";
	case 7:  return "slonghd";
	case 8:  return "ulonghd";
	case 9:  return "s64hd";
	case 10: return "u64hd";
	case 17: return "shcomplexhd";
	case 18: return "complexhd";
	case 19: return "complexdoublehd";
	case 20: return "shrealhd";
	case 21: return "realhd";
	case 22: return "doublehd";
	case 23: return "bitfhd";
	case 24: return "prokhd";
	case 25: return "ptrhd";
	case 26: return "offsethd";
	case 27: return "sizehd";
	case 28: return "cpdhd";
	case 29: return "nofhd";
	case 30: return "tokhd";
	default: return "unknown";
	}
}

void
properties(int i)
{
	exp l;

	switch (i) {
	case 0: l = last_exp_seen; break;
	case 1: l = last_exp_seen1; break;
	case 2: l = last_exp_seen2; break;
	case 3: l = last_exp_seen3; break;
	case 4: l = last_exp_seen4; break;
	case 5: l = last_exp_seen5; break;
	}

	if (l == NULL) {
		printf("No current exp\n");
		return;
	}

	switch (name(l)) {
	case ident_tag:        ident_props(l);            break;
	case proc_tag:         proc_tag_props(l);         break;
	case general_proc_tag: general_proc_tag_props(l); break;
	case solve_tag:        solve_props(l);            break;
	case movecont_tag:     movecont_props(l);         break;
	case cont_tag:         cont_props(l);             break;
	case labst_tag:        labst_props(l);            break;
	case name_tag:         name_props(l);             break;
	case string_tag:       string_props(l);           break;
	case val_tag:          val_props(l);              break;
	case rep_tag:          rep_props(l);              break;
	case apply_tag:        apply_props(l);            break;

	default:
		printf("Don't know about the properties of a %s\n", getname(name(l)));
		break;
	}
}

void
ident_props(exp e)
{
	printf("isvar       = %d\n", isvar(e));
	printf("isvis       = %d\n", isvis(e));
	printf("isenvoff    = %d\n", isenvoff(e));
	printf("iscaonly    = %d\n", iscaonly(e));
	printf("isusereg    = %d\n", isusereg(e));
	printf("isparam     = %d\n", isparam(e));
	printf("isglob      = %d\n", isglob(e));
	printf("copying     = %d\n", copying(e));
	printf("isinlined   = %d\n", isinlined(e));
#ifdef POWER
#define subvar 0x0100
	printf("subvar      = %d\n", !(!(props(e) & subvar)));
	printf("inreg_bits  = %d\n", !(!(props(e) & inreg_bits)));
	printf("infreg_bits = %d\n", !(!(props(e) & infreg_bits)));
	printf("inanyreg    = %d\n", !(!(props(e) & inanyreg)));
	printf("defer_bit   = %d\n", !(!(props(e) & defer_bit)));
	printf("notparreg   = %d\n", !(!(props(e) & notparreg)));
	printf("notresreg   = %d\n", !(!(props(e) & notresreg)));
#endif
}

void
proc_tag_props(exp e)
{
	printf("has_struct_res     = %d\n", has_struct_res(e));
	printf("loc_address        = %d\n", loc_address(e));
	printf("proc_has_setjmp    = %d\n", proc_has_setjmp(e));
	printf("proc_has_lv        = %d\n", proc_has_lv(e));
	printf("isrecursive        = %d\n", isrecursive(e));
	printf("proc_uses_crt_env  = %d\n", proc_uses_crt_env(e));
	printf("proc_uses_external = %d\n", proc_uses_external(e));
}

void
general_proc_tag_props(exp e)
{
	printf("has_struct_res     = %d\n", has_struct_res(e));
	printf("loc_address        = %d\n", loc_address(e));
	printf("proc_has_setjmp    = %d\n", proc_has_setjmp(e));
	printf("proc_has_lv        = %d\n", proc_has_lv(e));
	printf("isrecursive        = %d\n", isrecursive(e));
	printf("proc_uses_crt_env  = %d\n", proc_uses_crt_env(e));
	printf("proc_uses_external = %d\n", proc_uses_external(e));
	printf("PROCPROPS\n");
	printf("proc_has_vcallees  = %d\n", proc_has_vcallees(e));
	printf("proc_has_vcallers  = %d\n", proc_has_vcallers(e));
	printf("proc_has_checkstack= %d\n", proc_has_checkstack(e));
	printf("proc_has_nolongj   = %d\n", proc_has_nolongj(e));
}

void
solve_props(exp e)
{
	UNUSED(e);

#ifdef POWER
	printf("is_copying_solve = %d\n", is_copying_solve(e));
#endif
}

void
movecont_props(exp e)
{
	printf("isnooverlap = %d\n", isnooverlap(e));
}

void
cont_props(exp e)
{
	printf("to_propagate = %d\n", to_propagate(e));
}

void
labst_props(exp e)
{
	printf("is_loaded_lv = %d\n", is_loaded_lv(e));
	printf("isunroll     = %d\n", isunroll(e));
}

void
name_props(exp e)
{
	printf("islastuse   = %d\n", islastuse(e));
	printf("isloadparam = %d\n", isloadparam(e));
	printf("isreallyass = %d\n", isreallyass(e));
}

void
string_props(exp e)
{
	printf("string_char_size = %d\n", string_char_size(e));
}

void
val_props(exp e)
{
	printf("isbigval = %d\n", isbigval(e));
}

void
rep_props(exp e)
{
	printf("isunrolled = %d\n", isunrolled(e));
}

void
apply_props(exp e)
{
	printf("istoinline = %d\n", istoinline(e));
}

#endif

