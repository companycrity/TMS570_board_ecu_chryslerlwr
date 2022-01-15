/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : vim_regs.h
* Module Description: VIM (Vectored Interrupt Manager) Peripheral Registers
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec 14 14:58:07 2010
* %version:          1 %
* %derived_by:       czgng4 %
* %date_modified:    Tue Jun  5 09:52:54 2012 % 
*---------------------------------------------------------------------------*/

#ifndef VIM_REGS_H
#define VIM_REGS_H

/*****************************************************************************
* Include files
*****************************************************************************/
#include "Std_Types.h"

typedef volatile struct vimctrlregs
{
    uint32 : 24;			/* 0x0000        */
    uint32 IRQIVEC : 8;		/* 0x0000        */
    uint32 : 24;			/* 0x0004        */
    uint32 FIQIVEC : 8;		/* 0x0004        */
    uint32 : 32;			/* 0x0008        */
    uint32 : 32;			/* 0x000C        */
    uint32 FIRQPR0;			/* 0x0010        */
    uint32 FIRQPR1;			/* 0x0014        */
    uint32 FIRQPR2;			/* 0x0018        */
    uint32 FIRQPR3;			/* 0x001C        */
    uint32 INTREQ0;			/* 0x0020        */
    uint32 INTREQ1;			/* 0x0024        */
    uint32 INTREQ2;			/* 0x0028        */
    uint32 INTREQ3;			/* 0x002C        */
    uint32 REQMASKSET0;		/* 0x0030        */
    uint32 REQMASKSET1;		/* 0x0034        */
    uint32 REQMASKSET2;		/* 0x0038        */
    uint32 REQMASKSET3;		/* 0x003C        */
    uint32 REQMASKCLR0;		/* 0x0040        */
    uint32 REQMASKCLR1;		/* 0x0044        */
    uint32 REQMASKCLR2;		/* 0x0048        */
    uint32 REQMASKCLR3;		/* 0x004C        */
    uint32 WAKEMASKSET0;	/* 0x0050        */
    uint32 WAKEMASKSET1;	/* 0x0054        */
    uint32 WAKEMASKSET2;	/* 0x0058        */
    uint32 WAKEMASKSET3;	/* 0x005C        */
    uint32 WAKEMASKCLR0;	/* 0x0060        */
    uint32 WAKEMASKCLR1;	/* 0x0064        */
    uint32 WAKEMASKCLR2;	/* 0x0068        */
    uint32 WAKEMASKCLR3;	/* 0x006C        */
    uint32 IRQVECREG;		/* 0x0070        */
    uint32 FIQVECREG;		/* 0x0074        */
    uint32 : 9;				/* 0x0078        */
    uint32 CAPEVTSRC1 : 7;	/* 0x0078        */
    uint32 : 9;				/* 0x0078        */
    uint32 CAPEVTSRC0 : 7;	/* 0x0078        */
    uint32 : 32;			/* 0x007C        */
    uint8 CHANMAP[64];		/* 0x0080-0x017C */
}vimctrlregs_t;

typedef volatile struct vimparctrlregs
{
    uint32 PARFLG;			/* 0x0000        */
    uint32 PARCTL;			/* 0x0004        */
    uint32 ADDERR;			/* 0x0008        */
    uint32 FBPARERR;		/* 0x000c        */
}vimparctrlregs_t;

#define VIM ((vimctrlregs_t *)0xFFFFFE00)
#define VIMPAR ((vimparctrlregs_t *)0xFFFFFDEC)

#endif

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
12/14/10   1.0      JJW      Initial Creation
05/31/11   2.0      LWW      Fixed Register Name
10/13/11   3.0      LWW      Added parity registers
******************************************************************************/
