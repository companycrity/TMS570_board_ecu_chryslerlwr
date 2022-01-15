/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CANCallbacks.c
* Module Description: Definition of CAN Releated Application Callback Functions
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          4 %
 * %derived_by:       xz0btk %
 * %date_modified:    Tue Jul 30 12:54:31 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial K2xx Synergy Version
 * 07/05/11  2        LWW       Additions for WIR messages
 * 08/04/11  3        LWW       Added more message support
 * 08/04/11  4        LWW       Added timeout handling for message
 * 09/27/11  5        LWW       Added Bus Off NTC call
 * 05/04/12	 '3'	  SAH		Added call to allow NM junior to perform busoff recovery
 * 07/30/13  4        JJW		Added Disable and Restore Interrupts callout for running Can driver in user mode
 *								Removed commented out function definitions and unused development error hooks to 
 *								improve the readability of the file and prevent future confusion.
 */

#include "Std_Types.h"
#include "can_inc.h"
#include "nm_basic.h"
#include "frfm.h"
#include "applfrfm.h"

void DCan1_level0_Irqfunc(void)
{
	CanIsr_0();
}

void ApplNmBasicBusOffStart(void) 
{
	dbkTxStop();
	dbkRxStop();
	// need to be reviewed based on your requirements
}
void ApplNmBasicBusOffEnd(void) 
{
	dbkTxStart();
	dbkRxStart();
	// need to be reviewed based on your requirements
}

void ApplNmBasicEnabledCom(void)
{
	dbkTxStart();
	dbkRxStart();
	// might need to be reviewed
}
void ApplNmBasicSwitchTransceiverOn(void)
{}

void ApplNmBasicDisabledCom(void)
{
	dbkTxStop();
	dbkRxStop();
	// might need to be reviewed
}
vuint8 ApplNmBasicSwitchTransceiverOff(void)
{
	return 1;
}

void ApplCanFullCanOverrun (void)
{
	// need to add counter/while loop to detect error
}

#if defined (FRFM_ENABLE_APPL_ENABLECOND)
/*******************************************************************************
* NAME:              ApplFrfmCheckOfApplEnableCond
*
* CALLED BY:         FrfmSetEventStatus, FrfmDebounceEventFailed, FrfmDebounceEventPassed, FrfmGetEnableConditions
* PRECONDITIONS:     -
*
* DESCRIPTION:       When processing enable condition checks, the FRFM asks the application for additional enable
*                    conditions by calling this function.
*                    By returning frfmFalse the application prohibits the storage/update of a DTC in the ChronoStack.
*                    A frfmTrue result will not automatically allow the storage/update as other enable conditions are
*                    consulted, too.
*                    Return value t_FrfmBool:
*                      frfmTrue Application enable condition is set to enabled.
*                      frfmFalse Application enable condition is set to disabled.
*******************************************************************************/
t_FrfmBool      ApplFrfmCheckOfApplEnableCond(t_FrfmDtcSfnType dtcSfn)
{
	return frfmTrue;
}
#endif

#if defined (FRFM_ENABLE_CLEAR_DTC_NOTIFY)
/*******************************************************************************
* NAME:              ApplFrfmDtcWillBeCleared
*
* CALLED BY:         FrfmClearDTC
* PRECONDITIONS:     -
*
* DESCRIPTION:       FRFM notifies the Application about the deletion of a specific DTC (group).
*                    Before calling this function the FRFM has checked that the DTC is supported.
*******************************************************************************/
void            ApplFrfmDtcWillBeCleared(t_FrfmDtcNumType toBeDeletedDtcCode)
{

}
#endif

#if defined (FRFM_ENABLE_CLEAR_DTC_NOTIFY)
/*******************************************************************************
* NAME:              ApplFrfmDtcWasCleared
*
* CALLED BY:         FrfmClearDTC
* PRECONDITIONS:     -
*
* DESCRIPTION:       FRFM notifies the Application that the deletion of a specific DTC (group) has finished.
*                    The API is the twin of ApplFrfmDtcWillBeCleared, and will be called at end of the clear request.
*******************************************************************************/
void            ApplFrfmDtcWasCleared(t_FrfmDtcNumType deletedDtcCode)
{

}
#endif


#if defined (FRFM_ENABLE_APPL_CLEARDIAGINFO)
/*******************************************************************************
* NAME:              ApplFrfmCheckClearDTC
*
* CALLED BY:         FrfmClearDTC
* PRECONDITIONS:     GENy feature active: Application callback for 'ClearDiagnosticInformation'
*
* DESCRIPTION:       Before clearing a DTC or DTC group the function FrfmClearDTC() triggers this callback function.
*                    If this callback results frfmFalse, function FrfmClearDTC() will abort the clearing with return
*                    code frfmRC_Failed. Typically this will abort the current diagnostic service request 0x14 with the
*                    negative return code 0x22 (ConditionsNotCorrect).
*                    Return value t_FrfmBool: Permission to delete the requested (range of) DTC(s)
*                      frfmTrue   DTC shall be cleared.
*                      frfmFalse  DTC must not be cleared.
*******************************************************************************/
t_FrfmBool      ApplFrfmCheckClearDTC(t_FrfmDtcNumType reqDtc)
{
	return frfmTrue;
}
#endif

#if defined (FRFM_ENABLE_APPL_CLEAR_HISTDATA)
/*******************************************************************************
* NAME:              ApplFrfmCheckIsVinOrigLocked
*
* CALLED BY:         FrfmClearHistoricalData
* PRECONDITIONS:     GENy feature active: Application callback 'Clear Historical Data'
*
* DESCRIPTION:       Check if the Historical Stack and the Historical Interrogation Record is erasable
*                    (e.g. when the VIN Original is not locked)
*                    Result codes:
*                      frfmTrue:    the historical data will NOT be erasable.
*                      frfmFalse:   the historical data will be erasable.
*******************************************************************************/
t_FrfmBool      ApplFrfmCheckIsVinOrigLocked(void)
{
	return frfmTrue;
}
#endif

/*******************************************************************************
* NAME:              ApplCanAddCanInterruptDisable
*
* CALLED BY:         CanCanInterruptDisable
* PRECONDITIONS:     GENy user.cfg file define for C_ENABLE_INTCTRL_ADD_CAN_FCT
*
* DESCRIPTION:       Provides a hook mechanisim to disable the CAN interrupt
*                    when the driver is operating in User mode.  This implementation
*                    only supports a single CAN channel system.  In order to add support
*                    for a multi-channel system, the passes channel parameter
*                    should be evaluated to determine which interrupt to disable.
*******************************************************************************/
void ApplCanAddCanInterruptDisable(CanChannelHandle channel)
{
	DisableCanInterrupt();
}

/*******************************************************************************
* NAME:              ApplCanAddCanInterruptRestore
*
* CALLED BY:         CanCanInterruptRestore
* PRECONDITIONS:     GENy user.cfg file define for C_ENABLE_INTCTRL_ADD_CAN_FCT
*
* DESCRIPTION:       Provides a hook mechanisim to restore the CAN interrupt
*                    when the driver is operating in User mode.  This implementation
*                    only supports a single CAN channel system.  In order to add support
*                    for a multi-channel system, the passes channel parameter
*                    should be evaluated to determine which interrupt to restore.
*******************************************************************************/
void ApplCanAddCanInterruptRestore(CanChannelHandle channel)
{
	EnableCanInterrupt();
}
