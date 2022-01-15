/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : EPS_DiagSrvcs_CommonFunc.h file
* Module Description: Common Manufacturing Program Interface for XCP and ISO services
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*
* Notes:
* This file contains configurations that are shared between ISO and XCP services.
*
*****************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          EA3#6.1.8.1.8 %
 * %derived_by:       gz324f %
 * %date_modified:    Thu Feb 27 15:49:40 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 01/08/12 	1		BG		Initial Version
 * 07/31/12 	2		BG		Initial Version
 * 08/09/12 	3		SAH		Updates to work with CMS
 * 08/21/12		4		SAH		Added App and Cal version check for boot transition to app.
 * 10/05/12		5		SAH		Added software version for DID F150.
 * 10/05/12		6.1.3	SAH		Changed software version from var to const
 * 05/24/13		6.1.4	SAH		NVM updates for MtrPos Component integration
 * 06/10/13     6.1.6   M. Story Updated T_SwModuleInfo_Cnt_u8.
 * 06/10/13     6.1.7   SAH		Added WIR select and NomMtrPos deprecated function
 * 06/19/13     6.1.8   SAH		Changed T_SwModuleInfo_Cnt_u8
 * 08/29/13     6.1.9   SAH		Added Bootloader required NVM blocks
 * 10/25/13   6.1.9.1.1 SAH		Fee memory init block updates
 * 10/28/13   6.1.9.1.2 SAH		Updated size of Nvm_DiagStds_Cnt_u8 
 * 01/15/14   6.1.8.1.5 SAH		Updated address offset for software fingerprint 
 * 02/14/14   6.1.8.1.6 SAH		Updated NvM mapping for safety specifications
 * 02/28/14   6.1.8.1.7 SAH		Added extern for Nvm_EcuPn_Cnt_u8
 * 08/12/16   6.1.8.1.8 SV		Updated for EEPROM to FEE change 
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include area >>		                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Rte_Type.h"
#include "GlobalMacro.h"
#include "NvM.h"
#include "CDD_Data.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include area >>   		      		    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#ifndef RTE_AP_DFLTCONFIGDATA_H
#define RTE_AP_DFLTCONFIGDATA_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom define area >>   		  	    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom define area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* RAM references */
extern VAR(MtrPosCal_DataType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_MtrPos_MtrPosSnsr_EOLData;
extern VAR(HwTrqScale_Datatype, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_HwTrq_HwTrqScaleData;
extern VAR(HwTrqTrim_Datatype, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_HwTrq_HwTrqTrimData;
extern VAR(uint16, CDD_VAR_NOINIT) CDD_EOLNxtrWIRSelect_Cnt_G_u16;
extern VAR(EOLNomMtrParamType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_CurrParamComp_EOLNomMtrParam;
extern VAR(Float, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_TrqCmdScl_TorqueCmdSF_Uls_f32;
extern VAR(uint8, EPSDIAGSRVCS_VAR) NxtrMEC_Cnt_G_u8;
extern VAR(uint8, CDD_PARTNUMBER) Nvm_VIN_Cnt_u8[17];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_MtrPos_MtrPosSnsr_EOLData[sizeof(Rte_MtrPos_MtrPosSnsr_EOLData)];
extern VAR(EOLTrqStepType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_HwTrq_EOLTrqStepData;

/* SER Defined NvM Data */
extern CONST(uint8, NVM_APPL_DATA) T_BlocksizeSTMinParam_Cnt_u8[2];
extern VAR(uint8, NVM_APPL_DATA) T_SwModuleInfo_Cnt_u8[20];
extern VAR(uint8, NVM_APPL_DATA) T_A001InternalBusSig_Cnt_u8[38];
extern VAR(uint8, NVM_APPL_DATA) T_A002InternalBusSig_Cnt_u8[16];
extern VAR(uint8, NVM_APPL_DATA) T_A003InternalBusSig_Cnt_u8[6];
extern VAR(uint8, NVM_APPL_DATA) T_A004InternalBusSig_Cnt_u8[7];
extern CONST(uint8, NVM_APPL_DATA) T_CalVersionCheck_Cnt_u8[2];
extern CONST(uint8, NVM_APPL_DATA) T_AppVersionCheck_Cnt_u8[2];
extern CONST(uint8, NVM_APPL_DATA) T_SwVer_Cnt_u8[3];

extern VAR(uint8, NVM_APPL_DATA) Nvm_ResponseOnEventActv_Cnt_u8[2];
extern VAR(uint8, NVM_APPL_DATA) Nvm_VINOdometer_Cnt_u8[2];
extern VAR(uint8, NVM_APPL_DATA) Nvm_DiagSpecInfo_Cnt_u8[4];
extern VAR(uint8, NVM_APPL_DATA) Nvm_VehicleInfo_Cnt_u8[4];
extern VAR(uint8, NVM_APPL_DATA) Nvm_ECUSerialNumber_Cnt_u8[12];
extern VAR(uint8, NVM_APPL_DATA) Nvm_VINCurrent_Cnt_u8[17];
extern VAR(uint8, NVM_APPL_DATA) Nvm_VINOriginal_Cnt_u8[17];
extern VAR(uint8, NVM_APPL_DATA) Nvm_ActiveDiagInfoBoot_Cnt_u8[15];
extern VAR(uint8, NVM_APPL_DATA) Nvm_ActiveDiagInfoAppl_Cnt_u8[4];
extern VAR(uint8, NVM_APPL_DATA) Nvm_HwPartNumber_Cnt_u8[10];
extern VAR(uint8, NVM_APPL_DATA) Nvm_HwVersionInfo_Cnt_u8[3];
extern VAR(uint8, NVM_APPL_DATA) Nvm_BootSwVersionInfo_Cnt_u8[3];
extern VAR(uint8, NVM_APPL_DATA) Nvm_HwSupplierID_Cnt_u8[2];
extern VAR(uint8, NVM_APPL_DATA) Nvm_MetadataAppl_Cnt_u8[32];
extern VAR(uint8, NVM_APPL_DATA) Nvm_MetadataCal1_Cnt_u8[32];
extern VAR(uint8, NVM_APPL_DATA) Nvm_MetadataCal2_Cnt_u8[32];
extern VAR(uint8, NVM_APPL_DATA) Nvm_WirSelect_Cnt_u8[2];
extern VAR(uint8, NVM_APPL_DATA) Nvm_SWFingerprint_Cnt_u32;
extern VAR(uint8, NVM_APPL_DATA) Nvm_DiagStds_Cnt_u8[4];
extern VAR(uint8, NVM_APPL_DATA) Nvm_ParityStart_Cnt_u8;
extern VAR(uint8, NVM_APPL_DATA) Nvm_ProgReqCnt_Cnt_u8;
extern VAR(uint8, NVM_APPL_DATA) Nvm_ResetResp_Cnt_u8;
extern VAR(uint8, NVM_APPL_DATA) Nvm_SecDlyEn_Cnt_u8;
extern VAR(uint8, NVM_APPL_DATA) Nvm_BlkValFlg_Cnt_u8;
extern VAR(uint16, NVM_APPL_DATA) LatchCounters_Cnt_u16;
extern VAR(uint8, NVM_APPL_DATA) Nvm_EcuPn_Cnt_u8[10];

extern VAR(uint8, CDD_PARTNUMBER) Nvm_NMEC_Cnt_u8;
extern VAR(uint8, CDD_PARTNUMBER) Nvm_EcuSrlNum_Cnt_u8[4];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_EpsSrlNum_Cnt_u8[4];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_EcuHwPn_Cnt_u8[12];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_NxtrManfScrpd_Cnt_u8[64];
extern VAR(uint16, CDD_PARTNUMBER) Nvm_IgnCntr_Cnt_u16;

extern CONST(uint8, CDD_PARTNUMBER) k_SWRelNum_Cnt_u8[50];

extern VAR(boolean, AUTOMATIC) DPMShutDownState_Cnt_lgc;

extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_Init1(void);



#define kEepFblBaseAddress                ((uint8)0x00000000)

/* Defines for NvM Metadata block */
#define kEepSizeFingerprint                   0x0Au
#define kEepSizeProgAttempts              	  0x02u
#define kEepSizeCRC                       	  0x04u
#define kApplInfoSizeSwVersion                0x03u
#define kApplInfoSizeSwPartNumber             0x0Au
#define kApplInfoSizeSwSupplierInformation    0x02u


/* Address offsets within NvM Metadata block */
#define kEepAddressFingerprint           (kEepFblBaseAddress)
#define kEepAddressProgAttempts          (kEepAddressFingerprint+kEepSizeFingerprint)
#define kEepAddressCRC                   (kEepAddressProgAttempts+kEepSizeProgAttempts)
#define kEepAddressSwVersion             (kEepAddressCRC+kEepSizeCRC)
#define kEepAddressSwSupplierInformation (kEepAddressSwVersion+kApplInfoSizeSwVersion+kApplInfoSizeSwPartNumber)













#endif /* RTE_AP_DFLTCONFIGDATA_H */
