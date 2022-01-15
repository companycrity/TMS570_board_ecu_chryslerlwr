/*****************************************************************************
* Copyright 2010 Nexteer Automotive., All Rights Reserved.
* Nexteer Confidential
*
* Module File Name : CalConstants.c
* Module Description: This file contains the definitions of calibration
* constants used in the EPS Software.
* Product : Gen II Plus EA3.0
* Author : Lucas Wendling
*****************************************************************************/
/* Version Control:
* Date Created: Wed Apr 13 12:17:00 2011
* %version: 28.1.44.1.7 %
* %derived_by: jzh87w %
* %date_modified: Tue Feb 25 16:26:41 2014 %
*/

/* NOTE:
 * THIS FILE WAS HAND MODIFIED AND NOT GENEREATED.
 * REMOVE THIS COMMENT AFTER INTEGRATION DATA DICTIONARY HAS BEEN CREATED
 */

#include "CalConstants.h"

#define D_NUMOFTUNSETS_CNT_U16 	15U
#define D_NUMOFPERS_CNT_U16 	3U

#define CALCONSTANTS_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

P2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) TunPer_Ptr_Str;
P2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) TunSet_Ptr_Str;

#define CALCONSTANTS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/* Put this at end of file
CONSTP2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) T_TunSetSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16] =
		{	&k_TunSet0_Cnt_Str};

CONSTP2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) T_TunPersSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16][D_NUMOFPERS_CNT_U16] =
		{	{	&k_TunSet0Per0_Cnt_Str
										}};
*/


/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 2/25/2014 4:25:50 PM *******************/
/*********************** Chrysler LWR Project - Rev 6 ************************/



/************** AbsHwPos, My_LWR_WA, My_ePWM_LWR, AbsHwPosScom ***************/
#pragma DATA_SECTION(t_MtrPosComplTblX_MtrNm_u8p8, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_MtrPosComplTblX_MtrNm_u8p8[6] = 
	{ FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(0.0, u8p8_T) };

#pragma DATA_SECTION(t_MtrPosComplTblY_HwDegpMtrNm_u6p10, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_MtrPosComplTblY_HwDegpMtrNm_u6p10[6] = 
	{ FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T) };


/************************** AbsHwPos, AbsHwPosScom ***************************/
#pragma DATA_SECTION(k_InvGearRatio_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_InvGearRatio_Uls_f32 = 22.0f;


/*************************************  **************************************/
#pragma DATA_SECTION(k_CurrCorrErrFiltKn_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_CurrCorrErrFiltKn_Cnt_u16 = 1462U;


/********************************* CmMtrCurr *********************************/
#pragma DATA_SECTION(k_CurrCorrErrThresh_Amps_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CurrCorrErrThresh_Amps_f32 = 0.0f;

#pragma DATA_SECTION(k_MtrPosComputDelay_Sec_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MtrPosComputDelay_Sec_f32 = 0.000096f;

#pragma DATA_SECTION(k_MtrCurrEOLMinOffset_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MtrCurrEOLMinOffset_Volts_f32 = 2.2f;

#pragma DATA_SECTION(k_MtrCurrEOLMaxOffset_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MtrCurrEOLMaxOffset_Volts_f32 = 2.8f;

#pragma DATA_SECTION(k_MtrCurrEOLMinGain_AmpspVolts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MtrCurrEOLMinGain_AmpspVolts_f32 = 90.0f;

#pragma DATA_SECTION(k_MtrCurrEOLMaxGain_AmpspVolts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MtrCurrEOLMaxGain_AmpspVolts_f32 = 110.0f;

#pragma DATA_SECTION(k_CurrGainNumerator_Amps_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CurrGainNumerator_Amps_f32 = 45.0f;

#pragma DATA_SECTION(k_MaxCurrOffMtrVel_RadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MaxCurrOffMtrVel_RadpS_f32 = 10.0f;

#pragma DATA_SECTION(k_CurrOffGainKn_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_CurrOffGainKn_Cnt_u16 = 1462U;


/******************************* CurrReasDiag ********************************/
#pragma DATA_SECTION(k_IPMMtrSwitch_Cnt_lgc, ".FlashCal1Seg");
CONST(boolean, CAL_CONST) k_IPMMtrSwitch_Cnt_lgc = TRUE;


/******************************* CtrldDisShtdn *******************************/
#pragma DATA_SECTION(k_F2Damping_MtrNmpRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_F2Damping_MtrNmpRadpS_f32 = 0.036f;

#pragma DATA_SECTION(k_CtrlDpVelThr_MtrRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CtrlDpVelThr_MtrRadpS_f32 = 2.3f;

#pragma DATA_SECTION(k_MaxCtrlDmpLimit_MtrNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MaxCtrlDmpLimit_MtrNm_f32 = 3.0f;

#pragma DATA_SECTION(k_CtrlDmpTmrBkptOne_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_CtrlDmpTmrBkptOne_mS_u16 = 100U;

#pragma DATA_SECTION(k_CtrlDmpTmrBkptTwo_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_CtrlDmpTmrBkptTwo_mS_u16 = 1000U;


/********************************* CtrlTemp **********************************/
#pragma DATA_SECTION(k_TempSnsrFiltDft_Cnt_lgc, ".FlashCal1Seg");
CONST(boolean, CAL_CONST) k_TempSnsrFiltDft_Cnt_lgc = FALSE;

#pragma DATA_SECTION(k_TempSnsrDefVal_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TempSnsrDefVal_DegC_f32 = 60.0f;

#pragma DATA_SECTION(k_TempSensDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_TempSensDiag_Cnt_str = {40,2,1};

#pragma DATA_SECTION(k_TempSensLowLimit_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TempSensLowLimit_DegC_f32 = -40.0f;

#pragma DATA_SECTION(k_TempSensHighLimit_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TempSensHighLimit_DegC_f32 = 150.0f;


/********************** CurrCmd, IPMCurrCmd, MtrCtrl_CM **********************/
#pragma DATA_SECTION(k_NoofPoles_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_NoofPoles_Uls_f32 = 6.0f;


/**************************** CurrCmd, IPMCurrCmd ****************************/
#pragma DATA_SECTION(k_a0IdSlope_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_a0IdSlope_Uls_f32 = 0.79006f;

#pragma DATA_SECTION(k_a1IdSlope_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_a1IdSlope_Uls_f32 = 0.00795f;

#pragma DATA_SECTION(k_a2IdSlope_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_a2IdSlope_Uls_f32 = 0.0284f;

#pragma DATA_SECTION(k_K2Slope_RadpSecpNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_K2Slope_RadpSecpNm_f32 = -13.047f;

#pragma DATA_SECTION(k_K3VelIntercep_RadpSec_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_K3VelIntercep_RadpSec_f32 = 270.146f;

#pragma DATA_SECTION(k_IdrefMtrVelOffset_RadpSec_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_IdrefMtrVelOffset_RadpSec_f32 = 10.472f;

#pragma DATA_SECTION(k_MtrMaxCurr_AmpsSq_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MtrMaxCurr_AmpsSq_f32 = 28900.0f;


/********************** CurrCmd, IPMCurrCmd, MtrCtrl_CM **********************/
#pragma DATA_SECTION(k_PIGainVspdCutoff_kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PIGainVspdCutoff_kph_f32 = 3.0f;

#pragma DATA_SECTION(t_KpqGainX_MtrRadpSec_u12p4, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_KpqGainX_MtrRadpSec_u12p4[8] = 
	{FPM_InitFixedPoint_m(0.0, u12p4_T),FPM_InitFixedPoint_m(5.0, u12p4_T),
	FPM_InitFixedPoint_m(50.0, u12p4_T),FPM_InitFixedPoint_m(100.0, u12p4_T),
	FPM_InitFixedPoint_m(200.0, u12p4_T),
	FPM_InitFixedPoint_m(300.0, u12p4_T),
	FPM_InitFixedPoint_m(400.0, u12p4_T),
	FPM_InitFixedPoint_m(500.0, u12p4_T)};

#pragma DATA_SECTION(t_KpqGainY_Uls_u6p10, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_KpqGainY_Uls_u6p10[8] = 
	{FPM_InitFixedPoint_m(0.015, u6p10_T),
	FPM_InitFixedPoint_m(0.03, u6p10_T),FPM_InitFixedPoint_m(0.03, u6p10_T),
	FPM_InitFixedPoint_m(0.05, u6p10_T),FPM_InitFixedPoint_m(0.05, u6p10_T),
	FPM_InitFixedPoint_m(0.05, u6p10_T),FPM_InitFixedPoint_m(0.05, u6p10_T),
	FPM_InitFixedPoint_m(0.05, u6p10_T)};

#pragma DATA_SECTION(t_KiqGainX_MtrRadpSec_u12p4, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_KiqGainX_MtrRadpSec_u12p4[8] = 
	{FPM_InitFixedPoint_m(0.0, u12p4_T),FPM_InitFixedPoint_m(5.0, u12p4_T),
	FPM_InitFixedPoint_m(50.0, u12p4_T),FPM_InitFixedPoint_m(100.0, u12p4_T),
	FPM_InitFixedPoint_m(200.0, u12p4_T),
	FPM_InitFixedPoint_m(300.0, u12p4_T),
	FPM_InitFixedPoint_m(400.0, u12p4_T),
	FPM_InitFixedPoint_m(500.0, u12p4_T)};

#pragma DATA_SECTION(t_KiqGainY_Uls_u10p6, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_KiqGainY_Uls_u10p6[8] = 
	{FPM_InitFixedPoint_m(16.0, u10p6_T),FPM_InitFixedPoint_m(50.0, u10p6_T),
	FPM_InitFixedPoint_m(100.0, u10p6_T),
	FPM_InitFixedPoint_m(100.0, u10p6_T),
	FPM_InitFixedPoint_m(100.0, u10p6_T),
	FPM_InitFixedPoint_m(100.0, u10p6_T),
	FPM_InitFixedPoint_m(100.0, u10p6_T),
	FPM_InitFixedPoint_m(100.0, u10p6_T)};

#pragma DATA_SECTION(t_KpdGainX_MtrRadpSec_u12p4, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_KpdGainX_MtrRadpSec_u12p4[8] = 
	{FPM_InitFixedPoint_m(0.0, u12p4_T),FPM_InitFixedPoint_m(5.0, u12p4_T),
	FPM_InitFixedPoint_m(50.0, u12p4_T),FPM_InitFixedPoint_m(100.0, u12p4_T),
	FPM_InitFixedPoint_m(200.0, u12p4_T),
	FPM_InitFixedPoint_m(300.0, u12p4_T),
	FPM_InitFixedPoint_m(400.0, u12p4_T),
	FPM_InitFixedPoint_m(500.0, u12p4_T)};

#pragma DATA_SECTION(t_KpdGainY_Uls_u6p10, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_KpdGainY_Uls_u6p10[8] = 
	{FPM_InitFixedPoint_m(0.015, u6p10_T),
	FPM_InitFixedPoint_m(0.03, u6p10_T),FPM_InitFixedPoint_m(0.03, u6p10_T),
	FPM_InitFixedPoint_m(0.05, u6p10_T),FPM_InitFixedPoint_m(0.05, u6p10_T),
	FPM_InitFixedPoint_m(0.05, u6p10_T),FPM_InitFixedPoint_m(0.05, u6p10_T),
	FPM_InitFixedPoint_m(0.05, u6p10_T)};

#pragma DATA_SECTION(t_KidGainX_MtrRadpSec_u12p4, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_KidGainX_MtrRadpSec_u12p4[8] = 
	{FPM_InitFixedPoint_m(0.0, u12p4_T),FPM_InitFixedPoint_m(5.0, u12p4_T),
	FPM_InitFixedPoint_m(50.0, u12p4_T),FPM_InitFixedPoint_m(100.0, u12p4_T),
	FPM_InitFixedPoint_m(200.0, u12p4_T),
	FPM_InitFixedPoint_m(300.0, u12p4_T),
	FPM_InitFixedPoint_m(400.0, u12p4_T),
	FPM_InitFixedPoint_m(500.0, u12p4_T)};

#pragma DATA_SECTION(t_KidGainY_Uls_u10p6, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_KidGainY_Uls_u10p6[8] = 
	{FPM_InitFixedPoint_m(16.0, u10p6_T),FPM_InitFixedPoint_m(50.0, u10p6_T),
	FPM_InitFixedPoint_m(100.0, u10p6_T),
	FPM_InitFixedPoint_m(100.0, u10p6_T),
	FPM_InitFixedPoint_m(100.0, u10p6_T),
	FPM_InitFixedPoint_m(100.0, u10p6_T),
	FPM_InitFixedPoint_m(100.0, u10p6_T),
	FPM_InitFixedPoint_m(100.0, u10p6_T)};


/************** PICurrCntrl, CurrCmd, CurrParamComp, IPMCurrCmd **************/
#pragma DATA_SECTION(k_MtrTypeSwitch_Cnt_lgc, ".FlashCal1Seg");
CONST(boolean, CAL_CONST) k_MtrTypeSwitch_Cnt_lgc = FALSE;


/********************** CurrCmd, IPMCurrCmd, MtrCtrl_CM **********************/
#pragma DATA_SECTION(k_MtrPosComputationDelay_Sec_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MtrPosComputationDelay_Sec_f32 = 0.00009375f;


/************************* CurrParamComp, MtrCtrl_CM *************************/
#pragma DATA_SECTION(k_MinKeRngLmt_VpRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MinKeRngLmt_VpRadpS_f32 = 0.026f;

#pragma DATA_SECTION(k_MaxKeRngLmt_VpRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MaxKeRngLmt_VpRadpS_f32 = 0.06f;

#pragma DATA_SECTION(k_MinRRngLmt_Ohm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MinRRngLmt_Ohm_f32 = 0.01f;

#pragma DATA_SECTION(k_MaxRRngLmt_Ohm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MaxRRngLmt_Ohm_f32 = 0.06f;

#pragma DATA_SECTION(k_MinLqRngLmt_Henry_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MinLqRngLmt_Henry_f32 = 0.0001f;

#pragma DATA_SECTION(k_MaxLqRngLmt_Henry_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MaxLqRngLmt_Henry_f32 = 0.0002f;

#pragma DATA_SECTION(k_MinLdRngLmt_Henry_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MinLdRngLmt_Henry_f32 = 0.0001f;

#pragma DATA_SECTION(k_MaxLdRngLmt_Henry_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MaxLdRngLmt_Henry_f32 = 0.0002f;

#pragma DATA_SECTION(k_NomTemp_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_NomTemp_DegC_f32 = 25.0f;

#pragma DATA_SECTION(k_MagThrC_VpRadpSpDegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MagThrC_VpRadpSpDegC_f32 = -0.001f;

#pragma DATA_SECTION(k_NomRfet_Ohm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_NomRfet_Ohm_f32 = 0.00625f;

#pragma DATA_SECTION(k_SiThermCoeff_OhmpDegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_SiThermCoeff_OhmpDegC_f32 = 0.005f;

#pragma DATA_SECTION(k_CuThermCoeff_OhmpDegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CuThermCoeff_OhmpDegC_f32 = 0.00393f;

#pragma DATA_SECTION(t_KeSatTblX_Amp_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_KeSatTblX_Amp_u9p7[16] = 
	{ FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(10.0, u9p7_T),
	 FPM_InitFixedPoint_m(25.0, u9p7_T), FPM_InitFixedPoint_m(35.0, u9p7_T),
	 FPM_InitFixedPoint_m(45.0, u9p7_T), FPM_InitFixedPoint_m(55.0, u9p7_T),
	 FPM_InitFixedPoint_m(65.0, u9p7_T), FPM_InitFixedPoint_m(75.0, u9p7_T),
	 FPM_InitFixedPoint_m(85.0, u9p7_T), FPM_InitFixedPoint_m(95.0, u9p7_T),
	 FPM_InitFixedPoint_m(105.0, u9p7_T),
	 FPM_InitFixedPoint_m(115.0, u9p7_T),
	 FPM_InitFixedPoint_m(125.0, u9p7_T),
	 FPM_InitFixedPoint_m(135.0, u9p7_T),
	 FPM_InitFixedPoint_m(145.0, u9p7_T),
	 FPM_InitFixedPoint_m(150.0, u9p7_T) };

#pragma DATA_SECTION(t_KeSatTblY_Uls_u2p14, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_KeSatTblY_Uls_u2p14[16] = 
	{ FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.998046875, u2p14_T),
	 FPM_InitFixedPoint_m(0.998046875, u2p14_T),
	 FPM_InitFixedPoint_m(0.994140625, u2p14_T),
	 FPM_InitFixedPoint_m(0.9921875, u2p14_T),
	 FPM_InitFixedPoint_m(0.98828125, u2p14_T),
	 FPM_InitFixedPoint_m(0.982421875, u2p14_T),
	 FPM_InitFixedPoint_m(0.974609375, u2p14_T),
	 FPM_InitFixedPoint_m(0.966796875, u2p14_T),
	 FPM_InitFixedPoint_m(0.95703125, u2p14_T),
	 FPM_InitFixedPoint_m(0.9453125, u2p14_T),
	 FPM_InitFixedPoint_m(0.931640625, u2p14_T),
	 FPM_InitFixedPoint_m(0.916015625, u2p14_T),
	 FPM_InitFixedPoint_m(0.90625, u2p14_T) };

#pragma DATA_SECTION(t_CurrParamCompDaxRef_Amp_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_CurrParamCompDaxRef_Amp_u9p7[6] = 
	{ FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(25.0, u9p7_T),
	FPM_InitFixedPoint_m(50.0, u9p7_T),FPM_InitFixedPoint_m(75.0, u9p7_T),
	FPM_InitFixedPoint_m(100.0, u9p7_T),FPM_InitFixedPoint_m(125.0, u9p7_T) };

#pragma DATA_SECTION(t_CurrParamCompQaxRef_Amp_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_CurrParamCompQaxRef_Amp_u9p7[7] = 
	{ FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(25.0, u9p7_T),
	FPM_InitFixedPoint_m(50.0, u9p7_T),FPM_InitFixedPoint_m(75.0, u9p7_T),
	FPM_InitFixedPoint_m(100.0, u9p7_T),FPM_InitFixedPoint_m(125.0, u9p7_T),
	FPM_InitFixedPoint_m(150.0, u9p7_T) };


/******************************* CurrReasDiag ********************************/
#pragma DATA_SECTION(k_CurrReasErrAllow_Amp_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CurrReasErrAllow_Amp_f32 = 12.0f;

#pragma DATA_SECTION(k_CurrReasKValHi_CntpAmp_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CurrReasKValHi_CntpAmp_f32 = 0.45f;

#pragma DATA_SECTION(k_CurrReasKValLo_CntpAmp_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CurrReasKValLo_CntpAmp_f32 = 0.39f;

#pragma DATA_SECTION(k_CurrReasMaxFiltCnt_Cnt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CurrReasMaxFiltCnt_Cnt_f32 = 250.0f;

#pragma DATA_SECTION(k_CurrReasNStep_Cnt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CurrReasNStep_Cnt_f32 = 10.0f;

#pragma DATA_SECTION(k_CurrReasMaxErr_Amp_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CurrReasMaxErr_Amp_f32 = 250.0f;


/********************************** DiagMgr **********************************/
#pragma DATA_SECTION(k_FltRmpRate_UlspmS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_FltRmpRate_UlspmS_f32[13] = { 0.0005f, 0.0005f,
	 0.0005f, 0.0005f, 0.0005f, 0.0005f, 0.0005f, 0.0005f, 0.0005f, 0.0005f,
	 0.0005f, 0.0005f, 0.0005f };

#pragma DATA_SECTION(k_FltRspTbl_Cnt_str, ".FlashCal1Seg");
CONST(FltRsp_Str, CAL_CONST) k_FltRspTbl_Cnt_str[512] = { {0x000000, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}  };


/************************** DigPhsReasDiag, SVDiag ***************************/
#pragma DATA_SECTION(k_PhsReasErrorTerm_Cnt_s16, ".FlashCal1Seg");
CONST(sint16, CAL_CONST) k_PhsReasErrorTerm_Cnt_s16 = 0;

#pragma DATA_SECTION(k_ErrorFiltKn_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_ErrorFiltKn_Cnt_u16 = 1462U;

#pragma DATA_SECTION(k_ErrorThresh_Cnt_u32, ".FlashCal1Seg");
CONST(uint32, CAL_CONST) k_ErrorThresh_Cnt_u32 = 14400UL;

#pragma DATA_SECTION(k_PhsReasEnableThresh_Cnt_u32, ".FlashCal1Seg");
CONST(uint32, CAL_CONST) k_PhsReasEnableThresh_Cnt_u32 = 5760UL;


/****************************** EOTActuatorMng *******************************/
#pragma DATA_SECTION(k_EOTDynConf_Uls_u8p8, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_EOTDynConf_Uls_u8p8 = 
	FPM_InitFixedPoint_m(0.80078125, u8p8_T);


/*********************************** HwTrq ***********************************/
#pragma DATA_SECTION(k_TbarStiff_NmpDeg_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TbarStiff_NmpDeg_f32 = 2.5f;


/************************ HiLoadStall, ThrmDutyCycle *************************/
#pragma DATA_SECTION(k_AbsMtrVelBkt_MtrRadps_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AbsMtrVelBkt_MtrRadps_f32 = 1.375f;


/******************************** HiLoadStall ********************************/
#pragma DATA_SECTION(k_EOTThrmPrtLPFKn_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_EOTThrmPrtLPFKn_Cnt_u16 = 1130U;

#pragma DATA_SECTION(t_EOTThrmIndptTbl_MtrNm_u8p8, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_EOTThrmIndptTbl_MtrNm_u8p8[4] = 
	{ FPM_InitFixedPoint_m(5.75, u8p8_T), FPM_InitFixedPoint_m(6.22, u8p8_T),
	 FPM_InitFixedPoint_m(6.67, u8p8_T),
	 FPM_InitFixedPoint_m(7.125, u8p8_T) };

#pragma DATA_SECTION(t_EOTThrmDpntTbl_MtrNm_u8p8, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_EOTThrmDpntTbl_MtrNm_u8p8[4] = 
	{ FPM_InitFixedPoint_m(8.5, u8p8_T), FPM_InitFixedPoint_m(8.0, u8p8_T),
	 FPM_InitFixedPoint_m(7.5, u8p8_T), FPM_InitFixedPoint_m(7.0, u8p8_T) };

#pragma DATA_SECTION(k_EOTThrmSlwLmtStp_MtrNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_EOTThrmSlwLmtStp_MtrNm_f32 = 0.1015625f;


/*********************************** HwTrq ***********************************/
#pragma DATA_SECTION(k_T1HghRange_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_T1HghRange_Volts_f32 = 4.5f;

#pragma DATA_SECTION(k_T1LowRange_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_T1LowRange_Volts_f32 = 0.5f;

#pragma DATA_SECTION(k_T2HghRange_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_T2HghRange_Volts_f32 = 4.5f;

#pragma DATA_SECTION(k_T2LowRange_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_T2LowRange_Volts_f32 = 0.5f;

#pragma DATA_SECTION(k_T1AccRecLim_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_T1AccRecLim_Cnt_u16 = 0U;

#pragma DATA_SECTION(k_T2AccRecLim_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_T2AccRecLim_Cnt_u16 = 0U;

#pragma DATA_SECTION(k_MaxTrqSumLmt_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MaxTrqSumLmt_Volts_f32 = 3.2f;

#pragma DATA_SECTION(k_TdiagLim_Volts_u5p11, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_TdiagLim_Volts_u5p11 = 
	FPM_InitFixedPoint_m(0.557, u5p11_T);

#pragma DATA_SECTION(k_CorrDiagFiltActiv_Volts_u5p11, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_CorrDiagFiltActiv_Volts_u5p11 = 
	FPM_InitFixedPoint_m(0.05, u5p11_T);

#pragma DATA_SECTION(k_CorrDiagKn_Cnts_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_CorrDiagKn_Cnts_u16 = 814U;

#pragma DATA_SECTION(k_TdiagCorrLim_Volts_u5p11, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_TdiagCorrLim_Volts_u5p11 = 
	FPM_InitFixedPoint_m(0.1, u5p11_T);

#pragma DATA_SECTION(k_SSDiagKn_Cnts_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_SSDiagKn_Cnts_u16 = 814U;

#pragma DATA_SECTION(k_SSDiagLim_Volts_u5p11, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_SSDiagLim_Volts_u5p11 = 
	FPM_InitFixedPoint_m(0.557, u5p11_T);

#pragma DATA_SECTION(t_TDiagFiltKnTbl_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_TDiagFiltKnTbl_Cnt_u16[17] = { 10667U, 10667U,
	 10667U, 10667U, 10667U, 7106U, 7330U, 6359U, 5674U, 5927U,6633U,6752U,
	6112U,5584U,5141U,4763U,4437U };

#pragma DATA_SECTION(k_SumFiltRecLim_Volt_u5p11, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_SumFiltRecLim_Volt_u5p11 = 
	FPM_InitFixedPoint_m(0.273, u5p11_T);

#pragma DATA_SECTION(k_SSFiltRecLim_Volt_u5p11, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_SSFiltRecLim_Volt_u5p11 = 
	FPM_InitFixedPoint_m(0.488, u5p11_T);

#pragma DATA_SECTION(t_TDiagIndptTbl_Volts_u5p11, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_TDiagIndptTbl_Volts_u5p11[17] = 
	{ FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.15625, u5p11_T),
	 FPM_InitFixedPoint_m(0.3125, u5p11_T),
	 FPM_InitFixedPoint_m(0.46875, u5p11_T),
	  FPM_InitFixedPoint_m(0.625, u5p11_T),
	 FPM_InitFixedPoint_m(0.78125, u5p11_T),
	 FPM_InitFixedPoint_m(0.9375, u5p11_T),
	 FPM_InitFixedPoint_m(1.09375, u5p11_T),
	 FPM_InitFixedPoint_m(1.25, u5p11_T),
	 FPM_InitFixedPoint_m(1.40625, u5p11_T),
	 FPM_InitFixedPoint_m(1.5625, u5p11_T),
	 FPM_InitFixedPoint_m(1.71875, u5p11_T),
	 FPM_InitFixedPoint_m(1.875, u5p11_T),
	 FPM_InitFixedPoint_m(2.03125, u5p11_T),
	 FPM_InitFixedPoint_m(2.1875, u5p11_T),
	 FPM_InitFixedPoint_m(2.34375, u5p11_T),
	 FPM_InitFixedPoint_m(2.5, u5p11_T) };

#pragma DATA_SECTION(k_TrqFltRecLim_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_TrqFltRecLim_Cnt_u16 = 1U;

#pragma DATA_SECTION(k_MaxHwTrqTrim_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MaxHwTrqTrim_Volts_f32 = 0.1f;

#pragma DATA_SECTION(k_HwTrqSclNom_VoltspDeg_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HwTrqSclNom_VoltspDeg_f32 = 0.5f;


/******************************** IPMCurrCmd *********************************/
#pragma DATA_SECTION(k_MtrCurrMaxAlphaErad_Rad_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MtrCurrMaxAlphaErad_Rad_f32 = 0.523598776f;

#pragma DATA_SECTION(k_MtrMaxCurrRef_Amp_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MtrMaxCurrRef_Amp_f32 = 170.0f;


/******************************** IPMTrqCanc *********************************/
#pragma DATA_SECTION(k_Harmonic6th_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_Harmonic6th_Uls_f32 = 18.0f;

#pragma DATA_SECTION(k_Harmonic12th_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_Harmonic12th_Uls_f32 = 36.0f;


/******************************** MtrTempEst *********************************/
#pragma DATA_SECTION(k_SiLLFiltKB0_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_SiLLFiltKB0_Uls_f32 = 1.68567616f;

#pragma DATA_SECTION(k_SiLLFiltKB1_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_SiLLFiltKB1_Uls_f32 = -1.685565f;

#pragma DATA_SECTION(k_SiLLFiltKA1_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_SiLLFiltKA1_Uls_f32 = 0.99988879f;

#pragma DATA_SECTION(k_MagLLFiltKB0_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MagLLFiltKB0_Uls_f32 = 0.57143665f;

#pragma DATA_SECTION(k_MagLLFiltKB1_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MagLLFiltKB1_Uls_f32 = -0.571399f;

#pragma DATA_SECTION(k_MagLLFiltKA1_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MagLLFiltKA1_Uls_f32 = 0.9999623f;

#pragma DATA_SECTION(k_CuLLFiltKB0_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CuLLFiltKB0_Uls_f32 = 0.86667048f;

#pragma DATA_SECTION(k_CuLLFiltKB1_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CuLLFiltKB1_Uls_f32 = -0.8666133f;

#pragma DATA_SECTION(k_CuLLFiltKA1_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CuLLFiltKA1_Uls_f32 = 0.99994282f;

#pragma DATA_SECTION(k_AmbPwrMult_WtspAmpSq_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AmbPwrMult_WtspAmpSq_f32 = 0.01f;

#pragma DATA_SECTION(k_SiAmbMult_DegCpWatt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_SiAmbMult_DegCpWatt_f32 = 0.0f;

#pragma DATA_SECTION(k_MagAmbMult_DegCpWatt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MagAmbMult_DegCpWatt_f32 = 0.01f;

#pragma DATA_SECTION(k_CuAmbMult_DegCpWatt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CuAmbMult_DegCpWatt_f32 = 0.75f;

#pragma DATA_SECTION(k_SiCorrLmt_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_SiCorrLmt_DegC_f32 = 60.0f;

#pragma DATA_SECTION(k_MagCorrLmt_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MagCorrLmt_DegC_f32 = 60.0f;

#pragma DATA_SECTION(k_CuCorrLmt_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CuCorrLmt_DegC_f32 = 80.0f;

#pragma DATA_SECTION(k_AMDampScl_NmpRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AMDampScl_NmpRadpS_f32 = 0.0001f;

#pragma DATA_SECTION(k_AMAmbMult_DegCpWatt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AMAmbMult_DegCpWatt_f32 = 0.01f;

#pragma DATA_SECTION(k_TrimTempSi_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TrimTempSi_DegC_f32 = 0.0f;

#pragma DATA_SECTION(k_TrimTempMag_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TrimTempMag_DegC_f32 = 0.0f;

#pragma DATA_SECTION(k_TrimTempCu_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TrimTempCu_DegC_f32 = 0.0f;

#pragma DATA_SECTION(k_TrimTempAM_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TrimTempAM_DegC_f32 = 0.0f;

#pragma DATA_SECTION(k_EngTempScl_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_EngTempScl_Uls_f32 = 0.1f;

#pragma DATA_SECTION(k_AmbTempScl_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AmbTempScl_Uls_f32 = 0.9f;

#pragma DATA_SECTION(k_AMLLFiltPoleA1_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AMLLFiltPoleA1_Uls_f32 = 0.99996858f;

#pragma DATA_SECTION(k_AMLLFiltCoefB0_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AMLLFiltCoefB0_Uls_f32 = 0.4761987f;

#pragma DATA_SECTION(k_AMLLFiltCoefB1_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AMLLFiltCoefB1_Uls_f32 = -0.4761673f;


/*************************************  **************************************/
#pragma DATA_SECTION(k_TempAMEstCorrLmt_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TempAMEstCorrLmt_DegC_f32 = 60.0f;


/******************************** MtrTempEst *********************************/
#pragma DATA_SECTION(k_AssistMechSlew_DegCpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AssistMechSlew_DegCpS_f32 = 1.0f;


/******************** CurrentEst, PeakCurrEst, MtrCtrl_CM ********************/
#pragma DATA_SECTION(k_EstPkCurr2msLPFKn_Uls_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_EstPkCurr2msLPFKn_Uls_u16 = 6268U;

#pragma DATA_SECTION(k_EstPkCurrSlowLoopLPFKn_Uls_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_EstPkCurrSlowLoopLPFKn_Uls_u16 = 1224U;


/************************** PICurrCntrl, MtrCtrl_CM **************************/
#pragma DATA_SECTION(k_PiSamplingTs_Sec_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PiSamplingTs_Sec_f32 = 0.000125f;

#pragma DATA_SECTION(t_CommOffsetTblX_Uls_u3p13, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_CommOffsetTblX_Uls_u3p13[2] = 
	{FPM_InitFixedPoint_m(0.6, u3p13_T),FPM_InitFixedPoint_m(0.95, u3p13_T)};


/********************** PICurrCntrl, SVDiag, MtrCtrl_CM **********************/
#pragma DATA_SECTION(t_CommOffsetTblY_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_CommOffsetTblY_Cnt_u16[2] = {63U,0U};


/**************************** QuadDet, MtrCtrl_CM ****************************/
#pragma DATA_SECTION(k_InstMtrDirHyst_Deg_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_InstMtrDirHyst_Deg_f32 = 2.5f;


/*************************** TrqCmdScl, MtrCtrl_CM ***************************/
#pragma DATA_SECTION(k_MinTrqCmdScl_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MinTrqCmdScl_Uls_f32 = 0.9f;

#pragma DATA_SECTION(k_MaxTrqCmdScl_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MaxTrqCmdScl_Uls_f32 = 1.1f;


/****************** My_LWR_WA, My_ePWM_LWR, VehPwrMd, My_CL ******************/
#pragma DATA_SECTION(k_RampDnRt_UlspmS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_RampDnRt_UlspmS_f32 = 0.0005f;

#pragma DATA_SECTION(k_RampUpRtLoSpd_UlspmS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_RampUpRtLoSpd_UlspmS_f32 = 0.0005f;


/********************************* VehSpdLmt *********************************/
#pragma DATA_SECTION(k_PosMaxOfstOne_HwDeg_u12p4, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PosMaxOfstOne_HwDeg_u12p4 = 
	FPM_InitFixedPoint_m(140.0, u12p4_T);

#pragma DATA_SECTION(k_PosMaxOfstTwo_HwDeg_u12p4, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PosMaxOfstTwo_HwDeg_u12p4 = 
	FPM_InitFixedPoint_m(120.0, u12p4_T);

#pragma DATA_SECTION(t_MaxAsstTblX_Kph_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_MaxAsstTblX_Kph_u9p7[5] = 
	{ FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(25.0, u9p7_T),
	 FPM_InitFixedPoint_m(50.0, u9p7_T), FPM_InitFixedPoint_m(65.0, u9p7_T),
	 FPM_InitFixedPoint_m(75.0, u9p7_T) };

#pragma DATA_SECTION(t_MaxAsstTblY_MtrNm_u5p11, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_MaxAsstTblY_MtrNm_u5p11[5] = 
	{ FPM_InitFixedPoint_m(8.8, u5p11_T),FPM_InitFixedPoint_m(8.8, u5p11_T),
	FPM_InitFixedPoint_m(8.8, u5p11_T),FPM_InitFixedPoint_m(8.8, u5p11_T),
	FPM_InitFixedPoint_m(8.8, u5p11_T) };


/*********************** My_LWR_WA, My_ePWM_LWR, My_CL ***********************/
#pragma DATA_SECTION(k_CalRelNum_Cnt_u8, ".FlashCal1Seg");
CONST(uint8, CAL_CONST) k_CalRelNum_Cnt_u8[12] = "DefaultCals";


/******************* My_LWR_WA, My_ePWM_LWR, MtrVel, My_CL *******************/
#pragma DATA_SECTION(k_GearRatio_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_GearRatio_Uls_f32 = 0.04545454545f;


/********************** My_LWR_WA, My_ePWM_LWR, MtrPos ***********************/
#pragma DATA_SECTION(k_RTToNomRatioVar_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_RTToNomRatioVar_Uls_f32 = 0.1f;

#pragma DATA_SECTION(k_RTOffVelThr_MtrRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_RTOffVelThr_MtrRadpS_f32 = 100.0f;

#pragma DATA_SECTION(k_RTOffsetLmt_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_RTOffsetLmt_Volts_f32 = 0.1f;

#pragma DATA_SECTION(k_RTFiltEnThresh_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_RTFiltEnThresh_Uls_f32 = 0.99f;

#pragma DATA_SECTION(k_RTOffFiltKn_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_RTOffFiltKn_Cnt_u16 = 200U;

#pragma DATA_SECTION(k_AmpRecVarLmt_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AmpRecVarLmt_Uls_f32 = 0.122f;

#pragma DATA_SECTION(k_CorrelationError_Rev_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CorrelationError_Rev_f32 = 0.222f;

#pragma DATA_SECTION(k_MtrPosCorrDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_MtrPosCorrDiag_Cnt_str = {50, 10, 1};

#pragma DATA_SECTION(k_MtrPosValDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_MtrPosValDiag_Cnt_str = {50, 10, 1};

#pragma DATA_SECTION(k_ValMinError_VoltsSqrd_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_ValMinError_VoltsSqrd_f32 = 0.0625f;

#pragma DATA_SECTION(k_ValMaxError_VoltsSqrd_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_ValMaxError_VoltsSqrd_f32 = 6.25f;


/********************** My_LWR_WA, My_ePWM_LWR, MtrVel ***********************/
#pragma DATA_SECTION(k_MtrVelFiltEn_Cnt_lgc, ".FlashCal1Seg");
CONST(boolean, CAL_CONST) k_MtrVelFiltEn_Cnt_lgc = FALSE;

#pragma DATA_SECTION(t_MtrVelBlendTblX_MtrRadpS_u12p4, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_MtrVelBlendTblX_MtrRadpS_u12p4[2] = 
	{FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T)};

#pragma DATA_SECTION(t_MtrVelDeltaKpTblX_MtrRadpS_u12p4, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_MtrVelDeltaKpTblX_MtrRadpS_u12p4[2] = 
	{FPM_InitFixedPoint_m(0.9375, u12p4_T),
	 FPM_InitFixedPoint_m(3.125, u12p4_T)};

#pragma DATA_SECTION(t_MtrVelDeltaKpTblY_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_MtrVelDeltaKpTblY_Cnt_u16[2] = {40U, 150U};

#pragma DATA_SECTION(t_MtrVelFiltKpTblX_Kph_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_MtrVelFiltKpTblX_Kph_u9p7[2] = 
	{FPM_InitFixedPoint_m(10.0, u9p7_T), FPM_InitFixedPoint_m(30.0, u9p7_T)};

#pragma DATA_SECTION(t_MtrVelFiltKpYTbl_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_MtrVelFiltKpYTbl_Cnt_u16[2] = {40U, 150U};


/******************* My_LWR_WA, My_ePWM_LWR, PwrLmtFuncCr ********************/
#pragma DATA_SECTION(k_SpdAdjSlewEnable_Cnt_lgc, ".FlashCal1Seg");
CONST(boolean, CAL_CONST) k_SpdAdjSlewEnable_Cnt_lgc = TRUE;


/*********************** My_LWR_WA, My_ePWM_LWR, ePWM ************************/
#pragma DATA_SECTION(k_ADCTrig1Offset_Cnt_s16, ".FlashCal1Seg");
CONST(sint16, CAL_CONST) k_ADCTrig1Offset_Cnt_s16 = 15;

#pragma DATA_SECTION(k_PwmDeadBand_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PwmDeadBand_Cnt_u16 = 15U;


/********************* My_LWR_WA, My_ePWM_LWR, SVDrvr_CM *********************/
#pragma DATA_SECTION(k_DitherLPFKn_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_DitherLPFKn_Cnt_u16 = 20U;


/*********************** My_LWR_WA, My_ePWM_LWR, My_CL ***********************/
#pragma DATA_SECTION(k_DefaultVehSpd_Kph_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_DefaultVehSpd_Kph_u9p7 = 
	FPM_InitFixedPoint_m(50.0, u9p7_T);


/********************** My_LWR_WA, My_ePWM_LWR, SVDiag ***********************/
#pragma DATA_SECTION(k_GateDrvInitDwellTime_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_GateDrvInitDwellTime_mS_u16p0 = 
	FPM_InitFixedPoint_m(10.0, u16p0_T);

#pragma DATA_SECTION(k_GenGateDrvFltThrsh_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_GenGateDrvFltThrsh_Cnt_u16 = 200U;


/********************** My_LWR_WA, My_ePWM_LWR, BVDiag ***********************/
#pragma DATA_SECTION(k_OvDetect_Volts_u10p6, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_OvDetect_Volts_u10p6 = 
	FPM_InitFixedPoint_m(18.0, u10p6_T);

#pragma DATA_SECTION(k_OvNotDetect_Volts_u10p6, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_OvNotDetect_Volts_u10p6 = 
	FPM_InitFixedPoint_m(18.0, u10p6_T);

#pragma DATA_SECTION(k_OvDetect_ms_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_OvDetect_ms_u16p0 = 
	FPM_InitFixedPoint_m(1000.0, u16p0_T);

#pragma DATA_SECTION(k_OvNotDetect_ms_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_OvNotDetect_ms_u16p0 = 
	FPM_InitFixedPoint_m(600.0, u16p0_T);

#pragma DATA_SECTION(k_LowNotDetect_Volts_u10p6, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_LowNotDetect_Volts_u10p6 = 
	FPM_InitFixedPoint_m(9.0, u10p6_T);

#pragma DATA_SECTION(k_LowDetect_Volts_u10p6, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_LowDetect_Volts_u10p6 = 
	FPM_InitFixedPoint_m(9.0, u10p6_T);

#pragma DATA_SECTION(k_LowDetect_ms_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_LowDetect_ms_u16p0 = 
	FPM_InitFixedPoint_m(1000.0, u16p0_T);

#pragma DATA_SECTION(k_LowNotDetect_ms_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_LowNotDetect_ms_u16p0 = 
	FPM_InitFixedPoint_m(600.0, u16p0_T);


/************** My_LWR_WA, My_ePWM_LWR, BatteryVoltage, BkCpPc ***************/
#pragma DATA_SECTION(k_MaxSwitchedVolt_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MaxSwitchedVolt_Volts_f32 = 16.0f;


/****************** My_LWR_WA, My_ePWM_LWR, BatteryVoltage *******************/
#pragma DATA_SECTION(k_MaxBattVoltDiff_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MaxBattVoltDiff_Volts_f32 = 0.5f;


/******************* My_LWR_WA, My_ePWM_LWR, ThrmDutyCycle *******************/
#pragma DATA_SECTION(k_AbsTempDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_AbsTempDiag_Cnt_str = {140, 2, 1};

#pragma DATA_SECTION(k_DutyCycFltTrshld_Uls_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_DutyCycFltTrshld_Uls_u16p0 = 
	FPM_InitFixedPoint_m(92.0, u16p0_T);

#pragma DATA_SECTION(k_TrqCmdSlewDown_MtrNm_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_TrqCmdSlewDown_MtrNm_u9p7 = 
	FPM_InitFixedPoint_m(0.0390625, u9p7_T);

#pragma DATA_SECTION(k_TrqCmdSlewUp_MtrNm_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_TrqCmdSlewUp_MtrNm_u9p7 = 
	FPM_InitFixedPoint_m(0.0390625, u9p7_T);

#pragma DATA_SECTION(t_Mult1NSTblY_Uls_u3p13, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_Mult1NSTblY_Uls_u3p13[5] = 
	{FPM_InitFixedPoint_m(0.0155029, u3p13_T),
	 FPM_InitFixedPoint_m(0.0155029, u3p13_T),
	 FPM_InitFixedPoint_m(0.0155029, u3p13_T),
	 FPM_InitFixedPoint_m(0.198975, u3p13_T),
	 FPM_InitFixedPoint_m(0.198975, u3p13_T)};

#pragma DATA_SECTION(t_Mult2NSTblY_Uls_u3p13, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_Mult2NSTblY_Uls_u3p13[5] = 
	{FPM_InitFixedPoint_m(0.019409, u3p13_T),
	 FPM_InitFixedPoint_m(0.019409, u3p13_T),
	 FPM_InitFixedPoint_m(0.019409, u3p13_T),
	 FPM_InitFixedPoint_m(0.034302, u3p13_T),
	 FPM_InitFixedPoint_m(0.034302, u3p13_T)};

#pragma DATA_SECTION(t_Mult3NSTblY_Uls_u3p13, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_Mult3NSTblY_Uls_u3p13[5] = 
	{FPM_InitFixedPoint_m(0.024292, u3p13_T),
	 FPM_InitFixedPoint_m(0.024292, u3p13_T),
	 FPM_InitFixedPoint_m(0.024292, u3p13_T),
	 FPM_InitFixedPoint_m(0.1564941, u3p13_T),
	 FPM_InitFixedPoint_m(0.1564941, u3p13_T)};

#pragma DATA_SECTION(t_Mult4NSTblY_Uls_u3p13, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_Mult4NSTblY_Uls_u3p13[5] = 
	{FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T)};

#pragma DATA_SECTION(t_Mult5NSTblY_Uls_u3p13, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_Mult5NSTblY_Uls_u3p13[5] = 
	{FPM_InitFixedPoint_m(0.121826, u3p13_T),
	 FPM_InitFixedPoint_m(0.121826, u3p13_T),
	 FPM_InitFixedPoint_m(0.121826, u3p13_T),
	 FPM_InitFixedPoint_m(1.16394, u3p13_T),
	 FPM_InitFixedPoint_m(1.16394, u3p13_T)};

#pragma DATA_SECTION(t_Mult6NSTblY_Uls_u3p13, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_Mult6NSTblY_Uls_u3p13[5] = 
	{FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T)};

#pragma DATA_SECTION(t_LastTblValNS_MtrNm_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_LastTblValNS_MtrNm_u9p7[5] = 
	{FPM_InitFixedPoint_m(1.0, u9p7_T), FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(0.34375, u9p7_T),
	 FPM_InitFixedPoint_m(0.34375, u9p7_T)};

#pragma DATA_SECTION(t_Mult1STblY_Uls_u3p13, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_Mult1STblY_Uls_u3p13[5] = 
	{FPM_InitFixedPoint_m(0.016235, u3p13_T),
	 FPM_InitFixedPoint_m(0.016235, u3p13_T),
	 FPM_InitFixedPoint_m(0.016235, u3p13_T),
	 FPM_InitFixedPoint_m(0.021973, u3p13_T),
	 FPM_InitFixedPoint_m(0.021973, u3p13_T)};

#pragma DATA_SECTION(t_Mult2STblY_Uls_u3p13, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_Mult2STblY_Uls_u3p13[5] = 
	{FPM_InitFixedPoint_m(0.020386, u3p13_T),
	 FPM_InitFixedPoint_m(0.020386, u3p13_T),
	 FPM_InitFixedPoint_m(0.020386, u3p13_T),
	 FPM_InitFixedPoint_m(0.037842, u3p13_T),
	 FPM_InitFixedPoint_m(0.037842, u3p13_T)};

#pragma DATA_SECTION(t_Mult3STblY_Uls_u3p13, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_Mult3STblY_Uls_u3p13[5] = 
	{FPM_InitFixedPoint_m(0.025635, u3p13_T),
	 FPM_InitFixedPoint_m(0.025635, u3p13_T),
	 FPM_InitFixedPoint_m(0.025635, u3p13_T),
	 FPM_InitFixedPoint_m(0.208374, u3p13_T),
	 FPM_InitFixedPoint_m(0.208374, u3p13_T)};

#pragma DATA_SECTION(t_Mult4STblY_Uls_u3p13, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_Mult4STblY_Uls_u3p13[5] = 
	{FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T)};

#pragma DATA_SECTION(t_Mult5STblY_Uls_u3p13, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_Mult5STblY_Uls_u3p13[5] = 
	{FPM_InitFixedPoint_m(0.121826, u3p13_T),
	 FPM_InitFixedPoint_m(0.121826, u3p13_T),
	 FPM_InitFixedPoint_m(0.121826, u3p13_T),
	 FPM_InitFixedPoint_m(1.16394, u3p13_T),
	 FPM_InitFixedPoint_m(1.16394, u3p13_T)};

#pragma DATA_SECTION(t_Mult6STblY_Uls_u3p13, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_Mult6STblY_Uls_u3p13[5] = 
	{FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T)};

#pragma DATA_SECTION(t_LastTblValS_MtrNm_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_LastTblValS_MtrNm_u9p7[5] = 
	{FPM_InitFixedPoint_m(0.96875, u9p7_T),
	 FPM_InitFixedPoint_m(0.96875, u9p7_T),
	 FPM_InitFixedPoint_m(0.96875, u9p7_T),
	 FPM_InitFixedPoint_m(0.3125, u9p7_T),
	 FPM_InitFixedPoint_m(0.3125, u9p7_T)};


/******************************* AbsHwPosScom ********************************/
#pragma DATA_SECTION(k_HwPosOpLPFCoeffK_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_HwPosOpLPFCoeffK_Cnt_u16 = 175U;

#pragma DATA_SECTION(k_KinmIntDiagMaxRackLmt_HwDeg_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_KinmIntDiagMaxRackLmt_HwDeg_f32 = 2100.0f;


/****************************** AssistFirewall *******************************/
#pragma DATA_SECTION(k_AsstFWInpLimitHysComp_MtrNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AsstFWInpLimitHysComp_MtrNm_f32 = 8.8f;


/******************************* CtrldDisShtdn *******************************/
#pragma DATA_SECTION(k_CntrlDmpRampEnd_Uls_u8p8, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_CntrlDmpRampEnd_Uls_u8p8 = 
	FPM_InitFixedPoint_m(0.0, u8p8_T);


/********************************* CtrlTemp **********************************/
#pragma DATA_SECTION(k_TempSnsrLPFKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TempSnsrLPFKn_Hz_f32 = 8.0f;


/*********************************** HwTrq ***********************************/
#pragma DATA_SECTION(k_AnaRngDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_AnaRngDiag_Cnt_str = {200, 4, 1};

#pragma DATA_SECTION(k_AnaT1T2ErrThreshold_Volts_u5p11, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_AnaT1T2ErrThreshold_Volts_u5p11 = 
	FPM_InitFixedPoint_m(0.2, u5p11_T);


/******************************** MtrTempEst *********************************/
#pragma DATA_SECTION(k_SiAmbLPFKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_SiAmbLPFKn_Hz_f32 = 0.024f;

#pragma DATA_SECTION(k_MagAmbLPFKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MagAmbLPFKn_Hz_f32 = 0.024f;

#pragma DATA_SECTION(k_CuAmbLPFKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CuAmbLPFKn_Hz_f32 = 0.024f;

#pragma DATA_SECTION(k_AMAmbLPFKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AMAmbLPFKn_Hz_f32 = 0.024f;


/********************************** Return ***********************************/
#pragma DATA_SECTION(k_RtnOffsetSlew_HwDegpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_RtnOffsetSlew_HwDegpS_f32 = 0.04f;

#pragma DATA_SECTION(k_RtnOffsetRange_HWDeg_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_RtnOffsetRange_HWDeg_f32 = 17.0f;

#pragma DATA_SECTION(t_HWAuthRetScl_X_Uls_u8p8, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_HWAuthRetScl_X_Uls_u8p8[4] = 
	{ FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(0.5, u8p8_T),
	FPM_InitFixedPoint_m(0.75, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T) };

#pragma DATA_SECTION(t_HWAuthRetScl_Y_Uls_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_HWAuthRetScl_Y_Uls_u9p7[4] = 
	{ FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(0.0, u9p7_T),
	FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(1.0, u9p7_T) };

#pragma DATA_SECTION(k_RtnHWAuthSlew_UlspS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_RtnHWAuthSlew_UlspS_f32 = 0.5f;


/******************************* ThrmDutyCycle *******************************/
#pragma DATA_SECTION(k_EOCCtrlTemp_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_EOCCtrlTemp_DegC_f32 = 70.0f;

#pragma DATA_SECTION(k_CtrlTempSlc_Cnt_lgc, ".FlashCal1Seg");
CONST(boolean, CAL_CONST) k_CtrlTempSlc_Cnt_lgc = TRUE;

#pragma DATA_SECTION(k_MtrPrTempSlc_Cnt_lgc, ".FlashCal1Seg");
CONST(boolean, CAL_CONST) k_MtrPrTempSlc_Cnt_lgc = TRUE;

#pragma DATA_SECTION(t_MultTblX_DegC_s15p0, ".FlashCal1Seg");
CONST(sint16, CAL_CONST) t_MultTblX_DegC_s15p0[5] = 
	{FPM_InitFixedPoint_m(-40.0, s15p0_T),
	 FPM_InitFixedPoint_m(0.0, s15p0_T), FPM_InitFixedPoint_m(83.0, s15p0_T),
	 FPM_InitFixedPoint_m(84.0, s15p0_T),
	 FPM_InitFixedPoint_m(85.0, s15p0_T)};

#pragma DATA_SECTION(k_SlowFltTempSlc_Cnt_lgc, ".FlashCal1Seg");
CONST(boolean, CAL_CONST) k_SlowFltTempSlc_Cnt_lgc = FALSE;

#pragma DATA_SECTION(k_AbsTmpTrqSlewLmt_MtrNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AbsTmpTrqSlewLmt_MtrNm_f32 = 0.023438f;

#pragma DATA_SECTION(k_MultTempSlc_Cnt_lgc, ".FlashCal1Seg");
CONST(boolean, CAL_CONST) k_MultTempSlc_Cnt_lgc = TRUE;

#pragma DATA_SECTION(t_ThrmLoadLmtTblX_Uls_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_ThrmLoadLmtTblX_Uls_u16p0[8] = 
	{FPM_InitFixedPoint_m(0.0, u16p0_T), FPM_InitFixedPoint_m(76.0, u16p0_T),
	 FPM_InitFixedPoint_m(80.0, u16p0_T),
	 FPM_InitFixedPoint_m(84.0, u16p0_T),
	 FPM_InitFixedPoint_m(88.0, u16p0_T),
	 FPM_InitFixedPoint_m(92.0, u16p0_T),
	 FPM_InitFixedPoint_m(96.0, u16p0_T),
	 FPM_InitFixedPoint_m(100.0, u16p0_T)};

#pragma DATA_SECTION(t_ThrmLoadLmtTblY_MtrNm_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_ThrmLoadLmtTblY_MtrNm_u9p7[8] = 
	{FPM_InitFixedPoint_m(2.703125, u9p7_T),
	 FPM_InitFixedPoint_m(2.703125, u9p7_T),
	 FPM_InitFixedPoint_m(2.703125, u9p7_T),
	 FPM_InitFixedPoint_m(2.703125, u9p7_T),
	 FPM_InitFixedPoint_m(2.242188, u9p7_T),
	 FPM_InitFixedPoint_m(1.828125, u9p7_T),
	 FPM_InitFixedPoint_m(1.414063, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T)};


/******************************** SrlComInput ********************************/
#pragma DATA_SECTION(k_VehSpdMisMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_VehSpdMisMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_VehSpdValTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_VehSpdValTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_IgnStatMisMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_IgnStatMisMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_IgnStatValTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_IgnStatValTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_EngRPMMisMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_EngRPMMisMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_EngRPMValTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_EngRPMValTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_SWAMisMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_SWAMisMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_SWAValTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_SWAValTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_StrgWhlAnglPol_s08, ".FlashCal1Seg");
CONST(sint8, CAL_CONST) k_StrgWhlAnglPol_s08 = -1;


/********************************* SgnlCond **********************************/
#pragma DATA_SECTION(k_VehSpdSlewRate_KphpSec_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_VehSpdSlewRate_KphpSec_f32 = 35.0f;


/********************************* VehPwrMd **********************************/
#pragma DATA_SECTION(k_VehSpdAstLmt_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_VehSpdAstLmt_Kph_f32 = 5.0f;


/********************************* AstLmt_CM *********************************/
#pragma DATA_SECTION(k_SumLimPlCmpLimit_MtrNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_SumLimPlCmpLimit_MtrNm_f32 = 8.8f;


/******************************* PwrLmtFuncCr ********************************/
#pragma DATA_SECTION(k_SpdAdjSlewInc_MtrRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_SpdAdjSlewInc_MtrRadpS_f32 = 6.25f;

#pragma DATA_SECTION(k_SpdAdjSlewDec_MtrRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_SpdAdjSlewDec_MtrRadpS_f32 = 0.0625f;

#pragma DATA_SECTION(k_AsstReducLPFKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AsstReducLPFKn_Hz_f32 = 0.365f;

#pragma DATA_SECTION(k_LowVltAstRecTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_LowVltAstRecTime_mS_u16 = 2000U;

#pragma DATA_SECTION(k_LowVltAstRecTh_Volt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_LowVltAstRecTh_Volt_f32 = 13.5f;


/******************************* TMS570_uDiag ********************************/
#pragma DATA_SECTION(k_FlashECCDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_FlashECCDiag_Cnt_str = {100, 5, 1};

#pragma DATA_SECTION(k_RAMECCDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_RAMECCDiag_Cnt_str = {100, 5, 1};

#pragma DATA_SECTION(k_MtrCtrlMinCount_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_MtrCtrlMinCount_Cnt_u16 = 10U;

#pragma DATA_SECTION(k_MtrCtrlMaxCount_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_MtrCtrlMaxCount_Cnt_u16 = 120U;

#pragma DATA_SECTION(k_OneMsLoopMinCount_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_OneMsLoopMinCount_Cnt_u16 = 1U;

#pragma DATA_SECTION(k_OneMsLoopMaxCount_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_OneMsLoopMaxCount_Cnt_u16 = 11U;

#pragma DATA_SECTION(k_VIMParErrThrsh_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_VIMParErrThrsh_Cnt_u16 = 20U;


/******************************* SrlComOutput ********************************/
#pragma DATA_SECTION(k_StrClmTrqPolarity_Cnt_s08, ".FlashCal1Seg");
CONST(sint8, CAL_CONST) k_StrClmTrqPolarity_Cnt_s08 = -1;


/******************************* AbsHwPosScom ********************************/
#pragma DATA_SECTION(k_AutoCtrPinTrqLPFCoeffK_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AutoCtrPinTrqLPFCoeffK_Hz_f32 = 0.035f;

#pragma DATA_SECTION(k_AutoCtrMtrVelT1L_MtrRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AutoCtrMtrVelT1L_MtrRadpS_f32 = 30.0f;

#pragma DATA_SECTION(k_AutoCtrVehSpdT1L_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AutoCtrVehSpdT1L_Kph_f32 = 20.0f;

#pragma DATA_SECTION(k_AutoCtrPinTrqT1L_HwNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AutoCtrPinTrqT1L_HwNm_f32 = 4.0f;

#pragma DATA_SECTION(k_HwPTimer1MaxL_ms_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_HwPTimer1MaxL_ms_u16 = 500U;

#pragma DATA_SECTION(k_AutoCtrFiltOneCoeffkL_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AutoCtrFiltOneCoeffkL_Hz_f32 = 0.1f;

#pragma DATA_SECTION(k_AutoCtrWindowL_HwDeg_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AutoCtrWindowL_HwDeg_f32 = 8.0f;

#pragma DATA_SECTION(k_AutoCtrFiltTwoCoeffkL_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AutoCtrFiltTwoCoeffkL_Hz_f32 = 0.005f;

#pragma DATA_SECTION(k_AutoCtrTimer2LSpd_ms_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_AutoCtrTimer2LSpd_ms_u16 = 2000U;

#pragma DATA_SECTION(k_HwPMtrVelT1H_MtrRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HwPMtrVelT1H_MtrRadpS_f32 = 20.0f;

#pragma DATA_SECTION(k_HwPVehSpdT1H_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HwPVehSpdT1H_Kph_f32 = 65.0f;

#pragma DATA_SECTION(k_HwPPinionTrqT1H_HwNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HwPPinionTrqT1H_HwNm_f32 = 4.0f;

#pragma DATA_SECTION(k_HwPTimer1MaxH_ms_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_HwPTimer1MaxH_ms_u16 = 1500U;

#pragma DATA_SECTION(k_HwPFilter1KnH_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HwPFilter1KnH_Hz_f32 = 0.025f;

#pragma DATA_SECTION(k_HwPWindowCalH_HwDeg_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HwPWindowCalH_HwDeg_f32 = 5.0f;

#pragma DATA_SECTION(k_HwPFilter2KnH_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HwPFilter2KnH_Hz_f32 = 0.0002f;

#pragma DATA_SECTION(k_HwPTmr2MaxHiSpd_ms_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_HwPTmr2MaxHiSpd_ms_u16 = 2000U;

#pragma DATA_SECTION(k_MtrVelTmr4H_MtrRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MtrVelTmr4H_MtrRadpS_f32 = 20.0f;

#pragma DATA_SECTION(k_VehSpdTmr4H_kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_VehSpdTmr4H_kph_f32 = 65.0f;

#pragma DATA_SECTION(k_PinTrqTmr4H_HwNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PinTrqTmr4H_HwNm_f32 = 3.0f;

#pragma DATA_SECTION(k_Tmr4CntrWindowH_HwDeg_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_Tmr4CntrWindowH_HwDeg_f32 = 5.0f;

#pragma DATA_SECTION(k_AutoCtrTimer4H_ms_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_AutoCtrTimer4H_ms_u16 = 2000U;

#pragma DATA_SECTION(k_VDAuthL_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_VDAuthL_Uls_f32 = 1.0f;

#pragma DATA_SECTION(k_HiSpdAcAuth_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HiSpdAcAuth_Uls_f32 = 1.0f;

#pragma DATA_SECTION(k_HwPosAuthorityStep_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HwPosAuthorityStep_Uls_f32 = 0.2f;

#pragma DATA_SECTION(k_HwPosOpLPFError_HwDeg_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HwPosOpLPFError_HwDeg_f32 = 5.0f;

#pragma DATA_SECTION(k_RbstPosLPFKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_RbstPosLPFKn_Hz_f32 = 0.21278f;

#pragma DATA_SECTION(k_HwPosVehStabilityTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_HwPosVehStabilityTime_mS_u16 = 50U;

#pragma DATA_SECTION(k_ScomHwPosAuth_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_ScomHwPosAuth_Uls_f32 = 1.0f;

#pragma DATA_SECTION(k_HwPosVehStabilityHwTrq_HwNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HwPosVehStabilityHwTrq_HwNm_f32 = 1.0f;

#pragma DATA_SECTION(k_HwPosVehStabilityTrqCmd_MtrNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HwPosVehStabilityTrqCmd_MtrNm_f32 = 1.0f;

#pragma DATA_SECTION(k_HwPosVehStabilityMtrVel_MtrRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HwPosVehStabilityMtrVel_MtrRadpS_f32 = 20.0f;

#pragma DATA_SECTION(k_VdynToScomMaxErr_HwDeg_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_VdynToScomMaxErr_HwDeg_f32 = 360.0f;

#pragma DATA_SECTION(k_VdynToSComCorrLmt_HwDeg_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_VdynToSComCorrLmt_HwDeg_f32 = 20.0f;


/********************************** Assist ***********************************/
#pragma DATA_SECTION(t_AsstThermSclX_Cnt_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_AsstThermSclX_Cnt_u16p0[2] = 
	{FPM_InitFixedPoint_m(75.0, u16p0_T),
	 FPM_InitFixedPoint_m(100.0, u16p0_T)};

#pragma DATA_SECTION(t_AsstThermSclY_Uls_u2p14, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_AsstThermSclY_Uls_u2p14[2] = 
	{FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T)};


/********************************** Damping **********************************/
#pragma DATA_SECTION(k_MtrVelDampLPFKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MtrVelDampLPFKn_Hz_f32 = 15.0f;

#pragma DATA_SECTION(k_QddHwTrqDampKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_QddHwTrqDampKn_Hz_f32 = 15.0f;

#pragma DATA_SECTION(k_QddMtrVelDampKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_QddMtrVelDampKn_Hz_f32 = 15.0f;

#pragma DATA_SECTION(k_QDDHwTrqBckLash_HwNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_QDDHwTrqBckLash_HwNm_f32 = 0.0f;

#pragma DATA_SECTION(k_QDDMtrVelBckLash_MtrRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_QDDMtrVelBckLash_MtrRadpS_f32 = 0.0f;

#pragma DATA_SECTION(k_QddSfLFPKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_QddSfLFPKn_Hz_f32 = 15.0f;

#pragma DATA_SECTION(k_HPSbaseC1_MtrNmpMtrRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HPSbaseC1_MtrNmpMtrRadpS_f32 = 0.000521083f;

#pragma DATA_SECTION(k_HPSbaseC2_MtrNmpMtrRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HPSbaseC2_MtrNmpMtrRadpS_f32 = 0.0000288893f;

#pragma DATA_SECTION(k_HPSbaseC3_MtrNmpMtrRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HPSbaseC3_MtrNmpMtrRadpS_f32 = 0.00618654f;

#pragma DATA_SECTION(k_HPSbaseC4_MtrNmpMtrRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HPSbaseC4_MtrNmpMtrRadpS_f32 = 0.00000956832f;


/********************************** Return ***********************************/
#pragma DATA_SECTION(k_RtnLimit_MtrNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_RtnLimit_MtrNm_f32 = 0.1f;


/********************************** HaLFTO ***********************************/
#pragma DATA_SECTION(k_HaLFDSTSyncTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_HaLFDSTSyncTime_mS_u16 = 100U;


/*************************** HaLFTO, PAwTO, StbCTO ***************************/
#pragma DATA_SECTION(k_TrqOverlayLimitPerc_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TrqOverlayLimitPerc_Uls_f32 = 10.0f;

#pragma DATA_SECTION(k_TrqOverlaySuspendTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_TrqOverlaySuspendTime_mS_u16 = 1000U;


/*********************************** PAwTO ***********************************/
#pragma DATA_SECTION(k_HandsOnLPFKn_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_HandsOnLPFKn_Cnt_u16 = 818U;

#pragma DATA_SECTION(k_TrqOverlayHandsOnTrq_HwNm_u5p27, ".FlashCal1Seg");
CONST(uint32, CAL_CONST) k_TrqOverlayHandsOnTrq_HwNm_u5p27 = 
	FPM_InitFixedPoint_m(3.5, u5p27_T);

#pragma DATA_SECTION(k_PARvsGearChkTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PARvsGearChkTime_mS_u16 = 100U;

#pragma DATA_SECTION(k_PATrqOvNotZeroChkTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PATrqOvNotZeroChkTime_mS_u16 = 200U;

#pragma DATA_SECTION(k_PAVehSpdNotLowTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PAVehSpdNotLowTime_mS_u16 = 100U;

#pragma DATA_SECTION(k_PAVSpdNotLowMin_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PAVSpdNotLowMin_Kph_f32 = 0.0f;

#pragma DATA_SECTION(k_PAVSpdNotLowMax_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PAVSpdNotLowMax_Kph_f32 = 2.7f;

#pragma DATA_SECTION(k_PAIWSSWhlSpinSetTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PAIWSSWhlSpinSetTime_mS_u16 = 100U;

#pragma DATA_SECTION(k_PAIWSSWhlSpinClrTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PAIWSSWhlSpinClrTime_mS_u16 = 1000U;

#pragma DATA_SECTION(k_PAExcessVehSpdSetTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PAExcessVehSpdSetTime_mS_u16 = 100U;

#pragma DATA_SECTION(k_PAExcessVehSpdClrTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PAExcessVehSpdClrTime_mS_u16 = 1000U;

#pragma DATA_SECTION(k_PAExcessVehSpd_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PAExcessVehSpd_Kph_f32 = 8.0f;

#pragma DATA_SECTION(k_PAMovMismatchSetTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PAMovMismatchSetTime_mS_u16 = 40U;

#pragma DATA_SECTION(k_PAMovMismatchClrTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PAMovMismatchClrTime_mS_u16 = 1000U;

#pragma DATA_SECTION(k_PAMovMismatchVSpd_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PAMovMismatchVSpd_Kph_f32 = 5.0f;

#pragma DATA_SECTION(k_PAVspdMismatchSetTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PAVspdMismatchSetTime_mS_u16 = 300U;

#pragma DATA_SECTION(k_PAEIWSSChkVspd_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PAEIWSSChkVspd_Kph_f32 = 14.0f;

#pragma DATA_SECTION(k_PABoostCurveTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PABoostCurveTime_mS_u16 = 50U;


/*********************************** HwTrq ***********************************/
#pragma DATA_SECTION(t_HwTorqCorrLimXAxis_HwNm_u4p12, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_HwTorqCorrLimXAxis_HwNm_u4p12[6] = 
	{FPM_InitFixedPoint_m(0.0, u4p12_T), FPM_InitFixedPoint_m(2.0, u4p12_T),
	 FPM_InitFixedPoint_m(4.0, u4p12_T), FPM_InitFixedPoint_m(6.0, u4p12_T),
	 FPM_InitFixedPoint_m(8.0, u4p12_T), FPM_InitFixedPoint_m(10.0, u4p12_T)};

#pragma DATA_SECTION(t_HwTorqCorrLimYAxis_HwNmSq_u7p9, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_HwTorqCorrLimYAxis_HwNmSq_u7p9[6] = 
	{FPM_InitFixedPoint_m(0.25, u7p9_T), FPM_InitFixedPoint_m(2.25, u7p9_T),
	 FPM_InitFixedPoint_m(4.25, u7p9_T), FPM_InitFixedPoint_m(6.25, u7p9_T),
	 FPM_InitFixedPoint_m(8.25, u7p9_T), FPM_InitFixedPoint_m(10.25, u7p9_T)};

#pragma DATA_SECTION(k_HwTorqCorrLimDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_HwTorqCorrLimDiag_Cnt_str = {12, 4, 1};

#pragma DATA_SECTION(t_SysCHwTorqCorrLimXAxis_HwNm_u4p12, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_SysCHwTorqCorrLimXAxis_HwNm_u4p12[6] = 
	{FPM_InitFixedPoint_m(0.0, u4p12_T), FPM_InitFixedPoint_m(2.0, u4p12_T),
	 FPM_InitFixedPoint_m(4.0, u4p12_T), FPM_InitFixedPoint_m(6.0, u4p12_T),
	 FPM_InitFixedPoint_m(8.0, u4p12_T), FPM_InitFixedPoint_m(10.0, u4p12_T)};

#pragma DATA_SECTION(t_SysCHwTorqCorrLimYAxis_HwNmSq_u7p9, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_SysCHwTorqCorrLimYAxis_HwNmSq_u7p9[6] = 
	{FPM_InitFixedPoint_m(0.25, u7p9_T), FPM_InitFixedPoint_m(2.25, u7p9_T),
	 FPM_InitFixedPoint_m(4.25, u7p9_T), FPM_InitFixedPoint_m(6.25, u7p9_T),
	 FPM_InitFixedPoint_m(8.25, u7p9_T), FPM_InitFixedPoint_m(10.25, u7p9_T)};

#pragma DATA_SECTION(k_SysCHwTorqCorrLimDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_SysCHwTorqCorrLimDiag_Cnt_str = {12, 4,
	 1};


/********************************** StbCTO ***********************************/
#pragma DATA_SECTION(k_DSTVSpdVLH_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_DSTVSpdVLH_Kph_f32 = 10.0f;

#pragma DATA_SECTION(k_DSTVSpdVHH_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_DSTVSpdVHH_Kph_f32 = 55.0f;

#pragma DATA_SECTION(k_DSTVSpdVLL_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_DSTVSpdVLL_Kph_f32 = 5.0f;

#pragma DATA_SECTION(k_DSTVSpdVHL_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_DSTVSpdVHL_Kph_f32 = 30.0f;

#pragma DATA_SECTION(k_DSTVehSpdActvTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_DSTVehSpdActvTime_mS_u16 = 1000U;

#pragma DATA_SECTION(k_DSTVehSpdInActvTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_DSTVehSpdInActvTime_mS_u16 = 1000U;

#pragma DATA_SECTION(k_DSTBkwdMotionTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_DSTBkwdMotionTime_mS_u16 = 1000U;

#pragma DATA_SECTION(k_DSTTrqOvActiveMaxLimit_MtrNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_DSTTrqOvActiveMaxLimit_MtrNm_f32 = 2.0f;

#pragma DATA_SECTION(k_DSTTNAMaxTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_DSTTNAMaxTime_mS_u16 = 100U;

#pragma DATA_SECTION(k_DSTRDMaxTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_DSTRDMaxTime_mS_u16 = 3000U;

#pragma DATA_SECTION(k_DSTRDStateMaxCount_Cnt_u08, ".FlashCal1Seg");
CONST(uint8, CAL_CONST) k_DSTRDStateMaxCount_Cnt_u08 = 5;


/********************************** DiagMgr **********************************/
#pragma DATA_SECTION(t_BlkBoxGrp_Ptr_u32, ".FlashCal1Seg");
CONST(uint32* const, CAL_CONST) t_BlkBoxGrp_Ptr_u32[7][3] = {{0,0,0},{0,0,0},
	{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};

#pragma DATA_SECTION(t_SortedNTCs_Cnt_enum, ".FlashCal1Seg");
CONST(NTCNumber, CAL_CONST) t_SortedNTCs_Cnt_enum[256] = { 0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000 };


/******************************** SrlComInput ********************************/
#pragma DATA_SECTION(k_PSTMisMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PSTMisMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_VehCfg5MisMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_VehCfg5MisMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_HalfMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_HalfMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_NETCFGMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_NETCFGMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_EcuCfg6MsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_EcuCfg6MsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);


/*************************************  **************************************/
#pragma DATA_SECTION(k_PSTTrqOvrlRangeDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_PSTTrqOvrlRangeDiag_Cnt_str = {40,2,1};

#pragma DATA_SECTION(k_PSTTrqOvrlRange_Cnt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PSTTrqOvrlRange_Cnt_f32 = 5.0f;


/******************************** SrlComInput ********************************/
#pragma DATA_SECTION(k_MC292hMsg_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_MC292hMsg_Cnt_u16 = 
	FPM_InitFixedPoint_m(4.0, u16p0_T);

#pragma DATA_SECTION(k_MC11ChMsg_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_MC11ChMsg_Cnt_u16 = 
	FPM_InitFixedPoint_m(4.0, u16p0_T);

#pragma DATA_SECTION(k_DSTTOCProgCnt1Diag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_DSTTOCProgCnt1Diag_Cnt_str = {40,2,1};

#pragma DATA_SECTION(k_DSTTOCProgCnt2Diag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_DSTTOCProgCnt2Diag_Cnt_str = {40,2,1};

#pragma DATA_SECTION(k_MC29FhMsg_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_MC29FhMsg_Cnt_u16 = 
	FPM_InitFixedPoint_m(4.0, u16p0_T);

#pragma DATA_SECTION(k_HalfTrqMax_Nm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HalfTrqMax_Nm_f32 = 5.0f;

#pragma DATA_SECTION(k_MsgMaxHalfTorqTO_mS_u32p0, ".FlashCal1Seg");
CONST(uint32, CAL_CONST) k_MsgMaxHalfTorqTO_mS_u32p0 = 
	FPM_InitFixedPoint_m(300000.0, u32p0_T);

#pragma DATA_SECTION(k_PASlewRate_NmpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PASlewRate_NmpS_f32 = 5.0f;


/*************************************  **************************************/
#pragma DATA_SECTION(k_PSTTrqOvrlSlewLmt_NmpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PSTTrqOvrlSlewLmt_NmpS_f32 = 200.0f;

#pragma DATA_SECTION(k_PSTTrqOvrlSlewLmtDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_PSTTrqOvrlSlewLmtDiag_Cnt_str = {40,2,1};

#pragma DATA_SECTION(k_HaLFTrqOvrlSlewLmt_NmpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HaLFTrqOvrlSlewLmt_NmpS_f32 = 200.0f;

#pragma DATA_SECTION(k_HaLFTrqOvrlSlewDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_HaLFTrqOvrlSlewDiag_Cnt_str = {40,2,1};


/******************************** SrlComInput ********************************/
#pragma DATA_SECTION(k_CRC292DiagMsg_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_CRC292DiagMsg_Cnt_u16 = 4U;

#pragma DATA_SECTION(k_CRC29FDiagMsg_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_CRC29FDiagMsg_Cnt_u16 = 4U;

#pragma DATA_SECTION(k_CRC11CDiagMsg_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_CRC11CDiagMsg_Cnt_u16 = 4U;

#pragma DATA_SECTION(k_IWSSVSpdConst_Cnt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_IWSSVSpdConst_Cnt_f32 = 100.0f;


/*************************************  **************************************/
#pragma DATA_SECTION(k_ErrAllow_MtrNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_ErrAllow_MtrNm_f32 = 0.25f;

#pragma DATA_SECTION(k_MaxErr_MtrNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MaxErr_MtrNm_f32 = 8.8f;

#pragma DATA_SECTION(k_KvalHiPstep_pMtrNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_KvalHiPstep_pMtrNm_f32 = 0.45f;

#pragma DATA_SECTION(k_KvalLoPstep_pMtrNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_KvalLoPstep_pMtrNm_f32 = 0.39f;

#pragma DATA_SECTION(k_FltDecrement_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_FltDecrement_Uls_f32 = 0.99f;

#pragma DATA_SECTION(k_MaxfltAccum_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MaxfltAccum_Uls_f32 = 31.68f;

#pragma DATA_SECTION(k_MaxMtrEnvMi_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MaxMtrEnvMi_Uls_f32 = 0.97f;


/****************************** BatteryVoltage *******************************/
#pragma DATA_SECTION(k_VswitchCorrLim_Cnt_Str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_VswitchCorrLim_Cnt_Str = {120,1,3};

#pragma DATA_SECTION(k_VecuCorrLim_Cnt_Str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_VecuCorrLim_Cnt_Str = {120,1,3};

#pragma DATA_SECTION(k_VecuVbatCorrLim_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_VecuVbatCorrLim_Volts_f32 = 0.73f;

#pragma DATA_SECTION(k_VswitchCorrLim_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_VswitchCorrLim_Volts_f32 = 0.73f;


/*************************************  **************************************/
#pragma DATA_SECTION(k_AMDfltOutoutTemp_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AMDfltOutoutTemp_DegC_f32 = 25.0f;


/********************************** MtrVel ***********************************/
#pragma DATA_SECTION(k_MtrVelCorrLim_Cnt_Str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_MtrVelCorrLim_Cnt_Str = {12, 3, 1};

#pragma DATA_SECTION(k_HwVelCorrLim_Cnt_Str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_HwVelCorrLim_Cnt_Str = {12, 3, 1};

#pragma DATA_SECTION(k_MtrVelCorrLim_MtrRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MtrVelCorrLim_MtrRadpS_f32 = 225.0f;

#pragma DATA_SECTION(k_HwVelCorrLim_HwRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HwVelCorrLim_HwRadpS_f32 = 6.4f;

#pragma DATA_SECTION(k_HwVelSampleTime_ms_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HwVelSampleTime_ms_f32 = 2.0f;

#pragma DATA_SECTION(k_DiagMtrVelFiltKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_DiagMtrVelFiltKn_Hz_f32 = 50.0f;


/******************************** MtrCtrl_CM *********************************/
#pragma DATA_SECTION(k_MtrVelFiltFFKn_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_MtrVelFiltFFKn_Cnt_u16 = 7739U;

#pragma DATA_SECTION(k_MtrVelFiltPIKn_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_MtrVelFiltPIKn_Cnt_u16 = 7739U;

#pragma DATA_SECTION(t_MtrCurrQaxRpl_Amp_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_MtrCurrQaxRpl_Amp_u9p7[7] = 
	{FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(25.0, u9p7_T),
	FPM_InitFixedPoint_m(50.0, u9p7_T),FPM_InitFixedPoint_m(75.0, u9p7_T),
	FPM_InitFixedPoint_m(100.0, u9p7_T),FPM_InitFixedPoint_m(125.0, u9p7_T),
	FPM_InitFixedPoint_m(135.0, u9p7_T)};

#pragma DATA_SECTION(t_MtrCurrDaxRpl_Amp_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_MtrCurrDaxRpl_Amp_u9p7[6] = 
	{FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(25.0, u9p7_T),
	FPM_InitFixedPoint_m(50.0, u9p7_T),FPM_InitFixedPoint_m(75.0, u9p7_T),
	FPM_InitFixedPoint_m(100.0, u9p7_T),FPM_InitFixedPoint_m(125.0, u9p7_T)};

#pragma DATA_SECTION(t2_MtrCurrQaxRpl6X_Amp_s6p9, ".FlashCal1Seg");
CONST(sint16, CAL_CONST) t2_MtrCurrQaxRpl6X_Amp_s6p9[6][7] = 
	{{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)}, {FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)},
	{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)},{FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)},
	{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)},{FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)}};

#pragma DATA_SECTION(t2_MtrCurrQaxRpl6Y_Amp_s6p9, ".FlashCal1Seg");
CONST(sint16, CAL_CONST) t2_MtrCurrQaxRpl6Y_Amp_s6p9[6][7] = 
	{{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)}, {FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)},
	{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)},{FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)},
	{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)},{FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)}};

#pragma DATA_SECTION(t2_MtrCurrQaxRpl12X_Amp_s6p9, ".FlashCal1Seg");
CONST(sint16, CAL_CONST) t2_MtrCurrQaxRpl12X_Amp_s6p9[6][7] = 
	{{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)}, {FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)},
	{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)},{FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)},
	{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)},{FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)}};

#pragma DATA_SECTION(t2_MtrCurrQaxRpl12Y_Amp_s6p9, ".FlashCal1Seg");
CONST(sint16, CAL_CONST) t2_MtrCurrQaxRpl12Y_Amp_s6p9[6][7] = 
	{{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)}, {FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)},
	{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)},{FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)},
	{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)},{FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)}};


/******************************** SrlComInput ********************************/
#pragma DATA_SECTION(k_PSTTrqOverlayDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_PSTTrqOverlayDiag_Cnt_str = {40,2,1};

#pragma DATA_SECTION(k_PSTTrqOverlayLmt_Cnt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PSTTrqOverlayLmt_Cnt_f32 = 5.0f;

#pragma DATA_SECTION(k_PSTTrqOvrlChngeLmt_NmpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PSTTrqOvrlChngeLmt_NmpS_f32 = 200.0f;

#pragma DATA_SECTION(k_PSTTrqOvrlChngeLmtDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_PSTTrqOvrlChngeLmtDiag_Cnt_str = {40,2,1};

#pragma DATA_SECTION(k_HaLFTrqOvrlChngeLmt_NmpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HaLFTrqOvrlChngeLmt_NmpS_f32 = 200.0f;

#pragma DATA_SECTION(k_HaLFTrqOverlayDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_HaLFTrqOverlayDiag_Cnt_str = {40,2,1};

#pragma DATA_SECTION(k_BattVoltInvTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_BattVoltInvTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_BattVoltMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_BattVoltMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_ECMA3MsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_ECMA3MsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_ESP4AInvTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_ESP4AInvTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_ESP4AMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_ESP4AMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_IC1AAInvTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_IC1AAInvTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_IC1AMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_IC1AMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_VehCfg1AInvTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_VehCfg1AInvTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_VehCfg1MsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_VehCfg1MsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_VINInvTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_VINInvTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_VINMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_VINMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_BattMsgVoltHighTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_BattMsgVoltHighTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_BattMsgVoltLowTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_BattMsgVoltLowTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_CBCNodeAbsTime_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_CBCNodeAbsTime_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_DSLNodeAbsTime_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_DSLNodeAbsTime_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_StrWhlAnglRatTime_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_StrWhlAnglRatTime_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_VehCfg3InvMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_VehCfg3InvMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);


/******************************* TuningSelAuth *******************************/
#pragma DATA_SECTION(k_TunSelHwTrqLPFKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TunSelHwTrqLPFKn_Hz_f32 = 5.0f;

#pragma DATA_SECTION(k_TunSelHwTrqThresh_HwNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TunSelHwTrqThresh_HwNm_f32 = 2.0f;

#pragma DATA_SECTION(k_TunSelVehSpdThresh_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TunSelVehSpdThresh_Kph_f32 = 100.0f;


/**************************** My_ePWM_LWR, My_CL *****************************/
#pragma DATA_SECTION(t_ActiveDiagInfo_Cnt_u08, ".FlashCal1Seg");
CONST(uint8, CAL_CONST) t_ActiveDiagInfo_Cnt_u08[3] = { 0x00, 0x41, 0x02 };


/*********************************** ePWM ************************************/
#pragma DATA_SECTION(k_PwmRelay_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PwmRelay_Cnt_u16 = 2500U;


/******************************** SrlComInput ********************************/
#pragma DATA_SECTION(k_CRC294DiagThr1_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_CRC294DiagThr1_Cnt_u16 = 4U;

#pragma DATA_SECTION(k_CRC294DiagThr2_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_CRC294DiagThr2_Cnt_str = {8, 2, 1};

#pragma DATA_SECTION(k_DSTMisMsgThr0_ms_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_DSTMisMsgThr0_ms_u16 = 25U;

#pragma DATA_SECTION(k_DSTTOCActMisMsgThr1_Cnt_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_DSTTOCActMisMsgThr1_Cnt_u16p0 = 
	FPM_InitFixedPoint_m(6.0, u16p0_T);

#pragma DATA_SECTION(k_DSTTOCActMisMsgThr2_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_DSTTOCActMisMsgThr2_Cnt_str = {12, 2, 1};

#pragma DATA_SECTION(k_DSTTOCNotActMisMsgThr1_Cnt_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_DSTTOCNotActMisMsgThr1_Cnt_u16p0 = 
	FPM_InitFixedPoint_m(300.0, u16p0_T);

#pragma DATA_SECTION(k_DSTTOCNotActMisMsgThr2_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_DSTTOCNotActMisMsgThr2_Cnt_str = {500, 2,
	 1};

#pragma DATA_SECTION(k_DSTTOCProgCntDiagThr2_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_DSTTOCProgCntDiagThr2_Cnt_str = {8, 2, 1};

#pragma DATA_SECTION(k_DSTTOCProgCntThr1_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_DSTTOCProgCntThr1_Cnt_u16 = 4U;

#pragma DATA_SECTION(k_MsgMaxHalfTorqTO_Nm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MsgMaxHalfTorqTO_Nm_f32 = 1.5f;


/**************************** My_ePWM_LWR, My_CL *****************************/
#pragma DATA_SECTION(t_ECUPartNumber_Cnt_u8, ".FlashCal1Seg");
CONST(uint8, CAL_CONST) t_ECUPartNumber_Cnt_u8[10] = { 0x2A,0x2A,0x2A,0x2A,
	0x2A,0x2A,0x2A,0x2A,0x2A,0x2A };


/***************************** My_ePWM_LWR, Adc ******************************/
#pragma DATA_SECTION(k_MaxADCConvTime_uS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_MaxADCConvTime_uS_u16 = 50U;


/******************************** SrlComInput ********************************/
#pragma DATA_SECTION(k_DSTTrqMax_HwNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_DSTTrqMax_HwNm_f32 = 3.0f;

#pragma DATA_SECTION(k_DSTTrqOvrlSlewLmt_NmpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_DSTTrqOvrlSlewLmt_NmpS_f32 = 200.0f;

#pragma DATA_SECTION(k_MaxDSTActiveTime_mS_u32p0, ".FlashCal1Seg");
CONST(uint32, CAL_CONST) k_MaxDSTActiveTime_mS_u32p0 = 
	FPM_InitFixedPoint_m(5000.0, u32p0_T);

#pragma DATA_SECTION(k_MaxDSTXorCptNTC18F_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_MaxDSTXorCptNTC18F_Cnt_u16 = 
	FPM_InitFixedPoint_m(2.0, u16p0_T);


/**************************** My_ePWM_LWR, My_CL *****************************/
#pragma DATA_SECTION(k_ResetVehicleSpeedLmt_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_ResetVehicleSpeedLmt_Kph_f32 = 10.0f;

#pragma DATA_SECTION(k_ResetAnaHwTorqueLmt_HwNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_ResetAnaHwTorqueLmt_HwNm_f32 = 3.0f;


/********************************* CtrlTemp **********************************/
#pragma DATA_SECTION(k_TempSnsrOffset_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TempSnsrOffset_Volts_f32 = 0.5f;

#pragma DATA_SECTION(k_TempSnsrScaling_DegpVolt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TempSnsrScaling_DegpVolt_f32 = 100.0f;


/******************************** MtrTempEst *********************************/
#pragma DATA_SECTION(k_WtAvgTempDFt_Cnt_lgc, ".FlashCal1Seg");
CONST(Boolean, CAL_CONST) k_WtAvgTempDFt_Cnt_lgc = FALSE;


/******************************** OvrVoltMon *********************************/
#pragma DATA_SECTION(k_CPUSupplyOV_Cnt_Str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_CPUSupplyOV_Cnt_Str = {10,10,1};


/******************************* WIRInputQual ********************************/
#pragma DATA_SECTION(k_WhlSpdQPStep_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_WhlSpdQPStep_Cnt_u16 = 1U;

#pragma DATA_SECTION(k_WhlSpdQLimit_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_WhlSpdQLimit_Cnt_u16 = 10U;

#pragma DATA_SECTION(k_WhlSpdQNStep_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_WhlSpdQNStep_Cnt_u16 = 1U;

#pragma DATA_SECTION(k_WhlSpdQualDiag_Cnt_Str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_WhlSpdQualDiag_Cnt_Str = {30, 10, 1};


/********************************* WhlImbRej *********************************/
#pragma DATA_SECTION(k_NumberOfTaps_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_NumberOfTaps_Cnt_u16 = 30U;

#pragma DATA_SECTION(k_FreqDiagEnable_Cnt_lgc, ".FlashCal1Seg");
CONST(boolean, CAL_CONST) k_FreqDiagEnable_Cnt_lgc = TRUE;

#pragma DATA_SECTION(k_ScaleCancel_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_ScaleCancel_Uls_f32 = 0.1f;

#pragma DATA_SECTION(k_UGRPoleMag_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_UGRPoleMag_Uls_f32 = 0.999f;

#pragma DATA_SECTION(k_WIRRampDownTime_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_WIRRampDownTime_mS_u16p0 = 
	FPM_InitFixedPoint_m(2000.0, u16p0_T);

#pragma DATA_SECTION(k_CmdMagLPFKn1_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CmdMagLPFKn1_Hz_f32 = 5.0f;

#pragma DATA_SECTION(k_CmdMagLPFKn2_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CmdMagLPFKn2_Hz_f32 = 5.0f;

#pragma DATA_SECTION(k_MaxMagFltRecDly_Min_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MaxMagFltRecDly_Min_f32 = 5.0f;

#pragma DATA_SECTION(k_MaxMagFltRecLim_Cnt_u8, ".FlashCal1Seg");
CONST(uint8, CAL_CONST) k_MaxMagFltRecLim_Cnt_u8 = 1;

#pragma DATA_SECTION(k_CorrFltRecDly_Min_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CorrFltRecDly_Min_f32 = 5.0f;

#pragma DATA_SECTION(k_CorrFltRecLim_Cnt_u8, ".FlashCal1Seg");
CONST(uint8, CAL_CONST) k_CorrFltRecLim_Cnt_u8 = 1;

#pragma DATA_SECTION(k_DCTrendFltRecDly_Min_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_DCTrendFltRecDly_Min_f32 = 5.0f;

#pragma DATA_SECTION(k_DCTrendFltRecLim_Cnt_u8, ".FlashCal1Seg");
CONST(uint8, CAL_CONST) k_DCTrendFltRecLim_Cnt_u8 = 1;

#pragma DATA_SECTION(k_FreqDiagFltRecDly_Min_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_FreqDiagFltRecDly_Min_f32 = 5.0f;

#pragma DATA_SECTION(k_FreqDiagFltRecLim_Cnt_u8, ".FlashCal1Seg");
CONST(uint8, CAL_CONST) k_FreqDiagFltRecLim_Cnt_u8 = 1;

#pragma DATA_SECTION(k_WIRDCTrendLPFKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_WIRDCTrendLPFKn_Hz_f32 = 0.2f;

#pragma DATA_SECTION(k_WIRMaxMagDiag_Cnt_Str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_WIRMaxMagDiag_Cnt_Str = {250, 1, 15};

#pragma DATA_SECTION(k_AutoScaleEnable_Cnt_lgc, ".FlashCal1Seg");
CONST(boolean, CAL_CONST) k_AutoScaleEnable_Cnt_lgc = TRUE;

#pragma DATA_SECTION(k_AutoScaleTarget_RadpSec_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AutoScaleTarget_RadpSec_f32 = 0.4f;

#pragma DATA_SECTION(k_FreqDiagLPFKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_FreqDiagLPFKn_Hz_f32 = 2.0f;

#pragma DATA_SECTION(k_FreqDiagUGRPoleMag_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_FreqDiagUGRPoleMag_Uls_f32 = 0.949996948242188f;


/******************************** SrlComInput ********************************/
#pragma DATA_SECTION(k_maxFreqChg_RevpSec_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_maxFreqChg_RevpSec_f32 = 40.0f;

#pragma DATA_SECTION(k_WSP2AInvTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_WSP2AInvTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_WSP2TimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_WSP2TimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_EngCfgMisMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_EngCfgMisMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_EngOilTempMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_EngOilTempMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_ECMA3InvTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_ECMA3InvTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_RevGearMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_RevGearMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_TrnsStatInvTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_TrnsStatInvTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_TrnsStatTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_TrnsStatTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_VehCfg5MsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_VehCfg5MsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);


/****************************** DampingFirewall ******************************/
#pragma DATA_SECTION(t_DampFWDefltDampX_MtrRadpS_u11p5, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_DampFWDefltDampX_MtrRadpS_u11p5[11] = 
	{FPM_InitFixedPoint_m(0.0, u11p5_T), FPM_InitFixedPoint_m(10.0, u11p5_T),
	 FPM_InitFixedPoint_m(25.0, u11p5_T),
	 FPM_InitFixedPoint_m(50.0, u11p5_T),
	 FPM_InitFixedPoint_m(100.0, u11p5_T),
	 FPM_InitFixedPoint_m(150.0, u11p5_T),
	 FPM_InitFixedPoint_m(200.0, u11p5_T),
	 FPM_InitFixedPoint_m(250.0, u11p5_T),
	 FPM_InitFixedPoint_m(300.0, u11p5_T),
	 FPM_InitFixedPoint_m(350.0, u11p5_T),
	 FPM_InitFixedPoint_m(400.0, u11p5_T)};

#pragma DATA_SECTION(t_DampFWDefltDampY_MtrNm_u5p11, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_DampFWDefltDampY_MtrNm_u5p11[11] = 
	{FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.05, u5p11_T),
	 FPM_InitFixedPoint_m(0.1, u5p11_T), FPM_InitFixedPoint_m(0.15, u5p11_T),
	 FPM_InitFixedPoint_m(0.5, u5p11_T), FPM_InitFixedPoint_m(1.4, u5p11_T),
	 FPM_InitFixedPoint_m(2.5, u5p11_T), FPM_InitFixedPoint_m(4.0, u5p11_T),
	 FPM_InitFixedPoint_m(6.0, u5p11_T), FPM_InitFixedPoint_m(10.0, u5p11_T),
	 FPM_InitFixedPoint_m(14.0, u5p11_T)};


/******************** DampingFirewall, FrqDepDmpnInrtCmp *********************/
#pragma DATA_SECTION(k_CmnTbarStiff_NmpDeg_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CmnTbarStiff_NmpDeg_f32 = 2.5f;

#pragma DATA_SECTION(k_CmnSysKinRatio_MtrDegpHwDeg_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CmnSysKinRatio_MtrDegpHwDeg_f32 = 22.0f;


/******************************* ThrmDutyCycle *******************************/
#pragma DATA_SECTION(t_AbsTmpTblX_DegC_s15p0, ".FlashCal1Seg");
CONST(sint16, CAL_CONST) t_AbsTmpTblX_DegC_s15p0[4] = 
	{FPM_InitFixedPoint_m(122.0, s15p0_T),
	 FPM_InitFixedPoint_m(123.0, s15p0_T),
	 FPM_InitFixedPoint_m(125.0, s15p0_T),
	 FPM_InitFixedPoint_m(127.0, s15p0_T)};

#pragma DATA_SECTION(t_AbsTmpTblY_MtrNm_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_AbsTmpTblY_MtrNm_u9p7[4] = 
	{FPM_InitFixedPoint_m(2.703125, u9p7_T),
	 FPM_InitFixedPoint_m(2.242188, u9p7_T),
	 FPM_InitFixedPoint_m(1.828125, u9p7_T),
	 FPM_InitFixedPoint_m(0.0, u9p7_T)};

#pragma DATA_SECTION(k_DefaultIgnOffTime_Sec_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_DefaultIgnOffTime_Sec_f32 = 5000.0f;


/******************************** MtrCtrl_CM *********************************/
#pragma DATA_SECTION(t2_CurrParamLdSatSclFac_Uls_u2p14, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t2_CurrParamLdSatSclFac_Uls_u2p14[6][7] = 
	{{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)}};

#pragma DATA_SECTION(t2_CurrParamLqSatSclFac_Uls_u2p14, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t2_CurrParamLqSatSclFac_Uls_u2p14[6][7] = 
	{{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)}};

#pragma DATA_SECTION(k_NomLq_Henry_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_NomLq_Henry_f32 = 0.00011889f;

#pragma DATA_SECTION(k_NomLd_Henry_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_NomLd_Henry_f32 = 0.00011889f;

#pragma DATA_SECTION(t_RefDeltaPoints_Rad_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) t_RefDeltaPoints_Rad_f32[8] = {-3.1415926535897931f,
	-2.3561944901923448f,-1.5707963267948966f, -0.78539816339744828f, 0.0f,
	0.78539816339744828f, 1.5707963267948966f, 2.3561944901923448f};

#pragma DATA_SECTION(t_Q13VltgSchedXTbl_MtrRadpS_u12p4, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_Q13VltgSchedXTbl_MtrRadpS_u12p4[10] = 
	{FPM_InitFixedPoint_m(0.0, u12p4_T),FPM_InitFixedPoint_m(100.0, u12p4_T),
	FPM_InitFixedPoint_m(200.0, u12p4_T),
	FPM_InitFixedPoint_m(300.0, u12p4_T),
	FPM_InitFixedPoint_m(500.0, u12p4_T),
	FPM_InitFixedPoint_m(600.0, u12p4_T),
	FPM_InitFixedPoint_m(700.0, u12p4_T),
	FPM_InitFixedPoint_m(800.0, u12p4_T),
	FPM_InitFixedPoint_m(900.0, u12p4_T),
	FPM_InitFixedPoint_m(1100.0, u12p4_T)};

#pragma DATA_SECTION(t_Q13VltgSchedYTbl_Volt_u5p11, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_Q13VltgSchedYTbl_Volt_u5p11[10] = 
	{FPM_InitFixedPoint_m(0.0, u5p11_T),FPM_InitFixedPoint_m(0.0, u5p11_T),
	FPM_InitFixedPoint_m(0.0, u5p11_T),FPM_InitFixedPoint_m(0.0, u5p11_T),
	FPM_InitFixedPoint_m(0.0, u5p11_T),FPM_InitFixedPoint_m(0.0, u5p11_T),
	FPM_InitFixedPoint_m(0.0, u5p11_T),FPM_InitFixedPoint_m(0.0, u5p11_T),
	FPM_InitFixedPoint_m(0.0, u5p11_T),FPM_InitFixedPoint_m(0.0, u5p11_T)};

#pragma DATA_SECTION(t_Q24VltgSchedXTbl_MtrRadpS_u12p4, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_Q24VltgSchedXTbl_MtrRadpS_u12p4[10] = 
	{FPM_InitFixedPoint_m(0.0, u12p4_T),FPM_InitFixedPoint_m(100.0, u12p4_T),
	FPM_InitFixedPoint_m(200.0, u12p4_T),
	FPM_InitFixedPoint_m(300.0, u12p4_T),
	FPM_InitFixedPoint_m(500.0, u12p4_T),
	FPM_InitFixedPoint_m(600.0, u12p4_T),
	FPM_InitFixedPoint_m(700.0, u12p4_T),
	FPM_InitFixedPoint_m(800.0, u12p4_T),
	FPM_InitFixedPoint_m(900.0, u12p4_T),
	FPM_InitFixedPoint_m(1100.0, u12p4_T)};

#pragma DATA_SECTION(t_Q24VltgSchedYTbl_Volt_u5p11, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_Q24VltgSchedYTbl_Volt_u5p11[10] = 
	{FPM_InitFixedPoint_m(0.0, u5p11_T),FPM_InitFixedPoint_m(0.0, u5p11_T),
	FPM_InitFixedPoint_m(0.0, u5p11_T),FPM_InitFixedPoint_m(0.0, u5p11_T),
	FPM_InitFixedPoint_m(0.0, u5p11_T),FPM_InitFixedPoint_m(0.0, u5p11_T),
	FPM_InitFixedPoint_m(0.0, u5p11_T),FPM_InitFixedPoint_m(0.0, u5p11_T),
	FPM_InitFixedPoint_m(0.0, u5p11_T),FPM_InitFixedPoint_m(0.0, u5p11_T)};

#pragma DATA_SECTION(k_IdqRefTrqTol_Rad_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_IdqRefTrqTol_Rad_f32 = 0.015f;

#pragma DATA_SECTION(k_IdqRefTrqNIter_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_IdqRefTrqNIter_Cnt_u16 = 3U;

#pragma DATA_SECTION(k_IdqRefIminTol_Amp_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_IdqRefIminTol_Amp_f32 = 0.1f;

#pragma DATA_SECTION(k_IdqRefIminNIter_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_IdqRefIminNIter_Cnt_u16 = 3U;

#pragma DATA_SECTION(k_IdqRefLocateRefNIter_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_IdqRefLocateRefNIter_Cnt_u16 = 10U;

#pragma DATA_SECTION(k_deadtimeVScale_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_deadtimeVScale_Uls_f32 = 1.0f;


/********************************** ElePwr ***********************************/
#pragma DATA_SECTION(k_CntlrInResist_Ohm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CntlrInResist_Ohm_f32 = 0.005f;

#pragma DATA_SECTION(k_PstcPowerLoss_Watt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PstcPowerLoss_Watt_f32 = 10.0f;


/*************************************  **************************************/
#pragma DATA_SECTION(k_TrqReasCmd_Cnt_Str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_TrqReasCmd_Cnt_Str = {1,10,250};

#pragma DATA_SECTION(k_TrqReasIntg_Cnt_Str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_TrqReasIntg_Cnt_Str = {25,10.250};

#pragma DATA_SECTION(k_TrqReasMtrVoltCmdThr_Volt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TrqReasMtrVoltCmdThr_Volt_f32 = 2.0f;

#pragma DATA_SECTION(k_TrqReasMtrVoltIntgThr_Volt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TrqReasMtrVoltIntgThr_Volt_f32 = 5.0f;

#pragma DATA_SECTION(k_TrqReasLPFKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TrqReasLPFKn_Hz_f32 = 10.0f;


/******************************* StabilityComp *******************************/
#pragma DATA_SECTION(k_StCmpStabCmpPstep_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_StCmpStabCmpPstep_Cnt_u16 = 0U;

#pragma DATA_SECTION(k_StCmpStabCmpNstep_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_StCmpStabCmpNstep_Cnt_u16 = 0U;

#pragma DATA_SECTION(k_StCmpStabCmpPNThresh_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_StCmpStabCmpPNThresh_Cnt_u16 = 5000U;


/********************************* TmprlMon **********************************/
#pragma DATA_SECTION(k_TmprlMonPstepNstep_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_TmprlMonPstepNstep_Cnt_str = {20,10,5};


/********************************** SVDiag ***********************************/
#pragma DATA_SECTION(k_LowResPhsReas_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_LowResPhsReas_Cnt_str = {100,1,500};

#pragma DATA_SECTION(k_LowResPhsReasMaxTol_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_LowResPhsReasMaxTol_Uls_f32 = 1.2f;

#pragma DATA_SECTION(k_LowResPhsReasMinTol_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_LowResPhsReasMinTol_Uls_f32 = 0.4f;

#pragma DATA_SECTION(k_LRPRMtrVelDiagEnable_MtrRadpS_T_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_LRPRMtrVelDiagEnable_MtrRadpS_T_f32 = 300.0f;


/******************************** SrlComInput ********************************/
#pragma DATA_SECTION(k_ESPA5MsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_ESPA5MsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_ESPA5ValTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_ESPA5ValTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_ESPA6MsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_ESPA6MsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_ESPA6ValTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_ESPA6ValTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_TireCircRcvdTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_TireCircRcvdTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_TrqOvrlMaxSlewDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_TrqOvrlMaxSlewDiag_Cnt_str = {8, 2, 1};


/********************************** MtrVel ***********************************/
#pragma DATA_SECTION(t_MtrVelTimeOffsetTblX_Kph_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_MtrVelTimeOffsetTblX_Kph_u9p7[3] = 
	{ FPM_InitFixedPoint_m(10.0, u9p7_T), FPM_InitFixedPoint_m(40.0, u9p7_T),
	 FPM_InitFixedPoint_m(100.0, u9p7_T) };

#pragma DATA_SECTION(t_MtrVelTimeOffsetYTbl_uS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_MtrVelTimeOffsetYTbl_uS_u16[3] = { 0U, 100U, 300U };


/********************************** MtrPos ***********************************/
#pragma DATA_SECTION(k_NominalOffset_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_NominalOffset_Volts_f32 = 2.5f;

#pragma DATA_SECTION(k_SysCValMinError_VoltsSqrd_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_SysCValMinError_VoltsSqrd_f32 = 0.0625f;

#pragma DATA_SECTION(k_SysCValMaxError_VoltsSqrd_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_SysCValMaxError_VoltsSqrd_f32 = 1.96f;

#pragma DATA_SECTION(k_SysCMtrPosValDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_SysCMtrPosValDiag_Cnt_str = {50, 10, 1};


/******************************* PwrLmtFuncCr ********************************/
#pragma DATA_SECTION(k_PwrLmtMtrVelLPFKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PwrLmtMtrVelLPFKn_Hz_f32 = 100.0f;


/******************************** SrlComInput ********************************/
#pragma DATA_SECTION(k_CfgRQCMisMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_CfgRQCMisMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_CfgRQMisMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_CfgRQMisMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_EcuCfg6InvMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_EcuCfg6InvMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_GWLINIC2InvMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_GWLINIC2InvMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_GWLINIC2MsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_GWLINIC2MsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_VehCfg7InvMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_VehCfg7InvMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_VehCfg7MsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_VehCfg7MsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);


/********************************** LmtCod ***********************************/
#pragma DATA_SECTION(k_GainDecSlew_UlspS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_GainDecSlew_UlspS_f32 = 500.0f;

#pragma DATA_SECTION(k_TorqueDecSlew_MtrNmpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TorqueDecSlew_MtrNmpS_f32 = 4400.0f;

#pragma DATA_SECTION(t_GainIncSlewTblX_Kph_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_GainIncSlewTblX_Kph_u9p7[2] = 
	{FPM_InitFixedPoint_m(10.0, u9p7_T), FPM_InitFixedPoint_m(20.0, u9p7_T)};

#pragma DATA_SECTION(t_GainIncSlewTblY_UlspS_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_GainIncSlewTblY_UlspS_u9p7[2] = 
	{FPM_InitFixedPoint_m(500.0, u9p7_T),
	 FPM_InitFixedPoint_m(500.0, u9p7_T)};

#pragma DATA_SECTION(t_TorqueIncSlewTblX_Kph_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_TorqueIncSlewTblX_Kph_u9p7[2] = 
	{FPM_InitFixedPoint_m(10.0, u9p7_T), FPM_InitFixedPoint_m(20.0, u9p7_T)};

#pragma DATA_SECTION(t_TorqueIncSlewTblY_MtrNmpS_u13p3, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_TorqueIncSlewTblY_MtrNmpS_u13p3[2] = 
	{FPM_InitFixedPoint_m(4400.0, u13p3_T),
	 FPM_InitFixedPoint_m(4400.0, u13p3_T)};


/************************************ Adc ************************************/
#pragma DATA_SECTION(k_VbattOVTransIntConfig_Cnt_u32, ".FlashCal1Seg");
CONST(uint32, CAL_CONST) k_VbattOVTransIntConfig_Cnt_u32 = 385220609UL;


/********************************* SgnlCond **********************************/
#pragma DATA_SECTION(k_VehAccelSlewRate_KphpSecSq_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_VehAccelSlewRate_KphpSecSq_f32 = 150.0f;


/********************************** HaLFTO ***********************************/
#pragma DATA_SECTION(k_HaLFActvHwTrqTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_HaLFActvHwTrqTime_mS_u16 = 750U;

#pragma DATA_SECTION(k_HaLFActvMaxHwTrq_HwNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HaLFActvMaxHwTrq_HwNm_f32 = 5.0f;

#pragma DATA_SECTION(k_HaLFActvVehSpdTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_HaLFActvVehSpdTime_mS_u16 = 750U;

#pragma DATA_SECTION(k_HaLFActvMinVehSpd_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HaLFActvMinVehSpd_Kph_f32 = 55.0f;

#pragma DATA_SECTION(k_HaLFActvMaxVehSpd_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HaLFActvMaxVehSpd_Kph_f32 = 185.0f;

#pragma DATA_SECTION(k_HaLFActvRevGearTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_HaLFActvRevGearTime_mS_u16 = 750U;

#pragma DATA_SECTION(k_HaLFDeactHwTrqTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_HaLFDeactHwTrqTime_mS_u16 = 750U;

#pragma DATA_SECTION(k_HaLFDeactMaxHwTrq_HwNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HaLFDeactMaxHwTrq_HwNm_f32 = 5.0f;

#pragma DATA_SECTION(k_HaLFDeactVehSpdTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_HaLFDeactVehSpdTime_mS_u16 = 750U;

#pragma DATA_SECTION(k_HaLFDeactMinVehSpd_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HaLFDeactMinVehSpd_Kph_f32 = 55.0f;

#pragma DATA_SECTION(k_HaLFDeactMaxVehSpd_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HaLFDeactMaxVehSpd_Kph_f32 = 185.0f;

#pragma DATA_SECTION(k_HaLFDeactRevGearTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_HaLFDeactRevGearTime_mS_u16 = 750U;


/******************************** SrlComInput ********************************/
#pragma DATA_SECTION(k_StuckTrqBnd_Nm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_StuckTrqBnd_Nm_f32 = 0.0f;

#pragma DATA_SECTION(k_TrqStckActv_HwNm_M_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TrqStckActv_HwNm_M_f32 = 0.0f;

#pragma DATA_SECTION(k_TrqStckHiSWATime_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_TrqStckHiSWATime_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_TrqStckLowSWATime_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_TrqStckLowSWATime_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_TrqStckSWA_HwDeg_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TrqStckSWA_HwDeg_f32 = 0.0f;

#pragma DATA_SECTION(k_DSTTOCInvMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint32, CAL_CONST) k_DSTTOCInvMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u32p0_T);

#pragma DATA_SECTION(k_MaxHlfRmpOutRt_Nm_F32, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_MaxHlfRmpOutRt_Nm_F32 = 
	FPM_InitFixedPoint_m(0.0, u16p0_T);

#pragma DATA_SECTION(k_MtrTrqOvrlyStrRqMax_Nm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MtrTrqOvrlyStrRqMax_Nm_f32 = 65535.0f;

#pragma DATA_SECTION(k_PerMisMchCntLmt_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PerMisMchCntLmt_Cnt_u16 = 7U;

#pragma DATA_SECTION(k_PerMisMchFltThr_Cnt_u08, ".FlashCal1Seg");
CONST(uint8, CAL_CONST) k_PerMisMchFltThr_Cnt_u08 = 65535;


/*********************************** StaMd ***********************************/
#pragma DATA_SECTION(k_StaMdsSysCDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_StaMdsSysCDiag_Cnt_str = {21,10,1};


/********************************** BkCpPc ***********************************/
#pragma DATA_SECTION(k_MtrMotionThresh_MtrRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MtrMotionThresh_MtrRadpS_f32 = 100.0f;

#pragma DATA_SECTION(k_PwrDiscOpenThresh_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PwrDiscOpenThresh_Volts_f32 = 2.0f;

#pragma DATA_SECTION(k_PMOSDIAGOpenThresh_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PMOSDIAGOpenThresh_Volts_f32 = 0.5f;

#pragma DATA_SECTION(k_OVERRIDESIGDIAGOpenThresh_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_OVERRIDESIGDIAGOpenThresh_Volts_f32 = 0.5f;

#pragma DATA_SECTION(k_VerifyPwrDiscOpenThresh_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_VerifyPwrDiscOpenThresh_mS_u16 = 100U;

#pragma DATA_SECTION(k_WaitForSqrWaveThresh_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_WaitForSqrWaveThresh_mS_u16 = 100U;

#pragma DATA_SECTION(k_PwrDiscCloseThresh_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PwrDiscCloseThresh_Volts_f32 = 0.5f;

#pragma DATA_SECTION(k_PrechargeThresh_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PrechargeThresh_mS_u16 = 400U;

#pragma DATA_SECTION(k_PMOSVError_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PMOSVError_Volts_f32 = 1.0f;

#pragma DATA_SECTION(k_PMOSTError_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PMOSTError_mS_u16 = 50U;

#pragma DATA_SECTION(k_MaxDischEst_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MaxDischEst_Uls_f32 = 0.99f;

#pragma DATA_SECTION(k_MinDischEst_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MinDischEst_Uls_f32 = 0.98f;

#pragma DATA_SECTION(k_VswitchDeltaThresh_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_VswitchDeltaThresh_Volts_f32 = 0.5f;

#pragma DATA_SECTION(k_VerifyPwrDiscCloseThresh_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_VerifyPwrDiscCloseThresh_mS_u16 = 100U;

#pragma DATA_SECTION(k_ChargePumpDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_ChargePumpDiag_Cnt_str = {100, 4, 1};

#pragma DATA_SECTION(k_VbattSwitchThreshNonExt_Volt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_VbattSwitchThreshNonExt_Volt_f32 = 7.0f;

#pragma DATA_SECTION(k_VbattSwitchThreshExNorm_Volt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_VbattSwitchThreshExNorm_Volt_f32 = 8.0f;

#pragma DATA_SECTION(k_ChargeMinDeltaNonOp_Volt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_ChargeMinDeltaNonOp_Volt_f32 = 0.0f;

#pragma DATA_SECTION(k_ChargeMinDeltaExtOp_Volt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_ChargeMinDeltaExtOp_Volt_f32 = 5.0f;

#pragma DATA_SECTION(k_ChargeMinDeltaNormlOp_Volt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_ChargeMinDeltaNormlOp_Volt_f32 = 6.0f;


/******************************** CMS_Common *********************************/
#pragma DATA_SECTION(k_NxtrSrvcPosTrajThres_HwDeg_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_NxtrSrvcPosTrajThres_HwDeg_f32 = 2.0f;

#pragma DATA_SECTION(k_NxtrSrvcPosTrajHoldTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_NxtrSrvcPosTrajHoldTime_mS_u16 = 5000U;

#pragma DATA_SECTION(k_NxtrSrvcHandsOnTime_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_NxtrSrvcHandsOnTime_mS_u16 = 5000U;

#pragma DATA_SECTION(k_F00FHandsOnThres_HwNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_F00FHandsOnThres_HwNm_f32 = 0.5f;


/****************************** DampingFirewall ******************************/
#pragma DATA_SECTION(k_DampFWVBICLPF_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_DampFWVBICLPF_Hz_f32 = 10.0f;


/********************************** SVDiag ***********************************/
#pragma DATA_SECTION(k_OnStateDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_OnStateDiag_Cnt_str = {1500, 512, 1};

#pragma DATA_SECTION(k_GateDriveDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_GateDriveDiag_Cnt_str = {1500, 512, 1};


/*************************************  **************************************/
#pragma DATA_SECTION(k_SrvcHwTrqLimit_HwNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_SrvcHwTrqLimit_HwNm_f32 = 1.0f;

#pragma DATA_SECTION(k_SrvcVehSpdLimit_Kph_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_SrvcVehSpdLimit_Kph_f32 = 10.0f;


/******************************* PwrLmtFuncCr ********************************/
#pragma DATA_SECTION(t_DLVTblX_Volt_u5p11, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_DLVTblX_Volt_u5p11[10] = 
	{FPM_InitFixedPoint_m(8.54296875, u5p11_T),
	 FPM_InitFixedPoint_m(9.14453125, u5p11_T),
	 FPM_InitFixedPoint_m(9.2421875, u5p11_T),
	 FPM_InitFixedPoint_m(9.34375, u5p11_T),
	 FPM_InitFixedPoint_m(9.44140625, u5p11_T),
	 FPM_InitFixedPoint_m(9.54296875, u5p11_T),
	 FPM_InitFixedPoint_m(10.04296875, u5p11_T),
	 FPM_InitFixedPoint_m(10.54296875, u5p11_T),
	 FPM_InitFixedPoint_m(10.84375, u5p11_T),
	 FPM_InitFixedPoint_m(12.34375, u5p11_T)};

#pragma DATA_SECTION(t_DLVTblY_MtrRadpS_u11p5, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_DLVTblY_MtrRadpS_u11p5[10] = 
	{FPM_InitFixedPoint_m(106.09375, u11p5_T),
	 FPM_InitFixedPoint_m(89.34375, u11p5_T),
	 FPM_InitFixedPoint_m(86.53125, u11p5_T),
	 FPM_InitFixedPoint_m(83.75, u11p5_T),
	 FPM_InitFixedPoint_m(80.96875, u11p5_T),
	 FPM_InitFixedPoint_m(78.15625, u11p5_T),
	FPM_InitFixedPoint_m(64.1875, u11p5_T),
	FPM_InitFixedPoint_m(50.25, u11p5_T),
	FPM_InitFixedPoint_m(41.875, u11p5_T),FPM_InitFixedPoint_m(0.0, u11p5_T)};

#pragma DATA_SECTION(t_MtrEnvTblX_MtrRadpS_s11p4, ".FlashCal1Seg");
CONST(sint16, CAL_CONST) t_MtrEnvTblX_MtrRadpS_s11p4[14] = 
	{FPM_InitFixedPoint_m(-1100.0, s11p4_T),
	 FPM_InitFixedPoint_m(-800.0, s11p4_T),
	 FPM_InitFixedPoint_m(-650.0, s11p4_T),
	 FPM_InitFixedPoint_m(-550.0, s11p4_T),
	 FPM_InitFixedPoint_m(-353.5625, s11p4_T),
	 FPM_InitFixedPoint_m(-287.46875, s11p4_T),
	 FPM_InitFixedPoint_m(-218.65625, s11p4_T),
	 FPM_InitFixedPoint_m(-108.1875, s11p4_T),
	 FPM_InitFixedPoint_m(0.0, s11p4_T),
	 FPM_InitFixedPoint_m(108.1875, s11p4_T),
	 FPM_InitFixedPoint_m(218.65625, s11p4_T),
	 FPM_InitFixedPoint_m(287.46875, s11p4_T),
	 FPM_InitFixedPoint_m(353.5625, s11p4_T),
	 FPM_InitFixedPoint_m(550.0, s11p4_T)};

#pragma DATA_SECTION(t_MtrEnvTblY_MtrNm_u5p11, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_MtrEnvTblY_MtrNm_u5p11[14] = 
	{FPM_InitFixedPoint_m(0.720, u5p11_T),
	 FPM_InitFixedPoint_m(1.400, u5p11_T),
	 FPM_InitFixedPoint_m(1.900, u5p11_T),
	 FPM_InitFixedPoint_m(2.300, u5p11_T),
	 FPM_InitFixedPoint_m(3.500, u5p11_T),
	 FPM_InitFixedPoint_m(4.100, u5p11_T),
	 FPM_InitFixedPoint_m(4.632, u5p11_T),
	 FPM_InitFixedPoint_m(4.632, u5p11_T),
	 FPM_InitFixedPoint_m(4.632, u5p11_T),
	 FPM_InitFixedPoint_m(4.632, u5p11_T),
	 FPM_InitFixedPoint_m(3.553, u5p11_T),
	 FPM_InitFixedPoint_m(2.927, u5p11_T),
	 FPM_InitFixedPoint_m(2.200, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T)};

#pragma DATA_SECTION(k_KeStdTemp_VpRadpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_KeStdTemp_VpRadpS_f32 = 0.033599854f;

#pragma DATA_SECTION(t_StdOpMtrEnvTblX_MtrRadpS_u11p5, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_StdOpMtrEnvTblX_MtrRadpS_u11p5[6] = 
	{FPM_InitFixedPoint_m(0.0, u11p5_T),
	 FPM_InitFixedPoint_m(68.1875, u11p5_T),
	FPM_InitFixedPoint_m(178.656, u11p5_T),
	FPM_InitFixedPoint_m(247.468, u11p5_T),
	FPM_InitFixedPoint_m(313.5625, u11p5_T),
	FPM_InitFixedPoint_m(510.0, u11p5_T)};

#pragma DATA_SECTION(t_StdOpMtrEnvTblY_MtrNm_u4p12, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_StdOpMtrEnvTblY_MtrNm_u4p12[6] = 
	{FPM_InitFixedPoint_m(4.632, u4p12_T),
	 FPM_InitFixedPoint_m(4.632, u4p12_T),
	 FPM_InitFixedPoint_m(3.553, u4p12_T),
	 FPM_InitFixedPoint_m(2.927, u4p12_T),
	 FPM_InitFixedPoint_m(2.200, u4p12_T),
	 FPM_InitFixedPoint_m(0.000, u4p12_T)};

#pragma DATA_SECTION(k_FiltAsstReducTh_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_FiltAsstReducTh_Uls_f32 = 0.6f;

#pragma DATA_SECTION(k_PwrLmtVecuAltFltAdj_Volt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PwrLmtVecuAltFltAdj_Volt_f32 = 1.0f;

#pragma DATA_SECTION(k_PwrLmtVecuAdjSlew_VoltspL_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_PwrLmtVecuAdjSlew_VoltspL_f32 = 0.001f;


/********************************** BVDiag ***********************************/
#pragma DATA_SECTION(k_MSALowNotDetect_Volts_u10p6, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_MSALowNotDetect_Volts_u10p6 = 
	FPM_InitFixedPoint_m(9.0, u10p6_T);

#pragma DATA_SECTION(k_MSALowDetect_Volts_u10p6, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_MSALowDetect_Volts_u10p6 = 
	FPM_InitFixedPoint_m(9.0, u10p6_T);

#pragma DATA_SECTION(k_MSALowDetect_ms_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_MSALowDetect_ms_u16p0 = 
	FPM_InitFixedPoint_m(1000.0, u16p0_T);

#pragma DATA_SECTION(k_MSALowNotDetect_ms_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_MSALowNotDetect_ms_u16p0 = 
	FPM_InitFixedPoint_m(600.0, u16p0_T);


/******************************** SrlComInput ********************************/
#pragma DATA_SECTION(k_AnaHwTorquePerLim_HwNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AnaHwTorquePerLim_HwNm_f32 = 5.0f;

#pragma DATA_SECTION(k_HaLFTrqPerLim_HwNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HaLFTrqPerLim_HwNm_f32 = 5.0f;

#pragma DATA_SECTION(k_DesiredTuning_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_DesiredTuning_Cnt_u16[2][15] = {{0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U},{0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U}};

#pragma DATA_SECTION(k_TuningPerformedTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_TuningPerformedTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_HalfTrqMaxSpt_Nm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HalfTrqMaxSpt_Nm_f32 = 5.0f;

#pragma DATA_SECTION(k_HaLFTrqOvrlSlewLmtSpt_NmpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HaLFTrqOvrlSlewLmtSpt_NmpS_f32 = 5.0f;

#pragma DATA_SECTION(k_HalfTrqMaxNrm_Nm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HalfTrqMaxNrm_Nm_f32 = 5.0f;

#pragma DATA_SECTION(k_HaLFTrqOvrlSlewLmtNrm_NmpS_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_HaLFTrqOvrlSlewLmtNrm_NmpS_f32 = 5.0f;

#pragma DATA_SECTION(k_EstFricLim_HwNm_T_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_EstFricLim_HwNm_T_f32 = 5.0f;

#pragma DATA_SECTION(k_HndsOnDrngPAA_mS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_HndsOnDrngPAA_mS_u16 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);


/********************************* CtrlTemp **********************************/
#pragma DATA_SECTION(k_CustDiagAmbLowThresh_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CustDiagAmbLowThresh_DegC_f32 = -30.0f;

#pragma DATA_SECTION(k_CustDiagAmbLowEnable_Cnt_lgc, ".FlashCal1Seg");
CONST(boolean, CAL_CONST) k_CustDiagAmbLowEnable_Cnt_lgc = FALSE;


/********************************** BVDiag ***********************************/
#pragma DATA_SECTION(k_BattDiagUvMin_Volt_u10p6, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_BattDiagUvMin_Volt_u10p6 = 
	FPM_InitFixedPoint_m(9.0, u10p6_T);

#pragma DATA_SECTION(k_UvNotDetect_ms_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_UvNotDetect_ms_u16p0 = 
	FPM_InitFixedPoint_m(15000.0, u16p0_T);

#pragma DATA_SECTION(k_UvDetect_ms_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_UvDetect_ms_u16p0 = 
	FPM_InitFixedPoint_m(15000.0, u16p0_T);

#pragma DATA_SECTION(k_BattUvRecMax_Volt_u10p6, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_BattUvRecMax_Volt_u10p6 = 
	FPM_InitFixedPoint_m(16.5, u10p6_T);

#pragma DATA_SECTION(k_BattDiagUvMax_Volt_u10p6, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_BattDiagUvMax_Volt_u10p6 = 
	FPM_InitFixedPoint_m(10.0, u10p6_T);


/********************************** DiagMgr **********************************/
#pragma DATA_SECTION(t_LatchFaults_Cnt_str, ".FlashCal1Seg");
CONST(NTCLatch_Str, CAL_CONST) t_LatchFaults_Cnt_str[8] = {{0x000,{65535,1,
	1}},{0x000,{65535,1,1}},{0x000,{65535,1,1}},{0x000,{65535,1,1}},{0x000,
	{65535,1,1}},{0x000,{65535,1,1}},{0x000,{65535,1,1}},{0x000,{65535,1,1}}};


/********************************** SVDiag ***********************************/
#pragma DATA_SECTION(k_LRPRCommOffsetMargin_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_LRPRCommOffsetMargin_Uls_f32 = 1.05f;


/*********************************** My_CL ***********************************/
#pragma DATA_SECTION(k_VrefOORDiag_Cnt_str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_VrefOORDiag_Cnt_str = {100,4,1};

#pragma DATA_SECTION(k_VrefMax_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_VrefMax_Volts_f32 = 3.0f;

#pragma DATA_SECTION(k_VrefMin_Volts_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_VrefMin_Volts_f32 = 2.0f;

#pragma DATA_SECTION(k_GenMaxADCWaitTime_uS_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_GenMaxADCWaitTime_uS_u16 = 1000U;

#pragma DATA_SECTION(k_ADCVrefScaling_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_ADCVrefScaling_Uls_f32 = 1.0f;


/******************************** MtrCtrl_CM *********************************/
#pragma DATA_SECTION(k_Harmonic6thElec_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_Harmonic6thElec_Uls_f32 = 6.0f;

#pragma DATA_SECTION(k_Harmonic12thElec_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_Harmonic12thElec_Uls_f32 = 12.0f;

#pragma DATA_SECTION(k_Harmonic18thElec_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_Harmonic18thElec_Uls_f32 = 18.0f;

#pragma DATA_SECTION(t2_MtrCurrQaxRpl18X_Amp_s6p9, ".FlashCal1Seg");
CONST(sint16, CAL_CONST) t2_MtrCurrQaxRpl18X_Amp_s6p9[6][7] = 
	{{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)}, {FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)},
	{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)},{FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)},
	{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)},{FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)}};

#pragma DATA_SECTION(t2_MtrCurrQaxRpl18Y_Amp_s6p9, ".FlashCal1Seg");
CONST(sint16, CAL_CONST) t2_MtrCurrQaxRpl18Y_Amp_s6p9[6][7] = 
	{{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)}, {FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)},
	{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)},{FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)},
	{FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T)},{FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T),
	FPM_InitFixedPoint_m(0.0, s6p9_T),FPM_InitFixedPoint_m(0.0, s6p9_T)}};

#pragma DATA_SECTION(t_MtrCurrQaxRplPIY_Amp_u9p7, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_MtrCurrQaxRplPIY_Amp_u9p7[7] = 
	{FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(25.0, u9p7_T),
	FPM_InitFixedPoint_m(50.0, u9p7_T),FPM_InitFixedPoint_m(75.0, u9p7_T),
	FPM_InitFixedPoint_m(100.0, u9p7_T),FPM_InitFixedPoint_m(125.0, u9p7_T),
	FPM_InitFixedPoint_m(135.0, u9p7_T)};

#pragma DATA_SECTION(t_MtrVelX_MtrRadpS_T_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_MtrVelX_MtrRadpS_T_u16[10] = {0U,100U,114U,303U,
	800U,1200U,2620U,3200U,8492U,11100U};

#pragma DATA_SECTION(t2_MtrTrqCancPIMagRP_Uls_u6p10, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t2_MtrTrqCancPIMagRP_Uls_u6p10[10][7] = 
	{{FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T)},{FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T)},
	{FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T)},{FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T)},
	{FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T)},{FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T)},
	{FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T)},{FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T)},
	{FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T)},{FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T)}};

#pragma DATA_SECTION(t2_MtrTrqCancPIPhRP_Rev_u0p16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t2_MtrTrqCancPIPhRP_Rev_u0p16[10][7] = 
	{{FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T)},{FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T)},
	{FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T)},{FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T)},
	{FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T)},{FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T)},
	{FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T)},{FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T)},
	{FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T)},{FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T),
	FPM_InitFixedPoint_m(0.0, u0p16_T),FPM_InitFixedPoint_m(0.0, u0p16_T)}};


/******************************** SrlComInput ********************************/
#pragma DATA_SECTION(k_PTSDrStylTunSet_Cnt_u16, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_PTSDrStylTunSet_Cnt_u16 = 0U;

#pragma DATA_SECTION(k_MtrTorqOvrlStrReqPol_Cnt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_MtrTorqOvrlStrReqPol_Cnt_f32 = 1.0f;


/******************************** MtrCtrl_CM *********************************/
#pragma DATA_SECTION(k_IdBoostGain_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_IdBoostGain_Uls_f32 = 0.0f;

#pragma DATA_SECTION(k_IdBoostVRThreshScl_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_IdBoostVRThreshScl_Uls_f32 = 0.25f;

#pragma DATA_SECTION(t_IdBoostTrqCmdX_MtrNm_u4p12, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_IdBoostTrqCmdX_MtrNm_u4p12[11] = 
	{FPM_InitFixedPoint_m(0.0, u4p12_T),FPM_InitFixedPoint_m(1.5, u4p12_T),
	FPM_InitFixedPoint_m(1.75, u4p12_T),FPM_InitFixedPoint_m(2.0, u4p12_T),
	FPM_InitFixedPoint_m(2.25, u4p12_T),FPM_InitFixedPoint_m(2.5, u4p12_T),
	FPM_InitFixedPoint_m(3.0, u4p12_T),FPM_InitFixedPoint_m(3.5, u4p12_T),
	FPM_InitFixedPoint_m(4.0, u4p12_T),FPM_InitFixedPoint_m(4.5, u4p12_T),
	FPM_InitFixedPoint_m(5.0, u4p12_T)};

#pragma DATA_SECTION(t_IdBoostTrqCharSclY_Uls_u1p15, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) t_IdBoostTrqCharSclY_Uls_u1p15[11] = 
	{FPM_InitFixedPoint_m(0.0, u1p15_T),FPM_InitFixedPoint_m(0.5, u1p15_T),
	FPM_InitFixedPoint_m(0.6, u1p15_T),FPM_InitFixedPoint_m(0.7, u1p15_T),
	FPM_InitFixedPoint_m(0.725, u1p15_T),
	FPM_InitFixedPoint_m(0.775, u1p15_T),
	FPM_InitFixedPoint_m(0.825, u1p15_T),FPM_InitFixedPoint_m(0.85, u1p15_T),
	FPM_InitFixedPoint_m(0.9, u1p15_T),FPM_InitFixedPoint_m(0.95, u1p15_T),
	FPM_InitFixedPoint_m(1.0, u1p15_T)};


/********************************** TqRsDg ***********************************/
#pragma DATA_SECTION(k_CurrDiagPrimLPFKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CurrDiagPrimLPFKn_Hz_f32 = 1.0f;

#pragma DATA_SECTION(k_CurrDiagSecLPFKn_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CurrDiagSecLPFKn_Hz_f32 = 1.0f;

#pragma DATA_SECTION(k_CurrDiagSecTrqLmtThresh_Uls_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CurrDiagSecTrqLmtThresh_Uls_f32 = 0.0f;

#pragma DATA_SECTION(k_CurrDiagPrimErrorThresh_Volt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CurrDiagPrimErrorThresh_Volt_f32 = 20.0f;

#pragma DATA_SECTION(k_CurrDiagSecErrorThresh_Volt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CurrDiagSecErrorThresh_Volt_f32 = 20.0f;

#pragma DATA_SECTION(k_CurrDiagSec_Cnt_Str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_CurrDiagSec_Cnt_Str = {200,2,1};

#pragma DATA_SECTION(k_CurrDiagPrim_Cnt_Str, ".FlashCal1Seg");
CONST(DiagSettings_Str, CAL_CONST) k_CurrDiagPrim_Cnt_Str = {200,2,1};

#pragma DATA_SECTION(k_CurrDiagMtrEnvTblMax_MtrNm_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CurrDiagMtrEnvTblMax_MtrNm_f32 = 4.6f;


/********************************* CmMtrCurr *********************************/
#pragma DATA_SECTION(k_CurrCorrErrFiltFc_Hz_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CurrCorrErrFiltFc_Hz_f32 = 1.7953429f;


/********************************** TqRsDg ***********************************/
#pragma DATA_SECTION(k_CurrDiagLambdaMinMax_Volt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_CurrDiagLambdaMinMax_Volt_f32 = 3.0f;


/******************************** SrlComInput ********************************/
#pragma DATA_SECTION(k_TOReqPol_Cnt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TOReqPol_Cnt_f32 = 1.0f;

#pragma DATA_SECTION(k_TorqOvrlStrReqPol_Cnt_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_TorqOvrlStrReqPol_Cnt_f32 = 1.0f;

#pragma DATA_SECTION(k_GrInvTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_GrInvTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);

#pragma DATA_SECTION(k_TRNSSPMsgTimeOut_mS_u16p0, ".FlashCal1Seg");
CONST(uint16, CAL_CONST) k_TRNSSPMsgTimeOut_mS_u16p0 = 
	FPM_InitFixedPoint_m(5000.0, u16p0_T);


/******************************** MtrTempEst *********************************/
#pragma DATA_SECTION(k_AMCorrLmt_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AMCorrLmt_DegC_f32 = 60.0f;

#pragma DATA_SECTION(k_AMDefaultTemp_DegC_f32, ".FlashCal1Seg");
CONST(float32, CAL_CONST) k_AMDefaultTemp_DegC_f32 = 50.0f;



/*********************** Start of Code Footer ************************/

CONSTP2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) T_TunSetSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16] =
		{	&k_TunSet0_Cnt_Str,
			&k_TunSet1_Cnt_Str,
			&k_TunSet2_Cnt_Str,
			&k_TunSet3_Cnt_Str,
			&k_TunSet4_Cnt_Str,
			&k_TunSet5_Cnt_Str,
			&k_TunSet6_Cnt_Str,
			&k_TunSet7_Cnt_Str,
			&k_TunSet8_Cnt_Str,
			&k_TunSet9_Cnt_Str,
			&k_TunSet10_Cnt_Str,
			&k_TunSet11_Cnt_Str,
			&k_TunSet12_Cnt_Str,
			&k_TunSet13_Cnt_Str,
			&k_TunSet14_Cnt_Str };

CONSTP2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) T_TunPersSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16][D_NUMOFPERS_CNT_U16] =
		{	{
				&k_TunSet0Per0_Cnt_Str,
				&k_TunSet0Per1_Cnt_Str,
				&k_TunSet0Per2_Cnt_Str},
				{&k_TunSet1Per0_Cnt_Str,
				&k_TunSet1Per1_Cnt_Str,
				&k_TunSet1Per2_Cnt_Str},
				{&k_TunSet2Per0_Cnt_Str,
				&k_TunSet2Per1_Cnt_Str,
				&k_TunSet2Per2_Cnt_Str},
				{&k_TunSet3Per0_Cnt_Str,
				&k_TunSet3Per1_Cnt_Str,
				&k_TunSet3Per2_Cnt_Str},
				{&k_TunSet4Per0_Cnt_Str,
				&k_TunSet4Per1_Cnt_Str,
				&k_TunSet4Per2_Cnt_Str},
				{&k_TunSet5Per0_Cnt_Str,
				&k_TunSet5Per1_Cnt_Str,
				&k_TunSet5Per2_Cnt_Str},
				{&k_TunSet6Per0_Cnt_Str,
				&k_TunSet6Per1_Cnt_Str,
				&k_TunSet6Per2_Cnt_Str},
				{&k_TunSet7Per0_Cnt_Str,
				&k_TunSet7Per1_Cnt_Str,
				&k_TunSet7Per2_Cnt_Str},
				{&k_TunSet8Per0_Cnt_Str,
				&k_TunSet8Per1_Cnt_Str,
				&k_TunSet8Per2_Cnt_Str},
				{&k_TunSet9Per0_Cnt_Str,
				&k_TunSet9Per1_Cnt_Str,
				&k_TunSet9Per2_Cnt_Str},
				{&k_TunSet10Per0_Cnt_Str,
				&k_TunSet10Per1_Cnt_Str,
				&k_TunSet10Per2_Cnt_Str},
				{&k_TunSet11Per0_Cnt_Str,
				&k_TunSet11Per1_Cnt_Str,
				&k_TunSet11Per2_Cnt_Str},
				{&k_TunSet12Per0_Cnt_Str,
				&k_TunSet12Per1_Cnt_Str,
				&k_TunSet12Per2_Cnt_Str},
				{&k_TunSet13Per0_Cnt_Str,
				&k_TunSet13Per1_Cnt_Str,
				&k_TunSet13Per2_Cnt_Str},
				{&k_TunSet14Per0_Cnt_Str,
				&k_TunSet14Per1_Cnt_Str,
				&k_TunSet14Per2_Cnt_Str},
										};




























































