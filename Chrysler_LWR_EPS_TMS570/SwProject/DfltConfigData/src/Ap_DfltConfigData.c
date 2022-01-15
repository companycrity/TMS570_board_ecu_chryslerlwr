/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Ap_DfltConfigData.c
* Module Description:
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*
*
*****************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          EA3#26.1.20.1.26 %
 * %derived_by:       gz324f %
 * %date_modified:    Thu Mar  6 15:11:08 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/08/12 	1		BG		Initial Version
 * 07/31/12 	2		BG		Initial Version
 * 08/09/12 	3		SAH		Updates for CMS integration
 * 08/16/12		4		SAH		Part number update initial release
 * 08/17/12		5		SAH		Part number update
 * 08/21/12		6		SAH		Part number update.  Added App and Cal version check for boot transition to app.
 * 08/31/12		7		SAH		Part number update
 * 09/13/12		8		SAH		Part number update (01.00.04)
 * 09/18/12		9		SAH		Part number update (01.00.05)
 * 09/24/12		10		OT		Part number update (01.00.06)
 * 09/27/12		11		OT		Part number update (01.00.07)
 * 10/05/12		12		SAH		Part number update (01.00.08) and added T_SwVer_Cnt_u8 for DID F150(will need to be updated each build)!
 * 10/05/12		13		SAH		Changed software version from var to const
 * 10/10/12		14		SAH		Part number updates
 * 11/28/12		15		SAH		Removed EOL return range init.
 * 12/05/12		16		SAH		Part number update (02PRELIM)
 * 01/05/13		17		SAH		Part number update (02.00.01)
 * 01/11/13		18		BWL		Removed incorrect pointer
 * 01/15/13		19		SAH		Part number update (02.00.02), added Cal2versioncheck constant
 * 01/25/13		20		BWL		Updated Calibration version check for new memory map.
 * 01/28/13		21		SAH		Part number update (02.00.03), cal and build number updates
 * 01/29/13		22		SAH		Part number update (02.00.04)
 * 02/15/13		23		SAH		Part number update (02.00.05)
 * 02/15/13		24		SAH		Part number update (02.00.06)
 * 02/28/13		26.1.1	SAH		Part number update for ePWM path(02.01.00)
 * 03/04/13		26.1.2	SAH		Part number update for ePWM path(02.01.01)
 * 03/12/13		26.1.3	SAH		Part number update for ePWM path(02.01.02)
 * 04/05/13     26.1.4  M. Story Part number update for ePWM path(02.01.03)
 * 01/14/13     26.1.5  m. Story ECU Partnumber default.
 * 04/15/13     26.1.6  M. Story Part number update for ePWM path(02.01.04)
 * 04/18/13     26.1.7  M. Story Part number update for ePWM path(02.01.05)
 * 05/01/13		26.1.8	SAH		Part number update for 3.0SW release(03.00.00)
 * 05/20/13		26.1.9	SAH		Part number update for 3.0SW release(03.00.01)
 * 05/24/13		26.1.10	SAH		Added deprecated EOL MtrPos data func.
 * 06/03/13		26.1.11 SAH		Part number update for 3.0SW release(03.00.02) and cleanup
 * 06/10/13     26.1.12 M. Story Updated T_SwModuleInfo_Cnt_u8.
 * 06/18/13		26.1.13 SAH		Added NomMtrParam deprecated block and init values
 * 06/19/13		26.1.14 SAH		Part number update for 3.0SW release(03.00.03) and cleanup
 * 07/10/13		26.1.15 JJW		Change default init to refreference the NvM Proxy buffers instead of the secured
 *                              memory locations.  
 *                              moved T_SwModuleInfo_Cnt_u8 and T_A001InternalBusSig_Cnt_u8 to .ossDataAp_9
 * 07/10/13		26.1.16 SAH		Change default init to reference the NvM Proxy buffers instead of the secured locations
 *								Part number update for 3.0SW release(03.00.04)
 * 07/20/13		26.1.17	SAH		Part number update for 3.0SW release(03.00.05)
 * 07/27/13		26.1.18	SAH		Part number update for 3.0SW release(03.00.06)
 * 08/01/13		26.1.19	SAH		Part number update for 3.0SW release(03.00.07)
 * 08/07/13		26.1.20	SAH		Part number update for 3.0SW release(03.00.08)
 * 09/12/13	26.1.20.1.1	SAH		Part number update for WR SW release(01.00.00) and valid patterns
 * 09/13/13 26.1.20.1.2 M. Story Anomaly 4749, 4699, 4701, 4700
 * 09/30/13	26.1.20.1.3	SAH		Part number update for L SW release(01.00.01)
 * 10/07/13	26.1.20.1.4	SAH		Part number update for L SW release(01.00.02)
 * 10/15/13	26.1.20.1.5	SAH		Part number update for L SW release(01.00.03)
 * 10/21/13	26.1.20.1.6	SAH		Part number update for L SW release(01.00.04)
 * 11/18/13 26.1.20.1.7 M. Story ECUSerial Number default change
 * 11/20/13 26.1.20.1.8 M. Story NM change added DPMShutDownState_Cnt_lgc
 * 12/05/13	26.1.20.1.9	SAH		Part number update for L SW release(02.00.00), initialize VIN if not programmed
 * 12/18/13	26.1.20.1.12	SAH		Part number update for L SW release(02.00.01)
 * 01/08/14	26.1.20.1.13	SAH		Part number update for L SW release(02.00.02)
 * 01/18/14	26.1.20.1.14	SAH		Part number update for L SW release(02.00.03), initialize VIN org if not programmed
 * 01/22/14	26.1.20.1.15	SAH		Part number update for L SW release(02.00.04)
 * 01/30/14	26.1.20.1.16	SAH		Changed polarity to 8 bit value and added logic to zero out fingerprint if EEPROM is unprogrammed
 * 02/14/14	26.1.20.1.17	SAH		Rearranged NvM for safety.  Updated part numbers(03.00.00).  Added Boot compatibility
 * 02/28/14	26.1.20.1.18	SAH		Updated part numbers(03.00.01).
 * 03/07/14	26.1.20.1.19	SAH		Updated part numbers(03.00.02).
 * 03/17/14	26.1.20.1.20	SAH		Updated part numbers(03.00.03).
 * 05/01/14	26.1.20.1.21	SAH		Fix for DID F151 storage and updated part numbers(04.00.00).
 * 05/15/14	26.1.20.1.22	SAH		Updated part numbers(04.00.01).
 * 05/20/14	26.1.20.1.23	SAH		Updated part numbers(04.00.02).
 * 08/29/14	26.1.20.1.24	SAH		Updated part numbers(05.00.00).
 * 09/08/14	26.1.20.1.25	SAH		Updated part numbers(05.00.01).
 * 08/12/16 26.1.20.1.26    SV		Updated part numbers(05.01.00) for Archer migration with FEE
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_DfltConfigData.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"
#include "sip_vers.h"
#include "n_onmdef.h"
#include "Cd_NvMProxy.h"

/* Select the release suffix based on the build type*/
#if	defined(ENABLE_UTILIZATION_MONITOR)
	#define D_SUFFIX    "_U"
#elif defined(ENABLE_CPUUSE_METRICS)
	#define D_SUFFIX    "_T"
#elif defined(ENABLE_METRICS)
	#define D_SUFFIX    "_O"
#elif defined(SWEEPBUILD)
	#define D_SUFFIX    "_SWP1"
#else
	#define D_SUFFIX
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*Current Sw Release Number(from CM Synergy)*/

/* Multiple strings separated by a space are combined at compile time.  So the result of the expression is a single string */
#pragma DATA_SECTION(k_SWRelNum_Cnt_u8,".FixedAdd_NxtrSWPN");
CONST(uint8, CDD_PARTNUMBER) k_SWRelNum_Cnt_u8[] = "CL_05.01.00" D_SUFFIX;

#pragma DATA_SECTION(T_CalVersionCheck_Cnt_u8,".FixedAdd_CalVersionCheck");
CONST(uint8, CDD_PARTNUMBER) T_CalVersionCheck_Cnt_u8[2] = {0x03,0x01};

#pragma DATA_SECTION(T_AppVersionCheck_Cnt_u8,".FixedAdd_AppVersionCheck");
CONST(uint8, CDD_PARTNUMBER) T_AppVersionCheck_Cnt_u8[2] = {0x03,0x01};

#pragma DATA_SECTION(T_SwVer_Cnt_u8,".FixedAdd_SwVer");
CONST(uint8, CDD_PARTNUMBER) T_SwVer_Cnt_u8[3] = {0x10,0x32,0x00};  /* Software build date - 0x0x(x = year), 0xyy(yy = week), 0x0z(z =  no of revisions) */

#pragma DATA_SECTION(T_AppValid_Cnt_u8,".FixedAdd_AppValidPattern");
CONST(uint8, CDD_PARTNUMBER) T_AppValid_Cnt_u8[8] = {0x5A,0xF0,0xA5,0x0F,0x11,0x22,0x33,0x44};

#pragma DATA_SECTION(T_CalValid_Cnt_u8,".FixedAdd_CalValidPattern");
CONST(uint8, CDD_PARTNUMBER) T_CalValid_Cnt_u8[8] = {0x5A,0xF0,0xA5,0x0F,0x11,0x22,0x33,0x44};

#pragma DATA_SECTION(T_BootApplValidChk_Cnt_u8,".FixedAdd_BootApplValidChk");
CONST(uint8, CDD_PARTNUMBER) T_BootApplValidChk_Cnt_u8[2] = {0x00,0x02};


/* SER Defined NvM Data */
VAR(uint8, NVM_APPL_DATA) Nvm_ResponseOnEventActv_Cnt_u8[2];
VAR(uint8, NVM_APPL_DATA) Nvm_VINOdometer_Cnt_u8[2];/* SrlCom write Service application */
VAR(uint8, NVM_APPL_DATA) Nvm_DiagSpecInfo_Cnt_u8[4];/* Boot Writes */
VAR(uint8, NVM_APPL_DATA) Nvm_VehicleInfo_Cnt_u8[4];/* SrlCom write Service application */
VAR(uint8, NVM_APPL_DATA) Nvm_ECUSerialNumber_Cnt_u8[12];/* Did write Service application */
VAR(uint8, NVM_APPL_DATA) Nvm_VINCurrent_Cnt_u8[17];/* SrlCom write Service application */
VAR(uint8, NVM_APPL_DATA) Nvm_VINOriginal_Cnt_u8[17];/* SrlCom write Service application */
VAR(uint8, NVM_APPL_DATA) Nvm_ActiveDiagInfoBoot_Cnt_u8[15]; /* Boot Writes */
VAR(uint8, NVM_APPL_DATA) Nvm_ActiveDiagInfoAppl_Cnt_u8[4];
VAR(uint8, NVM_APPL_DATA) Nvm_HwPartNumber_Cnt_u8[10]; /* Did write Service application */
VAR(uint8, NVM_APPL_DATA) Nvm_HwVersionInfo_Cnt_u8[3]; /* Did write Service application */
VAR(uint8, NVM_APPL_DATA) Nvm_BootSwVersionInfo_Cnt_u8[3]; /* Boot Writes */
VAR(uint8, NVM_APPL_DATA) Nvm_HwSupplierID_Cnt_u8[2];/* Boot Writes */
VAR(uint8, NVM_APPL_DATA) Nvm_MetadataAppl_Cnt_u8[32]; /* Boot Writes */
VAR(uint8, NVM_APPL_DATA) Nvm_MetadataCal1_Cnt_u8[32]; /* Boot Writes */
VAR(uint8, NVM_APPL_DATA) Nvm_MetadataCal2_Cnt_u8[32]; /* Boot Writes */
VAR(uint8, NVM_APPL_DATA) Nvm_SWFingerprint_Cnt_u32;
VAR(uint8, NVM_APPL_DATA) Nvm_ProgReqCnt_Cnt_u8;
VAR(uint8, NVM_APPL_DATA) Nvm_ResetResp_Cnt_u8;
VAR(uint8, NVM_APPL_DATA) Nvm_SecDlyEn_Cnt_u8;
VAR(uint8, NVM_APPL_DATA) Nvm_WirSelect_Cnt_u8[2];
VAR(boolean, NVM_APPL_DATA) DPMShutDownState_Cnt_lgc;
VAR(uint8, NVM_APPL_DATA) Nvm_EcuPn_Cnt_u8[10];

/* Initial Data */

static CONST(uint8, CDD_PARTNUMBER) T_InitNMEC_Cnt_u8 = 0xFEU;

static CONST(uint8, CDD_PARTNUMBER) T_InitECUHwPn_Cnt_u8[12] = {'2', '8', '6', '4', '8', '8', '3', '1', '-', '0', '0', '7'};

#pragma DATA_SECTION(T_BlocksizeSTMinParam_Cnt_u8,".FixedAdd_BlocksizeSTMinParam");
CONST(uint8, CDD_PARTNUMBER) T_BlocksizeSTMinParam_Cnt_u8[2] = {0x01,0x02};

#pragma DATA_SECTION(T_SwModuleInfo_Cnt_u8,".ossDataAp_9:noinit");
VAR (uint8, CDD_PARTNUMBER) T_SwModuleInfo_Cnt_u8[20];

#pragma DATA_SECTION(T_A001InternalBusSig_Cnt_u8,".ossDataAp_9:noinit");
VAR(uint8, CDD_PARTNUMBER) T_A001InternalBusSig_Cnt_u8[38] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

#pragma DATA_SECTION(T_A002InternalBusSig_Cnt_u8,".ossDataAp_9:noinit");
VAR(uint8, CDD_PARTNUMBER) T_A002InternalBusSig_Cnt_u8[16] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

#pragma DATA_SECTION(T_A003InternalBusSig_Cnt_u8,".ossDataAp_9:noinit");
VAR(uint8, CDD_PARTNUMBER) T_A003InternalBusSig_Cnt_u8[6] = {0x00,0x00,0x00,0x00,0x00,0x00};

#pragma DATA_SECTION(T_A004InternalBusSig_Cnt_u8,".ossDataAp_9:noinit");
VAR(uint8, CDD_PARTNUMBER) T_A004InternalBusSig_Cnt_u8[7] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00};

static CONST(uint8, CDD_PARTNUMBER) T_ProgAttempts_Cnt_u8[2] = {0xFF, 0xFF};

static CONST(uint8, CDD_PARTNUMBER) T_InitVINData[17] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

/* Processing Functions */
FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_Init1(void)
{
	VAR(NvM_RequestResultType, AUTOMATIC) BlockStatus = 0;
	VAR(uint8, AUTOMATIC) i;
	VAR(boolean, AUTOMATIC) ECUSerialNumberSet_cnt_lgc = FALSE;

	T_SwModuleInfo_Cnt_u8[0] = kCanNumberOfChannels;
	T_SwModuleInfo_Cnt_u8[1] = 0x1Eu;
	T_SwModuleInfo_Cnt_u8[2] = kSipMainVersion;
	T_SwModuleInfo_Cnt_u8[3] = kSipSubVersion;
	T_SwModuleInfo_Cnt_u8[4] = kSipBugFixVersion;
	T_SwModuleInfo_Cnt_u8[5] = kDBCMainVersion;
	T_SwModuleInfo_Cnt_u8[6] = kDBCSubVersion;
	T_SwModuleInfo_Cnt_u8[7] = kDBCReleaseVersion;
	T_SwModuleInfo_Cnt_u8[8] = kCanMainVersion;
	T_SwModuleInfo_Cnt_u8[9] = kCanSubVersion;
	T_SwModuleInfo_Cnt_u8[10] = kCanBugFixVersion;
	T_SwModuleInfo_Cnt_u8[11] = kNmMainVersion;
	T_SwModuleInfo_Cnt_u8[12] = kNmSubVersion;
	T_SwModuleInfo_Cnt_u8[13] = kNmBugfixVersion;
	T_SwModuleInfo_Cnt_u8[14] = g_descMainVersion;
	T_SwModuleInfo_Cnt_u8[15] = g_descSubVersion;
	T_SwModuleInfo_Cnt_u8[16] = g_descBugFixVersion;
	T_SwModuleInfo_Cnt_u8[17] = kTpMainVersion;
	T_SwModuleInfo_Cnt_u8[18] = kTpSubVersion;
	T_SwModuleInfo_Cnt_u8[19] = kTpBugFixVersion;


	/* Nexteer MEC */
	NvM_GetErrorStatus(NVM_BLOCK_CMS_NXTRMEC, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		Nvm_NMEC_Cnt_u8 = T_InitNMEC_Cnt_u8;
	}

	EPS_DiagSrvcs_Init();


	/* The following sections are for blocks that do not require MEC checks */

	/* VIN Data */
	NvM_GetErrorStatus(NVM_BLOCK_SER_VINCURRENT, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i=0; i<TableSize_m(Nvm_VINCurrent_Cnt_u8); i++)
		{
			Nvm_VINCurrent_Cnt_u8[i] = T_InitVINData[i];
		}
	}

	NvM_GetErrorStatus(NVM_BLOCK_SER_VINORIGINAL, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i=0; i<TableSize_m(Nvm_VINOriginal_Cnt_u8); i++)
		{
			Nvm_VINOriginal_Cnt_u8[i] = T_InitVINData[i];
		}
	}

	/* ECU Hardware Part Number */
	NvM_GetErrorStatus(NVM_BLOCK_SER_ECUPN, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i=0; i<TableSize_m(Nvm_EcuPn_Cnt_u8); i++)
		{
			Nvm_EcuPn_Cnt_u8[i] = T_InitECUHwPn_Cnt_u8[i];
			NvM_SetRamBlockStatus(NVM_BLOCK_SER_ECUPN, TRUE);
		}
	}

	/* F15B software fingerprint at init appl */
	NvM_GetErrorStatus(NVM_BLOCK_SER_METADATA_APPLICATION, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i=0; i<kEepSizeFingerprint; i++)
		{
			Nvm_MetadataAppl_Cnt_u8[i] = 0x00u;
		}
		 Nvm_MetadataAppl_Cnt_u8[10] = T_ProgAttempts_Cnt_u8[0]; /* Programming attempts counter after the part has been programmed through Jtag.  Need to set the Counter to FFFF for bootloader*/
		 Nvm_MetadataAppl_Cnt_u8[11] = T_ProgAttempts_Cnt_u8[1];
		NvM_SetRamBlockStatus(NVM_BLOCK_SER_METADATA_APPLICATION, TRUE);
	}

	/* F15B software fingerprint at init cal1 */
	NvM_GetErrorStatus(NVM_BLOCK_SER_METADATA_CAL1, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i=0; i<kEepSizeFingerprint; i++)
		{
			Nvm_MetadataCal1_Cnt_u8[i] = 0x00u;
		}
		Nvm_MetadataCal1_Cnt_u8[10] = T_ProgAttempts_Cnt_u8[0]; /* Programming attempts counter after the part has been programmed through Jtag.  Need to set the Counter to FFFF for bootloader*/
		Nvm_MetadataCal1_Cnt_u8[11] = T_ProgAttempts_Cnt_u8[1];
		NvM_SetRamBlockStatus(NVM_BLOCK_SER_METADATA_CAL1, TRUE);
	}

	/* F15B software fingerprint at init cal2 */
	NvM_GetErrorStatus(NVM_BLOCK_SER_METADATA_CAL2, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i=0; i<kEepSizeFingerprint; i++)
		{
			Nvm_MetadataCal2_Cnt_u8[i] = 0x00u;
		}
		Nvm_MetadataCal2_Cnt_u8[10] = T_ProgAttempts_Cnt_u8[0]; /* Programming attempts counter after the part has been programmed through Jtag.  Need to set the Counter to FFFF for bootloader*/
		Nvm_MetadataCal2_Cnt_u8[11] = T_ProgAttempts_Cnt_u8[1];
		NvM_SetRamBlockStatus(NVM_BLOCK_SER_METADATA_CAL2, TRUE);
	}

	/* F151 Sw version */
	for (i=0; i<TableSize_m(T_SwVer_Cnt_u8); i++)
	{
		if(Nvm_MetadataAppl_Cnt_u8[kEepAddressSwVersion + i] != T_SwVer_Cnt_u8[i])
		{
			Nvm_MetadataAppl_Cnt_u8[kEepAddressSwVersion + i] = T_SwVer_Cnt_u8[i];
			NvM_SetRamBlockStatus(NVM_BLOCK_SER_METADATA_APPLICATION, TRUE);
		}
	}


	for (i=0; i<TableSize_m(t_ECUPartNumber_Cnt_u8); i++)
	{
		if (Nvm_EcuPn_Cnt_u8[i] != t_ECUPartNumber_Cnt_u8[i])
		{
			Nvm_EcuPn_Cnt_u8[i] = t_ECUPartNumber_Cnt_u8[i];
		}
		NvM_SetRamBlockStatus(NVM_BLOCK_SER_ECUPN, TRUE);
	}

    /* Set supplier ID to 0x00 0xD2 */
	if ((Nvm_MetadataAppl_Cnt_u8[kEepAddressSwSupplierInformation] != 0x00) ||
			(Nvm_MetadataAppl_Cnt_u8[kEepAddressSwSupplierInformation + 1] != 0xD2))
	{
		Nvm_MetadataAppl_Cnt_u8[kEepAddressSwSupplierInformation] = 0x00;
		Nvm_MetadataAppl_Cnt_u8[kEepAddressSwSupplierInformation + 1] = 0xD2;
	}
	/* Set supplier ID to 0x00 0xD2 */
	if ((Nvm_MetadataCal1_Cnt_u8[kEepAddressSwSupplierInformation] != 0x00) ||
			(Nvm_MetadataCal1_Cnt_u8[kEepAddressSwSupplierInformation + 1] != 0xD2))
	{
		Nvm_MetadataCal1_Cnt_u8[kEepAddressSwSupplierInformation] = 0x00;
		Nvm_MetadataCal1_Cnt_u8[kEepAddressSwSupplierInformation + 1] = 0xD2;
	}

	for (i=0; i<TableSize_m(Nvm_ECUSerialNumber_Cnt_u8); i++)
	{
		if (Nvm_ECUSerialNumber_Cnt_u8[i] != 0xFF)
		{
			ECUSerialNumberSet_cnt_lgc = TRUE;
		}
	}

	if(ECUSerialNumberSet_cnt_lgc == FALSE)
	{
		Nvm_ECUSerialNumber_Cnt_u8[0] = 0x54;
		Nvm_ECUSerialNumber_Cnt_u8[1] = 0x35;
		Nvm_ECUSerialNumber_Cnt_u8[2] = 0x4d;
	}


}



