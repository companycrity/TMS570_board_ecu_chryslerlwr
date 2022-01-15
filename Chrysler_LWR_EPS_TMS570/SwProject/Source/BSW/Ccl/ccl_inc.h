/*****************************************************************************
|  File Name: CCL_INC.H 
|
|  Description: Communication Control Layer Header (CORE)
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2000-2012 by Vector Informatik GmbH.      All rights reserved.
|
|               This software is copyright protected and proprietary 
|               to Vector Informatik GmbH. Vector Informatik GmbH 
|               grants to you only those rights as set out in the 
|               license conditions. All other rights remain with 
|               Vector Informatik GmbH.
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------
| Bs           Thomas Balster            Vector Informatik GmbH
| Et           Thomas Ebert              Vector Informatik GmbH 
| Zw           Werner Ziegler            Vector Informatik GmbH
| Dhf          Daniel Hof                Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Ver     Author  Description
| ---------   ----    ------  --------------------------------------------------
| 19.06.02    1.00    Zw      Initial version 
| 2002-12-02  1.01    Pet     add support for psa
| 2002-12-03  1.01    Pet     add support for Micronas CEVF
| 2003-02-04  1.02    Pet     ESCAN00004878: add support for GMLAN (single receive channel)
| 2003-02-06          Pet     ESCAN00004881: add support for NM JUNIOR
| 2003-04-01  1.04    Pet     ESCAN00005345: separation CCL into core files and OEM extension files
| 2003-06-05  1.05    Pet     CCL DLL version change
| 2003-06-16  1.05.01 Pet     bugfix version changed
| 2003-07-25  1.05.02 Pet     optimization for PSA
| 2003-08-11  1.05.03 Pet     new DLL bugfix version
| 2003-08-19  1.05.04 Pet     new DLL version
|                     Pet     ESCAN00006299: check return value of "CanSleep"
|                     Pet     ESCAN00006375: multiple release of network requests
| 2003-09-24  1.06    Et      ESCAN00007184: EMC wake up
|                             ESCAN00007185: network management restriction
|                             ESCAN00007187: pagging support
|                             ESCAN00007189: initialization API
|                             ESCAN00007190: reworking (algorithms and namings)
| 2003-12-28  1.07    Et      ESCAN00007258: debug access to internal states (C_COMP_ANSI_CANOE)
|                             ESCAN00007259: initialisation of "cclComHwState" and "cclComSwState"
|                             ESCAN00007260: start EMC wake up timer at power on (+30 reset)
|                             ESCAN00007261: support EMC wake up for CAN driver API
|                             ESCAN00007262: "C_SINGLE_RECEIVE_BUFFER" and "C_MULTIPLE_RECEIVE_BUFFER"
|                             ESCAN00007263: DLL compatibility defines (< V1.06)
|                             ESCAN00007264: support edge triggered transceiver port interrupt
|                             ESCAN00007265: correct network restriction handling
|                             ESCAN00007266: correct network restriction handling
|                             ESCAN00007267: conditional message reception & internal network request
| 2004-01-17  1.07.01 Et      ESCAN00007277: COSMIC compiler option -pck
| 2004-01-21  1.07.02 Pet     ESCAN00007310: wrong #endif
|                             ESCAN00007311: missing encapsulation of cclCanSleepRepetition
|                             ESCAN00007296: different parameter list by Error Hook function CclFatalError
| 2004-01-23  1.08    Pet     ESCAN00007328: add component define for DPM
|                             ESCAN00007403: dummy assignment  NM_MSG_COND_RX_PARAMETER_NAME#
|                             ESCAN00007404: support MISRA compliance
| 2004-02-02  1.09    Et      ESCAN00007429: incorrect CclComRelFct notification (set network restriction)
|                             ESCAN00007481: gateway component handle
|                             ESCAN00007548: extern declaration debug variables
| 2004-03-01  1.10    Pet     ESCAN00007741: compiler error in CclInitPowerOn
|                     Et      ESCAN00007722: support no external network requests
|                             ESCAN00007763: add include v_inc.h
|                             ESCAN00007773: no cancel of repeated CanSleep by external wake up
| 2004-03-16  1.11    Pet     ESCAN00007907: function CclGetNmState now API function
|                             ESCAN00007615: support of virtual networks (only for single receive channel)
| 2004-06-17  1.12    Pet     ESCAN00008082: EMC Wakeup Time in DPM is lower than 500ms
|                             ESCAN00008379: missing datatype in the prototypes of ApplCclVnDeactivated and ApplCclVnActivated
| 2004-07-02  1.13    Pet     ESCAN00008750: wrong assertion check
| 2004-07-30  1.14    Pet     ESCAN00009037: support multiple configurations
|                     Pet     ESCAN00009074: init value of variable "cclNmState"
|                     Pet     ESCAN00009098: support for GMLAN multichannel
| 2004-09-09  1.15    Pet     ESCAN00009431: add support for VAG NM C
| 2004-09-21  1.16    Pet     ESCAN00009573: change StateOn handling
|                             ESCAN00009192: missing paging define "DRV_API_CALLBACK_TYPE" in function "ApplCanMsgCondReceived"
|                             ESCAN00009623: prevent additional CAN wake up events
| 2004-10-04  1.17    Pet     ESCAN00009634: missing defines kCclNoCanAvailable and kCclCanAvailable
|                             ESCAN00009686: new core version defines
|                             ESCAN00009693: add support for CAN driver macro CanResetWakeup
|                             ESCAN00009740: inconsistent system request/release state
|                             reject ESCAN00009623
| 2004-10-12  1.18    Pet     ESCAN00009851: add support for Fj16lx
|                             ESCAN00009856: administrative service component handle
|                             ESCAN00009857: NM user data component handle
| 2004-11-02  1.19    Pet     ESCAN00010066: encapsulate CCL software state [only GM]
|                             ESCAN00010069: add support for transceiver type NONE
| 2004-11-10  1.20    Pet     ESCAN00010181: Add support for INM-OSEK (Organ Typ 1)
|                             ESCAN00010071: Transition to network state "prepare to sleep" in spite of pending internal network requests
|                             ESCAN00010087: Transition to network state "sleep" while running communication [only DC]
| 2004-12-10  1.21    Pet     ESCAN00010140: Wrong comment for cclNmRestriction[]. [only DC]
|                             ESCAN00009061: CclGetTrcvErrorPortFct contains NULL pointer
|                             ESCAN00010588: change the visibility of the network request field
|                             ESCAN00010613: Define VGEN_ENABLE_CIOA
| 2005-02-17  1.22    Pet     ESCAN00011217: inconsistencies between DPM and CCL state handling [only DC]
|                             ESCAN00011218: wakeup via CAN bus is not possible
| 2005-02-18  1.23.   Bs      ESCAN00011140: delete double defines
|                             ESCAN00011141: delete (CanChannelHandle) cast in channel parameter defines
|                             ESCAN00011142: change define VGEN_ENABLE_CIOA into CCL_ENABLE_EXTENDED_STATEON
|                             ESCAN00011145: add a hint to an OEM specific header
|                             ESCAN00011151: function CclGetNmState() is not needed anymore
|                             ESCAN00011170: some variables and functions are not necessary if assertions are not activated
|                             ESCAN00011187: change name and type of 'CanECUHandle'
|                             ESCAN00011212: change type of "channel" variable
|                     Pet     ESCAN00010421: advance system shutdown handling
|                             ESCAN00011118: NULL should not be used in the component
|                             ESCAN00011273: During restriction missing EMC wake up event
| 2005-03-07  1.24    Pet     ESCAN00011382: Add define for advanced shutdown handling
|                             ESCAN00011401: Add defines CCL_ENABLE_SYSTEM_STARTUP and CCL_ENABLE_SYSTEM_SHUTDOWN
| 2005-03-14  1.25    Pet     ESCAN00011430: Remove not used variable cclEndIndex
|                     Pet     ESCAN00011453: Wrong VN handling
|                     Pet     ESCAN00011500: Non expected wake up
|                     Pet     ESCAN00011503: Non wake up able through bus event
|                     Pet     ESCAN00011508: Wrong wake up reason
| 2005-04-05  1.26    Pet     ESCAN00011709: network restriction handling for multichannel systems
|                     Pet     ESCAN00011723: Add define for CclGetNmState
| 2005-04-11  1.27    Pet     ESCAN00011832: add support for wake up registration
|                             ESCAN00011833: add support for the component FIM
| 2005-04-20  1.28    Pet     ESCAN00011977: Support wake up for conditional wake up message
| 2005-05-13  1.29    Pet     ESCAN00012254: No wake up is possible during active restricion in special cirrumstances.
| 2005-05-23  1.30    Pet     ESCAN00012399: multichannel support for network initialization
| 2005-06-08  1.31    Pet     ESCAN00012515: Missing variable encapsulation
|                             ESCAN00012538: Add support for power fail handling
|                             ESCAN00012544: Lock global interrupt during sleep mode transition
| 2005-06-21  1.32    Pet     ESCAN00012614: Add support for single channel optimized CCL with a multichannel CAN driver
|                             ESCAN00012627: Missing internal standby event notification during power fail
|                             ESCAN00012638: Wrong CanOnline call
| 2005-07-05  1.33    Pet     ESCAN00012760: Review changes
|                             ESCAN00013027: Missing excplicitly variable initialization
|                             ESCAN00013208: Wrong call of CanInit during Bus Off recovery at the end of power fail
| 2005-08-15  1.34    Pet     ESCAN00012342: Wrong IL-NI PowerOn/Reset handling
|                             ESCAN00013241: Unexpected Tx timeout error (Tx observe) on first message after PowerFail
| 2005-08-27  1.35    Et      ESCAN00013331: GAIO compiler: symbol redefinition (variable: cclInit / function: CclInit)
| 2005-09-07  1.36    Pet     ESCAN00013450: adapt CAN driver API for reference implementation 1.20
| 2005-09-12  1.37    Pet     ESCAN00013229: update wake up timer handling
|                             ESCAN00013534: Wrong state change notification
|                             ESCAN00013232: Wrong CAN Driver state check during system shutdown
|                             ESCAN00013538: Reduce interrupt locking time in the CCL task
|                             ESCAN00013609: Macro CclAssert must be external visible
| 2005-11-22  1.37.01 Pet     ESCAN00014294: Compiler error if paging is used and CCL is located in a far page
|                             ESCAN00014380: Support faster wake up
| 2006-01-31  1.37.02 Pet     ESCAN00015144: Change configuration check for transceiver and CAN wake up settings
| 2006-03-20  1.37.03 Pet     ESCAN00015744: CAN channel does not enter sleep mode
| 2006-07-03  1.37.04 Pet     ESCAN00016713: ECU is not able to wake up
| 2007-01-10  1.37.05 Pet     ESCAN00018893: Missing variable cast
| 2007-01-29  1.37.06 Pet     ESCAN00018830: Missing DPM state change notification during NM startup
| 2007-02-12  1.37.07 Pet     ESCAN00019537: Add support for different configured identities
| 2007-05-10  1.37.08 Pet     ESCAN00020295: CAN channel stay alive even if no application network request is pending
| 2007-06-12  1.37.09 Pet     ESCAN00021059: Add support of multiple configurations for older configurations
| 2007-10-15  1.37.10 Pet     ESCAN00022782: Support CAN driver configurations which does not use special banking defines
| 2007-10-16  1.37.11 Pet     ESCAN00022800: support configurations which use only non wake up able NM
|                             ESCAN00022814: Add component error code define for the DC PowerTrain component
|                             ESCAN00022819: Shutdown validation of the CAN driver Online/Offline state
| 2007-10-25  1.37.12  Pet    ESCAN00023157: Add support of muliple configurations
| 2008-01-02  1.37.13  Pet    ESCAN00022973: Added support of transciever TLE6251G
| 2008-01-18  1.37.14  Pet    ESCAN00023715: missing function declarations
|                             ESCAN00023737: compiler warning: meaningless statements deleted in optimize phase
| 2008-04-11  1.37.15  Dhf    ESCAN00026013: Added check for number of channels
| 2008-08-25  1.37.16  Dhf    ESCAN00014084: Support new memory qualifier
| 2008-09-03  1.37.17  Dhf    ESCAN00029646: wrong memory qualifier used
| 2008-09-11  1.37.18  Dhf    ESCAN00029938: added support of multiple nodes with identity manager
| 2008-09-17  1.37.19  Pet    ESCAN00030084: Compiler error because of missing kCclChannelIndex definition
| 2009-03-16  1.37.20  Dhf    ESCAN00032576: No startup to DPM external mode
| 2009-05-07  1.37.21  Dhf    ESCAN00034925: added extended initialisation
|                             ESCAN00034953: removed precompile check
|                             ESCAN00027774: Compiler Warning in case of missing cast
|                             ESCAN00031836: added else-path to avoid misra warning
| 2010-02-11  1.37.22  Dhf    ESCAN00040416: Emc timeout is too long
| 2010-03-30  1.37.23  Dhf    ESCAN00040721: no changes in this file
|                             ESCAN00041956: added component identifier for NM ASR components
| 2012-06-29  1.37.24  Pet    ESCAN00057750: no changes in this file
|****************************************************************************/

/****************************************************************************/
/* one further header (the OEM specific one) is included                    */
/* at the end of this core header file                                      */
/****************************************************************************/

/* check multiple inclusion */
#ifndef CCL_INC_H
#define CCL_INC_H


/***************************************************************************/ 
/* Include files                                                           */ 
/***************************************************************************/ 
/* CCL configuration  */
#include "ccl_cfg.h"
#include "v_cfg.h"



/***************************************************************************/ 
/* Version  (core version)  (abcd: Main version ab Sub Version cd )        */ 
/***************************************************************************/ 
/* ##V_CFG_MANAGEMENT ##CQProject : Ccl__core CQComponent : Implementation */
#define CCL__CORE_VERSION          0x0137
#define CCL__CORE_RELEASE_VERSION  0x24

/***************************************************************************/
/* Version Defines to stay compatiple with older versions                  */
/***************************************************************************/
#define CCL_CORE_VERSION          CCL__CORE_VERSION
#define CCL_CORE_BUGFIX_VERSION   CCL__CORE_RELEASE_VERSION


/***************************************************************************/ 
/* Defines                                                                 */ 
/***************************************************************************/
/* ESCAN00030084 */
#if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#  if(kCclNrOfChannels == 1)
#    ifndef kCclChannelIndex
#      define kCclChannelIndex 0
#    endif
#  endif
#endif

#if defined( CCL_ENABLE_DEBUG)
#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if( kCclNrOfChannels > 1)
#      define CclAssert(p,e)  {if(!(p)){CclFatalError(channel, (e), (vuint16)(__LINE__),kModuleCcl);}}
#    else
#      define CclAssert(p,e)  {if(!(p)){CclFatalError((CanChannelHandle)kCclChannelIndex, (e), (vuint16)(__LINE__),kModuleCcl);}}
#    endif
#  elif (kCclNrOfChannels > 1)
/* non-indexed systems are not supported by the CCL */
#  else
#    define CclAssert(p,e)  {if(!(p)){CclFatalError(0, (e), (vuint16)(__LINE__),kModuleCcl);}}
#  endif
#else
#  define CclAssert(p,e)
#endif

/* defines for Paging-mode                                                  */
#ifndef CCL_API_CALL_TYPE                 /* API-Type */
# define CCL_API_CALL_TYPE
#endif
#ifndef CCL_API_CALLBACK_TYPE             /* Applicationfunction called by DBKOM */
# define CCL_API_CALLBACK_TYPE
#endif
#ifndef CCL_INTERNAL_CALL_TYPE            /* functions called from other vector-layers */
# define CCL_INTERNAL_CALL_TYPE
#endif

/* ESCAN00022782 */
#ifndef DRV_API_CALLBACK_TYPE
#  define DRV_API_CALLBACK_TYPE
#endif

#if( CCL_DLL_VERSION < 0x0106 )
#  define cclNetRequestField   cclIntNetState
#  define kCclNrOfNetworks     kCclNrOfNmNetworks
#  define cclStateCom          cclComSwState

#  define kCclComOn                kCclComSwOn
#  define kCclComOff               kCclComSwOff

#  if defined( CCL_USE_REQUEST_SETCOM_FCT )
#    define CCL_USE_REQUEST_SETINTCOM_FCT CCL_USE_REQUEST_SETCOM_FCT
#    define CCL_USE_REQUEST_SETEXTCOM_FCT CCL_USE_REQUEST_SETCOM_FCT
#  endif

#  if(kCclNrOfChannels > 1)
#    define CclInitTransFctTbl    CclInitTrcvFctTbl
#    define CclWakeUpTransFctTbl  CclWakeUpTrcvFctTbl
#    define CclSleepTransFctTbl   CclSleepTrcvFctTbl
#    define CclComRelFctTbl       CclClearComReqFctTbl
#    define CclExtCanComReqFctTbl CclSetComReqFctTbl
#    define CclIntComReqFctTbl    CclSetComReqFctTbl
#  else
#    define CclInitTransFct      CclInitTrcvFct
#    define CclWakeUpTransFct    CclWakeUpTrcvFct
#    define CclSleepTransFct     CclSleepTrcvFct
#    define CclComRelFct         CclClearComReqFct
#    define CclExtCanComReqFct   CclSetComReqFct
#    define CclIntComReqFct      CclSetComReqFct
#  endif

#endif

/* ESCAN00011723 */
#define CclGetNmState              CclGetChannelState

#  define kModuleCanDrv            kComponentCanDrv
#  define kModuleLinDrv            kComponentLinDrv
#  define kModuleIl                kComponentIl
#  define kModuleDbk               kComponentDbk
#  define kModuleMm                kComponentMm
#  define kModuleTp                kComponentTp
#  define kModuleNm                kComponentNm
#  define kModuleNmPt              kComponentNmPt
#  define kModuleSm                kComponentSm
#  define kModuleNmVagC            kComponentNmVagC
#  define kModuleDiagx             kComponentDiagx
#  define kModuleCANdesc           kComponentCANdesc
#  define kModuleCcl               kComponentCcl


/* channel parameter and index replacement */ 
#if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#  if(kCclNrOfChannels > 1)
#    define CCL_CHANNEL_CCLPARA_ONLY       channel
#    define CCL_CHANNEL_CCLPARA_FIRST      channel,
#    define CCL_CHANNEL_CCLTYPE_ONLY       CanChannelHandle channel
#    define CCL_CHANNEL_CCLTYPE_FIRST      CanChannelHandle channel,
#    define CCL_CHANNEL_CCLINDEX           channel
#    define CCL_CHANNEL_CANPARA_ONLY       channel
#  else
#    define CCL_CHANNEL_CCLPARA_ONLY
#    define CCL_CHANNEL_CCLPARA_FIRST
#    define CCL_CHANNEL_CCLTYPE_ONLY       void
#    define CCL_CHANNEL_CCLTYPE_FIRST
#    define CCL_CHANNEL_CCLINDEX           0
#    define CCL_CHANNEL_CANPARA_ONLY       (CanChannelHandle)kCclChannelIndex
#  endif
#else
#  define CCL_CHANNEL_CCLPARA_ONLY
#  define CCL_CHANNEL_CCLPARA_FIRST
#  define CCL_CHANNEL_CCLTYPE_ONLY       void
#  define CCL_CHANNEL_CCLTYPE_FIRST
#  define CCL_CHANNEL_CCLINDEX           0
#  define CCL_CHANNEL_CANPARA_ONLY
#endif

/* network parameter and index replacement */
#if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if(kCclNrOfChannels > 1)
#      define CCL_NET_CCLPARA_ONLY         channel
#      define CCL_NET_CCLPARA_FIRST        channel,
#      define CCL_NET_CCLTYPE_ONLY         CanChannelHandle channel
#      define CCL_NET_CCLTYPE_FIRST        CanChannelHandle channel,
#      define CCL_NET_CCLINDEX             channel
#    else
#      define CCL_NET_CCLPARA_ONLY
#      define CCL_NET_CCLPARA_FIRST
#      define CCL_NET_CCLTYPE_ONLY           void
#      define CCL_NET_CCLTYPE_FIRST
#      define CCL_NET_CCLINDEX               0
#    endif
#else
#    define CCL_NET_CCLPARA_ONLY
#    define CCL_NET_CCLPARA_FIRST
#    define CCL_NET_CCLTYPE_ONLY           void
#    define CCL_NET_CCLTYPE_FIRST
#    define CCL_NET_CCLINDEX               0
#endif

/* ECU handle replacement */
#if defined(CCL_ENABLE_MULTIPLE_NODES) 
#  if defined(CCL_ENABLE_CANBEDDED_HANDLING)
#  define CCL_ECUS_NODESTYPE_ONLY        cclECUHandle  CanEcuNr
#  define CCL_ECUS_NODESTYPE_FIRST       cclECUHandle  CanEcuNr,
#  define CCL_ECUS_NODESPARA_ONLY        (vuint8)CanEcuNr
#  else
#    define CCL_ECUS_NODESTYPE_ONLY        void
#    define CCL_ECUS_NODESPARA_ONLY
#  endif
#else
#  if defined(CCL_ENABLE_MULTIPLE_CONFIG) || defined(CCL_ENABLE_MULTIPLE_NODES_IDM)
#    if defined(CCL_ENABLE_CANBEDDED_HANDLING)
#     define CCL_ECUS_NODESTYPE_ONLY        vuint8  IdentityNr
#     define CCL_ECUS_NODESTYPE_FIRST       vuint8  IdentityNr
#     define CCL_ECUS_NODESPARA_ONLY        IdentityNr
#    else
#      define CCL_ECUS_NODESTYPE_ONLY        void
#      define CCL_ECUS_NODESTYPE_FIRST
#      define CCL_ECUS_NODESPARA_ONLY
#    endif
#  else
#    define CCL_ECUS_NODESTYPE_ONLY        void
#    define CCL_ECUS_NODESTYPE_FIRST
#    define CCL_ECUS_NODESPARA_ONLY
#  endif
#endif

/* multiple configuration replacement */
#  define CCL_SET_MULTIPLE_CFG_HANDLE(i)

#if defined( CCL_ENABLE_EMC_WAKEUP )
#  if defined (C_ENABLE_COND_RECEIVE_FCT)
#    if defined( C_SINGLE_RECEIVE_BUFFER )
#      define NM_MSG_COND_RX_PARAMETER_TYPE  void
#      define NM_MSG_COND_RX_PARAMETER_NAME
#      define NM_MSG_COND_RX_CHANNEL
#      if(kCclNrOfChannels > 1)
#        error "CCL doesn't support 'C_SINGLE_RECEIVE_BUFFER' in mulitple channel systems"
#      endif
#    endif

#    if defined( C_MULTIPLE_RECEIVE_BUFFER )
#      define NM_MSG_COND_RX_PARAMETER_TYPE  void
#      define NM_MSG_COND_RX_PARAMETER_NAME
#      define NM_MSG_COND_RX_CHANNEL
#      if(kCclNrOfChannels > 1)
#        error "CCL doesn't support 'C_MULTIPLE_RECEIVE_BUFFER' in mulitple channel systems"
#      endif
#    endif

#    if defined( C_MULTIPLE_RECEIVE_CHANNEL )  || \
        defined( C_SINGLE_RECEIVE_CHANNEL )
#      define NM_MSG_COND_RX_PARAMETER_TYPE  CanRxInfoStructPtr
#      define NM_MSG_COND_RX_PARAMETER_NAME  rxStruct
#      define NM_MSG_COND_RX_CHANNEL         (rxStruct->Channel)
#    endif
#  endif
#endif

#if defined(CCL_ENABLE_ADV_SHUTDOWN)
/* shutdown check */
#  if defined(C_ENABLE_EXTENDED_STATUS) && defined(C_ENABLE_SLEEP_WAKEUP)
#    define kCclCanDrvCheckMask            (kCanTxOff | kCanHwIsSleep)
#  else
#    define kCclCanDrvCheckMask            kCanTxOff
#  endif
#endif

/* CCL states (active, go to sleep and sleep) */
#define kCclNmStateSleep                0x00    /* network management state: sleep */
#define kCclNmStateGoToSleep            0x01    /* network management state: go to sleep */
#define kCclNmStateActive               0x02    /* network management state: active */
#define kCclNmPowerFail                 0x03    /* power fail state active */

#if defined(CCL_ENABLE_NET_STATE_RESTRICTION)
#  define kCclNmRestrictionOn           0x00    /* network management restriction: on */
#  define kCclNmRestrictionOff          0x01    /* network management restriction: off */
#endif

#define kCclComHwDisabled               0x00    /* HW communication state: disabled */
#define kCclComHwEnabled                0x01    /* HW communication state: enabled */

#define kCclComSwOff                    0x00    /* SW communication state: off */
#define kCclComSwOn                     0x01    /* SW communication state: on */

#if defined( CCL_ENABLE_EXTENDED_STATEON )
#  define kCclCanHwOff                    0x00    /* CAN HW is state: off */
#  define kCclCanHwOn                     0x01    /* CAN HW is state: on */
#endif

#define kCclBusOn                        0x00
#define kCclBusOff                       0x01

#define kCclNoCanAvailable                0x00    /* CAN HW is not stable */
#define kCclCanAvailable                  0x01    /* CAN HW is stable */

#define kCclTrcvWakeIntPending    0x00
#define kCclTrcvWakeIntNoPending  0x01

#define CCL_NO_CHANNEL_INFO_AVAILABLE   0xFF

#define kCclNoErrPort                   0xFF
#define kCclTrcvErrPinActive            0x00

#define kCclNoRepeatCanSleep            0x00     /* no repeat of the function CanSleep */
#define kCclRepeatCanSleep              0x01     /* repeat the CanSleep function */

#define kCclSystemSpecificInit          0x00
#define kCclChannelSpecificInit         0x01

#define kCclNoNetRequest                0x00
#define kCclNetRequest                  0x01

#define kCclNoWakeUpAble                0x00


#if defined( CCL_ENABLE_EMC_WAKEUP )
/* ESCAN00027774: added vuint8-casts: */
#  define kCclEmcWakeUpTimerStopped     (vuint8)0x00     /* EMC wake up timer stopped */
#  define kCclEmcWakeUpTimerActive      (vuint8)0x00     /* EMC wake up timer is active */
#  define kCclEmcWakeUpTimerDeactive    (vuint8)0xFF     /* EMC wake up timer is deactive */
#  define kCclEmcWakeUpTimerRunning     (vuint8)0xFF     /* EMC wake up timer is running */
#  define kCclEmcWakeUpTimerExpired     (vuint8)0x00     /* EMC wake up timer is expired */
#endif

#if defined(CCL_ENABLE_TRCV_PORT_INT)
#  define kCclDisableWakeUpInt          0x00     /* transceiver port interrupt is disabled */
#  define kCclEnableWakeUpInt           0x00     /* transceiver port interrupt is enabled */
#endif

#define kCclTrcvStateChangePerformed       0x01
#define kCclTrcvStateChangeNotPerformed    0x00






#define kCclOk                          0x01
#define kCclFailed                      0x00

/***************************************************************************/ 
/* Default switches                                                        */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* Memory qualifier                                                        */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* return values                                                           */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* error codes                                                             */ 
/***************************************************************************/ 
/* DRV component codes */ 
#define kComponentCanDrv                   0x01
#define kComponentLinDrv                   0x02

/* IL component codes */
#define kComponentIl                       0x10
#define kComponentDbk                      0x11
#define kComponentMm                       0x12
#define kComponentDcPt                     0x13

/* NM component codes */
#define kComponentNm                       0x20
#define kComponentNmPt                     0x21
#define kComponentSm                       0x22
#define kComponentNmVagC                   0x23
#define kComponentNmUData                  0x24
#define kComponentNmHigh                   0x25
#define kComponentNmBasic                  0x26
#define kComponentNmCbdWrp                 0x28
#define kComponentNmAsrIf                  0x29
#define kComponentNmAsrCan                 0x2a

/* TP component codes */
#define kComponentTp                       0x30

/* DIAG component codes */
#define kComponentDiagx                    0x40
#define kComponentCANdesc                  0x41

/* CCL component codes */
#define kComponentCcl                      0x50

/* DPM component code */
#define kComponentDpm                      0x60

/* GW component code */
#define kComponentSigGW                    0x70
#define kComponentAs                       0x71


/* CCL error codes */
#define kAssertCANandTRCVINT            0x00
#define kAssertNotSleepAndTRCVINTactive 0x01

#define kIllegalWakeUpInterrupt         0x03
#define kWrongReturnValue               0x04

#define kExtAndIntWakeUp                0x05

#define kCclErrEMCTimerHdlgFailed       0x06

#define kCclErrWakeFailed               0x07

#define kCclErrWrongCclState            0x0A

#if defined(CCL_ENABLE_ADV_SHUTDOWN)
/* CclSystemShutdown consistency error codes */
#  define kCclNmInSleep                   0x01
#  define kCclNmNotInSleep                0x02
#endif


/***************************************************************************/ 
/* macros                                                                  */ 
/***************************************************************************/ 



/***************************************************************************/ 
/* compatibility defines                                                   */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* data types                                                              */ 
/***************************************************************************/
#if defined(CCL_ENABLE_MULTIPLE_NODES)
typedef vuint8 cclECUHandle; /* ECU handle */  /* ESCAN00011187 */
#endif 


#if defined(CCL_ENABLE_EXTENDED_INITIALIZATION)
typedef enum
{
  kCclInitSleep,
  kCclInitNormal,
  kCclInitEmc
}tCclInitParaType;

typedef struct CclInitParaList
{
  tCclInitParaType cclInit_0;
#if (kCclNrOfChannels > 1)
  tCclInitParaType cclInit_1;
#endif
#if (kCclNrOfChannels > 2)
  tCclInitParaType cclInit_2;
#endif
#if (kCclNrOfChannels > 3)
  tCclInitParaType cclInit_3;
#endif
#if (kCclNrOfChannels > 4)
  tCclInitParaType cclInit_4;
#endif
#if (kCclNrOfChannels > 5)
  tCclInitParaType cclInit_5;
#endif
#if (kCclNrOfChannels > 6)
  tCclInitParaType cclInit_6;
#endif
#if (kCclNrOfChannels > 7)
  tCclInitParaType cclInit_7;
#endif
}tCclInitParaListType;
#endif



/***************************************************************************/ 
/* internal function prototypes                                            */ 
/***************************************************************************/ 
#if(defined( CCL_ENABLE_EXTERNAL_REQUEST ) ||\
    defined( CCL_ENABLE_INTERNAL_REQUEST ))
extern void CCL_API_CALL_TYPE CclTask(void);
#endif

#if defined(CCL_ENABLE_ERROR_HOOK)
extern void CCL_API_CALL_TYPE CclFatalError(CanChannelHandle ChannelNumber, vuint16 ErrorCode, vuint16 ErrorLine, vuint8 ComponentID);
#endif

/***************************************************************************/ 
/* external function prototypes                                            */
/***************************************************************************/
#if defined(CCL_ENABLE_EXTENDED_INITIALIZATION)
extern void CCL_API_CALL_TYPE CclInitPowerOn(CCL_ECUS_NODESTYPE_FIRST const tCclInitParaListType* cclInitPointer);
extern void CCL_API_CALL_TYPE CclInit(CCL_CHANNEL_CCLTYPE_FIRST tCclInitParaType cclInitValue);
#else
extern void CCL_API_CALL_TYPE CclInitPowerOn(CCL_ECUS_NODESTYPE_ONLY);
extern void CCL_API_CALL_TYPE CclInit(CCL_CHANNEL_CCLTYPE_ONLY);
#endif
#if defined( CCL_ENABLE_SYSTEM_STARTUP )
extern void CCL_API_CALL_TYPE CclSystemStartup(void);
#endif

#if defined(CCL_ENABLE_SYSTEM_SHUTDOWN)
#  if defined(CCL_ENABLE_ADV_SHUTDOWN)
extern vuint8 CCL_API_CALL_TYPE CclSystemShutdown(void);
#  else
extern void CCL_API_CALL_TYPE CclSystemShutdown(void);
#  endif
#endif

#if defined( CCL_ENABLE_INTERNAL_REQUEST )
#  if( CCL_DLL_VERSION < 0x0106 )
extern void CCL_API_CALL_TYPE CclSetNetRequest(CCL_CHANNEL_CCLTYPE_FIRST vuint8 network, vuint8 logNetwork);
extern void CCL_API_CALL_TYPE CclRelNetRequest(CCL_CHANNEL_CCLTYPE_FIRST vuint8 network, vuint8 logNetwork);
#  else
extern void CCL_API_CALL_TYPE CclRequestNetwork(CCL_CHANNEL_CCLTYPE_FIRST vuint8 network,vuint8 logNetwork, vuint8 netOffset, vuint8 netMask);
extern void CCL_API_CALL_TYPE CclReleaseNetwork(CCL_CHANNEL_CCLTYPE_FIRST vuint8 network, vuint8 logNetwork, vuint8 netOffset, vuint8 netMask);
#  endif
#  if defined( CCL_ENABLE_NET_STATE_RESTRICTION )
extern void CCL_API_CALL_TYPE CclSetNetworkRestriction(CCL_CHANNEL_CCLTYPE_ONLY);
extern void CCL_API_CALL_TYPE CclClearNetworkRestriction(CCL_CHANNEL_CCLTYPE_ONLY);
#  endif
#endif

extern void CCL_API_CALL_TYPE CclEnableCommunication(CCL_CHANNEL_CCLTYPE_ONLY);
extern void CCL_API_CALL_TYPE CclDisableCommunication(CCL_CHANNEL_CCLTYPE_ONLY);

#if defined(CCL_ENABLE_TRCV_PORT_INT)
#  if defined(CCL_ENABLE_EXTERNAL_REQUEST)
extern void CclCanWakeUpInt(CCL_CHANNEL_CCLTYPE_ONLY);
#  endif
#endif

#if defined( CCL_ENABLE_ERROR_PIN )
extern vuint8 CCL_API_CALL_TYPE CclGetErrorPort(CCL_CHANNEL_CCLTYPE_ONLY);
#endif

extern void CclCanNormal(CCL_CHANNEL_CCLTYPE_ONLY);
extern void CclCanStandby(CCL_CHANNEL_CCLTYPE_ONLY);
extern vuint8 CCL_API_CALLBACK_TYPE ApplCclCanStandby(CCL_CHANNEL_CCLTYPE_FIRST vuint8 sleepResult);

#if defined(CCL_ENABLE_ERROR_HOOK)
extern void CCL_API_CALLBACK_TYPE ApplCclFatalError(void);
#endif


#if defined(INM_TYPE_PSA)
extern void ApplCclSmStatusIndication(vuint8 state);
#endif


extern vuint8 CCL_API_CALL_TYPE CclGetChannelState(CCL_CHANNEL_CCLTYPE_ONLY);


#if defined (CCL_ENABLE_TRCV_TYPE_TLE6251G) /* ESCAN00022973 */
extern vuint8 CclSetTrcvRxOnlyMode(CCL_CHANNEL_CCLTYPE_ONLY);
extern vuint8 CclLeaveTrcvRxOnlyMode(CCL_CHANNEL_CCLTYPE_ONLY);
#endif

/***************************************************************************/ 
/* External Declarations                                                   */ 
/***************************************************************************/ 

#if defined( CCL_ENABLE_ERROR_HOOK)
V_MEMRAM0 extern V_MEMRAM1 vuint8 V_MEMRAM2 cclChannelNumber;
V_MEMRAM0 extern V_MEMRAM1 vuint16 V_MEMRAM2 cclErrorCode;
V_MEMRAM0 extern V_MEMRAM1 vuint16 V_MEMRAM2 cclErrorLine;
V_MEMRAM0 extern V_MEMRAM1 vuint16 V_MEMRAM2 cclComponentID;
#endif



#if defined( CCL_ENABLE_SW_COM_STATE )
V_MEMRAM0 extern V_MEMRAM1 vuint8 V_MEMRAM2 cclComSwState[kCclNrOfChannels];
#endif

#if defined( CCL_ENABLE_EXTENDED_STATEON )
V_MEMRAM0 extern volatile V_MEMRAM1 vuint8 V_MEMRAM2 cclStateOn[kCclNrOfChannels];
#endif

V_MEMRAM0 extern volatile V_MEMRAM1 vuint8 V_MEMRAM2 cclIntNetState[kCclNetReqTableSize];


V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kCclMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kCclSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kCclBugFixVersion;

/***************************************************************************/ 
/* Callback functions                                                      */ 
/***************************************************************************/ 



/***************************************************************************/ 
/* OEM specific                                                            */ 
/***************************************************************************/ 

/*****************************************************************************
| Project Name: CCL Communication Control Layer
| File Name: 
|
|  Description: CCL OEM for DC
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2000-2012 by Vector Informatik GmbH.      All rights reserved.
|
|               This software is copyright protected and proprietary 
|               to Vector Informatik GmbH. Vector Informatik GmbH 
|               grants to you only those rights as set out in the 
|               license conditions. All other rights remain with 
|               Vector Informatik GmbH.
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------
| Bs           Thomas Balster            Vector Informatik GmbH
| Et           Thomas Ebert              Vector Informatik GmbH
| Pet          Thomas Petrus             Vector Informatik GmbH
| Dhf          Daniel Hof                Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Ver      Author  Description
| ---------   ----     ------  --------------------------------------------------
| 2003-03-17  1.00.00  Pet     intitial version
| 2003-06-04  1.00.01  Pet     
| 2003-07.18  1.05     Pet     version changes
| 2003-08-11  1.05.01  Pet     ESCAN00006332: support of single channel OSEK NM 
| 2003-11-03  1.05.02  Pet     ESCAN00006932: add support for NM Basic
| 2003-09-24  1.06     Et      ESCAN00007184: EMC wake up 
| 2003-12-28  1.07     Et      ESCAN00007279: rename "ApplNmBusSleep" to "ApplNmCanBusSleep"
| 2004-01-16  1.08     Et      change core version to V1.07.01
| 2004-01-23  1.09     Pet     ESCAN00007402: correct NM parameter defines
|                      Pet     change core version to V1.08.00
| 2004-02-02  1.10     Et      change core version to V1.09.00
| 2004-02-20  1.11     Pet     ESCAN00007659: change kCclBugfixVersion to kCclBugFixVersion
| 2004-03-01  1.12     Pet     change core version to V1.10.00
| 2004-06-17  1.13.00  Pet     change core version to V1.12.00
| 2004-07-30  1.14.00  Pet     change core version to V1.14.00
| 2004-09-22  1.15.00  Pet     change core version to V1.16.00
|                              ESCAN00009206: missing wake up notification for synchron NM channel
| 2004-10-04  1.16     Pet     change core version to V1.17.00
|                              ESCAN00009687: new DC OEM version bugfix define
| 2004-10-12  1.17     Pet     change core version to V1.18.00
| 2004-10-13  1.18     Pet     ESCAN00009863: DPM network restriction failed 
| 2004-12-13  1.19     Pet     change core version to V1.21.00
| 2005-02-17  1.20     Pet     change core version to V1.22.00
| 2005-02-18  1.21     Bs      change core version to V1.23.00
| 2005-03-03  1.22     Pet     ESCAN00011353: Missing multiple node handling
|                              ESCAN00011355: Wrong typed define
| 2005-03-17  1.23     Pet     change core version to V1.25.00
| 2005-04-05  1.24     Pet     change core version to V1.26.00
| 2005-04-21  1.25     Pet     ESCAN00011983: Add support for NM Basic
|                              change core version to V1.28.00
|                              ESCAN00012036: Handling for single optimized channel is missing
| 2005-04-27  1.26     Pet     ESCAN00012053: Add configuration switches
| 2005-04-27  1.27     Pet     ESCAN00012060: Add support for NM Basic in indexed version
| 2005-05-13  1.28     Pet     ESCAN00012254: No wake up is possible during active restricion in special cirrumstances.
|                              change core version to V1.29.00
| 2005-06-22  1.29     Pet     change core version to V1.32.00
| 2005-09-13  1.30     Pet     change core version to V1.37.00
| 2005-11-22  1.30.01  Pet     change core version to V1.37.01
| 2006-01-31  1.30.02  Pet     change core version to V1.37.02
| 2006-03-20  1.30.03  Pet     change core version to V1.37.03
| 2006-06-07  1.30.04  Pet     ESCAN00015685: Wrong NM channel is used
| 2006-07-03  1.30.05  Pet     change core version to V1.37.04
| 2007-01-10  1.30.06  Pet     change core version to V1.37.05
| 2007-01-29  1.30.07  Pet     change core version to V1.37.06
| 2007-02-12  1.30.08  Pet     change core version to V1.37.07
| 2007-05-10  1.30.09  Pet     change core version to V1.37.08
| 2007-05-23  1.30.10  Pet     ESCAN00020863: Missing retrun value
| 2007-06-12  1.30.11  Pet     change core version to V1.37.09
| 2007-10-15  1.30.12  Pet     change core version to V1.37.10
| 2007-10-16  1.30.13  Pet     change core version to V1.37.11
|                              ESCAN00022815: Add support for DC Powertrain
| 2007-10-25  1.30.14  Pet     change core version to 1.37.12
| 2008-01-02  1.30.15  Pet     change core version to V1.37.13
| 2008-01-18  1.30.16  Pet     change core version to V1.37.14
| 2008-04-11  1.30.17  Dhf     change core version to V1.37.15
| 2008-08-25  1.30.18  Dhf     change core version to V1.37.16
|                              ESCAN00029459: update CCL to new memory qualifier
| 2008-09-03  1.30.19  Dhf     change core version to V1.37.17
| 2008-09-11  1.30.20  Dhf     change core version to V1.37.18
| 2008-09-17  1.30.21  Pet     change core version to V1.37.19
| 2009-03-16  1.30.22  Dhf     change core version to V1.37.20
| 2009-05-07  1.30.23  Dhf     change core version to V1.37.21
| 2010-01-19  1.30.24  Dhf     ESCAN00039955: no changes here
| 2010-02-11  1.30.25  Dhf     change core version to V1.37.22
| 2010-03-30  1.30.26  Dhf     ESCAN00041427: added support of NM ASR
|                              ESCAN00035214: no changes here
|                              change core version to V1.37.23
| 2010-09-09  1.30.27  Dhf     ESCAN00045205: added error directive that Ccl_Dc does not work without DPM
| 2012-06-29  1.30.28  Pet     change core version to V1.37.24
|****************************************************************************/


/***************************************************************************/ 
/* Version defines                                                       */ 
/***************************************************************************/ 
/* ##V_CFG_MANAGEMENT ##CQProject : Ccl_Dc CQComponent : Implementation */
#define CCL_DC_VERSION            0x0130
#define CCL_DC_RELEASE_VERSION    0x28

/***************************************************************************/
/* Version Defines to stay compatiple with older versions                  */
/***************************************************************************/
#define CCL_DC_BUGFIX_VERSION     CCL_DC_RELEASE_VERSION


/***************************************************************************/ 
/* macros                                                                  */ 
/***************************************************************************/



#endif /* ifndef CCL_INC_H */
/************************** end of file ***************************************/ 
/************   Organi, Version 2.1.16 Vector-Informatik GmbH  ************/
