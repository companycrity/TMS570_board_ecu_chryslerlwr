/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */



/******************************************************************************
|   File Name: onmxdc.h
| Description: OSEK NM Extensions Module Header File
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
| 2007-12-11  1.12.00  Fmi     ESCAN00023642: Adapted prototype of OnmExtPrecopy to match memory qualifiers
| 2008-02-14  1.13.00  Fmi     ESCAN00024575: Invalid pointer conversion from far to near when calling NmUdReadRecvData
| 2008-03-14  1.14.00  Fmi     ESCAN00025352: Remove include of nm_cfg.h in onmxdc.h
| 2008-08-22  1.15.00  vismas  ESCAN00029400: Add support of AUTOSAR environment
| 2008-12-16  1.15.01  vismas  ESCAN00031536: no changes in this file
|*****************************************************************************/

/*  *****   STOPSINGLE_OF_MULTIPLE_COMMENT    *****  */

#ifndef ONMX_DC_H
#define ONMX_DC_H

/* STARTSINGLE_OF_MULTIPLE */

/* DC OSEK NM header */
#include "n_onmdef.h"

#if defined ( NM_ENABLE_USERDATA_TASK )
  /* prototypes for UD services */
  #include "nm_udata.h"
#endif


/***************************************************************************/
/* External Data                                                           */
/***************************************************************************/


/*****************************************************************************/
/* Version information                                                       */
/*****************************************************************************/
/* ROM CATEGORY 4 START */
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kOnmExtMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kOnmExtSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kOnmExtReleaseVersion;
/* ROM CATEGORY 4 END */



/***************************************************************************/
/* Version                              BCD coded version numbers          */
/***************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : Nm_DirOsekExt_Dc CQComponent : Implementation */
#define NM_DIROSEKEXT_DC_VERSION         0x0115
#define NM_DIROSEKEXT_DC_RELEASE_VERSION 0x01

/***************************************************************************/
/* Data types                                                              */
/***************************************************************************/

typedef enum
{
  is_free = 0,
  is_occupied
}NmUDResStateType;

typedef enum
{
  is_unprotected = 0,
  is_protected
}NmUDModeType;

typedef enum
{
  start_alive_broadcast = 0,
  skipped_alive_broadcast,
  limphome_broadcast,
  ring_broadcast,
  protected_ring,
  unprotected_ring, 
  ring_notify_ud_slave
}NmUDRxTxStatusType;

typedef enum
{
  txBroadcastOnly = 0,
  txBroadcastOrRing
}NmUDTxPermissionType;

typedef enum
{
  errorRingBreakdown = 0,
  errorUDCodeSequence,
  errorUDWrongChannel
}NmUDErrorType;

typedef vuint8  NmDataLengthType;
typedef vuint8* NmUserDataRefType;  /* ptr. to Userdata */
typedef vuint8  OnmExtStatusTypeDc;

/* STOPSINGLE_OF_MULTIPLE */

/******************************************************************************
|
|
|    Area of definitions for ONMX channel 
|
|
******************************************************************************/

  #if defined ( NM_ENABLE_ONM_EXT_API )
    #if defined ( ONM_EXT_H_CHANNEL )
    #else
      #define ONM_EXT_H_CHANNEL

      /* Compatibility for old generation tool */
      #if defined ( VGEN_GENY )
      #else
        #error "ONMXDC.H: Not tested for this Generation Tool !!!"

        /*
          done in NM kernel header
        #define NM_ENABLE_USERDATA_ACCESS         NM_TYPE_DBAG_USERDATA_ACCESS_USED
        #define NM_ENABLE_SEND_ALIVE_BROADCAST    NM_TYPE_DBAG_SEND_ALIVE_BROADCAST
        */
        #define NM_ENABLE_SEND_RING_DATA          NM_TYPE_DBAG_SEND_RING_DATA
        #define NM_ENABLE_SEND_RING_BROADCAST     NM_TYPE_DBAG_SEND_RING_BROADCAST
        #define NM_ENABLE_RECEIVE_ALIVE_BROADCAST NM_TYPE_DBAG_RECEIVE_ALIVE_BROADCAST
        #define NM_ENABLE_RECEIVE_RING_BROADCAST  NM_TYPE_DBAG_RECEIVE_RING_BROADCAST
        #define NM_ENABLE_RECEIVE_RING_DATA       NM_TYPE_DBAG_RECEIVE_RING_DATA
        #define NM_ENABLE_GW_MULTI_NM             NM_TYPE_DBAG_GW_MULTI_NM

        /* compatibility mode for old usage of NM_DBAG define */
        /*
          done in NM kernel header
        #define NM_DBAG_USERDATA_ACCESS_USED      NM_ENABLE_USERDATA_ACCESS
        #define NM_DBAG_SEND_ALIVE_BROADCAST      NM_ENABLE_SEND_ALIVE_BROADCAST
        */
        #define NM_DBAG_SEND_RING_BROADCAST       NM_ENABLE_SEND_RING_BROADCAST
        #define NM_DBAG_SEND_RING_DATA            NM_ENABLE_SEND_RING_DATA
        #define NM_DBAG_RECEIVE_ALIVE_BROADCAST   NM_ENABLE_RECEIVE_ALIVE_BROADCAST
        #define NM_DBAG_RECEIVE_RING_BROADCAST    NM_ENABLE_RECEIVE_RING_BROADCAST
        #define NM_DBAG_RECEIVE_RING_DATA         NM_ENABLE_RECEIVE_RING_DATA
        #define NM_DBAG_GW_MULTI_NM               NM_ENABLE_GW_MULTI_NM
      #endif  /* VGEN_GENY */

      /* defines/types for DBAG_USERDATA: */
      #define UD_RESOURCE_SIZE 5    /* only 5-byte-channel implemented yet */

      /***************************************************************************/
      /* Function prototypes and external macros                                 */
      /***************************************************************************/
      #if defined ( NM_ENABLE_GW_MULTI_NM )
        /* net-sleep-readiness-flags */
        #define NmPreNetSleepInd(udState)     (((udState) & 0x01) ? 1 : 0)
        #define NmStateNetSleepInd(udState)   (((udState) & 0x02) ? 1 : 0)
      #endif
      #if defined ( NM_ENABLE_USERDATA_ACCESS )
        /* flag, if node is really UD-master */
        #define NmStateUDMaster(udState)      (((udState) & 0x04) ? 1 : 0)
      #endif

      #if defined ( NM_ENABLE_SEND_ALIVE_BROADCAST )
/* CODE CATEGORY 2 START */
StatusType NM_API_CALLBACK_TYPE ApplNmIndSendStartAliveBroadcast(NM_CHANNEL_APPLTYPE_FIRST vuint8*);/* UD-Start-Alive-BC can be sent */
/* CODE CATEGORY 2 END */

/* CODE CATEGORY 2 START */
StatusType NM_API_CALLBACK_TYPE ApplNmIndSendLimphomeBroadcast(NM_CHANNEL_APPLTYPE_FIRST vuint8*);  /* UD-Limphome-BC can be sent */
/* CODE CATEGORY 2 END */

/* CODE CATEGORY 2 START */
StatusType NM_API_CALLBACK_TYPE ApplNmIndSendSkippedAliveBroadcast(NM_CHANNEL_APPLTYPE_FIRST vuint8*);/* UD-Skipped-Alive-BC can be sent */
/* CODE CATEGORY 2 END */
      #endif

      #if defined ( NM_ENABLE_RECEIVE_ALIVE_BROADCAST )
/* CODE CATEGORY 1 START */
void NM_API_CALLBACK_TYPE ApplNmIndReadStartAliveBroadcastUserData(NM_CHANNEL_APPLTYPE_ONLY); /* Start-Alive-msg. with UD received */
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
void NM_API_CALLBACK_TYPE ApplNmIndReadLimphomeBroadcastUserData(NM_CHANNEL_APPLTYPE_ONLY); /* Limphome-msg. with UD received */
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
void NM_API_CALLBACK_TYPE ApplNmIndReadSkippedAliveBroadcastUserData(NM_CHANNEL_APPLTYPE_ONLY); /* Skipped-Alive-msg. with UD received */
/* CODE CATEGORY 1 END */
      #endif

      #if defined ( NM_ENABLE_SEND_RING_DATA       ) || \
          defined ( NM_ENABLE_SEND_RING_BROADCAST  ) || \
          defined ( NM_ENABLE_SEND_ALIVE_BROADCAST )
/* CODE CATEGORY 1 START */
void NM_API_CALLBACK_TYPE ApplNmConUserData(NM_CHANNEL_APPLTYPE_FIRST NmUDRxTxStatusType);      /* UD were sent */
/* CODE CATEGORY 1 END */
      #endif

      #if defined ( NM_ENABLE_SEND_RING_DATA         ) || \
          defined ( NM_ENABLE_SEND_RING_BROADCAST    ) || \
          defined ( NM_ENABLE_RECEIVE_RING_DATA      ) || \
          defined ( NM_ENABLE_RECEIVE_RING_BROADCAST )
/* CODE CATEGORY 2 START */
void NM_API_CALLBACK_TYPE ApplNmIndUserDataError(NM_CHANNEL_APPLTYPE_FIRST NmUDErrorType);      /* UD-error was recognized */
/* CODE CATEGORY 2 END */
      #endif

      #if defined ( NM_ENABLE_SEND_RING_DATA         ) || \
          defined ( NM_ENABLE_RECEIVE_RING_DATA      ) || \
          defined ( NM_ENABLE_RECEIVE_RING_BROADCAST )
/* CODE CATEGORY 2 START */
void NM_API_CALLBACK_TYPE ApplNmIndUserData(NM_CHANNEL_APPLTYPE_ONLY);                    /* received UD */
/* CODE CATEGORY 2 END */
      #endif

      #if defined ( NM_ENABLE_SEND_RING_DATA ) || defined ( NM_ENABLE_SEND_RING_BROADCAST )   
/* CODE CATEGORY 2 START */
void NM_API_CALLBACK_TYPE ApplNmIndRingResource(NM_CHANNEL_APPLTYPE_FIRST vuint8*, NmUDTxPermissionType);     /* resource available for appl. to send data */
/* CODE CATEGORY 2 END */
      #endif

      #if defined ( NM_ENABLE_SEND_RING_DATA )
/* CODE CATEGORY 2 START */
void NM_API_CALLBACK_TYPE ApplNmIndWriteUnprotectedUserData(NM_CHANNEL_APPLTYPE_FIRST vuint8*);
/* CODE CATEGORY 2 END */
      #endif

      #if defined ( NM_ENABLE_USERDATA_ACCESS )
        #if defined ( NM_ENABLE_USERDATA_TASK )
/* CODE CATEGORY 4 START */
void NM_API_CALLBACK_TYPE ApplNmUserDataInit(NM_CHANNEL_APPLTYPE_ONLY);
/* CODE CATEGORY 4 END */

/* CODE CATEGORY 2 START */
void NM_API_CALLBACK_TYPE ApplNmUserDataTask(NM_CHANNEL_APPLTYPE_ONLY);
/* CODE CATEGORY 2 END */
        #endif
      #endif

      #if defined ( NM_ENABLE_GW_MULTI_NM ) || defined ( NM_ENABLE_USERDATA_ACCESS )
/* CODE CATEGORY 4 START */
void NM_API_CALL_TYPE GetOnmExtStatus(NM_CHANNEL_NMTYPE_FIRST OnmExtStatusTypeDc *dest);
/* CODE CATEGORY 4 END */
/* CODE CATEGORY 4 START */
OnmExtStatusTypeDc NM_API_CALL_TYPE OnmExtGetStatus(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 4 END */
      #endif

      #if defined ( NM_ENABLE_USERDATA_ACCESS )
        #if defined ( NM_ENABLE_SEND_RING_BROADCAST )
/* CODE CATEGORY 2 START */
StatusType NM_API_CALL_TYPE NmSendBroadcastUserData(NM_CHANNEL_NMTYPE_FIRST NmDataLengthType);  
/* CODE CATEGORY 2 END */
        #endif
        #if defined ( NM_ENABLE_SEND_RING_DATA )
/* CODE CATEGORY 2 START */
StatusType NM_API_CALL_TYPE NmSendRingUserData(NM_CHANNEL_NMTYPE_FIRST NmDataLengthType, NmUDModeType);
/* CODE CATEGORY 2 END */
        #endif
        #if defined ( NM_ENABLE_SEND_RING_BROADCAST ) || defined ( NM_ENABLE_SEND_RING_DATA ) 
/* CODE CATEGORY 2 START */
StatusType NM_API_CALL_TYPE NmGetRingResource(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 2 END */

/* CODE CATEGORY 2 START */
StatusType NM_API_CALL_TYPE NmReleaseRingResource(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 2 END */

/* CODE CATEGORY 2 START */
NmUDResStateType NM_API_CALL_TYPE NmGetResourceState(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 2 END */
        #endif
      #endif
    
      #if defined ( NM_ENABLE_SEND_RING_DATA )
/* CODE CATEGORY 2 START */
StatusType  NM_API_CALL_TYPE NmRequestSendModifiedRingUserDataAsSlave(NM_CHANNEL_APPLTYPE_FIRST NmDataLengthType);
/* CODE CATEGORY 2 END */
      #endif
  
      #if defined ( NM_ENABLE_RECEIVE_ALIVE_BROADCAST ) || \
          defined ( NM_ENABLE_RECEIVE_RING_BROADCAST  ) || \
          defined ( NM_ENABLE_RECEIVE_RING_DATA       )
/* CODE CATEGORY 1 START */
StatusType NM_API_CALL_TYPE NmReadUserDataParameter(NM_CHANNEL_NMTYPE_FIRST NmUserDataRefType*, NmUDRxTxStatusType*, NmNodeType*, NmDataLengthType*);
/* CODE CATEGORY 1 END */
      #endif

      /***************************************************************************/
      /* Adaption for different names :                                          */
      /***************************************************************************/

      #if defined ( NM_ENABLE_INDEXED_NM )
        #if defined ( NM_ENABLE_SEND_RING_DATA )
          #define NmSendRingUserDataProtected(canChannel,NmDataLength)   NmSendRingUserData(canChannel,NmDataLength,is_protected) 
          #define NmSendRingUserDataUnprotected(canChannel,NmDataLength) NmSendRingUserData(canChannel,NmDataLength,is_unprotected)
        #endif
      #else
        #if defined (NM_ENABLE_GW_MULTI_NM) 
          /* net-sleep-readiness-flags */
          #define nmPreNetSleepInd(a)       NmPreNetSleepInd(a)
          #define nmStateNetSleepInd(a)     NmStateNetSleepInd(a)
        #endif
        #if defined (NM_ENABLE_USERDATA_ACCESS)
          /* flag, if node is really UD-master */
          #define nmStateUDMaster(a)        NmStateUDMaster(a)
        #endif
        /* UserData compatibility API */
        #if defined ( NM_ENABLE_SEND_RING_DATA )
          #define NmSendRingUserDataProtected(NmDataLength)   NmSendRingUserData(NmDataLength,is_protected) 
          #define NmSendRingUserDataUnprotected(NmDataLength) NmSendRingUserData(NmDataLength,is_unprotected)
        #endif
      #endif /* NM_ENABLE_INDEXED_NM */

    #endif /* ONM_EXT_H_CHANNEL */
  #endif /* NM_ENABLE_ONM_EXT_API */

#endif /* ONMX_DC_H */
