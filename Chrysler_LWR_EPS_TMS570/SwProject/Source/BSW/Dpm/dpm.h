/*****************************************************************************
| Project Name: DPM   Decentral Power Management
|    File Name: dpm.h
|
|  Description: DPM OEM for DC
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
| 2003-12-19  00.09.00  Alb     initial version
| 2004-01-30  01.00.00  Alb     released version
| 2004-02-04  01.01.00  Alb     optimizations include structure
| 2004-03-02  01.02.00  Alb     ESCAN00007613 optimization of DPM 
|                               ESCAN00007635 changes after review
| 2004-06-18  02.00.00  Alb     ESCAN00008621 no changes
| 2004-06-29  02.01.00  Alb     ESCAN00008707 add define DPM_CHECK_CAST 
| 2004-07-07  02.02.00  Et      ESCAN00008780 wrong CALL_TYPE for ApplDpmReadMaxChMode
|                               ESCAN00008782 return value API "DpmGetActualChannelActivityMode"
| 2004-08-02  02.03.00  Alb     ESCAN00009155 changes to use DPM in SLP6
|                       Alb     ESCAN00009156 remove unused function declarations
| 2004-10-04  02.04.00  Alb     ESCAN00009471 in mulitpe channel systems a delay of each channel is possible
|                       Alb     ESCAN00009446 additional state External_StartUpDelay 
|                       Alb     ESCAN00009631 nothing to do
|                       Alb     ESCAN00008902 add polling interface for restriction signal
|                       Alb     ESCAN00009680 change naming convention
|                       Alb     ESCAN00009742 Remove activity mode Extrnal_BusOff from DPM
|                       Alb     ESCAN00009746 add interrupt lock during target calculation
| 2004-10-12  02.05.00  Alb     ESCAN00009834 decrease value of DPM_DIAG_RECORD_LENGTH from 22 to 17
|                       Alb     ESCAN00009891 no changes
| 2004-10-22  02.06.00  Alb     ESCAN00009957 no changes
|                       Alb     ESCAN00009973 change protoype of DpmGetMaximumChannelEcuActivityMode
|                       Alb     ESCAN00009974 no changes
| 2004-12-10  02.07.00  Alb     ESCAN00010152 adjust version
|                       Alb     ESCAN00010312 no changes
| 2004-12-20  02.08.00  Alb     ESCAN00010645 delete VGEN_GENY encapsultaion to enable flag defines 
| 2005-02-17  02.09.00  Alb     ESCAN00011061 no changes
| 2005-02-21  02.10.00  Alb     ESCAN00011504 review changes and optimizations 
|                       Alb     ESCAN00010300 no changes
|                       Alb     ESCAN00011505 add DiagActiveFlag to t_DpmRestriction
|                       Alb     ESCAN00011530 no changes
| 2005-04-05  02.11.00  Alb     ESCAN00011713 encapsulate features with organi switches
| 2005-04-18  02.12.00  Alb     ESCAN00011979 no changes
|                       Alb     ESCAN00011991 add defines for the DPM features
|                       Alb     ESCAN00012005 no changes
|                       Alb     ESCAN00011945 add DPM_API_CALL_TYPE to diag request functions
| 2005-05-02  02.13.00  Alb     ESCAN00012103 no changes
| 2005-08-24  02.14.00  Alb     ESCAN00013257 no changes
|                       Alb     ESCAN00013147 no changes
|                       Alb     ESCAN00013287 no changes
| 2005-09-13  02.15.00  Alb     ESCAN00013427 no changes
|                       Alb     ESCAN00013211 add new error code defines
|                       Alb     ESCAN00013532 no changes
| 2005-11-21  02.16.00  Alb     ESCAN00014315 add paging prefix for ApplCclComStop
|                       Alb     ESCAN00014354 decrase wake up time 
| 2005-12-12  02.17.00  Alb     ESCAN00014532 no changes
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
| 2010-01-15  02.23.02  Dhf     ESCAN00038125 no changes here
| 2011-03-07  02.23.03  Dhf     ESCAN00047381 no changes here
|*****************************************************************************/

#ifndef V_DPM_H
# define V_DPM_H
/***************************************************************************/
/* Include files                                                           */
/***************************************************************************/
# include "v_cfg.h"
# include "v_def.h"
# include "dpm_cfg.h"

/***************************************************************************/
/* Version Defines                                                         */
/***************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject : Ccl_Dpm_Dc CQComponent : Implementation */
# define CCL_DPM_DC_VERSION 0x0223
# define CCL_DPM_DC_RELEASE_VERSION 0x03

/***************************************************************************/
/* Version Defines to stay compatiple with older versions                  */
/***************************************************************************/
# define DPM_MAIN_VERSION   CCL_DPM_DC_VERSION
# define DPM_BUGFIX_VERSION CCL_DPM_DC_RELEASE_VERSION

/***************************************************************************/
/* Paging Defines                                                          */
/***************************************************************************/
# if !defined(DPM_API_CALL_TYPE)
#  define DPM_API_CALL_TYPE
# endif
# if !defined(DPM_API_CALLBACK_TYPE)
#  define DPM_API_CALLBACK_TYPE
# endif

/***************************************************************************/
/* DPM feature configuration                                               */
/***************************************************************************/
#  define DPM_ENABLE_UD_SUPPORT

#  define DPM_ENABLE_DIAG_AWAKE

#  define DPM_ENABLE_ADV_SHUTDOWN

#  define DPM_ENABLE_STARTUP_TIME

/***************************************************************************/
/* Defines                                                                 */
/***************************************************************************/
/** activity modes **/
# define DPM_SLEEP_MODE              ((vuint8)0x00)  /* main state of DPM */
# define DPM_LOCAL_MODE              ((vuint8)0x01)  /* main state of DPM */
# define DPM_EXTERNAL_MODE           ((vuint8)0x02)  /* main state of DPM */

# define DPM_TRUE                  ((vuint8)0x01)    /* internal flag status */
# define DPM_FALSE                 ((vuint8)0x00)    /* internal flag status */

# define DPM_ACTION_COMPLETED      ((vuint8)0x00)    /* return value of ApplDpmPrepareSleep and ApplDpmUndoPrepareSleep */
# define DPM_ANOTHER_CALL_REQUIRED ((vuint8)0x01)    /* return value of ApplDpmPrepareSleep and ApplDpmUndoPrepareSleep */

# define DPM_INACTIVE              ((vuint8)0x00)    /* internal flag status */
# define DPM_ACTIVE                ((vuint8)0x01)    /* internal flag status */

# if (kDpmNumberOfChannels > 1)
#  define DPM_MAX_MODE_FLAG_MASK    ((vuint32)0x80000000u)
#  define DPM_IMM_NO_EXT_FLAG_MASK  ((vuint32)0x40000000u)
#  define DPM_CHECK_FLAG            ((vuint32)0x00000000u)
# else
#  define DPM_MAX_MODE_FLAG_MASK    ((vuint8)0x80u)
#  define DPM_IMM_NO_EXT_FLAG_MASK  ((vuint8)0x40u)
#  define DPM_CHECK_FLAG            ((vuint8)0x00u)
# endif

# if defined(DPM_ENABLE_REST_IND_FUNC)
#  define DPM_REST_STATUS_CLEAR     ((vuint8)0x00)    /* indication flag for restriction signal is cleard */
#  define DPM_REST_STATUS_SET       ((vuint8)0x01)    /* indication flag for restriction signal is set */
# endif

# if !defined(C_ENABLE_DPM_PRODUCTION)
#  define DPM_DIAG_RECORD_LENGTH 17
# endif

/** error codes **/
# if defined(DPM_ENABLE_DEBUG)
#  define DPM_ERR_NOT_INITIALIZED             ((vuint8)0x00)
#  define DPM_ERR_UNKNOWN_ACTIVITY_MODE       ((vuint8)0x01)
#  define DPM_ERR_INCORRECT_RETURN_VALUE      ((vuint8)0x02)
#  define DPM_ERR_INVALID_USER_NO             ((vuint8)0x03)
#  define DPM_ERR_INIT_VALUE_NOT_CORRECT      ((vuint8)0x06)
# endif /* defined(DPM_ENABLE_DEBUG) */
/* permanent error codes */
# define DPM_ERR_CCL_CONS_CHECK_FAIL         ((vuint8)0x04)
# define DPM_ERR_TRANS_NOT_POSSIBLE          ((vuint8)0x05)



/***************************************************************************/
/* defines for DPM modes                                                   */
/***************************************************************************/
# define SLP_PD  (vuint8)0x00
# define LOC_PS  (vuint8)0x01
# define LOC_BL  (vuint8)0x02
# define LOC_ED  (vuint8)0x03
# define EXT_WB  (vuint8)0x04
# define EXT_BA  (vuint8)0x05
# define EXT_SD  (vuint8)0x06
# define NOT_PO  (vuint8)0x07
/* to get compatible to the old interface */
# define  Sleep_PowerDown           SLP_PD         
# define  Local_PrepareSleep        LOC_PS
# define  Local_BusLocal            LOC_BL
# define  Local_EmcDetection        LOC_ED
# define  External_WaitBusSleep     EXT_WB
# define  External_BusActive        EXT_BA
# define  External_StartUpDelay     EXT_SD
# define  NotPossible               NOT_PO

/***************************************************************************/
/* data types                                                              */
/***************************************************************************/
typedef vuintx  t_DpmRetCode;
typedef vuintx  t_DpmWakeUpPermission;
typedef vuint8  t_DpmUserNumber;
typedef vuint8  t_DpmActivityMode;
typedef vuintx  t_DpmFlag;
typedef vuintx  t_DpmChannelActivityMode;

# if !defined(C_ENABLE_DPM_PRODUCTION)
typedef vuint8* t_DpmPointerDiagnosticRecord;
# endif

typedef struct{
  vbittype VariMaxActMode   : 1;
  vbittype VariImmNoExt     : 1;
  vbittype ImmNoExt         : 2;
  vbittype MaxActMode       : 2;
  vbittype MaxSleepFlag     : 1; /* max activity mode enable flag*/
  vbittype CallNotNecessary : 1; /* flag to prevent cyclic call of ApplDpmSave... callbacks */
  vbittype ExtCanComReq     : 1; /* flag to indicate external can wake up */
  vbittype DiagActiveFlag   : 1; /* flag to indicate active diag session */
  vbittype Dummy            : 6; /* dummy entry to ensure byte alignement */
} t_DpmRestriction;

# if !defined(C_ENABLE_DPM_PRODUCTION)
typedef struct{
  
  vbittype DiagImmCntFlag : 1;
  vbittype Dummy          : 7; /* to allocata a whole byte */
} t_DpmDiagStatusFlags;
# endif /* C_ENABLE_DPM_PRODUCTION */

# if (kCanNumberOfChannels > 1)
typedef vuint32 t_DpmMaxChModeVariantCode;
# else
typedef vuint8  t_DpmMaxChModeVariantCode;
# endif

# if (kDpmNumberOfChannels > 1)
typedef vuint16 t_DpmMaxChMode;
# else
typedef vuint8  t_DpmMaxChMode;
# endif

typedef vuint8 t_DpmApplRet; /* return value of ApplDpmModeChangeSystem() */

/* enum to index all possible sub states within the dpm state machine */

typedef vuint8  t_DpmState;

#if defined ( DPM_ENABLE_EXTENDEND_INITIALIZATION )
typedef enum
{
  kDpmInitEmc,
  kDpmInitLocal,
  kDpmInitExternal
}tDpmInitParaType;

typedef struct DpmInitParaList
{
  tDpmInitParaType dpmInit_0;
#if (kDpmNumberOfChannels > 1)
  tDpmInitParaType dpmInit_1;
#endif
#if (kDpmNumberOfChannels > 2)
  tDpmInitParaType dpmInit_2;
#endif
#if (kDpmNumberOfChannels > 3)
  tDpmInitParaType dpmInit_3;
#endif
#if (kDpmNumberOfChannels > 4)
  tDpmInitParaType dpmInit_4;
#endif
#if (kDpmNumberOfChannels > 5)
  tDpmInitParaType dpmInit_5;
#endif
#if (kDpmNumberOfChannels > 6)
  tDpmInitParaType dpmInit_6;
#endif
#if (kDpmNumberOfChannels > 7)
  tDpmInitParaType dpmInit_7;
#endif
}tDpmInitParaListType;
#endif


/***************************************************************************/
/* Version information                                                     */
/***************************************************************************/
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kDpmMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kDpmSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kDpmBugFixVersion;

/***************************************************************************/
/* assertions                                                              */
/***************************************************************************/
# if defined (DPM_ENABLE_DEBUG)
#  define DPM_ASSERT(p,e)  if(!(p)){ApplDpmFatalError(e);}
# else
#  define DPM_ASSERT(p,e)
# endif
/*  this assertions are always active */
# define DPM_ASSERT_PERMANENT(e) ApplDpmFatalError(e)


/***************************************************************************/
/* External variable declaration                                           */
/***************************************************************************/
/* restriction status information */
V_MEMRAM0 extern V_MEMRAM1 t_DpmRestriction V_MEMRAM2 gRestrictionStatus;

/***************************************************************************/
/* API function prototypes                                                 */
/***************************************************************************/
#if defined (DPM_ENABLE_EXTENDEND_INITIALIZATION)
void                      DPM_API_CALL_TYPE DpmInitPowerOn(const tDpmInitParaListType* dpmInitState);
#else
void                      DPM_API_CALL_TYPE DpmInitPowerOn(void);
#endif
void                      DPM_API_CALL_TYPE DpmInit(void);
t_DpmActivityMode         DPM_API_CALL_TYPE DpmGetRequestedActivityMode(t_DpmUserNumber UserNumber);
t_DpmActivityMode         DPM_API_CALL_TYPE DpmGetActualEcuActivityMode(void);
t_DpmChannelActivityMode  DPM_API_CALL_TYPE DpmGetActualChannelActivityMode(void);
t_DpmChannelActivityMode  DPM_API_CALL_TYPE DpmGetMaximumChannelActivityMode(void);
void                      DPM_API_CALL_TYPE DpmTask(void);

void                      DPM_API_CALL_TYPE DpmSystemShutdown(void);

# if !defined(C_ENABLE_DPM_PRODUCTION)

void DPM_API_CALL_TYPE DpmDiagSetLocal(t_DpmUserNumber DpmUserNumber);

t_DpmPointerDiagnosticRecord DPM_API_CALL_TYPE DpmGetPointerDiagnosticRecord(void);
# endif

void DPM_API_CALL_TYPE DpmIndicateActiveDiagnosticSession(t_DpmFlag DiagnosticSessionActive);

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 cDpmUserByteTable[DPM_USER_COUNT];
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 cDpmUserSetMask[DPM_USER_COUNT];
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 cDpmUserClearMask[DPM_USER_COUNT];

extern void DPM_API_CALL_TYPE DpmExternalRequest(t_DpmUserNumber UserNumber);
extern void DPM_API_CALL_TYPE DpmLocalRequest(t_DpmUserNumber UserNumber);
extern void DPM_API_CALL_TYPE DpmSleepRequest(t_DpmUserNumber UserNumber);

# if defined(DPM_ENABLE_USER_NOTIFICATION)
extern void DPM_API_CALL_TYPE DpmModeChangeContainer(t_DpmState target, t_DpmState active);
# endif

/***************************************************************************/
/* callback function prototypes                                            */
/***************************************************************************/
extern t_DpmMaxChModeVariantCode  DPM_API_CALLBACK_TYPE ApplDpmReadMaxChMode(void);

extern void         DPM_API_CALLBACK_TYPE ApplDpmSaveMaxChMode(t_DpmMaxChMode DpmMaxChMode);
extern t_DpmApplRet DPM_API_CALLBACK_TYPE ApplDpmModeChangeSystem(t_DpmState target, t_DpmState active);

extern void DPM_API_CALLBACK_TYPE ApplDpmSystemShutdown(void);

/* ESCAN00025268 */
# if (kDpmNumberOfChannels > 1)
extern t_DpmApplRet DPM_API_CALLBACK_TYPE ApplDpmModeChangeChannelSystem(vuint8 channel, t_DpmState targetState_ch, t_DpmState activeState_ch);
# endif

# if !defined(C_ENABLE_DPM_PRODUCTION)
extern vuint16 DPM_API_CALLBACK_TYPE ApplDpmReadCounterSleepForced(void);
extern vuint16 DPM_API_CALLBACK_TYPE ApplDpmReadCounterNoExternalMode(void);
extern void DPM_API_CALLBACK_TYPE ApplDpmSaveCounterValues(vuint16 DpmDebugCounterValueNoExternalMode, vuint16 DpmDebugCounterValuesSleepForced);
# endif

/* fatal error function to indicate exeptions */
extern void DPM_API_CALLBACK_TYPE ApplDpmFatalError(vuint8 DpmErrorCode);


/*****************************************************************************/
/* diag interface function prototypes                                        */
/*****************************************************************************/ 
void DPM_API_CALL_TYPE DpmDiagExtReq(t_DpmUserNumber userNumber);
void DPM_API_CALL_TYPE DpmDiagSleepReq(t_DpmUserNumber userNumber);

/*****************************************************************************/
/* interrupt enable/restore                                                  */
/*****************************************************************************/
/* a global interupt lock is */
# if defined (CCL_ENABLE_TRCV_PORT_INT) ||\
    !defined (DPM_APPL_GLOBAL_INT_LOCK)
#  define DPM_ENABLE_GLOBAL_INT_LOCK
# endif

# define DpmInterruptDisable()  (CanGlobalInterruptDisable())
# define DpmInterruptRestore()  (CanGlobalInterruptRestore())

# if (kCanNumberOfChannels > 1)
#  define DpmCanInterruptDisable(i)  CanCanInterruptDisable((CanChannelHandle) i )
#  define DpmCanInterruptRestore(i)  CanCanInterruptRestore((CanChannelHandle) i )
# else
#  define DpmCanInterruptDisable()  CanCanInterruptDisable()
#  define DpmCanInterruptRestore()  CanCanInterruptRestore()
# endif

#endif /* V_DPM_H */
