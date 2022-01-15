/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Interrupts.h
* Module Description: Interrupt API
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          2 %
 * %derived_by:       xz0btk %
 * %date_modified:    Tue Jul 30 15:54:48 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial K2xx Synergy Version
 */

#ifndef INTERRUPTS_H 
#define INTERRUPTS_H  

/***************************************************************************************************
* Include files
***************************************************************************************************/

#include "Platform_Types.h"

/**************************************************************************************************
* Global function externs
**************************************************************************************************/

extern void EnableCanInterrupt(void);
extern void EnableMtrCtlInterrupt(void);
extern void EnableEeSpiInterrupt(void);
extern void EnableSysTickInterrupt(void);
extern void EnableESMLInterrupt(void);
extern void EnableCRCInterrupt(void);

extern void DisableMtrCtlInterrupt(void);
extern void DisableSysTickInterrupt(void);
extern void DisableCanInterrupt(void);

#endif /*INTERRUPTS_H*/


