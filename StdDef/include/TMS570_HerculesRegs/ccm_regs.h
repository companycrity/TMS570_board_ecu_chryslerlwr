/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : ccm_regs.h
* Module Description: CCM (Core Compare Module) Peripheral Registers
* Product           : Gen II Plus - EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue May 31 09:10:25 2011 % 
* %version:          1 %
* %derived_by:       czgng4 %
* %date_modified:    Tue Jun  5 09:52:08 2012 % 
*---------------------------------------------------------------------------*/

#ifndef CCM_REGS_H
#define CCM_REGS_H

/*****************************************************************************
* Include files
*****************************************************************************/
#include "Std_Types.h"

typedef volatile struct ccmctrlregs
{
    uint32 CCMSR;		/* 0x0000 */
    uint32 CCMKEYR;		/* 0x0004 */
} ccmctrlregs_t;

#define CCMREG ((ccmctrlregs_t *)0xFFFFF600U)

#endif
