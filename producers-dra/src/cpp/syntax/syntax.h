/*
 * Automatically generated from the files:
 *	syntax.sid
 * and
 *	syntax.act
 * by:
 *	sid
 */

/* BEGINNING OF HEADER */


/*
    		 Crown Copyright (c) 1997, 1998
    
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


#ifndef SYNTAX_INCLUDED
#define SYNTAX_INCLUDED


/* BEGINNING OF FUNCTION DECLARATIONS */

#ifndef __SID_SPLIT
extern void parse_init(IDENTIFIER, EXP *);
extern void parse_tok_type(TYPE *);
extern void parse_type_param(IDENTIFIER *);
extern void parse_type(TYPE *);
extern void parse_file(TYPE, DECL_SPEC);
extern void parse_offset(OFFSET, TYPE, OFFSET *, TYPE *);
extern void parse_nat(EXP *);
extern void parse_param(TYPE, int, IDENTIFIER *);
extern void parse_func(EXP *);
extern void parse_id(IDENTIFIER *);
extern void parse_exp(EXP *);
extern void parse_stmt(EXP *);
extern void parse_mem_type(TYPE *);
extern void parse_operator(IDENTIFIER *);
extern void parse_decl(TYPE, DECL_SPEC);
#else /* __SID_SPLIT */
extern void ZR1270(EXP *);
extern void ZR510(BASE_TYPE *);
extern void ZR1019(NAMESPACE);
extern void ZR1400(NAMESPACE *, IDENTIFIER *, IDENTIFIER *);
extern void ZR910(TYPE, BASE_TYPE *, TYPE *, CV_SPEC *, DECL_SPEC *);
extern void ZR1147(EXP, EXP *);
extern void ZR416(void);
extern void ZR477(NAMESPACE, IDENTIFIER *);
extern void ZR948(IDENTIFIER, TYPE *, int *);
extern void ZR973(TYPE, int, IDENTIFIER *);
extern void ZR437(EXP *);
extern void ZR1404(NAMESPACE *, IDENTIFIER *, IDENTIFIER *);
extern void ZR1151(TYPE, TYPE *);
extern void ZR427(NAMESPACE *);
extern void ZR701(EXP *);
extern void ZR1407(NAMESPACE *, IDENTIFIER *, IDENTIFIER *);
extern void ZR518(NAMESPACE, IDENTIFIER *);
extern void ZR908(TYPE, BASE_TYPE *, TYPE *, CV_SPEC *, DECL_SPEC *);
extern void parse_init(IDENTIFIER, EXP *);
extern void ZR1029(TYPE, DECL_SPEC);
extern void ZR954(TYPE *);
extern void ZR683(EXP, EXP *);
extern void ZR844(void);
extern void ZR1010(DECL_SPEC, BASE_TYPE, TYPE, ACCESS_LIST);
extern void ZR1035(TYPE, DECL_SPEC, EXP *);
extern void ZR1286(EXP *);
extern void ZR1004(IDENTIFIER, SID_LIST_EXP *);
extern void ZR778(EXP *);
extern void ZR1288(EXP *);
extern void ZR504(IDENTIFIER *);
extern void ZR1021(EXP, EXP *, EXP *);
extern void ZR473(IDENTIFIER *);
extern void ZR763(int, IDENTIFIER *);
extern void ZR819(BASE_TYPE *);
extern void ZR1001(IDENTIFIER, SID_LIST_EXP *);
extern void ZR1163(TYPE, IDENTIFIER, TYPE *, IDENTIFIER *);
extern void ZR836(EXP *);
extern void parse_tok_type(TYPE *);
extern void ZR1291(EXP *, EXP *);
extern void ZR618(void);
extern void ZR622(EXP *);
extern void ZR1018(NAMESPACE);
extern void ZR1292(EXP *, SID_LIST_EXP *);
extern void ZR646(EXP *);
extern void ZR1293(EXP *);
extern void ZR584(int *);
extern void parse_type_param(IDENTIFIER *);
extern void ZR834(TYPE, DECL_SPEC);
extern void ZR1169(EXP, EXP *);
extern void ZR414(void);
extern void ZR554(int, EXP *);
extern void ZR594(int, EXP *);
extern void ZR478(IDENTIFIER *);
extern void ZR919(TYPE *, BASE_TYPE *, TYPE *, CV_SPEC *, DECL_SPEC *, BASE_TYPE *, TYPE *, CV_SPEC *, DECL_SPEC *);
extern void ZR773(EXP *);
extern void ZR1074(TYPE, DECL_SPEC, EXP *);
extern void ZR961(TYPE *, IDENTIFIER *);
extern void ZR1431(int *, int *, int *, EXP *);
extern void ZR963(TYPE, TYPE *, IDENTIFIER *);
extern void ZR1058(EXP *);
extern void ZR1432(int *, EXP *);
extern void ZR570(TYPE, EXP *);
extern void ZR634(EXP *);
extern void ZR946(int, TYPE *);
extern void ZR1433(int *);
extern void ZR1179(TYPE, IDENTIFIER, int, TYPE *, IDENTIFIER *, int *);
extern void ZR1434(int *);
extern void ZR944(IDENTIFIER *);
extern void parse_type(TYPE *);
extern void ZR1098(IDENTIFIER *);
extern void ZR1129(OFFSET, TYPE, OFFSET *, TYPE *);
extern void ZR1435(IDENTIFIER *, EXP *);
extern void ZR474(IDENTIFIER *);
extern void ZR993(TYPE *);
extern void ZR1031(EXP *);
extern void ZR942(TYPE *, IDENTIFIER *, int *);
extern void ZR613(EXP *);
extern void ZR738(EXP *, EXP *);
extern void ZR989(TYPE *);
extern void ZR1438(EXP *, EXP *);
extern void ZR865(IDENTIFIER);
extern void ZR952(TYPE, TYPE *, IDENTIFIER *, int *);
extern void ZR1006(int, IDENTIFIER, EXP *);
extern void parse_file(TYPE, DECL_SPEC);
extern void ZR1026(EXP *);
extern void ZR1112(int *);
extern void parse_offset(OFFSET, TYPE, OFFSET *, TYPE *);
extern void parse_nat(EXP *);
extern void ZR1441(EXP *);
extern void ZR1314(NAMESPACE *, IDENTIFIER *, IDENTIFIER *);
extern void ZR651(EXP *);
extern void parse_param(TYPE, int, IDENTIFIER *);
extern void ZR1442(EXP *);
extern void ZR1315(NAMESPACE *, IDENTIFIER *);
extern void ZR875(BASE_TYPE *, TYPE *, CV_SPEC *);
extern void ZR503(IDENTIFIER *);
extern void ZR1106(SID_LIST_TYPE *);
extern void ZR1317(NAMESPACE *, NAMESPACE *, IDENTIFIER *);
extern void ZR1190(EXP, EXP, int, EXP *, EXP *, int *);
extern void ZR485(IDENTIFIER *);
extern void ZR953(TYPE *);
extern void parse_func(EXP *);
extern void ZR517(IDENTIFIER *, BASE_TYPE *);
extern void ZR835(void);
extern void ZR1319(NAMESPACE *, NAMESPACE *, IDENTIFIER *);
extern void ZR505(IDENTIFIER *);
extern void ZR896(DECL_SPEC *);
extern void parse_id(IDENTIFIER *);
extern void ZR1321(int *);
extern void ZR1194(EXP, EXP *);
extern void ZR1322(int *);
extern void ZR582(EXP *);
extern void ZR874(TYPE, BASE_TYPE *, TYPE *, CV_SPEC *);
extern void ZR943(int *);
extern void ZR957(TYPE, TYPE *);
extern void ZR1323(int *);
extern void ZR418(void);
extern void ZR1198(EXP, EXP *);
extern void ZR868(IDENTIFIER);
extern void ZR1326(TYPE *, BASE_TYPE *, BASE_TYPE *, TYPE *, CV_SPEC *);
extern void ZR737(EXP *);
extern void ZR1025(EXP *);
extern void ZR1128(OFFSET, TYPE, OFFSET *, TYPE *);
extern void ZR1327(TYPE *, BASE_TYPE *, TYPE *, CV_SPEC *);
extern void ZR616(EXP *);
extern void ZR840(TYPE, DECL_SPEC);
extern void ZR1328(int *);
extern void ZR739(EXP *);
extern void ZR1329(int *);
extern void ZR1202(EXP, EXP *);
extern void ZR569(TYPE *, int *);
extern void ZR624(EXP *);
extern void ZR1330(DECL_SPEC *);
extern void parse_exp(EXP *);
extern void ZR1077(BASE_TYPE *, DECL_SPEC *, TYPE *, ACCESS_LIST *, int *, IDENTIFIER *);
extern void ZR689(TYPE, DECL_SPEC, EXP *);
extern void ZR1078(BASE_TYPE *, DECL_SPEC *, TYPE *, ACCESS_LIST *);
extern void ZR637(EXP *);
extern void ZR1206(EXP, EXP *);
extern void parse_stmt(EXP *);
extern void ZR1089(DECL_SPEC, TYPE, BASE_TYPE, ACCESS_LIST, int);
extern void ZR549(TYPE *, int *);
extern void ZR645(EXP *);
extern void ZR955(EXP *);
extern void ZR688(TYPE, DECL_SPEC);
extern void ZR1030(void);
extern void ZR1210(EXP, EXP *);
extern void ZR452(int *);
extern void ZR417(void);
extern void ZR499(SID_LIST_EXP *);
extern void ZR1341(TYPE *, BASE_TYPE *, TYPE *, CV_SPEC *, DECL_SPEC *);
extern void ZR1214(EXP, EXP *);
extern void ZR497(EXP *);
extern void ZR1342(void);
extern void ZR501(SID_LIST_EXP *);
extern void ZR1470(IDENTIFIER *, EXP *);
extern void ZR630(EXP *);
extern void ZR754(EXP *);
extern void ZR553(TYPE *, EXP *, int *);
extern void ZR700(EXP *, EXP *, int *);
extern void ZR787(CV_SPEC *);
extern void ZR1472(IDENTIFIER *, EXP *);
extern void ZR1218(EXP, EXP *);
extern void ZR1024(EXP, EXP *);
extern void ZR1346(NAMESPACE *, IDENTIFIER *);
extern void ZR1601(EXP *, EXP *);
extern void ZR1474(IDENTIFIER *, EXP *);
extern void ZR1347(NAMESPACE *, IDENTIFIER *);
extern void ZR790(CV_SPEC *);
extern void ZR1475(NAMESPACE *, EXP *);
extern void ZR1348(IDENTIFIER *);
extern void ZR1094(BASE_TYPE *, DECL_SPEC *, TYPE *, ACCESS_LIST *, IDENTIFIER *);
extern void ZR714(EXP *);
extern void ZR1476(NAMESPACE *, EXP *);
extern void ZR1222(EXP, EXP *);
extern void ZR1477(EXP *);
extern void ZR849(int *);
extern void ZR992(TYPE *);
extern void ZR1605(void);
extern void ZR428(NAMESPACE *);
extern void ZR664(void);
extern void ZR786(CV_SPEC *);
extern void ZR837(void);
extern void ZR1226(EXP, EXP *);
extern void ZR597(void);
extern void ZR1086(DECL_SPEC, TYPE, BASE_TYPE, ACCESS_LIST, int, IDENTIFIER *);
extern void ZR1608(NAMESPACE *, IDENTIFIER *);
extern void ZR429(NAMESPACE *);
extern void ZR1609(NAMESPACE *, IDENTIFIER *);
extern void ZR1000(IDENTIFIER, EXP *);
extern void ZR1091(TYPE, DECL_SPEC);
extern void ZR1610(IDENTIFIER *);
extern void ZR610(EXP *);
extern void ZR951(TYPE *, IDENTIFIER *, int *);
extern void ZR1230(EXP, EXP *);
extern void ZR715(EXP *);
extern void ZR492(EXP *);
extern void ZR572(SID_LIST_EXP *, TYPE *, int *);
extern void ZR678(EXP, EXP *);
extern void ZR1234(EXP, EXP *);
extern void ZR901(DECL_SPEC *);
extern void ZR663(EXP *);
extern void ZR956(TYPE *);
extern void ZR1238(EXP, EXP *);
extern void ZR772(EXP);
extern void ZR740(EXP *);
extern void ZR1367(DECL_SPEC *, TYPE *, BASE_TYPE *, ACCESS_LIST *, int *, IDENTIFIER *, IDENTIFIER *);
extern void ZR641(void);
extern void ZR671(EXP *);
extern void ZR1079(EXP *);
extern void ZR1127(OFFSET, TYPE, OFFSET *, TYPE *);
extern void ZR1242(EXP, EXP *);
extern void ZR509(IDENTIFIER *);
extern void ZR764(EXP);
extern void ZR1032(void);
extern void ZR1370(DECL_SPEC *, TYPE *, BASE_TYPE *, ACCESS_LIST *, int *, IDENTIFIER *, IDENTIFIER *);
extern void ZR603(EXP *);
extern void ZR476(NAMESPACE, int *);
extern void ZR829(DECL_SPEC *);
extern void ZR1054(void);
extern void ZR1373(TYPE *, IDENTIFIER *);
extern void parse_mem_type(TYPE *);
extern void ZR871(IDENTIFIER *);
extern void parse_operator(IDENTIFIER *);
extern void ZR1085(EXP *);
extern void ZR1254(TYPE *, BASE_TYPE *, TYPE *, CV_SPEC *, DECL_SPEC *);
extern void ZR628(EXP *);
extern void ZR753(EXP *);
extern void ZR810(BASE_TYPE *, TYPE *);
extern void ZR1256(TYPE *, DECL_SPEC *, BASE_TYPE *, TYPE *, CV_SPEC *, EXP *);
extern void ZR650(SID_LIST_EXP *);
extern void ZR977(int *);
extern void ZR1384(TYPE *, TYPE *);
extern void ZR1257(void);
extern void ZR1003(IDENTIFIER *, SID_LIST_EXP *);
extern void ZR438(EXP *);
extern void ZR941(SID_LIST_TYPE *);
extern void parse_decl(TYPE, DECL_SPEC);
extern void ZR1385(TYPE *);
extern void ZR1386(SID_LIST_TYPE *);
extern void ZR1259(void);
extern void ZR1260(EXP *);
extern void ZR626(EXP *);
extern void ZR680(EXP *);
extern void ZR1261(EXP *);
extern void ZR419(void);
extern void ZR632(EXP *);
extern void ZR653(EXP *);
extern void ZR1117(IDENTIFIER *);
extern void ZR500(SID_LIST_EXP *);
extern void ZR928(TYPE *);
extern void ZR1264(EXP *, EXP *);
extern void ZR847(void);
extern void ZR1064(TYPE, DECL_SPEC, EXP *);
extern void ZR619(EXP *);
extern void ZR1011(DECL_SPEC, BASE_TYPE, TYPE, ACCESS_LIST);
extern void ZR1266(EXP *, EXP *);
extern void ZR1268(NAMESPACE *, EXP *);
extern void ZR1141(TYPE, TYPE *);
extern void ZR887(BASE_TYPE *, TYPE *, CV_SPEC *, BASE_TYPE *, TYPE *, CV_SPEC *);
extern void ZR607(EXP *);
extern void ZR1396(NAMESPACE *, IDENTIFIER *);
extern void ZR1269(NAMESPACE *, EXP *);
extern int ZI0;
#endif /* __SID_SPLIT */

/* BEGINNING OF TERMINAL DEFINITIONS */

#define lex_double (102)
#define lex_arith_Hcap (177)
#define lex_macro_Harg (348)
#define lex_hash_Helse (28)
#define lex_private (142)
#define lex_incompatible (242)
#define lex_new_Harray_Hfull (351)
#define lex_ifdef (233)
#define lex_reject (291)
#define lex_compute (193)
#define lex_dollar (207)
#define lex_tendra (309)
#define lex_unreachable (323)
#define lex_vtable (330)
#define lex_inline (137)
#define lex_public (144)
#define lex_namespace_Hname (3)
#define lex_hash_H1 (51)
#define lex_either (208)
#define lex_hash_H2 (90)
#define lex_catch (128)
#define lex_const_Hcast (130)
#define lex_pointer (276)
#define lex_inset_Hstart (346)
#define lex_full_Hname (9)
#define lex_nested (264)
#define lex_suspend (306)
#define lex_break (95)
#define lex_begin (182)
#define lex_ignore (235)
#define lex_volatile_Ht (329)
#define lex_assign (36)
#define lex_endif (212)
#define lex_hash_Hhash_Hop (345)
#define lex_keyword (251)
#define lex_promote (283)
#define lex_wstring_Hlit (15)
#define lex_static (117)
#define lex_virtual (155)
#define lex_extend (220)
#define lex_this_Hname (311)
#define lex_minus_Hminus (61)
#define lex_lvalue (257)
#define lex_struct_Hcap (305)
#define lex_inset_Hend (347)
#define lex_lshift (57)
#define lex_open_Hround (65)
#define lex_false (135)
#define lex_block (184)
#define lex_scanf (297)
#define lex_wstring_Hexp (20)
#define lex_comma (42)
#define lex_union_Hcap (320)
#define lex_wchar_Hlit (13)
#define lex_func_Hcap (227)
#define lex_and_H1 (33)
#define lex_lshift_Heq (58)
#define lex_typeid (152)
#define lex_rvalue (295)
#define lex_string_Hlit (14)
#define lex_rshift (75)
#define lex_sizeof (116)
#define lex_and_H2 (157)
#define lex_unknown (0)
#define lex_wchar_Hexp (18)
#define lex_after (169)
#define lex_macro (258)
#define lex_precedence (279)
#define lex_undef (318)
#define lex_type_Hname (2)
#define lex_switch (119)
#define lex_assert (180)
#define lex_octal (269)
#define lex_ptrdiff_Ht (286)
#define lex_ident (231)
#define lex_printf (281)
#define lex_string_Hexp (19)
#define lex_and_Heq_H1 (34)
#define lex_reinterpret_Hcast (145)
#define lex_depth (202)
#define lex_unused (324)
#define lex_char_Hlit (12)
#define lex_rshift_Heq (76)
#define lex_arrow_Hstar (82)
#define lex_float (106)
#define lex_class (129)
#define lex_and_Heq_H2 (158)
#define lex_bottom (185)
#define lex_nline (265)
#define lex_open_Hinit (352)
#define lex_extern (105)
#define lex_decl (197)
#define lex_proc_Hcap (282)
#define lex_string (304)
#define lex_typeof (315)
#define lex_while (125)
#define lex_conditional (194)
#define lex_new_Harray (350)
#define lex_char_Hexp (17)
#define lex_code (189)
#define lex_option (273)
#define lex_reachable (289)
#define lex_colon (41)
#define lex_case (96)
#define lex_import (238)
#define lex_char (97)
#define lex_value (326)
#define lex_logical_Hand_H1 (55)
#define lex_fall (223)
#define lex_tag_Hcap (308)
#define lex_logical_Hand_H2 (160)
#define lex_allow (172)
#define lex_array (178)
#define lex_elif (209)
#define lex_file (224)
#define lex_limit (252)
#define lex_name (262)
#define lex_hash_Hif (26)
#define lex_return (113)
#define lex_token (312)
#define lex_close_Hbrace_H1 (38)
#define lex_export (134)
#define lex_reset (293)
#define lex_close_Hbrace_H2 (88)
#define lex_compatible (191)
#define lex_extra (222)
#define lex_main (259)
#define lex_destructor_Hname (5)
#define lex_nat_Hcap (263)
#define lex_type_Hcap (314)
#define lex_struct (118)
#define lex_using (154)
#define lex_close_Htemplate (338)
#define lex_identifier (1)
#define lex_const (98)
#define lex_line (253)
#define lex_weak (332)
#define lex_else (103)
#define lex_delete_Harray_Hfull (342)
#define lex_union (121)
#define lex_statement_Hname (4)
#define lex_cast (186)
#define lex_error (215)
#define lex_arrow (35)
#define lex_bool (127)
#define lex_stmt_Hcap (303)
#define lex_unify (319)
#define lex_minus (59)
#define lex_new_Hfull (349)
#define lex_definition (201)
#define lex_int_Hcap (250)
#define lex_array_Hop (335)
#define lex_not_H1 (62)
#define lex_quote (288)
#define lex_backslash (37)
#define lex_long (111)
#define lex_not_H2 (162)
#define lex_exp_Hcap (218)
#define lex_dot_Hstar (84)
#define lex_short (114)
#define lex_namespace (139)
#define lex_character (187)
#define lex_minus_Heq (60)
#define lex_void (123)
#define lex_cond_Hop (339)
#define lex_hash_Hop (344)
#define lex_reference (290)
#define lex_not_Heq_H1 (63)
#define lex_abs (85)
#define lex_enum (104)
#define lex_throw (149)
#define lex_not_Heq_H2 (163)
#define lex_incomplete (243)
#define lex_interface (247)
#define lex_end (211)
#define lex_less (53)
#define lex_xor_H1 (80)
#define lex_this (148)
#define lex_wchar_Ht (156)
#define lex_xor_H2 (166)
#define lex_all (171)
#define lex_eof (32)
#define lex_close_Hsquare_H1 (40)
#define lex_plus_Hplus (71)
#define lex_auto (94)
#define lex_goto (108)
#define lex_star (78)
#define lex_close_Hsquare_H2 (89)
#define lex_into (249)
#define lex_no_Hdef (267)
#define lex_off (271)
#define lex_func_Hop (343)
#define lex_environment (213)
#define lex_tag (307)
#define lex_less_Heq (54)
#define lex_xor_Heq_H1 (81)
#define lex_xor_Heq_H2 (167)
#define lex_size_Ht_H2 (300)
#define lex_unmatched (321)
#define lex_or_H1 (67)
#define lex_assignment (181)
#define lex_open_Hbrace_H1 (64)
#define lex_star_Heq (79)
#define lex_or_H2 (164)
#define lex_open_Hbrace_H2 (92)
#define lex_asm (126)
#define lex_true (150)
#define lex_un_Hknown (316)
#define lex_nested_Hname_Hstar (10)
#define lex_div (44)
#define lex_type (313)
#define lex_open_Htemplate (353)
#define lex_or_Heq_H1 (68)
#define lex_rem (73)
#define lex_min (87)
#define lex_dynamic_Hcast (132)
#define lex_directive (203)
#define lex_writeable (333)
#define lex_plus (69)
#define lex_or_Heq_H2 (165)
#define lex_max (86)
#define lex_text (310)
#define lex_delete_Harray (341)
#define lex_dot (46)
#define lex_for (107)
#define lex_bitfield (183)
#define lex_qualifier (287)
#define lex_div_Heq (45)
#define lex_rem_Heq (74)
#define lex_lit (255)
#define lex_sort (301)
#define lex_plus_Heq (70)
#define lex_new (140)
#define lex_variable (327)
#define lex_int (110)
#define lex_std (302)
#define lex_builtin_Hfile (336)
#define lex_conversion (195)
#define lex_exhaustive (217)
#define lex_set (298)
#define lex_logical_Hor_H1 (56)
#define lex_use (325)
#define lex_semicolon (77)
#define lex_if (109)
#define lex_logical_Hor_H2 (161)
#define lex_hash_Hpragma (30)
#define lex_protected (143)
#define lex_indented (244)
#define lex_implement (236)
#define lex_ambiguous (173)
#define lex_define_Hcap (199)
#define lex_do (101)
#define lex_decimal (196)
#define lex_defined (200)
#define lex_template_Htype (7)
#define lex_as (179)
#define lex_builtin_Hline (337)
#define lex_of (270)
#define lex_floating_Hexp (22)
#define lex_eq (48)
#define lex_open_Hsquare_H1 (66)
#define lex_open_Hsquare_H2 (93)
#define lex_nested_Hname (8)
#define lex_include_Hnext (241)
#define lex_hash_Hhash_H1 (52)
#define lex_hash_Hhash_H2 (91)
#define lex_delete_Hfull (340)
#define lex_directory (204)
#define lex_resolution (294)
#define lex_includes (240)
#define lex_template_Hid (6)
#define lex_hash_Hendif (29)
#define lex_no (266)
#define lex_on (272)
#define lex_scalar_Hcap (296)
#define lex_complete (192)
#define lex_discard (206)
#define lex_linkage (254)
#define lex_member_Hcap (261)
#define lex_size_Ht (299)
#define lex_try (151)
#define lex_implicit (237)
#define lex_zzzzzz (354)
#define lex_template (147)
#define lex_overload (275)
#define lex_unsigned (122)
#define lex_internal (248)
#define lex_unpostpone (322)
#define lex_alignof (170)
#define lex_disallow (205)
#define lex_volatile (124)
#define lex_longlong (256)
#define lex_explicit (133)
#define lex_static_Hcast (146)
#define lex_ellipsis_Hexp (210)
#define lex_identif (232)
#define lex_typename (153)
#define lex_argument (176)
#define lex_external (221)
#define lex_include (239)
#define lex_default (100)
#define lex_analysis (174)
#define lex_ellipsis (47)
#define lex_colon_Hcolon (83)
#define lex_continue (99)
#define lex_register (112)
#define lex_zzzz (334)
#define lex_integer_Hlit (16)
#define lex_function (228)
#define lex_variety_Hcap (328)
#define lex_greater (49)
#define lex_mutable (138)
#define lex_define (198)
#define lex_integer_Hexp (21)
#define lex_complex_Htype (25)
#define lex_anonymous (175)
#define lex_ifndef (234)
#define lex_promoted (284)
#define lex_full_Hname_Hstar (11)
#define lex_operator (141)
#define lex_preserve (280)
#define lex_close_Hround (39)
#define lex_initialization (245)
#define lex_integer (246)
#define lex_greater_Heq (50)
#define lex_accept (168)
#define lex_equality (214)
#define lex_escape (216)
#define lex_complex_Hstmt (24)
#define lex_typedef (120)
#define lex_explain (219)
#define lex_hash_Helif (27)
#define lex_newline (31)
#define lex_delete (131)
#define lex_hiding (230)
#define lex_comment (190)
#define lex_complex_Hexp (23)
#define lex_forward (226)
#define lex_overflow (274)
#define lex_object (268)
#define lex_unassert (317)
#define lex_warning (331)
#define lex_friend (136)
#define lex_member (260)
#define lex_pragma (278)
#define lex_compl_H1 (43)
#define lex_class_Hcap (188)
#define lex_float_Hcap (225)
#define lex_hexadecimal (229)
#define lex_prototype (285)
#define lex_question (72)
#define lex_signed (115)
#define lex_compl_H2 (159)
#define lex_postpone (277)
#define lex_representation (292)

/* BEGINNING OF TRAILER */




/*
    DUMMY LEXICAL TOKEN VALUES

    These values are used as lexical token values in certain circumstances
    but do not represent actual tokens.  Note that they are all negative.
*/

#define lex_ignore_token	-1
#define lex_end_condition	-2
#define lex_included		-3


#endif

/* END OF FILE */