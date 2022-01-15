/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CalConstants.h
* Module Description: This file contains the declarations of calibration 
*                     constants used in the EPS Software.
* Product           : Gen II Plus EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          1 %
 * %derived_by:       rz3h1n %
 * %date_modified:    Mon Nov 26 16:58:12 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"
#include "fixmath.h"
#include "Filter_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 11/6/2012 6:16:35 PM *******************/
/****************************** STBCTO - Rev 1 *******************************/


extern CONST(float32, CAL_CONST) k_DSTVSpdVLH_Kph_f32;
extern CONST(float32, CAL_CONST) k_DSTVSpdVHH_Kph_f32;
extern CONST(float32, CAL_CONST) k_DSTVSpdVLL_Kph_f32;
extern CONST(float32, CAL_CONST) k_DSTVSpdVHL_Kph_f32;
extern CONST(uint16, CAL_CONST) k_DSTVehSpdActvTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_DSTVehSpdInActvTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_DSTBkwdMotionTime_mS_u16;
extern CONST(float32, CAL_CONST) k_TrqOverlayLimitPerc_Uls_f32;
extern CONST(uint32, CAL_CONST) k_TrqOverlaySuspendTime_mS_u16;
extern CONST(float32, CAL_CONST) k_DSTTrqOvActiveMaxLimit_MtrNm_f32;
extern CONST(uint16, CAL_CONST) k_DSTTNAMaxTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_DSTRDMaxTime_mS_u16;
extern CONST(uint8, CAL_CONST) k_DSTRDStateMaxCount_Cnt_u08;
#endif
