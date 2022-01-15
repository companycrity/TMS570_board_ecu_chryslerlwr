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
 * %version:          2 %
 * %derived_by:       rz3h1n %
 * %date_modified:    Thu Jul 19 17:12:47 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 7/19/2012 3:57:18 PM *******************/
/***************************** WhlImbRej - Rev 1 *****************************/



/**************************** GM_K2XX_EPS_TMS570 *****************************/
extern CONST(float32, CAL_CONST) k_AdaptiveMu_Uls_f32;
extern CONST(float32, CAL_CONST) k_DistMagLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_EnSlewPerLoop_Uls_f32;
extern CONST(float32, CAL_CONST) k_MagEstDeltaScale_Uls_f32;
extern CONST(float32, CAL_CONST) k_MagEstDisable_Uls_f32;
extern CONST(float32, CAL_CONST) k_MagEstEnable_Uls_f32;
extern CONST(float32, CAL_CONST) k_MagEstFreq_Hz_f32;
extern CONST(float32, CAL_CONST) k_MagEstFreqDelta_Hz_f32;
extern CONST(float32, CAL_CONST) k_MagEstLeak_Uls_f32;
extern CONST(float32, CAL_CONST) k_WhlImbCmdMax_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_WhlSpdCorrThresh_Pct_f32;
extern CONST(uint16, CAL_CONST) k_WhlSpdCorrTime_mS_u16p0;
extern CONST(float32, CAL_CONST) k_WhlSpdLPFKn_Hz_f32;
extern CONST(uint16, CAL_CONST) t_FreqScaleTblX_Hz_u7p9[6];
extern CONST(uint16, CAL_CONST) t_FreqScaleTblY_Uls_u2p14[6];
extern CONST(uint16, CAL_CONST) t_PhaseAdjustX_Hz_u7p9[3];
extern CONST(sint16, CAL_CONST) t_PhaseAdjustY_Deg_s8p7[3];
extern CONST(uint16, CAL_CONST) k_WIRMaxDur_Cnt_u16;
extern CONST(float32, CAL_CONST) k_WIRDCTrendTh_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_WIRDCTrendTime_Sec_f32;
extern CONST(float32, CAL_CONST) k_WIRMaxMag_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_CurrMagSlewPerLoop_Uls_f32;
extern CONST(float32, CAL_CONST) k_FreqDiagThresh_MtrNm_f32;
extern CONST(uint16, CAL_CONST) k_FreqDiagTimeout_mS_u16p0;
extern CONST(float32, CAL_CONST) k_FreqDiagWIRAmpThresh_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_BlndCmdMagLPFKn1_Hz_f32;
extern CONST(float32, CAL_CONST) k_BlndCmdMagLPFKn2_Hz_f32;
extern CONST(float32, CAL_CONST) k_WIRVehSpdEnable_Kph_f32;
extern CONST(float32, CAL_CONST) k_WIRDCTrendTh2_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_WIRDCTrendTime2_Sec_f32;
extern CONST(uint16, CAL_CONST) k_NumberOfTaps_Cnt_u16;
extern CONST(boolean, CAL_CONST) k_FreqDiagEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_ScaleCancel_Uls_f32;
extern CONST(float32, CAL_CONST) k_UGRPoleMag_Uls_f32;
extern CONST(uint16, CAL_CONST) k_WIRRampDownTime_mS_u16p0;
extern CONST(float32, CAL_CONST) k_CmdMagLPFKn1_Hz_f32;
extern CONST(float32, CAL_CONST) k_CmdMagLPFKn2_Hz_f32;
extern CONST(float32, CAL_CONST) k_MaxMagFltRecDly_Min_f32;
extern CONST(uint8, CAL_CONST) k_MaxMagFltRecLim_Cnt_u8;
extern CONST(float32, CAL_CONST) k_CorrFltRecDly_Min_f32;
extern CONST(uint8, CAL_CONST) k_CorrFltRecLim_Cnt_u8;
extern CONST(float32, CAL_CONST) k_DCTrendFltRecDly_Min_f32;
extern CONST(uint8, CAL_CONST) k_DCTrendFltRecLim_Cnt_u8;
extern CONST(float32, CAL_CONST) k_FreqDiagFltRecDly_Min_f32;
extern CONST(uint8, CAL_CONST) k_FreqDiagFltRecLim_Cnt_u8;
extern CONST(float32, CAL_CONST) k_WIRDCTrendLPFKn_Hz_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_WIRMaxMagDiag_Cnt_Str;
extern CONST(boolean, CAL_CONST) k_AutoScaleEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_AutoScaleTarget_RadpSec_f32;
extern CONST(float32, CAL_CONST) k_FreqDiagLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_FreqDiagUGRPoleMag_Uls_f32;
#endif
