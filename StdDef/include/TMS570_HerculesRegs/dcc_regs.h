/*****************************************************************************
* Copyright 2012 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : dcc_regs.h
* Module Description: DCC (Dual-Clock Comparator) Registers
* Product           : Gen II Plus - EA3.0
* Author            : Lonnie Newton
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue May 31 09:10:25 2011 % 
* %version:          1 %
* %derived_by:       kzshz2 %
* %date_modified:    Fri Jun 29 14:54:29 2012 % 
*---------------------------------------------------------------------------*/

#ifndef DCC_REGS_H
#define DCC_REGS_H

/*****************************************************************************
* Include files
*****************************************************************************/
#include "Std_Types.h"

typedef volatile struct dccctrlregs
{
	uint32 DCCGCTRL;					/* 0x00 */
	uint32 DCCREV;						/* 0x04 */
	uint32 DCCCNT0SEED;					/* 0x08 */
	uint32 DCCVALID0SEED;					/* 0x0C */
	uint32 DCCCNT1SEED;					/* 0x10 */
	uint32 DCCSTAT;						/* 0x14 */
	uint32 DCCDCNT0;					/* 0x18 */
	uint32 DCCVALID0;					/* 0x1C */
	uint32 DCCDCNT1;					/* 0x20 */
	uint32 DCCCNT1CLKSRC;					/* 0x24 */
	uint32 DCCCNT0CLKSRC;					/* 0x28 */
}dccctrlregs_t;


#define DCCCTRLREG1 ((dccctrlregs_t *)0xFFFFEC00)
#define DCCCTRLREG2 ((dccctrlregs_t *)0xFFFFF400)


#endif

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
06/29/12   1.0      LN      	Initial Creation		  CR5400
******************************************************************************/
