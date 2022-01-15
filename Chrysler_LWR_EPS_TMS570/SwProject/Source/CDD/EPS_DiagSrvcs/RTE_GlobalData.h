/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : RTE_GlobalData.h file
* Module Description: Contains global Rte data used in Diagnostic Srvcs.
* Product           : Gen II Plus - EA3.0
* Author            : Bobby O'Steen
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          20 %
 * %derived_by:       jzh87w %
 * %date_modified:    Thu Feb 27 12:45:28 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial K2xx Synergy Version
 * 07/08/11  2		  SAH		Added veh spd and hwttrq variables
 * 08/04/11  3		  SAH		Added Srlcom Eng on variable
 * 10/13/11	 4		  KJS		Added variables for XCP services												4564
 * 01/06/12	 6		  LWW		Name change on Vecu, removed ParamEst variable
 * 03/14/12  7		  SAH		Updated hwpos and hwtrq variables
* --------------------
*  12/15/12  7		 SAH		Updates for Mtr vel component
*  12/17/12  8		 SAH		Updates for Mtr vel component
*  12/18/12  9		 SAH		Updates for vehicle speed signal
*  01/25/13  10		 SAH		Updates for MtrTrqCmdCRF name change
*  12/12/12  11      M. Story   Udates for SER 002C
*  03/25/13  12      M. Story   Added Rte_MtrVel_SysCHandwheelVel_HwRadpS_f32
*  04/30/13  13      M. Story   Added Rte_DiagStsWIRDisable_Cnt_lgc
*  05/02/13  14		 SAH		Removed WIRDisable variable.  Already externed in CDD_Data
*  05/20/13  16      M. Story   Added Rte_SrlComInput_SrlComVehSpdValid_Cnt_lgc
*  05/29/13  17		 SAH		Removed MtrPos variables
*  06.06.13  18      M. Story   Added CanMsgReceived
*  02/27/14  19      SAH	    Cleanup
 */

#include "fpmtype.h"
#include "Compiler.h"
#include "Rte_type.h"				/* For Rte component outputs */ 


#ifndef RTE_GLOBALDATA_H
#define RTE_GLOBALDATA_H

extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_T1ADC_Volt_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_T2ADC_Volt_f32;
extern VAR(Float, RTE_VAR_NOINIT) Rte_FinalHwPos_FinHwPosAuth_Uls_f32;
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr_ResetEventStatus(void);

extern VAR(Boolean, RTE_VAR_NOINIT) Rte_SrlComInput_SrlComEngOn_Cnt_lgc;

/* PID Values */
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd_SystemState_Mode;
extern VAR(Float, RTE_VAR_NOINIT) Rte_BatteryVoltage_Vecu_Volt_f32;
/* T1
   T2*/
extern VAR(Float, RTE_VAR_NOINIT) Rte_HwTrq_AnaHwTorque_HwNm_f32;
/* P1
   P2
   P3
   P4*/
extern VAR(Float, RTE_VAR_NOINIT) Rte_Ap_AbsHwPosScom_HwPos_HwDeg_f32;
extern VAR(Float, RTE_VAR_NOINIT) Rte_Ap_AbsHwPos_SrlComHwPos_HwDeg_f32;
/* HW Pos */
extern VAR(Float, RTE_VAR_NOINIT) Rte_MtrPos_MfgMtrBasedPos_HwDeg_f32;

extern VAR(Float, RTE_VAR_NOINIT) Rte_MtrTrqLmt_MRFMtrTrqCmd_MtrNm_f32;

extern VAR(Float, RTE_VAR_NOINIT) Rte_MtrVel_MRFMotorVel_MtrRadpS_f32;
extern VAR(Float, RTE_VAR_NOINIT) Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;
extern VAR(Float, RTE_VAR_NOINIT) Rte_BatteryVoltage_Vecu_Volt_f32;
extern VAR(uint16, RTE_VAR_NOINIT)Rte_SrlComInput_ElPwDStatStrtStop_Cnt_enum;
extern VAR(uint16, RTE_VAR_NOINIT)Rte_SrlComInput_PwPckTqDStat_Cnt_enum;
extern VAR(uint8, NVM_APPL_DATA) Nvm_VINOdometer_Cnt_u8[2];
extern VAR(uint16, RTE_VAR_NOINIT) Rte_SrlComInput_EngRPM_Cnt_u16;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsDefVehSpd_Cnt_lgc;
/* chrono stack variables */
extern VAR(Float, RTE_VAR_NOINIT) Rte_Ap_ElePwr_SupplyCurrent_Amp_f32; /*added here to A*/
extern VAR(Float, RTE_VAR_NOINIT) Rte_SrlComInput_SrlComVehSpd_Kph_f32;
extern VAR(boolean, RTE_VAR_NOINIT) Rte_HwTrq_SrlComHwTrqValid_Cnt_lgc;
extern VAR(Float, RTE_VAR_NOINIT) Rte_SrlComInput_BattVolt_Volt_f32;
extern VAR(Float, RTE_VAR_NOINIT) Rte_HwTrq_AnaHwTorque_HwNm_f32;  /*added till here A*/
extern VAR(Float, RTE_VAR_INIT) Rte_CtrlTemp_FiltMeasTemp_DegC_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_MtrVel_HandwheelVel_HwRadpS_f32;
extern VAR(boolean, RTE_VAR_NOINIT) Rte_SrlComInput_HaLFFuncPresent_Cnt_lgc;
extern VAR(boolean, RTE_VAR_NOINIT) Rte_Ap_HaLFTO_HaLFActive_Cnt_lgc;
extern VAR(uint8, RTE_VAR_NOINIT) Rte_Ap_HaLFTO_HaLFState_Cnt_u08;
extern VAR(boolean, RTE_VAR_NOINIT) Rte_Ap_HaLFTO_HaLFSuspend_Cnt_lgc;
extern VAR(boolean, RTE_VAR_NOINIT) Rte_Ap_PAwTO_PrkAssistActive_Cnt_lgc;
extern VAR(uint8, RTE_VAR_NOINIT) Rte_Ap_PAwTO_PrkAssistState_Cnt_u08;
extern VAR(boolean, RTE_VAR_NOINIT) Rte_Ap_PAwTO_PrkAssistSuspend_Cnt_lgc;
extern VAR(uint8, RTE_VAR_NOINIT) Rte_Ap_StbCTO_DSTState_Cnt_u08;
extern VAR(boolean, RTE_VAR_NOINIT) Rte_SrlComInput_DSTEOLDisable_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_CtrldDisShtdn_CntDisMtrTrqCmdCRF_MtrNm_f32;
extern VAR(Float, RTE_VAR_NOINIT) Rte_HwTrq_AnaHwTorque_HwNm_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_DSTFuncPresent_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Ap_PAwTO_HandsOnDetect_Cnt_lgc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Ap_ArbLmt_ActiveFunctionBits_Cnt_u08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_PrkAsstFuncPresent_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_MtrVel_SysCHandwheelVel_HwRadpS_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_PullCompSrlComSvcDft_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComVehSpdValid_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_CanMsgReceived_Cnt_lgc;


extern VAR(uint8, AUTOMATIC) CDD_DemIdSnapshot_Cnt_G_u8; /*added by nivi*/

extern FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SetEnableTorqueOverlay(boolean Enable_Cnt_T_lgc);
extern FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_GetEnableTorqueOverlay(void);

extern FUNC(boolean, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_GetMotorTorqueValid(void);



#endif
						
