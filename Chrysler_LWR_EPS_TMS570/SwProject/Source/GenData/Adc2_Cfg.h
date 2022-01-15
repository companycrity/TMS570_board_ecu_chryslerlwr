/*****************************************************************************
* Copyright 2012 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Adc2_Cfg.h
* Module Description: Adc2 Complex Driver configuration
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Sat Jul 28 18:03:04 2012
* %version:          4 %
* %derived_by:       jzh87w %
* %date_modified:    Thu Feb 13 15:49:29 2014 %
*---------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/14/14   4        SAH       Add Adc2_GetVswitched_Cnt_u16_m macro and D_ADC2VSWITCHED_CNT_U16
 */

#ifndef ADC2_CFG_H
#define ADC2_CFG_H

/* Include definitions for Diagnostic Event API */
#include "Ap_DiagMgr.h"

#define D_ADC2NUMEVTCH_CNT_U08	4U				/* Number of channels sampled (e.g. number of bits set in D_ADC2EVTCH_CNT_U32) */
#define D_ADC2EVTCH_CNT_U32		0x00000603U
#define D_ADC2EVTBUFSZ_CNT_U08	4U				/* Number of results allocated in ADC RAM, must be even */
#define D_ADC2EVSRC_CNT_U32		3U

#define D_ADC2NUMG1CH_CNT_U08	4U				/* Number of channels sampled (e.g. number of bits set in D_ADC2G1CH_CNT_U32) */
#define D_ADC2G1CH_CNT_U32		0x0000E100U
#define D_ADC2G1BUFSZ_CNT_U08	4U				/* Number of results allocated in ADC RAM, must be even */
#define D_ADC2G1SRC_CNT_U32		1U

#define D_ADC2NUMG2CH_CNT_U08	4U				/* Number of channels sampled (e.g. number of bits set in D_ADC2G2CH_CNT_U32) */
#define D_ADC2G2CH_CNT_U32		0x00000603U
#define D_ADC2G2BUFSZ_CNT_U08	56U				/* Number of results allocated in ADC RAM, must be even */
#define D_ADC2G2SRC_CNT_U32		0U


#define ADC2_E_PERDIAG_FAILURE		NTC_Num_PerDiag_ADC2Flt

#define ADC2_E_PERDIAG_INFO				0x04U

#define ADC2_REPORTERRORSTATUS(event, param, status)		NxtrDiagMgr10_ReportNTCStatus(event, param, status)
#define ADC2_EVENT_PASSED				NTC_STATUS_PASSED
#define ADC2_EVENT_FAILED				NTC_STATUS_FAILED


/* The following macros are designed to grant access to the motor Isr adc results
 *  At the moment, for efficiency, they allow direct access to the ADC results.
 * NOTE: This API is an extension to the AUTOSAR Adc API.
 */

#define  D_PHASEBCHN_CNT_U16           0U
#define  D_PHASECCHN_CNT_U16           1U
#define  D_COSTHETA1CHN_CNT_U16        2U
#define  D_SINTHETA1CHN_CNT_U16        3U
#define  D_ADC2VSWITCHED_CNT_U16	   5U
#define  D_ADC2T1CHN_CNT_U16           6U
#define  D_ADC2T2CHN_CNT_U16           7U

#define Adc2_GetPhsBCurr_Cnt_u16_m   Adc2_ReadConversion(D_PHASEBCHN_CNT_U16)
#define Adc2_GetPhsCCurr_Cnt_u16_m   Adc2_ReadConversion(D_PHASECCHN_CNT_U16)
#define Adc2_GetCosTheta1_Cnt_u16_m  Adc2_ReadConversion(D_COSTHETA1CHN_CNT_U16)
#define Adc2_GetSinTheta1_Cnt_u16_m  Adc2_ReadConversion(D_SINTHETA1CHN_CNT_U16)
#define Adc2_GetVSwitched_Cnt_u16_m	 Adc2_ReadConversion(D_ADC2VSWITCHED_CNT_U16)
#define Adc2_GetT1_Cnt_u16_m         Adc2_ReadConversion(D_ADC2T1CHN_CNT_U16)
#define Adc2_GetT2_Cnt_u16_m         Adc2_ReadConversion(D_ADC2T2CHN_CNT_U16)

#endif
