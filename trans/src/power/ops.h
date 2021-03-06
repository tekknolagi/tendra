/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 * Copyright 1993, Open Software Foundation, Inc.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#ifndef OPS_H
#define OPS_H

int comm_op(exp , space , where , Instruction_P);
int non_comm_op(exp , space , where , Instruction_P);

int fop(exp , space , where , Instruction_P);
int fmop(exp , space , where , Instruction_P);

#endif

