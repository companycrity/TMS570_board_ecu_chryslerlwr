/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CalConstants.h
* Module Description: This file contains the declarations of calibration 
*                     constants used in the EPS Software.
* Product           : Gen II Plus EA3.0
* Author            : Blake Latchford
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          1 %
 * %derived_by:       zz4r1x %
 * %date_modified:    Fri Nov  2 14:56:16 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"
#include "fixmath.h"
#include "Filter_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 11/2/2012 1:57:22 PM *******************/
/****************************** PAwTO - Rev 1.0 ******************************/



extern CONST(uint16, CAL_CONST) k_HandsOnLPFKn_Cnt_u16;
extern CONST(uint32, CAL_CONST) k_TrqOverlayHandsOnTrq_HwNm_u5p27;
extern CONST(uint16, CAL_CONST) k_PARvsGearChkTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_PATrqOvNotZeroChkTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_PAVehSpdNotLowTime_mS_u16;
extern CONST(float32, CAL_CONST) k_PAVSpdNotLowMin_Kph_f32;
extern CONST(float32, CAL_CONST) k_PAVSpdNotLowMax_Kph_f32;
extern CONST(uint16, CAL_CONST) k_PAIWSSWhlSpinSetTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_PAIWSSWhlSpinClrTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_PAExcessVehSpdSetTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_PAExcessVehSpdClrTime_mS_u16;
extern CONST(float32, CAL_CONST) k_PAExcessVehSpd_Kph_f32;
extern CONST(uint16, CAL_CONST) k_PAMovMismatchSetTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_PAMovMismatchClrTime_mS_u16;
extern CONST(float32, CAL_CONST) k_PAMovMismatchVSpd_Kph_f32;
extern CONST(uint16, CAL_CONST) k_PAVspdMismatchSetTime_mS_u16;
extern CONST(float32, CAL_CONST) k_PAEIWSSChkVspd_Kph_f32;
extern CONST(uint16, CAL_CONST) k_PABoostCurveTime_mS_u16;
extern CONST(float32, CAL_CONST) k_TrqOverlayLimitPerc_Uls_f32;
extern CONST(uint16, CAL_CONST) k_TrqOverlaySuspendTime_mS_u16;
#endif


