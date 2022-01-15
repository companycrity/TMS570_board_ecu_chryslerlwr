/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : tcram_regs.h
* Module Description: TCRAM (Tightly-Coupled RAM Wrapper) Peripheral Registers
* Product           : Gen II Plus - EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue May 31 09:10:25 2011 % 
* %version:          1 %
* %derived_by:       czgng4 %
* %date_modified:    Tue Jun  5 09:52:53 2012 % 
*---------------------------------------------------------------------------*/

#ifndef TCRAM_REGS_H
#define TCRAM_REGS_H

/*****************************************************************************
* Include files
*****************************************************************************/
#include "Std_Types.h"

typedef volatile struct tcramctrlregs
{
	uint32 RAMCTRL;
	uint32 RAMTHRESHOLD;
	uint32 RAMOCCUR;
	uint32 RAMINTCTRL;
	uint32 RAMERRSTATUS;
	uint32 RAMSERRADDR;
	uint32 : 32;
	uint32 RAMUERRADDR;
	uint32 : 32;
	uint32 : 32;
	uint32 : 32;
	uint32 : 32;
	uint32 RAMTEST;
	uint32 : 32;
	uint32 RAMADDRDECVECT;
	uint32 RAMPERRADDR;
}tcramctrlregs_t;

#define TCRAM0 ((tcramctrlregs_t *)0xFFFFF800)
#define TCRAM1 ((tcramctrlregs_t *)0xFFFFF900)

#endif

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
05/31/11   1.0      LWW      Initial Creation
******************************************************************************/
