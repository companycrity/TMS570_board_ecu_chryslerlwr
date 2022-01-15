/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : ApplCallbacks.c
* Module Description: Definition of Application Callback Functions
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          EA3#11.1.3 %
 * %derived_by:       gz324f %
 * %date_modified:    Wed Feb  5 13:41:17 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial K2xx Synergy Version
 * 09/21/11  2        LWW       Added Stack Overwrite and undefined exception handling
 * 01/10/12  4        LWW       Changes for user defined systemtick and watchdog integration
 * 01/25/12  4        LWW       Updates for manual partnumber block transfer
 * 04/17/12  5.1.2    LWW       Removed part number block transfer
 * 04/18/12  5.1.3    LWW       Block transfer on EOL Mtr Param
 * 12/03/12	 3		  SAH		Removed Protection and Error Hooks, added FlsTstNotification
 * 01/16/13	 4		  SAH		Moved systick enable and schM tasks into SchM.c
 * 02/21/13	 5		  SAH		Added unused Nhet reference function for udiag
 * 03/01/13  6   	  JJW       Removed InitCounterSystemTimer() for Os 5.06 integration 
 * 03/02/13  7		  JJW       Removed WdgM_UpdateTickCount() for Wdg Stack 2.0.x integration 
 * 05/24/13  8		  JJW       Updates for MtrPos component integration 
 * 05/24/13  9		  SAH       Updates for MtrPos component integration
 * 06/19/13  10		  SAH       Added call backs for deprecated Nom Mtr Params
 * 07/22/13  11		  JJW       Deprecated block data migration updated to access the NvMP buffers for application split
 * 								support.
 * 10/21/13  12		  SAH       Added deprecated DEM block
 * 10/21/13  11.1.2	  SAH       Removed all deprecated blocks
 * 08/12/16  11.1.3	  SV       Updated for EEPROM to FEE change
 */

#include "Std_Types.h"
#include "NvM_Cfg.h"
#include "EcuM.h"
#include "NvM.h"
#include "Cd_NvMProxy.h"
#include "MemIf_Types.h"
#include "Os.h"
#include "Gpt.h"
#include "WdgM.h"
#include "Wdg.h"
#include "WdgM_PBcfg.h"
#include "Wdg_TMS570LS3x_Lcfg.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "Interrupts.h"
#include "RednRpdShtdn.h"
#include "CDD_Data.h"
#include "FlsTst.h"
#include "Metrics.h"
#include "Ap_DfltConfigData.h"
#include "Cd_FeeIf.h"


/*FEE counter for DV only - can be removed once official FEE configuration is started*/

/*****************************************************************************
  * Name:        StartupHook
  * Description: Required OSEK Hook function, with no functional requirements
  *               in the context of the project.
  * Called by:   OS (On start-up)
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
FUNC(void, APPLCB_CODE) StartupHook(void)
{
#ifdef ENABLE_UTILIZATION_MONITOR
	UtilMon_Init();
#endif

#ifdef ENABLE_CPUUSE_METRICS
	Metrics_ThruputInit();
#endif

}

/*****************************************************************************
  * Name:        ShutdownHook
  * Description: Required OSEK Hook function, to start shutdown process on OS
  *               shutdown event.
  * Called by:   OS (On shutdown)
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
FUNC(void, OSHOOK_CODE) ShutdownHook(StatusType s)
{
  EcuM_Shutdown();
}


/*****************************************************************************
  * Name:         SystemTick
  * Description: 
  * Called by:   Gpt Timer Expiration Notification
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
FUNC(void, APPLCB_CODE) SystemTick(void)
{	
	/*TODO: Move System Time tick count update here or update the system time to use the full  
	 * 64 bit hardware counter to alleviate the need for maintaining an accumulator seperate from
	 * the hardware accumulator.
	 */
	Metrics_TaskStart( D_RTSID_CNT_U08 );
	CounterTriggerSystemTimer();
	Metrics_TaskEnd( D_RTSID_CNT_U08 );
}



/*Additional callbacks*/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Appl_WaitNvMReady                                          **
**                                                                            **
** DESCRIPTION   : Performs a synchronous wait until NvM has finished         **
**                 the last job                                               **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** GLOBAL DATA   : Appl_Nv_Mode:       Idle, fast or slow mode                **
**                 Appl_NvBlockNumber: Id of NvM block to wait for            **
**                                                                            **
** PARAMETER     : blockNumber: Id of  NvM block to wait for                  **
**                 fastMode:    TRUE:  Schedule Nv stack in loop (used during **
**                                     startup or Coding)                     **
**                              FALSE: Nv stack is scheduled via cyclic tasks **
**                                     (used during normal operation)         **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
** REMARKS       : This function is blocking! Do not call this function       **
**                 within the context of a high priority task!!!              **
**                                                                            **
*******************************************************************************/

void Appl_WaitNvMReady(const uint16 blockNumber, const boolean fastMode)
{
	uint8 FeeStatus;
	NvM_RequestResultType Int_NvMultiBlockStatus;
    do
    {
    	if (fastMode == TRUE)
	    {
	    	GetResource(OsRes_MemStackTask);
	    	NvM_MainFunction();
	    	TWrapC_Fee_MainFunction();
	      	ReleaseResource(OsRes_MemStackTask);
	      	/*TODO: Determine if servicing the watchdog is required within the Appl_WaitNvMReady
	      	 * function. The current design does not enable the watchdog at init, so triggering it
	      	 * causes a wotchdog violation by triggering the watchdog before it is enabled. 
	      	 * At the time of this change, there was no API to query the watchdog state.
	      	 */
	      	/*Wdg_Trigger();*/
	    }

	    NvM_GetErrorStatus(blockNumber, &Int_NvMultiBlockStatus);

		FeeStatus = TWrapC_Fee_GetStatus();
    }
	while ((Int_NvMultiBlockStatus == NVM_REQ_PENDING) || (FeeStatus != MEMIF_IDLE));
}



/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Appl_FlsTstCompletedNotif                                  **
**                                                                            **
** DESCRIPTION   : FlsTst configured notification that is invoked upon the    **
**					the completion of the Runtime config set.  In order to    **
**					minimize Flash bus contentions between the DMA and micro  **
**					core during EPS runtime, the Flash test is suspended      **
**					after the first test interval is completed. This strategy **
**					provides better micrprocessor throughput resulting from   **
**					less wait states caused by Flash access contentions.      **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** RETURN        : void                                                       **
**                                                                            **
*******************************************************************************/
FUNC(void, AUTOMATIC) Appl_FlsTstCompletedNotif(void)
{
	FlsTst_Suspend();
}


FUNC(void, AUTOMATIC) HTUMPUErr(void)
{
	/* Dummy function to support old NHET functionality used from uDiag - not implemented in ePWM */
}

