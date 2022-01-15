
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Cd_NvMProxy_Cfg.h
* Module Description: Configuration of the Cd_NvMProxy BSW
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
 * Version Control:
 * Date Created:      Tue Feb  7 11:23:49 2012
 * %version:          EA3#3.1.6 %
 * %derived_by:       gz324f %
 * %date_modified:    Wed Feb  5 13:43:52 2014 % 
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/07/12   1        JJW       Initial creation
 * 10/17/12   2        JJW       Generated output file
 * 05/30/13   3        JJW       Removed unsuported config feature, added multi-block support
 * 11/21/13   4        LWW       Added Redundant and CRC checking options
 */

#ifndef NVMPROXY_CFG_H
#define NVMPROXY_CFG_H


/* Include defs for data block types */
#ifndef _RTE_TYPE_H
	#define RTE_MICROSAR_PIM_EXPORT /* Define the Rte constant to allow exporting of PIM types to this CDD */
	#include "Rte_Type.h"
#endif
#include "NvM.h"
#include "Ap_DiagMgr.h"
#include "Ap_StaMd_Cfg.h"

#define D_CRC16SIZE_CNT_U16		2


typedef P2CONST(uint8, AUTOMATIC, AUTOMATIC) NvMP_FailActionDataType;
typedef P2FUNC(void, AUTOMATIC, NvMP_FailActFuncType)(void);

typedef enum {
	NVMPROXY_NONE = 0x00,
	NVMPROXY_CRC16 = 0x01,
	NVMPROXY_REDUNDANT = 0x02,
	NVMPROXY_ZERODATA = 0x03
}NvMProxy_InitHandling;

typedef enum {
	NVMPROXY_NOTAPPLICABLE = 0x00,
	NVMPROXY_NTC_0A = 0x01,
	NVMPROXY_NTC_08_ROMDEF = 0x02,
	NVMPROXY_NTC_08_NOTIFFUNC = 0x03,
	NVMPROXY_NTC_07_ROMDEF = 0x04,
	NVMPROXY_NTC_07_NOTIFFUNC = 0x05,
	NVMPROXY_NTC_06_ROMDEF = 0x06,
	NVMPROXY_NTC_06_NOTIFFUNC = 0x07
}NvMProxy_FailResponse;

typedef struct {
	CONST(NvM_BlockIdType, AUTOMATIC) NvMBlock;
	CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) unsecurePtr;
	CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) securePtr;
	CONST(uint16, AUTOMATIC) secureSize;
	CONST(NvMProxy_InitHandling, AUTOMTIC) initHandling;
	CONST(NvMProxy_FailResponse, AUTOMTIC) failResponse;
	CONST(NvMP_FailActionDataType, AUTOMATIC) failActData;
	CONST(NvMP_FailActFuncType, AUTOMATIC) failActFunc;
} NvMProxyCfg_Type;

#define D_NUMPRXYBLOCKS_CNT_U16    		15u
#define NVMPROXY_REPORTERRORSTATUS		NxtrDiagMgr10_ReportNTCStatus

extern CONST(NvMProxyCfg_Type, AUTOMATIC) NvMProxyCfg[D_NUMPRXYBLOCKS_CNT_U16];

/* Only provide externs if PIM Export is defined (won't compile otherwise) */
#ifdef RTE_MICROSAR_PIM_EXPORT
extern VAR(uint8, AUTOMATIC) NvMP_Rte_MtrPos_MtrPosSnsr_EOLData[sizeof(Rte_MtrPos_MtrPosSnsr_EOLData)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_CmMtrCurr_ShCurrCal[sizeof(Rte_CmMtrCurr_ShCurrCal)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_HwTrq_HwTrqScaleData[sizeof(Rte_HwTrq_HwTrqScaleData)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_HwTrq_HwTrqTrimData[sizeof(Rte_HwTrq_HwTrqTrimData)+D_CRC16SIZE_CNT_U16];

extern VAR(uint8, AUTOMATIC) NvMP_Rte_HwTrq_EOLTrqStepData[sizeof(Rte_HwTrq_EOLTrqStepData)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_CurrParamComp_EOLNomMtrParam[sizeof(Rte_CurrParamComp_EOLNomMtrParam)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32[sizeof(Rte_TrqCmdScl_TorqueCmdSF_Uls_f32)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Polarity_Polarity_Cnt_Str[sizeof(Rte_Polarity_Polarity_Cnt_Str)];


extern VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_TrqCanc_CogTrqCal[sizeof(Rte_Ap_TrqCanc_CogTrqCal)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_BatteryVoltage_OvervoltageData[sizeof(Rte_BatteryVoltage_OvervoltageData)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_TrqCanc_CogTrqRplComp[sizeof(Rte_Ap_TrqCanc_CogTrqRplComp)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_AstLmt_SteerAsstDefeat[sizeof(Rte_Ap_AstLmt_SteerAsstDefeat)];
#endif

#endif
