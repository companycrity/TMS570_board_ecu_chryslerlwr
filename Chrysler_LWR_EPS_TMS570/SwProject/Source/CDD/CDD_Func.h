/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CDD_Func.h
* Module Description: Header file for functions communicated between Nexteer
*                      Complex Device Drivers (CDD)
* Product           : Gen II Plus - EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          3 %
 * %derived_by:       jzh87w %
 * %date_modified:    Wed May 29 11:25:36 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial K2xx Synergy Version
 * 12/15/11  2		  SAH		Added I2C functions
 * 04/19/12  4		  LWW		Added IPMTrqCogCancRefPer1 for IPM
 * 05/13/13	 '2'	  SAH		Added MicroDiag per, removed MtrCtrl functions
 * 05/24/13	 3	  	  SAH		Removed QuadDet
 */

#ifndef CDD_FUNC_H
#define CDD_FUNC_H

#include "Std_Types.h"

extern FUNC(void, SA_MTRPOS_CODE) MtrPos_Per1(void);
extern FUNC(void, RTE_AP_MICRODIAG_APPL_CODE) MicroDiag_Per1(void);

/* TODO: Determine if the  CalRamInit really needs to execute as a CDD early in init */
/*        if it is determined that RAM cals are only used after RTE Start, then this */
/*        function can be removed from here and scheduled in Developer               */
extern FUNC(void, XCP_CODE) Xcp_CalRamInit(void);

extern FUNC(uint8 *, EPSDIAGSRVCS_CODE) ReadTrqSnsrEEPROM(void);
extern FUNC(void, EPSDIAGSRVCS_CODE) WriteTrqSnsrEEPROM(uint8 address, uint8 data);

#endif
