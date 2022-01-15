/******************************************************************************
|   File Name: nm_udata.c
| Description: Nm User Data Signal Layer
|
|------------------------------------------------------------------------------
|               C O P Y R I G H T
|------------------------------------------------------------------------------
| Copyright (c) by Vector Informatik GmbH.                All rights reserved.
|
| This software is copyright protected and proprietary
| to Vector Informatik GmbH. Vector Informatik GmbH
| grants to you only those rights as set out in the
| license conditions. All other rights remain with
| Vector Informatik GmbH.
|
|------------------------------------------------------------------------------
| Nm User Data Generator Version: 2.06.00
|*****************************************************************************/
#include "v_inc.h"
#include "n_onmdef.h"
#include "nm_udata.h"
#include "onmxdc.h"


/* CODE CATEGORY 4 START */
static vuint8 nmpduEvalActive(const vuint8 *txDataPtr);
/* CODE CATEGORY 4 END */

/* Defining a send buffer for each userdata service */
/* RAM CATEGORY 1 START */

static vuint8 UdTxWakeup_EPS[5];
static vuint8 UdTxAwake_EPS[5];
/* RAM CATEGORY 1 END */





/* Defining a queue for the userdata services */
/* RAM CATEGORY 2 START */

static vuint8 startalive_broadcast_queue[1];
static vuint8 ring_queue[1];
static vuint8 ring_queue_pending;
/* RAM CATEGORY 2 END */


/* Defining a buffer for the DPM awake reasons */

/* RAM CATEGORY 2 START */
volatile DpmAwakeFlags_buffer_type DpmAwakeFlags_buffer[1];

/* RAM CATEGORY 2 END */
/* Assertions */
#if defined(C_ENABLE_USER_CHECK)
# if defined(C_SINGLE_RECEIVE_CHANNEL)
#  define assertUser(p,c,e) if (!(p))       ApplNmpduFatalError(e);
# else
#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#   define assertUser(p,c,e) if (!(p))      ApplNmpduFatalError(c,e);
#  else
#   define assertUser(p,e) if (!(p))          ApplNmpduFatalError(e)
#  endif
# endif
#else
# define assertUser(a,c,b)
#endif

#if defined(C_ENABLE_GEN_CHECK)
# if defined(C_SINGLE_RECEIVE_CHANNEL)
#  define assertGen(p,c,e) if (!(p))       ApplNmpduFatalError(e)
# else
#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#   define assertGen(p,c,e) if (!(p))      ApplNmpduFatalError(c,e);
#  else
#   define assertGen(p,e)  if (!(p))       ApplNmpduFatalError(e);
#  endif
# endif
#else
# define assertGen(a,c,b)
#endif

#if defined(C_ENABLE_HARDWARE_CHECK)
# if defined(C_SINGLE_RECEIVE_CHANNEL)
#  define assertHardware(p,c,e) if (!(p))   ApplNmpduFatalError(e)
# else
#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#   define assertHardware(p,c,e) if (!(p))  ApplNmpduFatalError(c,e);
#  else
#   define assertHardware(p,e)  if (!(p))   ApplNmpduFatalError(e);
#  endif
# endif
#else
# define assertHardware(a,c,b)
#endif

#if defined(C_ENABLE_INTERNAL_CHECK)
# if defined(C_SINGLE_RECEIVE_CHANNEL)
#  define assertInternal(p,c,e) if (!(p))   ApplNmpduFatalError(e)
# else
#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#   define assertInternal(p,c,e) if (!(p))  ApplNmpduFatalError(c,e);
#  else
#   define assertInternal(p,e)  if (!(p))   ApplNmpduFatalError(e);
#  endif
# endif
#else
# define assertInternal(p,c,e)
#endif


/* CODE CATEGORY 4 START */

void NM_API_CALL_TYPE i_nmpduPutWakeup_EPS(vuint8* txDataPtr)
{
  if(nmpduEvalActive(txDataPtr) != 0)
  {
    CanInterruptDisable();
    /* container type is nByte */
    UdTxWakeup_EPS[1] = txDataPtr[0];
    UdTxWakeup_EPS[2] = txDataPtr[1];
    UdTxWakeup_EPS[3] = txDataPtr[2];
    CanInterruptRestore();
    startalive_broadcast_queue[0] = 2;
  }
}

/* CODE CATEGORY 4 END */


/* CODE CATEGORY 4 START */

void NM_API_CALL_TYPE i_nmpduPutAwake_EPS(vuint8* txDataPtr)
{
  if(nmpduEvalActive(txDataPtr) != 0)
  {
    CanInterruptDisable();
    /* container type is nByte */
    UdTxAwake_EPS[1] = txDataPtr[0];
    UdTxAwake_EPS[2] = txDataPtr[1];
    UdTxAwake_EPS[3] = txDataPtr[2];
    CanInterruptRestore();
    ring_queue[0] = 15;
  }
}

/* CODE CATEGORY 4 END */



/* Filling provided functions of NM */


/* CODE CATEGORY 4 START */


static vuint8 nmpduEvalActive(const vuint8 *txDataPtr)
{
  if((txDataPtr[0] != 0xFF) ||
     (txDataPtr[1] != 0xFF) ||
     (txDataPtr[2] != 0xFF))
  {
     return((vuint8)1);
  }
  else
  {
     return((vuint8)0);
  }
}

/* CODE CATEGORY 4 END */

/* CODE CATEGORY 2 START */


/***********************************************************************************/
/* NAME:           ApplNmIndSendStartAliveBroadcast(vuint8*)                     */
/* CALLED BY:      OSEK-NM                                                         */
/* PRECONDITIONS:  NM_ENABLE_SEND_ALIVE_BROADCAST                                  */
/* RETURN VALUE:   send/not send userdata E_OK/E_NotOK                             */
/* DESCRIPTION:    Indication of Start Alive Broadcast userdata service (sending)  */
/***********************************************************************************/
StatusType NM_API_CALLBACK_TYPE ApplNmIndSendStartAliveBroadcast(vuint8* txDataPtr)
{
  if (DpmAwakeFlags_buffer[0].DpmWakeupReason_CAN != 0)
  {
    startalive_broadcast_queue[0] = 2;
  }
  if(startalive_broadcast_queue[0] == 2)
  {
    if (DpmAwakeFlags_buffer[0].DpmWakeupReason_CAN != 0)
    {
      UdTxWakeup_EPS[1] = 0;
      UdTxWakeup_EPS[2] = 0;
      UdTxWakeup_EPS[3] = 0;
      DpmAwakeFlags_buffer[0].DpmWakeupReason_CAN = 0;
    }
    CanInterruptDisable();
    VStdMemCpyRamToRam(txDataPtr, UdTxWakeup_EPS, 5);
    CanInterruptRestore();
    return(E_OK);
  }
  return(E_NotOK);
}

/* CODE CATEGORY 2 END */

/* CODE CATEGORY 1 START */



/* CODE CATEGORY 1 END */

/* CODE CATEGORY 2 START */


/***********************************************************************************/
/* NAME:           ApplNmIndRingResource(vuint8*, NmUDTxPermissionType)          */
/* CALLED BY:      OSEK-NM                                                         */
/* PRECONDITIONS:  NM_ENABLE_RECEIVE_RING_BROADCAST or                             */
/*                 NM_ENABLE_SEND_RING_DATA and NmGetRingResource() called         */
/* RETURN VALUE:   -                                                               */
/* DESCRIPTION:    Indication of free ring ressource                               */
/***********************************************************************************/
void NM_API_CALLBACK_TYPE ApplNmIndRingResource(vuint8* txDataPtr, NmUDTxPermissionType ud_tx_perm)
{
  if(ring_queue[0] == 15)
  {
    tAwake_EPS udcontainer;
    /* container type is nByte */
    ((vuint8*) &udcontainer)[0] = UdTxAwake_EPS[1];
    ((vuint8*) &udcontainer)[1] = UdTxAwake_EPS[2];
    ((vuint8*) &udcontainer)[2] = UdTxAwake_EPS[3];
    if (DpmAwakeFlags_buffer[0].DpmAwakeReason_CAN != 0)
    {
      SetBitTxAwake_NwSt(udcontainer);
    }
    else
    {
      ClearBitTxAwake_NwSt(udcontainer);
    }
    if (DpmAwakeFlags_buffer[0].DpmAwakeReason_Diag != 0)
    {
      SetBitTxAwake_Diag_Actv(udcontainer);
    }
    else
    {
      ClearBitTxAwake_Diag_Actv(udcontainer);
    }
    /* container type is nByte */
    UdTxAwake_EPS[1] = ((vuint8*) &udcontainer)[0];
    UdTxAwake_EPS[2] = ((vuint8*) &udcontainer)[1];
    UdTxAwake_EPS[3] = ((vuint8*) &udcontainer)[2];
    CanInterruptDisable();
    VStdMemCpyRamToRam(txDataPtr, UdTxAwake_EPS, 5);
    CanInterruptRestore();
    ring_queue_pending = 15;
    (void)NmSendBroadcastUserData(5);
    return;
  }
  #if defined V_ENABLE_USE_DUMMY_STATEMENT
  ud_tx_perm = ud_tx_perm; /* avoid compiler warning */
  #endif
}

/* CODE CATEGORY 2 END */

/* CODE CATEGORY 2 START */

/* CODE CATEGORY 2 END */

/* CODE CATEGORY 1 START */


/***********************************************************************************/
/* NAME:           ApplNmConUserData(NmUDRxTxStatusType )                          */
/* CALLED BY:      OSEK-NM                                                         */
/* PRECONDITIONS:  NM_ENABLE_SEND_ALIVE_BROADCAST or                               */
/*                 NM_ENABLE_SEND_RING_BROADCAST or                                */
/*                 NM_ENABLE_SEND_RING_DATA                                        */
/* RETURN VALUE:   -                                                               */
/* DESCRIPTION:    Confirmation of userdata services                               */
/***********************************************************************************/
void NM_API_CALLBACK_TYPE ApplNmConUserData(NmUDRxTxStatusType txstate)
{
  if(txstate == start_alive_broadcast)
  {
    if(((vuint8*)nmSendMess)[3] ==2)
    {
      startalive_broadcast_queue[0] = 0xFF;
      return;
    }
  }
  if(txstate == ring_broadcast)
  {
    if(ring_queue_pending == 15)
    {
      ring_queue[0] = 0xFF;
      ring_queue_pending= 0xFF;
      return;
    }
  }
}

/* CODE CATEGORY 1 END */

/* CODE CATEGORY 2 START */


/***********************************************************************************/
/* NAME:           ApplNmIndUserDataError(NmUDErrorType)                           */
/* CALLED BY:      OSEK-NM                                                         */
/* PRECONDITIONS:  NM_ENABLE_RECEIVE_RING_BROADCAST or                             */
/*                 NM_ENABLE_RECEIVE_RING_DATA or                                  */
/*                 NM_ENABLE_SEND_RING_BROADCAST or                                */
/*                 NM_ENABLE_SEND_RING_DATA or                                     */
/* RETURN VALUE:   -                                                               */
/* DESCRIPTION:    Error notification of userdata services                         */
/***********************************************************************************/
void NM_API_CALLBACK_TYPE ApplNmIndUserDataError(NmUDErrorType uderr)
{
  #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  uderr = uderr; /* to avoid compiler warning */
  #endif
  /* No notifcation for channel 0 selected */
}

/* CODE CATEGORY 2 END */

/* CODE CATEGORY 2 START */


/***********************************************************************************/
/* NAME:           ApplNmUserDataTask(void)                                        */
/* CALLED BY:      OSEK-NM                                                         */
/* PRECONDITIONS:  called by Network Management                                    */
/* RETURN VALUE:   -                                                               */
/* DESCRIPTION:    cyclic task for userdata services                               */
/***********************************************************************************/
void NM_API_CALLBACK_TYPE ApplNmUserDataTask(void)
{
  if ((DpmAwakeFlags_buffer[0].DpmAwakeReason_CAN != 0) || (DpmAwakeFlags_buffer[0].DpmAwakeReason_Diag != 0))
  {
    ring_queue[0] = 15;
  }
  if(ring_queue[0] != 0xFF)
  {
    (void)NmGetRingResource();
    return;
  }
}

/* CODE CATEGORY 2 END */

/* CODE CATEGORY 4 START */


/***********************************************************************************/
/* NAME:           ApplNmUserDataInit(void)                                        */
/* CALLED BY:      OSEK-NM                                                         */
/* PRECONDITIONS:  called by Network Management                                    */
/* RETURN VALUE:   -                                                               */
/* DESCRIPTION:    initialize userdata services                                    */
/***********************************************************************************/
void NM_API_CALLBACK_TYPE ApplNmUserDataInit(void)
{
  /* initialize constant part of sendbuffer */
  UdTxWakeup_EPS[0] = 2;
  UdTxWakeup_EPS[4] = 0;
  UdTxAwake_EPS[0] = 15;
  UdTxAwake_EPS[4] = 0;
  /* initialize container of Ring Broadcast used by DPM */
  UdTxAwake_EPS[1] = 0;
  UdTxAwake_EPS[2] = 0;
  UdTxAwake_EPS[3] = 0;
  /* initialize startalive broadcast queue */
  startalive_broadcast_queue[0] = 0xFF;
  /* initialize ring queue */
  ring_queue[0] = 0xFF;

}

/* CODE CATEGORY 4 END */


/* Providing functions which are not used yet */
#if defined(NM_ENABLE_SEND_ALIVE_BROADCAST)

/* CODE CATEGORY 2 START */
StatusType NM_API_CALLBACK_TYPE ApplNmIndSendSkippedAliveBroadcast(vuint8* dummy)
{
  #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  dummy = dummy; /* to avoid compiler warnings */
  #endif
  return E_NotOK;
}

/* CODE CATEGORY 2 END */



/* CODE CATEGORY 2 START */
StatusType NM_API_CALLBACK_TYPE ApplNmIndSendLimphomeBroadcast(vuint8* dummy)
{
  #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  dummy = dummy; /* to avoid compiler warnings */
  #endif
  return E_NotOK;
}

/* CODE CATEGORY 2 END */
#endif
#if defined(NM_ENABLE_RECEIVE_ALIVE_BROADCAST)

/* CODE CATEGORY 1 START */
void NM_API_CALLBACK_TYPE ApplNmIndReadLimphomeBroadcastUserData(void)
{
}

/* CODE CATEGORY 1 END */


/* CODE CATEGORY 1 START */
void NM_API_CALLBACK_TYPE ApplNmIndReadSkippedAliveBroadcastUserData(void)
{
}

/* CODE CATEGORY 1 END */
#endif

#if defined(NM_ENABLE_SEND_RING_DATA)

/* CODE CATEGORY 2 START */
void NM_API_CALLBACK_TYPE ApplNmIndWriteUnprotectedUserData(vuint8* dummy)
{
  #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  dummy = dummy; /* to avoid compiler warnings */
  #endif
}

/* CODE CATEGORY 2 END */
#endif

