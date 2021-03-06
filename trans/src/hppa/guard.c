/*
 * Copyright 2011-2012, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

/*
 * These routines protect registers from future use. The type involved
 * is space which consists of two long ints with bit patterns taken to
 * represent usage of temporary fixed and floating point registers.
 * These bits are used in the procedure getregs which understands
 * a clear bit to mean that the corresponding register is free for use.
 *
 * The procedures are widely used in make_code which may use getreg
 * to choose a register to contain the result of an expression.
 *
 * If this expression is the first operand of a binary operation (say)
 * then the register is guarded, producing another space which will be
 * used by make_code for the second operand.
 */

#include <shared/bool.h>
#include <shared/error.h>

#include <refactor/optimise.h>

#include <main/print.h>

#include "reg.h"
#include "procrec.h"
#include "addr.h"
#include "tempdecs.h"
#include "guard.h"

/*
 * The integer parameter to procedures guardreg and guardfreg is taken
 * to be a register which needs to be protected. For floating point
 * registers a factor of 2 is involved. The corresponding bit in the
 * appropriate field of the space i.e fixed or float, is therefore set.
 */
space
guardreg(int r, space sp)
{
  if (IS_TREG(r))
  {
    sp.fixed |= RMASK(r);
  }				/* set bit in the fixed field of sp */
  return sp;
}

space
guardfreg(int r, space sp)
{
  if (IS_FLT_TREG(r))		/* r is a floating point t reg */
  {
    sp.flt |= RMASK(r);
  }				/* set bit in the flt field of sp */
  return sp;
}

/*
 * needreg is like guardreg, except it is an error if the reg is alread in use.
 * Used, eg, when claiming regs that will be damaged, as in a call.
 */
space
needreg(int r, space sp)
{
  /* tempdec() can allocate t regs if dead over calls, so dont fail */
#if 0 /* !!!! */
  if (!(optim & OPTIM_TEMPDEC && IS_TREG(r)) && (sp.fixed & RMASK(r)) != 0)
  {
    asm_comment("needreg: %d", r);
    error(ERR_SERIOUS, "needreg: fixed reg already in use");
  }
#endif
  return guardreg(r, sp);
}

/*
 * The procedure guard may also protect a register involved in addressing
 * depending on the value of the parameter of type where. This is a union of
 * a fixpnt reg, a float reg and an instore value. In the latter case the
 * register involved in the addressing can be deduced from the base field
 * of the instore value. These types are defined in addr.h.
 */
space
guard(where w, space sp)
{
  switch (discrim ( w.answhere ) )
  {
    case inreg:
    {
      int r = regalt(w.answhere);

      if (IS_TREG(r))
      {
	sp.fixed |= RMASK(r);
      }				/* guard reg */
      return sp;
    }
  case infreg:
    {
      int r = fregalt(w.answhere).fr;

      if (IS_FLT_TREG(r))
      {
	sp.flt |= RMASK(r);
      }				/* guard freg */
      return sp;
    }
#if USE_BITAD
  case bitad:
#endif
  case notinreg:
    {
      int r = insalt(w.answhere).b.base;

      if (IS_TREG(r))
      {
	sp.fixed |= RMASK(r);
      }
      /* guard fixed point t reg used as base of address */
      return sp;
    }
  case insomereg:
  case insomefreg:
    {
      asm_comment("guard: BAD discrim %d", (int) discrim ( w.answhere ) );
      error(ERR_SERIOUS, "guard: Guard ? reg");
      return sp;
    }
  default:
    {
      asm_comment("guard: BAD discrim %d", (int) discrim ( w.answhere ) );
      error(ERR_SERIOUS, "guard: not in switch");
      return sp;
    }
  }
}

