/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_CDDInterface.c
 *     Workspace:  C:/CMSynergy_Projects/Ford_S550_P552_EPS_TMS570/SwProject/CDDInterface/autosar
 *     SW-C Type:  Sa_CDDInterface
 *  Generated at:  Wed Apr 18 13:50:16 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_CDDInterface>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Aug 15 20:53:00 2011
 * %version:          18.1.4 %
 * %date_modified:    Thu Feb  6 10:05:53 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 08/15/11  13       LWW       Phase Reasonableness Updates
 * 10/11/11  14       BDO       Add TcReflashActive interface
 * 11/23/11  15       BDO       Add SrlComSvcDft boolean flags based on CDD_EOLSrlComSvcDft_Cnt_G_b32 
 * 12/02/11  16       BDO       Add LimitSrlComSvcDft boolean flags												CR4678
 * 01/06/12  17       LWW       Updates for K2xx implementation 
 * 01/25/12  18       LWW       Update to stub out MEC signal
 * 01/31/12  19       LWW       Updates for digital phase reasonableness 
 * 02/27/12  21	      RR		Update to the constant list
 * 04/17/12  22	      RR		Update for IPM Changes 
 * 04/18/12  23	      LWW		Added support of VehSpdValid signal
 * 08/15/12  3	   	  SAH       (New version for Chrysler)Updates to support MtrElecMech polarity changes due to new polarity component integration
 * 12/10/12  4		  SAH		Added MtrCurrQaxFinalRef as an output for TqRsDg
 * 12/13/12  5		  SAH		Added FricLearning srlcom defeat
 * 02/26/13  7		  SAH		File cleanup
 * 03/20/13  8        M. Story  Anomaly 4464 Implement MEC counter.                                              4464
 * 04/10/13  9        M. Story  Anomaly 4761 Remove VehSpdValid as an output.                                    4761
 * 05/09/13  10		  SAH       Added correctedMtrPos redundant copy
 * 05/09/13  11		  SAH       Updates for SVDiag_Cm integration
 * 05/24/13  12		  SAH       Updates for MtrPos Component integration
 * 09/26/13	13.1.1	  SAH		Added MfgDiagInhibit_Uls_G_lgc as an output from Per4
 * 09/22/13  14       M. Story  Anomaly5582
 * 09/27/13  15       m> Story  Meerge of 13.1.1 and 14
 * 10/11/13  17       SAH		Added CorrMtrCurrposition variable
 * 10/15/13  18       SAH		Updated CorrMtrCurrposition variable, removed corrmtrposelec
 * 11/27/13  19       SAH		Send out MEC value at init.
 * 01/18/14  18.1.2   SAH		Updates for srlcom defeats eng vs production mode.
 * 05/12/14  18.1.3   SAH		Updates for srlcom defeats(allow customer eng on defeat to work in prod mode).
 * 09/08/14  18.1.4   SAH		Fix for DID 0xFDE4 and updates for srlcom defeats(allow customer eng on defeat to work in prod mode).
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Element Prototypes:
 ========================
  Volt_f32 of Port Interface Voltage
    This signal is intended to communicate any type voltage signal measured by the ecu.  This signal has a lower limit of 0 which reequires users of the signal to provide divide by 0 protection if it is used as a denominator in a calculation.  See Vecu port prototype if a port with a lower limit is desired.


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Sa_CDDInterface.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "fixmath.h"
#include "GlobalMacro.h"
#include "CDD_Data.h"
#include "Interrupts.h"
#include "Nhet.h"
#include "CalConstants.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"
#include "RTE_GlobalData.h"


/* TODO: Consider moving all a/d scaling to a single file (IO HwAbs?) */
#define D_ADCVOLTSPERCNT_ULS_F32		5.0F /4095.0F
#define D_WHLIMBSEL_CNT_U16		   		0xA5A2
#define D_PXACCUMMAX_CNT_U32			536870911UL
#define D_PHSADVSCALE_ULS_F32			(6144.0f/65536.0f)
#define D_HALFREV_CNT_U16		   		32768U
#define D_FULLREV_CNT_S32		   		65536L


#define D_PHASEA_CNT_U16  0U    
#define D_PHASEB_CNT_U16  1U
#define D_PHASEC_CNT_U16  2U

#define CDDINTERFACE_START_SEC_VAR_NOINIT_32
#include "MemMap.h"
STATIC VAR(uint32, CDDINTERFACE_VAR_NOINIT) PXAccumPrev_Cnt_M_u32[D_PHASEC_CNT_U16 + 1];
#define CDDINTERFACE_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h"

#define CDDINTERFACE_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
STATIC VAR(sint8, CDDINTERFACE_VAR_NOINIT) PrevMtrElecMechPolarity_Cnt_M_s08;
#define CDDINTERFACE_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define D_SVCDFTENGON_CNT_B32			1U
#define D_SVCDFTFREQDEPDMP_CNT_B32		2U
#define D_SVCDFTKININTDIAG_CNT_B32		4U
#define D_SVCDFTTHERMALDC_CNT_B32		8U
#define D_SVCDFTEOTIMPACT_CNT_B32		16U
#define D_SVCDFTEOTTHERMAL_CNT_B32		32U
#define D_SVCDFTMTRVELNRMLRN_CNT_B32	64U
#define D_SVCDFTMTRPARMNRMLRN_CNT_B32	128U
#define D_SVCDFTTRQRMP_CNT_B32			256U
#define D_SVCDFTMODIDX_CNT_B32			512U
#define D_SVCDFTPULLCOMP_CNT_B32		1024U
#define D_SVCDFTWHLIMBREJ_CNT_B32		2048U
#define D_SVCDFTPARKAST_CNT_B32			4096U
#define D_SVCDFTDRIVINGDYN_CNT_B32		8192U
#define D_SVCDFTHYSTCOMP_CNT_B32		16384U
#define D_SVCDFTHYSTADD_CNT_B32			32768U
#define D_SVCDFTRETURN_CNT_B32			65536U
#define D_SVCDFTDAMPING_CNT_B32			131072U
#define D_SVCDFTLIMIT_CNT_B32			262144U
#define D_SVCDFTFRICLRN_CNT_B32			1048576U
#define D_POSITIVEONE_CNT_S8            1

#define D_MEC_ENGMODE_CNT_U8			0xFFU
#define D_MEC_PRODMODE_CNT_U8			0x00U
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * Double: Real in interval ]-DBL_MAX...DBL_MAX[ with double precision including NaN (standard type)
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * FETFAULTTYPE_ENUM: Enumeration of integer in interval [0...255] with enumerators
 *   NOFAULT (0u)
 *   LOWER (1u)
 *   UPPER (2u)
 * FETPHASETYPE_ENUM: Enumeration of integer in interval [0...255] with enumerators
 *   NOPHASE (0u)
 *   PHASEA (1u)
 *   PHASEB (2u)
 *   PHASEC (3u)
 * ManufModeType: Enumeration of integer in interval [0...2] with enumerators
 *   ProductionMode (0u)
 *   ManufacturingMode (1u)
 *   EngineeringMode (2u)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 * Boolean: D_TRUE_CNT_LGC = TRUE
 * Double: D_SFINVMILLI_ULS_F32 = 1000
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_2PI_ULS_F32 = 6.2831853071796
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199
 * Float: D_PI_ULS_F32 = 3.1415926535898
 * Float: D_VECUMIN_VOLTS_F32 = 5
 * Float: D_ZERO_ULS_F32 = 0
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt32: D_ZERO_CNT_S32 = 0
 * SInt8: D_NEGONE_CNT_S8 = -1
 * SInt8: D_ONE_CNT_S8 = 1
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_ZERO_CNT_U16 = 0u
 * UInt32: D_ZERO_CNT_U32 = 0u
 * UInt8: D_MTRPOLESDIV2_CNT_U8 = 3u
 * UInt8: D_QUADRANT1_CNT_U8 = 1u
 * UInt8: D_QUADRANT2_CNT_U8 = 2u
 * UInt8: D_QUADRANT3_CNT_U8 = 3u
 * UInt8: D_QUADRANT4_CNT_U8 = 4u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_CDDINTERFACE_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_CDDInterface_Init1_Cos1RTAmpRec_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Init1_Cos1RTOffset_Volts_f32(void)
 *   SInt8 Rte_IRead_CDDInterface_Init1_MtrElecMechPolarity_Cnt_s08(void)
 *   Float Rte_IRead_CDDInterface_Init1_Sin1RTAmpRec_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Init1_Sin1RTOffset_Volts_f32(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode

 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface_Init1
 *********************************************************************************************************************/
	VAR(sint8, AUTOMATIC) MtrElecMechPolarity_Cnt_T_s08;
	
	MtrElecMechPolarity_Cnt_T_s08 = Rte_IRead_CDDInterface_Init1_MtrElecMechPolarity_Cnt_s08();
	
	CDD_AppDataFwdPthAccessBfr_Cnt_G_u16 = 0U;
	CDD_AppDataFbkPthAccessBfr_Cnt_G_u16 = 0U;
	CDD_CDDDataAccessBfr_Cnt_G_u16 = 0U;
	PXAccumPrev_Cnt_M_u32[D_PHASEA_CNT_U16] = HET_P1ACC_1.memory.data_word >>3U;
	PXAccumPrev_Cnt_M_u32[D_PHASEB_CNT_U16] = HET_P2ACC_1.memory.data_word >>3U;
	PXAccumPrev_Cnt_M_u32[D_PHASEC_CNT_U16] = HET_P3ACC_1.memory.data_word >>3U;

	Rte_Call_CDDPorts_ApplyMtrElecMechPol(MtrElecMechPolarity_Cnt_T_s08);
	PrevMtrElecMechPolarity_Cnt_M_s08 = MtrElecMechPolarity_Cnt_T_s08;
	
	Rte_IWrite_CDDInterface_Init1_MEC_Cnt_enum(NxtrMEC_Uls_G_enum);

	Rte_IWrite_CDDInterface_Init1_IgnCnt_Cnt_u16(Nvm_IgnCntr_Cnt_u16);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Init2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Init2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface_Init2
 *********************************************************************************************************************/
	
	EnableMtrCtlInterrupt();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface_Per1_ADCMtrCurr1_Volts_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_ADCMtrCurr1_Volts_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_ADCMtrCurr2_Volts_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_ADCMtrCurr2_Volts_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_CorrMtrPosElec_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_CorrMtrPosElec_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_Cos1Theta_Volts_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_Cos1Theta_Volts_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeA_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeA_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeB_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeB_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeC_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeC_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MeasuredOnTimeA_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_MeasuredOnTimeA_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MeasuredOnTimeB_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_MeasuredOnTimeB_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MeasuredOnTimeC_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_MeasuredOnTimeC_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_ModIdxFinal_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_ModIdxFinal_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrCurrDaxRef_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrCurrDaxRef_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrCurrDax_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrCurrDax_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrCurrK1_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrCurrK1_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrCurrK2_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrCurrK2_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrCurrQaxFinalRef_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrCurrQaxFinalRef_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrCurrQax_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrCurrQax_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrPosElec_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrPosElec_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrPosMech_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrPosMech_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrRevCntr_Cnt_s16(SInt16 data)
 *   SInt16 *Rte_IWriteRef_CDDInterface_Per1_MtrRevCntr_Cnt_s16(void)
 *   void Rte_IWrite_CDDInterface_Per1_Sin1Theta_Volts_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_Sin1Theta_Volts_f32(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface_Per1
 *********************************************************************************************************************/
	VAR(uint16,  AUTOMATIC) ReadBuffer_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) WriteBuffer_Cnt_T_u16;
	VAR(float32, AUTOMATIC) MtrCurrQax_Amp_T_f32;
	VAR(float32, AUTOMATIC) MtrCurrDax_Amp_T_f32;
	VAR(float32, AUTOMATIC) MtrCurrK1_Amps_T_f32;
	VAR(float32, AUTOMATIC) MtrCurrK2_Amps_T_f32;
	VAR(float32, AUTOMATIC) ModIdx_Uls_T_f32;
	VAR(uint16,  AUTOMATIC) PhaseAdvFinal_Cnt_T_u16;
	VAR(float32, AUTOMATIC) MtrCurrQaxFinalRef_Amp_T_f32;
	VAR(float32, AUTOMATIC) MtrCurrDaxRef_Amp_T_f32;
	VAR(float32, AUTOMATIC) MtrCurr1_Volts_T_f32;
	VAR(float32, AUTOMATIC) MtrCurr2_Volts_T_f32;
	VAR(float32, AUTOMATIC) MtrVoltDax_Volt_T_f32;
	VAR(float32, AUTOMATIC) MtrVoltQax_Volt_T_f32;
	
	VAR(uint32,  AUTOMATIC) ExpectedOnTimeA_Cnt_T_u32;
	VAR(uint32,  AUTOMATIC) ExpectedOnTimeB_Cnt_T_u32;
	VAR(uint32,  AUTOMATIC) ExpectedOnTimeC_Cnt_T_u32;
	VAR(uint32,  AUTOMATIC) MeasuredOnTime_Cnt_T_u32[D_PHASEC_CNT_U16 + 1U];
	VAR(uint32,  AUTOMATIC) PXAccum_Cnt_T_u32[D_PHASEC_CNT_U16 + 1U];
	VAR(uint16, AUTOMATIC) i;
	VAR(sint16,  AUTOMATIC) PhaseAdvFinal_Cnt_T_s16;
	VAR(float32, AUTOMATIC) CorrMtrCurrPosition_Rev_T_f32;


	ReadBuffer_Cnt_T_u16 = CDD_CDDDataAccessBfr_Cnt_G_u16;
	WriteBuffer_Cnt_T_u16 = (ReadBuffer_Cnt_T_u16 & 1U) ^ 1U;
	CDDPorts_ClearPhsReasSum(WriteBuffer_Cnt_T_u16);
	CDD_CDDDataAccessBfr_Cnt_G_u16 = WriteBuffer_Cnt_T_u16;
	
	/* These NHET2 memory reads are performed immediately after the buffer swap for greatest possible synchronization */
	PXAccum_Cnt_T_u32[D_PHASEA_CNT_U16] = HET_P1ACC_1.memory.data_word >>3U;
	PXAccum_Cnt_T_u32[D_PHASEB_CNT_U16] = HET_P2ACC_1.memory.data_word >>3U;
	PXAccum_Cnt_T_u32[D_PHASEC_CNT_U16] = HET_P3ACC_1.memory.data_word >>3U;
	
	
	MtrCurrQax_Amp_T_f32 = CDD_MtrCurrQax_Amp_G_f32[ReadBuffer_Cnt_T_u16];
	MtrCurrDax_Amp_T_f32 = CDD_MtrCurrDax_Amp_G_f32[ReadBuffer_Cnt_T_u16];
	MtrCurr1_Volts_T_f32 = CDD_MtrCurr1_Volts_G_f32[ReadBuffer_Cnt_T_u16];
	MtrCurr2_Volts_T_f32 = CDD_MtrCurr2_Volts_G_f32[ReadBuffer_Cnt_T_u16];
	ModIdx_Uls_T_f32 = FPM_FixedToFloat_m((CDD_ModIdxFinal_Uls_G_u16p16[ReadBuffer_Cnt_T_u16]), u16p16_T);
	PhaseAdvFinal_Cnt_T_u16 = CDD_PhaseAdvFinal_Cnt_G_u16[ReadBuffer_Cnt_T_u16];
	MtrCurrQaxFinalRef_Amp_T_f32 = CDD_MtrCurrQaxFinalRef_Amp_G_f32[ReadBuffer_Cnt_T_u16];
	MtrCurrDaxRef_Amp_T_f32 = CDD_MtrCurrDaxRef_Amp_G_f32[CDD_AppDataFwdPthAccessBfr_Cnt_G_u16];
	CorrMtrCurrPosition_Rev_T_f32 = CDD_CorrMtrCurrPosition_Rev_G_f32[ReadBuffer_Cnt_T_u16];
	MtrCurrK1_Amps_T_f32 = CDD_MtrCurrK1_Amps_G_f32[ReadBuffer_Cnt_T_u16];
	MtrCurrK2_Amps_T_f32 = CDD_MtrCurrK2_Amps_G_f32[ReadBuffer_Cnt_T_u16];
	ExpectedOnTimeA_Cnt_T_u32 = CDD_PWMDutyCycleASum_Cnt_G_u32[ReadBuffer_Cnt_T_u16];
	ExpectedOnTimeB_Cnt_T_u32 = CDD_PWMDutyCycleBSum_Cnt_G_u32[ReadBuffer_Cnt_T_u16];
	ExpectedOnTimeC_Cnt_T_u32 = CDD_PWMDutyCycleCSum_Cnt_G_u32[ReadBuffer_Cnt_T_u16];
	MtrVoltDax_Volt_T_f32 = CDD_MtrVoltDax_Volt_G_f32[ReadBuffer_Cnt_T_u16];
	MtrVoltQax_Volt_T_f32 = CDD_MtrVoltQax_Volt_G_f32[ReadBuffer_Cnt_T_u16];
	
	for(i = D_PHASEA_CNT_U16; i <= D_PHASEC_CNT_U16; i++)
	{
		if(PXAccum_Cnt_T_u32[i] < PXAccumPrev_Cnt_M_u32[i])
		{
			MeasuredOnTime_Cnt_T_u32[i] = (D_PXACCUMMAX_CNT_U32 - PXAccumPrev_Cnt_M_u32[i]) + PXAccum_Cnt_T_u32[i] + 1;
		}
		else
		{
			MeasuredOnTime_Cnt_T_u32[i] = PXAccum_Cnt_T_u32[i] - PXAccumPrev_Cnt_M_u32[i];
		}
		
		PXAccumPrev_Cnt_M_u32[i] = PXAccum_Cnt_T_u32[i];
	}
	
	if( PhaseAdvFinal_Cnt_T_u16 >= D_HALFREV_CNT_U16 )
	{
		PhaseAdvFinal_Cnt_T_s16 = (sint16)(((float32)(((sint32)PhaseAdvFinal_Cnt_T_u16) - D_FULLREV_CNT_S32)) * D_PHSADVSCALE_ULS_F32);
	}
	else
	{
		PhaseAdvFinal_Cnt_T_s16 = (sint16)(((float32)PhaseAdvFinal_Cnt_T_u16) * D_PHSADVSCALE_ULS_F32);
	}

	
	Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeA_Cnt_u32(ExpectedOnTimeA_Cnt_T_u32);
	Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeB_Cnt_u32(ExpectedOnTimeB_Cnt_T_u32);
	Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeC_Cnt_u32(ExpectedOnTimeC_Cnt_T_u32);
	Rte_IWrite_CDDInterface_Per1_MeasuredOnTimeA_Cnt_u32(MeasuredOnTime_Cnt_T_u32[D_PHASEA_CNT_U16]);
	Rte_IWrite_CDDInterface_Per1_MeasuredOnTimeB_Cnt_u32(MeasuredOnTime_Cnt_T_u32[D_PHASEB_CNT_U16]);
	Rte_IWrite_CDDInterface_Per1_MeasuredOnTimeC_Cnt_u32(MeasuredOnTime_Cnt_T_u32[D_PHASEC_CNT_U16]);
	Rte_IWrite_CDDInterface_Per1_MtrCurrDax_Amp_f32(MtrCurrDax_Amp_T_f32);
	Rte_IWrite_CDDInterface_Per1_MtrCurrQax_Amp_f32(MtrCurrQax_Amp_T_f32);
	Rte_IWrite_CDDInterface_Per1_CorrMtrCurrPosition_Rev_f32(CorrMtrCurrPosition_Rev_T_f32);
	Rte_IWrite_CDDInterface_Per1_MtrCurrK1_Amp_f32(MtrCurrK1_Amps_T_f32);
	Rte_IWrite_CDDInterface_Per1_MtrCurrK2_Amp_f32(MtrCurrK2_Amps_T_f32);
	Rte_IWrite_CDDInterface_Per1_ADCMtrCurr1_Volts_f32(MtrCurr1_Volts_T_f32);
	Rte_IWrite_CDDInterface_Per1_ADCMtrCurr2_Volts_f32(MtrCurr2_Volts_T_f32);
	Rte_IWrite_CDDInterface_Per1_ModIdxFinal_Uls_f32(ModIdx_Uls_T_f32);
	Rte_IWrite_CDDInterface_Per1_LRPRPhaseadvanceCaptured_Cnt_s16(PhaseAdvFinal_Cnt_T_s16);
	Rte_IWrite_CDDInterface_Per1_MtrCurrQaxFinalRef_Amp_f32(MtrCurrQaxFinalRef_Amp_T_f32);
	Rte_IWrite_CDDInterface_Per1_MtrCurrDaxRef_Amp_f32(MtrCurrDaxRef_Amp_T_f32);
	Rte_IWrite_CDDInterface_Per1_MtrVoltDax_Volt_f32(MtrVoltDax_Volt_T_f32);
	Rte_IWrite_CDDInterface_Per1_MtrVoltQax_Volt_f32(MtrVoltQax_Volt_T_f32);
	

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt16 Rte_IRead_CDDInterface_Per2_CommOffset_Cnt_u16(void)
 *   Float Rte_IRead_CDDInterface_Per2_DaxIntegralGain_IPM_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_DaxIntegralGain_SPM_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_DaxPropotionalGain_IPM_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_DaxPropotionalGain_SPM_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_EstKe_VpRadpS_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MRFMtrVel_MtrRadpS_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurr1TempOffset_Volt_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurr2TempOffset_Volt_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrDaxRef_IPM_Amp_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrDaxRef_SPM_Amp_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrQax12Mag_Amp_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrQax12Ph_Rev_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrQax6Mag_Amp_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrQax6Ph_Rev_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrQaxRef_IPM_Amp_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrQaxRef_SPM_Amp_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrPosComputationDelay_IPM_Deg_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrPosComputationDelay_SPM_Deg_f32(void)
 *   SInt16 Rte_IRead_CDDInterface_Per2_MtrTrqCmdSign_IPM_Cnt_s16(void)
 *   SInt16 Rte_IRead_CDDInterface_Per2_MtrTrqCmdSign_SPM_Cnt_s16(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrVoltDaxFF_IPM_Volt_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrVoltDaxFF_SPM_Volt_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrVoltQaxFF_IPM_Volt_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrVoltQaxFF_SPM_Volt_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_QaxIntegralGain_IPM_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_QaxIntegralGain_SPM_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_QaxPropotionalGain_IPM_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_QaxPropotionalGain_SPM_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_Vecu_Volt_f32(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface_Per2
 *********************************************************************************************************************/
	VAR(uint16, AUTOMATIC) WriteBuffer_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) CommOffset_Cnt_T_u16;
	VAR(sint16, AUTOMATIC) MtrTrqCmdSignIPM_Cnt_T_s16;
	VAR(sint16, AUTOMATIC) MtrTrqCmdSignSPM_Cnt_T_s16;
	VAR(float32, AUTOMATIC) MRFMtrVel_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) MtrCurr1TempOffset_Volt_T_f32;
	VAR(float32, AUTOMATIC) MtrCurr2TempOffset_Volt_T_f32;
	VAR(float32, AUTOMATIC) Vecu_Volt_T_f32;
	VAR(float32, AUTOMATIC) EstKe_VpRadpS_T_f32;
	VAR(float32, AUTOMATIC)	IPMQaxIntegralGain_Uls_T_f32;
	VAR(float32, AUTOMATIC)	SPMQaxIntegralGain_Uls_T_f32;
	VAR(float32, AUTOMATIC)	SPMQaxPropotionalGain_Uls_T_f32;
	VAR(float32, AUTOMATIC)	IPMQaxPropotionalGain_Uls_T_f32;
	VAR(float32, AUTOMATIC)	IPMDaxPropotionalGain_Uls_T_f32;
	VAR(float32, AUTOMATIC)	SPMDaxPropotionalGain_Uls_T_f32;
	VAR(float32, AUTOMATIC)	IPMDaxIntegralGain_Uls_T_f32;
	VAR(float32, AUTOMATIC)	SPMDaxIntegralGain_Uls_T_f32;
	VAR(float32, AUTOMATIC)	IPMMtrCurrDaxRef_Amp_T_f32;
	VAR(float32, AUTOMATIC)	SPMMtrCurrDaxRef_Amp_T_f32;
	VAR(float32, AUTOMATIC)	SPMMtrCurrQaxRef_Amp_T_f32;
	VAR(float32, AUTOMATIC)	IPMMtrCurrQaxRef_Amp_T_f32;
	VAR(float32, AUTOMATIC)	IPMMtrVoltDaxFF_Volt_T_f32;
	VAR(float32, AUTOMATIC)	SPMMtrVoltDaxFF_Volt_T_f32;
	VAR(float32, AUTOMATIC) IPMMtrVoltQaxFF_Volt_T_f32;
	VAR(float32, AUTOMATIC) SPMMtrVoltQaxFF_Volt_T_f32;
	VAR(float32, AUTOMATIC) MtrCurrQax12Mag_Amp_T_f32;
	VAR(float32, AUTOMATIC) MtrCurrQax12Ph_Rev_T_f32;
	VAR(float32, AUTOMATIC) MtrCurrQax6Mag_Amp_T_f32;
	VAR(float32, AUTOMATIC) MtrCurrQax6Ph_Rev_T_f32;
	VAR(float32, AUTOMATIC) MtrPosComputationDelayIPM_Deg_T_f32;
	VAR(float32, AUTOMATIC) MtrPosComputationDelaySPM_Deg_T_f32;
	
	
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SysState_Cnt_T_Enum;
	
	WriteBuffer_Cnt_T_u16 = (CDD_AppDataFwdPthAccessBfr_Cnt_G_u16 & 1)^1;
	
	CommOffset_Cnt_T_u16 = Rte_IRead_CDDInterface_Per2_CommOffset_Cnt_u16();
	SysState_Cnt_T_Enum=Rte_Mode_SystemState_Mode();
	MtrTrqCmdSignIPM_Cnt_T_s16 = Rte_IRead_CDDInterface_Per2_MtrTrqCmdSign_IPM_Cnt_s16();
	 MtrTrqCmdSignSPM_Cnt_T_s16 = Rte_IRead_CDDInterface_Per2_MtrTrqCmdSign_SPM_Cnt_s16();
	MRFMtrVel_MtrRadpS_T_f32=Rte_IRead_CDDInterface_Per2_MRFMtrVel_MtrRadpS_f32();
	MtrCurr1TempOffset_Volt_T_f32=Rte_IRead_CDDInterface_Per2_MtrCurr1TempOffset_Volt_f32();
	MtrCurr2TempOffset_Volt_T_f32=Rte_IRead_CDDInterface_Per2_MtrCurr2TempOffset_Volt_f32();
	EstKe_VpRadpS_T_f32=Rte_IRead_CDDInterface_Per2_EstKe_VpRadpS_f32();
	MtrCurrQax12Mag_Amp_T_f32=Rte_IRead_CDDInterface_Per2_MtrCurrQax12Mag_Amp_f32();
	MtrCurrQax12Ph_Rev_T_f32=Rte_IRead_CDDInterface_Per2_MtrCurrQax12Ph_Rev_f32();
	MtrCurrQax6Mag_Amp_T_f32=Rte_IRead_CDDInterface_Per2_MtrCurrQax6Mag_Amp_f32();
	MtrCurrQax6Ph_Rev_T_f32=Rte_IRead_CDDInterface_Per2_MtrCurrQax6Ph_Rev_f32();
	MtrPosComputationDelayIPM_Deg_T_f32=Rte_IRead_CDDInterface_Per2_MtrPosComputationDelay_IPM_Deg_f32();
	MtrPosComputationDelaySPM_Deg_T_f32=Rte_IRead_CDDInterface_Per2_MtrPosComputationDelay_SPM_Deg_f32();
	
	IPMDaxPropotionalGain_Uls_T_f32=Rte_IRead_CDDInterface_Per2_DaxPropotionalGain_IPM_Uls_f32();
	SPMDaxPropotionalGain_Uls_T_f32=Rte_IRead_CDDInterface_Per2_DaxPropotionalGain_SPM_Uls_f32();
	IPMDaxIntegralGain_Uls_T_f32=Rte_IRead_CDDInterface_Per2_DaxIntegralGain_IPM_Uls_f32();
	SPMDaxIntegralGain_Uls_T_f32=Rte_IRead_CDDInterface_Per2_DaxIntegralGain_SPM_Uls_f32();
	
	IPMQaxIntegralGain_Uls_T_f32=Rte_IRead_CDDInterface_Per2_QaxIntegralGain_IPM_Uls_f32();
	SPMQaxIntegralGain_Uls_T_f32=Rte_IRead_CDDInterface_Per2_QaxIntegralGain_SPM_Uls_f32();
	
	SPMQaxPropotionalGain_Uls_T_f32=Rte_IRead_CDDInterface_Per2_QaxPropotionalGain_SPM_Uls_f32();
	IPMQaxPropotionalGain_Uls_T_f32=Rte_IRead_CDDInterface_Per2_QaxPropotionalGain_IPM_Uls_f32();
	
	
	Vecu_Volt_T_f32=Rte_IRead_CDDInterface_Per2_Vecu_Volt_f32();
	IPMMtrCurrDaxRef_Amp_T_f32	=Rte_IRead_CDDInterface_Per2_MtrCurrDaxRef_IPM_Amp_f32();
	SPMMtrCurrDaxRef_Amp_T_f32 =Rte_IRead_CDDInterface_Per2_MtrCurrDaxRef_SPM_Amp_f32();
	
	IPMMtrCurrQaxRef_Amp_T_f32	=Rte_IRead_CDDInterface_Per2_MtrCurrQaxRef_IPM_Amp_f32();
	
	SPMMtrCurrQaxRef_Amp_T_f32	= Rte_IRead_CDDInterface_Per2_MtrCurrQaxRef_SPM_Amp_f32();
	
	IPMMtrVoltDaxFF_Volt_T_f32=Rte_IRead_CDDInterface_Per2_MtrVoltDaxFF_IPM_Volt_f32();
	SPMMtrVoltDaxFF_Volt_T_f32=Rte_IRead_CDDInterface_Per2_MtrVoltDaxFF_SPM_Volt_f32();
	IPMMtrVoltQaxFF_Volt_T_f32=Rte_IRead_CDDInterface_Per2_MtrVoltQaxFF_IPM_Volt_f32();
	SPMMtrVoltQaxFF_Volt_T_f32=Rte_IRead_CDDInterface_Per2_MtrVoltQaxFF_SPM_Volt_f32();


	CDD_MtrCurrOffComOffset_Cnt_G_u16[WriteBuffer_Cnt_T_u16] = CommOffset_Cnt_T_u16;
	
	CDD_MRFMtrVel_MtrRadpS_G_f32[WriteBuffer_Cnt_T_u16]=MRFMtrVel_MtrRadpS_T_f32;
	CDD_MtrCurr1TempOffset_Volt_G_f32[WriteBuffer_Cnt_T_u16]=MtrCurr1TempOffset_Volt_T_f32;
	CDD_MtrCurr2TempOffset_Volt_G_f32[WriteBuffer_Cnt_T_u16]=MtrCurr2TempOffset_Volt_T_f32;
	
	CDD_MtrCurrQax12Mag_Amp_G_f32[WriteBuffer_Cnt_T_u16]=MtrCurrQax12Mag_Amp_T_f32;
	CDD_MtrCurrQax6Mag_Amp_G_f32[WriteBuffer_Cnt_T_u16]=MtrCurrQax6Mag_Amp_T_f32;
	CDD_MtrCurrQax12Ph_Rev_G_f32[WriteBuffer_Cnt_T_u16]=MtrCurrQax12Ph_Rev_T_f32;
	CDD_MtrCurrQax6Ph_Rev_G_f32[WriteBuffer_Cnt_T_u16]=MtrCurrQax6Ph_Rev_T_f32;
	CDD_EstKe_VpRadpS_G_f32[WriteBuffer_Cnt_T_u16]=EstKe_VpRadpS_T_f32;
	
	if(k_IPMMtrSwitch_Cnt_lgc==TRUE)
	{
	CDD_DaxPropotionalGain_Uls_G_f32[WriteBuffer_Cnt_T_u16]=IPMDaxPropotionalGain_Uls_T_f32;
	CDD_DaxIntegralGain_Uls_G_f32[WriteBuffer_Cnt_T_u16]=IPMDaxIntegralGain_Uls_T_f32;
	CDD_QaxIntegralGain_Uls_G_f32[WriteBuffer_Cnt_T_u16]=IPMQaxIntegralGain_Uls_T_f32;
	CDD_QaxPropotionalGain_Uls_G_f32[WriteBuffer_Cnt_T_u16]=IPMQaxPropotionalGain_Uls_T_f32;
	CDD_MtrCurrDaxRef_Amp_G_f32[WriteBuffer_Cnt_T_u16]=IPMMtrCurrDaxRef_Amp_T_f32;
	CDD_MtrCurrQaxRef_Amp_G_f32[WriteBuffer_Cnt_T_u16]=IPMMtrCurrQaxRef_Amp_T_f32;
	CDD_MtrVoltDaxFF_Volt_G_f32[WriteBuffer_Cnt_T_u16]=IPMMtrVoltDaxFF_Volt_T_f32;
	CDD_MtrVoltQaxFF_Volt_G_f32[WriteBuffer_Cnt_T_u16]=IPMMtrVoltQaxFF_Volt_T_f32;
	CDD_MtrTrqCmdSign_Cnt_G_s16[WriteBuffer_Cnt_T_u16] = MtrTrqCmdSignIPM_Cnt_T_s16;
	CDD_MtrPosComputationDelay_Deg_G_f32[WriteBuffer_Cnt_T_u16]=MtrPosComputationDelayIPM_Deg_T_f32;
	}
	else
	{
	CDD_DaxPropotionalGain_Uls_G_f32[WriteBuffer_Cnt_T_u16]=SPMDaxPropotionalGain_Uls_T_f32;
	CDD_DaxIntegralGain_Uls_G_f32[WriteBuffer_Cnt_T_u16]=SPMDaxIntegralGain_Uls_T_f32;
	CDD_QaxIntegralGain_Uls_G_f32[WriteBuffer_Cnt_T_u16]=SPMQaxIntegralGain_Uls_T_f32;
	CDD_QaxPropotionalGain_Uls_G_f32[WriteBuffer_Cnt_T_u16]=SPMQaxPropotionalGain_Uls_T_f32;
	CDD_MtrCurrDaxRef_Amp_G_f32[WriteBuffer_Cnt_T_u16]=SPMMtrCurrDaxRef_Amp_T_f32;
	CDD_MtrCurrQaxRef_Amp_G_f32[WriteBuffer_Cnt_T_u16]=SPMMtrCurrQaxRef_Amp_T_f32;
	CDD_MtrVoltDaxFF_Volt_G_f32[WriteBuffer_Cnt_T_u16]=SPMMtrVoltDaxFF_Volt_T_f32;
	CDD_MtrVoltQaxFF_Volt_G_f32[WriteBuffer_Cnt_T_u16]=SPMMtrVoltQaxFF_Volt_T_f32;
	CDD_MtrTrqCmdSign_Cnt_G_s16[WriteBuffer_Cnt_T_u16] = MtrTrqCmdSignSPM_Cnt_T_s16;
	CDD_MtrPosComputationDelay_Deg_G_f32[WriteBuffer_Cnt_T_u16]=MtrPosComputationDelaySPM_Deg_T_f32;
	}
	
	

	CDD_Vecu_Volt_G_f32[WriteBuffer_Cnt_T_u16]=Vecu_Volt_T_f32;
	
	
	CDD_SysState_Cnt_G_Enum=SysState_Cnt_T_Enum;
	
	
	
	
	CDD_AppDataFwdPthAccessBfr_Cnt_G_u16 = WriteBuffer_Cnt_T_u16;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Per4
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_CDDInterface_Per4_DiagStsDefVehSpd_Cnt_lgc(void)
 *   SInt8 Rte_IRead_CDDInterface_Per4_MtrElecMechPolarity_Cnt_s08(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_DftAsstTbl_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_DftAsstTbl_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_DwnldAsstGain_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per4_DwnldAsstGain_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_MEC_Cnt_enum(ManufModeType data)
 *   ManufModeType *Rte_IWriteRef_CDDInterface_Per4_MEC_Cnt_enum(void)
 *   void Rte_IWrite_CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_SrlComSvcDft_Cnt_b32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per4_SrlComSvcDft_Cnt_b32(void)
 *   void Rte_IWrite_CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_VehSpdValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_VehSpdValid_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_WIREnabled_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_WIREnabled_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_WhlImbRejSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_WhlImbRejSrlComSvcDft_Cnt_lgc(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Per4(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface_Per4
 *********************************************************************************************************************/
	VAR(sint8, AUTOMATIC) MtrElecMechPolarity_Cnt_T_s08;
	VAR(boolean, AUTOMATIC) TOEnable_Cnt_T_lgc;
	VAR(uint32, AUTOMATIC)	EOLSrlComSvcDft_Cnt_T_b32;
	
	MtrElecMechPolarity_Cnt_T_s08 = Rte_IRead_CDDInterface_Per4_MtrElecMechPolarity_Cnt_s08();
	TOEnable_Cnt_T_lgc = SrlComInput_GetEnableTorqueOverlay();

	if (MtrElecMechPolarity_Cnt_T_s08 != PrevMtrElecMechPolarity_Cnt_M_s08)
	{
		Rte_Call_CDDPorts_ApplyMtrElecMechPol(MtrElecMechPolarity_Cnt_T_s08);
		PrevMtrElecMechPolarity_Cnt_M_s08 = MtrElecMechPolarity_Cnt_T_s08;
	}

	if ((D_WHLIMBSEL_CNT_U16 == CDD_EOLNxtrWIRSelect_Cnt_G_u16) &&
	    (FALSE == CDD_WIRDisableSvc_Cnt_G_lgc))
	{
		Rte_IWrite_CDDInterface_Per4_WIREnabled_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_WIREnabled_Cnt_lgc(FALSE);
	}
	
	if (FALSE == TOEnable_Cnt_T_lgc)
	{
		Rte_IWrite_CDDInterface_Per4_TOEOLDisable_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_TOEOLDisable_Cnt_lgc(FALSE);
	}

	/* DiagManager manufacturing defeat functionality */
	Rte_IWrite_CDDInterface_Per4_MfgDiagInhibit_Cnt_lgc(MfgDiagInhibit_Uls_G_lgc);

	switch (Nvm_NMEC_Cnt_u8)
    {
        case D_MEC_ENGMODE_CNT_U8:  /* Production mode or Engineering mode, do nothing */
			Rte_IWrite_CDDInterface_Per4_MEC_Cnt_enum(EngineeringMode);
			EOLSrlComSvcDft_Cnt_T_b32 = CDD_EOLSrlComSvcDft_Cnt_G_b32;
        break;
        case D_MEC_PRODMODE_CNT_U8:
			Rte_IWrite_CDDInterface_Per4_MEC_Cnt_enum(ProductionMode);
			if(TRUE == ChryEngDft_Cnt_G_lgc)
			{
				EOLSrlComSvcDft_Cnt_T_b32 = (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTENGON_CNT_B32);
			}
			else
			{
				EOLSrlComSvcDft_Cnt_T_b32 = 0U;
			}
        break;
        default:
			Rte_IWrite_CDDInterface_Per4_MEC_Cnt_enum(ManufacturingMode);
			EOLSrlComSvcDft_Cnt_T_b32 = CDD_EOLSrlComSvcDft_Cnt_G_b32;
        break;
    }

	/* DIAGNOSTIC SERVICE INTERFACE - ASSIST GAIN FUNCTION */
	Rte_IWrite_CDDInterface_Per4_DftAsstTbl_Cnt_lgc(CDD_DftAsstTbl_Cnt_G_lgc);
	Rte_IWrite_CDDInterface_Per4_DwnldAsstGain_Uls_f32(CDD_DwnldAsstGain_Uls_G_f32);
	
	/* DIAGNOSTIC SERVICE INTERFACE - SRLCOMSVC DEFEAT */
	Rte_IWrite_CDDInterface_Per4_SrlComSvcDft_Cnt_b32(EOLSrlComSvcDft_Cnt_T_b32);

	/* REQUEST TRANSITION TO OPERATE/RUN STATE */
	if (D_SVCDFTENGON_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTENGON_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTFREQDEPDMP_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTFREQDEPDMP_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTKININTDIAG_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTKININTDIAG_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTTHERMALDC_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTTHERMALDC_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTEOTIMPACT_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTEOTIMPACT_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTEOTTHERMAL_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTEOTTHERMAL_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTMTRVELNRMLRN_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTMTRVELNRMLRN_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTMTRPARMNRMLRN_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTMTRPARMNRMLRN_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTTRQRMP_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTTRQRMP_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTMODIDX_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTMODIDX_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc(TRUE);
		CDD_ModIdxSrlComSvcDft_Cnt_G_u16=TRUE;
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc(FALSE);	
		CDD_ModIdxSrlComSvcDft_Cnt_G_u16=FALSE;
	}
	
	if (D_SVCDFTPULLCOMP_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTPULLCOMP_CNT_B32) || (TRUE == Appdesc_PullCompDis_Cnt_G_lgc))
	{
		Rte_IWrite_CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTWHLIMBREJ_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTWHLIMBREJ_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_WhlImbRejSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_WhlImbRejSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTPARKAST_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTPARKAST_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTDRIVINGDYN_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTDRIVINGDYN_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTHYSTCOMP_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTHYSTCOMP_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTHYSTADD_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTHYSTADD_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTRETURN_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTRETURN_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTDAMPING_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTDAMPING_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTLIMIT_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTLIMIT_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc(FALSE);	
	}

	if (D_SVCDFTFRICLRN_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTFRICLRN_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_FricLrnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_FricLrnSrlComSvcDft_Cnt_lgc(FALSE);
	}
		
	/* DEFEAT RECEPTION OF SRLCOMINPUT MESSAGES */
	if (D_SVCDFTRXMSGS_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTRXMSGS_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	/* MULTIPLE IGNITION CYCLE DEFEATS - store EOLSrlComSvcDft */
	if (D_SVCDFTMULTIGNMASK_CNT_B32 == (EOLSrlComSvcDft_Cnt_T_b32 & D_SVCDFTMULTIGNMASK_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_CDDINTERFACE_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
FUNC(void, CDDInterface_CODE) CDDPorts_ApplyMtrElecMechPol(sint8 MtrElecMechPol_Cnt_s8)
{
	CDD_MtrElecPol_Cnt_G_s8=MtrElecMechPol_Cnt_s8;
	CDD_ApplyPWMMtrElecMechPol(CDD_MtrElecPol_Cnt_G_s8);

}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
