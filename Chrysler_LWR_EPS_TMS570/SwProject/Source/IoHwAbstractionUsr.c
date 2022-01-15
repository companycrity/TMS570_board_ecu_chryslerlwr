


/*
   !! B E T A   V E R S I O N !!

  These programs are fully operative programs.
  However, they are not thoroughly tested yet (beta-version).
  With regard to the fact that the programs are a beta-version only,
  Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence,
  to the extent admissible by law or statute.
*/



/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  IoHwAbstractionUsr.c
 *     Workspace:  C:/cmsynergy/My_LWR_WA/Chrysler_LWR_EPS_TMS570/Tools/AsrProject/Generators/Rte/<WSP_FILE
 *     SW-C Type:  IoHwAbstractionUsr
 *  Generated at:  Fri Dec 14 11:26:51 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <IoHwAbstractionUsr>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 18 18:34:17 2011
 * %version:          8 %
 * %derived_by:       jzh87w %
 * %date_modified:    Thu Feb 13 15:49:06 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev          Author         Change Description                                                        SCR #
 * -------   -------      --------  ---------------------------------------------------------------------------  ----------
 * 08/02/11   3           JJW       R230 mcu hardware scaling
 * 11/03/11   3.1.1       LWW       Added anomaly fix
 * 12/12/11	  3.1.2	      KJS		Added PWM torque function. 
 * 12/13/11	  3.1.3	      LWW		Added torque signals to FwdPath periodic
 * 01/25/12	  3.1.4	      LWW		Added temperature output as sender port
 * 01/30/12	  3.1.5	      LWW		Header name changes for Nhet component
 * 02/28/12	  3.1.5.1.1	  LWW		Corrected anomaly for HwTrq lag in ADC result reads
 * 04/24/12	  3.1.5.1.3	  LWW		Updates per NHET design changes
 * 05/24/12	  3.1.5.1.4	  LWW		Updates for anomaly correction
 * 05/17/13	  5.1.1		  SAH		Updates for MtrPos component integration
 * 07/10/13	  6		      JJW		MemMap statements for module level variable allocation
 * 10/15/13	  7		      SAH		Added ADC runtime and ref NTCs
 * 10/15/13	  8		      SAH		Added Adc2_GetVswitched_Cnt_u16_m macro for 50us read (A5898)
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Constants:
 ==========
  D_RACKTOVEHCNTRUNLEARNED_CNT_U16
    This constant has been added until anomaly 3744 can be corrected. Once the anomaly is corrected, this can be removed from StdDef. This should only be used by BMW as of 12Sep12.


 Data Element Prototypes:
 ========================
  Volt_f32 of Port Interface Voltage_Volt_f32
    This signal is intended to communicate any type voltage signal measured by the ecu.  This signal has a lower limit of 0 which reequires users of the signal to provide divide by 0 protection if it is used as a denominator in a calculation.  See Vecu port prototype if a port with a lower limit is desired.

  Volt_f32 of Port Interface Voltage
    This signal is intended to communicate any type voltage signal measured by the ecu.  This signal has a lower limit of 0 which reequires users of the signal to provide divide by 0 protection if it is used as a denominator in a calculation.  See Vecu port prototype if a port with a lower limit is desired.


 *********************************************************************************************************************/

#include "Rte_IoHwAbstractionUsr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Adc.h"
#include "Adc_Cfg.h"
#include "Adc2.h"
#include "CDD_Const.h"
#include "CalConstants.h"
#include "CDD_Data.h"
#include "GlobalMacro.h"

#define D_NUMFWDPTHCH_CNT_U16   2U
#define D_NUMFDBKPTHCH_CNT_U16  8U

#define D_T1CHN_CNT_U16  				0U
#define D_T2CHN_CNT_U16  				1U

#define D_TEMPSNSRCHN_CNT_U16  			0U
#define D_BATTCHN_CNT_U16  				1U
#define D_VREFCHN_CNT_U16  				2U
#define D_COS1CHN_CNT_U16  				3U
#define D_SIN1CHN_CNT_U16  				4U
#define D_SIN2CHN_CNT_U16  				5U
#define D_COS2CHN_CNT_U16  				6U
#define D_BATTSWITCHEDCHN_CNT_U16  		7U

#define D_ADCVOLTSPERCNT_ULS_F32		5.0F /4095.0F /*PSR324 - 5V Gladiator Reference*/

#define D_NHET_PWMPULSECNTMAX_CNT_U32	4294967295U
#define D_NHET_PWMPULSECNTMIN_CNT_U32	768U

/* TODO: See if these need to be calibrations */
#define D_TORQUEHWSCALING_ULS_F32		1.0F			/*PSR324 - R230 Scaling (Needs to change to cal)*/
#define D_BATTSWHWSCALING_ULS_F32		3.36966824645F  /*PSR324 - R230 Scaling (Needs to change to cal)*/
#define D_BATTHWSCALING_ULS_F32			6.74712643678F  /*PSR324 - R230 Scaling (Needs to change to cal)*/

#define IOHWAB10_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

volatile VAR(uint8, IOHWABSTRACTIONUSR_VAR) FwdPathAdcActvDblBuf_Cnt_G_u08;
static VAR(uint8, IOHWABSTRACTIONUSR_VAR) IO_InitComplete_M_Uls_u08;

#define IOHWAB10_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define IOHWAB10_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

static VAR(Adc_ValueGroupType, IOHWABSTRACTIONUSR_VAR) IO_FwdPthAdcBufRead_M_Cnt[D_NUMFWDPTHCH_CNT_U16];
static VAR(Adc_ValueGroupType, IOHWABSTRACTIONUSR_VAR) IO_FwdPthAdcBufRslt_M_Cnt[D_NUMFWDPTHCH_CNT_U16];

static VAR(Adc_ValueGroupType, IOHWABSTRACTIONUSR_VAR) IO_FdbkPthAdcBufRead_M_Cnt[D_NUMFDBKPTHCH_CNT_U16];
static VAR(Adc_ValueGroupType, IOHWABSTRACTIONUSR_VAR) IO_FdbkPthAdcBufRslt_M_Cnt[D_NUMFDBKPTHCH_CNT_U16];

STATIC VAR(uint16, AUTOMATIC) IoHwAb_ADCVrefErrorAcc_Cnt_M_u16;
STATIC VAR(uint16, AUTOMATIC) IoHwAb_ADCSysCVSwitched_Cnt_M_u16;

#define IOHWAB10_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"
#define IOHWAB10_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
STATIC VAR(float32, AUTOMATIC) IoHwAb_ADCVrefScaled_Volt_M_f32;
#define IOHWAB10_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

STATIC FUNC(void, RTE_IOHWABSTRACTIONUSR_APPL_CODE) FwdPathConv( void );
STATIC FUNC(void, RTE_IOHWABSTRACTIONUSR_APPL_CODE) FdbkPathConv( void );

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
 * Double: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN (standard type)
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * IoHwAb_BoolType: Integer in interval [0...1]
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
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
 * Float: D_100MS_SEC_F32 = 0.1F
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082F
 * Float: D_2MS_MS_F32 = 0.002F
 * Float: D_2MS_SEC_F32 = 0.002F
 * Float: D_2PI_ULS_F32 = 6.2831853071796F
 * Float: D_MSECPERSEC_ULS_F32 = 1000.0F
 * Float: D_MTRCTRLHIGHLMT_VOLTS_F32 = 18.0F
 * Float: D_MTRCTRLLOWLMT_VOLTS_F32 = 9.0F
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8F
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8F
 * Float: D_MTRTRQCMLOLMT_MTRNM_F32 = -8.8F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199F
 * Float: D_PI_ULS_F32 = 3.1415926535898F
 * Float: D_RADPERREV_ULS_F32 = 6.28318530718F
 * Float: D_VECUMIN_VOLTS_F32 = 5.0F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * SInt16: D_NEGONE_CNT_S16 = -1
 * SInt16: D_ONE_CNT_S16 = 1
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt32: D_NEGONE_CNT_S32 = -1
 * SInt32: D_ONE_CNT_S32 = 1
 * SInt32: D_ZERO_CNT_S32 = 0
 * SInt8: D_NEGONE_CNT_S8 = -1
 * SInt8: D_ONE_CNT_S8 = 1
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_DELTAROLLASST_MTRNM_U5P11 = 512U
 * UInt16: D_MAXCONF_ULS_U8P8 = 256U
 * UInt16: D_MTRPOLESDIV2_CNT_U16 = 3U
 * UInt16: D_ONE_CNT_U16 = 1U
 * UInt16: D_QUADRANT1_CNT_U16 = 1U
 * UInt16: D_QUADRANT2_CNT_U16 = 2U
 * UInt16: D_QUADRANT3_CNT_U16 = 3U
 * UInt16: D_QUADRANT4_CNT_U16 = 4U
 * UInt16: D_RACKCNTRUNLEARNED_CNT_U16 = 65535U
 * UInt16: D_RACKTOVEHCNTRINVALID_CNT_U16 = 4095U
 * UInt16: D_RACKTOVEHCNTRUNLEARNED_CNT_U16 = 4095U
 * UInt16: D_ZERO_CNT_U16 = 0U
 * UInt32: D_ONE_CNT_U32 = 1U
 * UInt32: D_SVCDFTKININTDIAG_CNT_B32 = 4U
 * UInt32: D_ZERO_CNT_U32 = 0U
 * UInt8: D_MTRPOLESDIV2_CNT_U8 = 3U
 * UInt8: D_ONE_CNT_U8 = 1U
 * UInt8: D_QUADRANT1_CNT_U8 = 1U
 * UInt8: D_QUADRANT2_CNT_U8 = 2U
 * UInt8: D_QUADRANT3_CNT_U8 = 3U
 * UInt8: D_QUADRANT4_CNT_U8 = 4U
 * UInt8: D_TURNSCNTRPARTNUMINIT_CNT_U08 = 255U
 * UInt8: D_ZERO_CNT_U8 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_IOHWABSTRACTIONUSR_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_FdbkPathAdc
 *
 * This runnable can be invoked concurrently (reentrant implementation).
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
 *   void Rte_IWrite_IoHwAb_FdbkPathAdc_BattSwitched_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_FdbkPathAdc_BattSwitched_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_FdbkPathAdc_Batt_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_FdbkPathAdc_Batt_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_FdbkPathAdc_SysCVSwitch_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_FdbkPathAdc_SysCVSwitch_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_FdbkPathAdc_TemperatureADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_FdbkPathAdc_TemperatureADC_Volt_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWABSTRACTIONUSR_APPL_CODE) IoHwAb_FdbkPathAdc(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_FdbkPathAdc
 *********************************************************************************************************************/

    /* Perform the feedback path conversion steps */
    FdbkPathConv();

    IoHwAb_ADCVrefScaled_Volt_M_f32 = (float32)IO_FdbkPthAdcBufRead_M_Cnt[D_VREFCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVrefScaling_Uls_f32;

	if(IoHwAb_ADCVrefScaled_Volt_M_f32 > k_VrefMax_Volts_f32)
	{
		IoHwAb_ADCVrefErrorAcc_Cnt_M_u16 = DiagPStep_m(IoHwAb_ADCVrefErrorAcc_Cnt_M_u16, k_VrefOORDiag_Cnt_str);
		if (DiagFailed_m( IoHwAb_ADCVrefErrorAcc_Cnt_M_u16, k_VrefOORDiag_Cnt_str) == D_TRUE_CNT_LGC)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_RefSupplyVltg, D_NTCPARMBIT0_CNT_U8, NTC_STATUS_FAILED);
		}
	}
	else if(IoHwAb_ADCVrefScaled_Volt_M_f32 < k_VrefMin_Volts_f32)
	{
		IoHwAb_ADCVrefErrorAcc_Cnt_M_u16 = DiagPStep_m(IoHwAb_ADCVrefErrorAcc_Cnt_M_u16, k_VrefOORDiag_Cnt_str);
		if (DiagFailed_m( IoHwAb_ADCVrefErrorAcc_Cnt_M_u16, k_VrefOORDiag_Cnt_str) == D_TRUE_CNT_LGC)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_RefSupplyVltg, D_NTCPARMBIT1_CNT_U8, NTC_STATUS_FAILED);
		}
	}
	else
	{
		IoHwAb_ADCVrefErrorAcc_Cnt_M_u16 = DiagNStep_m(IoHwAb_ADCVrefErrorAcc_Cnt_M_u16, k_VrefOORDiag_Cnt_str);
		if (IoHwAb_ADCVrefErrorAcc_Cnt_M_u16 == D_ZERO_CNT_U16)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_RefSupplyVltg, D_NTCPARMBIT0_CNT_U8, NTC_STATUS_PASSED);
		}
	}

	/* Update Sender port signals for completed analog conversions*/
	Rte_IWrite_IoHwAb_FdbkPathAdc_TemperatureADC_Volt_f32(((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_TEMPSNSRCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32));
	Rte_IWrite_IoHwAb_FdbkPathAdc_BattSwitched_Volt_f32(((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_BATTSWITCHEDCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * D_BATTSWHWSCALING_ULS_F32));
	Rte_IWrite_IoHwAb_FdbkPathAdc_Batt_Volt_f32(((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_BATTCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * D_BATTHWSCALING_ULS_F32));
	Rte_IWrite_IoHwAb_FdbkPathAdc_SysCVSwitch_Volt_f32(((float32)IoHwAb_ADCSysCVSwitched_Cnt_M_u16 * D_ADCVOLTSPERCNT_ULS_F32 * D_BATTSWHWSCALING_ULS_F32));
	Rte_IWrite_IoHwAb_FdbkPathAdc_InvCos2Scaled_Volt_f32(((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_COS2CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32));
	Rte_IWrite_IoHwAb_FdbkPathAdc_InvSin2Scaled_Volt_f32(((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_SIN2CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32));

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_FwdPathAdc
 *
 * This runnable can be invoked concurrently (reentrant implementation).
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
 *   void Rte_IWrite_IoHwAb_FwdPathAdc_SysCT1ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_FwdPathAdc_SysCT1ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_FwdPathAdc_SysCT2ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_FwdPathAdc_SysCT2ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_FwdPathAdc_T1ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_FwdPathAdc_T1ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_FwdPathAdc_T2ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_FwdPathAdc_T2ADC_Volt_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWABSTRACTIONUSR_APPL_CODE) IoHwAb_FwdPathAdc(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_FwdPathAdc
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) T1ADC_Volt_T_f32;
	VAR(float32, AUTOMATIC) T2ADC_Volt_T_f32;
	VAR(float32, AUTOMATIC) SysCT1ADC_Volt_T_f32;
	VAR(float32, AUTOMATIC) SysCT2ADC_Volt_T_f32;

    /* Perform the forward path conversion steps */
    FwdPathConv();

    /* Grab SysC version of VSwitch from 50uS sample as close to feedback path start of conversion as possible */
    IoHwAb_ADCSysCVSwitched_Cnt_M_u16 = Adc2_GetVSwitched_Cnt_u16_m;

	FwdPathAdcActvDblBuf_Cnt_G_u08 = (FwdPathAdcActvDblBuf_Cnt_G_u08 ^ 1u) & 1u;
    /* Buffer 50uS data as close to 2ms data as possible */
    SysCT1ADC_Volt_T_f32 = Adc2_GetT1_Cnt_u16_m;
    SysCT2ADC_Volt_T_f32 = Adc2_GetT2_Cnt_u16_m;


	/* Stnadardize the conversion values and update the Sender Port Interfaces */
	T1ADC_Volt_T_f32 = IO_FwdPthAdcBufRead_M_Cnt[D_T1CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * D_TORQUEHWSCALING_ULS_F32;
	T2ADC_Volt_T_f32 = IO_FwdPthAdcBufRead_M_Cnt[D_T2CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * D_TORQUEHWSCALING_ULS_F32;
	SysCT1ADC_Volt_T_f32 = SysCT1ADC_Volt_T_f32 * D_ADCVOLTSPERCNT_ULS_F32 * D_TORQUEHWSCALING_ULS_F32;
	SysCT2ADC_Volt_T_f32 = SysCT2ADC_Volt_T_f32 * D_ADCVOLTSPERCNT_ULS_F32 * D_TORQUEHWSCALING_ULS_F32;
		
	Rte_IWrite_IoHwAb_FwdPathAdc_T1ADC_Volt_f32(T1ADC_Volt_T_f32);
	Rte_IWrite_IoHwAb_FwdPathAdc_T2ADC_Volt_f32(T2ADC_Volt_T_f32);
	Rte_IWrite_IoHwAb_FwdPathAdc_SysCT1ADC_Volt_f32(SysCT1ADC_Volt_T_f32);
	Rte_IWrite_IoHwAb_FwdPathAdc_SysCT2ADC_Volt_f32(SysCT2ADC_Volt_T_f32);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_Init
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_IoHwAb_Init_BattSwitched_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_BattSwitched_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_Batt_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_Batt_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_SysCT1ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_SysCT1ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_SysCT2ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_SysCT2ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_SysCVSwitch_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_SysCVSwitch_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_T1ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_T1ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_T2ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_T2ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_TemperatureADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_TemperatureADC_Volt_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWABSTRACTIONUSR_APPL_CODE) IoHwAb_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_Init
 *********************************************************************************************************************/
    
    Adc_SetupResultBuffer( AdcFwdPath, IO_FwdPthAdcBufRslt_M_Cnt );
    Adc_SetupResultBuffer( AdcFdbkPath, IO_FdbkPthAdcBufRslt_M_Cnt );
    
    /* Start the first conversions and update the sender ports with the results */
    FwdPathConv();
    FdbkPathConv();

    IO_InitComplete_M_Uls_u08 = TRUE;
    IoHwAb_ADCSysCVSwitched_Cnt_M_u16 = Adc2_GetVSwitched_Cnt_u16_m;

	/* Update Sender port signals for completed analog conversions*/
	Rte_IWrite_IoHwAb_Init_TemperatureADC_Volt_f32((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_TEMPSNSRCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32);
	Rte_IWrite_IoHwAb_Init_T1ADC_Volt_f32((float32)IO_FwdPthAdcBufRead_M_Cnt[D_T1CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * D_TORQUEHWSCALING_ULS_F32);
	Rte_IWrite_IoHwAb_Init_T2ADC_Volt_f32((float32)IO_FwdPthAdcBufRead_M_Cnt[D_T2CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * D_TORQUEHWSCALING_ULS_F32);
	Rte_IWrite_IoHwAb_Init_BattSwitched_Volt_f32(((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_BATTSWITCHEDCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * D_BATTSWHWSCALING_ULS_F32));
	Rte_IWrite_IoHwAb_Init_Batt_Volt_f32(((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_BATTCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * D_BATTHWSCALING_ULS_F32));
	Rte_IWrite_IoHwAb_Init_SysCVSwitch_Volt_f32(((float32)IoHwAb_ADCSysCVSwitched_Cnt_M_u16 * D_ADCVOLTSPERCNT_ULS_F32 * D_BATTSWHWSCALING_ULS_F32));
	Rte_IWrite_IoHwAb_Init_SysCT1ADC_Volt_f32((Adc2_GetT1_Cnt_u16_m * D_ADCVOLTSPERCNT_ULS_F32 * D_TORQUEHWSCALING_ULS_F32));
	Rte_IWrite_IoHwAb_Init_SysCT2ADC_Volt_f32((Adc2_GetT2_Cnt_u16_m * D_ADCVOLTSPERCNT_ULS_F32 * D_TORQUEHWSCALING_ULS_F32));
	Rte_IWrite_IoHwAb_Init_InvCos2Scaled_Volt_f32(((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_COS2CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32));
	Rte_IWrite_IoHwAb_Init_InvSin2Scaled_Volt_f32(((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_SIN2CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32));
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}



#define RTE_STOP_SEC_IOHWABSTRACTIONUSR_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /*****************************************************************************
  * Name:        FwdPathConv
  * Description: Perform the ADC conversion management required during the 
  *               forward path conversion.
  * Inputs:      None 
  * Outputs:     Forward path ADC results buffer
*****************************************************************************/
 STATIC FUNC(void, RTE_IOHWABSTRACTIONUSR_APPL_CODE) FwdPathConv( void )
{
	 VAR(boolean, AUTOMATIC)  TimeOut_Cnt_T_lgc = D_FALSE_CNT_LGC;
	 VAR(uint32, AUTOMATIC)  StartTime_uS_T_u32;
	 VAR(uint16, AUTOMATIC)  ElapsedTime_uS_T_u16;

	 /* InitComplete flag required since the motor control ISR may not be started
	   and the ECU will be held in an inf loop */
	if( (CDD_Adc_ConvFlag_Uls_u08 == 0U) && (IO_InitComplete_M_Uls_u08 == TRUE))
	{
		/* Set flag for first conversion. */
		CDD_Adc_ConvFlag_Uls_u08 = 0x01U;
			
		/* Get start time for wait period */
		(void)Rte_Call_SystemTime_GetSystemTime_uS_u32(&StartTime_uS_T_u32);

		/* Wait for Motor Control ISR routine to start conversion */
		while ((CDD_Adc_ConvFlag_Uls_u08 != 0U) && (TimeOut_Cnt_T_lgc == D_FALSE_CNT_LGC))
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(StartTime_uS_T_u32, &ElapsedTime_uS_T_u16);

			if( ElapsedTime_uS_T_u16 >= k_GenMaxADCWaitTime_uS_u16 )
			{
				TimeOut_Cnt_T_lgc = D_TRUE_CNT_LGC;
			}
		}

		/* Get start time for wait period */
		(void)Rte_Call_SystemTime_GetSystemTime_uS_u32(&StartTime_uS_T_u32);

		/* Wait for hardware to indicate End of Conversion */
		while((Adc_GetGroupStatus(AdcFwdPath)== ADC_BUSY) && (TimeOut_Cnt_T_lgc == D_FALSE_CNT_LGC))
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(StartTime_uS_T_u32, &ElapsedTime_uS_T_u16);

			if( ElapsedTime_uS_T_u16 >= k_MaxADCConvTime_uS_u16 )
			{
				/* Set ADC End of Conversion fault and exit loop */
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PerDiag_ADC1Flt, D_NTCPARMBIT1_CNT_U8, NTC_STATUS_FAILED);
				TimeOut_Cnt_T_lgc = D_TRUE_CNT_LGC;
			}
		}
				
		(void)Adc_ReadGroup ( AdcFwdPath, IO_FwdPthAdcBufRead_M_Cnt );
		
		/* Set flag to allow next group to start. */
		CDD_Adc_ConvFlag_Uls_u08 = 0x10U;
	}
	else if (IO_InitComplete_M_Uls_u08 == FALSE)
	{
		if(Adc_GetGroupStatus(AdcFwdPath)!= ADC_BUSY)
		{
			Adc_StartGroupConversion ( AdcFwdPath );
		}

		/* Get start time for wait period */
		(void)Rte_Call_SystemTime_GetSystemTime_uS_u32(&StartTime_uS_T_u32);

		/* Wait for hardware to indicate End of Conversion */
		while((Adc_GetGroupStatus(AdcFwdPath)== ADC_BUSY) && (TimeOut_Cnt_T_lgc == D_FALSE_CNT_LGC))
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(StartTime_uS_T_u32, &ElapsedTime_uS_T_u16);

			if( ElapsedTime_uS_T_u16 >= k_MaxADCConvTime_uS_u16 )
			{
				/* Set ADC End of Conversion fault and exit loop */
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PerDiag_ADC1Flt, D_NTCPARMBIT1_CNT_U8, NTC_STATUS_FAILED);
				TimeOut_Cnt_T_lgc = D_TRUE_CNT_LGC;
			}
		}
	
		/* Get the results buffer data from the T1/T2 Conversion */
		(void)Adc_ReadGroup ( AdcFwdPath, IO_FwdPthAdcBufRead_M_Cnt );
			
		/* Trigger the Feedback Path ADC conversion */
		if(Adc_GetGroupStatus(AdcFdbkPath)!= ADC_BUSY)
		{
		   Adc_StartGroupConversion ( AdcFdbkPath );
		}
		else
		{
			/* TODO: Determine what to do in the case of an unexpected conversion in progress at this point */
		}
		
	}
	else
	{

	}
}

/*****************************************************************************
  * Name:        FdbkPathConv
  * Description: Perform the ADC conversion management required during the 
  *               feedback path conversion.
  * Inputs:      None 
  * Outputs:     Feedback path ADC results buffer
*****************************************************************************/ 
STATIC FUNC(void, RTE_IOHWABSTRACTIONUSR_APPL_CODE) FdbkPathConv( void )
{
	VAR(boolean, AUTOMATIC)  TimeOut_Cnt_T_lgc = D_FALSE_CNT_LGC;
	VAR(uint32, AUTOMATIC)  StartTime_uS_T_u32;
	VAR(uint16, AUTOMATIC)  ElapsedTime_uS_T_u16;

	if (IO_InitComplete_M_Uls_u08 == TRUE)
	{
		/* Get start time for wait period */
		(void)Rte_Call_SystemTime_GetSystemTime_uS_u32(&StartTime_uS_T_u32);

		while((CDD_Adc_ConvFlag_Uls_u08 != 0U) && (TimeOut_Cnt_T_lgc == D_FALSE_CNT_LGC))
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(StartTime_uS_T_u32, &ElapsedTime_uS_T_u16);

			if( ElapsedTime_uS_T_u16 >= k_GenMaxADCWaitTime_uS_u16 )
			{
				TimeOut_Cnt_T_lgc = D_TRUE_CNT_LGC;
			}
		}
	} 

	/* Get start time for wait period */
	(void)Rte_Call_SystemTime_GetSystemTime_uS_u32(&StartTime_uS_T_u32);

	/* Get the results buffer data from the feedback path conversion */
	while((Adc_GetGroupStatus(AdcFdbkPath)== ADC_BUSY) && (TimeOut_Cnt_T_lgc == D_FALSE_CNT_LGC))
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(StartTime_uS_T_u32, &ElapsedTime_uS_T_u16);

		if( ElapsedTime_uS_T_u16 >= k_MaxADCConvTime_uS_u16 )
		{
			/* Set ADC End of Conversion fault and exit loop */
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PerDiag_ADC1Flt, D_NTCPARMBIT1_CNT_U8, NTC_STATUS_FAILED);
			TimeOut_Cnt_T_lgc = D_TRUE_CNT_LGC;
		}
	}
	(void)Adc_ReadGroup ( AdcFdbkPath, IO_FdbkPthAdcBufRead_M_Cnt );
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
