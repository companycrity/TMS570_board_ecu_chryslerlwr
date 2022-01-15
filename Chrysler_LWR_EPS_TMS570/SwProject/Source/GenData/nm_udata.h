/******************************************************************************
|   File Name: nm_udata.h
| Description: Nm User Data Signal Layer Header
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
#if !defined(NM_USERDATA_H)
#define NM_USERDATA_H


#include "n_onmdef.h"

#if defined(C_ENABLE_HARDWARE_CHECK) ||\
    defined(C_ENABLE_USER_CHECK)     ||\
    defined(C_ENABLE_GEN_CHECK)      ||\
    defined(C_ENABLE_INTERNAL_CHECK)
/* CODE CATEGORY 4 START */
#if defined(C_MULTIPLE_RECEIVE_CHANNEL)
  void NM_API_CALLBACK_TYPE ApplNmpduFatalError(CanChannelHandle channel, vuint8 errorNumber);
#else
  void NM_API_CALLBACK_TYPE ApplNmpduFatalError(vuint8 errorNumber);
#endif
/* CODE CATEGORY 4 END */
#endif
#define kErrorInvalidChannel       0x00

/* Signal access makros */
#define nmpduPutAwake_EPS(a) i_nmpduPutAwake_EPS((vuint8*) &a)
#define nmpduPutWakeup_EPS(a) i_nmpduPutWakeup_EPS((vuint8*) &a)
/* Prototypes for userdata services */
/* Prototypes for confirmation functions of userdata services */

/* Prototypes for indication functions of userdata services */

/* Prototypes for error functions of userdata services */

/*Prototypes of signal-orientated interface of userdata services */
/* CODE CATEGORY 4 START */
void NM_API_CALL_TYPE i_nmpduPutWakeup_EPS(vuint8* txDataPtr);
/* CODE CATEGORY 4 END */
/* CODE CATEGORY 4 START */
void NM_API_CALL_TYPE i_nmpduPutAwake_EPS(vuint8* txDataPtr);
/* CODE CATEGORY 4 END */

/*Prototypes of signal-orientated interface of userdata services */

/* Typedef for DPM awake reason flags */
typedef struct
{
  vbittype DpmWakeupReason_CAN : 1;
  vbittype DpmAwakeReason_CAN  : 1;
  vbittype DpmAwakeReason_Diag : 1;
}
DpmAwakeFlags_buffer_type;

/* RAM CATEGORY 2 START */
extern volatile DpmAwakeFlags_buffer_type DpmAwakeFlags_buffer[1];
/* RAM CATEGORY 2 END */

/* Macros for accessing DPM awake reason flags */
#define nmpduDpmAwakeReasonCAN(a)   DpmAwakeFlags_buffer[a].DpmAwakeReason_CAN
#define nmpduDpmAwakeReasonDiag(a)  DpmAwakeFlags_buffer[a].DpmAwakeReason_Diag
#define nmpduDpmWakeupReasonCAN(a)  DpmAwakeFlags_buffer[a].DpmWakeupReason_CAN


#endif

