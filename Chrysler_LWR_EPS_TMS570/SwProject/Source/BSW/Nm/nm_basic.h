
/*****************************************************************************
| Project Name: Node-Management Basic
|    File Name: nm_basic.h
|
|  Description: implementation of node management for CAN Class C ECUs
|
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2003 - 2012 by Vector Informatik GmbH.    All rights reserved.
|
| COPYRIGHT NOTE / Urheberrechtlicher Vermerk
| 
|
| This software is copyright protected and proprietary 
| to Vector Informatik GmbH. Vector Informatik GmbH 
| grants to you only those rights as set out in the 
| license conditions. All other rights remain with 
| Vector Informatik GmbH.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------
| Bs           Thomas Balster            Vector Informatik GmbH
| Et           Thomas Ebert              Vector Informatik GmbH
| Pet          Thomas Petrus             Vector Informatik GmbH
| Dhf          Daniel Hof                Vector Informatik GmbH
| vismpf       Marco Pfalzgraf           Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date         Ver   Author    Description
| ----------   ---   -------   -----------------------------------------------
| 2003-10-31   1.0   Et,Pet    creation
| 2004-09-06   1.01  Bs        copyright paragraph changed into english version
|                              ESCAN00009376: adapt the names of the constants which store the version numbers
|                              ESCAN00009705: add callback functions for transceiver handling
| 2004-10-13   1.02  Bs        ESCAN00009878: Naming Conventions: change version defines to serve the Vector naming rules
| 2005-04-05   1.03  Bs        ESCAN00011712: add the new BusOff recovery algorithm 'extended'
|                              ESCAN00011728: NM start and stop handling must be configurable
|                              ESCAN00011785: add assertions for runtime checks
|                              ESCAN00011786: add a 'get Net state' function
|                              ESCAN00011787: add const pragma to support IAR linker
| 2005-04-21   1.04  Bs        ESCAN00011990: change memory qualifier of version number constants
|                              ESCAN00011994: change datatype of configuration fields for multi channel support
|                              ESCAN00012062: standardization of NMbasic defines
|                              ESCAN00012063: add support of indexed and indirected NM channels for use in multi channel systems
| 2005-07-06   1.05  Bs        ESCAN00012094: just check the indirection switch instead in combination with indexed NM
|                              ESCAN00012095: add interface to AsrNm
|                              ESCAN00012490: include of configuration header file added
|                              ESCAN00012670: two compiler switches corrected
|                              ESCAN00012853: Add return value to application callback function 
|                                             'ApplNmBasicSwitchTransceiverOff()'
| 2005-07-14   1.06  Bs        ESCAN00012906: Delete the define 'kNmBasicErrStateNotRunInTxConf'
| 2005-07-25   1.07  Bs        ESCAN00013016: change automatic version number detection
| 2006-02-16   1.08  Bs        ESCAN00015623: Assertion-Defines 'kNmBasicErrStateNotOkInStart' and 
|                                             'kNmBasicErrStateNotOkInStop' not used anymore
| 2006-03-14   1.09  Pet       ESCAN00015663: initialization of multi NM-channel systems corrected for no channel indirection
| 2006-04-26   1.10  Bs        Assertion defines reworked
| 2006-06-08   1.11  Bs        changes just in source file
| 2006-08-03   1.12  Dhf       changes just in source file
| 2006-10-06   1.13  Dhf       ESCAN00017908: Adaption of Nm_PwrTrainBasic to 
|                              support the BusOff algorithm 'time supervised'
| 2007-01-24   1.14  Dhf       ESCAN00012093: changes just in source file
|                              ESCAN00012097: add assertions to check the generated tabels during initialization
|                              ESCAN00018548: changes just in source file
|                              ESCAN00018971: Nm Basic uses incorrect preprocessor switch: VGEN_ENABLE_NM_ASR_GENERIC replaced by VGEN_ENABLE_NM_ASR_CAN
|                              ESCAN00018298: changes just in source file
|                              ESCAN00019119: added BusOff additions and Tx-Observation-Handling
|                              ESCAN00019593: changes just in source file
| 2008-11-10   1.15  Dhf       ESCAN00023008: changes in source file only
|                              ESCAN00025822: changes in source file only
|                              ESCAN00030715: changes in source file only
|                              ESCAN00031037: changes in source file only
|                              ESCAN00031155: Adapt NM Basic to support QNX context switch
|                              ESCAN00031157: added external CanOnline/Offline handling
|                              ESCAN00031403: changes in source file only
| 2009-02-04   1.15.01 Dhf     ESCAN00032403: changes in source file only
| 2009-10-19   1.15.02 Dhf     ESCAN00034728: changes in source file only
|                              ESCAN00038780: changes in source file only
| 2010-08-18   1.15.03 Dhf     ESCAN00044450: changes in source file only
| 2011-11-23   1.15.04 vismpf  ESCAN00051839: changes in source file only
| 2012-10-08   1.15.05 vismpf  ESCAN00061225: corrected encapsulation of bNmBasicStateRequest and bNmBasicBusOffRepaired
|****************************************************************************/

#ifndef NMBASIC_IMPL_H
#define NMBASIC_IMPL_H

#include "nmb_cfg.h"


/***************************************************************************
* defines
****************************************************************************/
/* node management version */
/* ##V_CFG_MANAGEMENT ##CQProject : Nm_PwrTrainBasic CQComponent : Implementation */
#define NM_PWRTRAINBASIC_VERSION 0x0115
#define NM_PWRTRAINBASIC_RELEASE_VERSION 0x05

#define NM_TYPE_NMBASIC

/* NM states */
#define NMBASIC_STATE_POWER_OFF      0x00
#define NMBASIC_STATE_TX_ERROR       0x01 /* ESCAN00019119 */
#define NMBASIC_STATE_STOP           0x02
#define NMBASIC_STATE_RUN            0x03
#define NMBASIC_STATE_BUSOFF         0x04

/* different handling of channel parameter in prototypes and funcion calls */
/* used for NM and CAN Driver functions */
#if defined ( NMBASIC_ENABLE_INDEXED_NM )
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
#  define NMBASIC_CHANNEL_NMTYPE_ONLY     CanChannelHandle channel
#  define NMBASIC_CHANNEL_NMTYPE_FIRST    CanChannelHandle channel,
#  define NMBASIC_CHANNEL_NMPARA_ONLY     channel
#  define NMBASIC_CHANNEL_NMPARA_FIRST    channel,

#  if defined ( NMBASIC_ENABLE_CHANNEL_INDIRECTION )
#   define NMBASIC_CHANNEL_CANTYPE_ONLY  CanChannelHandle channel
#   define NMBASIC_CHANNEL_CANTYPE_FIRST CanChannelHandle channel,
#   define NMBASIC_CHANNEL_CANPARA_ONLY  NmBasicNmToCanIndirection[channel]
#   define NMBASIC_CHANNEL_CANPARA_FIRST NmBasicNmToCanIndirection[channel],
#  else
#   define NMBASIC_CHANNEL_CANTYPE_ONLY  NMBASIC_CHANNEL_NMTYPE_ONLY
#   define NMBASIC_CHANNEL_CANTYPE_FIRST NMBASIC_CHANNEL_NMTYPE_FIRST
#   define NMBASIC_CHANNEL_CANPARA_ONLY  NMBASIC_CHANNEL_NMPARA_ONLY
#   define NMBASIC_CHANNEL_CANPARA_FIRST NMBASIC_CHANNEL_NMPARA_FIRST
#  endif

#  define NMBASIC_CHANNEL_APPLTYPE_ONLY   NMBASIC_CHANNEL_NMTYPE_ONLY
#  define NMBASIC_CHANNEL_APPLTYPE_FIRST  NMBASIC_CHANNEL_NMTYPE_FIRST
#  define NMBASIC_CHANNEL_APPLPARA_ONLY   NMBASIC_CHANNEL_CANPARA_ONLY
#  define NMBASIC_CHANNEL_APPLPARA_FIRST  NMBASIC_CHANNEL_CANPARA_FIRST
# else
#  error "Configuration error in NMBASIC: NM indexed on driver without C_MULTIPLE_RECEIVE_CHANNEL not possible!"
# endif
#else  /* NMBASIC_ENABLE_INDEXED_NM */
# define NMBASIC_CHANNEL_NMTYPE_ONLY         void
# define NMBASIC_CHANNEL_NMTYPE_FIRST
# define NMBASIC_CHANNEL_NMPARA_ONLY    
# define NMBASIC_CHANNEL_NMPARA_FIRST

# if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
#  define NMBASIC_CHANNEL_CANTYPE_ONLY      CanChannelHandle channel
#  define NMBASIC_CHANNEL_CANTYPE_FIRST     CanChannelHandle channel,

#  if defined ( NMBASIC_CAN_CHANNEL )
#   define NMBASIC_CHANNEL_CANPARA_ONLY    NMBASIC_CAN_CHANNEL
#   define NMBASIC_CHANNEL_CANPARA_FIRST   NMBASIC_CAN_CHANNEL,
#  else
#   if ( cNmBasicNrOfChannels > 1 )
#    error "Configuration error in NMBASIC: NM non indexed on more than one channels with C_MULTIPLE_RECEIVE_CHANNEL not possible!"
#   else
#    define NMBASIC_CHANNEL_CANPARA_ONLY  0
#    define NMBASIC_CHANNEL_CANPARA_FIRST 0,
#   endif
#  endif
# else
#  define NMBASIC_CHANNEL_CANTYPE_ONLY      NMBASIC_CHANNEL_NMTYPE_ONLY
#  define NMBASIC_CHANNEL_CANTYPE_FIRST     NMBASIC_CHANNEL_NMTYPE_FIRST
#  define NMBASIC_CHANNEL_CANPARA_ONLY      NMBASIC_CHANNEL_NMPARA_ONLY
#  define NMBASIC_CHANNEL_CANPARA_FIRST     NMBASIC_CHANNEL_NMPARA_FIRST
# endif

# define NMBASIC_CHANNEL_APPLTYPE_ONLY       NMBASIC_CHANNEL_NMTYPE_ONLY
# define NMBASIC_CHANNEL_APPLTYPE_FIRST      NMBASIC_CHANNEL_NMTYPE_FIRST
# define NMBASIC_CHANNEL_APPLPARA_ONLY
# define NMBASIC_CHANNEL_APPLPARA_FIRST
#endif  /* NMBASIC_ENABLE_INDEXED_NM */

#if defined ( NMBASIC_ENABLE_INDEXED_NM )
# define NMBASICVAR_CH_DEF(var)               var[cNmBasicNrOfChannels] /* PRQA S 3410 */ 
# define NMBASICVAR(var)                      var[channel]              /* PRQA S 3410 */ 
#else
# define NMBASICVAR_CH_DEF(var)               var /* PRQA S 3410 */ 
# define NMBASICVAR(var)                      var /* PRQA S 3410 */ 
#endif


/***************************************************************************/
/* error codes for ApplNmBasicFatalError                                   */
/***************************************************************************/
/* error codes to check generated tables */
/* There are gaps in the assertion numbering. These gaps belong to former assertions which were deleted meanwhile. */
#if (defined NMBASIC_ENABLE_SOFTWARE_CHECK)
# define kNmBasicErrStateUndefined                 0x01 /* an undefined state is detected in the NM state machine */

/* ESCAN00012097 */
# define kNmBasicErrInitObjOutOfRange              0x02 /* the initialization object is out of range */

# if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) || defined(NMBASIC_BUSOFF_RECOV_EXTENDED) )
#  define kNmBasicErrBusOffFastTimeOutOfRange       0x03 /* the fast BusOff recovery time is out of range */
# endif

# if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
#  define kNmBasicErrBusOffSlowTimeOutOfRange       0x04 /* the slow BusOff recovery time is out of range */
#  define kNmBasicErrBusOffFastSlowTimeOutOfRange   0x05 /* the change-from-fast-to-slow BusOff recovery time is out of range */
#  define kNmBasicErrFastLargerSlowTime             0x06
#  if defined(NMBASIC_ENABLE_BUSOFFREP_TIMER)
#   define kNmBasicErrBusOffRepTimeOutOfRange        0x07 /* the BusOff repaired time is out of range */
#   define kNmBasicErrBusOffRepairTimeTooSmall       0x08 /* the fast BusOff repaired time is too small */
#  endif
# endif



# define kNmBasicErrWrongChannelHandle             0x0D /* NM Basic API is called for a CAN channel which does not belong to the current identity */
#endif


/**********************************************************************************************************************
  Global typedefs
**********************************************************************************************************************/
/* ESCAN00031155 */


/***************************************************************************/
/* External Data                                                           */
/***************************************************************************/
/* ROM constants for version control */
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kNmBasicMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kNmBasicSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kNmBasicReleaseVersion;

/* ROM tables for multi NM channel systems */
#if defined ( NMBASIC_ENABLE_CHANNEL_INDIRECTION )  /* ESCAN00012670 */
/* channel indirection */
extern CanChannelHandle MEMORY_ROM NmBasicCanToNmIndirection[kCanNumberOfChannels];
extern CanChannelHandle MEMORY_ROM NmBasicNmToCanIndirection[cNmBasicNrOfChannels];
#endif

#if( defined NMBASIC_ENABLE_INDEXED_NM )
/* field of init objects */
extern V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmBasicCanInitObject_Field[cNmBasicNrOfChannels];

/* field of task cyles */
extern V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmBasicTaskPeriod_Field[cNmBasicNrOfChannels];

# if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) || defined(NMBASIC_BUSOFF_RECOV_EXTENDED) || defined(NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED) )/* ESCAN00017908 */
/* time distance between HW BusOff event and SW BusOff recovery */
extern V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmBasicBusOffRecTime_Field[cNmBasicNrOfChannels];
# endif

# if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
/* time distance between HW BusOff event and SW BusOff recovery for slow recovery */
extern V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmBasicBusOffRecTimeSlow_Field[cNmBasicNrOfChannels];

/* time distance between first fast and first slow BusOff recovery */
extern V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmBasicBusOffFastToSlow_Field[cNmBasicNrOfChannels];
# endif

# if defined(NMBASIC_ENABLE_BUSOFFREP_TIMER)
/* time distance between detected BusOff event and a detection of BusOff repaired */
extern V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmBasicBusOffRepairedTime_Field[cNmBasicNrOfChannels];
# endif

#endif


/***************************************************************************
* service function prototypes
****************************************************************************/
extern void NmBasicInitPowerOn(void);
extern void NmBasicInit(NMBASIC_CHANNEL_NMTYPE_ONLY);
extern void NmBasicTask(NMBASIC_CHANNEL_NMTYPE_ONLY);
extern void NmBasicStart(NMBASIC_CHANNEL_NMTYPE_ONLY);
extern void NmBasicStop(NMBASIC_CHANNEL_NMTYPE_ONLY);
extern void NmBasicCanBusOff(NMBASIC_CHANNEL_CANTYPE_ONLY);
extern vuint8 NmBasicGetNetState(NMBASIC_CHANNEL_NMTYPE_ONLY);




/***************************************************************************
* callback function prototypes
****************************************************************************/
extern void ApplNmBasicBusOffStart(NMBASIC_CHANNEL_APPLTYPE_ONLY);
extern void ApplNmBasicBusOffEnd(NMBASIC_CHANNEL_APPLTYPE_ONLY);

#if (defined NMBASIC_BUSOFF_RECOV_EXTENDED)
extern void ApplNmBasicFirstBusOffSlow(NMBASIC_CHANNEL_APPLTYPE_ONLY);
extern void ApplNmBasicBusOffRestart(NMBASIC_CHANNEL_APPLTYPE_ONLY);
#endif



extern void ApplNmBasicEnabledCom(NMBASIC_CHANNEL_APPLTYPE_ONLY);
extern void ApplNmBasicSwitchTransceiverOn(NMBASIC_CHANNEL_APPLTYPE_ONLY);

extern void ApplNmBasicDisabledCom(NMBASIC_CHANNEL_APPLTYPE_ONLY);
extern vuint8 ApplNmBasicSwitchTransceiverOff(NMBASIC_CHANNEL_APPLTYPE_ONLY);

#if (defined NMBASIC_ENABLE_SOFTWARE_CHECK)
# if( defined (C_MULTIPLE_RECEIVE_CHANNEL) && defined (NMBASIC_ENABLE_INDEXED_NM) )
extern void ApplNmBasicFatalError(NMBASIC_CHANNEL_APPLTYPE_FIRST vuint8 error);
# else
extern void ApplNmBasicFatalError(vuint8 error);
# endif
#endif

/* ESCAN00031157 */

#endif  /* NMBASIC_IMPL_H */
