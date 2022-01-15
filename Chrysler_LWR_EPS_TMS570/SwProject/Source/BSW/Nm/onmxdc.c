/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */



/******************************************************************************
|   File Name: onmxdc.c
| Description: OSEK NM Extensions Module File
|
|------------------------------------------------------------------------------
|               C O P Y R I G H T
|------------------------------------------------------------------------------
| Copyright (c) by Vector Informatik GmbH.                 All rights reserved.
|
| This software is copyright protected and proprietary
| to Vector Informatik GmbH. Vector Informatik GmbH
| grants to you only those rights as set out in the
| license conditions. All other rights remain with
| Vector Informatik GmbH.
|
|------------------------------------------------------------------------------
|              A U T H O R   I D E N T I T Y
|------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     --------------------------------------
| Js           Bernd Jesse               Vector Informatik GmbH
| Fmi          Michael Frank             Vector Informatik GmbH
| vismas       Markus Schwarz            Vector Informatik GmbH
|------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|------------------------------------------------------------------------------
| Date        Version  Author  Description
| ----------  -------  ------  -------------------------------------------------
| 2003-12-09  1.00.00  Js      ESCAN00007219: Introduction
| 2004-01-30  1.01.00  Fmi     Optimization
| 2004-02-13  1.02.00  Rn      ESCAN00007561: Include v_inc.h instead of can_inc.h (only GENy)
| 2004-02-27  1.03.00  Fmi     ESCAN00007747: Move call to NmGetSendUdProtocolCommand()
|                                             from Tx path to Rx path in OnmExtTask()
| 2004-04-08  1.04.00  Rn      ESCAN00008154: Value of NetSleepInd not consistent in state cansleep
| 2004-07-19  1.05.00  Fmi     ESCAN00008836: Copying of User Data bytes from receive to send buffer
|                                             moved from NmPrecopy to OnmExtTask
|                              ESCAN00008886: Do not use channel indirection in case of NM internal call
| 2004-08-04  1.06.00  Fmi     ESCAN00008995: No changes
|                              ESCAN00009043: Changes for MISRA conformance
| 2004-09-01  1.07.00  Fmi     ESCAN00009195: Add support for UD Broadcast sender address retrieval
|                              ESCAN00009361: Correct reception of UD Ring Broadcasts
| 2004-09-29  1.08.00  Fmi     ESCAN00009449: New naming conventions
| 2004-12-01  1.09.00  Fmi     ESCAN00009043: Changes for MISRA conformance
| 2005-01-13                   ESCAN00010792: Remove error notification for Ring Broadcasts
| 2005-05-20                   ESCAN00012334: Changed interface of OnmExtPrecopy
| 2005-07-06                   ESCAN00012703: Insert comments for different resource categories
| 2005-08-12  1.10.00  Fmi     ESCAN00012703: Insert comments for different resource categories
| 2006-12-06  1.11.00  Fmi     ESCAN00018635: Usage of module without Userdata
| 2007-12-11  1.12.00  Fmi     ESCAN00023642: adapted prototype of OnmExtPrecopy to match memory qualifiers
| 2008-02-14  1.13.00  Fmi     ESCAN00024575: Invalid pointer conversion from far to near when calling NmUdReadRecvData
| 2008-03-14  1.14.00  Fmi     ESCAN00025352: Remove include of nm_cfg.h in onmxdc.h
| 2008-08-22  1.15.00  vismas  ESCAN00029400: Add support of AUTOSAR environment
| 2008-12-16  1.15.01  vismas  ESCAN00031536: Added dummy statement for msgType to avoid compiler warnings
|*****************************************************************************/

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "v_inc.h"
#include "onmxdc.h"

/*****************************************************************************/
/* Version check                                                             */
/*****************************************************************************/
#if ( NM_DIROSEKEXT_DC_VERSION != 0x0115 )
  #error "Header and Source file are inconsistent!"
#endif
#if ( NM_DIROSEKEXT_DC_RELEASE_VERSION != 0x01 )
  #error "Different versions of Release in Header and Source used!"
#endif

#if !defined (NM_DIROSEK_VERSION)
  #error "OSEK NM version is not compatible with this module."
#endif

/*****************************************************************************/
/* Version information                                                       */
/*****************************************************************************/
/* ROM CATEGORY 4 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kOnmExtMainVersion    = (vuint8)(NM_DIROSEKEXT_DC_VERSION >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kOnmExtSubVersion     = (vuint8)(NM_DIROSEKEXT_DC_VERSION & 0xFF);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kOnmExtReleaseVersion = (vuint8)(NM_DIROSEKEXT_DC_RELEASE_VERSION);
/* ROM CATEGORY 4 END */

/*****************************************************************************/
/* Plausibility check of switches                                            */
/*****************************************************************************/
#if !defined ( NM_ENABLE_USERDATA_ACCESS ) && \
( \
 defined ( NM_ENABLE_SEND_ALIVE_BROADCAST )    || \
 defined ( NM_ENABLE_RECEIVE_ALIVE_BROADCAST ) || \
 defined ( NM_ENABLE_SEND_RING_BROADCAST )     || \
 defined ( NM_ENABLE_RECEIVE_RING_BROADCAST )  || \
 defined ( NM_ENABLE_SEND_RING_DATA )          || \
 defined ( NM_ENABLE_RECEIVE_RING_DATA ) \
)
  #error "NM_ENABLE_USERDATA_ACCESS not set"
#endif

/*****************************************************************************/
/* Timing Measurement Module                                                 */
/*****************************************************************************/
#if defined ( TIMING_MEASUREMENT )
#else
  #if defined ( StartMeasure )
  #else
    #define StartMeasure(i)
  #endif

  #if defined ( StopMeasure )
  #else
    #define StopMeasure(i)
  #endif
#endif

/*****************************************************************************/
/* Defines                                                                   */
/*****************************************************************************/

/* multi channel can driver */
#if defined ( C_SINGLE_RECEIVE_BUFFER ) || defined ( C_MULTIPLE_RECEIVE_BUFFER )
 #if defined ( NM_CAN_CHANNEL )
  #if ( NM_CAN_CHANNEL == 0 )
    #define CanInterruptDisable    CanInterruptDisable_0
    #define CanInterruptRestore    CanInterruptRestore_0
  #endif /* #if ( NM_CAN_CHANNEL == 0 ) */
  #if ( NM_CAN_CHANNEL == 1 )
    #define CanInterruptDisable    CanInterruptDisable_1
    #define CanInterruptRestore    CanInterruptRestore_1
  #endif /* #if ( NM_CAN_CHANNEL == 1 ) */
  #if ( NM_CAN_CHANNEL == 2 )
    #define CanInterruptDisable    CanInterruptDisable_2
    #define CanInterruptRestore    CanInterruptRestore_2
  #endif /* #if ( NM_CAN_CHANNEL == 2 ) */
  #if ( NM_CAN_CHANNEL == 3 )
    #define CanInterruptDisable    CanInterruptDisable_3
    #define CanInterruptRestore    CanInterruptRestore_3
  #endif /* #if ( NM_CAN_CHANNEL == 3 ) */
  #if ( NM_CAN_CHANNEL == 4 )
    #define CanInterruptDisable    CanInterruptDisable_4
    #define CanInterruptRestore    CanInterruptRestore_4
  #endif /* #if ( NM_CAN_CHANNEL == 4 ) */
 #endif /* defined ( NM_CAN_CHANNEL ) */
#endif /* defined ( C_SINGLE_RECEIVE_BUFFER ) || defined ( C_MULTIPLE_RECEIVE_BUFFER ) */





#define UD_DATA_INIT                     ((vuint8)0xFF)  /* User Data Init Pattern */

/* User data protocol byte bit masks */
#define UD_MASK_PART1_BROADCAST          ((vuint8)0x00)  /* 00 bin */
#define UD_MASK_PART1_RING_A             ((vuint8)0x01)  /* 01 bin */
#define UD_MASK_PART1_RING_B             ((vuint8)0x02)  /* 10 bin */
#define UD_MASK_PART1_NOT_USED           ((vuint8)0x03)  /* 11 bin */
#define UD_MASK_PART1                    ((vuint8)0x38)  /* Part 1 Bits */
#define UD_MASK_CLEAR_PART1              ((vuint8)0xC7)  /* Clear Part 1 Bits */
#define UD_MASK_PART2                    ((vuint8)0x07)  /* Part 2 Bits */
#define UD_MASK_CLEAR_PART2              ((vuint8)0xF8)  /* Clear Part 2 Bits */
#define UD_MASK_PART1_PART2              ((vuint8)0x3F)  /* Part 1 and 2 Bits */

/* User data resource types */
#define UD_RES_PROTECTED_RING_A          ((vuint8)0x01)  /* 000001 bin */
#define UD_RES_PROTECTED_RING_B          ((vuint8)0x02)  /* 000010 bin */
#define UD_RES_BROADCAST                 ((vuint8)0x04)  /* 000100 bin */
#define UD_RES_UNPROTECTED_RING_A        ((vuint8)0x05)  /* 000101 bin */
#define UD_RES_UNPROTECTED_RING_B        ((vuint8)0x06)  /* 000110 bin */
#define UD_RES_FREE                      ((vuint8)0x3F)  /* 111111 bin */


/*****************************************************************************/
/* Data types / enumerations                                                 */
/*****************************************************************************/

#if defined ( NM_ENABLE_GW_MULTI_NM ) || defined ( NM_ENABLE_USERDATA_ACCESS )

typedef union
{
  vuint8 c[2];

  #if defined ( C_CPUTYPE_BITORDER_MSB2LSB )
  struct
  {
    vbittype    b_UdRingResourceRequested           :1;
    vbittype    b_UdApplIndRingRes                  :1;
    vbittype    b_UdMasterLastRxRingA               :1;
    vbittype    b_UdApplSendBroadcastRequested      :1;
    vbittype    b_UdApplSendRingRequested           :1;
    vbittype    b_StateUDMaster                     :1;
    vbittype    b_StateNetSleepInd                  :1;
    vbittype    b_PreNetSleepInd                    :1;

    vbittype    b_Dummy                             :1;
    vbittype    b_UdSendModifiedRingDataRequested   :1;
    vbittype    b_UdApplConfBroadcast               :1;
    vbittype    b_UdSendRingAllowed                 :1;
    vbittype    b_UdResourceUsed                    :1;
    vbittype    b_UdUsedBy5ByteResource             :1;
    vbittype    b_UdUsedBy3ByteCh                   :1;
    vbittype    b_UdUsedBy2ByteCh                   :1;
  } b;
  #elif defined ( C_CPUTYPE_BITORDER_LSB2MSB )
  struct
  {
    vbittype    b_PreNetSleepInd                    :1;
    vbittype    b_StateNetSleepInd                  :1;
    vbittype    b_StateUDMaster                     :1;
    vbittype    b_UdApplSendRingRequested           :1;
    vbittype    b_UdApplSendBroadcastRequested      :1;
    vbittype    b_UdMasterLastRxRingA               :1;
    vbittype    b_UdApplIndRingRes                  :1;
    vbittype    b_UdRingResourceRequested           :1;
                                                      
    vbittype    b_UdUsedBy2ByteCh                   :1;
    vbittype    b_UdUsedBy3ByteCh                   :1;
    vbittype    b_UdUsedBy5ByteResource             :1;
    vbittype    b_UdResourceUsed                    :1;
    vbittype    b_UdSendRingAllowed                 :1;
    vbittype    b_UdApplConfBroadcast               :1;
    vbittype    b_UdSendModifiedRingDataRequested   :1;
    vbittype    b_Dummy                             :1;
  } b;
  #else 
    #error "Missing bitorder for typedef NmUdStateTypeDc !!"
  #endif
} NmUdStateTypeDc;

#endif /* ( NM_ENABLE_GW_MULTI_NM ) || ( NM_ENABLE_USERDATA_ACCESS ) */

#if defined ( NM_ENABLE_USERDATA_ACCESS )

/* for userdata-access */
typedef enum
{
  RES_NOTUSED,
  RES_RX_BROADCAST,
  RES_RX_RING_A_PROTECTED,
  RES_RX_RING_A_UNPROTECTED,
  RES_RX_RING_B_PROTECTED,
  RES_RX_RING_B_UNPROTECTED,
  RES_TX_RING_A,
  RES_TX_RING_B
} NmUdPtype;

#if defined ( C_CPUTYPE_BITORDER_MSB2LSB )
typedef struct
{
  vbittype NMSleep                :2;   /* NM Sleep Indication / Acknowledge */
  vbittype UdP1UnprotectedMsg     :1;   /* Userdata Part 2 Protected/Unprotected Ring A/B or Broadcast Message */
  vbittype UdP1RingOrBroadcastMsg :2;   /* Userdata Part 2 Ring A/B or Broadcast Message */
  vbittype UdP2UnprotectedMsg     :1;   /* Userdata Part 1 Protected/Unprotected Ring A/B or Broadcast Message */
  vbittype UdP2RingOrBroadcastMsg :2;   /* Userdata Part 1 Ring A/B or Broadcast Message */
} NmUdCtrlByteType;
#elif defined ( C_CPUTYPE_BITORDER_LSB2MSB )
typedef struct
{
  vbittype UdP2RingOrBroadcastMsg :2;   /* Userdata Part 1 Ring A/B or Broadcast Message */
  vbittype UdP2UnprotectedMsg     :1;   /* Userdata Part 1 Protected/Unprotected Ring A/B or Broadcast Message */
  vbittype UdP1RingOrBroadcastMsg :2;   /* Userdata Part 2 Ring A/B or Broadcast Message */
  vbittype UdP1UnprotectedMsg     :1;   /* Userdata Part 2 Protected/Unprotected Ring A/B or Broadcast Message */
  vbittype NMSleep                :2;   /* NM Sleep Indication / Acknowledge */
} NmUdCtrlByteType;
#else
  #error "Missing bitorder for typedef NmUdCtrlByteType !!"
#endif

typedef union
{
  vuint8 c;               /* Note: No local buffer for tx user data bytes */
  NmUdCtrlByteType b;
} NmUdSendMessType;

typedef union
{
  vuint8 c[6];
  NmUdCtrlByteType b;
  /* 5 User Data bytes follow. Access is done by array element of union. */
} NmUdRecvMessType;

#endif /* NM_ENABLE_USERDATA_ACCESS */

/****************************************************************************/
/* Definition of variables depends on number of channels                    */
/****************************************************************************/


/*  *****   STOPSINGLE_OF_MULTIPLE_COMMENT    *****  */


#if defined ( NM_ENABLE_ONM_EXT_API )


/*****************************************************************************
*
*
*      HEADER-Part for NM channel 
*
*
******************************************************************************/



#if defined ( NM_ENABLE_INDEXED_NM )

  /****************************************************************************/
  /* Page0 data                                                               */
  /****************************************************************************/
  /*---- transmit buffer nm message ------------------------------------------*/


    #if defined ( NM_ENABLE_GW_MULTI_NM ) || defined ( NM_ENABLE_USERDATA_ACCESS )
/* RAM CATEGORY 1 START */
static volatile NmUdStateTypeDc MEMORY_NEAR nmStateDcUd[kNmNumberOfChannels];
/* RAM CATEGORY 1 END */
    #endif



/****************************************************************************/
/* Extended page variables                                                  */
/****************************************************************************/

  #if defined ( NM_ENABLE_RECEIVE_ALIVE_BROADCAST ) || \
      defined ( NM_ENABLE_RECEIVE_RING_BROADCAST  ) || \
      defined ( NM_ENABLE_RECEIVE_RING_DATA       )
/*
  ##Js: onmMsgTypeInfo Holds the current message type global for the ONM module,
        to support any service function with the current state.
*/
/* RAM CATEGORY 1 START */
static NmMsgType onmMsgTypeInfo[kNmNumberOfChannels];
/* RAM CATEGORY 1 END */
  #endif

  #if defined ( NM_ENABLE_USERDATA_ACCESS )
/* RAM CATEGORY 2 START */
static NmUdPtype nmPreviousUdCode[kNmNumberOfChannels];
static canuint8 *onmUdTxBufferStartAddr[kNmNumberOfChannels];
static NmUdSendMessType onmUdTxProtByte[kNmNumberOfChannels];
/* RAM CATEGORY 2 END */
/* RAM CATEGORY 1 START */
static NmUdRecvMessType onmUdRxBuffer[kNmNumberOfChannels];
/* RAM CATEGORY 1 END */
  #endif

#else /* #if defined ( NM_ENABLE_INDEXED_NM ) */

  /****************************************************************************/
  /* Page0 data                                                               */
  /****************************************************************************/
  /*---- transmit buffer nm message ------------------------------------------*/


    #if defined ( NM_ENABLE_GW_MULTI_NM ) || defined ( NM_ENABLE_USERDATA_ACCESS )
/* RAM CATEGORY 1 START */
static volatile NmUdStateTypeDc MEMORY_NEAR nmStateDcUd;
/* RAM CATEGORY 1 END */
    #endif



/****************************************************************************/
/* Extended page variables                                                  */
/****************************************************************************/
  #if defined ( NM_ENABLE_RECEIVE_ALIVE_BROADCAST ) || \
      defined ( NM_ENABLE_RECEIVE_RING_BROADCAST  ) || \
      defined ( NM_ENABLE_RECEIVE_RING_DATA       )
/*
  ##Js: onmMsgTypeInfo Holds the current message type global for the ONM module,
        to support any service function with the current state.
*/
/* RAM CATEGORY 1 START */
static NmMsgType onmMsgTypeInfo;
/* RAM CATEGORY 1 END */
  #endif

  #if defined ( NM_ENABLE_USERDATA_ACCESS )
/* RAM CATEGORY 2 START */
static NmUdPtype nmPreviousUdCode;
static canuint8 *onmUdTxBufferStartAddr;
static NmUdSendMessType onmUdTxProtByte;
/* RAM CATEGORY 2 END */
/* RAM CATEGORY 1 START */
static NmUdRecvMessType onmUdRxBuffer;
/* RAM CATEGORY 1 END */
  #endif

#endif /* #if defined ( NM_ENABLE_INDEXED_NM ) */



/******************************************************************************/
/* Defines for nmState, tx and rx buffer access depends on number of channels */
/******************************************************************************/

#if defined ( NM_ENABLE_INDEXED_NM )

  /****************************************************************************/
  /* Additional defines for required indexed arrays                           */
  /****************************************************************************/

  #define onmMsgTypeInfo            onmMsgTypeInfo[channel]

  #if defined ( NM_ENABLE_USERDATA_ACCESS )
    #define nmPreviousUdCode        nmPreviousUdCode[channel]
  #endif

  /****************************************************************************/
  /* Common with code redoubled section, but channel dependent                */
  /****************************************************************************/

  #if defined (NM_ENABLE_USERDATA_ACCESS) || defined (NM_ENABLE_GW_MULTI_NM)
    #define StateUdGwFlags                    nmStateDcUd[channel].c[0]
    #define StateUdChFlags                    nmStateDcUd[channel].c[1]
  #endif
  #if defined ( NM_ENABLE_GW_MULTI_NM )
    #define StateNetSleepInd                  nmStateDcUd[channel].b.b_StateNetSleepInd
    #define PreNetSleepInd                    nmStateDcUd[channel].b.b_PreNetSleepInd
  #endif
  #if defined (NM_ENABLE_USERDATA_ACCESS)
    #define StateUDMaster                     nmStateDcUd[channel].b.b_StateUDMaster          
    #define UdApplIndRingRes                  nmStateDcUd[channel].b.b_UdApplIndRingRes        
    #define UdRingResourceRequested           nmStateDcUd[channel].b.b_UdRingResourceRequested     
    #define UdApplSendBroadcastRequested      nmStateDcUd[channel].b.b_UdApplSendBroadcastRequested          
    #define UdApplSendRingRequested           nmStateDcUd[channel].b.b_UdApplSendRingRequested          
    #define UdMasterLastRxRingA               nmStateDcUd[channel].b.b_UdMasterLastRxRingA  
    #define UdUsedBy5ByteResource             nmStateDcUd[channel].b.b_UdUsedBy5ByteResource
    #define UdResourceUsed                    nmStateDcUd[channel].b.b_UdResourceUsed
    #define UdSendRingAllowed                 nmStateDcUd[channel].b.b_UdSendRingAllowed
    #define UdApplConfBroadcast               nmStateDcUd[channel].b.b_UdApplConfBroadcast
    #define UdSendModifiedRingDataRequested   nmStateDcUd[channel].b.b_UdSendModifiedRingDataRequested

  #endif

  /* Tx buffer */
  #define SendUdMsgBufferStart      onmUdTxBufferStartAddr[channel]
  #define SendUdMsgProtByte         onmUdTxProtByte[channel].c
  #define SendUdMsgRingOrBroadcast  onmUdTxProtByte[channel].b.UdP2RingOrBroadcastMsg   /* Bits 0-1: Ring A/B / Broadcast */   
  #define SendUdMsgUnprotected      onmUdTxProtByte[channel].b.UdP2UnprotectedMsg       /* Bit 2:    Protected / Unprotected */

  #define SendUdMsgUser0            onmUdTxBufferStartAddr[channel][0]
  #define SendUdMsgUser1            onmUdTxBufferStartAddr[channel][1]
  #define SendUdMsgUser2            onmUdTxBufferStartAddr[channel][2]
  #define SendUdMsgUser3            onmUdTxBufferStartAddr[channel][3]
  #define SendUdMsgUser4            onmUdTxBufferStartAddr[channel][4]


  /* Rx buffer */
  #define RecvUdMsgRingOrBroadcast  onmUdRxBuffer[channel].b.UdP2RingOrBroadcastMsg   /* Bits 0-1: Ring A/B / Broadcast */
  #define RecvUdMsgUnprotected      onmUdRxBuffer[channel].b.UdP2UnprotectedMsg       /* Bit 2:    Protected / Unprotected */
  #define RecvUdMsgProtByte         onmUdRxBuffer[channel].c[0]
  #define RecvUdMsgUser0            onmUdRxBuffer[channel].c[1]
  #define RecvUdMsgUser1            onmUdRxBuffer[channel].c[2]
  #define RecvUdMsgUser2            onmUdRxBuffer[channel].c[3]
  #define RecvUdMsgUser3            onmUdRxBuffer[channel].c[4]
  #define RecvUdMsgUser4            onmUdRxBuffer[channel].c[5]

#else /* NM_ENABLE_INDEXED_NM */

  /****************************************************************************/
  /* Additional defines for required for special implementation               */
  /****************************************************************************/

  /****************************************************************************/
  /* Common with indexed section, but only code redoubled                     */
  /****************************************************************************/

  #if defined ( NM_ENABLE_USERDATA_ACCESS ) || defined ( NM_ENABLE_GW_MULTI_NM )
    #define StateUdGwFlags                nmStateDcUd.c[0]
    #define StateUdChFlags                nmStateDcUd.c[1]
  #endif
  #if defined ( NM_ENABLE_GW_MULTI_NM )
  /* NetSleep-indication */
    #define StateNetSleepInd              nmStateDcUd.b.b_StateNetSleepInd
    #define PreNetSleepInd                nmStateDcUd.b.b_PreNetSleepInd
  #endif /* NM_ENABLE_GW_MULTI_NM */
  #if defined (NM_ENABLE_USERDATA_ACCESS)
    #define StateUDMaster                 nmStateDcUd.b.b_StateUDMaster                 /* flag: node is UD-master */
    #define UdApplIndRingRes              nmStateDcUd.b.b_UdApplIndRingRes              /* flag: notify application about rcvd. ring resource */
    #define UdRingResourceRequested       nmStateDcUd.b.b_UdRingResourceRequested       /* flag: UD-master can occupy the resource */
    #define UdApplSendBroadcastRequested  nmStateDcUd.b.b_UdApplSendBroadcastRequested  /* flag: appl. called SendBroadcastUser */
    #define UdApplSendRingRequested       nmStateDcUd.b.b_UdApplSendRingRequested       /* flag: appl. called SendRingUser */
    #define UdMasterLastRxRingA           nmStateDcUd.b.b_UdMasterLastRxRingA           /* flag: UD-master received Ring_A-msg as last msg */
    #define UdUsedBy5ByteResource         nmStateDcUd.b.b_UdUsedBy5ByteResource
    #define UdResourceUsed                nmStateDcUd.b.b_UdResourceUsed
    #define UdSendRingAllowed             nmStateDcUd.b.b_UdSendRingAllowed
    #define UdApplConfBroadcast           nmStateDcUd.b.b_UdApplConfBroadcast
    #define UdSendModifiedRingDataRequested  nmStateDcUd.b.b_UdSendModifiedRingDataRequested
  #endif

  /* Tx buffer */
  #define SendUdMsgBufferStart      onmUdTxBufferStartAddr
  #define SendUdMsgProtByte         onmUdTxProtByte.c
  #define SendUdMsgRingOrBroadcast  onmUdTxProtByte.b.UdP2RingOrBroadcastMsg    /* Bits 0-1: Ring A/B / Broadcast */
  #define SendUdMsgUnprotected      onmUdTxProtByte.b.UdP2UnprotectedMsg        /* Bit 2:    Protected / Unprotected */

  #define SendUdMsgUser0            onmUdTxBufferStartAddr[0]
  #define SendUdMsgUser1            onmUdTxBufferStartAddr[1]
  #define SendUdMsgUser2            onmUdTxBufferStartAddr[2]
  #define SendUdMsgUser3            onmUdTxBufferStartAddr[3]
  #define SendUdMsgUser4            onmUdTxBufferStartAddr[4]

  /* Rx buffer */
  #define RecvUdMsgRingOrBroadcast  onmUdRxBuffer.b.UdP2RingOrBroadcastMsg      /* Bits 0-1: Ring A/B / Broadcast */
  #define RecvUdMsgUnprotected      onmUdRxBuffer.b.UdP2UnprotectedMsg          /* Bit 2:    Protected / Unprotected */
  #define RecvUdMsgProtByte         onmUdRxBuffer.c[0]
  #define RecvUdMsgUser0            onmUdRxBuffer.c[1]
  #define RecvUdMsgUser1            onmUdRxBuffer.c[2]
  #define RecvUdMsgUser2            onmUdRxBuffer.c[3]
  #define RecvUdMsgUser3            onmUdRxBuffer.c[4]
  #define RecvUdMsgUser4            onmUdRxBuffer.c[5]
#endif /* NM_ENABLE_INDEXED_NM */

#define SendUdMsgInitResource() { SendUdMsgUser0  = UD_DATA_INIT; \
                                  SendUdMsgUser1  = UD_DATA_INIT; \
                                  SendUdMsgUser2  = UD_DATA_INIT; \
                                  SendUdMsgUser3  = UD_DATA_INIT; \
                                  SendUdMsgUser4  = UD_DATA_INIT; }


#if (UD_RESOURCE_SIZE != 5)
  #error "Userdata Resource Size other than 5 byte not implemented!"
#endif


/****************************************************************************/
/* Functions                                                                */
/****************************************************************************/


/*****************************************************************************/
/* Local functions                                                           */
/*****************************************************************************/

#if defined ( NM_ENABLE_USERDATA_ACCESS )

#if NM_DIROSEK_VERSION < 0x0365
/* CODE CATEGORY 1 START */
static StatusType NM_API_CALL_TYPE NmUdReadRecvData(NM_CHANNEL_NMTYPE_FIRST canuint8 MEMORY_CAN* udRecvData);
/* CODE CATEGORY 1 END */
#else
/* CODE CATEGORY 1 START */
#if defined ( NM_ENABLE_IF_ASRIFCAN )
static StatusType NM_API_CALL_TYPE NmUdReadRecvData(NM_CHANNEL_NMTYPE_FIRST const uint8*);
#else
static StatusType NM_API_CALL_TYPE NmUdReadRecvData(NM_CHANNEL_NMTYPE_FIRST CanChipDataPtr);
#endif
/* CODE CATEGORY 1 END */
#endif
/* CODE CATEGORY 2 START */
static void NmUdReleaseClearResource(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 2 END */

/* CODE CATEGORY 1 START */

/************************************************************************
| NAME:               NmUdReadRecvData
| PROTOTYPE:          StatusType NmUdReadRecvData(CanChipDataPtr)
|                     StatusType NmUdReadRecvData(vuint8*)
| CALLED BY:          !!! OnmExtPrecopy() !!!
| PRECONDITIONS:      Interrupts disabled
| INPUT PARAMETERS:   udRecvData: Pointer to a source field, there the
|                                 current user data are copied from
| RETURN VALUE:       E_NotOK, E_OK
| DESCRIPTION:        copies the current user data for reception
|                     into the local ONM buffer for reception
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
#if NM_DIROSEK_VERSION < 0x0365
static StatusType NM_API_CALL_TYPE NmUdReadRecvData(NM_CHANNEL_NMTYPE_FIRST canuint8 MEMORY_CAN* udRecvData)
#else
#if defined ( NM_ENABLE_IF_ASRIFCAN )
static StatusType NM_API_CALL_TYPE NmUdReadRecvData(NM_CHANNEL_NMTYPE_FIRST const uint8* udRecvData)
#else
static StatusType NM_API_CALL_TYPE NmUdReadRecvData(NM_CHANNEL_NMTYPE_FIRST CanChipDataPtr udRecvData)
#endif
#endif
{
  NmStatusType nmRecvState;

  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  /* !!! Not used, because only for module internal usage on NM channel allowed
    channel = NmCanToNmIndirection[channel];
  */
  #endif

  /*
    Leave the NM_CHANNEL_APPLPARA_ONLY, because NmGetStatus() will be used now internal.
  */

  nmRecvState = NmGetStatus(NM_CHANNEL_APPLPARA_ONLY);

  if((NmStateBusError(nmRecvState) != 0) ||
     (NmStateWaitBusSleep(nmRecvState) != 0) ||
     (NmStateBusSleep(nmRecvState) != 0))
  {
    return(E_NotOK); /* User data undefined */
  }
  else
  {
    /* Interrupts already blocked, because usage only allowed in ONMX */
    RecvUdMsgUser0 = udRecvData[0];
    RecvUdMsgUser1 = udRecvData[1];
    RecvUdMsgUser2 = udRecvData[2];
    RecvUdMsgUser3 = udRecvData[3];
    RecvUdMsgUser4 = udRecvData[4];

    return(E_OK);
  }
}

/* CODE CATEGORY 1 END */

/* CODE CATEGORY 2 START */

/************************************************************************
| NAME:               NmUdReleaseClearResource
| CALLED BY:          NmTask (internal)
| PRECONDITIONS:      Ring breakdown for userdata
|                     for indexed version, function works
|                     always with NM internal channel
|*************************************************************************/
static void NmUdReleaseClearResource(NM_CHANNEL_NMTYPE_ONLY) 
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  /* !!! Not used, because only for module internal usage on NM channel allowed
    channel = NmCanToNmIndirection[channel];
  */
  #endif

  StateUDMaster = 0;       /* no longer UD-master */
  nmPreviousUdCode = RES_NOTUSED;

  UdMasterLastRxRingA = 0;              /* clear flag for rx Ring_A */
  SendUdMsgInitResource();
  SendUdMsgProtByte = UD_RES_FREE;
  UdResourceUsed = 0;       /* reset flag which prevents successful call of NmSendRingUserData() */
  UdSendRingAllowed = 0;   /* reset flag to become UD-master, able to send ringdata */
}

/* CODE CATEGORY 2 END */


#endif /* #if defined ( NM_ENABLE_USERDATA_ACCESS ) */


/******************************************************************************
Global, exported functions
******************************************************************************/

/* CODE CATEGORY 1 START */

/************************************************************************
| NAME:               OnmExtConfirmation
| PROTOTYPE:          void OnmExtConfirmation(NmMsgType msgType)
| CALLED BY:          NmConfirmation()
| PRECONDITIONS:      Interrupt context
| INPUT PARAMETERS:   msgType of transmitted message
| RETURN VALUE:       -
| DESCRIPTION:        Confirmation routine for NM User Data module
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
void NM_INTERNAL_CALL_TYPE OnmExtConfirmation(NM_CHANNEL_NMTYPE_FIRST NmMsgType msgType) 
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  /* !!! Not used, because only for module internal usage on NM channel allowed
    channel = NmCanToNmIndirection[channel];
  */
  #endif

  StartMeasure(OnmExtConfirmationTimings);

  #if defined ( NM_ENABLE_RECEIVE_ALIVE_BROADCAST ) || \
      defined ( NM_ENABLE_RECEIVE_RING_BROADCAST  ) || \
      defined ( NM_ENABLE_RECEIVE_RING_DATA       )
  onmMsgTypeInfo = msgType; /* Make backup for usage within service functions. */
  #endif

  #if defined ( NM_ENABLE_SEND_RING_DATA ) || defined ( NM_ENABLE_SEND_RING_BROADCAST )
  if ((msgType & NM_MSG_RING) != 0)
  {
    NmStatusType nmConfState;

    /*
      Leave the NM_CHANNEL_APPLPARA_ONLY, because NmGetStatus() will be used now internal.
    */

    nmConfState = NmGetStatus(NM_CHANNEL_APPLPARA_ONLY);

    if ((NmStateRingStable(nmConfState) != 0) && ((StateUDMaster != 0) || (UdApplConfBroadcast != 0)))
    { 
      if (SendUdMsgRingOrBroadcast == UD_MASK_PART1_BROADCAST)
      {
        ApplNmConUserData(NM_CHANNEL_APPLPARA_FIRST ring_broadcast);  /* notify application */
        UdApplConfBroadcast = 0;
      }
      else if ((SendUdMsgRingOrBroadcast == UD_MASK_PART1_RING_A) || (SendUdMsgRingOrBroadcast == UD_MASK_PART1_RING_B))
      {
        if (SendUdMsgUnprotected != 0)
        {
          ApplNmConUserData(NM_CHANNEL_APPLPARA_FIRST unprotected_ring);  /* notify application */
        }
        else
        {
          ApplNmConUserData(NM_CHANNEL_APPLPARA_FIRST protected_ring);    /* dto.*/
        }
      }
      else
      {
        /* nothing to be done (MISRA) */
      }
    }
  }
  else
  #endif /* ( NM_ENABLE_SEND_RING_DATA ) || ( NM_ENABLE_SEND_RING_BROADCAST ) */
  #if defined ( NM_ENABLE_SEND_ALIVE_BROADCAST )
  if ((msgType & NM_MSG_LIMPHOME) != 0)
  {
    if(SendUdMsgRingOrBroadcast == UD_MASK_PART1_BROADCAST)
    {
      ApplNmConUserData(NM_CHANNEL_APPLPARA_FIRST limphome_broadcast);
    }
  }
  else if ((msgType & NM_MSG_RESET_ALIVE) != 0)
  {
    if(SendUdMsgRingOrBroadcast == UD_MASK_PART1_BROADCAST)
    {
      ApplNmConUserData(NM_CHANNEL_APPLPARA_FIRST start_alive_broadcast);
    }
  }
  else if ((msgType & NM_MSG_SKIPPED_ALIVE) != 0)
  {
    if(SendUdMsgRingOrBroadcast == UD_MASK_PART1_BROADCAST)
    {
      ApplNmConUserData(NM_CHANNEL_APPLPARA_FIRST skipped_alive_broadcast);
    }
  }
  else
  #endif /* ( NM_ENABLE_SEND_ALIVE_BROADCAST ) */
  {
    /* nothing to be done (MISRA) */
  }

  StopMeasure(OnmExtConfirmationTimings);

} /* end of OnmExtConfirmation() */



/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */

/************************************************************************
| NAME:               OnmExtPrecopy()
| PROTOTYPE:          void OnmExtPrecopy(NmMsgType, CanChipDataPtr);
|                     void OnmExtPrecopy(NmMsgType, vuint8*);
| CALLED BY:          NmPrecopy()
| PRECONDITIONS:      Interrupt context
| INPUT PARAMETERS:   msgType of received message
|                     Pointer to the received User Data
| RETURN VALUE:       -
| DESCRIPTION:        Precopy routine for NM User Data module
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
#if NM_DIROSEK_VERSION < 0x0365
void NM_INTERNAL_CALL_TYPE OnmExtPrecopy(NM_CHANNEL_NMTYPE_FIRST NmMsgType msgType, canuint8 MEMORY_CAN* udRecvData) /* ESCAN00023642 */
#else
#if defined ( NM_ENABLE_IF_ASRIFCAN )
void NM_INTERNAL_CALL_TYPE OnmExtPrecopy(NM_CHANNEL_NMTYPE_FIRST NmMsgType msgType, const uint8 *udRecvData)
#else
void NM_INTERNAL_CALL_TYPE OnmExtPrecopy(NM_CHANNEL_NMTYPE_FIRST NmMsgType msgType, CanChipDataPtr udRecvData)
#endif
#endif
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  /* !!! Not used, because only for module internal usage on NM channel allowed
    channel = NmCanToNmIndirection[channel];
  */
  #endif

  StartMeasure(OnmExtPrecopyTimings);

  #if defined ( NM_ENABLE_RECEIVE_ALIVE_BROADCAST ) || \
      defined ( NM_ENABLE_RECEIVE_RING_BROADCAST  ) || \
      defined ( NM_ENABLE_RECEIVE_RING_DATA       )
  onmMsgTypeInfo = msgType; /* Make backup for usage within service functions. */
  #else
    /* ESCAN00031536 */
    #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  msgType = msgType;
    #endif
  #endif

  #if defined ( NM_ENABLE_USERDATA_ACCESS )
  /* Copy UD receive data into local receive buffer */
  if(NmUdReadRecvData(NM_CHANNEL_NMPARA_FIRST udRecvData) == E_OK)
  {
    RecvUdMsgProtByte = NmGetRecvUdProtocolCommand(NM_CHANNEL_NMPARA_ONLY);
  }
  #endif
 
  #if defined ( NM_ENABLE_RECEIVE_ALIVE_BROADCAST )
  if((RecvUdMsgProtByte & UD_MASK_PART1_PART2) == UD_RES_BROADCAST)
  {
    if ((msgType & NM_MSG_RESET_ALIVE) != 0)
    {
      ApplNmIndReadStartAliveBroadcastUserData(NM_CHANNEL_APPLPARA_ONLY);
    }
    else if ((msgType & NM_MSG_SKIPPED_ALIVE) != 0)
    {
      ApplNmIndReadSkippedAliveBroadcastUserData(NM_CHANNEL_APPLPARA_ONLY);
    }
    else if ((msgType & NM_MSG_LIMPHOME) != 0)
    {
      ApplNmIndReadLimphomeBroadcastUserData(NM_CHANNEL_APPLPARA_ONLY);
    }
    else
    {
      /* nothing to be done (MISRA) */
    }
  }
  #endif

  #if defined ( NM_ENABLE_SEND_RING_DATA )
  if (((msgType & NM_MSG_RESET_ALIVE) != 0) || ((msgType & NM_MSG_SKIPPED_ALIVE) != 0))
  {
    ApplNmIndUserDataError( NM_CHANNEL_APPLPARA_FIRST errorRingBreakdown);  /* notify application */
  }
  #endif

  #if defined ( NM_ENABLE_GW_MULTI_NM )
  if(!(msgType & NM_MSG_SLEEP_IND)   ||
      (msgType & NM_MSG_RESET_ALIVE) || 
      (msgType & NM_MSG_SKIPPED_ALIVE))
  {
    /* NetSleep-indication */
    PreNetSleepInd   = 0;  /* reset NetSleepInd for ring messages with sleep ind=0 and alive broadcasts */
    StateNetSleepInd = 0;
  }
  #endif

  StopMeasure(OnmExtPrecopyTimings);

} /* end of OnmExtPrecopy() */

/* CODE CATEGORY 1 END */


/* CODE CATEGORY 4 START */

/************************************************************************
| NAME:               OnmExtInit
| PROTOTYPE:          void OnmExtInit(void)
| CALLED BY:          NmOsekInit()
| PRECONDITIONS:      Interrupts disabled
| INPUT PARAMETERS:   -
| RETURN VALUE:       -
| DESCRIPTION:        Init routine for NM User Data module
|                     Use NmGetStatus() to initialize depending on NM state.
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
void NM_API_CALL_TYPE OnmExtInit(NM_CHANNEL_NMTYPE_ONLY) 
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  /* !!! Not used, because only for module internal usage on NM channel allowed
    channel = NmCanToNmIndirection[channel];
  */
  #endif

  #if defined ( NM_ENABLE_USERDATA_ACCESS )
  /* NO channel indirection because NM INTERNAL call (ESCAN00008886) */
  SendUdMsgBufferStart = NmGetUdStartAddress(NM_CHANNEL_NMPARA_ONLY);
    #if defined ( NM_ENABLE_USERDATA_TASK )
  /* USE channel indirection because NM EXTERNAL call */
  ApplNmUserDataInit(NM_CHANNEL_APPLPARA_ONLY);
    #endif
  #endif
} /* end of OnmExtInit() */

/* CODE CATEGORY 4 END */

/* CODE CATEGORY 2 START */

/************************************************************************
| NAME:               OnmExtTask
| PROTOTYPE:          void OnmExtTask(NmMsgType msgType)
| CALLED BY:          NmTask()
| PRECONDITIONS:      Interrupts disabled
| INPUT PARAMETERS:   -
| RETURN VALUE:       -
| DESCRIPTION:        Task routine for NM User Data module
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
void NM_API_CALL_TYPE OnmExtTask(NM_CHANNEL_NMTYPE_FIRST NmMsgType msgType) 
{
  NmStatusType nmTaskState;

  #if defined ( NM_ENABLE_USERDATA_ACCESS )
  vuint8 ud_error = 0;
  vuint8 ud_send  = 0;  /* error-, send-mark for UserData */
  #endif

  StartMeasure(OnmExtTaskTimings);

  #if defined ( NM_ENABLE_RECEIVE_ALIVE_BROADCAST ) || \
      defined ( NM_ENABLE_RECEIVE_RING_BROADCAST  ) || \
      defined ( NM_ENABLE_RECEIVE_RING_DATA       )
  onmMsgTypeInfo = msgType; /* Make backup for usage within service functions. */
  #endif

  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  /* !!! Not used, because only for module internal usage on NM channel allowed
    channel = NmCanToNmIndirection[channel];
  */
  #endif

  #if defined ( NM_ENABLE_USERDATA_ACCESS )
    #if defined ( NM_ENABLE_USERDATA_TASK )
  /* ##Js - interrupts from call within NmTask() were not blocked, now blocked */
  ApplNmUserDataTask(NM_CHANNEL_APPLPARA_ONLY); /* context is now inside while loop */
    #endif
  #endif

  /*
    Leave the NM_CHANNEL_APPLPARA_ONLY, because NmGetStatus() will be used now internal.
  */
  nmTaskState = NmGetStatus(NM_CHANNEL_APPLPARA_ONLY);

  if ((msgType & NM_MSG_WAIT_TX) != 0)
  {
    if ((msgType & NM_MSG_RESET_ALIVE) != 0)
    {
      /* Transmission of RESET ALIVE prepared */

      #if defined ( NM_ENABLE_SEND_RING_DATA ) || defined ( NM_ENABLE_SEND_RING_BROADCAST )
      ApplNmIndUserDataError(NM_CHANNEL_APPLPARA_FIRST errorRingBreakdown);  /* notify application */
      #endif

      #if defined ( NM_ENABLE_USERDATA_ACCESS ) || defined ( NM_ENABLE_GW_MULTI_NM )
      StateUdGwFlags = 0;
      StateUdChFlags = 0; 
      #endif

      #if defined (NM_ENABLE_USERDATA_ACCESS)
      /* set UD-resource-state to "not used" */
      nmPreviousUdCode = RES_NOTUSED;
      #endif

      #if defined ( NM_ENABLE_SEND_ALIVE_BROADCAST )
      if ((msgType & NM_MSG_START_TX) != 0)
      {
        if(ApplNmIndSendStartAliveBroadcast(NM_CHANNEL_APPLPARA_FIRST &SendUdMsgUser0) != E_OK)
        {
          SendUdMsgInitResource();
          SendUdMsgProtByte = UD_RES_FREE;
        } 
        else
        {
          /* UD data bytes were initialized by application */
          SendUdMsgProtByte = UD_RES_BROADCAST;
        }

        NmSetSendUdProtocolCommand(NM_CHANNEL_NMPARA_FIRST SendUdMsgProtByte);
      }
      #endif
    }
    else if ((msgType & NM_MSG_SKIPPED_ALIVE) != 0)
    {
      /* Transmission of SKIPPED ALIVE prepared */

      #if defined ( NM_ENABLE_SEND_RING_DATA ) || defined ( NM_ENABLE_SEND_RING_BROADCAST )
      ApplNmIndUserDataError( NM_CHANNEL_APPLPARA_FIRST errorRingBreakdown);  /* notify application */
      #endif

      if ((msgType & NM_MSG_START_TX) != 0)
      {
        #if defined ( NM_ENABLE_SEND_ALIVE_BROADCAST )
        if(ApplNmIndSendSkippedAliveBroadcast(NM_CHANNEL_APPLPARA_FIRST &SendUdMsgUser0) != E_OK)
        {
          SendUdMsgInitResource();
          SendUdMsgProtByte = UD_RES_FREE;
        } 
        else
        {
          /* UD data bytes were initialized by application */
          SendUdMsgProtByte = UD_RES_BROADCAST;
        }

        NmSetSendUdProtocolCommand(NM_CHANNEL_NMPARA_FIRST SendUdMsgProtByte);
        #endif

        #if defined ( NM_ENABLE_GW_MULTI_NM )
        /* NetSleep-indication */
        PreNetSleepInd   = 0;   /* GW-NM-node sent skipped-ALIVE -> reset NetSleepInd */
        StateNetSleepInd = 0;
        #endif /* NM_ENABLE_GW_MULTI_NM */
      }
    }
    else if (((msgType & NM_MSG_RING) != 0) && ((msgType & NM_MSG_START_TX) != 0))
    {
      /* Transmission of RING prepared */

      #if defined ( NM_ENABLE_GW_MULTI_NM )
      /* NetSleep-indication */
      if(PreNetSleepInd)       /* here: 2nd token received */
      {
        StateNetSleepInd = 1;
      }

      PreNetSleepInd = 1;       /* here: 1st token received */
      #endif

      #if defined ( NM_ENABLE_USERDATA_ACCESS )
      
      if (NmStateRingStable(nmTaskState) != 0)
      {
        #if defined ( NM_ENABLE_SEND_RING_DATA ) || defined ( NM_ENABLE_SEND_RING_BROADCAST )
        if (UdUsedBy5ByteResource != 0)  /* UD 5-byte-channel used */
        {
          if (UdSendModifiedRingDataRequested != 0)  /* request to modify unprotected ring-data by UD-Slave */
          {
        #endif
        #if defined ( NM_ENABLE_SEND_RING_DATA )
            /* make it possible to modify unprotected ring-data (as an UD-slave) */
            UdSendModifiedRingDataRequested = 0;    /* clear flag set in NmRequestSendModifiedRingUserDataAsSlave() */ 
            UdApplIndRingRes = 0; /* reset flag */

            if((nmPreviousUdCode == RES_RX_RING_A_UNPROTECTED)||
               (nmPreviousUdCode == RES_RX_RING_B_UNPROTECTED)  )
            {
              /* last rx-msg were unsafe data, can be overwritten by application with NmSendRingUserData(is_unprotected) */
              ApplNmIndWriteUnprotectedUserData(NM_CHANNEL_APPLPARA_FIRST &SendUdMsgUser0);  /* notify application */
              /* for UD-5-byte-channel: clear bits in 3rd msg-byte, UD-bits-part1 */
              /* -> SendUDByte2_3/4/5 must already be cleared by master       */
            }
        #endif /* NM_ENABLE_SEND_RING_DATA */

        #if defined ( NM_ENABLE_SEND_RING_DATA ) || defined ( NM_ENABLE_SEND_RING_BROADCAST )
          }
          else /* UdSendModifiedRingDataRequested was NOT set */
          {
            if (UdRingResourceRequested != 0)  /* NmGetRingResource() called */
            {
              if (!UdResourceUsed)    /* no-one else is UD-master   */
              {
                if (UdApplIndRingRes != 0)   /* application can be notified to send Userdata */
                { 
                  if (UdSendRingAllowed != 0)
                  {
                    ApplNmIndRingResource(NM_CHANNEL_APPLPARA_FIRST &SendUdMsgUser0, txBroadcastOrRing); /* notify application */
                  }
                  else
                  {
                    ApplNmIndRingResource(NM_CHANNEL_APPLPARA_FIRST &SendUdMsgUser0, txBroadcastOnly); /* notify application */
                  }

                  UdApplIndRingRes = 0; /* reset flag */
                }
        #endif /* defined (NM_ENABLE_SEND_RING_DATA) || defined (NM_ENABLE_SEND_RING_BROADCAST) */

        #if defined ( NM_ENABLE_SEND_RING_DATA )                   
                if (UdApplSendRingRequested != 0)   /* application called NmSendRingUserData() */
                {
                  /* UD-master received a ring A message he sent before */
                  if ((nmPreviousUdCode == RES_TX_RING_A) && (UdMasterLastRxRingA != 0))
                  { 
                    nmPreviousUdCode = RES_TX_RING_B;  /* toggle ring-code in new UD-ring-msg */
                    StateUDMaster = 1;    /* still UD-master */
                    SendUdMsgProtByte = UD_RES_PROTECTED_RING_B;
                  }

                  /* not yet UD-master, previous msg. was UD_MASK_PART1_NOT_USED or BC-msg                        */
                  /* or: not yet UD-master,  BC-msg received, previous was no Ring_A or Ring_B -msg */
                  /* or:     UD-master  and  Ring_B-msg received before                             */

                  if ((((nmPreviousUdCode == RES_NOTUSED) || (nmPreviousUdCode == RES_RX_BROADCAST)) && (UdSendRingAllowed != 0)) ||
                     ((nmPreviousUdCode == RES_TX_RING_B) && (!UdMasterLastRxRingA)))
                  {
                    nmPreviousUdCode = RES_TX_RING_A;  /* new UD-RD-master starts with Ring_A - message */
                                                           /* or: toggle UD-master from Ring_B to Ring_A    */
                    StateUDMaster = 1;    /* become UD-master - in case of RES_RX_BROADCAST only if UdSendRingAllowed = 1 !! */
                    SendUdMsgProtByte = UD_RES_PROTECTED_RING_A;
                  } /* endif */
      
                  UdApplSendRingRequested = 0;    /* clear flag set in NmSendRingUserData() */ 

                }    /* endif ( UdApplSendRingRequested ) */
                else  /* UdApplSendRingRequested = 0 : application didn't call NmSendRingUserData() anew */
        #endif  /* #if defined (NM_ENABLE_SEND_RING_DATA) */

        #if defined ( NM_ENABLE_SEND_RING_DATA ) || defined ( NM_ENABLE_SEND_RING_BROADCAST )
                {
        #endif

        #if defined ( NM_ENABLE_SEND_RING_BROADCAST )
                  /* application called NmSendBroadcastUserData() */
                  if (UdApplSendBroadcastRequested != 0)
                  {
                    if( (nmPreviousUdCode == RES_NOTUSED     )||  /* resource is free */
                        (nmPreviousUdCode == RES_TX_RING_A   )||  /* or node was UD-master before */
                        (nmPreviousUdCode == RES_TX_RING_B   )||
                        (nmPreviousUdCode == RES_RX_BROADCAST)  ) /* or node received BC before   */
                    {
                      UdApplConfBroadcast = 1;   /* for enabling callback-fct. ApplNmConUserData() */
                      UdApplSendBroadcastRequested = 0;
                      UdRingResourceRequested = 0; /* release resource for BC */
                      SendUdMsgProtByte = UD_RES_BROADCAST;
                    }
                  }
                  else  /* application didn't call NmSendBroadcastUserData()  (nor NmSendRingUserData()) */
        #endif /* defined (NM_ENABLE_SEND_RING_BROADCAST) */

        #if defined ( NM_ENABLE_SEND_RING_DATA ) || defined ( NM_ENABLE_SEND_RING_BROADCAST )
                  {
                    NmUdReleaseClearResource(NM_CHANNEL_NMPARA_ONLY);  /* internal fctn. to clear and release resource */
                  }
                } /* endif ( !UdApplSendRingRequested ) */
              } /* endif (!UdResourceUsed)  */
            } /* (UdRingResourceRequested) */
            else  /* resource not occupied by node */
            {
              if (StateUDMaster != 0)
              {
                /* !! clear UD only in case of the node being UD-master before ! */
                NmUdReleaseClearResource(NM_CHANNEL_NMPARA_ONLY);  /* internal fctn. to clear and release resource */
              } 
            } /* endif - res. not occupied by node */
          } /* endif-else UdSendModifiedRingDataRequested set */
        } /* endif (UdUsedBy5ByteResource) */
        #endif /* (NM_ENABLE_SEND_RING_DATA) || (NM_ENABLE_SEND_RING_BROADCAST) */
      }  /* endif (StateRingStable) */
      else  /* ring not stable */
      {
        NmUdReleaseClearResource(NM_CHANNEL_NMPARA_ONLY);  /* internal fctn. to clear and release resource */
      }
  
      UdSendRingAllowed = 0;  /* reset flag to become UD-master, able to send ringdata */

      NmSetSendUdProtocolCommand(NM_CHANNEL_NMPARA_FIRST SendUdMsgProtByte);
      #endif /*(NM_ENABLE_USERDATA_ACCESS)*/
    }
    else if ((msgType & NM_MSG_LIMPHOME) != 0)
    {
      /* Transmission of LIMPHOME prepared */

      if ((msgType & NM_MSG_START_TX) != 0)
      {  /* send limphome message */
        #if defined ( NM_ENABLE_SEND_ALIVE_BROADCAST )
        if(ApplNmIndSendLimphomeBroadcast(NM_CHANNEL_APPLPARA_FIRST &SendUdMsgUser0) != E_OK)
        {
          SendUdMsgInitResource();
          SendUdMsgProtByte = UD_RES_FREE;
        } 
        else
        {
          /* UD data bytes were initialized by application */
          SendUdMsgProtByte = UD_RES_BROADCAST;
        }

        NmSetSendUdProtocolCommand(NM_CHANNEL_NMPARA_FIRST SendUdMsgProtByte);
        #endif

        #if defined ( NM_ENABLE_GW_MULTI_NM )
        /* NetSleep-indication */
        StateNetSleepInd = 1;   /* GW-NM-node sends LH-msg -> set subnet sleep-ready        */
        PreNetSleepInd   = 1;   /*                            (reason: GW-NM is 'deaf' now) */
        #endif /* NM_ENABLE_GW_MULTI_NM */
      }
    }
    else
    {
      /* nothing to be done (MISRA) */
    }
  } /* end of Tx path */
  else if (((msgType & NM_MSG_WAIT_RX) != 0) && ((msgType & NM_MSG_RING) != 0))
  {
    if ((msgType & NM_MSG_TIMEOUT_RX) != 0)
    {
      /* Timeout of RING */

      #if defined ( NM_ENABLE_SEND_RING_DATA ) || defined ( NM_ENABLE_SEND_RING_BROADCAST )
      ApplNmIndUserDataError( NM_CHANNEL_APPLPARA_FIRST errorRingBreakdown);  /* notify application */
      NmUdReleaseClearResource(NM_CHANNEL_NMPARA_ONLY);  /* internal fctn. to clear and release resource */
      #endif
    }
    else if ((msgType & NM_MSG_RECEIVED) != 0)
    {
      /* RING received */

      #if defined ( NM_ENABLE_USERDATA_ACCESS ) /* ESCAN00018635 */
      /* ESCAN00008836 - Copy UD bytes from receive to send buffer */
      SendUdMsgProtByte = RecvUdMsgProtByte;
      SendUdMsgUser0 = RecvUdMsgUser0;
      SendUdMsgUser1 = RecvUdMsgUser1;
      SendUdMsgUser2 = RecvUdMsgUser2;
      SendUdMsgUser3 = RecvUdMsgUser3;
      SendUdMsgUser4 = RecvUdMsgUser4;

      if (((msgType & NM_MSG_TOKEN_RECEIVED) != 0) && (NmStateActive(nmTaskState) != 0) && (NmStateRingStable(nmTaskState) != 0))
      {
        if(((RecvUdMsgProtByte & UD_MASK_PART1_PART2) == UD_RES_FREE) ||   /* UD resource not used */
           ((RecvUdMsgProtByte & UD_MASK_PART1)       == (vuint8)0x00))    /* 5 bytes resource indicated */
        {
          UdUsedBy5ByteResource = 1;                    /* set flag for 5 bytes resource */

          #if defined ( NM_ENABLE_SEND_RING_DATA )
          if(nmPreviousUdCode == RES_TX_RING_A)                       /* *** UD-master, sent Ring_A */
          {
            if(RecvUdMsgRingOrBroadcast == UD_MASK_PART1_RING_A)      /* rx UD_MASK_PART1_RING_A  */
            {
              ApplNmIndUserData(NM_CHANNEL_APPLPARA_ONLY);            /* notify application: data received */
              UdMasterLastRxRingA = 1; 
              ud_send = 1;
              UdSendRingAllowed = 1;   /* set flag to become UD-master, able to send ringdata */
              UdResourceUsed = 0;       /* reset flag which prevents successful call of NmSendRingUserData() */
            }
            else
            {
              ud_error = 1;
            }
          }
          else if(nmPreviousUdCode == RES_TX_RING_B)                  /* *** UD-master, sent Ring_B */
          {
            if(RecvUdMsgRingOrBroadcast == UD_MASK_PART1_RING_B)      /* rx UD_MASK_PART1_RING_B  */
            {
              ApplNmIndUserData(NM_CHANNEL_APPLPARA_ONLY);            /* notify application */
              UdMasterLastRxRingA = 0; 
              ud_send = 1;
              UdSendRingAllowed = 1;   /* set flag to become UD-master, able to send ringdata */
              UdResourceUsed = 0;       /* reset flag which prevents successful call of NmSendRingUserData() */
            }
            else
            {
              ud_error = 1;
            }
          }
          else if(RecvUdMsgRingOrBroadcast == UD_MASK_PART1_NOT_USED) /* rx UD_MASK_PART1_NOT_USED  */
          #else
          if(RecvUdMsgRingOrBroadcast == UD_MASK_PART1_NOT_USED)      /* rx UD_MASK_PART1_NOT_USED  */
          #endif
          {
            if( (nmPreviousUdCode == RES_NOTUSED     )||
                (nmPreviousUdCode == RES_RX_BROADCAST)  )
            {                                                       /* *** UD_MASK_PART1_NOT_USED or BC before  */
              UdSendRingAllowed = 1;  /* set flag to become UD-master, able to send ringdata */
                                          /* -> only here: allow send ring-UD (wait for 2* UD_MASK_PART1_NOT_USED before occupying res.) */
            }

            #if defined ( NM_ENABLE_SEND_RING_DATA )
            if( (nmPreviousUdCode == RES_RX_RING_A_PROTECTED       )||
                (nmPreviousUdCode == RES_RX_RING_A_UNPROTECTED)||
                (nmPreviousUdCode == RES_RX_RING_B_PROTECTED       )||
                (nmPreviousUdCode == RES_RX_RING_B_UNPROTECTED)  )  /* *** UD-Slave, received Ring_A or Ring_B before */
            {
              ApplNmConUserData( NM_CHANNEL_APPLPARA_FIRST ring_notify_ud_slave);  /* notify application */
            }
            #endif

            ud_send = 1;
            UdResourceUsed = 0; /* reset flag which prevents successful call of NmSendRingUserData() */
            nmPreviousUdCode = RES_NOTUSED;
          }

          else if(RecvUdMsgRingOrBroadcast == UD_MASK_PART1_RING_A)                      /* rx UD_MASK_PART1_RING_A  */
          {
            if( (nmPreviousUdCode == RES_RX_RING_A_PROTECTED       )||
                (nmPreviousUdCode == RES_RX_RING_A_UNPROTECTED)  )  /* *** UD-Slave, received Ring_A before */
            {
              ud_error = 1;
            }
            else                                                    /* *** UD-slave, received UD_MASK_PART1_NOT_USED or UD_MASK_PART1_RING_B before */
            {
              if(!RecvUdMsgUnprotected) 
              {
                /* safe data received */
                nmPreviousUdCode = RES_RX_RING_A_PROTECTED;
              }
              else 
              {
                /* unsafe data received (can be overwritten by UD-slave) */
                nmPreviousUdCode = RES_RX_RING_A_UNPROTECTED;
              }

              #if defined ( NM_ENABLE_SEND_RING_DATA )
              if( (nmPreviousUdCode == RES_RX_RING_B_PROTECTED       )||
                  (nmPreviousUdCode == RES_RX_RING_B_UNPROTECTED)  )  /* *** UD-Slave, received Ring_B before */
              {
                ApplNmConUserData( NM_CHANNEL_APPLPARA_FIRST ring_notify_ud_slave);  /* notify application */
              }
              #endif

              #if defined ( NM_ENABLE_RECEIVE_RING_DATA )
              ApplNmIndUserData(NM_CHANNEL_APPLPARA_ONLY);
              #endif
            }

            UdResourceUsed = 1; /* set flag which prevents successful call of NmSendRingUserData() */
          }
          else if(RecvUdMsgRingOrBroadcast == UD_MASK_PART1_RING_B)                      /* rx UD_MASK_PART1_RING_B  */
          {
            if( (nmPreviousUdCode == RES_RX_RING_A_PROTECTED       )||
                (nmPreviousUdCode == RES_RX_RING_A_UNPROTECTED)  ) /* *** UD-Slave, received Ring_A before */
            {
              if(!RecvUdMsgUnprotected) 
              {
                /* safe data received */
                nmPreviousUdCode = RES_RX_RING_B_PROTECTED;
              }
              else 
              {
                /* unsafe data received (can be overwritten by UD-slave) */
                nmPreviousUdCode = RES_RX_RING_B_UNPROTECTED;
              }

              #if defined ( NM_ENABLE_SEND_RING_DATA )
              ApplNmConUserData( NM_CHANNEL_APPLPARA_FIRST ring_notify_ud_slave);  /* notify application */
              #endif

              #if defined ( NM_ENABLE_RECEIVE_RING_DATA )
              ApplNmIndUserData(NM_CHANNEL_APPLPARA_ONLY);
              #endif
            }
            else                                                  /* *** UD-slave, received UD_MASK_PART1_NOT_USED or UD_MASK_PART1_RING_B before */
            {
              ud_error = 1;
            }

            UdResourceUsed = 1; /* set flag which prevents successful call of NmSendRingUserData() */
          }
          else if(RecvUdMsgRingOrBroadcast == UD_MASK_PART1_BROADCAST)                   /* rx UD_MASK_PART1_BROADCAST  */
          {
            #if defined ( NM_ENABLE_SEND_RING_DATA )
            if( (nmPreviousUdCode == RES_RX_RING_A_PROTECTED       )||
                (nmPreviousUdCode == RES_RX_RING_A_UNPROTECTED)||
                (nmPreviousUdCode == RES_RX_RING_B_PROTECTED       )||
                (nmPreviousUdCode == RES_RX_RING_B_UNPROTECTED)  )  /* *** UD-Slave, received Ring_A or Ring_B before */
            {
              ApplNmConUserData( NM_CHANNEL_APPLPARA_FIRST ring_notify_ud_slave);  /* notify application */
            }
            #endif

            #if defined ( NM_ENABLE_RECEIVE_RING_BROADCAST )
            ApplNmIndUserData(NM_CHANNEL_APPLPARA_ONLY); /* notify application  */
            #endif

            if( (nmPreviousUdCode == RES_NOTUSED     )||
                (nmPreviousUdCode == RES_RX_BROADCAST)  )
            {                                                       /* *** UD_MASK_PART1_NOT_USED or BC before  */
              UdSendRingAllowed = 1;  /* set flag to become UD-master, able to send ringdata */
            }

            NmUdReleaseClearResource(NM_CHANNEL_NMPARA_ONLY);  /* internal fctn. to clear and release resource */
            nmPreviousUdCode = RES_RX_BROADCAST;
            UdResourceUsed = 0; /* reset flag which prevents successful call of NmSendRingUserData() */
            ud_send = 1;
          }
          else
          {
            /* nothing to be done (MISRA) */
          }

          /* send-flag set and NmGetResource() called and res.not used by other node */
          if((ud_send == 1) && (UdRingResourceRequested) && (!UdResourceUsed))
          {
            UdApplIndRingRes = 1;  /* set flag for enabling callback-fctn. in NmTask/ tx token */
          }
          else if(ud_error == 1)
          {
            #if defined ( NM_ENABLE_SEND_RING_DATA         ) || \
                defined ( NM_ENABLE_SEND_RING_BROADCAST    ) || \
                defined ( NM_ENABLE_RECEIVE_RING_DATA      ) || \
                defined ( NM_ENABLE_RECEIVE_RING_BROADCAST )
            ApplNmIndUserDataError( NM_CHANNEL_APPLPARA_FIRST errorUDCodeSequence);  /* notify application: error occurred */
            #endif
            NmUdReleaseClearResource(NM_CHANNEL_NMPARA_ONLY);  /* internal fctn. to clear and release resource */
          }
          else
          {
            /* nothing to be done (MISRA) */
          }
        }  /* UD resource not used OR 5 bytes resource indicated */
        else
        {
          UdUsedBy5ByteResource = 0;            /* clear 5-byte-ch. flag */

          #if defined ( NM_ENABLE_SEND_RING_DATA ) || defined ( NM_ENABLE_SEND_RING_BROADCAST ) 
          if (StateUDMaster != 0)    /* 5 bytes resource send by UD-master disturbed by 2 or 3 bytes resource */
          {
            ApplNmIndUserDataError( NM_CHANNEL_APPLPARA_FIRST errorUDWrongChannel);  /* notify application: error occurred */
            /* 5byte-channel-master received 3-or2-byte-channel-msg. during his sending-activity    */
            NmUdReleaseClearResource(NM_CHANNEL_NMPARA_ONLY);  /* internal fctn. to clear and release resource */
          }
          else
          {
            UdResourceUsed = 1; /* set flag which prevents successful call of NmSendRingUserData() */
          }
          #endif
        } /* UD resource not used OR 5 bytes resource indicated */
      } /* NM_MSG_TOKEN_RECEIVED AND NmStateActive AND NmStateRingStable */
      else if ((NmStateActive(nmTaskState) != 0))
      {
        #if defined (NM_ENABLE_RECEIVE_RING_BROADCAST)
        if(RecvUdMsgRingOrBroadcast == UD_MASK_PART1_BROADCAST)
        {
          ApplNmIndUserData(NM_CHANNEL_APPLPARA_ONLY);
        }
        #endif
      } /* NmStateActive */
      else
      {
        /* nothing to be done (MISRA) */
      }
      #endif /* NM_ENABLE_USERDATA_ACCESS */
    }
    else
    {
      /* nothing to be done (MISRA) */
    }
  } /* end of Rx path */
  else
  {
    /* no action for ONMX - reset state machine */

    #if defined ( NM_ENABLE_USERDATA_ACCESS ) || defined ( NM_ENABLE_GW_MULTI_NM )
    StateUdGwFlags &= 0x03;
    StateUdChFlags = 0; 
    #endif
  }

  StopMeasure(OnmExtTaskTimings);

} /* end of OnmExtTask() */

/* CODE CATEGORY 2 END */


#if defined ( NM_ENABLE_GW_MULTI_NM ) || defined ( NM_ENABLE_USERDATA_ACCESS )

/* CODE CATEGORY 4 START */

/************************************************************************
| NAME:               GetOnmExtStatus
| PROTOTYPE:          void GetOnmExtStatus(OnmExtStatusTypeDc *dest)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   Pointer to application specific variable
| RETURN VALUE:       -
| DESCRIPTION:        Copies the current NM user data state into an
|                     application specific variable
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
void NM_API_CALL_TYPE GetOnmExtStatus(NM_CHANNEL_NMTYPE_FIRST OnmExtStatusTypeDc *dest)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  *dest = (OnmExtStatusTypeDc)(StateUdGwFlags);
} /* End of GetOnmExtStatus */

/* CODE CATEGORY 4 END */

/* CODE CATEGORY 4 START */

/************************************************************************
| NAME:               OnmExtGetStatus
| PROTOTYPE:          OnmExtStatusTypeDc OnmExtGetStatus(void)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   -
| RETURN VALUE:       Current NM user data status
| DESCRIPTION:        -
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
OnmExtStatusTypeDc NM_API_CALL_TYPE OnmExtGetStatus(NM_CHANNEL_NMTYPE_ONLY)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  return((OnmExtStatusTypeDc)(StateUdGwFlags));
} /* end of OnmExtGetStatus ()*/

/* CODE CATEGORY 4 END */

#endif  /* NM_ENABLE_GW_MULTI_NM || NM_ENABLE_USERDATA_ACCESS */


#if defined ( NM_ENABLE_USERDATA_ACCESS )
  #if defined ( NM_ENABLE_SEND_RING_BROADCAST )

/* CODE CATEGORY 2 START */

/************************************************************************
| NAME:               NmSendBroadcastUserData
| PROTOTYPE:          StatusType NmSendBroadcastUserData( NmDataLengthType len )
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   len: number of bytes to be sent
|                     
| RETURN VALUE:       -
| DESCRIPTION:        enables sending User-BroadcastData during next tx of token
|                     can only be called from appl. in callback-fctn. ApplNmIndRingResource()
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
StatusType NM_API_CALL_TYPE NmSendBroadcastUserData( NM_CHANNEL_NMTYPE_FIRST NmDataLengthType len)
{
    #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
    #endif

  if(len != UD_RESOURCE_SIZE)
  {/* only 5-byte-channel implemented yet */
    return(E_NotOK);
  }

  if((!UdApplSendRingRequested) && (!UdApplSendBroadcastRequested))
  {
    /* free to send */
    UdApplSendBroadcastRequested = 1;   /* set flag for NmTask() */
    SendUdMsgUnprotected = 1;           /* broadcast transfer */

    /*
       -> now   : application fills directly nmSendMess (5 bytes userdata) 
                  via txDataPtr (parameter given to application by ApplNmIndRingResource(vuint8 *)
                  before calling NmSendBroadcastUserData() )
    */

    return(E_OK);
  }
  else
  {
    /* tx-buffer full */
    return(E_NotOK);
  }
} /* NmSendBroadcastUserData */

/* CODE CATEGORY 2 END */

  #endif /* NM_ENABLE_SEND_RING_BROADCAST */

  #if defined ( NM_ENABLE_SEND_RING_DATA )

/* CODE CATEGORY 2 START */

/************************************************************************
| NAME:               NmSendRingUserData
| PROTOTYPE:          StatusType NmSendRingUserData( NmDataLengthType len, NmUDModeType udmode )
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   len:    number of bytes to be sent
|                     udmode: transmission type                
|                     
| RETURN VALUE:       -
| DESCRIPTION:        enables sending User-RingData during next tx of token
|                     can only be called from appl. in callback-fctn. ApplNmIndRingResource()
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
StatusType NM_API_CALL_TYPE NmSendRingUserData(NM_CHANNEL_NMTYPE_FIRST NmDataLengthType len, NmUDModeType udmode)
{
    #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
    #endif

  if(len != UD_RESOURCE_SIZE)    /* only 5-byte-channel implemented yet */
  {
    return(E_NotOK);
  }

  if((!UdApplSendRingRequested) && (!UdApplSendBroadcastRequested))
  {
    /* Sendbuffer free  */
    UdApplSendRingRequested = 1;  /* set flag for NmTask */

    if(udmode == is_protected)
    {
      SendUdMsgUnprotected = 0;  /* safe data-transfer */
    }
    else
    {
      SendUdMsgUnprotected = 1;  /* unsafe data-transfer */
    }

    /*
     -> now   : application fills directly nmSendMess (5 bytes userdata) 
                via txDataPtr (parameter given to application by ApplNmIndRingResource(vuint8 *)
                before calling NmSendRingUserData() )
    */

    return(E_OK);
  }
  else
  {
    /* tx-buffer full */
    return(E_NotOK);
  }
} /* NmSendRingUserData */

/* CODE CATEGORY 2 END */

/* CODE CATEGORY 2 START */

/************************************************************************
| NAME:               NmRequestSendModifiedRingUserDataAsSlave
| PROTOTYPE:          StatusType NmRequestSendModifiedRingUserDataAsSlave
|                     ( NmDataLengthType len, NmUDModeType udmode )
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   len:    number of bytes to be sent
|                     
| RETURN VALUE:       -
| DESCRIPTION:        enables sending modified unprotected User-RingData
|                     can only be called from appl. in callback-fctn. ApplNmIndUserData()
|                     in case of "unprotected_ring"-userdata that may be modified by an UD-Slave
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
StatusType NM_API_CALL_TYPE NmRequestSendModifiedRingUserDataAsSlave(NM_CHANNEL_NMTYPE_FIRST NmDataLengthType len)
{
    #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
    #endif

  if(len != UD_RESOURCE_SIZE)    /* only 5-byte-channel implemented yet */
  {
    return(E_NotOK);
  }

  UdSendModifiedRingDataRequested = 1;  /* set flag for NmTask */
  SendUdMsgUnprotected = 1;             /* unprotected ring */

  /*
  -> application fills directly nmSendMess (5 bytes userdata) 
  via txDataPtr (parameter given to application by ApplNmIndWriteUnprotectedUserData(vuint8 *))
  */
  return(E_OK);
} /* NmRequestSendModifiedRingUserDataAsSlave */

/* CODE CATEGORY 2 END */

  #endif  /* NM_ENABLE_SEND_RING_DATA */

  #if defined ( NM_ENABLE_SEND_RING_BROADCAST ) || defined ( NM_ENABLE_SEND_RING_DATA ) 

/* CODE CATEGORY 2 START */

/************************************************************************
| NAME:               NmGetRingResource
| PROTOTYPE:          NmGetRingResource(void)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   -
|                     
| RETURN VALUE:       -
| DESCRIPTION:        occupy free resource of UserData in ringmessage
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
StatusType NM_API_CALL_TYPE NmGetRingResource(NM_CHANNEL_NMTYPE_ONLY)
{
    #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
    #endif

    #if defined ( NM_ENABLE_IF_ASRIFCAN )
  Can_DisableControllerInterrupts( NM_CHANNEL_CANASRPARA_ONLY );
    #else
  CanInterruptDisable();
    #endif

  if(!UdRingResourceRequested)    /* no-one else called NmGetRingResource() */
  {
    UdRingResourceRequested = 1;  /* set status-flag  */

    #if defined ( NM_ENABLE_IF_ASRIFCAN )
    Can_EnableControllerInterrupts( NM_CHANNEL_CANASRPARA_ONLY );
    #else
    CanInterruptRestore();
    #endif
    return(E_OK);
  }
  else  /* res. already occupied */
  {
    #if defined ( NM_ENABLE_IF_ASRIFCAN )
    Can_EnableControllerInterrupts( NM_CHANNEL_CANASRPARA_ONLY );
    #else
    CanInterruptRestore();
    #endif
    return(E_NotOK);
  }
} /* NmGetRingResource */

/* CODE CATEGORY 2 END */

/* CODE CATEGORY 2 START */

/************************************************************************
| NAME:               NmReleaseRingResource
| PROTOTYPE:          NmReleaseRingResource(void)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   -
|                     
| RETURN VALUE:       -
| DESCRIPTION:        release occupied resource of UserData in ringmessage
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
StatusType NM_API_CALL_TYPE NmReleaseRingResource( NM_CHANNEL_NMTYPE_ONLY )
{
    #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
    #endif

    #if defined ( NM_ENABLE_IF_ASRIFCAN )
  Can_DisableControllerInterrupts( NM_CHANNEL_CANASRPARA_ONLY );
    #else
  CanInterruptDisable();
    #endif

  if (UdRingResourceRequested != 0)     /* resource in use ? */
  {
    UdRingResourceRequested = 0;  /* reset status-flag */
    UdApplSendRingRequested = 0;       /* clear flag set in NmSendRingUserData() */

    #if defined ( NM_ENABLE_IF_ASRIFCAN )
    Can_EnableControllerInterrupts( NM_CHANNEL_CANASRPARA_ONLY );
    #else
    CanInterruptRestore();
    #endif
    return(E_OK);
  }
  else  /* res. already released */
  {
    #if defined ( NM_ENABLE_IF_ASRIFCAN )
    Can_EnableControllerInterrupts( NM_CHANNEL_CANASRPARA_ONLY );
    #else
    CanInterruptRestore();
    #endif
    return(E_NotOK);
  }
} /* NmReleaseRingResource */

/* CODE CATEGORY 2 END */

/* CODE CATEGORY 2 START */

/************************************************************************
| NAME:               NmGetResourceState
| PROTOTYPE:          NmGetResourceState(void)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   -
|                     
| RETURN VALUE:       -
| DESCRIPTION:        get current state of resource (occupied or free) 
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
NmUDResStateType NM_API_CALL_TYPE NmGetResourceState( NM_CHANNEL_NMTYPE_ONLY )
{
    #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
    #endif

  if(!UdRingResourceRequested)   /* resource not used */
  {
    return(is_free);
  }
  else
  {
    return(is_occupied);
  }
} /* NmGetResourceState */

/* CODE CATEGORY 2 END */

  #endif  /* defined (NM_ENABLE_SEND_RING_BROADCAST) || defined (NM_ENABLE_SEND_RING_DATA) */
#endif /* NM_ENABLE_USERDATA_ACCESS */

#if defined ( NM_ENABLE_RECEIVE_ALIVE_BROADCAST ) || \
    defined ( NM_ENABLE_RECEIVE_RING_BROADCAST  ) || \
    defined ( NM_ENABLE_RECEIVE_RING_DATA       )


/* CODE CATEGORY 1 START */

/************************************************************************
| NAME:               NmReadUserDataParameter
| PROTOTYPE:          NmReadUserDataParameter(NmUserDataRefType*  udRxPtr,
|                                                 NmUDRxTxStatusType* udRxState,
|                                                 NmNodeType*         recvSourceAddr,
|                                                 NmDataLengthType*   dataLength)
| CALLED BY:          Application
| PRECONDITIONS:      Only in ApplNmIndBroadcastData()
| INPUT PARAMETERS:   refer to documentation
|                     
| RETURN VALUE:       StatusType
| DESCRIPTION:        read state of received userdata, their sender
|                     (only for alive/LH-messages), received datalength and pointer of rx-UserData
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
StatusType NM_API_CALL_TYPE NmReadUserDataParameter(NM_CHANNEL_NMTYPE_FIRST
                                                        NmUserDataRefType   *udRxPtr,
                                                        NmUDRxTxStatusType  *udRxState,
                                                        NmNodeType          *recvSourceAddr,
                                                        NmDataLengthType    *dataLength)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  *dataLength = UD_RESOURCE_SIZE;  /* datalength 2/3/5-byte channel */

  #if defined ( NM_ENABLE_RECEIVE_RING_BROADCAST )|| defined ( NM_ENABLE_RECEIVE_RING_DATA )
  if ((onmMsgTypeInfo & NM_MSG_RING) != 0)
  {
    if((RecvUdMsgRingOrBroadcast == UD_MASK_PART1_RING_A) || (RecvUdMsgRingOrBroadcast == UD_MASK_PART1_RING_B))
    { 
      if(!RecvUdMsgUnprotected)   /* "safe" data received */
      {
        *udRxState = protected_ring;
      }
      else
      {
        *udRxState = unprotected_ring;
      }
      *recvSourceAddr = 0xFF; /* recvSourceAddr not valid in case of ring-msg. */
    } 
    else if(RecvUdMsgRingOrBroadcast == UD_MASK_PART1_BROADCAST)
    {
      *udRxState = ring_broadcast;
      /* Leave the NM_CHANNEL_NMPARA_FIRST, because NmReadRecvSourceAddress() is only used internally */
      if (NmReadRecvSourceAddress(NM_CHANNEL_NMPARA_FIRST recvSourceAddr) != E_OK)
      {
        return (E_NotOK);
      }
    }
    else
    {
      return (E_NotOK);
    }

    *udRxPtr = &RecvUdMsgUser0;   /* address of UserData in rx-interim-buffer */
  }
  else
  #endif /* (NM_ENABLE_RECEIVE_RING_BROADCAST) || (...) */
  #if defined ( NM_ENABLE_RECEIVE_ALIVE_BROADCAST ) 
  if ((onmMsgTypeInfo & NM_MSG_RESET_ALIVE) != 0)
  {
    /* Leave the NM_CHANNEL_NMPARA_FIRST, because NmReadRecvSourceAddress() is only used internally */
    if(NmReadRecvSourceAddress(NM_CHANNEL_NMPARA_FIRST recvSourceAddr) == E_OK)
    {
      *udRxState = start_alive_broadcast;
      *udRxPtr = &RecvUdMsgUser0;  /* address of UserData in rx-msg. */
    }
    else
    {
      return(E_NotOK);
    }
  }
  else if ((onmMsgTypeInfo & NM_MSG_SKIPPED_ALIVE) != 0)
  {
    /* Leave the NM_CHANNEL_NMPARA_FIRST, because NmReadRecvSourceAddress() is only used internally */
    if(NmReadRecvSourceAddress(NM_CHANNEL_NMPARA_FIRST recvSourceAddr) == E_OK)
    {
      *udRxState = skipped_alive_broadcast;
      *udRxPtr = &RecvUdMsgUser0;  /* address of UserData in rx-msg. */
    }
    else
    {
      return(E_NotOK);
    }
  }
  else if(onmMsgTypeInfo == NM_MSG_LIMPHOME)
  {
    /* Leave the NM_CHANNEL_NMPARA_FIRST, because NmReadRecvSourceAddress() is only used internally */
    if(NmReadRecvSourceAddress(NM_CHANNEL_NMPARA_FIRST recvSourceAddr) == E_OK)
    {
      *udRxState = limphome_broadcast;
      *udRxPtr = &RecvUdMsgUser0;  /* address of UserData in rx-msg. */
    }
    else
    {
      return(E_NotOK);
    }
  }
  else
  #endif /* ( NM_ENABLE_RECEIVE_ALIVE_BROADCAST ) */
  {
    return(E_NotOK);
  }

  return(E_OK);

} /* NmReadUserDataParameter */

/* CODE CATEGORY 1 END */

#endif  /* RECEIVE_ALIVE_BROADCAST || RECEIVE_RING_BROADCAST || RECEIVE_RING_DATA */

#endif /* NM_ENABLE_ONM_EXT_API */

