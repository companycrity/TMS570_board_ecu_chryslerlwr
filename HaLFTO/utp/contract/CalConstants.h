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
 * %version:          2 %
 * %derived_by:       wz7x3j %
 * %date_modified:    Fri May 10 00:04:02 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"
#include "fixmath.h"
#include "Filter_Types.h"

/*********************** Start of Auto Generated Code ************************/

/******************* File Generated on 5/9/2013 9:27:14 PM *******************/
/***************************** HaLFTO - Rev 1.0 ******************************/



extern CONST(uint16, CAL_CONST) k_HaLFActvHwTrqTime_mS_u16;
extern CONST(float32, CAL_CONST) k_HaLFActvMaxHwTrq_HwNm_f32;
extern CONST(uint16, CAL_CONST) k_HaLFActvVehSpdTime_mS_u16;
extern CONST(float32, CAL_CONST) k_HaLFActvMinVehSpd_Kph_f32;
extern CONST(float32, CAL_CONST) k_HaLFActvMaxVehSpd_Kph_f32;
extern CONST(uint16, CAL_CONST) k_HaLFActvRevGearTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_HaLFDSTSyncTime_mS_u16;

/******************** Ref ES40B-Chrysler for Park Assist *********************/
extern CONST(float32, CAL_CONST) k_TrqOverlayLimitPerc_Uls_f32;
extern CONST(uint16, CAL_CONST) k_TrqOverlaySuspendTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_HaLFDeactHwTrqTime_mS_u16;
extern CONST(float32, CAL_CONST) k_HaLFDeactMaxHwTrq_HwNm_f32;
extern CONST(uint16, CAL_CONST) k_HaLFDeactVehSpdTime_mS_u16;
extern CONST(float32, CAL_CONST) k_HaLFDeactMinVehSpd_Kph_f32;
extern CONST(float32, CAL_CONST) k_HaLFDeactMaxVehSpd_Kph_f32;
extern CONST(uint16, CAL_CONST) k_HaLFDeactRevGearTime_mS_u16;
#endif


