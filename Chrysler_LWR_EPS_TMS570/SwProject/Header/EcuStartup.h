/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : EcuStartup.h
* Module Description: AUTOSAR Startup Sequence
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          2 %
 * %derived_by:       jzh87w %
 * %date_modified:    Wed Jan 29 12:54:02 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial K2xx Synergy Version
 * 01/27/14  2	      SAH       Updates to fix compiler warnings
 */

#ifndef ECUSTARTUP_H 
#define ECUSTARTUP_H  

/***************************************************************************************************
* Include files
***************************************************************************************************/

#include "Platform_Types.h"

/**************************************************************************************************
* Defines / Constants
**************************************************************************************************/



/* Prototypes */
extern void EcuStartup_Init1(void);
extern void EcuStartup_Init2(void);
extern FUNC(void, RTE_CD_UDIAG_APPL_CODE) uDiagCCRM_Init(void);
extern FUNC(void, RTE_CD_UDIAG_APPL_CODE) uDiagClockMonitor_Init(void);
extern FUNC(void, RTE_CD_UDIAG_APPL_CODE) uDiagECC_Init(void);
extern FUNC(void, RTE_CD_UDIAG_APPL_CODE) uDiagESM_Init(void);
extern FUNC(void, RTE_CD_UDIAG_APPL_CODE) uDiagIOMM_Init(void);
extern FUNC(void, RTE_CD_UDIAG_APPL_CODE) uDiagParity_Init(void);
extern FUNC(void, RTE_CD_UDIAG_APPL_CODE) uDiagStaticRegs_Init(void);
extern FUNC(void, RTE_CD_UDIAG_APPL_CODE) uDiagVIM_Init(void);
#endif /*ECUSTARTUP_H*/


