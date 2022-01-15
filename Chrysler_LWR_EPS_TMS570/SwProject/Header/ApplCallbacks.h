/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : ApplCallbacks.h
* Module Description: Application defined Callback functions
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          EA3#5.1.2 %
 * %derived_by:       gz324f %
 * %date_modified:    Tue Oct 22 12:01:00 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial K2xx Synergy Version
 * 01/10/12  2        LWW       Added extern of SystemTick function
 * 01/25/12  3        LWW       Updates for manual partnumber block transfer
 * 04/18/12  5		  LWW       Block transfer on EOL Mtr Param
 * 05/24/13  6		  SAH       Added deprecated EOL Mtr Param
 * 06/19/13  4		  SAH       Added deprecated Nom Mtr Param
 * 07/17/13  5        M. Story  Added ECU Reset
 * 10/21/13  6        SAH		Added Deprecated DEM block
 * 08/12/16  7        SV		Removed unused code
 */
#ifndef APPLCALLBACKS_H
#define APPLCALLBACKS_H


#define Rte_Call_NvM_RpNotifyJobEnd_NVM_BLOCK_SER_METADATA_APPLICATION_JobFinished(sid, res)     Appdesc_MCU_Reset()

extern uint8 Appdesc_MCU_Reset(void);
extern void Appl_WaitNvMReady(const uint16 blockNumber, const boolean fastMode);
extern void SystemTick(void);

extern VAR(Boolean, AP_SRLCOMINPUT_VAR_INIT) ECUReset_G_lgc;
#endif /*APPLCALLBACKS_H*/
