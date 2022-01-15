/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : EcuStartup.c
* Module Description: AUTOSAR BSW Scheduler
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Thu Nov 11 16:33:22 2010
* %version:          EA3#5.1.10.1.3 %
* %derived_by:       gz324f %
* %date_modified:    Fri Feb 14 11:06:47 2014 % 
*---------------------------------------------------------------------------*/
/*****************************************************************************
*
* CHANGE HISTORY:
*
* Date      Rev      Author         Change Description              SCR #
*                                    (MDD Rev & Date)
* -------   -------  --------  -----------------------------------  ----------
* 04/13/11   1.0      LWW       Initial Synergy Version
* 09/09/11   2.0      LWW       Wdg cleanup and removal of SchM2
* 01/09/13   3	      SAH       Added enablesystick interrupt
* 01/16/13   4	      SAH       Added SchM_Task_ASIL_D(was in applcallbacks)
* 01/28/13   5		  SAH	    Added CCL_TASK for new vector SIP
* 02/28/13   5.1.1	  SAH		Warning and misc cleanup
* 07/01/13   5.1.3	  JJW       Added NvMProxy_MainFunction
* 07/17/13	 5.1.6	  SAH		Included trustfct.h
* 07/25/13	 5.1.8	  SAH		Included NtWrap.h and proxy header file.
* 07/31/13	 5.1.9	  JJW		Changes to support polling of Rx CAN msgs.
*								New ap9 SchM task.  Change of SchM tasks to Basic Tasks
* 08/08/13	 5.1.10	  JJW		Support better transmit resolution and consistent cycle calls for
*								cyclic tasks managing timing counters.
* 02/14/14	5.1.10.1.2  SAH		Added new task for NvM processing.  Faster reset timing.
******************************************************************************/

#include "SchM.h"
#include "SchM_Cfg.h"
#include "desc.h"
#include "Interrupts.h"
#include "WdgM.h"
#include "Wdg.h"
#include "WdgM_PBcfg.h"
#include "Wdg_TMS570LS3x_Lcfg.h"
#include "FlsTst.h"
#include "NtWrap.h"
#if (SCHM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#define SchM_DetReportError(ApiId, ErrorId)   Det_ReportError(SCHM_MODULE_ID, 0, ApiId, ErrorId)
#endif

#include "Metrics.h"
 
/**
 * Define for SchM internal usage
 */
#define __SCHM__

/**
 * Version check for AUTOSAR specification consistency
 */
#if (SCHM_AR_MAJOR_VERSION != 1)
#  error "Source and Header file are inconsistent!"
#endif

#if (SCHM_AR_MINOR_VERSION != 1)
#  error "Source and Header file are inconsistent!"
#endif

#if (SCHM_AR_PATCH_VERSION != 0)
#  error "Source and Header file are inconsistent!"
#endif

/**
 * Version check for source and header file consistency
 */
#if (SCHM_SW_MAJOR_VERSION != 0x00)
#  error "Source and Header file are inconsistent!"
#endif

#if (SCHM_SW_MINOR_VERSION != 0x00)
#  error "Source and Header file are inconsistent!"
#endif

#if (SCHM_SW_PATCH_VERSION != 0x00)
#  error "Source and Header file are inconsistent!"
#endif


/*******************************************************************************
 * Includes
 *******************************************************************************/
#include "v_cfg.h"
#include "SchM_Types.h"

#  include "Os.h"


#  include "can_inc.h"
#  include "SchM_CanDesc.h"
#  include "SchM_Tpiso15765.h"
#  include "SchM_Com.h"
#  include "EcuM.h"
#  include "SchM_EcuM.h"
#include "SchM_Xcp.h"
#include "EPS_DiagSrvcs_ISO.h"


#  include "Crc.h"
#  include "SchM_Crc.h"

#  include "Adc.h"
#  include "SchM_Adc.h"

#  include "Dio.h"
#  include "SchM_Dio.h"


#  include "Gpt.h"
#  include "SchM_Gpt.h"

#  include "Mcu.h"
#  include "SchM_Mcu.h"

#  include "Port.h"
#  include "SchM_Port.h"



#  include "MemIf.h"
#  include "SchM_MemIf.h"

#  include "SchM_NvMProxy.h"
#  include "Cd_NvMProxy.h"

#  include "NvM.h"
#  include "SchM_NvM.h"

#  include "Dem.h"
#  include "SchM_Dem.h"

#  include "Ccl.h"
#  include "SchM_Ccl.h"

#if defined( VGEN_ENABLE_SYSSERVICE_ASRDET )
#  include "Det.h"
#  include "SchM_Det.h"
#endif



#  include "IoHwAb.h"
#  include "SchM_IoHwAb.h"




/*******************************************************************************
 * Defines
 *******************************************************************************/


/*******************************************************************************
 * Global variables
 *******************************************************************************/
#if (SCHM_DEV_ERROR_DETECT == STD_ON)
static uint8 SchM_InitState;
#endif
/*******************************************************************************
 * Global functions
 *******************************************************************************/

/****************************************************************************
| NAME:             SchM_InitMemory
| CALLED BY:        EcuM
| PRECONDITIONS:    none
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Initializes global variables. This function has to be called
|                   before any other calls to the SchM API
****************************************************************************/
void SchM_InitMemory( void )
{
#if (SCHM_DEV_ERROR_DETECT == STD_ON)
   SchM_InitState = SCHM_UNINIT;
#endif
}

/****************************************************************************
| NAME:             SchM_Init
| CALLED BY:        EcuM
| PRECONDITIONS:    none
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Initialize the timers for the scheduling of the main
|                   functions of the BSW modules
****************************************************************************/
void SchM_Init( void )
{
  
  SCHM_INIT_TIMER(CCL_10TASK);
  SCHM_INIT_TIMER(CCL_20TASK);
  SCHM_INIT_TIMER(ECUM);
  SCHM_INIT_TIMER(NVM);
  SCHM_INIT_TIMER(XCP);


  SetRelAlarm(Alarm_10ms_SchM9, MSEC(SCHM_TASK_CYCLE_TIME), MSEC(SCHM_TASK_CYCLE_TIME));
  
#if (SCHM_DEV_ERROR_DETECT == STD_ON)
  SchM_InitState = SCHM_INIT;
#endif
}

/****************************************************************************
| NAME:             SchM_Deinit
| CALLED BY:        EcuM
| PRECONDITIONS:    none
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Deinitialize the timers for the scheduling of the main
|                   functions of the BSW modules
****************************************************************************/
void SchM_Deinit( void )
{
#if (SCHM_DEV_ERROR_DETECT == STD_ON)
  if(SCHM_INIT != SchM_InitState)
  {
     SchM_DetReportError(SCHM_APIID_SCHM_DEINIT, SCHM_E_NOT_INIT);   
  }
  else
  {
#endif


     CancelAlarm(Alarm_10ms_SchM9);

#if (SCHM_DEV_ERROR_DETECT == STD_ON)
     SchM_InitState = SCHM_UNINIT;
  }
#endif
}

/****************************************************************************
| NAME:             Task_10ms_SchM9
| CALLED BY:        OS
| PRECONDITIONS:    SchM initialized, SchM_InitTask executed
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Task to schedule the low priority main functions of 
|                   Application 9 BSW's
****************************************************************************/
TASK(Task_10ms_SchM9)
{

#if (SCHM_DEV_ERROR_DETECT == STD_ON)
     if(SCHM_INIT != SchM_InitState)
     {
       SchM_DetReportError(SCHM_APIID_SCHM_TASK, SCHM_E_NOT_INIT);
     }
     else
     {
#endif
       SCHM_MAINFUNCTION_CALL(ECUM);
	   



	   
       SCHM_MAINFUNCTION_CALL(CCL_10TASK);
       SCHM_MAINFUNCTION_CALL(CCL_20TASK);
       EPSDiagSrvcs_Task();
	   GetResource(OsRes_MemStackTask);
   //    SCHM_MAINFUNCTION_CALL(EEP);
   //    SCHM_MAINFUNCTION_CALL(EA);
	   //NvMProxy_MainFunction();
     //  SCHM_MAINFUNCTION_CALL(NVM);
	   ReleaseResource(OsRes_MemStackTask);
       
#if (SCHM_DEV_ERROR_DETECT == STD_ON)
     }
#endif

  TerminateTask();
}
#if 0
/****************************************************************************
| NAME:             Task2_10ms_SchM9
| CALLED BY:        OS
| PRECONDITIONS:    SchM initialized, SchM_InitTask executed
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Task to schedule the low priority main functions of
|                   Application 9 BSW's
****************************************************************************/
TASK(Task2_10ms_SchM9)
{

#if (SCHM_DEV_ERROR_DETECT == STD_ON)
     if(SCHM_INIT != SchM_InitState)
     {
       SchM_DetReportError(SCHM_APIID_SCHM_TASK, SCHM_E_NOT_INIT);
     }
     else
     {
#endif

    do
    {
	   GetResource(OsRes_MemStackTask);
   SCHM_MAINFUNCTION_CALL(EEP);
 SCHM_MAINFUNCTION_CALL(EA);
	   NvMProxy_MainFunction();
       SCHM_MAINFUNCTION_CALL(NVM);
	   ReleaseResource(OsRes_MemStackTask);
    }while(EcuHardResetSrvcActive_Cnt_G_lgc == TRUE);

#if (SCHM_DEV_ERROR_DETECT == STD_ON)
     }
#endif

  TerminateTask();
}
#endif
/****************************************************************************
| NAME:             Task_100ms_SchM9
| CALLED BY:        OS
| PRECONDITIONS:    None
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Task to schedule the NvM main function
****************************************************************************/
TASK(Task_100ms_SchM9)
{
	NvMProxy_MainFunction();
	NvM_MainFunction();
	TerminateTask();
}


/****************************************************************************
| NAME:             Task_100ms_SchM0
| CALLED BY:        OS
| PRECONDITIONS:    None
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Task to schedule the Fee main function
****************************************************************************/
TASK(Task_100ms_SchM0)
{
	Fee_MainFunction();
	TerminateTask();
}


/****************************************************************************
| NAME:             Task_4ms_SchM0
| CALLED BY:        OS
| PRECONDITIONS:    None
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Task to schedule the main functions of Application 0 BSW's
****************************************************************************/
TASK(Task_4ms_SchM0)
{
	WdgM_MainFunction();
	FlsTst_MainFunction();
	TerminateTask();
}

/****************************************************************************
| NAME:             Task_Init_SchM9
| CALLED BY:        OS
| PRECONDITIONS:    None
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Task to perform final init prior to starting periodic operation
****************************************************************************/
TASK(Task_Init_SchM9)
{
  EcuM_StartupTwo();
  NtWrapC_Wdg_TMS570LS3x_Init(&wdg_tms570ls3x_config);
  NtWrapC_WdgM_Init(&WdgMConfig_Mode0);

  Gpt_EnableNotification(SystemTime_uS);
  EnableSysTickInterrupt();
  TerminateTask();
}

/****************************************************************************
| NAME:             Bkgnd_Task
| CALLED BY:        OS
| PRECONDITIONS:    None
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Task to schedule an infinite background loop
****************************************************************************/
TASK(Task_Bkgnd)
{
  for(;;)
  {
  	Metrics_MainFunction();
  }
}

#if (SCHM_VERSION_INFO_API == STD_ON)
/****************************************************************************
| NAME:             SchM_GetVersionInfo
| CALLED BY:        Application
| PRECONDITIONS:    Preprocessed
| INPUT PARAMETERS: Pointer to version structure
| RETURN VALUES:    none
| DESCRIPTION:      Get version of the BSW Scheduler
****************************************************************************/
void SchM_GetVersionInfo( Std_VersionInfoType *versioninfo )
{
  versioninfo->vendorID = SCHM_VENDOR_ID;
  versioninfo->moduleID = SCHM_MODULE_ID;
  versioninfo->instanceID = 0;
  versioninfo->sw_major_version = (uint8)SCHM_SW_MAJOR_VERSION;
  versioninfo->sw_minor_version = (uint8)SCHM_SW_MINOR_VERSION;
  versioninfo->sw_patch_version = (uint8)SCHM_SW_PATCH_VERSION;
}
#endif

#if (SCHM_INTERRUPTLOCKS_AS_FUNCTION == STD_ON)
/****************************************************************************
| NAME:             SchM_SuspendAllInterrupts
| CALLED BY:        BSW Moduls
| PRECONDITIONS:    Preprocessed
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      abstracts Interrupt Locks
****************************************************************************/
void SchM_SuspendAllInterrupts(void)
{
   SuspendAllInterrupts();
}
   
/****************************************************************************
| NAME:             SchM_ResumeAllInterrupts
| CALLED BY:        BSW Moduls
| PRECONDITIONS:    Preprocessed
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      abstracts Interrupt Locks
****************************************************************************/
void SchM_ResumeAllInterrupts(void)
{
   ResumeAllInterrupts();
}
#endif

