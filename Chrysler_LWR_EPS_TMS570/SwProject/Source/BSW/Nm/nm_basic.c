
/*****************************************************************************
| Project Name: Node-Management Basic
|    File Name: nm_basic.c
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
|                              ESCAN00009408: change the name of the algorithm defines
|                              ESCAN00009426: change compiler switches for organi: #ifdef
|                              ESCAN00009681: abort BusOff recovery in case is stopping the NM is not working correctly
|                              ESCAN00009705: add callback functions for transceiver handling
| 2004-10-13   1.02  Bs        ESCAN00009377: add checks of generated defines
|                              ESCAN00009874: ignore return value of CanStop() and CanStart() function
|                              ESCAN00009877: do not interrupt BusOff recovery by call of NmBasicStart()
|                              ESCAN00009878: Naming Conventions: change version defines to serve the Vector naming rules
|                              ESCAN00009910: change use of numbers into symbolic defines in BusOff recovery checks
|                              ESCAN00009911: declare variables as 'static'
|                              ESCAN00009912: explicite check of variables in if-condition
| 2005-04-05   1.03  Bs        ESCAN00010780: comment for CanOnline() is wrong
|                              ESCAN00011711: init object should support code duplication
|                              ESCAN00011712: add the new BusOff recovery algorithm 'extended'
|                              ESCAN00011728: NM start and stop handling must be configurable
|                              ESCAN00011765: add state machine in cyclic task
|                              ESCAN00011785: add assertions for runtime checks
|                              ESCAN00011786: add a 'get Net state' function
|                              ESCAN00011787: add const pragma to support IAR linker
| 2005-04-21   1.04  Bs        ESCAN00011990: change memory qualifier of version number constants
|                              ESCAN00012062: standardization of NMbasic defines
|                              ESCAN00012063: add support of indexed and indirected NM channels for use in multi channel systems
|                              ESCAN00012064: shorten compiler switches which are too long
|                              ESCAN00012065: change macros which are used for assertion handling
|                              ESCAN00012066: do BusOff-repaired detection via Tx-Observe handling for NMbasic channels only
|                              ESCAN00012098: reset timer for detection of 'change from fast to slow BusOff' 
|                                             when the NM handling is stopped
|                              ESCAN00012099: correct BusOff repaired detection algorithm by message transmission 
|                                             (CAN bus is asserted to work correct again)
|                              ESCAN00012104: support the use of power management components
|                              some comments changed and some unnecessary comments deleted
|                              some indentations corrected
| 2005-07-06   1.05  Bs        the word 'notifiy' corrected into 'notify'
|                              ESCAN00012094: add a compiler check for the dependency of indexed NM and channel indirection
|                                             and just use the indirection switch instead in combination with indexed NM
|                              ESCAN00012094: just check the indirection switch instead in combination with indexed NM
|                              ESCAN00012095: change function names of interface to AsrNm
|                              ESCAN00012156: function call of 'ApplNmBasicBusOffRestart()' is done in 
|                                             already in 'ApplCanTxObjConfirmed()' instead on task level 
|                                             (just for 'reparied CAN bus' detection via message Tx)
|                              ESCAN00012158: Assertion to checkt the NM state in 'ApplCanTxObjConfirmed()' removed
|                              ESCAN00012490: include of header files changed
|                              ESCAN00012671: some pre-processor checks are just done in non-indexed systems
|                              ESCAN00012672: timer for 'reparied CAN bus' detection is (re-)started if BusOffStart is detected
|                              ESCAN00012786: call CanOffline during initialization just, if AsrNm is not used on this channel
|                              ESCAN00012853: Add return value to application callback function 
|                                             'ApplNmBasicSwitchTransceiverOff()'
|                              ESCAN00012854: function call of 'CanResetBusSleep()' only in combination with AsrNm
| 2005-07-14   1.06  Bs        PC-Lint messages e652 suppressed for re-defining variables to arrays
|                              unnecessary comment deleted
|                              configuration check added: AsrNm only together with BusOff recovery algorithm 'extended'
|                              ESCAN00012903: call function 'CanOffline()' during initialization
|                              ESCAN00012904: variable 'bNmBasicBusOffRecTimer' just available in function 
|                                             'NmBasic_BusSleepModeNotification' if algo 'delayed' or 'extended' is configured
|                              ESCAN00012905: Define 'cNmBasicNrOfChannels' is not channel specific /
|                                             arrays in indexed systems are not channel specific
|                              ESCAN00012919: Add prototypes of local functions
|                              ESCAN00012920: access to variable 'bNmBasicBusOffRepairedTimer' must be enclosed in compiler switches
|                              ESCAN00012926: 'BusOff restart' detection corrected in 'ApplCanTxObjConfirmed()'
| 2005-07-25   1.07  Bs        Variable 'cNmBasicBusOffRepaired' put into compiler switches
|                              ESCAN00012883: change 'BusOffEnd'-handling for BusOff recovery algorithm 'immediate'
|                              ESCAN00013091: reset variables after 'BusOff repaired' detection in 'ApplCanTxObjConfirmed()'
| 2006-02-16   1.08  Bs        ORGANI check added to detect remaining NM_ASR code sequences
|                              ESCAN00014289: initialization of multi NM-channel systems corrected
|                              ESCAN00014705: _COMMENT switches deleted
|                              ESCAN00015623: Assertions in NmBasicStart() and NmBasicStop() deleted
| 2006-03-14   1.09  Pet       ESCAN00015663: initialization of multi NM-channel systems corrected for no channel indirection
| 2006-04-26   1.10  Bs        complete assertion handling reworked
|                              compile check about CANdrv reference implementation added
|                              ESCAN00015987: BusOff request handling changed
|                              ESCAN00016185: call 'CanResetBusOffEnd()' only CAN-interrupt protected in 
|                               'NmBasic_BusSleepModeNotification()'
|                              ESCAN00016186: BusOffEnd handling for AsrNm changed
|                              ESCAN00016211: Communication request and release events will be handled in every state
| 2006-06-08   1.11  Bs        ESCAN00016466: Dummy assignment added in NmBasicCanBusOff()
|                              ESCAN00016556: Handle only the NmBasic channel in ApplCanTxObjConfirmed()
| 2006-08-03   1.12  Dhf       ESCAN00017158: replaced CanCanInterruptDisable/Restore with CanGlobalInterruptDisable/Restore
|                                             in function NmBasic_BusSleepModeNotification
|                              ESCAN00016667: added casts to avoid compiler warnings
|                              configuration check for CAN driver reference implementation added
| 2006-10-05   1.13  Dhf       ESCAN00017908: Adaption of Nm_PwrTrainBasic to 
|                              support the BusOff algorithm 'time supervised'
| 2007-01-24   1.14  Dhf       ESCAN00012093: change order of #ifdefs at variable declaration
|                              ESCAN00012097: add assertions to check the generated tabels during initialization
|                              ESCAN00018548: A BusOff notification in state STOP is not handled correctly
|                              ESCAN00018971: Nm Basic uses incorrect preprocessor switch: VGEN_ENABLE_NM_ASR_GENERIC replaced by VGEN_ENABLE_NM_ASR_CAN
|                              ESCAN00018298: Compiler warning using bNmBasicStateRequest
|                              ESCAN00019119: added BusOff additions and Tx-Observation-Handling
|                              ESCAN00019593: ApplNmBasicBusOffRestart() is not called in all cases when the BusOff recovery is aborted
| 2008-11-10   1.15  Dhf       ESCAN00023008: Support Rx during BusOff as soon as possible
|                              ESCAN00025822: Compiler warning due to pointless comparison in assertion
|                              ESCAN00030715: reinitialization of the CAN controller before stopping the communication
|                              ESCAN00031037: NM Basic does not support CAN driver reference implementation 1.5
|                              ESCAN00031155: Adapt NM Basic to support QNX context switch
|                              ESCAN00031157: added external CanOnline/Offline handling
|                              ESCAN00031403: relocated call of ApplNmBasicBusOffEnd
| 2009-02-04   1.15.01 Dhf     ESCAN00032403: incorrect fatal error notification via ApplNmBasicFatalError
| 2009-10-19   1.15.02 Dhf     ESCAN00034728: changed precompile checks
|                              ESCAN00038780: changed precompile checks
| 2010-08-18   1.15.03 Dhf     ESCAN00044450: removed CanInit call during initialization and added multiple configuration check
| 2011-11-23   1.15.04 vismpf  ESCAN00051839: adapted dummy statements
| 2012-10-08   1.15.05 vismpf  ESCAN00061225: corrected encapsulation of bNmBasicStateRequest and bNmBasicBusOffRepaired
|****************************************************************************/


#define NMBASIC_MODULE

/***************************************************************************
* include files
****************************************************************************/
#include "v_cfg.h"

#if defined ( VGEN_GENY )
#include "v_inc.h"
#else
#include "can_inc.h"
#endif

#include "nm_basic.h"

#if( !defined(__NMBASIC_CFG_H__))
# if defined ( VGEN_GENY )
#  error "The configuration file for the NMbasic is not included in 'v_inc.h'."
# else
#  error "The configuration file for the NMbasic is not included in 'can_inc.h'."
# endif
#endif


/***************************************************************************
* version control
****************************************************************************/
#if( NM_PWRTRAINBASIC_VERSION != 0x0115 )
# error "Header and source file are inconsistent!"
#endif
#if( NM_PWRTRAINBASIC_RELEASE_VERSION != 0x05 )
# error "Different release versions in Header and source used!"
#endif


/****************************************************************************/
/* Constants                                                                */
/****************************************************************************/
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kNmBasicMainVersion    = (vuint8)(NM_PWRTRAINBASIC_VERSION >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kNmBasicSubVersion     = (vuint8)(NM_PWRTRAINBASIC_VERSION & 0xFF);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kNmBasicReleaseVersion = (vuint8)(NM_PWRTRAINBASIC_RELEASE_VERSION);


/***************************************************************************/
/* Organi Check                                                            */
/***************************************************************************/
/* Organi filtering was performed */



/*****************************************************************************/
/* check configuration defines                                               */
/*****************************************************************************/
#if defined(NMBASIC_ENABLE_CHANNEL_INDIRECTION) && !defined(NMBASIC_ENABLE_INDEXED_NM)   /* ESCAN00012094 */
# error "Sorry, the current configuration is illegal:"
# error "Channel indirection is not possible in a non-indexed system."
#endif


/* check if CAN driver supports the 'BusOff repaired' detection by message transmission */
#if( defined NMBASIC_BUSOFF_RECOV_EXTENDED )
# if( defined NMBASIC_ENABLE_BUSOFFREP_MSG )
#  if defined(C_VERSION_REF_IMPLEMENTATION)
#  else
#   error "Sorry, the CANdrv reference implementation define is missing."
#  endif
/* ESCAN00031037 */
#  if( (C_VERSION_REF_IMPLEMENTATION != 0x140) && (C_VERSION_REF_IMPLEMENTATION != 0x150) )
#   error "Sorry, the 'BusOff repaired' detection by message transmission"
#   error "needs a CAN driver with ReferenceImplementation 1.4 or 1.5!"
#  endif
# endif
#endif

/* check if the define for the number of used NMbasic channels is configured or not */
#if !(defined( cNmBasicNrOfChannels ))  /* ESCAN00012905 */
# error "No valid configuration of the number of used NMbasic channels found."
# error "Please check the configuration if the define 'cNmBasicNrOfChannels' is correctly implemented."
#endif

#if !defined ( NMBASIC_ENABLE_INDEXED_NM )  /* ESCAN00012671 */
/* check if the define for the initialization object is configured or not */
# if !(defined( cNmBasicInitObject ))
#  error "No valid configuration of the init object found."
#  error "Please check the configuration if the define 'cNmBasicInitObject' is correctly implemented."
# endif

/* check if the define for the task period is configured or not */
# if !(defined( cNmBasicTaskPeriod ))
#  error "No valid configuration of the task period found."
#  error "Please check the configuration if the define 'cNmBasicTaskPeriod' is correctly implemented."
# endif

# if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) || defined(NMBASIC_BUSOFF_RECOV_EXTENDED) || defined(NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED) ) /* ESCAN00017908 */
/* check if the define for the (fast) BusOff recovery time is configured or not */
#  if !(defined( cNmBasicBusOffRecTime ))
#   error "No valid configuration of the (fast) Busoff recovery time found."
#   error "Please check the configuration if the define 'cNmBasicBusOffRecTime' is correctly implemented."
#  endif
# endif

# if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
/* check if the define for the fast BusOff recovery time is configured or not */
#  if !(defined( cNmBasicBusOffRecTimeSlow ))
#   error "No valid configuration of the (fast) BusOff recovery time found."
#   error "Please check the configuration if the define 'cNmBasicBusOffRecTimeSlow' is correctly implemented."
#  endif

/* check if the define for the time distance between changing from fast to slow BusOff recovery is configured or not */
#  if !(defined( cNmBasicBusOffChangeFastToSlow ))
#   error "No valid configuration of the time distance between changing from fast to slow BusOff recovery found."
#   error "Please check the configuration if the define 'cNmBasicBusOffChangeFastToSlow' is correctly implemented."
#  endif

#  if defined(NMBASIC_ENABLE_BUSOFFREP_TIMER)
/* check if the define for the time distance to detect a repaired BusOff is configured or not */
#   if !(defined( cNmBasicBusOffRepairedTime ))
#    error "No valid configuration of the define for the time distance to detect a repaired BusOff found."
#    error "Please check the configuration if the define 'cNmBasicBusOffRepairedTime' is correctly implemented."
#   endif
#  endif
# endif  /* extended algorithm */


#endif  /* ! indexed NM */

/* check if either the 'immediat' or the 'delayed' or the 'extended' or the 'time supervised' BusOff recovery algorithm is activated */
/* ESCAN00017908: added check for algo 'time supervised'  */
#if !(defined( NMBASIC_BUSOFF_RECOV_DELAYED ) || defined( NMBASIC_BUSOFF_RECOV_IMMEDIAT ) || defined( NMBASIC_BUSOFF_RECOV_EXTENDED ) || defined( NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED ))
# error "no valid configuration of the BusOff algorithm - neither 'immediat' nor 'delayed' nor 'extended' nor 'time supervised' algo is specified"
# error "please check configuration in generation tool and/or the configuration file"
#endif

#if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) && defined(NMBASIC_BUSOFF_RECOV_IMMEDIAT) )
# error "more than one BusOff algorithm configured - 'delayed' and 'immediate' at the same time"
# error "please check configuration in generation tool and/or the configuration file"
#endif

#if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) && defined(NMBASIC_BUSOFF_RECOV_EXTENDED) )
# error "more than one BusOff algorithm configured - 'delayed' and 'extended' at the same time"
# error "please check configuration in generation tool and/or the configuration file"
#endif

#if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) && defined(NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED) ) /* ESCAN00017908 */
# error "more than one BusOff algorithm configured - 'delayed' and 'time supervised' at the same time"
# error "please check configuration in generation tool and/or the configuration file"
#endif

#if( defined(NMBASIC_BUSOFF_RECOV_EXTENDED) && defined(NMBASIC_BUSOFF_RECOV_IMMEDIAT) )
# error "more than one BusOff algorithm configured - 'extended' and 'immediate' at the same time"
# error "please check configuration in generation tool and/or the configuration file"
#endif

#if( defined(NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED) && defined(NMBASIC_BUSOFF_RECOV_IMMEDIAT) ) /* ESCAN00017908 */
# error "more than one BusOff algorithm configured - 'time supervised' and 'immediate' at the same time"
# error "please check configuration in generation tool and/or the configuration file"
#endif

#if( defined(NMBASIC_BUSOFF_RECOV_EXTENDED) && defined(NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED) ) /* ESCAN00017908 */
# error "more than one BusOff algorithm configured - 'extended' and 'immediate' at the same time"
# error "please check configuration in generation tool and/or the configuration file"
#endif

#if(defined(NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED) && defined (VGEN_CANGEN_VERSION) ) /* ESCAN00017908 */
# error "BusOff recovery algorithm 'Time Supervised' is not supported in CANgen"
# error "please check configuration in generation tool and/or the configuration file"
#endif

/* only if the 'extended' BusOff algorithm is activated */
#if( defined NMBASIC_BUSOFF_RECOV_EXTENDED )
/* check if the BusOff repair mechanism via message Tx is either enabled or disabled */
# if( defined(NMBASIC_ENABLE_BUSOFFREP_MSG) && defined(NMBASIC_DISABLE_BUSOFFREP_MSG) )
#  error "The BusOff repair mechanism via message Tx is configured as enabled and disabled at the same time."
#  error "please check configuration in generation tool and/or the configuration file"
# endif

# if !( defined(NMBASIC_ENABLE_BUSOFFREP_MSG) || defined(NMBASIC_DISABLE_BUSOFFREP_MSG) )
#  error "The BusOff repair mechanism via message Tx is not configured as enabled or disabled."
#  error "please check configuration in generation tool and/or the configuration file"
# endif

/* check if the BusOff repair mechanism via timer is either enabled or disabled */
# if( defined(NMBASIC_ENABLE_BUSOFFREP_TIMER) && defined(NMBASIC_DISABLE_BUSOFFREP_TIMER) )
#  error "The BusOff repair mechanism via timer is configured as enabled and disabled at the same time."
#  error "please check configuration in generation tool and/or the configuration file"
# endif

# if !( defined(NMBASIC_ENABLE_BUSOFFREP_TIMER) || defined(NMBASIC_DISABLE_BUSOFFREP_TIMER) )
#  error "The BusOff repair mechanism via timer is not configured as enabled or disabled."
#  error "please check configuration in generation tool and/or the configuration file"
# endif

/* check if the BusOff repair mechanism via timer and via msg Tx is configured at the same time or not */
# if( defined(NMBASIC_ENABLE_BUSOFFREP_TIMER) && defined(NMBASIC_ENABLE_BUSOFFREP_MSG) )
#  error "The BusOff repair mechanism via timer and by successful message transmission are enabled at the same time."
#  error "please check configuration in generation tool and/or the configuration file"
# endif
# if( defined(NMBASIC_DISABLE_BUSOFFREP_TIMER) && defined(NMBASIC_DISABLE_BUSOFFREP_MSG) )
#  error "The BusOff repair mechanism via timer and by successful message transmission are both disabled at the same time."
#  error "please check configuration in generation tool and/or the configuration file"
# endif
#else
/* 'extended' BusOff algorithm is de-activated => no BusOff repair mechanism is needed */
# if( defined( NMBASIC_ENABLE_BUSOFFREP_MSG ) )
#  error "The BusOff repair mechanism via message transmission is activated but not used in the current algorithm"
#  error "please check configuration in generation tool and/or the configuration file"
# endif
# if( defined( NMBASIC_ENABLE_BUSOFFREP_TIMER ) )
#  error "The BusOff repair mechanism via timer is activated but not used in the current algorithm"
#  error "please check configuration in generation tool and/or the configuration file"
# endif
#endif

/* check if the NM assertion handling (software checks) is correctly configured */
#if( defined(NMBASIC_ENABLE_SOFTWARE_CHECK) && defined(NMBASIC_DISABLE_SOFTWARE_CHECK) )
# error "The assertion handling (SW checks) is configured as enabled and disabled at the same time."
# error "please check configuration in generation tool and/or the configuration file"
#endif

#if !( defined(NMBASIC_ENABLE_SOFTWARE_CHECK) || defined(NMBASIC_DISABLE_SOFTWARE_CHECK) )
# error "The assertion handling (SW checks) is not configured as enabled nor disabled."
# error "please check configuration in generation tool and/or the configuration file"
#endif

/* check, if Tx observe mechanism is activated for BusOff repaired detection */
#if( defined NMBASIC_BUSOFF_RECOV_EXTENDED )
# if( defined NMBASIC_ENABLE_BUSOFFREP_MSG )
#  if( defined C_ENABLE_TX_OBSERVE )
#  else
#   error "The NMbasic uses the Tx observe mechanism of the CAN driver."
#   error "Please activate the Tx observe functionality in the generation tool on the CAN driver page."
#  endif
# endif
#endif



#if( defined NMBASIC_ENABLE_INDEXED_NM )
/* a lot of checks are not possible in multi channel systems because tables instead of defines are used */

/* check configuration of the init object which is used for BusOff recovery */
/* in C_MULTIPLE_RECEIVE_CHANNEL systems the init object can not be checked by compiler directives */
/* please activate assertions in the CANdriver to detect the use of a maybe wrong init object */

#else
/* check defines which are used in a single NMbasic-channel system */

/* check configuration of the init object which is used for BusOff recovery */
# if( (cNmBasicInitObject>=kCanNumberOfInitObjects) || (cNmBasicInitObject < 0))
#  error "An illegal number of busoff init register structure is configured."
# endif

/* task call cycle must be unequal to zero */
# if ( cNmBasicTaskPeriod == 0x00 )
#  error "configured call cycle of NmBasicTask is zero; please correct the setting in generation tool"
# endif

/* check, if the configured times can be reached by the specified call cycle */
# if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) || defined(NMBASIC_BUSOFF_RECOV_EXTENDED) )
#  if( cNmBasicBusOffRecTime != ((cNmBasicBusOffRecTime/cNmBasicTaskPeriod) * cNmBasicTaskPeriod) )
#   error "sorry, the specified 'BusOff recovery' time can not be reached with the call cycle"
#   error "please check configuration in generation tool and the generated configuration file"
#  endif
# endif

# if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
#  if( cNmBasicBusOffRecTimeSlow != ((cNmBasicBusOffRecTimeSlow/cNmBasicTaskPeriod) * cNmBasicTaskPeriod) )
#   error "sorry, the specified 'slow BusOff recovery' time can not be reached with the call cycle"
#   error "please check configuration in generation tool and the generated configuration file"
#  endif

#  if( cNmBasicBusOffChangeFastToSlow != ((cNmBasicBusOffChangeFastToSlow/cNmBasicTaskPeriod) * cNmBasicTaskPeriod) )
#   error "sorry, the specified 'change BusOff from fast to slow recovery' time can not be reached with the call cycle"
#   error "please check configuration in generation tool and the generated configuration file"
#  endif
# endif

# if defined(NMBASIC_ENABLE_BUSOFFREP_TIMER)
#  if( cNmBasicBusOffRepairedTime != ((cNmBasicBusOffRepairedTime/cNmBasicTaskPeriod) * cNmBasicTaskPeriod) )
#   error "sorry, the specified 'BusOff repaired' time can not be reached with the call cycle"
#   error "please check configuration in generation tool and the generated configuration file"
#  endif
# endif

/* check, that the BusOff recovery time 'fast' is shorter or equal to 'slow' */
# if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
#  if( cNmBasicBusOffRecTime > cNmBasicBusOffRecTimeSlow )
#   error "sorry, the specified 'fast BusOff recovery' time is longer than the 'slow BusOff recovery' time "
#   error "please check configuration in generation tool and the generated configuration file"
#  endif
# endif

# if defined(NMBASIC_ENABLE_BUSOFFREP_TIMER)
/* check, that the 'BusOff repaired' detection time is longer than the BusOff recovery time 'fast' */
#  if( cNmBasicBusOffRepairedTime <= cNmBasicBusOffRecTime )
#   error "sorry, the specified 'BusOff repaired' time is shorter than or equal as the 'fast BusOff recovery' time "
#   error "please check configuration in generation tool and the generated configuration file"
#  endif

/* check, that the 'BusOff repaired' detection time is longer than the BusOff recovery time 'long' */
#  if( cNmBasicBusOffRepairedTime <= cNmBasicBusOffRecTimeSlow )
#   error "sorry, the specified 'BusOff repaired' time is shorter than or equal as the 'slow BusOff recovery' time "
#   error "please check configuration in generation tool and the generated configuration file"
#  endif
# endif
#endif

/* check, if at least one NmBasic channel is configured */
#if(cNmBasicNrOfChannels <= 0)  /* ESCAN00016556 */
# error "Sorry, the NmBasic is included in your project, but not configured in the configuration tool."
#endif


/* ESCAN00023008 */
#if defined(NMBASIC_BUSOFF_RECOV_IMMEDIAT)
#else
# if defined ( NMBASIC_ENABLE_EARLY_BUSOFF_REINIT )
#  if defined ( C_ENABLE_DRIVER_STATUS )
#  else
#   error "NmBasic: Feature 'NMBASIC_ENABLE_EARLY_BUSOFF_REINIT' requires a DrvCan that supports 'C_ENABLE_DRIVER_STATUS'!"
#  endif
# endif
#endif

/***************************************************************************
* defines
****************************************************************************/
/* for clearing NM state requests */
#define NMBASIC_STATE_NO_REQUEST  0x00

/* defines for using the fast or slow BusOff recovery */
#define cNmBasicBusOffSlowNotActive  0x00
#define cNmBasicBusOffSlowActive     0x01

/* defines for 'BusOff repaired' detection via messages Tx */
#define cNmBasicBusOffNotDetected  0x00
#define cNmBasicBusOffNotRepaired  0x01
#if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
# if defined(NMBASIC_ENABLE_BUSOFFREP_TIMER)
#  define cNmBasicBusOffRepaired     0x02
# endif
#endif

/* defines for 'BusOff repaired' detection via messages Tx */
#define cNmBasicBusOffFastToSlowNotDone  0x00
#define cNmBasicBusOffFastToSlowDone     0x01


#if( defined NMBASIC_ENABLE_INDEXED_NM )
/* defines used for timing values (multi NM channel system) */

# if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) || defined(NMBASIC_BUSOFF_RECOV_EXTENDED) )
/* time distance between HW BusOff event and SW BusOff recovery */
#  define cNmBasicBusOffRecTimer (NmBasicBusOffRecTime_Field[channel] / NmBasicTaskPeriod_Field[channel])
# endif

# if( defined NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED )/* ESCAN00017908 */
/* time distance between HW BusOff event and SW BusOff recovery, NmBasicBusOffRecTime_Field is already divided by
   the task cycle in the generation tool */
#  define cNmBasicBusOffRecTimer  NmBasicBusOffRecTime_Field[channel]
# endif

# if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
/* time distance between HW BusOff event and SW BusOff recovery for slow recovery */
#  define cNmBasicBusOffRecSlowTimer (NmBasicBusOffRecTimeSlow_Field[channel] / NmBasicTaskPeriod_Field[channel])
#  define cNmBasicBusOffFastToSlowTimer (NmBasicBusOffFastToSlow_Field[channel] / NmBasicTaskPeriod_Field[channel])
# endif

# if defined(NMBASIC_ENABLE_BUSOFFREP_TIMER)
/* time distance between detected BusOff event and a detection of BusOff repaired */
#  define cNmBasicBusOffRepairedTimer (NmBasicBusOffRepairedTime_Field[channel] / NmBasicTaskPeriod_Field[channel])
# endif


/* re-define the Init-Object */
# define cNmBasicInitObject (NmBasicCanInitObject_Field[channel])

#else
/* defines used for timing values (single NM channel system) */

# if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) || defined(NMBASIC_BUSOFF_RECOV_EXTENDED) )
/* time distance between HW BusOff event and SW BusOff recovery */
#  define cNmBasicBusOffRecTimer (cNmBasicBusOffRecTime / cNmBasicTaskPeriod)
# endif

# if( defined NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED )/* ESCAN00017908 */
/* time distance between HW BusOff event and SW BusOff recovery, cNmBasicBusOffRecTime is already divided by
   the task cycle in the generation tool */
#  define cNmBasicBusOffRecTimer  cNmBasicBusOffRecTime
# endif

# if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
/* time distance between HW BusOff event and SW BusOff recovery for slow recovery */
#  define cNmBasicBusOffRecSlowTimer (cNmBasicBusOffRecTimeSlow / cNmBasicTaskPeriod)
#  define cNmBasicBusOffFastToSlowTimer (cNmBasicBusOffChangeFastToSlow / cNmBasicTaskPeriod)
# endif

# if defined(NMBASIC_ENABLE_BUSOFFREP_TIMER)
/* time distance between detected BusOff event and a detection of BusOff repaired */
#  define cNmBasicBusOffRepairedTimer (cNmBasicBusOffRepairedTime / cNmBasicTaskPeriod)
# endif

#endif

/* ESCAN00023008 */
#if defined(NMBASIC_BUSOFF_RECOV_IMMEDIAT)
/* not applicable for algo "immediate" */
#else
# if defined ( NMBASIC_ENABLE_EARLY_BUSOFF_REINIT )
#  define cNmBasicCanDrvInInitMode    (vuint8)0x00
#  define cNmBasicCanDrvIsBusOff      (vuint8)0x01
# endif
#endif


/***************************************************************************
* check calculated defines
****************************************************************************/
#if( defined NMBASIC_ENABLE_INDEXED_NM )
/* checks are not possible in multi NM channel systems */
#else
/* only possible in single channel version of the NMbasic if the algorithm is DELAYED or EXTENDED */

# if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) || defined(NMBASIC_BUSOFF_RECOV_EXTENDED) )
#  if((cNmBasicBusOffRecTimer < 1) || (cNmBasicBusOffRecTimer > 255))
#   error "The time distance of the BusOff (fast) recovery algorithm is out of range."
#  endif
# endif

# if defined NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED /* ESCAN00017908 */
#  if((cNmBasicBusOffRecTimer < 1) || (cNmBasicBusOffRecTimer > 65535))
#   error "The time distance of the BusOff recovery algorithm is out of range."
#   error "Please check configuration and generation warnings."
#  endif
# endif

# if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
#  if((cNmBasicBusOffRecSlowTimer < 1) || (cNmBasicBusOffRecSlowTimer > 255))
#   error "The time distance of the BusOff slow recovery algorithm is out of range."
#  endif
#  if((cNmBasicBusOffFastToSlowTimer < 1) || (cNmBasicBusOffFastToSlowTimer > 255))
#   error "The configured time for changing from fast to slow BusOff recovery is out of range."
#  endif
# endif

# if defined(NMBASIC_ENABLE_BUSOFFREP_TIMER)
#  if((cNmBasicBusOffRepairedTimer < 1) || (cNmBasicBusOffRepairedTimer > 255))
#   error "The configured time for detecting a 'BusOff repaired' is out of range."
#  endif
# endif


#endif


/***************************************************************************/
/* Assertions                                                              */
/***************************************************************************/
#if defined( NMBASIC_ENABLE_SOFTWARE_CHECK )
# if( defined (C_MULTIPLE_RECEIVE_CHANNEL) && defined (NMBASIC_ENABLE_INDEXED_NM) )
/* assertions are enabled in multi channel system */
#  define NmBasicAssert(p,e)       {if(!(p)){ApplNmBasicFatalError(channel, (e));}}
#  define NmBasicAssertAlways(e)   {ApplNmBasicFatalError(channel, (e));}
# else
/* assertions are enabled in single channel system */
#  define NmBasicAssert(p,e)       {if(!(p)){ApplNmBasicFatalError((e));}}
#  define NmBasicAssertAlways(e)   {ApplNmBasicFatalError((e));}
# endif
#else
  /* assertions are disabled! */
# define NmBasicAssert(p,e)
# define NmBasicAssertAlways(e)
#endif


/***************************************************************************
* local variables
****************************************************************************/
#if( defined NMBASIC_ENABLE_INDEXED_NM )
/* state machine variable */
static vuint8 bNmBasicState[cNmBasicNrOfChannels];
#else
/* state machine variable */
static vuint8 bNmBasicState;
#endif

# if( defined NMBASIC_ENABLE_INDEXED_NM )
  /* requested state (start or stop) */
static vuint8 bNmBasicStateRequest[cNmBasicNrOfChannels];
# else
/* requested state (start or stop) */
static vuint8 bNmBasicStateRequest;
# endif

#if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) || defined(NMBASIC_BUSOFF_RECOV_EXTENDED) )
# if( defined NMBASIC_ENABLE_INDEXED_NM )
/* time distance between HW BusOff event and SW BusOff recovery (fast) */
static vuint8 bNmBasicBusOffRecTimer[cNmBasicNrOfChannels];
# else
static vuint8 bNmBasicBusOffRecTimer;
# endif
#elif defined NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED /* ESCAN00017908 */
# if( defined NMBASIC_ENABLE_INDEXED_NM )
/* time distance between HW BusOff event and SW BusOff recovery (fast) */
static vuint16 wNmBasicBusOffRecTimer[cNmBasicNrOfChannels];
# else
static vuint16 wNmBasicBusOffRecTimer;
# endif
#endif

#if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
# if( defined NMBASIC_ENABLE_INDEXED_NM )
/* ESCAN00012093: change order of #ifdefs at variable declaration */

/* time distance between changing from fast to slow BusOff recovery */
static vuint8 bNmBasicBusOffRecFastSlowTimer[cNmBasicNrOfChannels];

/* flag to store, that the BusOff recovery time 'slow' should be used */
static vuint8 bNmBasicBusOffRecSlowActive[cNmBasicNrOfChannels];

/* flag to store, that the change from fast to slow BusOff recovery was done */
static vuint8 bNmBasicBusOffFastToSlowChange[cNmBasicNrOfChannels];

#  if defined(NMBASIC_ENABLE_BUSOFFREP_MSG) /* ESCAN00061225 */
/* flag to store, that the BusOff repaired state is detected */
static vuint8 bNmBasicBusOffRepaired[cNmBasicNrOfChannels];
#  endif
# else
/* time distance between changing from fast to slow BusOff recovery */
static vuint8 bNmBasicBusOffRecFastSlowTimer;

/* flag to store, that the BusOff recovery time 'slow' should be used */
static vuint8 bNmBasicBusOffRecSlowActive;

/* flag to store, that the change from fast to slow BusOff recovery was done */
static vuint8 bNmBasicBusOffFastToSlowChange;

#  if defined(NMBASIC_ENABLE_BUSOFFREP_MSG) /* ESCAN00061225 */
/* flag to store, that the BusOff repaired state is detected */
static vuint8 bNmBasicBusOffRepaired;
#  endif
# endif
#endif


#if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
#endif


#if (defined(NMBASIC_BUSOFF_RECOV_EXTENDED) && defined(NMBASIC_ENABLE_BUSOFFREP_TIMER))
# if( defined NMBASIC_ENABLE_INDEXED_NM )
/* time distance to detect a repaired BusOff */
static vuint8 bNmBasicBusOffRepairedTimer[cNmBasicNrOfChannels];
# else
/* time distance to detect a repaired BusOff */
static vuint8 bNmBasicBusOffRepairedTimer;
# endif
#endif

/* ESCAN00015987 */
#if( defined NMBASIC_ENABLE_INDEXED_NM )
/* flag to store a detected BusOff event */
static vuint8 bNmBasicBusOffRequest[cNmBasicNrOfChannels];
#else
/* flag to store a detected BusOff event */
static vuint8 bNmBasicBusOffRequest;
#endif

/* ESCAN00023008 */
#if defined(NMBASIC_BUSOFF_RECOV_IMMEDIAT)
/* not applicable for algo "immediate" */
#else
# if defined ( NMBASIC_ENABLE_EARLY_BUSOFF_REINIT )
/* variable which represents the CAN drivers init state after BusOff */
#  if( defined NMBASIC_ENABLE_INDEXED_NM )
static vuint8 bNmBasicCanDrvIsBusOff[cNmBasicNrOfChannels];
#  else
static vuint8 bNmBasicCanDrvIsBusOff;
#  endif
# endif
#endif


/****************************************************************************/
/* Additional defines for indexed arrays in multichannel systems            */
/****************************************************************************/
/*lint -save -e652 */
/* Suppress PC-Lint message: Warning 652: "#define of symbol 'xy' declared previously at line 'z'"
*  The message is suppressed because the re-definition is done deliberate and not by mistake. */
#if( defined NMBASIC_ENABLE_INDEXED_NM )
# define bNmBasicState                   bNmBasicState[channel]
# define bNmBasicStateRequest            bNmBasicStateRequest[channel]
# define bNmBasicBusOffRequest           bNmBasicBusOffRequest[channel]  /* ESCAN00015987 */
# if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) || defined(NMBASIC_BUSOFF_RECOV_EXTENDED) )
#  define bNmBasicBusOffRecTimer          bNmBasicBusOffRecTimer[channel]
# else
#  if defined NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED /* ESCAN00017908 */
#   define wNmBasicBusOffRecTimer          wNmBasicBusOffRecTimer[channel]
#  endif
# endif
# if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
#  define bNmBasicBusOffRecFastSlowTimer  bNmBasicBusOffRecFastSlowTimer[channel]
#  define bNmBasicBusOffRecSlowActive     bNmBasicBusOffRecSlowActive[channel]
#  define bNmBasicBusOffFastToSlowChange  bNmBasicBusOffFastToSlowChange[channel]
#  if defined(NMBASIC_ENABLE_BUSOFFREP_MSG) /* ESCAN00061225 */
#   define bNmBasicBusOffRepaired          bNmBasicBusOffRepaired[channel]
#  endif
# endif
# if defined(NMBASIC_ENABLE_BUSOFFREP_TIMER)
#  define bNmBasicBusOffRepairedTimer     bNmBasicBusOffRepairedTimer[channel]
# endif

/* ESCAN00023008 */
# if defined(NMBASIC_BUSOFF_RECOV_IMMEDIAT)
/* not applicable for algo "immediate" */
# else
#  if defined ( NMBASIC_ENABLE_EARLY_BUSOFF_REINIT )
#   define bNmBasicCanDrvIsBusOff            bNmBasicCanDrvIsBusOff[channel]
#  endif
# endif
#endif
/*lint -restore */


/***************************************************************************
* external variable
****************************************************************************/
#if defined ( C_ENABLE_MULTI_ECU_CONFIG )
# if (C_VERSION_REF_IMPLEMENTATION >= 0x150)
V_MEMROM0 extern V_MEMROM1 tVIdentityMsk V_MEMROM2 CanChannelIdentityAssignment[kCanNumberOfChannels];
# else
#  error "Multiple Configuration with RI < 1.5 is not supported by NM Basic!"
# endif
#endif


/***************************************************************************
* prototypes of local functions
****************************************************************************/
/* list of internal used functions */
static void NmBasicDoTheStopHandling(NMBASIC_CHANNEL_NMTYPE_ONLY);

#if( defined( NMBASIC_BUSOFF_RECOV_IMMEDIAT))
/* The function 'NmBasicDoBusOffAbort()' is not needed for this algorithm. */
#else
static void NmBasicDoBusOffAbort(NMBASIC_CHANNEL_NMTYPE_ONLY);
#endif


/***************************************************************************
* local functions
****************************************************************************/

/****************************************************************************
| NAME:             NmBasicDoTheStopHandling
| CALLED BY:        NmBasicTask
| PRECONDITIONS:    none
| INPUT PARAMETERS: indexed multi channel: network management channel
|                   single channel:        none
| RETURN VALUES:    none
| DESCRIPTION:      does all necessary actions for stopping the CAN channel
****************************************************************************/
static void NmBasicDoTheStopHandling(NMBASIC_CHANNEL_NMTYPE_ONLY)
{
# if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
  
  /* ESCAN00019593 */
#  if defined(NMBASIC_ENABLE_BUSOFFREP_TIMER)
  /* If the BusOff repaired timer is not expired this indicates that a BusOff occurred
     but the BusOff recovery is not yet aborted => 'ApplNmBasicBusOffRestart()' has to be called
     and the BusOff repaired timer has to be stopped: */
  if ( bNmBasicBusOffRepairedTimer != 0x00 )
  {
    bNmBasicBusOffRepairedTimer = 0x00;

    ApplNmBasicBusOffRestart(NMBASIC_CHANNEL_APPLPARA_ONLY);
  }
#  endif

#  if defined(NMBASIC_ENABLE_BUSOFFREP_MSG)
  /* A BusOff occurred but is not yet repaired. The communication is stopped and the BusOff
     recovery is not yet aborted => call 'ApplNmBasicBusOffRestart()'. The BusOff repaired flag
     is reset beneath. */
  if(bNmBasicBusOffRepaired == cNmBasicBusOffNotRepaired)
  { 
    ApplNmBasicBusOffRestart(NMBASIC_CHANNEL_APPLPARA_ONLY);
  }
#  endif


  /* if a BusOff occurred and it is not yet repaired and Nm Basic is in state Run and the communication 
     is stopped: all flags have to be reset... */
  bNmBasicBusOffRecFastSlowTimer = 0x00;
  bNmBasicBusOffRecSlowActive    = cNmBasicBusOffSlowNotActive;
  bNmBasicBusOffFastToSlowChange = cNmBasicBusOffFastToSlowNotDone;
#  if defined(NMBASIC_ENABLE_BUSOFFREP_MSG) /* ESCAN00061225 */
  bNmBasicBusOffRepaired         = cNmBasicBusOffNotDetected;
#  endif

# endif


# if defined NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED /* ESCAN00017908 */
  /* in case NMbasic is stopped when the BusOff recovery timer is running */
  wNmBasicBusOffRecTimer = 0x00;
# endif


  /* notify application on disabling communication */
  ApplNmBasicDisabledCom(NMBASIC_CHANNEL_APPLPARA_ONLY);

  /* set CAN driver to Tx offline mode */
  CanOffline(NMBASIC_CHANNEL_CANPARA_ONLY);

# if defined( VGEN_ENABLE_DPM)
  /* The CAN controller must not be switched off when the current configured 
  *  power management component is used. */
# else

  /* ESCAN00030715: re-initialize the CAN controller and ... */
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  CanResetBusSleep(NMBASIC_CHANNEL_CANPARA_ONLY, cNmBasicInitObject);
#  else
  CanResetBusSleep(cNmBasicInitObject);
#  endif

  /* ... switch it off: */
  (void)CanStop(NMBASIC_CHANNEL_CANPARA_ONLY);
# endif

  /* switch transceiver off */
  (void)ApplNmBasicSwitchTransceiverOff(NMBASIC_CHANNEL_APPLPARA_ONLY);
}


#if( defined( NMBASIC_BUSOFF_RECOV_IMMEDIAT))
/* The function 'NmBasicDoBusOffAbort()' is not needed for this algorithm. */
#else
/****************************************************************************
| NAME:             NmBasicDoBusOffAbort
| CALLED BY:        NmBasic_BusSleepModeNotification (ESCAN00012095) OR
|                   NmBasicTask
| PRECONDITIONS:    none
| INPUT PARAMETERS: indexed multi channel: network management channel
|                   single channel:        none
| RETURN VALUES:    none
| DESCRIPTION:      does all necessary actions if a current BusOff repair 
|                   mechanism is aborted by a stop request
****************************************************************************/
static void NmBasicDoBusOffAbort(NMBASIC_CHANNEL_NMTYPE_ONLY)
{
# if defined NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED /* ESCAN00017908 */
  /* in case NMbasic is stopped in the BusOff state, set the recovery timer to zero */
  wNmBasicBusOffRecTimer = 0x00;
# else
  /* stop all maybe running timer */
  bNmBasicBusOffRecTimer = 0x00;
# endif

# if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
  bNmBasicBusOffRecFastSlowTimer = 0x00;
  bNmBasicBusOffRecSlowActive = cNmBasicBusOffSlowNotActive;
  bNmBasicBusOffFastToSlowChange = cNmBasicBusOffFastToSlowNotDone;
#  if defined(NMBASIC_ENABLE_BUSOFFREP_MSG) /* ESCAN00061225 */
  bNmBasicBusOffRepaired = cNmBasicBusOffNotDetected;
#  endif
# endif
# if defined(NMBASIC_ENABLE_BUSOFFREP_TIMER)
  bNmBasicBusOffRepairedTimer = 0x00;
# endif

  /* ESCAN00023008 */
# if defined ( NMBASIC_ENABLE_EARLY_BUSOFF_REINIT )
  if ( bNmBasicCanDrvIsBusOff != cNmBasicCanDrvInInitMode )
  {
    /* CAN driver is not yet in init mode but recovery time expired.
        Reset flag and reinitialize anyway: */
    bNmBasicCanDrvIsBusOff = cNmBasicCanDrvInInitMode;
# else
  {
# endif

  /* run CAN driver handling for BusOff end */
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
    /* makros must be encapsulated in this way */
    CanResetBusOffEnd(NMBASIC_CHANNEL_CANPARA_ONLY, cNmBasicInitObject);
# else
    CanResetBusOffEnd(cNmBasicInitObject);
# endif
   }

  /* ESCAN00031403 */
  /* notify application on end of BusOff recovery algorithm */
  ApplNmBasicBusOffEnd(NMBASIC_CHANNEL_APPLPARA_ONLY); 

# if (defined NMBASIC_BUSOFF_RECOV_EXTENDED)
  /* repeated BusOff detection has ended => inform application */
  ApplNmBasicBusOffRestart(NMBASIC_CHANNEL_APPLPARA_ONLY);
# endif
}
#endif


/***************************************************************************
* global functions
****************************************************************************/

/****************************************************************************
| NAME:             NmBasicInitPowerOn
| CALLED BY:        application
| PRECONDITIONS:    The CAN interrupts must be disabled.
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      init node management
****************************************************************************/
void NmBasicInitPowerOn(void)
{
#if( defined NMBASIC_ENABLE_INDEXED_NM )
  /* local variables */
  CanChannelHandle channel;  /* used to initialize all channels of the NM (in multi channel version) */

  for( channel=0; channel<(cNmBasicNrOfChannels); channel++ )
  {    
    /* ESCAN00012097: add assertions to check the generated tabels during initialization */
    /* ESCAN00025822: removed comparison to zero */
    NmBasicAssert( (cNmBasicInitObject < kCanNumberOfInitObjects), kNmBasicErrInitObjOutOfRange);

# if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) || defined(NMBASIC_BUSOFF_RECOV_EXTENDED) )
    NmBasicAssert( ( (cNmBasicBusOffRecTimer > 0) && (cNmBasicBusOffRecTimer <= 255) ), kNmBasicErrBusOffFastTimeOutOfRange);
# endif

# if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
    NmBasicAssert( ( (cNmBasicBusOffRecSlowTimer > 0) && (cNmBasicBusOffRecSlowTimer <= 255) ), kNmBasicErrBusOffSlowTimeOutOfRange);
    NmBasicAssert( ( (cNmBasicBusOffFastToSlowTimer > 0) && (cNmBasicBusOffFastToSlowTimer <= 255) ), kNmBasicErrBusOffFastSlowTimeOutOfRange);
    NmBasicAssert( ( (cNmBasicBusOffRecTimer <= cNmBasicBusOffRecSlowTimer) ), kNmBasicErrFastLargerSlowTime);
#  if defined(NMBASIC_ENABLE_BUSOFFREP_TIMER)
    NmBasicAssert( ( (cNmBasicBusOffRepairedTimer > 0) && (cNmBasicBusOffRepairedTimer <= 255)), kNmBasicErrBusOffRepTimeOutOfRange);
    NmBasicAssert( ( cNmBasicBusOffRepairedTimer > cNmBasicBusOffRecTimer ), kNmBasicErrBusOffRepairTimeTooSmall);
    NmBasicAssert( ( cNmBasicBusOffRepairedTimer > cNmBasicBusOffRecSlowTimer ), kNmBasicErrBusOffRepairTimeTooSmall);
#  endif
# endif


    /* intialize the node management */
# if( defined NMBASIC_ENABLE_CHANNEL_INDIRECTION )
    /* use indirection table to pass CAN channel as parameter to the init function */  /* ESCAN00014289 */
    NmBasicInit(NmBasicNmToCanIndirection[channel]);
# else
    NmBasicInit(NMBASIC_CHANNEL_NMPARA_ONLY);
# endif
  }
#else
  NmBasicInit(NMBASIC_CHANNEL_NMPARA_ONLY);
#endif
}


/****************************************************************************
| NAME:             NmBasicInit
| CALLED BY:        node management / application
| PRECONDITIONS:    The CAN interrupts must be disabled.
| INPUT PARAMETERS: indexed multi channel: network management channel
|                   single channel:        none
| RETURN VALUES:    none
| DESCRIPTION:      init node management
****************************************************************************/
void NmBasicInit(NMBASIC_CHANNEL_NMTYPE_ONLY)
{
#if defined ( NMBASIC_ENABLE_CHANNEL_INDIRECTION )  /* ESCAN00012094 */
  channel = NmBasicCanToNmIndirection[channel];
#endif

  /* initialize the state machine */
  bNmBasicState = NMBASIC_STATE_STOP;
  bNmBasicBusOffRequest = NMBASIC_STATE_NO_REQUEST;  /* ESCAN00015987 */

  bNmBasicStateRequest = NMBASIC_STATE_NO_REQUEST;

#if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) || defined(NMBASIC_BUSOFF_RECOV_EXTENDED) )
  /* initialize the BusOff recovery timer */
  bNmBasicBusOffRecTimer = 0x00;
#endif

#if defined NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED /* ESCAN00017908 */
  /* initialize the BusOff recovery timer */
  wNmBasicBusOffRecTimer = 0x00;
#endif

#if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
  /* initialize timer for changing from fast to slow BusOff recovery */
  bNmBasicBusOffRecFastSlowTimer = 0x00;

  /* initialize the flag to store, that the BusOff recovery time 'slow' should be used */
  bNmBasicBusOffRecSlowActive = cNmBasicBusOffSlowNotActive;

  /* initialize flag to store, that the change from fast to slow BusOff recovery was done */
  bNmBasicBusOffFastToSlowChange = cNmBasicBusOffFastToSlowNotDone;

# if defined(NMBASIC_ENABLE_BUSOFFREP_MSG) /* ESCAN00061225 */
  /* initialize the flag to store, that the BusOff repaired state is detected by a successful message transmission */
  bNmBasicBusOffRepaired = cNmBasicBusOffNotDetected;
# endif

#endif

#if defined(NMBASIC_ENABLE_BUSOFFREP_TIMER)
  /* initialize timer for distance to detect a repaired BusOff */
  bNmBasicBusOffRepairedTimer = 0x00;
#endif


  /* ESCAN00023008 */
#if defined(NMBASIC_BUSOFF_RECOV_IMMEDIAT)
/* not applicable for algo "immediate" */
#else
# if defined ( NMBASIC_ENABLE_EARLY_BUSOFF_REINIT )
  bNmBasicCanDrvIsBusOff = cNmBasicCanDrvInInitMode;
# endif
#endif

#if defined( C_ENABLE_MULTI_ECU_CONFIG )
# if (C_VERSION_REF_IMPLEMENTATION >= 0x150)
  /* check if channel is enabled in current identity: */
  if ( (CanChannelIdentityAssignment[NMBASIC_CHANNEL_CANPARA_ONLY] & V_ACTIVE_IDENTITY_MSK) != (tVIdentityMsk)0 )
# endif
#endif
  {
    /* set CAN driver to Tx offline mode */  /* ESCAN00012903 */
    CanOffline(NMBASIC_CHANNEL_CANPARA_ONLY);

# if defined( VGEN_ENABLE_DPM)
    /* The CAN controller must not be switched off when the current configured 
     * power management component is used. */
# else
    /* ... switch it off: */
    (void)CanStop(NMBASIC_CHANNEL_CANPARA_ONLY);
# endif

    /* switch transceiver off */
    (void)ApplNmBasicSwitchTransceiverOff(NMBASIC_CHANNEL_APPLPARA_ONLY);
  }
}


/****************************************************************************
| NAME:             NmBasicCanBusOff
| CALLED BY:        CAN driver
| PRECONDITIONS:    The node management must be initialized.
| INPUT PARAMETERS: indexed multi channel: network management channel
|                   single channel:        none
| RETURN VALUES:    none
| DESCRIPTION:      busoff event
****************************************************************************/
void NmBasicCanBusOff(NMBASIC_CHANNEL_CANTYPE_ONLY)
{
#if defined ( NMBASIC_ENABLE_CHANNEL_INDIRECTION )  /* ESCAN00016466 */
#else
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  /* ESCAN00051839 adapted dummy statement */
#    if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)channel;  /* PRQA S 3112 */ /* the channel parameter is not used in this function */
#    endif
#  endif
#endif

#if defined ( NMBASIC_ENABLE_CHANNEL_INDIRECTION )  /* ESCAN00012094 */
  channel = NmBasicCanToNmIndirection[channel];
#endif

  /* Prevent calls of CanOffline() and CanResetBusOffStart() in the states NMBASIC_STATE_STOP, NMBASIC_STATE_TX_ERROR
   * and NMBASIC_STATE_POWER_OFF because CanOffline() was already called during the transition to one of these states.
   * Otherwise a call of CanResetBusOffStart()could cause a call of CanInit() which clears the stop state of the CAN controller.
   * Do not set the BusOff flag bNmBasicBusOffRequest in these states to prevent a BusOffEnd handling when switching back to 
   * state NMBASIC_STATE_RUN (ESCAN00018548).
   */
  if( bNmBasicState == NMBASIC_STATE_RUN )
  {    
    /* set CAN driver to Tx offline mode */
    CanOffline(NMBASIC_CHANNEL_CANPARA_ONLY);

    /* run CAN driver handling for BusOff start */
#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
    /* makros must be encapsulated in this way */
    CanResetBusOffStart(NMBASIC_CHANNEL_CANPARA_ONLY, cNmBasicInitObject);
#else
    CanResetBusOffStart(cNmBasicInitObject);
#endif


    /* ESCAN00023008 */
#if defined(NMBASIC_BUSOFF_RECOV_IMMEDIAT)
    /* not applicable for algo "immediate" */
#else
# if defined ( NMBASIC_ENABLE_EARLY_BUSOFF_REINIT )
    bNmBasicCanDrvIsBusOff = cNmBasicCanDrvIsBusOff;
# endif
#endif

#if( defined(NMBASIC_BUSOFF_RECOV_EXTENDED) )
# if defined(NMBASIC_ENABLE_BUSOFFREP_MSG) /* ESCAN00061225 */
    /* ESCAN00019593 */
    /* prepare variable for 'BusOff repaired' detection and ... */
    bNmBasicBusOffRepaired = cNmBasicBusOffNotRepaired;
# endif

# if defined(NMBASIC_ENABLE_BUSOFFREP_TIMER)
    /* ... (re-)start the timer for 'BusOff repaired' detection. Plus 1 because the timer is decremented
       directly in the beginning of the task in order not to lose one task cycle time. */
    bNmBasicBusOffRepairedTimer = (vuint8) cNmBasicBusOffRepairedTimer + 1; /* ESCAN00016667 */
# endif
#endif

    /* store requested NM state */
    bNmBasicBusOffRequest = NMBASIC_STATE_BUSOFF;  /* ESCAN00015987 */
  }
    
  /* notify application about BusOff event */
  ApplNmBasicBusOffStart(NMBASIC_CHANNEL_APPLPARA_ONLY);


}


/****************************************************************************
| NAME:             NmBasicStart
| CALLED BY:        application
| PRECONDITIONS:    The node management must be initialized.
| INPUT PARAMETERS: indexed multi channel: network management channel
|                   single channel:        none
| RETURN VALUES:    none
| DESCRIPTION:      set a flag to start the node management in the cyclic task
****************************************************************************/
void NmBasicStart(NMBASIC_CHANNEL_NMTYPE_ONLY)
{
# if defined ( NMBASIC_ENABLE_CHANNEL_INDIRECTION )  /* ESCAN00012094 */
  channel = NmBasicCanToNmIndirection[channel];
# endif

# if defined( C_ENABLE_MULTI_ECU_CONFIG )
#  if (C_VERSION_REF_IMPLEMENTATION >= 0x150)
  NmBasicAssert( ((CanChannelIdentityAssignment[NMBASIC_CHANNEL_CANPARA_ONLY] & V_ACTIVE_IDENTITY_MSK) != (tVIdentityMsk)0 ), kNmBasicErrWrongChannelHandle );
#  endif
# endif


  /* ESCAN00016211 */

  /* store the requested state to handle on cyclic task */
  bNmBasicStateRequest = NMBASIC_STATE_RUN;
}


/****************************************************************************
| NAME:             NmBasicStop
| CALLED BY:        application
| PRECONDITIONS:    The node management must be initialized.
| INPUT PARAMETERS: indexed multi channel: network management channel
|                   single channel:        none
| RETURN VALUES:    none
| DESCRIPTION:      set a flag to stop the node management in the cyclic task
****************************************************************************/
void NmBasicStop(NMBASIC_CHANNEL_NMTYPE_ONLY)
{
# if defined ( NMBASIC_ENABLE_CHANNEL_INDIRECTION )  /* ESCAN00012094 */
  channel = NmBasicCanToNmIndirection[channel];
# endif

# if defined( C_ENABLE_MULTI_ECU_CONFIG )
#  if (C_VERSION_REF_IMPLEMENTATION >= 0x150)
  NmBasicAssert( ((CanChannelIdentityAssignment[NMBASIC_CHANNEL_CANPARA_ONLY] & V_ACTIVE_IDENTITY_MSK) != (tVIdentityMsk)0 ), kNmBasicErrWrongChannelHandle );
#  endif
# endif

  /* ESCAN00015987, ESCAN00016211: some code deleted or moved to cyclic task */

  /* store the requested state to handle on cyclic task */
  bNmBasicStateRequest = NMBASIC_STATE_STOP;
}


/****************************************************************************
| NAME:             NmBasicGetNetState
| CALLED BY:        application
| PRECONDITIONS:    The node management must be initialized.
| INPUT PARAMETERS: indexed multi channel: network management channel
|                   single channel:        none
| RETURN VALUES:    current state of the NM; possible values:
|                   NMBASIC_STATE_STOP
|                   NMBASIC_STATE_RUN
|                   additional for the 'delayed' and 'extended' algorithm:
|                   NMBASIC_STATE_BUSOFF
|                   additional for the feature 'Tx observation':
|                   NMBASIC_STATE_TX_ERROR
| DESCRIPTION:      returns the current state of the NM
****************************************************************************/
vuint8 NmBasicGetNetState(NMBASIC_CHANNEL_NMTYPE_ONLY)
{
#if defined ( NMBASIC_ENABLE_CHANNEL_INDIRECTION )  /* ESCAN00012094 */
  channel = NmBasicCanToNmIndirection[channel];
#endif

  return bNmBasicState;
}

#if( ((defined NMBASIC_BUSOFF_RECOV_EXTENDED) && ((defined NMBASIC_ENABLE_BUSOFFREP_MSG) )) )
/*****************************************************************************************************
| NAME:             ApplCanInit
| CALLED BY:        CAN driver
| PRECONDITIONS:    initialization
| INPUT PARAMETERS: CAN_CHANNEL_CANTYPE_FIRST = defined to nothing in single channel system
|                   CAN_CHANNEL_CANTYPE_FIRST = channel number in multi channel system
|                   txHwObjectFirstUsed = first HW object used by CAN driver for transmission
|                   txHwObjectFirstUnused = first HW object unused by CAN driver for transmission
| RETURN VALUE:     none
| DESCRIPTION:      In case 'BusOff repaired' is detected by a successful message transmission,
|                   the message transmission is observed by the so called TX_OBSERVE mechanism, 
|                   to which this CAN driver application callback function belongs.
|                   This function is called during initialization and it is empty, because nothing 
|                   is enabled the Tx message timeout timer is cleared to restart the observation
|                   after initialization.
|*****************************************************************************************************/
void ApplCanInit( CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle txHwObjectFirstUsed, CanObjectHandle txHwObjectFirstUnused )
{
# if defined ( NMBASIC_ENABLE_CHANNEL_INDIRECTION )  /* ESCAN00012094 */
  channel = NmBasicCanToNmIndirection[channel];
# endif

# if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  /* ESCAN00051839 adapted dummy statement */
  (void)txHwObjectFirstUsed;  /* PRQA S 3112 */ /* parameter is not used in this function */
  (void)txHwObjectFirstUnused;  /* PRQA S 3112 */ /* parameter is not used in this function */

#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  /* ESCAN00051839 adapted dummy statement */
  (void)channel;  /* PRQA S 3112 */ /* the channel parameter is not used in this function */
#  endif
# endif

}
#endif


#if( ((defined NMBASIC_BUSOFF_RECOV_EXTENDED) && (defined NMBASIC_ENABLE_BUSOFFREP_MSG) ) )
/************************************************************************
| NAME:             ApplCanTxObjStart
| CALLED BY:        CAN driver
| PRECONDITIONS:    initialization
| INPUT PARAMETERS: CAN_CHANNEL_CANTYPE_FIRST = defined to nothing in single channel system
|                   CAN_CHANNEL_CANTYPE_FIRST = channel number in multi channel system
|                   txHwObject = HW object used by CAN driver for current transmission
| RETURN VALUE:     none
| DESCRIPTION:      In case 'BusOff repaired' is detected by a successful message transmission,
|                   the message transmission is observed by the so called TX_OBSERVE mechanism, 
|                   to which this CAN driver application callback function belongs.
|                   This function is called when a message a message transmission is started.
|                   If the Tx observation is enabled the Tx message timeout timer is set to the
|                   configured value to start the timeout observation.
|*************************************************************************/
void ApplCanTxObjStart( CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle txHwObject )
{
# if defined ( NMBASIC_ENABLE_CHANNEL_INDIRECTION )  /* ESCAN00012094 */
  channel = NmBasicCanToNmIndirection[channel];
# endif

# if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  /* ESCAN00051839 adapted dummy statement */
  (void)txHwObject;  /* PRQA S 3112 */ /* parameter is not used in this function */

#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  /* ESCAN00051839 adapted dummy statement */
  (void)channel;  /* PRQA S 3112 */ /* the channel parameter is not used in this function */
#  endif
# endif


}
#endif


#if( ((defined NMBASIC_BUSOFF_RECOV_EXTENDED) && (defined NMBASIC_ENABLE_BUSOFFREP_MSG) ) )
/************************************************************************************************
| NAME:             ApplCanTxObjConfirmed
| CALLED BY:        CAN driver
| PRECONDITIONS:    initialization
| INPUT PARAMETERS: CAN_CHANNEL_CANTYPE_FIRST = defined to nothing in single channel system
|                   CAN_CHANNEL_CANTYPE_FIRST = channel number in multi channel system
|                   txHwObject = HW object used by CAN driver for current transmission
| RETURN VALUE:     none
| DESCRIPTION:      In case 'BusOff repaired' is detected by a successful message transmission,
|                   the message transmission is observed by the so called TX_OBSERVE mechanism, 
|                   to which this CAN driver application callback function belongs.
|                   This function is called in the Tx confirmation and a flag is set to store 
|                   the successful Tx request.
|************************************************************************************************/
void ApplCanTxObjConfirmed( CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle txHwObject )
{
# if defined ( NMBASIC_ENABLE_CHANNEL_INDIRECTION )  /* ESCAN00012094 */
  channel = NmBasicCanToNmIndirection[channel];
# endif

# if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  /* ESCAN00051839 adapted dummy statement */
  (void)txHwObject;  /* PRQA S 3112 */ /* parameter is not used in this function */
# endif

# if defined ( C_MULTIPLE_RECEIVE_CHANNEL )  /* ESCAN00016556 */
  /* check if the message transmission was done on an NMbasic channel */
  /* variabel 'channel' is an NM channel in this configuration */
#  if( (cNmBasicNrOfChannels == 1) && (!defined NMBASIC_ENABLE_INDEXED_NM) )
  if( channel == NMBASIC_CAN_CHANNEL )
#  else
  if( (channel != (CanChannelHandle)0xFF) && (channel < cNmBasicNrOfChannels ) )
#  endif
# endif
  {



# if( (defined NMBASIC_BUSOFF_RECOV_EXTENDED) && (defined NMBASIC_ENABLE_BUSOFFREP_MSG) )
    /* 'BusOff repaired' is detected by a successful message transmission ... */
    if(bNmBasicBusOffRepaired == cNmBasicBusOffNotRepaired)
    {
      /* ... clear this event */
      bNmBasicBusOffRepaired = cNmBasicBusOffNotDetected;

      /* reset timer for changing from fast to slow recovery */
      bNmBasicBusOffRecFastSlowTimer = 0x00;

      /* reset BusOff recovery time from 'slow' to 'fast' */
      bNmBasicBusOffRecSlowActive = cNmBasicBusOffSlowNotActive;

      /* 'BusOff repaired' is detected => reset timer for change from fast to slow BusOff */
      bNmBasicBusOffFastToSlowChange = cNmBasicBusOffFastToSlowNotDone;


      /* repeated BusOff detection has ended => inform application */  /* ESCAN00012156 */
      ApplNmBasicBusOffRestart(NMBASIC_CHANNEL_APPLPARA_ONLY);
    }
# endif
  }
}
#endif









/****************************************************************************
| NAME:             NmBasicTask
| CALLED BY:        application
| PRECONDITIONS:    The node management must be initialized.
| INPUT PARAMETERS: indexed multi channel: network management channel
|                   single channel:        none
| RETURN VALUES:    none
| DESCRIPTION:      node management handling
****************************************************************************/
void NmBasicTask(NMBASIC_CHANNEL_NMTYPE_ONLY)
{
#if defined ( NMBASIC_ENABLE_CHANNEL_INDIRECTION )  /* ESCAN00012094 */
  channel = NmBasicCanToNmIndirection[channel];
#endif

#if defined( C_ENABLE_MULTI_ECU_CONFIG )
# if (C_VERSION_REF_IMPLEMENTATION >= 0x150)
  NmBasicAssert( ((CanChannelIdentityAssignment[NMBASIC_CHANNEL_CANPARA_ONLY] & V_ACTIVE_IDENTITY_MSK) != (tVIdentityMsk)0 ), kNmBasicErrWrongChannelHandle );
# endif
#endif

  /* disable global interrupt for data and state handling consistency */
  CanInterruptDisable();

  /* ESCAN00023008 */
#if defined(NMBASIC_BUSOFF_RECOV_IMMEDIAT)
  /* algorithm "immediately" reinitializes the CAN controller anyway in the very next task after a busOff */
#else
# if defined ( NMBASIC_ENABLE_EARLY_BUSOFF_REINIT )
  if ( bNmBasicCanDrvIsBusOff == cNmBasicCanDrvIsBusOff )
  {
     /* check if DrvCan is ready for re-init: */
    if( CanGetDriverStatus(NMBASIC_CHANNEL_CANPARA_ONLY) != kCanDriverBusoff )
    {
      bNmBasicCanDrvIsBusOff = cNmBasicCanDrvInInitMode;

#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
      CanResetBusOffEnd(NMBASIC_CHANNEL_CANPARA_ONLY, cNmBasicInitObject);
#  else
      CanResetBusOffEnd(cNmBasicInitObject);
#  endif
    }
  }
# endif
#endif

#if defined NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED /* ESCAN00017908 */
  /* decrement BusOff recovery timer */
  if ( wNmBasicBusOffRecTimer != 0x00)
  {
    wNmBasicBusOffRecTimer--;
  }
#endif

#if( defined(NMBASIC_BUSOFF_RECOV_EXTENDED) )
  /* timer handling for change from fast to slow BusOff recovery time */
  if( bNmBasicBusOffRecFastSlowTimer != 0x00 )
  {
    /* decrement the timer */
    bNmBasicBusOffRecFastSlowTimer--;

    if( bNmBasicBusOffRecFastSlowTimer == 0x00 )
    {
      /* the timer expired => set a flag, that from now on the slow BusOff recovery time has to be used */
      bNmBasicBusOffRecSlowActive = cNmBasicBusOffSlowActive;
    }
  }
#endif


#if defined(NMBASIC_BUSOFF_RECOV_EXTENDED)
# if defined(NMBASIC_ENABLE_BUSOFFREP_TIMER)
  /* ESCAN00019593 */

  /* timer handling to detect the 'BusOff repaired' condition */
  if(bNmBasicBusOffRepairedTimer != 0x00)
  {
    /* decrement the timer */
    bNmBasicBusOffRepairedTimer--;

    if( bNmBasicBusOffRepairedTimer == 0x00 )
    { 
# if defined(NMBASIC_ENABLE_BUSOFFREP_MSG) /* ESCAN00061225 */
      /* reset the variable for next detection */
      bNmBasicBusOffRepaired = cNmBasicBusOffNotDetected;
# endif

      /* 'BusOff repaired' is detected => reset all timer for next 'first' BusOff */
      /* bNmBasicBusOffRecTimer = 0; => not necessary because the BusOff recovery 
      *  timer runs in state BusOff and the 'BusOff repaired' timer in state RUN, only. */
      bNmBasicBusOffRecFastSlowTimer = 0x00;
      bNmBasicBusOffRecSlowActive = cNmBasicBusOffSlowNotActive;
      bNmBasicBusOffFastToSlowChange = cNmBasicBusOffFastToSlowNotDone;

      /* repeated BusOff detection has ended => inform application */
      ApplNmBasicBusOffRestart(NMBASIC_CHANNEL_APPLPARA_ONLY);
    }
  }
# endif
#endif


  /* do the NM state handling */
  switch(bNmBasicState)
  {
/* -------------------- case NMBASIC_STATE_STOP -------------------- */
    case NMBASIC_STATE_STOP:

      if(bNmBasicStateRequest == NMBASIC_STATE_RUN)
      {
        /* new state is requested */

        /* switch transceiver on */
        ApplNmBasicSwitchTransceiverOn(NMBASIC_CHANNEL_APPLPARA_ONLY);

# if defined( VGEN_ENABLE_DPM)
        /* The CAN controller must not be switched on when the current configured 
        *  power management component is used. */
# else
        /* switch on CAN controller */
        (void)CanStart(NMBASIC_CHANNEL_CANPARA_ONLY);
# endif

        /* set CAN driver to Tx online mode */
        CanOnline(NMBASIC_CHANNEL_CANPARA_ONLY);

        /* notify application on enabling communication */
        ApplNmBasicEnabledCom(NMBASIC_CHANNEL_APPLPARA_ONLY);


        /* change into new state */
        bNmBasicState = NMBASIC_STATE_RUN;

        /* clear the state request for next further usage */  /* ESCAN00016211 */
        bNmBasicStateRequest = NMBASIC_STATE_NO_REQUEST;
      }
      break;

/* -------------------- case NMBASIC_STATE_RUN -------------------- */
    case NMBASIC_STATE_RUN:


      /* first: perform the BusOff handling */  /* ESCAN00016211 */

      /* BusOffEnd handling has to be done on task level */
      if( bNmBasicBusOffRequest == NMBASIC_STATE_BUSOFF )
      {
#if defined(NMBASIC_BUSOFF_RECOV_IMMEDIAT)
        /* immediate BusOff, do the BusOffEnd handling at once without changing the NM state */

        /* run CAN driver handling for BusOff end */
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
        CanResetBusOffEnd(NMBASIC_CHANNEL_CANPARA_ONLY, cNmBasicInitObject);
# else
        CanResetBusOffEnd(cNmBasicInitObject);
# endif

        /* set CAN driver to Tx online mode */
        CanOnline(NMBASIC_CHANNEL_CANPARA_ONLY);

        /* notify application on end of BusOff recovery algorithm */
        ApplNmBasicBusOffEnd(NMBASIC_CHANNEL_APPLPARA_ONLY);
#endif
#if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) )
        /* BusOff is detected => prepare BusOff handling with setting the delay timer */

        /* start BusOff recovery timer for normal recovery */
        bNmBasicBusOffRecTimer = cNmBasicBusOffRecTimer;

        /* change into new state */
        bNmBasicState = NMBASIC_STATE_BUSOFF;
#endif


#if( defined(NMBASIC_BUSOFF_RECOV_EXTENDED) )
        if(bNmBasicBusOffRecSlowActive == cNmBasicBusOffSlowNotActive)
        {
          /* start BusOff recovery timer for fast recovery */
          bNmBasicBusOffRecTimer = (vuint8) cNmBasicBusOffRecTimer; /* ESCAN00016667 */

            /* if it is the first BusOff ... */
            if( bNmBasicBusOffRecFastSlowTimer == 0x00 )
            {
              /* ... start the timer to detect the change from fast to slow recovery */
              bNmBasicBusOffRecFastSlowTimer = (vuint8) cNmBasicBusOffFastToSlowTimer; /* ESCAN00016667 */
            }
        }
        else
        {
          /* start BusOff recovery timer for slow recovery */
          bNmBasicBusOffRecTimer = (vuint8) cNmBasicBusOffRecSlowTimer; /* ESCAN00016667 */

          /* check, if BusOff callback was done already */
          if(bNmBasicBusOffFastToSlowChange == cNmBasicBusOffFastToSlowNotDone)
          {
            /* prevent further calls */
            bNmBasicBusOffFastToSlowChange = cNmBasicBusOffFastToSlowDone;

            /* inform application about change from fast to slow recovery */
            ApplNmBasicFirstBusOffSlow(NMBASIC_CHANNEL_APPLPARA_ONLY);
          }
        }

        /* change into new state */
        bNmBasicState = NMBASIC_STATE_BUSOFF;
#endif

#if defined NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED /* ESCAN00017908 */
  /* check BusOff recovery timer */
        if ( wNmBasicBusOffRecTimer == 0x00)
        {
          /* we are in state 'RUN', a BusOff occurred and the BusOff recovery timer has expired:
             this indicates the first BusOff or the first BusOff after a successful recovered BusOff.
             Do the BusOff recovery immediately and stay in state 'RUN': */

        /* ESCAN00023008 */
# if defined ( NMBASIC_ENABLE_EARLY_BUSOFF_REINIT )
          if ( bNmBasicCanDrvIsBusOff != cNmBasicCanDrvInInitMode )
          {
            /* CAN driver is not yet in init mode but recovery time expired.
                Reset flag and reinitialize anyway: */
            bNmBasicCanDrvIsBusOff = cNmBasicCanDrvInInitMode;
# else
          {
# endif

            /* run CAN driver handling for BusOff end */
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
            CanResetBusOffEnd(NMBASIC_CHANNEL_CANPARA_ONLY, cNmBasicInitObject);
# else
            CanResetBusOffEnd(cNmBasicInitObject);
# endif
          }

          /* set CAN driver to Tx online mode */
          CanOnline(NMBASIC_CHANNEL_CANPARA_ONLY);

          /* notify application on end of BusOff recovery algorithm */
          ApplNmBasicBusOffEnd(NMBASIC_CHANNEL_APPLPARA_ONLY);        
        }
        else
        {
          /* we are in state 'RUN', a BusOff occurred and the BusOff recovery timer has NOT expired:
             this indicates that a BusOff re-occurred: */
  
          /* and switch to state 'BusOff'*/ 
          bNmBasicState = NMBASIC_STATE_BUSOFF;
        }

        /* (re-)start the BusOff recovery timer */
        wNmBasicBusOffRecTimer = cNmBasicBusOffRecTimer;

#endif
        /* clear the state request for next further usage */
        bNmBasicBusOffRequest = NMBASIC_STATE_NO_REQUEST;
      }

      /* second: perform the state change into STOP state */  /* ESCAN00016211 */

      if( bNmBasicStateRequest == NMBASIC_STATE_STOP )
      {
# if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) || defined(NMBASIC_BUSOFF_RECOV_EXTENDED) )
        /* if a BusOff and a STOP request occurred in the same task cycle ... */
        if(bNmBasicState == NMBASIC_STATE_BUSOFF)
        {
          /* ... the BusOff has to be aborted */
          NmBasicDoBusOffAbort(NMBASIC_CHANNEL_NMPARA_ONLY);
        }
# endif
        
        /* do all necessary actions for the NM stop handling */
        NmBasicDoTheStopHandling(NMBASIC_CHANNEL_NMPARA_ONLY);

        /* change into new state */
        bNmBasicState = NMBASIC_STATE_STOP;

        /* clear the state request for next further usage */
        bNmBasicStateRequest = NMBASIC_STATE_NO_REQUEST;
      }

      break;

#if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) || defined(NMBASIC_BUSOFF_RECOV_EXTENDED) || defined(NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED) )
/* -------------------- case NMBASIC_STATE_BUSOFF -------------------- */
    case NMBASIC_STATE_BUSOFF:
      /* check if a current BusOff recovery has to be aborted */
      if(bNmBasicStateRequest == NMBASIC_STATE_STOP)
      {
        /* request to stop NM handling -> abort the BusOff handling */
        NmBasicDoBusOffAbort(NMBASIC_CHANNEL_NMPARA_ONLY);

        /* do all necessary actions for the NM stop handling */  /* ESCAN00016211 */
        NmBasicDoTheStopHandling(NMBASIC_CHANNEL_NMPARA_ONLY);

        /* change into new state */
        bNmBasicState = NMBASIC_STATE_STOP;

        /* clear the state request for next further usage */
        bNmBasicStateRequest = NMBASIC_STATE_NO_REQUEST;
      }
      else
      {
        /* ---------------------------------------------------------------- */
        /* NM is not requested to switch off => do 'normal' BusOff handling */
        /* ---------------------------------------------------------------- */
# if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) || defined(NMBASIC_BUSOFF_RECOV_EXTENDED))
        /* check BusOff recovery timer activation */
        if(bNmBasicBusOffRecTimer != 0x00)
        {
          /* decrement BusOff recovery timer */
          bNmBasicBusOffRecTimer--;

          /* check BusOff recovery timer expiration */
          if( bNmBasicBusOffRecTimer == 0x00)
          {
# elif defined(NMBASIC_BUSOFF_RECOV_TIME_SUPERVISED) /* ESCAN00017908 */
          /* wait until BusOff recovery timer expires */
          if(wNmBasicBusOffRecTimer == 0x00)
          {          
# else
#  error "Please select a valid BusOff algorithm!"
# endif
            /* BusOff recovery time is expired */
  
            /* ESCAN00023008 */
# if defined ( NMBASIC_ENABLE_EARLY_BUSOFF_REINIT )
            if ( bNmBasicCanDrvIsBusOff != cNmBasicCanDrvInInitMode )
            {
              /* CAN driver is not yet in init mode but recovery time expired.
                 Reset flag and reinitialize anyway: */
              bNmBasicCanDrvIsBusOff = cNmBasicCanDrvInInitMode;
# else
            {
# endif

              /* run CAN driver handling for BusOff end */
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
              /* makros must be encapsulated in this way */
              CanResetBusOffEnd(NMBASIC_CHANNEL_CANPARA_ONLY, cNmBasicInitObject);
# else
              CanResetBusOffEnd(cNmBasicInitObject);
# endif
            }

            /* set CAN driver to Tx online mode */
            CanOnline(NMBASIC_CHANNEL_CANPARA_ONLY);

            /* notify application that BusOff recovery algorithm has finished */
            ApplNmBasicBusOffEnd(NMBASIC_CHANNEL_APPLPARA_ONLY);

            /* change into new state */
            bNmBasicState = NMBASIC_STATE_RUN;
          }
# if( defined(NMBASIC_BUSOFF_RECOV_DELAYED) || defined(NMBASIC_BUSOFF_RECOV_EXTENDED))
        }
# endif
      }
      /* change from state NMBASIC_STATE_BUSOFF to state NMBASIC_STATE_RUN is just done due to 
      *  an expired timer (see some lines above) => no further if/else clause necessary here */

      break;
#endif

 

/* -------------------- default -------------------- */
    default:
      /* should never be reached because NM state is set during initialization and 
      *  this cyclic function is only allowed to be called after initialization! */
      NmBasicAssertAlways(kNmBasicErrStateUndefined);
      break;
  }

  /* restore global interrupt */
  CanInterruptRestore();
}




