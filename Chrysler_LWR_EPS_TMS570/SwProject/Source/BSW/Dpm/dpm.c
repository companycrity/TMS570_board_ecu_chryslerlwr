/*****************************************************************************
| Project Name: DPM   Decentral Power Management
|    File Name: dpm.c
|
|  Description: DPM/CCL OEM for DC
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
|   Copyright (c) by Vector Informatik GmbH.     All rights reserved.
|
|   This software is copyright protected and proprietary to 
|   Vector Informatik GmbH. Vector Informatik GmbH grants to you 
|   only those rights as set out in the license conditions. All 
|   other rights remain with Vector Informatik GmbH.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| Alb          Stefan Albrecht           Vector Informatik GmbH 
| Et           Thomas Ebert              Vector Informatik GmbH
| Dhf          Daniel Hof                Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Ver      Author  Description
| ---------   ----     ------  -----------------------------------------------
| 2003-12-19  01.00.00  Alb     initial version
| 2004-02-03  01.01.00  Alb     ESCAN00007473 changed return value of DpmGetMaximumChannelEcuActivityMode
|                       Alb     ESCAN00007453 encapsulate unused variable in DpmInit()
| 2004-03-02  01.02.00  Alb     ESCAN00007613 optimization of DPM
|                       Alb     ESCAN00007635 changes after review
|                       Alb     ESCAN00007665 delet local request in init
|                       Alb     ESCAN00007732 correct define C_ENABLE_DPM_PRODUCTION in DpmTask()
|                       Alb     ESCAN00007507 changed behaviour of NoExternalMode cnt. during diag session
|                       Alb     ESCAN00007774 prevent entering sleep mode during EMC wake up session
| 2004-03-09  01.03.00  Alb     ESCAN00007835 on EMC wake up detection the DPM stays to long in local mode 
| 2004-03-17  01.04.00  Alb     ESCAN00007905 no external mode diag cnt only count on activ restriction
| 2004-04-22  01.05.00  Alb     ESCAN00008411 major API changes and optimizations (NEW API DPM)
| 2004-06-24  02.00.00  Alb     ESCAN00008621 no changes
| 2004-06-29  02.01.00  Alb     ESCAN00008707 add define DPM_CHECK_FLAG to cast in right manner
|                       Alb     ESCAN00008708 add DBK_API_CALLBACK_TYPE
| 2004-07-07  02.02.00  Et      ESCAN00008780 wrong CALL_TYPE for ApplDpmReadMaxChMode
|                       Alb     ESCAN00008782 return value API "DpmGetActualChannelActivityMode"
| 2004-08-02  02.03.00  Alb     ESCAN00009155 changes to use DPM in SLP6
|                       Alb     ESCAN00009099 set system user1 request to sleep mode  
|                       Alb     ESCAN00009106 during EMC detection set restriction can be active
| 2004-10-04  02.04.00  Alb     ESCAN00009471 in mulitpe channel systems a delay of each channel is possible
|                       Alb     ESCAN00009446 additional state External_StartUpDelay 
|                       Alb     ESCAN00009631 set T_MINIMUM_LOCAL_MODE_DURATION at least to one
|                       Alb     ESCAN00008902 add polling interface for restriction signal
|                       Alb     ESCAN00009680 change naming convention
|                       Alb     ESCAN00009742 Remove activity mode Extrnal_BusOff from DPM
|                       Alb     ESCAN00009746 add interrupt lock during target calculation
| 2004-10-18  02.05.00  Alb     ESCAN00009834 delet first two bytes of diagnostic record
|                       Alb     ESCAN00009891 changes to reach misra compliance
|                       Alb     ESCAN00009924 encapsulate local variable to prevent compiler warning
| 2004-10-22  02.06.00  Alb     ESCAN00009957 change behavior of enable mechanism in BusActive state
|                       Alb     ESCAN00009973 change name of DpmGetMaximumChannelEcuActivityMode
|                       Alb     ESCAN00009974 change names of CCL call back functions 
| 2004-12-10  02.07.00  Alb     ESCAN00010152 change clear restriction call in BusActive mode
|                       Alb     ESCAN00010312 change restricion behavior
| 2004-12-20  02.08.00  Alb     ESCAN00010645 change rest. sig. from ind. function to flag SLP6 only
| 2005-02-17  02.09.00  Alb     ESCAN00011061 system user 1 handling was changed
| 2005-03-18  02.10.00  Alb     ESCAN00011504 review changes and optimizations
|                       Alb     ESCAN00010300 ApplDpmSaveMaxChMode and ApplDpmSaveCounterValues called multiple times
|                       Alb     ESCAN00011505 Support wake up reason CAN, awake reason network and diag for user data
|                       Alb     ESCAN00011530 keep the ECU awake during diagnostic session
| 2005-04-05  02.11.00  Alb     ESCAN00011713 encapsulate features with organi switches
| 2005-04-18  02.12.00  Alb     ESCAN00011979 different start up delay time configurabel per channel
|                       Alb     ESCAN00011991 no changes
|                       Alb     ESCAN00012005 Assertion occures in case of a diagnostic session is started
|                       Alb     ESCAN00011945 add DPM_API_CALL_TYPE to diag request functions
| 2005-05-02  02.13.00  Alb     ESCAN00012103 reset of gRestrictionStatus.MaxSleepFlag has changed
| 2005-08-24  02.14.00  Alb     ESCAN00013257 add aditional transition from External_BusActive to External_StartupSleepDelay
|                       Alb     ESCAN00013147 change local mode duration timer handling in Local_EmcDetection 
|                       Alb     ESCAN00013287 change locla mode duration timer handling in Local_BusLocal
| 2005-09-14  02.15.00  Alb     ESCAN00013427 call set and clear restricions in all modes below Local_EmcDetection
|                                             and in DpmInitPowerOn function
|                       Alb     ESCAN00013211 add assertion and error directive 
|                       Alb     ESCAN00013532 change diagnostic active handling
| 2005-11-21  02.16.00  Alb     ESCAN00014315 add paging prefix for ApplCclComStop
|                       Alb     ESCAN00014354 decrase wake up time
| 2005-12-12  02.17.00  Alb     ESCAN00014532 encapsulate DpmCheckHighestUserRequest to prevent compiler warning
| 2006-12-15  02.18.00  Alb     ESCAN00017431 add dedicated interrupt lock for all ApplDpmModeChange function calls
|                               ESCAN00013794 call permanten fatal error function direct without macro
| 2007-11-07  02.19.00  Alb     ESCAN00023155 add support for multipe config CCL_ENABLE_MULTIPLE_CONFIG
| 2008-01-09  02.20.00  Alb     ESCAN00020186 prevent compile error: "identifier lLoopIndex not declared" occures
|                       Alb     ESCAN00022794 prevent call of CAN-driver assertions
|                       Alb     ESCAN00023792 no lock of CAN interrupts for all channels in multiple configuration
| 2008-08-25  02.21.00  Dhf     ESCAN00022086 Compiler warning "uninitialised Variable lDpmRequestedActivityMode"
|                               ESCAN00025268 "ApplDpmModeChangeChannelSystem" causes linker error (in single channel project with channel parameter)
|                               ESCAN00027775 Compiler Warning in case of missing cast
|                               ESCAN00028955 Encapsulation of function DpmIndicateActiveDiagnosticSession changed
|                               ESCAN00029456 made DPM independent from DBKOM-availability
|                               ESCAN00029458 update DPM to new memory qualifier
| 2009-02-09  02.22.00  Dhf     ESCAN00029906 adapted indentation of preprocessor statements
|                               ESCAN00029935 extended restriction handling for multiple configuration
| 2009-05-06  02.23.00  Dhf     ESCAN00034923 added extended initialization
|                               ESCAN00035035 MISRA compliance
| 2009-07-27  02.23.01  Dhf     ESCAN00036058 Unexpected ECU behavior due to out of bounds access
|                               ESCAN00036693 awake reason CAN is not transmitted correctly within the NM user data
| 2010-01-15  02.23.02  Dhf     ESCAN00038125 adapted interrupt locks in DpmTask()
| 2011-03-07  02.23.03  Dhf     ESCAN00047381 added state check before executing CclSystemShutdown()
|*****************************************************************************/

/*-----------------------------------------------------------------------------
--- include files
-----------------------------------------------------------------------------*/

#include "ccl_inc.h"
#include "can_def.h"

#if defined(GENy)
# if defined (VGEN_ENABLE_IL_DBKOM)
#  include "dbk_par.h"
# endif
# include "dpm_par.h"
# include "ccl_par.h"
# if defined (VGEN_ENABLE_IL_DBKOM)
#  include "dbk_cfg.h"
# endif
# include "dpm.h"
#else
# include "dpm_par.h"
# include "ccl_par.h"
# include "dbk_cfg.h"
# include "dpm.h"
#endif



# if defined (VGEN_ENABLE_NM_OSEK_D_UD)
#  include "nm_udata.h"
# endif


/*-----------------------------------------------------------------------------
--- version check
-----------------------------------------------------------------------------*/
#if (CCL_DPM_DC_VERSION != 0x0223)
# error "main version of DPM header and code file are inconsistent"
#endif
#if (CCL_DPM_DC_RELEASE_VERSION != 0x03)
# error "release version of DPM header and code file are inconsisten"
#endif

/*-----------------------------------------------------------------------------
--- DPM feature configuration
-----------------------------------------------------------------------------*/
/*  DPM_FEATURE_UD_SUPPORT   ENABLED  */
/*  DPM_FEATURE_DIAG_AWAKE   ENABLED  */
/*  DPM_FEATURE_ADV_SHUTDOWN ENABLED  */
/*  DPM_FEATURE_STARTUP_TIME ENABLED  */

/*-----------------------------------------------------------------------------
--- consitstency check
-----------------------------------------------------------------------------*/
#if !defined(DPM_ENABLE_STARTUP_TIME) 
# if (T_STARTUP_SLEEP_DELAY == 0x00)
#  error "T_STARTUP_SLEEP_DELAY time is 0 please configure a value higher than 0"
# endif
#endif

# if defined (VGEN_ENABLE_NM_OSEK_D_UD)
/*-----------------------------------------------------------------------------
--- defines
-----------------------------------------------------------------------------*/
#  if defined( NM_ENABLE_INDEXED_NM )
#   if defined( NM_ENABLE_CHANNEL_INDIRECTION )  
#    define dpmNmpduDpmWakeupReasonCAN(b)    nmpduDpmWakeupReasonCAN(NmCanToNmIndirection[b])
#    define dpmNmpduDpmAwakeReasonCAN(b)     nmpduDpmAwakeReasonCAN(NmCanToNmIndirection[b])
#     define dpmNmpduDpmAwakeReasonDiag(b)   nmpduDpmAwakeReasonDiag(NmCanToNmIndirection[b])
#   else
#    define dpmNmpduDpmWakeupReasonCAN(b)    nmpduDpmWakeupReasonCAN(b)
#    define dpmNmpduDpmAwakeReasonCAN(b)     nmpduDpmAwakeReasonCAN(b) 
#     define dpmNmpduDpmAwakeReasonDiag(b)   nmpduDpmAwakeReasonDiag(b)
#   endif
#  else
#   define dpmNmpduDpmWakeupReasonCAN(b)    nmpduDpmWakeupReasonCAN(0)
#   define dpmNmpduDpmAwakeReasonCAN(b)     nmpduDpmAwakeReasonCAN(0) 
#    define dpmNmpduDpmAwakeReasonDiag(b)   nmpduDpmAwakeReasonDiag(0)
#  endif
# endif

/*-----------------------------------------------------------------------------
--- globals
-----------------------------------------------------------------------------*/
/* stored requests for Extern_Mode */
V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 gDpmUserExternalRequest[DPM_USER_BYTE];
  
/* stored requests for Local_Mode */
V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 gDpmUserLocalRequest[DPM_USER_BYTE];

/* enum of all possible states content is active state */
V_MEMRAM0 static V_MEMRAM1 t_DpmState V_MEMRAM2 gActiveState;

#if(kDpmNumberOfChannels > 1)
V_MEMRAM0 static V_MEMRAM1 t_DpmState V_MEMRAM2 gActiveStateCh[kDpmNumberOfChannels];
#endif

/* active diag indication to prevent the ECU to enter sleep mode during diag session */
V_MEMRAM0 static V_MEMRAM1 t_DpmState V_MEMRAM2 gDiagActiveFlag[kDpmNumberOfChannels]; 

/* enum of all possible states content is next target state */
V_MEMRAM0 static volatile V_MEMRAM1 t_DpmState V_MEMRAM2 gTargetState;

/* requested state of communication bus*/
#if(kDpmNumberOfChannels > 1)
V_MEMRAM0 static V_MEMRAM1 t_DpmState V_MEMRAM2  gBusReqCh[kDpmNumberOfChannels];
#else
V_MEMRAM0 static V_MEMRAM1 t_DpmState V_MEMRAM2  gBusReq;
#endif
/* enum of all possilbe state content is requested state from user point of view*/
V_MEMRAM0 static V_MEMRAM1 t_DpmState V_MEMRAM2 gUserReq;

/* on entry flag to indicate first entry of a new mode */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 gOnEntry;

/* start up sleep delay timer to keep ECU for at least 5s in external mode */
#if (kDpmNumberOfChannels >1)
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 gStartUpSleepDelayTimerCh[kDpmNumberOfChannels];
#else
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 gStartUpSleepDelayTimer;
#endif 
/* local mode duration timer */
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 gLocalModeTimer;

/* restriction status information */
V_MEMRAM0 V_MEMRAM1 t_DpmRestriction V_MEMRAM2 gRestrictionStatus;

#if !defined(C_ENABLE_DPM_PRODUCTION)
/* diagnostic flag restriction */
V_MEMRAM0 static V_MEMRAM1 t_DpmDiagStatusFlags V_MEMRAM2 gDiagStatus;
#endif /* C_ENABLE_DPM_PRODUCTION */

#if defined ( DPM_ENABLE_EXTENDEND_INITIALIZATION )
V_MEMRAM0 static V_MEMRAM1 tCclInitParaListType V_MEMRAM2 DpmCclInitList;
#endif

/*-----------------------------------------------------------------------------
--- ROM table to coordinate mode transitions
-----------------------------------------------------------------------------*/
#if (kDpmNumberOfChannels > 1)
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 cTransitionTable[6][6] =
{
  {NOT_PO,SLP_PD,LOC_PS,LOC_PS,LOC_BL,EXT_WB}, /* Sleep_PowerDown       */
  {NOT_PO,NOT_PO,NOT_PO,NOT_PO,NOT_PO,NOT_PO}, /* Local_PreparSleep     */
  {LOC_BL,LOC_BL,NOT_PO,LOC_BL,LOC_BL,EXT_WB}, /* Local_BusLocal        */
  {LOC_ED,LOC_ED,LOC_ED,NOT_PO,LOC_ED,NOT_PO}, /* Local_EmcDetection    */
  {NOT_PO,NOT_PO,NOT_PO,NOT_PO,NOT_PO,EXT_WB}, /* External_WaitBusSleep */
  {LOC_ED,LOC_ED,EXT_BA,EXT_BA,EXT_BA,NOT_PO}  /* External_BusActive    */
};
#else
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 cTransitionTable[7][7] =
{
  {NOT_PO,SLP_PD,LOC_PS,LOC_PS,LOC_BL,EXT_WB,EXT_WB},  /* Sleep_PowerDown        */
  {NOT_PO,NOT_PO,NOT_PO,NOT_PO,NOT_PO,NOT_PO,NOT_PO},  /* Local_PreparSleep      */
  {LOC_BL,LOC_BL,NOT_PO,LOC_BL,LOC_BL,EXT_WB,EXT_WB},  /* Local_BusLocal         */
  {LOC_ED,LOC_ED,LOC_ED,NOT_PO,LOC_ED,NOT_PO,NOT_PO},  /* Local_EmcDetection     */
  {NOT_PO,NOT_PO,NOT_PO,NOT_PO,NOT_PO,EXT_WB,EXT_WB},  /* External_WaitBusSleep  */
  {LOC_ED,LOC_ED,NOT_PO,NOT_PO,EXT_SD,NOT_PO,EXT_BA},  /* External_BusActive     */
  {LOC_ED,LOC_ED,EXT_SD,EXT_SD,EXT_SD,EXT_SD,NOT_PO}   /* External_StartUpDelay  */
};
#endif
/*-----------------------------------------------------------------------------
--- global variables for diagnostic services
-----------------------------------------------------------------------------*/
#if !defined(C_ENABLE_DPM_PRODUCTION)
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2  gDpmDiagRecord[DPM_DIAG_RECORD_LENGTH];  /* allocate an array to store the diagnostic data*/
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 gDpmInhibitExternalCnt;                  /* counter for diag reasons*/
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 gDpmImmediateNoExternalCnt;              /* counter for diag reasons*/
#endif

/*-----------------------------------------------------------------------------
--- internal DPM function prototypes
-----------------------------------------------------------------------------*/
static t_DpmState DpmCheckHighestRequest(void);

#if !defined(C_ENABLE_DPM_PRODUCTION)
static vuint8  DpmCheckHighestUserRequest(void);
#endif

#if defined ( DPM_ENABLE_EXTENDEND_INITIALIZATION )
# if (kDpmNumberOfChannels > 1)
static void DpmValidateInitValue( CanChannelHandle channel, tDpmInitParaType dpmInitValue );
static void DpmSetRequestOnInit( CanChannelHandle channel, tDpmInitParaType dpmInitValue );
static void DpmSetCclInitValue( CanChannelHandle channel, tDpmInitParaType dpmInitValue );
# else
static void DpmValidateInitValue( tDpmInitParaType dpmInitValue );
static void DpmSetCclInitValue( tDpmInitParaType dpmInitValue );
static void DpmSetRequestOnInit( tDpmInitParaType dpmInitValue );
# endif
#endif

/*-----------------------------------------------------------------------------
--- version information
-----------------------------------------------------------------------------*/
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kDpmMainVersion   = (vuint8) ((CCL_DPM_DC_VERSION) >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kDpmSubVersion    = (vuint8) (CCL_DPM_DC_VERSION & 0xff);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kDpmBugFixVersion = (vuint8) (CCL_DPM_DC_RELEASE_VERSION & 0xff);

#if defined ( DPM_ENABLE_EXTENDEND_INITIALIZATION )
/************************************************************************
| NAME:               DpmValidateInitValue
| CALLED BY:          DPM
| PRECONDITIONS:
| INPUT PARAMETERS:   CAN channel, initialization parameter value
| RETURN VALUE:       void
| DESCRIPTION:        validate init pointer
|*************************************************************************/
# if (kDpmNumberOfChannels > 1)
static void DpmValidateInitValue( CanChannelHandle channel,  tDpmInitParaType dpmInitValue)
# else
static void DpmValidateInitValue( tDpmInitParaType dpmInitValue)
# endif
{
  switch (dpmInitValue)
  {
/* ===================================================================
   ==================== kDpmInitExternal =============================
   =================================================================== */
    case kDpmInitExternal:
# if (kDpmNumberOfChannels > 1)
      gActiveStateCh[channel]              = External_StartUpDelay;
      gBusReqCh[channel]                   = External_StartUpDelay;

#   if defined DPM_ENABLE_DIFF_STARTUP_TIME
      gStartUpSleepDelayTimerCh[channel]   = cStartUpSleepDelayCycles[channel];
#   else
      gStartUpSleepDelayTimerCh[channel]   = T_STARTUP_SLEEP_DELAY; 
#   endif
      if( gActiveState < External_BusActive )
      {
        gActiveState                       = External_BusActive;
      }
# else
      gBusReq                              = External_StartUpDelay;
      gStartUpSleepDelayTimer              = T_STARTUP_SLEEP_DELAY;
      gActiveState                         = External_StartUpDelay;
# endif
    break;
    
/* ===================================================================
   ===================== kDpmInitLocal ===============================
   =================================================================== */
    case kDpmInitLocal:
# if (kDpmNumberOfChannels > 1)
      gActiveStateCh[channel]              = Sleep_PowerDown;
      gBusReqCh[channel]                   = Sleep_PowerDown;
      gStartUpSleepDelayTimerCh[channel]   = 0x00;
      
      if( gActiveState < Local_BusLocal )
      {
        gActiveState                       = Local_BusLocal;
      }
# else
      gBusReq                              = Local_BusLocal;
      gStartUpSleepDelayTimer              = 0x00;
      gActiveState                         = Local_BusLocal;
# endif
      break;

/* ===================================================================
   ===================== kDpmInitEmc =================================
   =================================================================== */
    case kDpmInitEmc:
# if (kDpmNumberOfChannels > 1)
      gActiveStateCh[channel]              = Local_EmcDetection;
      gBusReqCh[channel]                   = Local_EmcDetection;
      gStartUpSleepDelayTimerCh[channel]   = 0x00;

      if( gActiveState < Local_EmcDetection )
      {
        gActiveState                       = Local_EmcDetection;
      }
# else
      gBusReq                              = Local_EmcDetection;
      gStartUpSleepDelayTimer              = 0x00;
      gActiveState                         = Local_EmcDetection;
# endif
      break;

    default:
# if defined (DPM_ENABLE_DEBUG)      
      ApplDpmFatalError(DPM_ERR_INIT_VALUE_NOT_CORRECT);
# endif
      break;
  }

# if (kDpmNumberOfChannels > 1)
  DpmSetCclInitValue(channel,dpmInitValue);
# else
  DpmSetCclInitValue(dpmInitValue);
# endif

  gOnEntry      = 0x01; /* set entry flag to do the necessary actions for requested state */
}

/************************************************************************
| NAME:               DpmSetCclInitValue
| CALLED BY:          DPM
| PRECONDITIONS:
| INPUT PARAMETERS:   CAN channel, initialization parameter value
| RETURN VALUE:       void
| DESCRIPTION:        sets the CCL init value
|*************************************************************************/
# if (kDpmNumberOfChannels > 1)
static void DpmSetCclInitValue(CanChannelHandle channel, tDpmInitParaType dpmInitValue)
# else
static void DpmSetCclInitValue(tDpmInitParaType dpmInitValue)
# endif
{
# if (kDpmNumberOfChannels > 1)
  switch (channel)
  {
    case 0:
# endif
      switch(dpmInitValue)
      {
        case kDpmInitLocal:
          DpmCclInitList.cclInit_0 = kCclInitSleep;
          break;

        case kDpmInitEmc:
          DpmCclInitList.cclInit_0 = kCclInitEmc;
          break;

        case kDpmInitExternal:
          DpmCclInitList.cclInit_0 = kCclInitNormal;
          break;

        default:
          break;
      }

# if (kDpmNumberOfChannels > 1)
      break;

      case 1:
      switch(dpmInitValue)
      {
        case kDpmInitLocal:
          DpmCclInitList.cclInit_1 = kCclInitSleep;
          break;

        case kDpmInitEmc:
          DpmCclInitList.cclInit_1 = kCclInitEmc;
          break;

        case kDpmInitExternal:
          DpmCclInitList.cclInit_1 = kCclInitNormal;
          break;

        default:
          break;
      }
      break;

#  if (kDpmNumberOfChannels > 2)
      case 2:
     switch(dpmInitValue)
      {
        case kDpmInitLocal:
          DpmCclInitList.cclInit_2 = kCclInitSleep;
          break;

        case kDpmInitEmc:
          DpmCclInitList.cclInit_2 = kCclInitEmc;
          break;

        case kDpmInitExternal:
          DpmCclInitList.cclInit_2 = kCclInitNormal;
          break;

        default:
          break;
      }
      break;
#  endif

#  if (kDpmNumberOfChannels > 3)
      case 3:
      switch(dpmInitValue)
      {
        case kDpmInitLocal:
          DpmCclInitList.cclInit_3 = kCclInitSleep;
          break;

        case kDpmInitEmc:
          DpmCclInitList.cclInit_3 = kCclInitEmc;
          break;

        case kDpmInitExternal:
          DpmCclInitList.cclInit_3 = kCclInitNormal;
          break;

        default:
          break;
      }
      break;
#endif

#  if (kDpmNumberOfChannels > 4)
      case 4:
     switch(dpmInitValue)
      {
        case kDpmInitLocal:
          DpmCclInitList.cclInit_4 = kCclInitSleep;
          break;

        case kDpmInitEmc:
          DpmCclInitList.cclInit_4 = kCclInitEmc;
          break;

        case kDpmInitExternal:
          DpmCclInitList.cclInit_4 = kCclInitNormal;
          break;

        default:
          break;
      }
      break;
#endif

#  if (kDpmNumberOfChannels > 5)
      case 5:
     switch(dpmInitValue)
      {
        case kDpmInitLocal:
          DpmCclInitList.cclInit_5 = kCclInitSleep;
          break;

        case kDpmInitEmc:
          DpmCclInitList.cclInit_5 = kCclInitEmc;
          break;

        case kDpmInitExternal:
          DpmCclInitList.cclInit_5 = kCclInitNormal;
          break;

        default:
          break;
      }
      break;
#endif

#  if (kDpmNumberOfChannels > 6)
      case 6:
      switch(dpmInitValue)
      {
        case kDpmInitLocal:
          DpmCclInitList.cclInit_6 = kCclInitSleep;
          break;

        case kDpmInitEmc:
          DpmCclInitList.cclInit_6 = kCclInitEmc;
          break;

        case kDpmInitExternal:
          DpmCclInitList.cclInit_6 = kCclInitNormal;
          break;

        default:
          break;
      }
      break;
#  endif

#  if (kDpmNumberOfChannels > 7)
      case 7:
     switch(dpmInitValue)
      {
        case kDpmInitLocal:
          DpmCclInitList.cclInit_7 = kCclInitSleep;
          break;

        case kDpmInitEmc:
          DpmCclInitList.cclInit_7 = kCclInitEmc;
          break;

        case kDpmInitExternal:
          DpmCclInitList.cclInit_7 = kCclInitNormal;
          break;

        default:
          break;
      }
      break;
#  endif

      default:
        break;
  }
# endif
}


/************************************************************************
| NAME:               DpmSetRequestOnInit
| CALLED BY:          DPM
| PRECONDITIONS:
| INPUT PARAMETERS:   CAN channel, initialization parameter value
| RETURN VALUE:       void
| DESCRIPTION:        sets a mode request according to the init value
|*************************************************************************/
# if (kDpmNumberOfChannels > 1)
static void DpmSetRequestOnInit( CanChannelHandle channel,  tDpmInitParaType dpmInitValue)
# else
static void DpmSetRequestOnInit( tDpmInitParaType dpmInitValue)
# endif
{
  if ( dpmInitValue == kDpmInitExternal)
  {
# if (kDpmNumberOfChannels > 1)
    DpmExternalRequest((t_DpmUserNumber)channel);
# else
    DpmExternalRequest((t_DpmUserNumber)0);
# endif
  }
  else
  {
# if (kDpmNumberOfChannels > 1)
    DpmLocalRequest((t_DpmUserNumber)channel);
# else
    DpmLocalRequest((t_DpmUserNumber)0);
# endif
  }
}
#endif


#if defined ( DPM_ENABLE_EXTENDEND_INITIALIZATION )
/******************************************************************************
Name          : DpmInitPowerOn
Called by     : application
Preconditions : none
Parameters    : dpmInitState
Returnvalue   : none
Description   : Initialization after startup 
******************************************************************************/
void DPM_API_CALL_TYPE DpmInitPowerOn(const tDpmInitParaListType* dpmInitState)
#else
/******************************************************************************
Name          : DpmInitPowerOn
Called by     : application
Preconditions : none
Parameters    : none
Returnvalue   : none
Description   : Initialization after startup 
******************************************************************************/
void DPM_API_CALL_TYPE DpmInitPowerOn(void)
#endif
{
  vsintx loopIndex;
  t_DpmMaxChModeVariantCode lMaxChActModeVari; /* maximum channel activity mode and variant status information */ 

  for(loopIndex = (vsintx)(DPM_USER_BYTE - 0x01); loopIndex >= 0x00; loopIndex--) /* reset all requests to sleep mode */
  {
    gDpmUserExternalRequest[loopIndex] = DPM_SLEEP_MODE;
    gDpmUserLocalRequest[loopIndex]    = DPM_SLEEP_MODE;
  }
#if (kDpmNumberOfChannels > 1)
  /* pre-initialize the active state, the highest state will be set later in DpmValidateInitValue() */
  gActiveState = Sleep_PowerDown;

  for(loopIndex = (vsintx)(kDpmNumberOfChannels - 0x01); loopIndex >= 0x00; loopIndex--)
  {
# if defined(CCL_ENABLE_MULTIPLE_CONFIG)
    if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (loopIndex)))>(vuint8)0x00)/* check if physical CAN channel is active in current identity */
    {
# endif
# if defined ( DPM_ENABLE_EXTENDEND_INITIALIZATION )
      switch ( loopIndex )
      {
        case 0:
          DpmValidateInitValue( (CanChannelHandle)0, dpmInitState->dpmInit_0 );
          break;

        case 1:
          DpmValidateInitValue( (CanChannelHandle)1, dpmInitState->dpmInit_1 );
          break;
      
#  if (kDpmNumberOfChannels > 2)
        case 2:
          DpmValidateInitValue( (CanChannelHandle)2, dpmInitState->dpmInit_2 );
          break;
#  endif
#  if (kDpmNumberOfChannels > 3)
        case 3:
          DpmValidateInitValue( (CanChannelHandle)3, dpmInitState->dpmInit_3 );
          break;
#  endif
#  if (kDpmNumberOfChannels > 4)
        case 4:
          DpmValidateInitValue( (CanChannelHandle)4, dpmInitState->dpmInit_4 );
          break;
#  endif
#  if (kDpmNumberOfChannels > 5)
        case 5:
          DpmValidateInitValue( (CanChannelHandle)5, dpmInitState->dpmInit_5 );
          break;
#  endif
#  if (kDpmNumberOfChannels > 6)
        case 6:
          DpmValidateInitValue( (CanChannelHandle)6, dpmInitState->dpmInit_6 );
          break;
#  endif
#  if (kDpmNumberOfChannels > 7)
        case 7:
          DpmValidateInitValue( (CanChannelHandle)7, dpmInitState->dpmInit_7 );
          break;
#  endif
#  if (kDpmNumberOfChannels > 8)
#   error "The DPM only supports 8 channels!"
#  endif
      default:
        break;
    }
# else
    gActiveStateCh[loopIndex]  = Sleep_PowerDown;
    gBusReqCh[loopIndex]       = Local_EmcDetection; /* after init the power mode for all active channels is EMC detection */
# endif

# if defined(CCL_ENABLE_MULTIPLE_CONFIG)
    }
    else
    {
      gActiveStateCh[loopIndex]  = Sleep_PowerDown;
      gBusReqCh[loopIndex]       = Sleep_PowerDown; /* after init the power mode for all inactive channels is sleep */
    }
# endif


# if defined ( DPM_ENABLE_EXTENDEND_INITIALIZATION )
    /* gStartUpSleepDelayTimerCh is initialized in DpmValidateInitValue() dependent on the init value */
# else
    gStartUpSleepDelayTimerCh[loopIndex] = 0x00;
# endif

    /*****************************************************************************/
    /* user data support                                                         */
    /*****************************************************************************/
#  if defined (VGEN_ENABLE_NM_OSEK_D_UD)
#   if defined( NM_ENABLE_INDEXED_NM )
#    if defined( NM_ENABLE_CHANNEL_INDIRECTION )
    if (NmCanToNmIndirection[(CanChannelHandle)loopIndex]!=0xFF)
#    endif
#   else
#    if defined( NM_CAN_CHANNEL )
    if (NM_CAN_CHANNEL == (CanChannelHandle)loopIndex)
#    endif  
#   endif
    {
      dpmNmpduDpmWakeupReasonCAN(loopIndex) = (vbittype)0x00;
      dpmNmpduDpmAwakeReasonCAN(loopIndex)  = (vbittype)0x00;
      dpmNmpduDpmAwakeReasonDiag(loopIndex) = (vbittype)0x00;
    }
#  endif
    gDiagActiveFlag[loopIndex] = DPM_INACTIVE; /* diag indication flag */
  }
#else
 
# if defined ( DPM_ENABLE_EXTENDEND_INITIALIZATION )  
  DpmValidateInitValue( dpmInitState->dpmInit_0 );
# else
  gBusReq = Local_EmcDetection; /* after initialization the power mode is EMC detection */
  gStartUpSleepDelayTimer = 0x00;  /* initialze start up delay with zero real value is set in ccl callback functionts*/
# endif

  gDiagActiveFlag[DPM_SYS_USER1_CH0] = DPM_INACTIVE; /* diag indication flag */


  /*****************************************************************************/
  /* user data support                                                         */
  /*****************************************************************************/  
#  if defined (VGEN_ENABLE_NM_OSEK_D_UD)
  nmpduDpmWakeupReasonCAN(0) = (vbittype)0x00;
  nmpduDpmAwakeReasonCAN(0)  = (vbittype)0x00;
  nmpduDpmAwakeReasonDiag(0) = (vbittype)0x00;
#  endif

#endif

#if defined ( DPM_ENABLE_EXTENDEND_INITIALIZATION )
  CclInitPowerOn(&DpmCclInitList);
# if (kDpmNumberOfChannels > 1)
  for(loopIndex = (vsintx)(kDpmNumberOfChannels - 0x01); loopIndex >= 0x00; loopIndex--)
  {
    switch ( loopIndex )
    {
      case 0:
        DpmSetRequestOnInit( (CanChannelHandle)0, dpmInitState->dpmInit_0 );
        break;

      case 1:
        DpmSetRequestOnInit( (CanChannelHandle)1, dpmInitState->dpmInit_1 );
        break;
      
#  if (kDpmNumberOfChannels > 2)
      case 2:
        DpmSetRequestOnInit( (CanChannelHandle)2, dpmInitState->dpmInit_2 );
        break;
#  endif
#  if (kDpmNumberOfChannels > 3)
      case 3:
        DpmSetRequestOnInit( (CanChannelHandle)3, dpmInitState->dpmInit_3 );
        break;
#  endif
#  if (kDpmNumberOfChannels > 4)
      case 4:
        DpmSetRequestOnInit( (CanChannelHandle)4, dpmInitState->dpmInit_4 );
        break;
#  endif
#  if (kDpmNumberOfChannels > 5)
      case 5:
        DpmSetRequestOnInit( (CanChannelHandle)5, dpmInitState->dpmInit_5 );
        break;
#  endif
#  if (kDpmNumberOfChannels > 6)
      case 6:
        DpmSetRequestOnInit( (CanChannelHandle)6, dpmInitState->dpmInit_6 );
        break;
#  endif
#  if (kDpmNumberOfChannels > 7)
      case 7:
        DpmSetRequestOnInit( (CanChannelHandle)7, dpmInitState->dpmInit_7 );
        break;
#  endif
#  if (kDpmNumberOfChannels > 8)
#   error "The DPM only supports 8 channels!"
#  endif
      default:
        break;
    }
  }
# else
  DpmSetRequestOnInit(dpmInitState->dpmInit_0);
# endif
#endif

  lMaxChActModeVari = ApplDpmReadMaxChMode(); /* read max channel activity mode and variant information in bitcoded formate */

  if((lMaxChActModeVari & DPM_IMM_NO_EXT_FLAG_MASK) != DPM_CHECK_FLAG)/* get variant bit for immediate no external mode out of lMaxChActModeVari */ 
  {
    gRestrictionStatus.VariImmNoExt   = (vbittype)0x01; /* set variant coding bit */
  }
  else
  {
    gRestrictionStatus.VariImmNoExt   = (vbittype)0x00; /* clear variant coding bit */
  }

  if((lMaxChActModeVari & DPM_MAX_MODE_FLAG_MASK) != DPM_CHECK_FLAG) /* get variant bit for maximum activity mode out of lMaxChActModeVari */
  {
    gRestrictionStatus.VariMaxActMode = (vbittype)0x01; /* set variant coding bit */
    gRestrictionStatus.MaxActMode = (vuint8)(lMaxChActModeVari & 0x03); /* mask out the max activity mode information and 
                                                                         store into global restricion bit field */
    if(gRestrictionStatus.MaxActMode < DPM_EXTERNAL_MODE) /* handel restriction handling in init function to secure gap between init and first task call*/
      {
#if (kDpmNumberOfChannels > 1)
        for(loopIndex = (vsintx)(kDpmNumberOfChannels - 0x01); loopIndex >= 0x00; loopIndex--)
        {
          CclSetNetworkRestriction((CanChannelHandle)loopIndex);
        }

#else
        CclSetNetworkRestriction();
#endif           
      }
  }
  else /* variant coding bit is not set in non volatile memory */
  {
    /* clear variant coding bit */
    gRestrictionStatus.VariMaxActMode = (vbittype)0x00; 
    /* maximum activity mode is set to external mode, restrition is inactive */
    gRestrictionStatus.MaxActMode = 0x02; 
  }
  /* set flag to DPM save callback functions */
  gRestrictionStatus.CallNotNecessary = (vbittype)0x01;
  
#if !defined(C_ENABLE_DPM_PRODUCTION)
  /* get counter values from application */
  gDpmImmediateNoExternalCnt = ApplDpmReadCounterSleepForced();     /* get counter values from application */
  gDpmInhibitExternalCnt     = ApplDpmReadCounterNoExternalMode();  /* get counter values from application */
#endif

#if defined ( DPM_ENABLE_EXTENDEND_INITIALIZATION )
  /* gActiveState and gOnEntry are already set in DpmValidateInitValue() */
#else
  gActiveState  = Sleep_PowerDown;
  gOnEntry      = 0x00; /* reset entry flag */
#endif

  gTargetState  = Sleep_PowerDown;
  gUserReq      = Sleep_PowerDown;

  
  gLocalModeTimer = T_MINIMUM_LOCAL_MODE_DURATION; /* load local mode duration timer */

  gRestrictionStatus.MaxSleepFlag   = 0x01; /* enable local mode restricion */
  gRestrictionStatus.ImmNoExt       = 0x02; /* disable immediate no ext. restriction */

#if !defined(C_ENABLE_DPM_PRODUCTION)
  gDiagStatus.DiagImmCntFlag = DPM_INACTIVE;
#endif /* C_ENABLE_DPM_PRODUCTION */
  gRestrictionStatus.DiagActiveFlag = 0x00;  /* reset diagnostic flag */


#if defined ( DPM_ENABLE_EXTENDEND_INITIALIZATION )
#else
  DpmLocalRequest(DPM_SYS_USER1_CH0); /* set local request for system user channel 1 */
#endif
}
/******************************************************************************
Name          : DpmInit
Called by     : application
Preconditions : none
Parameters    : none
Returnvalue   : none
Description   : none
******************************************************************************/
void DPM_API_CALL_TYPE DpmInit(void)
{
  /* nothing to do */
}

/******************************************************************************
Name          : DpmGetRequestedActivityMode
Called by     : application
Preconditions : the DPM must be initialized.
Parameters    : the user number 
Returnvalue   : requested activity mode:  DPM_SLEEP_MODE
                                          DPM_LOCAL_MODE
                                          DPM_EXTERN_MODE
Description   : This function returns the requested activity mode for a user. 
                If nothing requested the default value is DPM_SLEEP_MODE.
******************************************************************************/
t_DpmActivityMode DPM_API_CALL_TYPE DpmGetRequestedActivityMode(t_DpmUserNumber UserNumber)
{
  t_DpmActivityMode lDpmRequestedActivityMode;

#if defined(DPM_ENABLE_DEBUG)
  /* ESCAN00022086: initialize variable here: */
  lDpmRequestedActivityMode = DPM_SLEEP_MODE; /* default value in case of assertion */

  if(UserNumber < DPM_USER_COUNT)
  {
#endif
    DpmInterruptDisable();
    if((gDpmUserExternalRequest[cDpmUserByteTable[UserNumber]] & cDpmUserSetMask[UserNumber])>0)
    {
      lDpmRequestedActivityMode = DPM_EXTERNAL_MODE;
    }
    else if((gDpmUserLocalRequest[cDpmUserByteTable[UserNumber]] & cDpmUserSetMask[UserNumber])>0)
    {
      lDpmRequestedActivityMode = DPM_LOCAL_MODE;
    }
    else
    {
       lDpmRequestedActivityMode = DPM_SLEEP_MODE; /* sleep mode is default*/
    }
    DpmInterruptRestore(); 
#if defined (DPM_ENABLE_DEBUG)
  }
  else /* the user number is invalid */
  {
    ApplDpmFatalError(DPM_ERR_INVALID_USER_NO);
  }
#endif
  return (lDpmRequestedActivityMode);
}

/******************************************************************************
Name          : DpmGetActualEcuActivityMode
Called by     : application
Preconditions : DPM must be initialized.
Parameters    : none
Returnvalue   : current main activity mode: DPM_SLEEP_MODE
                                            DPM_LOCAL_MODE
                                            DPM_EXTERNAL_MODE
Description   : This function returns the actual ECU activity mode
******************************************************************************/
t_DpmActivityMode DPM_API_CALL_TYPE DpmGetActualEcuActivityMode(void)
{
  t_DpmActivityMode lretActEcuMode;

  DpmInterruptDisable();
  if(gActiveState > Sleep_PowerDown)      /* activity mode is higher than sleep mode*/
  {
    if(gActiveState > Local_EmcDetection) /* activity mode is higer than local mode */
    {
      lretActEcuMode = DPM_EXTERNAL_MODE;
    }
    else /* activity mode is local mode*/
    {
      lretActEcuMode = DPM_LOCAL_MODE;
    }
  }
  else /* activity mode is sleep mode*/
  {
    lretActEcuMode = DPM_SLEEP_MODE;
  }
  DpmInterruptRestore();

  return (lretActEcuMode);
}

/******************************************************************************
Name          : DpmGetActualChannelActivityMode
Called by     : application
Preconditions : DPM must be initialized
Parameters    : none
Returnvalue   : bitcoded channel activity mode t_DpmChannelActivityMode
Description   : for single channel version this function returns the same 
                value as DpmGetActualEcuActivityMode
******************************************************************************/
t_DpmChannelActivityMode DPM_API_CALL_TYPE DpmGetActualChannelActivityMode(void) /* multi */
{
  t_DpmChannelActivityMode lretActEcuMode;

#if (kDpmNumberOfChannels > 1)
  vsintx  lLoopIndex; /* local loop index variable */

  lretActEcuMode = 0x00;
  for(lLoopIndex = (vsintx)(kDpmNumberOfChannels - 0x01); lLoopIndex >= 0x00; lLoopIndex--)
  {
  	lretActEcuMode = lretActEcuMode << 2; /* ESCAN00008782 shift to right channel position */
    if(gActiveStateCh[lLoopIndex] > Local_EmcDetection)
    {
      lretActEcuMode |= DPM_EXTERNAL_MODE;
    }
    else
    {
      if(gActiveStateCh[lLoopIndex] > Sleep_PowerDown)
      {
        lretActEcuMode |= DPM_LOCAL_MODE;
      }
    }
  }
#else
  if(gActiveState > Sleep_PowerDown) /* activity mode is higher than sleep mode */
  {
    if(gActiveState > Local_EmcDetection) /* activity mode is higer than local mode */
    {
      lretActEcuMode = DPM_EXTERNAL_MODE;
    }
    else /* activity mode is local mode */
    {
      lretActEcuMode = DPM_LOCAL_MODE;
    }
  }
  else /* activity mode is sleep mode*/
  {
    lretActEcuMode = DPM_SLEEP_MODE;
  }
#endif
  return (lretActEcuMode);
}

/******************************************************************************
Name          : DpmGetMaximumChannelActivityMode
Called by     : application
Preconditions : DPM must be initialized and once the DpmTask function must be called
Parameters    : none
Returnvalue   : bitfield with encoded maximum activity mode for each channel
Description   : This function calculates and returns the maximum activity mode for each channel.
******************************************************************************/
t_DpmChannelActivityMode DPM_API_CALL_TYPE DpmGetMaximumChannelActivityMode(void)
{
  t_DpmChannelActivityMode lRetMaxChannelActivityMode;
#if (kDpmNumberOfChannels > 1)
  t_DpmChannelActivityMode lMaxChHold;
  vuintx lLoopIndex;
#endif
  if(gRestrictionStatus.MaxActMode < DPM_EXTERNAL_MODE) /* MaxActMode is inactive */
  {
    if(gRestrictionStatus.MaxActMode < DPM_LOCAL_MODE) /* limitation to sleep mode */
    {
      lRetMaxChannelActivityMode = (t_DpmChannelActivityMode)DPM_SLEEP_MODE;
    }
    else /* limitation to local mode */
    {
      lRetMaxChannelActivityMode = (t_DpmChannelActivityMode)DPM_LOCAL_MODE;
    }
  }
  else
  {
    if(gRestrictionStatus.ImmNoExt < DPM_EXTERNAL_MODE) /* limitation to local mode */
    {
      lRetMaxChannelActivityMode = (t_DpmChannelActivityMode)DPM_LOCAL_MODE;
    }
    else /* no limitation */
    {
      lRetMaxChannelActivityMode = (t_DpmChannelActivityMode)DPM_EXTERNAL_MODE;
    }
  }

  if(gRestrictionStatus.DiagActiveFlag == DPM_ACTIVE)
  {
    lRetMaxChannelActivityMode = (t_DpmChannelActivityMode)DPM_EXTERNAL_MODE; /* a diag session disables all restricions*/
  }


#if (kDpmNumberOfChannels > 1)
/*-----------------------------------------------------------------------------
--- extend maximum channel activity mode to all channels 
-----------------------------------------------------------------------------*/
  lMaxChHold = lRetMaxChannelActivityMode;
  for(lLoopIndex = (vsintx)(kDpmNumberOfChannels-1);lLoopIndex > 0;lLoopIndex--)
  {
    lRetMaxChannelActivityMode = lRetMaxChannelActivityMode << 2;
    lRetMaxChannelActivityMode |= lMaxChHold;
  }
#endif
  return (lRetMaxChannelActivityMode);
}
/******************************************************************************
Name          : ApplCclSetExtEmcComReq
Called by     : CCL
Preconditions : none
Parameters    : channel index / none if single channel version
Returnvalue   : none
Description   : a EMC signal was detected on the communication bus
******************************************************************************/
#if(kDpmNumberOfChannels > 1)
void ApplCclSetExtEmcComReq(CanChannelHandle channel) 
{
  t_DpmApplRet lStateHandlerRet; /* return value of ApplDpmModeChangeSystem*/

  gBusReqCh[channel] = Local_EmcDetection; /* request emc detection for the right channel */
 
/*-----------------------------------------------------------------------------
--- channel dependent transition handling
-----------------------------------------------------------------------------*/
  if(gBusReqCh[channel] > gActiveStateCh[channel]) /* a transiton is required */
  {
    /* call of channel specific state handler function */
    lStateHandlerRet = ApplDpmModeChangeChannelSystem((vuint8)channel,gBusReqCh[channel],gActiveStateCh[channel]);

# if defined (DPM_ENABLE_DEBUG)
    DPM_ASSERT(lStateHandlerRet <= 0x01,DPM_ERR_INCORRECT_RETURN_VALUE); 
# endif    

    if(lStateHandlerRet == DPM_ACTION_COMPLETED) /* another call is not required */
    {
      gActiveStateCh[channel] = gBusReqCh[channel];/* perform transition */
      /* look interrupts to permit reentrant function call (prevent double call of ApplDpmModeChangeSystem */
      DpmInterruptDisable();
      if(gActiveStateCh[channel] > gActiveState) /* a global state transition is necessary */
      {
        gTargetState = cTransitionTable[Local_EmcDetection][gActiveState];
        if(gTargetState != NotPossible)
        {
          lStateHandlerRet = ApplDpmModeChangeSystem(gTargetState, gActiveState);

# if defined (DPM_ENABLE_DEBUG)
     DPM_ASSERT(lStateHandlerRet <= 0x01,DPM_ERR_INCORRECT_RETURN_VALUE); 
# endif

          if(lStateHandlerRet == DPM_ACTION_COMPLETED)
          {

# if defined(DPM_ENABLE_USER_NOTIFICATION)
            DpmModeChangeContainer(gTargetState, gActiveState);
# endif /* DPM_ENABLE_USER_NOTIFICATION */
           
            if(gTargetState != NotPossible)
            {
              gActiveState = gTargetState;  /* perform transition */
              gOnEntry = 0x01;              /* set entry flag */
            }       
          }
        }
        else /* gTargetState == NotPossible */
        {
          /* permanent assertion if impossible transition requested */
          DPM_ASSERT_PERMANENT(DPM_ERR_TRANS_NOT_POSSIBLE);
        }
      }
      DpmInterruptRestore();
    }
  }
}
#else
void ApplCclSetExtEmcComReq(void)
{
  t_DpmApplRet lStateHandlerRet; /* return value of ApplDpmModeChangeSystem*/

  gTargetState = (t_DpmState)cTransitionTable[Local_EmcDetection][gActiveState];
  if(gTargetState != NotPossible)
  {
    lStateHandlerRet = ApplDpmModeChangeSystem(gTargetState, gActiveState);

# if defined (DPM_ENABLE_DEBUG)
    DPM_ASSERT(lStateHandlerRet <= 0x01,DPM_ERR_INCORRECT_RETURN_VALUE); 
# endif

    if(lStateHandlerRet == DPM_ACTION_COMPLETED)
    {
# if defined(DPM_ENABLE_USER_NOTIFICATION)
      DpmModeChangeContainer(gTargetState, gActiveState);
# endif /* DPM_ENABLE_USER_NOTIFICATION */
      DpmInterruptDisable();
      if(gTargetState != NotPossible)
      {
        gActiveState = gTargetState;  /* perform transition */
        gOnEntry = 0x01;              /* set entry flag */
      }
      DpmInterruptRestore();
    }
  }
  gBusReq = Local_EmcDetection;                   /* emc is highest Request*/
  /* if a transition is not possible the ecu must be in external mode an emc wake up makes no sense in this case*/
} 
#endif /* kDpmNumberOfChannels > 1 */
/******************************************************************************
Name          : ApplCclSetExtCanComReq
Called by     : CCL
Preconditions : none
Parameters    : channel index / none if single channel version
Returnvalue   : none
Description   : a valid Msg was detected
******************************************************************************/
#if (kDpmNumberOfChannels > 1)
void ApplCclSetExtCanComReq(CanChannelHandle channel)
{
  /* set curren bus request to external startup delay */
  gBusReqCh[channel] = External_StartUpDelay;
  /* system user 1 req to ensure a communication startup */
  DpmExternalRequest((t_DpmUserNumber)channel);
  /* set start up delay timer to start value*/
#  if defined DPM_ENABLE_DIFF_STARTUP_TIME
  gStartUpSleepDelayTimerCh[channel] = cStartUpSleepDelayCycles[channel];
#  else
  gStartUpSleepDelayTimerCh[channel] = T_STARTUP_SLEEP_DELAY; 
#  endif

#  if defined (VGEN_ENABLE_NM_OSEK_D_UD)
  dpmNmpduDpmWakeupReasonCAN(channel) = (vbittype)0x01;
#  endif
}
#else
void ApplCclSetExtCanComReq(void)
{
  gBusReq = External_StartUpDelay; /* set busActive request */
  /* system user 1 req to ensure a communication startup */
  DpmExternalRequest(DPM_SYS_USER1_CH0);
  /* set start up delay timer to start value*/
  gStartUpSleepDelayTimer = T_STARTUP_SLEEP_DELAY;
  /* set wake up reason can */
#  if defined (VGEN_ENABLE_NM_OSEK_D_UD)
  nmpduDpmWakeupReasonCAN(0) = (vbittype)0x01;
#  endif
  
  gRestrictionStatus.ExtCanComReq = (vbittype)DPM_TRUE;
}
#endif
/******************************************************************************
Name          : ApplCclSetIntComReq
Called by     : CCL
Preconditions : none
Parameters    : channel index / none if single channel version
Returnvalue   : none
Description   : this callback function notifies the DPM when a channel goes online
******************************************************************************/
#if(kDpmNumberOfChannels > 1)
void ApplCclSetIntComReq(CanChannelHandle channel)
{
  /* set current bus request to external startup delay */
  gBusReqCh[channel] = External_StartUpDelay;
  /* system user 1 req to ensure a communication startup */
  DpmExternalRequest((t_DpmUserNumber)channel);
  /* set start up delay timer to start value*/
#  if defined DPM_ENABLE_DIFF_STARTUP_TIME
  gStartUpSleepDelayTimerCh[channel] = cStartUpSleepDelayCycles[channel];
#  else
  gStartUpSleepDelayTimerCh[channel] = T_STARTUP_SLEEP_DELAY; 
#  endif
}
#else
void ApplCclSetIntComReq(void)
{
  gBusReq = External_StartUpDelay; /* set busActive request */
  /* system user 1 req to ensure a communication startup */
  DpmExternalRequest(DPM_SYS_USER1_CH0);
  /* set start up delay timer to start value*/
  gStartUpSleepDelayTimer = T_STARTUP_SLEEP_DELAY;
}
#endif

/******************************************************************************
Name          : ApplCclClearComReq
Called by     : CCL
Preconditions : none
Parameters    : channel index / none if single channel version
Returnvalue   : none
Description   : this callback function notifies the DPM when a channel go offline
******************************************************************************/
#if(kDpmNumberOfChannels > 1)
void ApplCclClearComReq(CanChannelHandle channel)
{
  gBusReqCh[channel] = Sleep_PowerDown;
}
#else
void ApplCclClearComReq(void)
{
  gBusReq = Sleep_PowerDown; /* sleep is highest Request*/
}
#endif

/******************************************************************************
Name          : ApplCclComStop
Called by     : CCL
Preconditions : none
Parameters    : channel index / none if single channel version
Returnvalue   : none
Description   : notifies that the CCL has stopped the IL Rx and Tx
******************************************************************************/
#if (kDpmNumberOfChannels > 1)
void CCL_API_CALLBACK_TYPE ApplCclComStop(CanChannelHandle channel)
{
  gBusReqCh[channel] = External_WaitBusSleep;

}
#else
void CCL_API_CALLBACK_TYPE ApplCclComStop(void)
{
  gBusReq = External_WaitBusSleep; /* waitbussleep is highest Request */
}
#endif



/******************************************************************************
Name          : DpmTask
Called by     : application 
Preconditions : DPM must be initialized
Parameters    : none
Returnvalue   : none
Description   : Within this function all cyclic actions performed
******************************************************************************/
void DPM_API_CALL_TYPE DpmTask(void)
{
  t_DpmApplRet lStateHandlerRet;  /* return value of state handler callback function */
  vuint8       lImmRes;           /* local immediate no external mode restricion information */
  vuint8       lMaxActMode;       /* local maximum channel activity mode restricion */
  vuint8       lHighestReq;       /* calculated highest request */


#if (kDpmNumberOfChannels > 1)
  t_DpmState   lMaxReqChMode;     /* highest request out of all channels */
  vsintx       lLoopIndex;        /* loop index */
#endif


#if defined(DPM_ENABLE_REST_IND_FUNC)     /* available if restriction signal is located by GENy */
# if defined(VGEN_GENY)                   /* available for GENy only */
  /* ESCAN00029935 */
  DpmGetRestrictionInformation();
# else
  vuint8 allRestrictions;                 /* local variable for DPM restriction status container */

/*-----------------------------------------------------------------------------
--- get restriction signal value out of DBKOM 
-----------------------------------------------------------------------------*/
  if(DpmRestrictionStatusIndication == DPM_REST_STATUS_SET)
  {
    DpmRestrictionStatusIndication = DPM_REST_STATUS_CLEAR;

    allRestrictions = DPM_GET_RESTRICTION_SIGNAL();

/*-----------------------------------------------------------------------------
--- max activity mode handling
-----------------------------------------------------------------------------*/
    if(gRestrictionStatus.VariMaxActMode == 0x01) /* only if variant bit is set */
    { 
      gRestrictionStatus.MaxActMode =  DPM_MAX_MODE_SIGNAL(allRestrictions); /* update max act mode signal */
    }
/*-----------------------------------------------------------------------------
--- immediate no external mode handling
-----------------------------------------------------------------------------*/
    if(gRestrictionStatus.VariImmNoExt == 0x01) /* only if variant bit is set */
    {
      gRestrictionStatus.ImmNoExt = DPM_EXT_MODE_NOT_ALLOWED_SIGNAL(allRestrictions);/* update immediate no external */
    }
  }
# endif /*(VGEN_GENY)*/
#endif /* DPM_ENABLE_REST_IND_FUNC*/



/*-----------------------------------------------------------------------------
--- immediate no external mode restricion handling 
-----------------------------------------------------------------------------*/
  /* ESCAN00027775 */
  lImmRes = (vuint8)gRestrictionStatus.ImmNoExt;

#if !defined(C_ENABLE_DPM_PRODUCTION)
  if(lImmRes >= DPM_EXTERNAL_MODE)/* immediate restriction is deactivated */
  {
    gDiagStatus.DiagImmCntFlag = DPM_ACTIVE; /* activate immediate counter */
  }
#endif /* C_ENABLE_DPM_PRODUCTION */
/*-----------------------------------------------------------------------------
--- maximum channel activity mode restricion handling
-----------------------------------------------------------------------------*/
  if(gRestrictionStatus.MaxActMode != 0x00)   /* no limitation to sleep mode */
  {
    /* ESCAN00027775 */
    lMaxActMode = (vuint8)gRestrictionStatus.MaxActMode;/* restricion is active */
  }
  else /* in all other cases like signal not available the restricion is disabled*/
  {
    if(gRestrictionStatus.MaxSleepFlag == 0x01) /* a limitation to sleep mode 
                                                     is only possible if the flag is enabled */
    {
      lMaxActMode = 0x00; /* limitation to sleep mode*/
    }
    else
    {
      lMaxActMode = 0x01;
    }
  }

/*-----------------------------------------------------------------------------
--- diagnostic session handling
-----------------------------------------------------------------------------*/
  if(gRestrictionStatus.DiagActiveFlag == 0x01) /* deactivate all restrictions during an ongoing diagnostic session */
  {
    lMaxActMode = 0x02;
    lImmRes     = 0x02;
  }

#if defined (DPM_ENABLE_GLOBAL_INT_LOCK)/* external interrupt is used */
    DpmInterruptDisable(); /* global interrupt lock to prevent reentrant call of ApplDpmModeChangeSystem */
#else /* only can interrupts are used */
# if (kCanNumberOfChannels > 1)
  for(lLoopIndex = (vsintx)(kCanNumberOfChannels -1); lLoopIndex >= 0x00;lLoopIndex--)
  {
    DpmCanInterruptDisable(lLoopIndex);  /* lock local interrupts to prevent reentratn call of ApplDpmModeChangeSystem */
  }
# else
  DpmCanInterruptDisable();
# endif
#endif  

#if (kDpmNumberOfChannels > 1)

  lMaxReqChMode = Sleep_PowerDown; /* sleep mode is highest bus request */

  for(lLoopIndex = (vsintx)(kDpmNumberOfChannels -1); lLoopIndex >= 0x00;lLoopIndex--)
  {
/*-----------------------------------------------------------------------------
--- channel dependent application notification
-----------------------------------------------------------------------------*/
    if(gBusReqCh[lLoopIndex] != gActiveStateCh[lLoopIndex])
    {
      lStateHandlerRet = ApplDpmModeChangeChannelSystem((vuint8)lLoopIndex,gBusReqCh[lLoopIndex],gActiveStateCh[lLoopIndex]);

# if defined (DPM_ENABLE_DEBUG)
       DPM_ASSERT(lStateHandlerRet <= 0x01,DPM_ERR_INCORRECT_RETURN_VALUE); 
# endif
      if(lStateHandlerRet == DPM_ACTION_COMPLETED) /* transition can be performed*/
      {
        gActiveStateCh[lLoopIndex] = gBusReqCh[lLoopIndex];/* perform transition */
      }
    }
/*-----------------------------------------------------------------------------
--- maximum requested state calculation
-----------------------------------------------------------------------------*/
    if(gActiveStateCh[lLoopIndex] > lMaxReqChMode) /* check if a transition of a channel requires a global state change*/
    {
      if(gActiveStateCh[lLoopIndex] == External_StartUpDelay)
      {
        lMaxReqChMode = External_BusActive; /* in multiple channel systems the StartUpDelay mode is not visible for the global state machine*/
      }
      else
      {
        lMaxReqChMode = gActiveStateCh[lLoopIndex];/* the highest request over all channels will be stored in lMaxReqChMode*/
      }
    }
  } /* for loop*/

  if(lMaxReqChMode > Local_BusLocal) /* bus request is highest request (higher than bus local) */
  {
     lHighestReq = lMaxReqChMode; 
  }
#else /* single channel version*/
  if(gBusReq > Local_BusLocal) /* bus request is highest request (higher than bus local) */
  {
    lHighestReq = gBusReq;
  }
#endif /* #if (kDpmNumberOfChannels > 1) */

  else /* User request is highest request no comm bus request */
  {
    if(lMaxActMode >= DPM_LOCAL_MODE) /* maximum activity mode is at least DPM_LOCAL_MODE */
    {
      gUserReq = DpmCheckHighestRequest(); /* get the highes user Request */
    }
    else /* DPM is restricted to sleep mode */
    {
      gUserReq = DpmGetRequestedActivityMode(DPM_SYS_USER1_CH0); /* system user 1 requests are only valid */
    }
    if(gUserReq >= DPM_LOCAL_MODE)
    {
      lHighestReq = Local_BusLocal; /* bus local is highest request */ 
    }
    else
    {
      lHighestReq = Sleep_PowerDown; /* if nothing is requested sleep is highest request */
    }
  }


/*-----------------------------------------------------------------------------
--- transition handling
-----------------------------------------------------------------------------*/
  if(lHighestReq != gActiveState)     /* a transition is necessary */   
  {
    DpmInterruptDisable();
    gTargetState = cTransitionTable[lHighestReq][gActiveState];
    DpmInterruptRestore();
    if(gTargetState != NotPossible) /* a transition is possible check*/
    {
      if(gTargetState == Local_PrepareSleep)/* call save callback functions right before a transition to 
                                               local prepare sleep is performed */
      {
        if(gRestrictionStatus.CallNotNecessary == 0x01) /* only call callbacks if necessary */
        {
          gRestrictionStatus.CallNotNecessary = (vbittype)0x00;
          ApplDpmSaveMaxChMode((t_DpmMaxChMode)gRestrictionStatus.MaxActMode);
#if !defined(C_ENABLE_DPM_PRODUCTION) /* encapsulates all diagnostic code */
          ApplDpmSaveCounterValues(gDpmInhibitExternalCnt, gDpmImmediateNoExternalCnt);
#endif  
        }
      }
      else /* a transition to another mode than Local_PrepareSleep is perfomed*/
      {
        gRestrictionStatus.CallNotNecessary = (vbittype)0x01;
      }

      lStateHandlerRet = ApplDpmModeChangeSystem(gTargetState, gActiveState);

#if defined (DPM_ENABLE_DEBUG)
      DPM_ASSERT(lStateHandlerRet <= 0x01,DPM_ERR_INCORRECT_RETURN_VALUE); 
#endif

      if(lStateHandlerRet == DPM_ACTION_COMPLETED)
      {

#if defined(DPM_ENABLE_USER_NOTIFICATION)
        DpmModeChangeContainer(gTargetState, gActiveState);
#endif /* DPM_ENABLE_USER_NOTIFICATION */
        DpmInterruptDisable();
        if(gTargetState != NotPossible)
        {
          gActiveState = gTargetState;      /* perform transition */
          gOnEntry     = 0x01;              /* set entry flag */
        }
        else
        {
          /* permanent assertion if impossible transition requested */
          DPM_ASSERT_PERMANENT(DPM_ERR_TRANS_NOT_POSSIBLE); 
        }
        DpmInterruptRestore();
      }
    }
  }
  else /* if(lHighestReq != gActiveState)  */
  {
    if(lHighestReq == Local_BusLocal)
    {
      gRestrictionStatus.CallNotNecessary = (vbittype)0x01;
    }
  }

#if defined (DPM_ENABLE_GLOBAL_INT_LOCK)/* external interrupt is used */
    DpmInterruptRestore(); /* global interrupt lock to prevent reentrant call of ApplDpmModeChangeSystem */
#else /* only can interrupts are used */
# if (kCanNumberOfChannels > 1)
    for(lLoopIndex = (vsintx)(kCanNumberOfChannels -1); lLoopIndex >= 0x00;lLoopIndex--)
    {
      DpmCanInterruptRestore(lLoopIndex);  /* lock local interrupts to prevent reentratn call of ApplDpmModeChangeSystem */
    }
# else
    DpmCanInterruptRestore();
# endif
#endif


#if(kDpmNumberOfChannels > 1)
/*-----------------------------------------------------------------------------
--- channel dependent transition handling
-----------------------------------------------------------------------------*/
# if defined (DPM_ENABLE_GLOBAL_INT_LOCK)/* external interrupt is used */
  DpmInterruptDisable(); /* global interrupt lock to prevent reentrant call of ApplDpmModeChangeSystem */
# else /* only can interrupts are used */
  for(lLoopIndex = (vsintx)(kCanNumberOfChannels -1); lLoopIndex >= 0x00;lLoopIndex--)
  {
    DpmCanInterruptDisable(lLoopIndex);  /* lock local interrupts to prevent reentratn call of ApplDpmModeChangeSystem */
  }
# endif
  for(lLoopIndex = (vsintx)(kDpmNumberOfChannels - 1);lLoopIndex >= 0x00;lLoopIndex--)
  {
    if(gBusReqCh[lLoopIndex] != gActiveStateCh[lLoopIndex]) /* a transiton is required */
    {
      /* call of channel specific state handler function */
      lStateHandlerRet = ApplDpmModeChangeChannelSystem((vuint8)lLoopIndex,gBusReqCh[lLoopIndex],gActiveStateCh[lLoopIndex]);

# if defined (DPM_ENABLE_DEBUG)
      DPM_ASSERT(lStateHandlerRet <= 0x01,DPM_ERR_INCORRECT_RETURN_VALUE); 
# endif      

      if(lStateHandlerRet == DPM_ACTION_COMPLETED) /* another call is not required */
      {
        gActiveStateCh[lLoopIndex] = gBusReqCh[lLoopIndex];/* perform transition */
      }
    }

    /*****************************************************************************/
    /* communication bus specific state machine                                  */
    /*****************************************************************************/
    switch(gActiveStateCh[lLoopIndex])
    {
    case Sleep_PowerDown:
      CclDisableCommunication((CanChannelHandle)lLoopIndex);
      if((lImmRes < DPM_EXTERNAL_MODE)||(lMaxActMode < DPM_EXTERNAL_MODE))
      {
        CclSetNetworkRestriction((CanChannelHandle)lLoopIndex);
      }
      else
      {
        CclClearNetworkRestriction((CanChannelHandle)lLoopIndex);
      }
    break;
    case Local_EmcDetection:
      CclEnableCommunication((CanChannelHandle)lLoopIndex);

      if((lImmRes < DPM_EXTERNAL_MODE)||(lMaxActMode < DPM_EXTERNAL_MODE))
      {
        CclSetNetworkRestriction((CanChannelHandle)lLoopIndex);
      }
      else
      {
        CclClearNetworkRestriction((CanChannelHandle)lLoopIndex);
      }
    
      break;
    case External_BusActive:
    case External_WaitBusSleep:
      CclEnableCommunication((CanChannelHandle)lLoopIndex);
      if(lImmRes < DPM_EXTERNAL_MODE)
      {
        CclSetNetworkRestriction((CanChannelHandle)lLoopIndex);
      }
      else
      {
        CclClearNetworkRestriction((CanChannelHandle)lLoopIndex);
      }
#  if defined (VGEN_ENABLE_NM_OSEK_D_UD)
#   if defined( NM_ENABLE_INDEXED_NM )
#    if defined( NM_ENABLE_CHANNEL_INDIRECTION )
    if (NmCanToNmIndirection[(CanChannelHandle)lLoopIndex]!=0xFF)
#    endif
#   else
#    if defined( NM_CAN_CHANNEL )
    if (NM_CAN_CHANNEL == (CanChannelHandle)lLoopIndex)
#    endif  
#   endif
    {
      dpmNmpduDpmAwakeReasonCAN(lLoopIndex) = 0x00; /* reset awake reason can for user data */
    }
#  endif
      break;
    case External_StartUpDelay:
      CclEnableCommunication((CanChannelHandle)lLoopIndex);
      CclClearNetworkRestriction((CanChannelHandle)lLoopIndex);
#  if defined (VGEN_ENABLE_NM_OSEK_D_UD)
#   if defined( NM_ENABLE_INDEXED_NM )
#    if defined( NM_ENABLE_CHANNEL_INDIRECTION )
    if (NmCanToNmIndirection[(CanChannelHandle)lLoopIndex]!=0xFF)
#    endif
#   else
#    if defined( NM_CAN_CHANNEL )
    if (NM_CAN_CHANNEL == (CanChannelHandle)lLoopIndex)
#    endif  
#   endif
    {
      dpmNmpduDpmAwakeReasonCAN(lLoopIndex) = 0x01; /* set awake reason can for user data */
    }
#  endif      
      break;
/*---------------------------------------------------------------------------
--- default path
-----------------------------------------------------------------------------*/
     default:
# if defined(DPM_ENABLE_DEBUG)
      ApplDpmFatalError(DPM_ERR_UNKNOWN_ACTIVITY_MODE);
# endif
      break;
    }
  }
# if defined (DPM_ENABLE_GLOBAL_INT_LOCK)/* external interrupt is used */
  DpmInterruptRestore(); /* global interrupt lock to prevent reentrant call of ApplDpmModeChangeSystem */
# else /* only can interrupts are used */
  for(lLoopIndex = (vsintx)(kCanNumberOfChannels -1); lLoopIndex >= 0x00;lLoopIndex--)
  {
    DpmCanInterruptRestore(lLoopIndex);  /* lock local interrupts to prevent reentratn call of ApplDpmModeChangeSystem */
  }
# endif
#endif /*(kDpmNumberOfChannels > 1)*/



/*-----------------------------------------------------------------------------
--- mode specific actions
-----------------------------------------------------------------------------*/
  switch(gActiveState)
  {
/*-----------------------------------------------------------------------------
--- sleep or power down mode specific actions
-----------------------------------------------------------------------------*/
  case Sleep_PowerDown:
    if(gOnEntry == DPM_ACTIVE)
    {
      gLocalModeTimer = T_MINIMUM_LOCAL_MODE_DURATION;
      gRestrictionStatus.ImmNoExt = 0x02;     /* reset immediate no external mode restriction */
      gRestrictionStatus.MaxSleepFlag = 0x01; /* set local mode restriction flag */
# if defined(CCL_ENABLE_STOP_MODE_ECU) || defined(CCL_ENABLE_POWER_DOWN_MODE_ECU)   
      /* the ECU is now prepared for shutdown the call of DpmSystemShutdown guides the ECU to shutdown */ 
      DpmSystemShutdown(); 
# endif
    }
#if (kDpmNumberOfChannels == 1)
    if(lMaxActMode < DPM_EXTERNAL_MODE) /* set restricion to active */
    {
      CclSetNetworkRestriction();
    }
    else
    {
      CclClearNetworkRestriction();
    }
#endif
    break;
/*-----------------------------------------------------------------------------
--- Local_PrepareSleep specific actions
-----------------------------------------------------------------------------*/
  case Local_PrepareSleep:
    if(gOnEntry == DPM_ACTIVE)
    {
#if (kDpmNumberOfChannels > 1)

#else
      CclDisableCommunication();
      if((lImmRes < DPM_EXTERNAL_MODE)||(lMaxActMode < DPM_EXTERNAL_MODE)) /* restricion is active */
      {
        CclSetNetworkRestriction();
      }
      else
      {
        CclClearNetworkRestriction();
      }
#endif
    }
    break;
/*-----------------------------------------------------------------------------
--- Local_BusLocal specific actions
-----------------------------------------------------------------------------*/
  case Local_BusLocal:
#if (kDpmNumberOfChannels == 0x01)
    CclDisableCommunication(); /* communication is not possible in Local_BusLocal mode */
    if((lImmRes < DPM_EXTERNAL_MODE)||(lMaxActMode < DPM_EXTERNAL_MODE)) /* restricion is active */
    {
      CclSetNetworkRestriction();
    }
    else
    {
      CclClearNetworkRestriction();
    }
#endif
    if(gOnEntry == DPM_ACTIVE)
    {
      if(gLocalModeTimer == T_MINIMUM_LOCAL_MODE_DURATION) /* check if bus local mode is entered from sleep mode */
      {
        DpmInterruptDisable(); /* to ensure no request occure after get function */
        lHighestReq = DpmGetRequestedActivityMode(DPM_SYS_USER1_CH0); /* get requested activtiy mode*/
        if(lHighestReq != DPM_EXTERNAL_MODE) 
        {
          DpmLocalRequest(DPM_SYS_USER1_CH0);/* request local mode only if external mode is not requested*/
        }
        DpmInterruptRestore();
      }
    }
    else 
    {
      /* local mode timer handling */
      if(gLocalModeTimer != 0x00) /* timer is active */
      {
        gLocalModeTimer--;  /* decrement timer*/
      }
      else
      { 
        DpmInterruptDisable(); /* to ensure no request occure after get function */
        lHighestReq = DpmGetRequestedActivityMode(DPM_SYS_USER1_CH0); /* get requested activtiy mode*/
        if(lHighestReq != DPM_EXTERNAL_MODE) 
        {
          DpmSleepRequest(DPM_SYS_USER1_CH0); /* if timer is elapsed set DPM into sleep mode */
        }
        DpmInterruptRestore();
      }
    }

    break;
/*-----------------------------------------------------------------------------
--- Local_EmcDetection specific actions
-----------------------------------------------------------------------------*/
  case Local_EmcDetection:
    if(gOnEntry == DPM_ACTIVE)
    {    
      if(gRestrictionStatus.DiagActiveFlag == 0x00) /* deactivate all restrictions during an ongoing diagnostic session */
      {
        if(lMaxActMode != 0x00) /* clear flag only if restriciton to sleep mode is inactive*/
        {
          gRestrictionStatus.MaxSleepFlag = 0x00; /* clear local mode restriction flag */
        }
      }
    }
#if (kDpmNumberOfChannels == 1)
       CclEnableCommunication(); /* is enabled in first task to incrase the wake up time  */ 
#endif
    /* local mode timer handling */
    if(gLocalModeTimer != 0x00) /* timer is active */
    {
      gLocalModeTimer--;  /* Emc detection and local mode duration timer working parallel */
    }
#if (kDpmNumberOfChannels == 1)
    /* check if restriction is active and no external can com. request is pending */
    if(((lImmRes < DPM_EXTERNAL_MODE)||(lMaxActMode < DPM_EXTERNAL_MODE))&&(gRestrictionStatus.ExtCanComReq == DPM_FALSE))
    {
      CclSetNetworkRestriction();
    }
    else
    {
      CclClearNetworkRestriction();
    }
#endif        
    break;
/*-----------------------------------------------------------------------------
--- External_WaitBusSleep specific actions
-----------------------------------------------------------------------------*/
  case External_WaitBusSleep:
#if (kDpmNumberOfChannels == 1)
#  if defined (VGEN_ENABLE_NM_OSEK_D_UD)
    nmpduDpmAwakeReasonCAN(0) = 0x00; /* reset awake reason can for user data */
#  endif
#endif /* (kDpmNumberOfChannels == 1) */
    break;
/*-----------------------------------------------------------------------------
--- External_BusActive specific actions
-----------------------------------------------------------------------------*/
  case External_BusActive:
    if(gOnEntry == DPM_ACTIVE) /* perform all on entry actions */
    {
      /* ESCAN00036693 */
#if (kDpmNumberOfChannels == 1)
#  if defined (VGEN_ENABLE_NM_OSEK_D_UD)
      nmpduDpmAwakeReasonCAN(0) = 0x00;  /* reset awake reason can for user data */
#  endif
#endif
      /* reset local mode timer to ensure to set back the system user 1 local request*/
      gLocalModeTimer = 0x00;
      gRestrictionStatus.ExtCanComReq = DPM_FALSE; /* reset external can communication flag */
      if(gRestrictionStatus.DiagActiveFlag == 0x00) /* deactivate all restrictions during an ongoing diagnostic session */
      {
        /* local mode restriction is temporarily disabled because external mode was entered */
        gRestrictionStatus.MaxSleepFlag = 0x00; /* clear local mode restriction flag */
      }
    }
    else /* (onEntry) */
    {
#if (kDpmNumberOfChannels == 1)
      if(lImmRes == DPM_LOCAL_MODE)
      {
        CclSetNetworkRestriction();
      }
      else /* immediate no external mode is inactive */
      {
        CclClearNetworkRestriction();
      }
#endif /* (kDpmNumberOfChannels == 1)*/
#if !defined(C_ENABLE_DPM_PRODUCTION) /* encapsulates all diagnostic code */
/*-----------------------------------------------------------------------------
--- handling of diagnostic sleep force counter (immediate restriction cnt)
-----------------------------------------------------------------------------*/ 
      if(gDiagStatus.DiagImmCntFlag == DPM_ACTIVE)
      {       
        if((DpmCheckHighestUserRequest() == DPM_EXTERNAL_MODE) && (lImmRes == DPM_ACTIVE))
        {
          gDiagStatus.DiagImmCntFlag = DPM_INACTIVE;  /* reset diagnose counter flag*/
          if(gDpmImmediateNoExternalCnt == 0xffff)
          {
            gDpmImmediateNoExternalCnt = 0x8000; /* set overflow bit an reset counter value */
          }
          else
          {
            gDpmImmediateNoExternalCnt++; /* increment diagnostic counter */
          }
        }
      }
#endif /* !defined(C_ENABLE_DPM_PRODUCTION) */
    }
/*-----------------------------------------------------------------------------
--- StartUpSleepDelayCounter handling and immediate restriction for multi channel systems only
-----------------------------------------------------------------------------*/
#if (kDpmNumberOfChannels > 1)
    for(lLoopIndex = (vsintx)(kDpmNumberOfChannels - 0x01); lLoopIndex >= 0x00; lLoopIndex --)
    {
      if(gActiveStateCh[lLoopIndex] > External_WaitBusSleep)
      {
        if(gStartUpSleepDelayTimerCh[lLoopIndex] > 0x01) /* timer is active*/
        {
          gStartUpSleepDelayTimerCh[lLoopIndex]--; 
        }
        else /* timer elapsed*/
        {
          if(gStartUpSleepDelayTimerCh[lLoopIndex] != 0x00)
          {
            gBusReqCh[lLoopIndex] = External_BusActive; /* set bus request after 5s back to BusActive */
            gStartUpSleepDelayTimerCh[lLoopIndex] = 0x00;  /* set timer to zero */
          }
          /* request sleep mode for system user of channel each time start up sleep delay timer is zero*/
          if(gDiagActiveFlag[lLoopIndex] == DPM_INACTIVE)
          {
            DpmSleepRequest((vuint8)lLoopIndex);
          }
        }
      }
    }

#endif

    break;
#if (kDpmNumberOfChannels == 1)
/*-----------------------------------------------------------------------------
--- External_StartUpDelay specific actions
-----------------------------------------------------------------------------*/
     case External_StartUpDelay:
      if(gOnEntry == DPM_ACTIVE)
      {
        CclEnableCommunication();                         /* ccl restriction handling is deactiviated  */
        CclClearNetworkRestriction();
        gLocalModeTimer = 0x00;                           /* clear timer local mode timer */
#  if defined (VGEN_ENABLE_NM_OSEK_D_UD)
        nmpduDpmAwakeReasonCAN(0) = 0x01; /* set awake reason CAN for user data support */     
#  endif
      }
      else
      {
        if(gStartUpSleepDelayTimer > 0x01)
        {
          gStartUpSleepDelayTimer--;  /* decrement timer*/
        }
        else
        {
          if(gStartUpSleepDelayTimer != 0x00)
          {
            gBusReq = External_BusActive;
            gStartUpSleepDelayTimer = 0x00;     /* clear timer */
          }
          /* only set sleep request if diag active flag is inactive */
          if(gDiagActiveFlag[DPM_SYS_USER1_CH0] == DPM_INACTIVE)
          {
          /* set sleep request for sys user 1 always the timer is elapsed */
            DpmSleepRequest(DPM_SYS_USER1_CH0);    
          }
        }
      }
      
    break;
#endif
/*---------------------------------------------------------------------------
--- default path
-----------------------------------------------------------------------------*/
  default:
#if defined(DPM_ENABLE_DEBUG)
   ApplDpmFatalError(DPM_ERR_UNKNOWN_ACTIVITY_MODE);
#endif    
    break;

  }
  gOnEntry = 0x00;  /* reset entry flag*/

}

/***************************************************************************/
/* Dpm administration functions                                            */
/***************************************************************************/
/******************************************************************************
Name          : DpmCheckHighesRequest
Called by     : DpmTask
Preconditions : The DPM must be initialized to get a valid result.
Parameters    : none
Returnvalue   : vuint8 SLEEP_MODE,LOCAL_MODE and EXTERNAL_MODE
Description   : This function returns the higest requested mode under the scope
                of request priorities.
******************************************************************************/
static t_DpmState DpmCheckHighestRequest(void)
{
  vuint8      lDpmByteIndex;
  t_DpmState  lHighestRequest; 

  lHighestRequest = Sleep_PowerDown;/* if no other requeste is active the default is sleep_mode*/

  DpmInterruptDisable();
  for(lDpmByteIndex = 0;lDpmByteIndex < DPM_USER_BYTE ;lDpmByteIndex++)
  {
    if(gDpmUserLocalRequest[lDpmByteIndex] != 0x00) /* is at least one local request active*/
    {
      lHighestRequest = Local_BusLocal;
    }
  }

  for(lDpmByteIndex = 0; lDpmByteIndex < DPM_USER_BYTE ;lDpmByteIndex++)
  {
    if(gDpmUserExternalRequest[lDpmByteIndex] != 0x00) /* is at least one external request active*/
    {
      lHighestRequest = External_BusActive;
    }
  }
  DpmInterruptRestore(); /** enable interrupts **/  

  return lHighestRequest;
}

#if !defined(C_ENABLE_DPM_PRODUCTION) /* encapsulates all diagnostic code */
/******************************************************************************
Name          : DpmCheckHighesUserRequest
Called by     : DpmTask
Preconditions : The DPM must be initialized to get a valid result.
Parameters    : none
Returnvalue   : vuint8 SLEEP_MODE,LOCAL_MODE and EXTERNAL_MODE
Description   : This function returns the higest User requested mode under the scope
                of request priorities.
******************************************************************************/
static vuint8 DpmCheckHighestUserRequest(void)
{
  vuint8 lHighestRequest;  /* to store highest user request */

# if (DPM_USER_BYTE > 0x01)
  vuint8 lDpmByteIndex;    /* loop index for request arrays */
# endif

  lHighestRequest = DPM_SLEEP_MODE; /* if no other requeste is active the default is sleep_mode*/

  DpmInterruptDisable();  /* disable interrupts */
  if((gDpmUserLocalRequest[0]>>kDpmNumberOfChannels) != 0x00)
  {
    lHighestRequest = DPM_LOCAL_MODE;
  }

# if (DPM_USER_BYTE > 0x01)
  for(lDpmByteIndex = 1;lDpmByteIndex < DPM_USER_BYTE ;lDpmByteIndex++)
  {
    if(gDpmUserLocalRequest[lDpmByteIndex] != 0x00) /* is at least one local request active*/
    {
      lHighestRequest = DPM_LOCAL_MODE;
      break;
    }
  }
# endif /*(DPM_USER_BYTE > 0x01)*/

  if((gDpmUserExternalRequest[0]>>kDpmNumberOfChannels)!=0x00)
  {
    lHighestRequest = DPM_EXTERNAL_MODE;
  }

# if (DPM_USER_BYTE > 0x01)
  for(lDpmByteIndex = 1; lDpmByteIndex< DPM_USER_BYTE ;lDpmByteIndex++)
  {
    if(gDpmUserExternalRequest[lDpmByteIndex] != 0x00) /* is at least one external request active*/
    {
      lHighestRequest = DPM_EXTERNAL_MODE;
      break;
    }
  }
# endif /*(DPM_USER_BYTE > 0x01)*/

  DpmInterruptRestore();  /* eneable interrupts */ 

  return lHighestRequest;
}


/***************************************************************************/
/* Dpm diagnotic functions                                                 */
/***************************************************************************/


/******************************************************************************
Name          : DpmGetPointerDiagnosticRecord
Called by     : application
Preconditions : DPM must be initialized
Parameters    : none
Returnvalue   : DpmDiagnosticRecord pointer to diagnostic Chay
Description   : this funcion builts the diagnostic record and returns a pointer
                to the first element of the record.
******************************************************************************/
t_DpmPointerDiagnosticRecord DpmGetPointerDiagnosticRecord(void)
{
  vuint8 lByteIndex, lBitIndex, lTempUserMode, lWriteMask;
# if((DPM_USER_COUNT - kDpmNumberOfChannels) > 31)  
  vuint8 lReqResult;
# endif
  vuint16 lUserIndex;
  t_DpmPointerDiagnosticRecord DpmDiagnosticRecord;

  lUserIndex = kDpmNumberOfChannels; /* set user index to the value of the first "real" user */

  gDpmDiagRecord[0] = (vuint8) kDpmNumberOfChannels;                  /* number of channels */
  gDpmDiagRecord[1] = (vuint8)(gDpmInhibitExternalCnt >> 8);          /* MSB of  no external cnt */
  gDpmDiagRecord[2] = (vuint8)gDpmInhibitExternalCnt;                 /* LSB of  no external cnt */
  gDpmDiagRecord[3] = (vuint8)(gDpmImmediateNoExternalCnt >> 8);      /* MSB of forced bus sleep */
  gDpmDiagRecord[4] = (vuint8)gDpmImmediateNoExternalCnt;             /* LSB of forced bus sleep */
  /* fill byte 7 up to byte 14 with the user request information */
  for(lByteIndex = 5; lByteIndex < 13; lByteIndex++)
  {
    gDpmDiagRecord[lByteIndex] = 0xff; /* set all user requests to default value 0x03 */

    for(lBitIndex = 0; lBitIndex < 8; lBitIndex += 2)
    {
      if(lUserIndex < DPM_USER_COUNT)
      {
        lTempUserMode = DpmGetRequestedActivityMode((t_DpmUserNumber)lUserIndex);
        if(lTempUserMode == DPM_SLEEP_MODE)
        {
          lWriteMask = VUINT8_CAST ((vuint8)0x03 << lBitIndex);
          lWriteMask = VUINT8_CAST ~ VUINT8_CAST lWriteMask;

          gDpmDiagRecord[lByteIndex] &= lWriteMask; 
        }
        else if(lTempUserMode == DPM_LOCAL_MODE)
        {
          lWriteMask = VUINT8_CAST ((vuint8)0x02 << lBitIndex);
          lWriteMask = VUINT8_CAST ~ VUINT8_CAST lWriteMask;
          gDpmDiagRecord[lByteIndex] &= lWriteMask;
        }
        else /* lTempUserMode == DPM_EXTERNAL_MODE */
        {
          lWriteMask = VUINT8_CAST ((vuint8)0x01 << lBitIndex);
          lWriteMask = VUINT8_CAST ~ VUINT8_CAST lWriteMask;
          gDpmDiagRecord[lByteIndex] &= lWriteMask;
        }
      }

      lUserIndex++;
    }
  }
# if((DPM_USER_COUNT - kDpmNumberOfChannels) > 31)
  lTempUserMode = DPM_SLEEP_MODE;
  lReqResult    = DPM_SLEEP_MODE;

  gDpmDiagRecord[13] = 0x00; /* set user number of highest requested user to zero */
  for(lUserIndex = 32 + kDpmNumberOfChannels;lUserIndex < DPM_USER_COUNT; lUserIndex++)
  {
    lTempUserMode = DpmGetRequestedActivityMode((t_DpmUserNumber)lUserIndex);
    if(lTempUserMode > lReqResult)
    {
      lReqResult = lTempUserMode; /* store current maximum */
      gDpmDiagRecord[13] = (vuint8)lUserIndex; /* store number of highest user request */
    }
  }
  gDpmDiagRecord[14] = lReqResult; /* store highest user request*/
# else
  gDpmDiagRecord[13] = 0;
  gDpmDiagRecord[14] = 0xff;/* if less than 32 users allocated set byte 16 of reserved */
# endif
  gDpmDiagRecord[15] = 0x00;
  for(lUserIndex = 0; lUserIndex < kDpmNumberOfChannels; lUserIndex++)
  {
    lTempUserMode = DpmGetRequestedActivityMode((t_DpmUserNumber)lUserIndex);
    if(lTempUserMode == DPM_EXTERNAL_MODE)
    {
      lWriteMask = VUINT8_CAST ((vuint8)0x01 << lUserIndex);
      gDpmDiagRecord[15] |= lWriteMask;
    }
  }
  DpmDiagnosticRecord = gDpmDiagRecord;
  return DpmDiagnosticRecord;
}

/******************************************************************************
Name          : DpmDiagSetExternal
Called by     : DpmExternalRequest
Preconditions : DPM must be initialized
Parameters    : none
Returnvalue   : none
Description   : this function check if a limitation is active and increments 
                if necessary the diagnostic counters.
******************************************************************************/
void DpmDiagSetExternal(void)
{
  if(gRestrictionStatus.DiagActiveFlag == 0x00)    /* count only if no diagnostic session is active */
  {
    if((gRestrictionStatus.MaxActMode < 0x02)&&(gActiveState < External_WaitBusSleep)) /* count only if diagnostic session becomes active */
    {
      if(gDpmInhibitExternalCnt == 0xffff)  /* at overflow highest bit keeps highe*/
      {
        gDpmInhibitExternalCnt = 0x8000;    /* set overflow bit and reset counter */
      }
      else
      {
        gDpmInhibitExternalCnt++;
      }
    }
  }
}

#endif /* !defined(C_ENABLE_DPM_PRODUCTION) */

/* ESCAN00028955 */
/******************************************************************************
Name          : DpmIndicateActiveDiagnosticSession
Called by     : application
Preconditions : DPM must be initialized
Parameters    : t_DpmFlag DiagnosticSessionActive to indicate if a diagnostic 
                session is active
Returnvalue   : none
Description   : this function notivies the DPM if a diagnostic session is active
                or inactive. Based on this information the DPM suspend the 
                limitation and immediately no external function.
******************************************************************************/
void DPM_API_CALL_TYPE DpmIndicateActiveDiagnosticSession(t_DpmFlag DiagnosticSessionActive)
{
  if(DiagnosticSessionActive == DPM_TRUE)
  {
    gRestrictionStatus.DiagActiveFlag = 0x01;
#if !defined(C_ENABLE_DPM_PRODUCTION)
    gDiagStatus.DiagImmCntFlag = DPM_INACTIVE;
#endif
  }
  else /* end of active diag session */
  {
    gRestrictionStatus.DiagActiveFlag = DPM_INACTIVE; /* clear active diag mode flag enable restrictions */
  } 
}

/****************************************************************************
Name          : DpmSystemShutdown
Called by     : DPM or Application depends on configuration
Preconditions : System must be prepared for ECU shut down
Parameters    : none
Return values : none
Description   : DpmSystemShutdown perform a consistency check and controls the
                transceivers in the configurated manner.
*****************************************************************************/
void DPM_API_CALL_TYPE DpmSystemShutdown(void)
{
  t_DpmState lHighestReq;
  vuint8     lConsCheckRes;

  /* disable global interrupts to avoid a disturbance of shut down process */
  DpmInterruptDisable(); 

  lHighestReq = DpmCheckHighestRequest();
  if(lHighestReq == DPM_SLEEP_MODE) /* */
  {
    /* ESCAN00047381: if a bus wake up occurred before the active state would not be Sleep_PowerDown, so do shutdown only if state is Sleep_PowerDown: */
    if( gActiveState == Sleep_PowerDown )
    {
      /* perform consistency check and control trcv. as configured */
      lConsCheckRes = CclSystemShutdown();

      if(lConsCheckRes == DPM_TRUE)
      {
#if defined(CCL_ENABLE_STOP_MODE_ECU) || defined(CCL_ENABLE_CUSTOMER_MODE_ECU)
        ApplDpmSystemShutdown();
#endif
      }
      else /* consistency check failed */
      {
        /* call permanent assertion if consistency check fails */
        DPM_ASSERT_PERMANENT(DPM_ERR_CCL_CONS_CHECK_FAIL);
      }
    }
  }
  DpmInterruptRestore();
}
/****************************************************************************
Name          : DpmDiagExtReq
Called by     : Diagnostic module
Preconditions : -
Parameters    : channel
Return values : none
Description   : Allows the diagnostic copmonent to keep the ECU awake during
                an active diagnostic session. All restrictions will be dis-
                abled during this period.
****************************************************************************/
void DPM_API_CALL_TYPE DpmDiagExtReq(t_DpmUserNumber userNumber)
{
# if (kDpmNumberOfChannels > 1)&&(!defined(CCL_ENABLE_MULTIPLE_CONFIG)) 
  vsintx lChannelLoop;
# endif

# if defined (DPM_ENABLE_DEBUG)
    DPM_ASSERT(userNumber < kDpmNumberOfChannels,DPM_ERR_INVALID_USER_NO); 
# endif

# if defined(V_ENABLE_USE_DUMMY_STATEMENT)&&(!defined(CCL_ENABLE_MULTIPLE_CONFIG))
  userNumber = userNumber;
# endif

  gRestrictionStatus.DiagActiveFlag = DPM_ACTIVE; /* set DPM to active diag mode disable all restrictions */

# if (kDpmNumberOfChannels > 1)
#  if defined CCL_ENABLE_MULTIPLE_CONFIG /* keep for multiple config the diagnostic CAN channel awake only */

    gDiagActiveFlag[(vuint8)userNumber] = DPM_ACTIVE;/* set diag active flag to prevent the ECU to enter sleep mode */

#    if defined (VGEN_ENABLE_NM_OSEK_D_UD)
#     if defined( NM_ENABLE_INDEXED_NM )
#      if defined( NM_ENABLE_CHANNEL_INDIRECTION )
    if (NmCanToNmIndirection[(CanChannelHandle)userNumber]!=0xFF)
#      endif
#     else
#      if defined( NM_CAN_CHANNEL )
    if (NM_CAN_CHANNEL == (CanChannelHandle)userNumber)
#      endif  
#     endif
    {
      dpmNmpduDpmAwakeReasonDiag((vuint8)userNumber) = (vbittype)0x01; /* set user data flag for awake reason diag */
    }
#    endif 
    
    DpmExternalRequest((vuint8)userNumber); /* set system user request for all channels to keep ECU awake */

#  else /* no multiple config define */
  for(lChannelLoop = (vsintx)(kDpmNumberOfChannels - 0x01);lChannelLoop >= 0;lChannelLoop--)
  {
    gDiagActiveFlag[(vuint8)lChannelLoop] = DPM_ACTIVE;/* set diag active flag to prevent the ECU to enter sleep mode */

#    if defined (VGEN_ENABLE_NM_OSEK_D_UD)
#     if defined( NM_ENABLE_INDEXED_NM )
#      if defined( NM_ENABLE_CHANNEL_INDIRECTION )
    if (NmCanToNmIndirection[(CanChannelHandle)lChannelLoop]!=0xFF)
#      endif
#     else
#      if defined( NM_CAN_CHANNEL )
    if (NM_CAN_CHANNEL == (CanChannelHandle)lChannelLoop)
#      endif  
#     endif
    {
      dpmNmpduDpmAwakeReasonDiag((vuint8)lChannelLoop) = (vbittype)0x01; /* set user data flag for awake reason diag */
    }
#    endif 
    
    DpmExternalRequest((vuint8)lChannelLoop); /* set system user request for all channels to keep ECU awake */
  }
#  endif /* CCL_ENABLE_MULTIPLE_CONFIG */
# else /* single channel case */
  gDiagActiveFlag[DPM_SYS_USER1_CH0] = DPM_ACTIVE;
  
  DpmExternalRequest(DPM_SYS_USER1_CH0); /* set system user request for all channels to keep ECU awake */

#   if defined (VGEN_ENABLE_NM_OSEK_D_UD)
    nmpduDpmAwakeReasonDiag(DPM_SYS_USER1_CH0) = (vbittype)0x01; /* set user data flag for awake reason diag */
#   endif 
# endif

# if !defined(C_ENABLE_DPM_PRODUCTION) /* encapsulates all diagnostic code */
  gDiagStatus.DiagImmCntFlag = DPM_INACTIVE; /* deactivate immediate no external mode counter */
# endif
}

/****************************************************************************
Name          : DpmDiagSleepReq
Called by     : Diagnostic module
Preconditions : -
Parameters    : channel
Return values : none
Description   : Signals DPM the end of a diagnostic session.
****************************************************************************/
void DPM_API_CALL_TYPE DpmDiagSleepReq(t_DpmUserNumber userNumber)
{
# if (kDpmNumberOfChannels > 1)&&(!defined(CCL_ENABLE_MULTIPLE_CONFIG))
  vsintx lChannelLoop;
# endif

# if defined(V_ENABLE_USE_DUMMY_STATEMENT)&&(!defined(CCL_ENABLE_MULTIPLE_CONFIG))
  userNumber = userNumber;
# endif


# if defined (DPM_ENABLE_DEBUG)
    DPM_ASSERT(userNumber < kDpmNumberOfChannels,DPM_ERR_INVALID_USER_NO); 
# endif 

   gRestrictionStatus.DiagActiveFlag = DPM_INACTIVE; /* clear active diag mode flag enable restrictions */

# if (kDpmNumberOfChannels > 1)
#  if defined CCL_ENABLE_MULTIPLE_CONFIG /* keep for multiple config the diagnostic CAN channel awake only */
    
   gDiagActiveFlag[(vuint8)userNumber] = DPM_INACTIVE; /* channel specific flag handling */

#    if defined (VGEN_ENABLE_NM_OSEK_D_UD)
#     if defined( NM_ENABLE_INDEXED_NM )
#      if defined( NM_ENABLE_CHANNEL_INDIRECTION )
    if (NmCanToNmIndirection[(CanChannelHandle)userNumber]!=0xFF)
#      endif
#     else
#      if defined( NM_CAN_CHANNEL )
    if (NM_CAN_CHANNEL == (CanChannelHandle)userNumber)
#      endif  
#     endif
    {
      dpmNmpduDpmAwakeReasonDiag((vuint8)userNumber) = (vbittype)0x00; /* clear user data flag for awake reason diag */
    }
#    endif
  if(gStartUpSleepDelayTimerCh[(vuint8)userNumber] == 0x00)
  {
    DpmSleepRequest((vuint8)userNumber);
  }

#  else /* no multiple config define*/

  for(lChannelLoop = (vsintx)(kDpmNumberOfChannels - 0x01);lChannelLoop >= 0;lChannelLoop--)
  {
    gDiagActiveFlag[(vuint8)lChannelLoop] = DPM_INACTIVE; /* channel specific flag handling */

#    if defined (VGEN_ENABLE_NM_OSEK_D_UD)
#     if defined( NM_ENABLE_INDEXED_NM )
#      if defined( NM_ENABLE_CHANNEL_INDIRECTION )
    if (NmCanToNmIndirection[(CanChannelHandle)lChannelLoop]!=0xFF)
#      endif
#     else
#      if defined( NM_CAN_CHANNEL )
    if (NM_CAN_CHANNEL == (CanChannelHandle)lChannelLoop)
#      endif  
#     endif
    {
      dpmNmpduDpmAwakeReasonDiag((vuint8)lChannelLoop) = (vbittype)0x00; /* clear user data flag for awake reason diag */
    }
#    endif

    if(gStartUpSleepDelayTimerCh[(vuint8)lChannelLoop] == 0x00)
    {
      DpmSleepRequest((vuint8)lChannelLoop);
    }

  }
#  endif /* CCL_ENABLE_MULTIPLE_CONFIG */
# else /* single channel case */
  gDiagActiveFlag[DPM_SYS_USER1_CH0] = DPM_INACTIVE; /* channel specific flag handling */

#   if defined (VGEN_ENABLE_NM_OSEK_D_UD)
  nmpduDpmAwakeReasonDiag(DPM_SYS_USER1_CH0) = (vbittype)0x00; /* clear user data flag for awake reason diag */
#   endif

   if(gStartUpSleepDelayTimer == 0x00) /* set sleep request only if start up delay time is elapsed */
   {
      DpmSleepRequest(DPM_SYS_USER1_CH0);
   }
# endif

}
