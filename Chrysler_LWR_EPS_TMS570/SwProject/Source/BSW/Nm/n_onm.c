/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */



/******************************************************************************
| Project Name: O S E K   N e t w o r k   M a n a g e m e n t
|    File Name: N_ONM.C
|
| Description: Implementation of Vector OSEK Network Management
|
| Fujitsu FFMC16LX        Softune Workbench V30L22 (inkl. Cross-Compiler V30L02)
| Fujitsu FR30            Softune V30L26
| Hitachi H8S             HEW V1.1 R3 (inkl. Cross-Compiler MCS V3.0C)
|                         HWB Core 1.3 (inkl. Cross-Compiler IAR V1.31A)
| Hitachi SH7055          HEW V1.1 R3 (inkl. Cross-Compiler MCS V5.1)
| Infineon C5x5           Keil C5X5C Compiler V5.50a
| Infineon C16x           Tasking C-Compiler V7.0 r1
|                         Keil C16X Compiler V4.03
| Micronas CEVG           Greenhills Compiler
| Mitsubishi M16C         IAR Compiler V3.15
|                         Mitsubishi Compiler NC 30 V 4.0 Rev. 1
| Motorola MC68HC05       HiTech 68HC05 Compiler, V7.50a / V7.60
| Motorola MC68HC08       COSMIC 68HC08 Compiler V4.2p
|                         HIWARE HC08 Compiler V5.0.12
| Motorola MC68HC12       COSMIC 68HC12 Compiler V4.4c
|                         IAR    68HC12 Compiler V2.10a
|                         METROWERKS Compiler for HC12 V5.0.21
| Motorola PowerPC        Diab Data v4.1 / v4.3g
| Motorola MCORE          Diab Data v4.3f
| Motorola MC68376        Tasking v9.2r0
| NEC V850                Greenhills V850 Cross-Compiler V1.8.9, Release 2.3
|                         NEC V850 Cross-Compiler V2.41f
| NEC 78K0                IAR 78k0 Cross-Compiler 3.21a 
| OKI ARM7TM              Greenhills MULTI2000 v2.0
| OKI ML66565             OKI CC665S V3.02
| OSEK-OS Emulation       Microsoft Visal C++ V6.0
| STMicroelectronics ST7  HIWARE ST7 HI-CROSS+ ANSI-C/cC++ V-5.0.4
|                         COSMIC V4.2e  
| STMicroelectronics ST9  GNU Tool chain
| STMicroelectronics ST10 Tasking C-Compiler V7.0 r1
| STMicroelectronics ARM  TDMI, Arm Developper Suit 1.01
| Texas Instrument TMS470 TI Compiler V2.01
|
|------------------------------------------------------------------------------
|               C O P Y R I G H T
|------------------------------------------------------------------------------
| Copyright (c) 2002-2012 by Vector Informatik GmbH.      All rights reserved.
|
|                    Alle Rechte an der Software verbleiben bei der
|                    Vector Informatik GmbH.
|                    Vector Informatik GmbH räumt dem Lizenznehmer das unwider-
|                    rufliche, geographisch und zeitlich nicht beschränkte,
|                    jedoch nicht ausschließliche Nutzungsrecht innerhalb des
|                    Lizenznehmers ein. Die Weitergabe des Nutzungsrechts
|                    durch den Lizenznehmers ist auf dessen Zulieferer
|                    beschränkt. Die Zulieferer sind zu verpflichten, die
|                    Software nur im Rahmen von Projekten für den Lizenznehmer
|                    zu verwenden; weitere Rechte der Zulieferer sind
|                    auszuschließen.
|------------------------------------------------------------------------------
|              A U T H O R   I D E N T I T Y
|------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     --------------------------------------
| Bs           Thomas Balster            Vector Informatik GmbH
| Ba           Bernd Baudermann          Vector Informatik GmbH
| Bd           Steffen Braendle          Vector Informatik GmbH
| Be           Christian Baeuerle        Vector Informatik GmbH
| dH           Gunnar de Haan            Vector Informatik GmbH
| Et           Thomas Ebert              Vector Informatik GmbH 
| Fr           Günther Förstner          Vector Informatik GmbH
| Fz           Ralf Fritz                Vector Informatik GmbH
| Gu           Alexander Gutlederer      Vector Informatik GmbH 
| Gz           Oliver Garnatz            Vector Informatik GmbH
| HH           Hartmut Hoerner           Vector Informatik GmbH
| Ht           Heike Honert              Vector Informatik GmbH
| Js           Bernd Jesse               Vector Informatik GmbH
| Mas          Markus Schwarz            Vector Informatik GmbH
| Ml           Patrick Markl             Vector Informatik GmbH
| Mr           Rainer Mueller            Vector Informatik GmbH
| Oh           Oliver Hornung            Vector Informatik GmbH
| Pl           Georg Pfluegel            Vector Informatik GmbH
| Rn           Jochen Rein               Vector Informatik GmbH
| Sa           Mishel Shishmanyan        Vector Informatik GmbH
| Si           Bernd Sigle               Vector Informatik GmbH
| Th           Jochen Theuer             Vector Informatik GmbH
| vismdr       Markus Drescher           Vector Informatik GmbH
|------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|------------------------------------------------------------------------------
| Date        Version  Author  Description
| ----------  -------  ------  -------------------------------------------------
| 1999-01-25  0.01.00  dH      Creation
| 1999-01-26  0.02.00  dH      first tests with C167 and VECTOR_NM succesfull
| 1999-01-27  0.03.00  dH      changes according to code review with Ba
| 1999-01-28  0.04.00  dH      optimizations
| 1999-02-01  0.05.00  HH      unchanged
| 1999-02-02  0.06.00  dH      added _0 (first step to multichannel version)
| 1999-02-03  0.08.00  dH      multichannel NM
| 1999-04-27  1.00.00  Fr      Mod. for new definition of multichanneling
| 1999-06-18  3.00.00  dH      some bugfixing within processor defines
|                              deTAB
|                      dH      bugfixing: moved some code from single to multiple
|                              -> removed all C_CLIENT_XXX
|                              C_COMP_TASKING_C16x -> C_COMP_TASKING_C16X
|                      dH      merged several branches into single source
|                              corrected some errors in the NM algorithm
|                      Ba      first official version
| 1999-07-02  3.01.00  dH      changed NmPrecopy: no statement before variable declarations
|                              added channel at CanEcuNumber&=0x1f within NmPrecopy
|                              added nmSendmess to multican define section
|                      Ba      CanInterruptDisable/Restore channel dependent
|                      Si      changes in prototype of ApplWriteWakeUpInfo
|                      Ba      CANNWM channel 0 also added for nmRecvMess macro
| 1999-12-06  3.10.00  HH      adapted to automatic gentool
| 1999-12-07  3.11.00  HH      enable selective disabling of channels by means of
|                              NM_TYPE_NONE
| 2000-02-28  3.12.00  Be      Compatibility for SINGLE_/MULTIPLE_RECEIVE_BUFFER
|                      dH      adaptation to new GenTool CANgen
|                              renamed callback functions to ApplNm...
|                              renamed timing parameters to NM_COUNT...
|                              no more #ifndef
|                              added C_COMP_HEW_SH7055
|                              added some casts to avoid compiler warnings
|                              changed C_ENABLE_MULTICAN and CANNWM to NM_CAN_CHANNEL
|                              changed NM_NumberOfConfigNodes to NM_NUMBER_OF_CONFIG_NODES
|                              changed NM_NumberOfConfigBytes to NM_NUMBER_OF_CONFIG_BYTES
| 2000-02-15  3.15.00  Mr      changes according to DC-ONM ver. 3.14d
|                      Mr      StateNetSleepInd, PreNetSleepInd (DC-ONM) implemented
|                      Mr      Userdata-Protocol (UDP for DC-ONM) implemented
| 2000-04-10  3.16.00  Fz      adaptation to new GenTool CANgen
|                              nmEcuNr->kNmEcuNr, nmTxObj->kNmTxObj, nmCanPara->kNmCanPara
|                      Rn      conditional namechanges of includefiles
| 2000-04-12           Fz      added C_COMP_NEC_V85X
| 2000-04-26           Bd      bugfix for NM_BROADCAST_ACCESS_USED with C_MULTIPLE_RECEIVE_BUFFER
| 2000-05-30  3.17.00  Gz      adaptation CanEcuNumber -> canEcuNumber
|                              changed switch for FJVGC 
| 2000-06-02  3.18.00  Et      inserted dummy assignment to avoid compiler
|                              warnings for all C_COMP_...
|                              access to SleepInd and SleepAck both by DB and by VAG
| 2000-08-17  3.19.00  Rn      delete C_SPECIAL_HC08AGATE 
|                      Gu      new CUSTOMER_SWITCH
|                      Rn      support C_MULTIPLE_RECEIVE_CHANNEL 
|                      Gu      added C_COMP_IAR_78K0 and C_COMP_HEW_H8S
|                      Gu      divided ApplCanErrorPin() into ApplCanErrorPinReceive()/Send()
|                      Js      C_COMP_MITSUBISHI_M32R added
| 2000-09-01  3.20.00  Js, Ba  Correction: ResetConfig now also works with 128 nodes
|                              bus diagnostic added
| 2000-09-04           Fz      changed NmMessType for NEC CA850 compiler  
| 2000-09-04           Js      bus diagnostics added and ringdata mechanism changed
| 2000-09-08           Gu      moved initialisation of SendMsgUser1 and SendMsgUser2
|                              added C_COMP_IAR_12 in CopyErrorBitToMess
|                              condensed union NmMessType for C_COMP_NEC_V85X
|                              added plausibility check of NM configuration
| 2000-09-20  3.21.00  Js      Ring Address (nmSendMess.c[0]) and
|                              Control Byte (nmSendMess.c[1]) initialized with 0
| 2000-09-25           Th      added support for GNU ST9
| 2000-09-27           Rn      CanInterruptDisable without Paramater with index-Can-driver
| 2000-10-09  3.22.00  Gu      Updated versions of supported compiler
| 2000-10-19           Fr      added C_COMP_ANSI_TMS_470
| 2000-11-13           Bd      added support for DIABDATA MCORE
| 2000-11-15           Gu      added variable kNmBugfixVersion Bugfix support
|                              bugfix for direct repetition in NmCanError
| 2000-11-20  3.23.00  Gu      no special treatment for C5x5C in CanError needed anymore
| 2000-11-21           Th      added support  for HIWARE ST7
| 2000-11-21           Gz      C_COMP_MITSUBISHI_NC30 -> C_COMP_MITSUBISHI_M16C 
|                              added NM_DUMMY_STATEMENT to avoid compiler warnings
| 2000-12-18  3.24.00  Gu      C_COMP_KEIL_C16x -> C_COMP_KEIL_C16X
| 2000-01-08           Gu      changed instruction in state NM_ACTION_START to avoid compiler warnings 
|                              NM_DBAG_... -> NM_TYPE_DBAG
|                              added condition for old DC_ONM define to ensure compilation of header
| 2001-02-14           Rn      added channel 4, correction in channel 1,2,3
|                      Gu      changed instruction in function NmTask to avoid compiler warnings 
| 2001-02-22  3.25.00  Rn      bugfix: CanReset... for indexed-Can-driver with paramter 
|                              NM_CAN_CHANNEL (ESCAN00000463)
| 2001-02-23  3.26.00  Bs      Greenhils MULTI2000 for OKI ARM7TM added / C_COMP_GHS_ARM7TM
| 2001-03-01           Gu      Deleted MEMORY_ROM assigment for multiple ECU declaration
| 2001-03-19  3.27.00  Gu      no special treatment for C5x5C in NmTask needed anymore
|                              changed dummy statement für M16C in NmConfirmation
|                              added plausibility check for include structure
|                              deleted old DC define
|                              moved compatibility mode of nmEcuNr->kNmEcuNr, nmTxObj->kNmTxObj, 
|                              nmCanPara->kNmCanPara into NM_CFG.H, Source also changed
| 2001-04-06           Gu      added new Customer switch
|                              added extended NM Callbacks
| 2001-04-06           Sa      added Dummy Statement to avoid compiler warnings for NEC 78K0 
|                              and nested comment fix.
| 2001-04-09           Pl      added support for ARM7TDMI
|                      Gu      changed compatibility mode for older versions of Gen-Tool
| 2001-04-19  3.28.00  Gu      added Dummy Statement to avoid compiler warnings
|                              for KEIL C16X Compiler
| 2001-04-26  3.29.00  Gu      XPAGE setting for C_COMP_KEIL_C5x5 removed due to CAN LI1.2 support
|                      Bs      ESCAN00000677: support of C_COMP_OKI_CC665S added in source file
| 2001-06-08  3.30.00  Ba, Js  ESCAN00000792: Implementation for indexed usage of the NM
|                              ESCAN00000560: wrong param for callback for indexed
|                                             CAN-Driver fixed
| 2001-07-16  3.31.00  Ht      ESCAN00000867: support for C_SINGLE_RECEIVE_CHANNEL added
|                      Gu      ESCAN00000835: Changed pChipDataPtr to CanChipDataPtr which
|                                             was changed in reference implementation 1.1
|                                             of the CAN Driver
|                              ESCAN00000875: Wrong assigment of #define TargetErrorConfig changed
|                              ESCAN00000876: changed instruction in function ReadBroadcastData
|                                             to avoid compiler warnings
|                              ESCAN00000927: refer next line
|                              ESCAN00000930: changed instruction in function ResetConfig 
|                                             and ResetErrorConfig to avoid compiler warnings
|                              ESCAN00000928: code for time-measurement added
|                              ESCAN00000931: Missing define for PAG added when using 128 nodes
|                              ESCAN00000570: Vector NM now also works with 128 nodes
|                              ESCAN00001039: tempCanRxActualDLC dependens not only
|                                             of NM_BROADCAST_ACCESS_USED
|                              ESCAN00000980: Adaptions for Ford
| 2001-07-27  3.32.00  Gu      ESCAN00001055: DLC-check in tempCanRxActualDLC optimized
|                      Rn      ESCAN00001055: tempCanRxActualDLC deleted
|                      Ml      ESCAN00001069: added cast to avoid HC12 compiler errors
|                                             when using -pck option
|                      Rn      ESCAN00001068: fixed compiler error in case of indexed
|                                             CAN-Driver and DC Userdata
|                      Gu      ESCAN00001072: Added some casts to avoid warning when
|                                             using strict typechecking
| 2001-08-03  3.33.00  Gu                     no changes
|                      Js      ESCAN00001229: C_COMP_TASKING_MC376 added
| 2001-08-23  3.34.00  Gu      ESCAN00001284: Bugfix in case of using the Ford-NM
| 2001-08-30  3.35.00  Ba      ESCAN00001358: Support of Hiware compiler with Motorola HC08
| 2001-09-03  3.36.00  Gu      ESCAN00001375: Special inquiry in case
|                                             NM_NUMBER_OF_CONFIG_NODES is not used
| 2001-09-12  3.37.00  Gu      ESCAN00001446: Incomplete statement in case of using
|                                             STM ST7 and indexed NM corrected
|                      Gu      ESCAN00001463: Support for extended Userdata Access
| 2001-09-21  3.38.00  Gu      ESCAN00001480: added new and deleted some old compiler switches
|                      Gu, Js  ESCAN00001468: temporary buffer for userdata access
|                                             used for BMW
|                      Gu      ESCAN00001516: udinit and udtask changed to UdInit and UdTask
| 2001-10-25  3.39.00  Gu      ESCAN00001688: Change in bus-off handling for Ford NOS
| 2001-11-01  3.40.00  Rn      ESCAN00001731: added missing brackets for userdata DC
| 2001-11-05           Gu      ESCAN00001733: Fixed another incomplete code line
|                                             using STM ST7
|                              ESCAN00001712: changed switch from C_COMP_<xxx>_SH7055
|                                             to  C_COMP_<xxx>_SH705X
|                              ESCAN00001736: Additional Micro Support for NM C_COMP_COSMIC_ST7_BECAN
|                              ESCAN00001737: Corrected some comments
|                              ESCAN00001738: no changes
| 2001-11-07           Rn      ESCAN00001748: DC-Userdata: clear nmpdu in case of limphome
|                              ESCAN00001749: GW-Support: code before definition
| 2001-11-29           Gu      ESCAN00001842: DC-Userdata: notification of userdata
|                                             service in case ECU is not addressed
| 2001-12-13           Gu      ESCAN00001901: Remove compiler specific definition
|                                             of bit fields
|                              ESCAN00001917: Adapted call of function ApplWriteWakeUpInfo
|                                             in C-File according to Header-File
| 2002-01-03  3.41.00  Ml      ESCAN00001855: Added keywords for paging support
| 2002-01-15           Gu      ESCAN00002062: ApplWriteWakeUpInfo does not support
|                                             MEMORY_NEAR for Hiware Compiler
| 2002-01-22  3.42.00  Gu      ESCAN00002111: New features according to the new
|                                             specification of a car manufacturer
|                      Js      ESCAN00002210: no changes
| 2002-03-04  3.43.00  Js      ESCAN00002413: no changes
|                              ESCAN00002757: no changes
|                      Gu      ESCAN00001900: Added typecast's for NM send buffer to
|                                             avoid linker warnings
|                              ESCAN00004445: During execution of GotoMode(): Possible loss
|                                             of sleep / wakeup information
|                              ESCAN00002759: Corrected bus-off handling for Ford NOS
|                              ESCAN00002760: Type nmAction has been changed from
|                                             enum to canuint8 to avoid compiler warnings
|                              ESCAN00002807: Insert interrupt protection in API
|                                             functions to ensure data consistency
| 2002-05-24  3.44.00  Fz      ESCAN00002926: nmSendMess array aligned to two bytes
|                                             for V850 with NEC compiler
| 2002-06-18           Et      ESCAN00003089: support of physical multiple ECUs
| 2002-07-17                   ESCAN00002926: nmSendMess array aligned to two bytes
|                                             for 16-/32-bit MCUs
| 2002-07-25           Js      ESCAN00002906: UdTask() and UdInit() renamed to
|                                             ApplNmUserDataTask() and ApplUserDataInit()
| 2002-11-11  3.45.00  Js      ESCAN00004146: C-Library functions not longer used
|                              ESCAN00004247: Rx/Tx Inversion resolution
|                              ESCAN00004259: Delayed state transition or during execution of
|                                             GotoMode(): Possible loss of sleep information
|                              ESCAN00004328: CanOnline() added to NM_ACTION_START in NmTask()
|                              ESCAN00004376: Formal changes
|                              ESCAN00004286: kNmEcuNr handling for indexed NM
|                                             according to implementation of
|                                             ESCAN00003089 corrected
|                              ESCAN00003323: Lint warnings removed
|                              ESCAN00004441: Wrong access to UD receive message command
|                              ESCAN00002357  AND
|                              ESCAN00004163: Some compiler produces warning on dummy statements
|                                             V_ENABLE_USE_DUMMY_STATEMENT inserted
|                              ESCAN00004500: Further status functions according to ESCAN00004259
|                              ESCAN00004601: To less copy and initialization of User Data for
|                                             NM_TYPE_VECTOR_OSEK
|                              ESCAN00004607: No Skipped Alive for a special Ring Message
| 2003-02-22  3.46.00  Js      ESCAN00004844: DC Userdata support will not compile in a code
|                                             doubled system
| 2003-03-17  3.47.00  Js      ESCAN00005108: Wrong definition of SendMessFlag and NmStateTypeDcUd
|                                             for C5X5
| 2003-03-28  3.48.00  Js      ESCAN00005245: No CanInterruptRestore() in ReadRingData()
|                                             for special OEM
|                              ESCAN00005246: MEMORY_CAN inserted
|                                             SINGLE_RECEIVE_BUFFER and MULTIPLE_RECEIVE_BUFFER
|                                             deleted
|                              ESCAN00003524: Memory qualifier for zero page mapping
|                                             for C_COMP_HIWARE_08
| 2003-05-06  3.49.00  Js      ESCAN00005573: Warning removed
| 2003-06-17  3.50.00  Js      ESCAN00004601: To less copy and initialization of User Data for
|                                             NM_TYPE_VECTOR_OSEK
| 2003-09-03  3.51.00  Js      ESCAN00006420: OSEK NM send message has incorrect data
|                                             due to alignment problem
| 2003-10-06  3.52.00  Js      ESCAN00006646: New features (2nd step) according to the new
|                                             specification of a car manufacturer
|                              ESCAN00006727: Error Pin detection does not work on
|                                             indexed multi channel NM for special OEM
|                              ESCAN00006769: No WakeUp after BusSleep for Ring Message
|                                             with set Sleep Indication
|                              ESCAN00005970: canChannel for Multiple ECUs with
|                                             indirection not defined
|                              ESCAN00006771: Amount of User Data changed for
|                                             special OEM
|                              ESCAN00006891: nmSendMess now fix on 8 byte
|                              ESCAN00006916: canEcuNumber not longer used
| 2003-11-27  3.53.00  Js      ESCAN00007008: WakeUp Type Indication for a car manufacturer added
|                              ESCAN00007091: Changes according GENy introduction
|                              ESCAN00007216: User Data extracted for special car manufacturer
|                              ESCAN00007217: Generic NM adaptation API introduced
|                              ESCAN00006970: Warning is generated "canChannel not used"
|                              ESCAN00006361: Prepare Sleep Counter for Indexed Systems
|                              ESCAN00007275: Possible compiler report for truncating assignment
|                              ESCAN00007287: Error Configuration mismatch for special
|                                             car manufacturer
| 2004-01-28  3.54.00  Js      ESCAN00007369: ONMX send data access changed
|                              ESCAN00007382: Cosmic HC(S)12 issue fix
| 2004-02-13  3.55.00  Rn      ESCAN00007561: Include v_inc.h instead of can_inc.h in case of GENy
| 2004-02-17  3.56.00  Js      ESCAN00007430: Remote Sleep Indication adapted
|                              ESCAN00007436: ESCAN00006769 moved to NmPrecopy
|                              ESCAN00007437: ESCAN00007008 reworked for wait bus sleep
| 2004-03-11  3.57.00  Js      ESCAN00007856: Faster solution for ESCAN00004247
|                              ESCAN00007535: Multiple calls of ApplNmWaitBusSleep when
|                                             multiply receiving RING messages with set SleepAck
|                              ESCAN00007530: Compiler Warning for GetConfig() and CmpConfig()
|                              ESCAN00007822: Warning about unreferenced variable 'channel'
|                              ESCAN00007866: Usage of Multiple ECU for special configuration
| 2004-04-05  3.58.00  Js      ESCAN00007954: no changes
|                              ESCAN00008104: Unexpected copy of User Data
|                              ESCAN00008229: Optimization of UD handling for special
|                                             car manufacturer
|                              ESCAN00008463: Tx path activation to late after cancel
|                                             of TwaitBusSleep
|                              ESCAN00008466: Feature review and rework
|                              ESCAN00008489: Formal adaptations for specific car manufacturer
| 2004-06-29  3.59.00  Js      ESCAN00008585: no changes
|                              ESCAN00008665: Usage of temp. buffer for indexed C16x driver
| 2004-10-01  3.60.00  Js      ESCAN00009420: The ECU does not transmit any message
|                                             except NM messages
|                              ESCAN00009728: New Version Defines introduced
|                              ESCAN00009711: BusOff Flag remains active
| 2004-10-14  3.61.00  Js      ESCAN00009728: New Version Defines introduced
| 2004-10-29  3.62.00  Js      ESCAN00010055: Wrong context of CanOffline
| 2004-11-29  3.63.00  Js      ESCAN00010415: Support of 256 nodes
|                              ESCAN00010454: Config algorithm equal for all OEMs
|                              ESCAN00010455: no changes
|                              ESCAN00010456: C_COMP_HITECH_05 removed
|                              ESCAN00010463: Fast BusOff recovery introduced
|                              ESCAN00010468: Extensions for special OEM removed
|                              ESCAN00010471: no changes
|                              ESCAN00010498: Wrong Fast BusOff recovery time
| 2005-01-18  3.64.00  Js      ESCAN00010855: CarWakeUp for special OEM introduced
| 2005-11-14  3.64.01  Bus     ESCAN00012702: insert comments for different resource categories
| 2006-02-17  3.64.02  Mas     ESCAN00015398: adapted memory qualifiers in header file
| 2006-06-23  3.64.03  Mas     ESCAN00015719: adapted type qualifier in header file
| 2006-11-20  3.64.04  Mas     ESCAN00017962: added reset of limphome status
| 2007-01-09  3.64.05  Mas     ESCAN00018853: no changes
| 2007-05-22  3.64.06  Mas     ESCAN00020303: no changes
|                              ESCAN00020580: removed compiler warnings for kNmEcuNr == 0x00
| 2007-06-05  3.64.07  Mas     ESCAN00020990: changed handling of solution for ESCAN00020580
|                              ESCAN00021051: added BusOff end handling for RX of SleepAck in LimpHome
| 2007-09-20  3.64.08  Mas     ESCAN00014458: adapted NmConfirmation for usage in indexed, multipleEcu systems
| 2007-10-09  3.64.09  Mas     ESCAN00022178: no changes in this file
| 2008-08-05  3.64.10  Oh      ESCAN00029003: corrected declarations of version constants
| 2008-10-20  3.64.11  Mas     ESCAN00030171: moved platform-specific definition of MEMORY_CAN
| 2009-05-15  3.64.12  Mas     ESCAN00028757: added support for QNX
|                      Mas     ESCAN00028089: changed encpasulation of condition for update of NM node table
|                      Mas     ESCAN00033467: removed compiler warning for condition that is always true
| 2009-12-03  3.64.13  Mas     ESCAN00035150: corrected NM message reception for invalid messages
| 2010-12-21  3.64.14  vismdr  ESCAN00014119: changed implementation of SkippedAlive
| 2011-10-05  3.64.15  vismdr  ESCAN00047102: ignore NmConfirmation() calls when bus off state is active
| 2012-01-02  3.64.16  vismas  ESCAN00055784: Added API NmSetInitObject
|                              ESCAN00046063: Corrected QNX NmSetModuleContext
| 2012-06-25  3.64.17  vismdr  ESCAN00059554: Adapted declaration of nmSendMess
|*****************************************************************************/

/******************************************************************************
Include files
******************************************************************************/
/* used for nm internal */
#define OSEK_NM_MODULE

#include "v_cfg.h"
#if defined ( VGEN_GENY )
#include "v_inc.h"
#else
#include "can_inc.h"
#endif

#include "n_onmdef.h"

/*lint -e539*/ /* Did not expect positive indentation from line ... */
/*lint -e655*/ /* Warning 655: bit-wise operation uses (compatible) enum's */
/*lint -e750*/ /* local macro ... not referenced */

/***************************************************************************/
/* Plausibility check of include structure                                 */
/***************************************************************************/
#if defined ( NM_CFG_H )
#else
  #error "Configuration error in NM_DIROSEK: Please include the generated NM_CFG.H in your adapted CAN_INC.H!"
#endif

/*****************************************************************************/
/* Version check                                                             */
/*****************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject : Nm_DirOsek CQComponent : Implementation */
#if ( NM_DIROSEK_VERSION != 0x0364u )
  #error "Configuration error in NM_DIROSEK: Header and Source file are inconsistent!"
#endif
#if ( NM_DIROSEK_RELEASE_VERSION != 0x17u )
  #error "Configuration error in NM_DIROSEK: Different versions of Bugfix in Header and Source used!"
#endif

/*****************************************************************************/
/* Timing Measurement Module                                                 */
/*****************************************************************************/
#if defined ( TIMING_MEASUREMENT )
#else
  #if defined ( StartMeasure )
  #else
    #define StartMeasure(i)
  #endif

  #if defined ( StopMeasure )
  #else
    #define StopMeasure(i)
  #endif
#endif

/*****************************************************************************/
/* Defines                                                                   */
/*****************************************************************************/

#if defined ( C_CPUTYPE_8BIT )
  #define kNmSendMessSize 8
  #define kNmSendMessType canuint8
#else
  #if defined ( C_CPUTYPE_16BIT )
    #define kNmSendMessSize 4
    #define kNmSendMessType canuint16
  #else
    #if defined ( C_CPUTYPE_32BIT )
      #define kNmSendMessSize 2
      #define kNmSendMessType canuint32
    #else
      #error "Configuration error in NM_DIROSEK: Missing C_CPUTYPE_xBIT for valid alignment of NmSendMess!"
    #endif
  #endif
#endif

/* multi channel can driver */
#if defined ( C_SINGLE_RECEIVE_BUFFER ) || defined ( C_MULTIPLE_RECEIVE_BUFFER )
 #if defined ( NM_CAN_CHANNEL )
  #if ( NM_CAN_CHANNEL == 0 )
    #define CanRxActualId          CanRxActualId_0
    #define CanTransmit            CanTransmit_0
    #define CanResetBusOffStart(a) CanResetBusOffStart_0(a)
    #define CanResetBusOffEnd(a)   CanResetBusOffEnd_0(a)
    #define CanResetBusSleep(a)    CanResetBusSleep_0(a)
    #define CanOffline             CanOffline_0
    #define CanOnline              CanOnline_0
    #define CanInterruptDisable    CanInterruptDisable_0
    #define CanInterruptRestore    CanInterruptRestore_0
    #define CanRxActualDLC         CanRxActualDLC_0
    #define NmConfirmation         NmConfirmation_0
    #define NmPrecopy              NmPrecopy_0
    #define NmCanError             NmCanError_0
    #define nmSendMess             nmSendMess_0
  #endif /* #if ( NM_CAN_CHANNEL == 0 ) */
  #if ( NM_CAN_CHANNEL == 1 )
    #define CanRxActualId          CanRxActualId_1
    #define CanTransmit            CanTransmit_1
    #define CanResetBusOffStart(a) CanResetBusOffStart_1(a)
    #define CanResetBusOffEnd(a)   CanResetBusOffEnd_1(a)
    #define CanResetBusSleep(a)    CanResetBusSleep_1(a)
    #define CanOffline             CanOffline_1
    #define CanOnline              CanOnline_1
    #define CanInterruptDisable    CanInterruptDisable_1
    #define CanInterruptRestore    CanInterruptRestore_1
    #define CanRxActualDLC         CanRxActualDLC_1
    #define NmConfirmation         NmConfirmation_1
    #define NmPrecopy              NmPrecopy_1
    #define NmCanError             NmCanError_1
    #define nmSendMess             nmSendMess_1
  #endif /* #if ( NM_CAN_CHANNEL == 1 ) */
  #if ( NM_CAN_CHANNEL == 2 )
    #define CanRxActualId          CanRxActualId_2
    #define CanTransmit            CanTransmit_2
    #define CanResetBusOffStart(a) CanResetBusOffStart_2(a)
    #define CanResetBusOffEnd(a)   CanResetBusOffEnd_2(a)
    #define CanResetBusSleep(a)    CanResetBusSleep_2(a)
    #define CanOffline             CanOffline_2
    #define CanOnline              CanOnline_2
    #define CanInterruptDisable    CanInterruptDisable_2
    #define CanInterruptRestore    CanInterruptRestore_2
    #define CanRxActualDLC         CanRxActualDLC_2
    #define NmConfirmation         NmConfirmation_2
    #define NmPrecopy              NmPrecopy_2
    #define NmCanError             NmCanError_2
    #define nmSendMess             nmSendMess_2
  #endif /* #if ( NM_CAN_CHANNEL == 2 ) */
  #if ( NM_CAN_CHANNEL == 3 )
    #define CanRxActualId          CanRxActualId_3
    #define CanTransmit            CanTransmit_3
    #define CanResetBusOffStart(a) CanResetBusOffStart_3(a)
    #define CanResetBusOffEnd(a)   CanResetBusOffEnd_3(a)
    #define CanResetBusSleep(a)    CanResetBusSleep_3(a)
    #define CanOffline             CanOffline_3
    #define CanOnline              CanOnline_3
    #define CanInterruptDisable    CanInterruptDisable_3
    #define CanInterruptRestore    CanInterruptRestore_3
    #define CanRxActualDLC         CanRxActualDLC_3
    #define NmConfirmation         NmConfirmation_3
    #define NmPrecopy              NmPrecopy_3
    #define NmCanError             NmCanError_3
    #define nmSendMess             nmSendMess_3
  #endif /* #if ( NM_CAN_CHANNEL == 3 ) */
  #if ( NM_CAN_CHANNEL == 4 )
    #define CanRxActualId          CanRxActualId_4
    #define CanTransmit            CanTransmit_4
    #define CanResetBusOffStart(a) CanResetBusOffStart_4(a)
    #define CanResetBusOffEnd(a)   CanResetBusOffEnd_4(a)
    #define CanResetBusSleep(a)    CanResetBusSleep_4(a)
    #define CanOffline             CanOffline_4
    #define CanOnline              CanOnline_4
    #define CanInterruptDisable    CanInterruptDisable_4
    #define CanInterruptRestore    CanInterruptRestore_4
    #define CanRxActualDLC         CanRxActualDLC_4
    #define NmConfirmation         NmConfirmation_4
    #define NmPrecopy              NmPrecopy_4
    #define NmCanError             NmCanError_4
    #define nmSendMess             nmSendMess_4
  #endif /* #if ( NM_CAN_CHANNEL == 4 ) */
 #endif /* defined ( NM_CAN_CHANNEL ) */
#endif /* defined ( C_SINGLE_RECEIVE_BUFFER ) || defined ( C_MULTIPLE_RECEIVE_BUFFER ) */

#if defined ( NM_ENABLE_CONFIG )
#define BYTE_OFFSET_MASK           ((canuint8)0x07) /* Used for config */
#endif

/* used for handling rx and tx counter */
#define RX_CNT_MASK                ((canuint8)0x0F) /* Low-Nibble  of nmRxTxCnt */
#define TX_CNT_MASK                ((canuint8)0xF0) /* High-Nibble of nmRxTxCnt */
#define TX_CNT_STEP                ((canuint8)0x10)
#define RX_CNT_STEP                ((canuint8)0x01)
#define RX_CNT_MAX                 ((canuint8)4)
#define TX_CNT_MAX                 ((canuint8)8)

/*---- Variable for storing the current state for the Network Management state machine ----------------------*/
typedef canuint8 NmActionType;

/*---- Definition of the different states of Network Management state machine  ----------------------*/
#define NO_ACTION                     ((NmActionType)0x00)
#define NM_ACTION_START               ((NmActionType)0x01)
#define NM_ACTION_WAIT_SENDTOKEN      ((NmActionType)0x02)
#define NM_ACTION_WAIT_RINGMSG        ((NmActionType)0x03)
#define NM_ACTION_LH_WAIT_LIMPHOME_TX ((NmActionType)0x04)
#define NM_ACTION_LH_PREPARE_SLEEP    ((NmActionType)0x05)
#define NM_ACTION_GO_BUSSLEEP         ((NmActionType)0x06)
#define NM_ACTION_BUS_SLEEP           ((NmActionType)0x07)
#define NM_ACTION_REPEAT              ((NmActionType)0x80)


/* ROM CATEGORY 4 START*/
V_MEMROM0 V_MEMROM1 canuint8 V_MEMROM2 kNmMainVersion   = (canuint8)(NM_DIROSEK_VERSION >> 8);
V_MEMROM0 V_MEMROM1 canuint8 V_MEMROM2 kNmSubVersion    = (canuint8)(NM_DIROSEK_VERSION & 0xFF);
V_MEMROM0 V_MEMROM1 canuint8 V_MEMROM2 kNmBugfixVersion = (canuint8)(NM_DIROSEK_RELEASE_VERSION);
/* ROM CATEGORY 4 END*/


/*  *****   STOPSINGLE_OF_MULTIPLE_COMMENT    *****  */


/*****************************************************************************
*
*
*      HEADER-Part for NM channel 
*
*
******************************************************************************/



/*---- Defines for NM message bits ------------------------------------------*/
#if defined ( NM_TYPE_DBAG_OSEK )
  #define ALIVE                     ((canuint8)0x0E)
  #define RING                      ((canuint8)0x0D)
  #define LIMPHOME                  ((canuint8)0x0C)
  #define CTRL_INIT                 ((canuint8)0xFF)
  #define DATA_INIT                 ((canuint8)0xFF)

  #define UD_CMD_MASK               ((canuint8)0x3F)
  #define NM_SLEEP_CMD_MASK         ((canuint8)~UD_CMD_MASK)
#else /* NM_TYPE_DBAG_OSEK */
  #define CTRL_INIT                 ((canuint8)0x00)

    #define DATA_INIT               ((canuint8)0x00)

    #define ALIVE                   ((canuint8)0x01)
    #define RING                    ((canuint8)0x02)
    #define LIMPHOME                ((canuint8)0x04)
#endif /* NM_TYPE_DBAG_OSEK */

/***************************************************************************/
/* Defines for Receive Handling                                            */
/***************************************************************************/

/* Masks for Receiver CAN-ID Handling - only valid in NmPrecopy() */
#if defined ( VGEN_GENY )
  #if defined ( NM_ENABLE_INDEXED_NM )
    #if ( kNmNumberOfRanges > 1 )
      #define kNmSourceMask (NmRangeMask_Field[channel])  /* Dynamic node mask */
    #else
      #define kNmSourceMask ((canuint8)NM_RANGE_MASK) /* Dynamic node mask */
    #endif
  #else
    #define kNmSourceMask   ((canuint8)NM_RANGE_MASK) /* Dynamic node mask */
  #endif
#else
    #if defined ( NM_TYPE_DBAG_OSEK )
      #define kNmSourceMask ((canuint8)0x3F)              /*  64 nodes */  
    #else
      #define kNmSourceMask ((canuint8)0x7F)              /* 128 nodes */  
    #endif
#endif

/* Receiver CAN-ID Handling - only valid in NmPrecopy() */
#if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) || defined ( C_SINGLE_RECEIVE_CHANNEL )
  #define GetNmSourceAddress ((canuint8)((canuint8)(CanRxActualId(rxStruct)) & kNmSourceMask))
#else
  #define GetNmSourceAddress ((canuint8)((canuint8)(CanRxActualId      ) & kNmSourceMask))
#endif

/* Define Rx buffer access */ 
#define RecvSleepInd      nmRecvMess.b.bSleepInd
#define RecvSleepAck      nmRecvMess.b.bSleepAck

#if defined ( NM_TYPE_DBAG_OSEK )
  #define RecvMessCmd     nmRecvMess.b.cCmd
  #define NmDestAddress   nmRecvMess.c[1]
  #define RecvMsgSleep    nmRecvMess.c[2]

  #define RecvMsgUser0    nmRecvMess.c[3]
  #define RecvMsgUser1    nmRecvMess.c[4]
  #define RecvMsgUser2    nmRecvMess.c[5]
  #define RecvMsgUser3    nmRecvMess.c[6]
  #define RecvMsgUser4    nmRecvMess.c[7]
#else /* NM_TYPE_DBAG_OSEK */
  #define NmDestAddress   nmRecvMess.c[0]
  #define RecvMessCmd     nmRecvMess.b.cCmd

  #define RecvMsgUser0    nmRecvMess.c[2]
  #define RecvMsgUser1    nmRecvMess.c[3]
  #define RecvMsgUser2    nmRecvMess.c[4]
  #define RecvMsgUser3    nmRecvMess.c[5]
  #define RecvMsgUser4    nmRecvMess.c[6]
  #define RecvMsgUser5    nmRecvMess.c[7]
#endif /* NM_TYPE_DBAG_OSEK */


/*---- Receive buffer for NM messages (on - chip receive buffer ) -----------*/

#if defined ( C_SINGLE_RECEIVE_BUFFER )
  #if defined ( NM_CAN_CHANNEL )
    #if ( NM_CAN_CHANNEL == 0 )
      #define nmRecvMess      (*(NmMessTypeUnion MEMORY_CAN*)CanRDSPtr_0)
    #endif
    #if ( NM_CAN_CHANNEL == 1 )
      #define nmRecvMess      (*(NmMessTypeUnion MEMORY_CAN*)CanRDSPtr_1)
    #endif
    #if ( NM_CAN_CHANNEL == 2 )
      #define nmRecvMess      (*(NmMessTypeUnion MEMORY_CAN*)CanRDSPtr_2)
    #endif
    #if ( NM_CAN_CHANNEL == 3 )
      #define nmRecvMess      (*(NmMessTypeUnion MEMORY_CAN*)CanRDSPtr_3)
    #endif
  #else /* NM_CAN_CHANNEL */
    #define nmRecvMess    (*(NmMessTypeUnion MEMORY_CAN*)(CanRDSPtr))
  #endif /* NM_CAN_CHANNEL */
#endif /* C_SINGLE_RECEIVE_BUFFER */

#if defined ( C_MULTIPLE_RECEIVE_BUFFER )
    #define nmRecvMess    (*(NmMessTypeUnion MEMORY_CAN *)(rxDataPtr))
#endif /* C_MULTIPLE_RECEIVE_BUFFER */

#if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) || defined ( C_SINGLE_RECEIVE_CHANNEL )
    #define nmRecvMess    (*(NmMessTypeUnion MEMORY_CAN *)(rxStruct->pChipData))
#endif


/*****************************************************************************/
/* Data types / enumerations                                                 */
/*****************************************************************************/

/*---- NM  state  in byte 0; flags in byte 1 --------------------------------*/
typedef union               /* c[0]:  07 06 04 03 02 01 00 :mem    net state */
{                           /* c[1]:  17 16 14 13 12 11 10 :mem+1  flags     */
  canuint8 c[2];

  #if defined ( C_CPUTYPE_BITORDER_MSB2LSB )
  struct
  {
    canbittype    b_BusSleepInd     :1;     /* byte 0 bit 7 */
    canbittype    b_TxRingDataAllow :1;     /* byte 0 bit 6 */
    canbittype    b_WaitBusSleep    :1;     /* byte 0 bit 5 */
    canbittype    b_BusSleep        :1;     /* byte 0 bit 4 */
    canbittype    b_LimpHome        :1;     /* byte 0 bit 3 */
    canbittype    b_Active          :1;     /* byte 0 bit 2 */
    canbittype    b_BusError        :1;     /* byte 0 bit 1 */
    canbittype    b_RingStable      :1;     /* byte 0 bit 0 */

    canbittype    b_PrepSleep       :1;     /* byte 1 bit 7 */
    canbittype    b_RingPreStable   :1;     /* byte 1 bit 6 */
    canbittype    b_RxTxLockUd      :1;     /* byte 1 bit 5 */  /* ESCAN00008104 */
    canbittype    b_NmMsgRecvRemind :1;     /* byte 1 bit 4 */
    canbittype    b_ImSkippedOver   :1;     /* byte 1 bit 3 */
    canbittype    b_ImAddressed     :1;     /* byte 1 bit 2 */
    canbittype    b_RingMsgRecv     :1;     /* byte 1 bit 1 */
    canbittype    b_NmMsgRecv       :1;     /* byte 1 bit 0 */
  }b;
  #else
    #if defined ( C_CPUTYPE_BITORDER_LSB2MSB )
  struct
  {
    canbittype    b_RingStable      :1;     /* byte 0 bit 0 */
    canbittype    b_BusError        :1;     /* byte 0 bit 1 */
    canbittype    b_Active          :1;     /* byte 0 bit 2 */
    canbittype    b_LimpHome        :1;     /* byte 0 bit 3 */
    canbittype    b_BusSleep        :1;     /* byte 0 bit 4 */
    canbittype    b_WaitBusSleep    :1;     /* byte 0 bit 5 */
    canbittype    b_TxRingDataAllow :1;     /* byte 0 bit 6 */
    canbittype    b_BusSleepInd     :1;     /* byte 0 bit 7 */

    canbittype    b_NmMsgRecv       :1;     /* byte 1 bit 0 */
    canbittype    b_RingMsgRecv     :1;     /* byte 1 bit 1 */
    canbittype    b_ImAddressed     :1;     /* byte 1 bit 3 */
    canbittype    b_ImSkippedOver   :1;     /* byte 1 bit 4 */
    canbittype    b_NmMsgRecvRemind :1;     /* byte 1 bit 6 */
    canbittype    b_RxTxLockUd      :1;     /* byte 1 bit 5 */  /* ESCAN00008104 */
    canbittype    b_RingPreStable   :1;     /* byte 1 bit 6 */
    canbittype    b_PrepSleep       :1;     /* byte 1 bit 7 */
  }b;
    #else 
      #error "Configuration error in NM_DIROSEK: Missing bitorder for typedef NmStateType!"
    #endif
  #endif
}NmStateType;

#if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION ) || defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
typedef union
{
  canuint8 c[2];

  #if defined ( C_CPUTYPE_BITORDER_MSB2LSB )
  struct
  {
    canbittype    b_Dummy0_7            :1;     /* byte 0 bit 7 */
    canbittype    b_Dummy0_6            :1;     /* byte 0 bit 6 */
    canbittype    b_Dummy0_5            :1;     /* byte 0 bit 5 */
    canbittype    b_Dummy0_4            :1;     /* byte 0 bit 4 */
    canbittype    b_Dummy0_3            :1;     /* byte 0 bit 3 */
    canbittype    b_PrepareSendSleepAck :1;     /* byte 0 bit 2 */
    canbittype    b_RemoteSleepInd      :1;     /* byte 0 bit 1 */
    canbittype    b_RemotePrepareSleep  :1;     /* byte 0 bit 0 */

    canbittype    b_Dummy1_7            :1;     /* byte 1 bit 7 */
    canbittype    b_Dummy1_6            :1;     /* byte 1 bit 6 */
    canbittype    b_Dummy1_5            :1;     /* byte 1 bit 5 */
    canbittype    b_Dummy1_4            :1;     /* byte 1 bit 4 */
    canbittype    b_Dummy1_3            :1;     /* byte 1 bit 3 */
    canbittype    b_Dummy1_2            :1;     /* byte 1 bit 2 */
    canbittype    b_Dummy1_1            :1;     /* byte 1 bit 1 */
    canbittype    b_Dummy1_0            :1;     /* byte 1 bit 0 */
  }b;
  #else
    #if defined ( C_CPUTYPE_BITORDER_LSB2MSB )
  struct
  {
    canbittype    b_RemotePrepareSleep  :1;     /* byte 0 bit 0 */
    canbittype    b_RemoteSleepInd      :1;     /* byte 0 bit 1 */
    canbittype    b_PrepareSendSleepAck :1;     /* byte 0 bit 2 */
    canbittype    b_Dummy0_3            :1;     /* byte 0 bit 3 */
    canbittype    b_Dummy0_4            :1;     /* byte 0 bit 4 */
    canbittype    b_Dummy0_5            :1;     /* byte 0 bit 5 */
    canbittype    b_Dummy0_6            :1;     /* byte 0 bit 6 */
    canbittype    b_Dummy0_7            :1;     /* byte 0 bit 7 */

    canbittype    b_Dummy1_0            :1;     /* byte 1 bit 0 */
    canbittype    b_Dummy1_1            :1;     /* byte 1 bit 1 */
    canbittype    b_Dummy1_2            :1;     /* byte 1 bit 2 */
    canbittype    b_Dummy1_3            :1;     /* byte 1 bit 3 */
    canbittype    b_Dummy1_4            :1;     /* byte 1 bit 4 */
    canbittype    b_Dummy1_5            :1;     /* byte 1 bit 5 */
    canbittype    b_Dummy1_6            :1;     /* byte 1 bit 6 */
    canbittype    b_Dummy1_7            :1;     /* byte 1 bit 7 */
  }b;
      #else 
        #error "Configuration error in NM_DIROSEK: Missing bitorder for typedef NmStateTypeGwMaster!"
      #endif
    #endif
}NmStateTypeGwMaster;
#endif  /* NM_ENABLE_SLEEPACK_NOTIFICATION || NM_ENABLE_REMOTESLEEP_INDICATION */

typedef union
{
  canuint8 c[8];

  #if defined ( C_CPUTYPE_BITORDER_MSB2LSB )
  struct
  {
    #if defined ( NM_TYPE_DBAG_OSEK )
    canbittype cReserved0     :4;   /* bit  7...4 ; bit 7...4 Byte 0        */
    canbittype cCmd           :4;   /* bit  3...0 ; bit 3...0 Byte 0        */
                                    /*
                                                    0xFC: LIMPHOME
                                                    0xFD: RING
                                                    0xFE: ALIVE
                                                                            */
    canbittype cDest          :8;   /* bit 15...8 ; bit 7...0 Byte 1        */
    canbittype bSleepInd      :1;   /* bit 23     ; bit 7     Byte 2        */
    canbittype bSleepAck      :1;   /* bit 22     ; bit 6                   */
    canbittype cReserved1     :6;   /* bit 21...16; bit 5...0 Byte 2        */
    /* 1 to 5 user bytes follow. Access is done by array element of union.  */
    #else /* NM_TYPE_DBAG_OSEK */
    canbittype cDest          :8;   /* bit  7...0 ;           Byte 0        */ 
    canbittype bReserved0     :1;   /* bit 15     ; bit 7     Byte 1        */
    canbittype bConfig        :1;   /* bit 14     ; bit 6                   */
    canbittype bSleepAck      :1;   /* bit 13     ; bit 5                   */
    canbittype bSleepInd      :1;   /* bit 12     ; bit 4                   */
    canbittype cCmd           :4;   /* bit 11...8 ; bit 3...0 Byte 1        */
                                    /*
                                                    0x01: ALIVE - VAG: RING
                                                    0x02: RING  - VAG: ALIVE
                                                    0x04: LIMPHOME
                                                                            */
    /* 1 to 6 user bytes follow. Access is done by array element of union.  */
    #endif  /* NM_TYPE_DBAG_OSEK */
  }b;
  #else
    #if defined ( C_CPUTYPE_BITORDER_LSB2MSB )
  struct
  {
    #if defined ( NM_TYPE_DBAG_OSEK )
    canbittype cCmd           :4;   /* bit  3...0 ; bit 3...0 Byte 0        */
                                    /*
                                                    0xFC: LIMPHOME
                                                    0xFD: RING
                                                    0xFE: ALIVE
                                                                            */
    canbittype cReserved0     :4;   /* bit  7...4 ; bit 7...4 Byte 0        */
    canbittype cDest          :8;   /* bit 15...8 ; bit 7...0 Byte 1        */
    canbittype cReserved1     :6;   /* bit 21...16; bit 5...0 Byte 2        */
    canbittype bSleepAck      :1;   /* bit 22     ; bit 6                   */
    canbittype bSleepInd      :1;   /* bit 23     ; bit 7     Byte 2        */
    /* 1 to 5 user bytes follow. Access is done by array element of union.  */
    #else /* NM_TYPE_DBAG_OSEK */
    canbittype cDest          :8;   /* bit  7...0 ;           Byte 0        */ 
    canbittype cCmd           :4;   /* bit 11...8 ; bit 3...0 Byte 1        */
                                    /*
                                                    0x01: ALIVE - VAG: RING
                                                    0x02: RING  - VAG: ALIVE
                                                    0x04: LIMPHOME
                                                                            */
    canbittype bSleepInd      :1;   /* bit 12     ; bit 4                   */
    canbittype bSleepAck      :1;   /* bit 13     ; bit 5                   */
    canbittype bConfig        :1;   /* bit 14     ; bit 6                   */
    canbittype bReserved0     :1;   /* bit 15     ; bit 7     Byte 1        */
    /* 1 to 6 user bytes follow. Access is done by array element of union.  */
    #endif  /* NM_TYPE_DBAG_OSEK */
  }b;
    #else
      #error "Configuration error in NM_DIROSEK: Missing bitorder for typedef NmMessTypeUnion!"
    #endif
  #endif
}NmMessTypeUnion;


/****************************************************************************/
/* Definition of variables depends on number of channels                    */
/****************************************************************************/


#if defined ( NM_ENABLE_SETINITOBJECT )
static CanInitHandle nmUserInitObject[kNmNumberOfChannels];
#endif

#if defined ( NM_ENABLE_INDEXED_NM )

  /****************************************************************************/
  /* Page0 data                                                               */
  /****************************************************************************/
  /*---- transmit buffer nm message ------------------------------------------*/

/* RAM CATEGORY 2 START*/
static        NmStateType MEMORY_NEAR nmState[kNmNumberOfChannels];
static volatile canuint8 MEMORY_NEAR SendMessFlag[kNmNumberOfChannels]; /* ESCAN00004259 */

    #if defined ( NM_ENABLE_MULTIPLE_NODES )
/* new array, because of complex statement */
static canuint8 MEMORY_NEAR NmEcuNr_FieldMultipleNodes[kNmNumberOfChannels];
static canuint8 MEMORY_NEAR NmTxObj_FieldMultipleNodes[kNmNumberOfChannels];
    #endif
/* RAM CATEGORY 2 END*/
/* RAM CATEGORY 1 START*/
kNmSendMessType MEMORY_NEAR nmSendMess[kNmNumberOfChannels][kNmSendMessSize];
/* RAM CATEGORY 1 END*/
/* RAM CATEGORY 2 START*/
    #if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION ) || defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
static NmStateTypeGwMaster MEMORY_NEAR nmStateGwMaster[kNmNumberOfChannels];
    #endif
/* RAM CATEGORY 2 END*/



/****************************************************************************/
/* Extended page variables                                                  */
/****************************************************************************/
/* RAM CATEGORY 2 START*/
static canuint8          TimeCnt[kNmNumberOfChannels];
static NmActionType     nmAction[kNmNumberOfChannels];
static canuint8  NmSourceAddress[kNmNumberOfChannels];
 /*--- counters to detect failures of rx/tx functionality of the NM */
static canuint8        nmRxTxCnt[kNmNumberOfChannels];
static canuint8 logicalSuccessor[kNmNumberOfChannels];
/* RAM CATEGORY 2 END*/
/* RAM CATEGORY 1 START*/
  #if defined ( NM_ENABLE_CONFIG )
/*---- Net management configuration ----------------------------------------*/
static NmConfigType nmConfig;
  #endif
/* RAM CATEGORY 1 END*/
/* RAM CATEGORY 2 START*/
  #if defined ( NM_ENABLE_COPY_RINGDATA_TO_TEMPBUFFER)
/* Received ringdata are copied to global buffer for application usage */
/* but they are not automatically copied to the send message buffer */
static canuint8 nmRecvCopyMsgUser[kNmNumberOfChannels][6];
  #endif


  #if defined ( NM_TYPE_DBAG_OSEK )
    #if defined ( NM_ENABLE_ONM_EXT_API )
static canuint8 RecvUdCmd[kNmNumberOfChannels];
    #endif
  #endif
/* RAM CATEGORY 2 END*/
/* RAM CATEGORY 3 START*/
  #if defined ( NM_ENABLE_FAST_BUSOFF_RECOVERY ) 
static canuint8 nmBusOffCounter[kNmNumberOfChannels];
  #endif
/* RAM CATEGORY 3 END*/

#else /* NM_ENABLE_INDEXED_NM */

  /****************************************************************************/
  /* Page0 data                                                               */
  /****************************************************************************/
  /*---- transmit buffer nm message ------------------------------------------*/

/* RAM CATEGORY 2 START*/

static NmStateType MEMORY_NEAR nmState;
static volatile canuint8 MEMORY_NEAR SendMessFlag; /* ESCAN00004259 */
/* RAM CATEGORY 2 END*/
/* RAM CATEGORY 1 START*/
V_MEMRAM0 V_MEMRAM1_NEAR kNmSendMessType V_MEMRAM2_NEAR nmSendMess[kNmSendMessSize]; /* ESCAN00059554 */
/* RAM CATEGORY 1 END*/
/* RAM CATEGORY 2 START*/
    #if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION ) || defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
static NmStateTypeGwMaster MEMORY_NEAR nmStateGwMaster;
    #endif
/* RAM CATEGORY 2 END*/



/****************************************************************************/
/* Extended page variables                                                  */
/****************************************************************************/
/* RAM CATEGORY 2 START*/
static canuint8          TimeCnt;
static NmActionType     nmAction;
static canuint8  NmSourceAddress;
/*--- counters to detect failures of rx/tx functionality of the NM */
static canuint8        nmRxTxCnt;
static canuint8 logicalSuccessor;
/* RAM CATEGORY 2 END*/
/* RAM CATEGORY 1 START*/
  #if defined ( NM_ENABLE_CONFIG )
  /*---- Net management configuration ----------------------------------------*/
static NmConfigType nmConfig;
  #endif
/* RAM CATEGORY 1 END*/
/* RAM CATEGORY 2 START*/
  #if defined ( NM_ENABLE_COPY_RINGDATA_TO_TEMPBUFFER )
/* Received ringdata are copied to global buffer for application usage */
/* but they are not automatically copied to the send message buffer */
static canuint8 nmRecvCopyMsgUser[6];
  #endif


  #if defined ( NM_TYPE_DBAG_OSEK )
    #if defined ( NM_ENABLE_ONM_EXT_API )
static canuint8 RecvUdCmd;
    #endif
  #endif
/* RAM CATEGORY 2 END*/
/* RAM CATEGORY 3 START*/
  #if defined ( NM_ENABLE_FAST_BUSOFF_RECOVERY ) 
static canuint8 nmBusOffCounter;
  #endif
/* RAM CATEGORY 3 END*/

#endif /* NM_ENABLE_INDEXED_NM */



/******************************************************************************/
/* Defines for nmState, tx and rx buffer access depends on number of channels */
/******************************************************************************/

/* Reset Low Nibble of NmStatLocal */
#define ResetMessRecvFlags()         (NmStatLocal &= (canuint8)0xF0)

#if defined ( NM_ENABLE_INDEXED_NM )

  /****************************************************************************/
  /* Additional defines for required indexed arrays                           */
  /****************************************************************************/

  #define TimeCnt                     TimeCnt[channel]
  #define nmAction                    nmAction[channel]
  #define SendMessFlag                SendMessFlag[channel] /* ESCAN00004259 */
  #define nmRxTxCnt                   nmRxTxCnt[channel]
  #define logicalSuccessor            logicalSuccessor[channel]
  #define NmSourceAddress             NmSourceAddress[channel]

  #define NM_COUNT_RING_TYP           NmCountRingTyp_Field[channel]
  #define NM_COUNT_RING_MAX           NmCountRingMax_Field[channel]
  #define NM_COUNT_LIMPHOME           NmCountLimphome_Field[channel]
  #define NM_COUNT_WAIT_BUSSLEEP      NmCountWaitBussleep_Field[channel]

#if defined ( NM_ENABLE_SETINITOBJECT )
  #define kNmInitObject               nmUserInitObject[channel]
#else
  #define kNmInitObject               NmCanPara_Field[channel]
#endif

  #if defined ( NM_ENABLE_MULTIPLE_NODES )
    /* new array, because of complex statement */
    #define kNmEcuNr                  NmEcuNr_FieldMultipleNodes[channel]
    #define kNmTxObj                  NmTxObj_FieldMultipleNodes[channel]
  #else
    #define kNmEcuNr                  NmEcuNr_Field[channel]
    #define kNmTxObj                  NmTxObj_Field[channel]
  #endif


  #if defined ( NM_TYPE_DBAG_OSEK )
    #if defined ( NM_ENABLE_ONM_EXT_API )
      #define RecvUdCmd               RecvUdCmd[channel]
    #endif
  #endif

  #if defined ( NM_ENABLE_FAST_BUSOFF_RECOVERY )
    #define NM_COUNT_LIMPHOME_SHORT   NmCountLimphomeShort_Field[channel]
    #define NM_COUNT_SHORT_NUMBER     NmCountShortNumber_Field[channel]

    #define nmBusOffCounter           nmBusOffCounter[channel]
  #endif


  /****************************************************************************/
  /* Common with code redoubled section, but channel dependend                */
  /****************************************************************************/

  #define NmStatGlobal                nmState[channel].c[0]
  #define NmStatLocal                 nmState[channel].c[1]

  #define NmStatRingStable            nmState[channel].b.b_RingStable
  #define NmStatBusError              nmState[channel].b.b_BusError
  #define NmStatActive                nmState[channel].b.b_Active
  #define NmStatLimpHome              nmState[channel].b.b_LimpHome
  #define NmStatBusSleep              nmState[channel].b.b_BusSleep
  #define NmStatWaitBusSleep          nmState[channel].b.b_WaitBusSleep
  #define NmStatTxRingDataAllow       nmState[channel].b.b_TxRingDataAllow
  #define NmStatBusSleepInd           nmState[channel].b.b_BusSleepInd
 
  #define NmStatNmMsgRecv             nmState[channel].b.b_NmMsgRecv
  #define NmStatRingMsgRecv           nmState[channel].b.b_RingMsgRecv
  #define NmStatImAddressed           nmState[channel].b.b_ImAddressed
  #define NmStatImSkippedOver         nmState[channel].b.b_ImSkippedOver
  #define NmStatNmMsgRecvRemind       nmState[channel].b.b_NmMsgRecvRemind
  #define NmStatRxTxLockUd            nmState[channel].b.b_RxTxLockUd  /* ESCAN00008104 */
  #define NmStatRingPreStable         nmState[channel].b.b_RingPreStable
  #define NmStatPrepSleep             nmState[channel].b.b_PrepSleep

  #if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION ) || defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
    #define NmStatGwMasterFlags       nmStateGwMaster[channel].c[0]
    #define NmStatGwMasterDummy       nmStateGwMaster[channel].c[1]
  #endif

  #if defined( NM_ENABLE_SLEEPACK_NOTIFICATION )
    #define PrepareSendSleepAck       nmStateGwMaster[channel].b.b_PrepareSendSleepAck
  #endif

  #if defined( NM_ENABLE_REMOTESLEEP_INDICATION )
    #define RemotePrepareSleep        nmStateGwMaster[channel].b.b_RemotePrepareSleep
    #define RemoteSleepInd            nmStateGwMaster[channel].b.b_RemoteSleepInd
  #endif

  #define SendMsgByte0           (*(NmMessTypeUnion*)nmSendMess[channel]).c[0]
  #define SendMsgByte1           (*(NmMessTypeUnion*)nmSendMess[channel]).c[1]
  #define SendMsgByte2           (*(NmMessTypeUnion*)nmSendMess[channel]).c[2]

  #define SendSleepAck           (*(NmMessTypeUnion*)nmSendMess[channel]).b.bSleepAck
  #define SendSleepInd           (*(NmMessTypeUnion*)nmSendMess[channel]).b.bSleepInd
  #define SendMsgConfig          (*(NmMessTypeUnion*)nmSendMess[channel]).b.bConfig

  #if defined ( NM_TYPE_DBAG_OSEK )
    #define SendMsgCmdSet        (*(NmMessTypeUnion*)nmSendMess[channel]).b.cCmd
    #define SendMsgCmdIf         (*(NmMessTypeUnion*)nmSendMess[channel]).b.cCmd

    #define SendMsgCmd           (*(NmMessTypeUnion*)nmSendMess[channel]).c[0]
    #define SendMsgEcuNr         (*(NmMessTypeUnion*)nmSendMess[channel]).c[1]
    #define SendMsgSleep         (*(NmMessTypeUnion*)nmSendMess[channel]).c[2]
    #define SendMsgUser0         (*(NmMessTypeUnion*)nmSendMess[channel]).c[3]
    #define SendMsgUser1         (*(NmMessTypeUnion*)nmSendMess[channel]).c[4]
    #define SendMsgUser2         (*(NmMessTypeUnion*)nmSendMess[channel]).c[5]
    #define SendMsgUser3         (*(NmMessTypeUnion*)nmSendMess[channel]).c[6]
    #define SendMsgUser4         (*(NmMessTypeUnion*)nmSendMess[channel]).c[7]
  #else /* NM_TYPE_DBAG_OSEK */
    #define SendMsgCmdSet           SendMsgCmd
    #define SendMsgCmdIf            SendMsgCmd

    #define SendMsgEcuNr         (*(NmMessTypeUnion*)nmSendMess[channel]).c[0]
    #define SendMsgCmd           (*(NmMessTypeUnion*)nmSendMess[channel]).b.cCmd
    #define SendMsgUser0         (*(NmMessTypeUnion*)nmSendMess[channel]).c[2]
    #define SendMsgUser1         (*(NmMessTypeUnion*)nmSendMess[channel]).c[3]
    #define SendMsgUser2         (*(NmMessTypeUnion*)nmSendMess[channel]).c[4]
    #define SendMsgUser3         (*(NmMessTypeUnion*)nmSendMess[channel]).c[5]
    #define SendMsgUser4         (*(NmMessTypeUnion*)nmSendMess[channel]).c[6]
    #define SendMsgUser5         (*(NmMessTypeUnion*)nmSendMess[channel]).c[7]
  #endif /* NM_TYPE_DBAG_OSEK */

  #if defined ( NM_ENABLE_COPY_RINGDATA_TO_TEMPBUFFER )
    #define RecvCopyMsgUser0        nmRecvCopyMsgUser[channel][0]
    #define RecvCopyMsgUser1        nmRecvCopyMsgUser[channel][1]
    #define RecvCopyMsgUser2        nmRecvCopyMsgUser[channel][2]
    #define RecvCopyMsgUser3        nmRecvCopyMsgUser[channel][3]
    #define RecvCopyMsgUser4        nmRecvCopyMsgUser[channel][4]
    #define RecvCopyMsgUser5        nmRecvCopyMsgUser[channel][5]
  #endif

#else /* NM_ENABLE_INDEXED_NM */

  /****************************************************************************/
  /* Additional defines for required for special implementation               */
  /****************************************************************************/

  #if defined ( NM_ENABLE_MULTIPLE_NODES )
    #if defined ( NM_CAN_CHANNEL )
      #define kNmEcuNr                NmEcuNr_Field[comMultipleECUCurrent[NM_CAN_CHANNEL]]
      #define kNmTxObj                NmTxObj_Field[comMultipleECUCurrent[NM_CAN_CHANNEL]]
    #else
      #define kNmEcuNr                NmEcuNr_Field[comMultipleECUCurrent]
      #define kNmTxObj                NmTxObj_Field[comMultipleECUCurrent]
    #endif
  #endif

  /****************************************************************************/
  /* Common with indexed section, but only code redoubled                     */
  /****************************************************************************/

  #define NmStatGlobal                nmState.c[0]
  #define NmStatLocal                 nmState.c[1]

  #define NmStatRingStable            nmState.b.b_RingStable
  #define NmStatBusError              nmState.b.b_BusError
  #define NmStatActive                nmState.b.b_Active
  #define NmStatLimpHome              nmState.b.b_LimpHome
  #define NmStatBusSleep              nmState.b.b_BusSleep
  #define NmStatWaitBusSleep          nmState.b.b_WaitBusSleep
  #define NmStatTxRingDataAllow       nmState.b.b_TxRingDataAllow
  #define NmStatBusSleepInd           nmState.b.b_BusSleepInd

  #define NmStatNmMsgRecv             nmState.b.b_NmMsgRecv
  #define NmStatRingMsgRecv           nmState.b.b_RingMsgRecv
  #define NmStatImAddressed           nmState.b.b_ImAddressed
  #define NmStatImSkippedOver         nmState.b.b_ImSkippedOver
  #define NmStatNmMsgRecvRemind       nmState.b.b_NmMsgRecvRemind
  #define NmStatRxTxLockUd            nmState.b.b_RxTxLockUd  /* ESCAN00008104 */
  #define NmStatRingPreStable         nmState.b.b_RingPreStable
  #define NmStatPrepSleep             nmState.b.b_PrepSleep

  #if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION ) || defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
    #define NmStatGwMasterFlags       nmStateGwMaster.c[0]
    #define NmStatGwMasterDummy       nmStateGwMaster.c[1]
  #endif

  #if defined( NM_ENABLE_SLEEPACK_NOTIFICATION )
    #define PrepareSendSleepAck       nmStateGwMaster.b.b_PrepareSendSleepAck
  #endif

  #if defined( NM_ENABLE_REMOTESLEEP_INDICATION )
    #define RemotePrepareSleep        nmStateGwMaster.b.b_RemotePrepareSleep
    #define RemoteSleepInd            nmStateGwMaster.b.b_RemoteSleepInd
  #endif

  #if defined ( NM_ENABLE_SETINITOBJECT )
    #define kNmInitObject             nmUserInitObject[0]
  #else
    #define kNmInitObject             kNmCanPara
  #endif

  /* Define tx buffer access */
  #define SendSleepAck           (*(NmMessTypeUnion*)nmSendMess).b.bSleepAck
  #define SendSleepInd           (*(NmMessTypeUnion*)nmSendMess).b.bSleepInd
  #define SendMsgConfig          (*(NmMessTypeUnion*)nmSendMess).b.bConfig

  #define SendMsgByte0           (*(NmMessTypeUnion*)nmSendMess).c[0]
  #define SendMsgByte1           (*(NmMessTypeUnion*)nmSendMess).c[1]
  #define SendMsgByte2           (*(NmMessTypeUnion*)nmSendMess).c[2]

  #if defined ( NM_TYPE_DBAG_OSEK )
    #define SendMsgCmdSet        (*(NmMessTypeUnion*)nmSendMess).b.cCmd
    #define SendMsgCmdIf         (*(NmMessTypeUnion*)nmSendMess).b.cCmd

    #define SendMsgCmd           (*(NmMessTypeUnion*)nmSendMess).c[0]
    #define SendMsgEcuNr         (*(NmMessTypeUnion*)nmSendMess).c[1]
    #define SendMsgSleep         (*(NmMessTypeUnion*)nmSendMess).c[2]
    #define SendMsgUser0         (*(NmMessTypeUnion*)nmSendMess).c[3]
    #define SendMsgUser1         (*(NmMessTypeUnion*)nmSendMess).c[4]
    #define SendMsgUser2         (*(NmMessTypeUnion*)nmSendMess).c[5]
    #define SendMsgUser3         (*(NmMessTypeUnion*)nmSendMess).c[6]
    #define SendMsgUser4         (*(NmMessTypeUnion*)nmSendMess).c[7]
  #else /* NM_TYPE_DBAG_OSEK */
    #define SendMsgCmdSet           SendMsgCmd
    #define SendMsgCmdIf            SendMsgCmd

    #define SendMsgEcuNr         (*(NmMessTypeUnion*)nmSendMess).c[0]
    #define SendMsgCmd           (*(NmMessTypeUnion*)nmSendMess).b.cCmd
    #define SendMsgUser0         (*(NmMessTypeUnion*)nmSendMess).c[2]
    #define SendMsgUser1         (*(NmMessTypeUnion*)nmSendMess).c[3]
    #define SendMsgUser2         (*(NmMessTypeUnion*)nmSendMess).c[4]
    #define SendMsgUser3         (*(NmMessTypeUnion*)nmSendMess).c[5]
    #define SendMsgUser4         (*(NmMessTypeUnion*)nmSendMess).c[6]
    #define SendMsgUser5         (*(NmMessTypeUnion*)nmSendMess).c[7]
  #endif /* NM_TYPE_DBAG_OSEK */

  #if defined ( NM_ENABLE_COPY_RINGDATA_TO_TEMPBUFFER )
    #define RecvCopyMsgUser0        nmRecvCopyMsgUser[0]
    #define RecvCopyMsgUser1        nmRecvCopyMsgUser[1]
    #define RecvCopyMsgUser2        nmRecvCopyMsgUser[2]
    #define RecvCopyMsgUser3        nmRecvCopyMsgUser[3]
    #define RecvCopyMsgUser4        nmRecvCopyMsgUser[4]
    #define RecvCopyMsgUser5        nmRecvCopyMsgUser[5]
  #endif

#endif /* NM_ENABLE_INDEXED_NM */


/****************************************************************************/
/* Functions                                                                */
/****************************************************************************/


/*****************************************************************************/
/* Local functions                                                           */
/*****************************************************************************/

/* ESCAN00014119 */
/************************************************************************
| NAME:               TransmitSkippedAlive
| PROTOTYPE:          void TransmitSkippedAlive(void/channel)
| CALLED BY:          NmTask (internal)
| PRECONDITIONS:      -
| INPUT PARAMETERS:   -
| RETURN VALUE:       -
| DESCRIPTION:        Prepare Skipped Alive message for asynchronous
|                     transmission, the transmission should be pushed
|                     at the appropriate situation
|                     for indexed version, function works
|                     always with NM internal channel
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
static void TransmitSkippedAlive(NM_CHANNEL_NMTYPE_ONLY)
{
  NmStatRxTxLockUd    = 1; /* ESCAN00008104 - wait for NmConfirmation() */
  SendMessFlag        = 1; /* send alive message */

  nmRxTxCnt          += TX_CNT_STEP; /* increment transmit counter */

  NmStatRingStable    = 0;
  NmStatRingPreStable = 0;

  #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
  RemotePrepareSleep  = 0;
  RemoteSleepInd      = 0;
  #endif

  SendMsgCmdSet = ALIVE;
  SendMsgEcuNr  = logicalSuccessor;
  SendSleepInd  = NmStatBusSleepInd;
  SendSleepAck  = 0;
} /* end of TransmitSkippedAlive() */

/************************************************************************
| NAME:               ResetConfig
| PROTOTYPE:          void ResetConfig(void)
| CALLED BY:          NmOsekInit, NmTask (internal)
| PRECONDITIONS:      -
| INPUT PARAMETERS:   -
| RETURN VALUE:       -
| DESCRIPTION:        reset all configurations in memory
|                     for indexed version, function works
|                     always with NM internal channel
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* CODE CATEGORY 2 START*/
static void ResetConfig(NM_CHANNEL_NMTYPE_ONLY)
{
  #if defined ( NM_ENABLE_CONFIG )
  canuint8 configByte;
  #endif

  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  /* !!! Not used, because only for module internal usage on NM cannel allowed
    channel = NmCanToNmIndirection[channel];
  */
  #endif

  NmStatRingStable    = 0;
  NmStatRingPreStable = 0;

  #if defined ( NM_ENABLE_CONFIG )
    #if defined ( NM_ENABLE_INDEXED_NM )
  for(configByte =   channel      * (canuint8)(NM_NUMBER_OF_CONFIG_NODES/8);
      configByte < ((channel + 1) * (canuint8)(NM_NUMBER_OF_CONFIG_NODES/8));
      configByte++)
  {
    nmConfig.nmConfigChar[configByte] = 0; /* clear whole configuration */
  }

  /* calculate the index for the config table */
  configByte = (canuint8)((canuint8)(kNmEcuNr >> 3) + (channel * (canuint8)(NM_NUMBER_OF_CONFIG_NODES/8)));
    #else
  for(configByte = 0; configByte < ((canuint8)(NM_NUMBER_OF_CONFIG_NODES/8)); configByte++)
  {
    nmConfig.nmConfigChar[configByte] = 0; /* clear whole configuration */
  }

  /* calculate the index for the config table */
      #if !defined ( NM_ENABLE_INDEXED_NM ) && \
          !defined ( NM_ENABLE_MULTIPLE_NODES )
  /* ESCAN00020990 */
        #if ( kNmEcuNr <= 0x07 )
  /* ESCAN00020580 */
  configByte = 0;
        #else
  configByte = (canuint8)(kNmEcuNr >> 3);
        #endif
      #else
  configByte = (canuint8)(kNmEcuNr >> 3);
      #endif
    #endif

  /* set own ECU number as present */
  nmConfig.nmConfigChar[configByte] |= (canuint8)(1 << (kNmEcuNr & BYTE_OFFSET_MASK));
  #endif /* NM_ENABLE_CONFIG */
} /* end of ResetConfig() */
/* CODE CATEGORY 2 END*/




/******************************************************************************
Global, exported functions
******************************************************************************/

/************************************************************************
| NAME:               NmCanError
| PROTOTYPE:          void NmCanError( void ) OR
|                     void NmCanError ( CanChannelHandle canChannel )
| CALLED BY:          CAN driver (Error Interrupt)
| PRECONDITIONS:      Error interrupts have to be enabled
| INPUT PARAMETERS:   -
| RETURN VALUE:       -
| DESCRIPTION:        Handles detected CAN error ( Bus off detected )
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* Call back function of the CAN driver depends on driver type */
/* CODE CATEGORY 1 START*/
void NM_INTERNAL_CALL_TYPE NmCanError(NM_CHANNEL_CANTYPE_ONLY)
{
  #if defined ( NM_ENABLE_INDEXED_NM )
    #if defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  CanChannelHandle channel = NmCanToNmIndirection[canChannel];
    #endif
  #else
    #if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
      #if defined ( NM_CAN_CHANNEL )
        #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  canChannel = canChannel; /* avoid compiler warnings */
        #endif
      #endif
    #endif
  #endif

  CanOffline(NM_CHANNEL_CANPARA_ONLY);

  NmStatBusError = 1;

  #if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
  /* makros must be encapsulated in this way */
  CanResetBusOffStart(NM_CHANNEL_CANPARA_ONLY, kNmInitObject);
  #else
  CanResetBusOffStart(kNmInitObject);
  #endif

  if((NmStatPrepSleep == 1) && ((NmStatBusSleep == 1) || (NmStatWaitBusSleep == 1)))
  {
    /*
      ESCAN00009420: BusOff after SleepAck:
                     Hold the Sleep state regardless of BusOff - restart always with Reset Alive.
                     The call of ApplNmBusOff() and ApplNmBusOffEnd() is not symmetric.
                     The Application has to decide, depending on the WaitBusSleep-State within
                     ApplNmBusOff(), if it is neccessary to stop the communication (IL)
                     or not if already in this state.
    */

    #if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
    /* makros must be encapsulated in this way */
    CanResetBusOffEnd(NM_CHANNEL_CANPARA_ONLY, kNmInitObject);
    #else
    CanResetBusOffEnd(kNmInitObject);
    #endif
  }
  else
  {
    ResetMessRecvFlags();
    NmStatNmMsgRecvRemind = 0;
    NmStatRxTxLockUd      = 0; /* ESCAN00008104 */
    SendMessFlag          = 0;

    nmRxTxCnt = TX_CNT_STEP; /* clear rx counter; set tx counter = 1*/

    if((nmAction & ((NmActionType)~NM_ACTION_REPEAT)) != NM_ACTION_LH_PREPARE_SLEEP)
    {
      #if defined ( NM_ENABLE_FAST_BUSOFF_RECOVERY )
      if(nmBusOffCounter > 0)
      {
        TimeCnt = NM_COUNT_LIMPHOME_SHORT;
      } 
      else
      {
        TimeCnt = NM_COUNT_LIMPHOME;
      }
      #else
      TimeCnt   = NM_COUNT_LIMPHOME;
      #endif
      nmAction  = NM_ACTION_LH_WAIT_LIMPHOME_TX;    /* start state limphome */
    }
  }

  #if defined ( NM_ENABLE_FAST_BUSOFF_RECOVERY ) 
  if(nmBusOffCounter > 0)
  {
    nmBusOffCounter--;
  }
  #endif

  ApplNmBusOff(NM_CHANNEL_APPLPARA_ONLY);
} /* end of NmCanError() */
/* CODE CATEGORY 1 END*/

/************************************************************************
| NAME:               NmConfirmation
| PROTOTYPE:          void NmConfirmation(CanTransmitHandle tmtObject)
| CALLED BY:          CAN driver (Tx Interrupt)
| PRECONDITIONS:      CAN tx interrupts have to be enabled
| INPUT PARAMETERS:   Index on TX object (not used)
| RETURN VALUE:       -
| DESCRIPTION:        Confirmation routine for net management CAN messages
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
/* CODE CATEGORY 1 START*/
void NM_INTERNAL_CALL_TYPE NmConfirmation(CanTransmitHandle tmtObject)
{
  #if defined ( NM_ENABLE_ONM_EXT_API )
  NmMsgType onmStateParam = NM_MSG_INVALID; 
  #endif

  #if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && defined ( NM_ENABLE_INDEXED_NM )
  CanChannelHandle channel;
  /* Calculate logical channel of nm based on physical channel (tmtObject) of the CAN driver */
    #if defined( NM_ENABLE_MULTIPLE_NODES )
  for(channel = 0; tmtObject != NmTxObj_Field[channel][comMultipleECUCurrent[channel]]; channel++ ){;} /* ESCAN00014458 */
    #else
  for(channel = 0; tmtObject != NmTxObj_Field[channel]; channel++ ){;}
    #endif
  #else
    #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  tmtObject = tmtObject;
    #endif
  #endif

  StartMeasure(NmConfirmationTimings);

  if ( NmStatBusError == 0 ) /* ESCAN00047102 */
  {
    NmStatRxTxLockUd = 0; /* ESCAN00008104 - release waiting for NmConfirmation() */

    nmRxTxCnt &= ((canuint8)~TX_CNT_MASK);   /* Reset transmit counter  */

    #if defined ( NM_ENABLE_FAST_BUSOFF_RECOVERY ) 
    nmBusOffCounter = NM_COUNT_SHORT_NUMBER;  /* Reset BusOff-Counter */
    #endif

  /*---------------------------------------------------------------------------*/
    if(SendMsgCmdIf == RING)
  /*---------------------------------------------------------------------------*/
    {
      #if defined ( NM_ENABLE_ONM_EXT_API )
      onmStateParam |= NM_MSG_RING; 
      #endif

      /* ESCAN00007856 */

      if((NmStatPrepSleep == 1) && (SendSleepAck == 1))  /* check Sleep Prepare */
      {
        CanOffline(NM_CHANNEL_CANPARA_ONLY);

        #if defined ( NM_ENABLE_ONM_EXT_API )
        onmStateParam |= NM_MSG_SLEEP_ACK; 
        #endif

        NmStatWaitBusSleep = 1;
        SendMessFlag       = 0;  /* cancel nm tx request, NmStatRxTxLockUd is already 0 */


        TimeCnt  = NM_COUNT_WAIT_BUSSLEEP;
        nmAction = NM_ACTION_GO_BUSSLEEP;
      }
      else
      {
        if((NmStatBusSleepInd == 1) && (SendSleepInd == 1))
        {
          #if defined ( NM_ENABLE_ONM_EXT_API )
          onmStateParam |= NM_MSG_SLEEP_IND; 
          #endif

          NmStatPrepSleep = 1;

          #if defined( NM_ENABLE_REMOTESLEEP_INDICATION )
          /* Remote sleep indication depends only on received sleep indication flags */                 
          #endif
        }

        /*
          Do not wait for any Ring message if we are currently go to sleep.
          This could happen, if we receive a Sleep Acknowledge (NmPrecopy()) while waiting for
          our own Confirmation for the Sleep Indication message.
          Then, this last retrigger and state transition could be discarded.
          Leave the NmStatImAddressed and NmStatPrepSleep information too.
          These flags got it's latest update also in NmPrecopy().
        */
        if(NmStatWaitBusSleep == 0) /* ESCAN00007856 */
        {
          NmStatImAddressed = 0;
          NmStatLimpHome = 0; /* ESCAN00017962 */

          /* Retrigger timer to avoid duplicate rings */
          TimeCnt  = NM_COUNT_RING_MAX;
          nmAction = NM_ACTION_WAIT_RINGMSG;
        }
      }
    }
    else
    {
  /*---------------------------------------------------------------------------*/
      if(SendMsgCmdIf == LIMPHOME)
  /*---------------------------------------------------------------------------*/
      {
        #if defined ( NM_ENABLE_ONM_EXT_API )
        onmStateParam |= NM_MSG_LIMPHOME; 
        #endif

        if((NmStatActive == 1) && (NmStatNmMsgRecvRemind == 1))
        {
          nmAction = NM_ACTION_START;
        }
      }
  /*---------------------------------------------------------------------------*/
      else
      {
  /*---------------------------------------------------------------------------*/
        if(SendMsgCmdIf == ALIVE)
  /*---------------------------------------------------------------------------*/
        {
          #if defined ( NM_ENABLE_ONM_EXT_API )
          if(SendMsgEcuNr == kNmEcuNr)  /* address is own nodenr. ? */
          {
            onmStateParam |= NM_MSG_RESET_ALIVE; 
          }
          else
          {
            onmStateParam |= NM_MSG_SKIPPED_ALIVE; 
          }
          #endif

          if((nmAction ==  NM_ACTION_LH_WAIT_LIMPHOME_TX)||
             (nmAction ==  NM_ACTION_LH_PREPARE_SLEEP   )  )
          {
            /* set tx counter, use as Limphome tx mark, reset only on limphome msg */
            nmRxTxCnt = TX_CNT_STEP; 
          }
        }
      }
    } /* endif (SendMsgCmdIf == RING) */


    #if defined ( NM_ENABLE_ONM_EXT_API )
    OnmExtConfirmation(NM_CHANNEL_NMPARA_FIRST onmStateParam); 
    #endif
  }

  StopMeasure(NmConfirmationTimings);

} /* end of NmConfirmation() */
/* CODE CATEGORY 1 END*/


/************************************************************************
| NAME:               NmPrecopy
| PROTOTYPE:          canuint8 NmPrecopy(CanTransmitHandle rcvObject) or
|                     canuint8 NmPrecopy(CanChipDataPtr ReceivedMessage)
| CALLED BY:          CAN driver (Rx Interrupt)
| PRECONDITIONS:      CAN Rx interrupts have to be enabled
| INPUT PARAMETERS:   Index on RX object (not used)   OR
|                     Pointer to RX object
| RETURN VALUE:       kCanNoCopyData: Do not copy data, because of no
|                                     RX buffer for NM messages
| DESCRIPTION:        Precopy routine for net management CAN messages
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* CODE CATEGORY 1 START*/
#if defined ( C_SINGLE_RECEIVE_BUFFER )
canuint8 NM_INTERNAL_CALL_TYPE NmPrecopy(CanReceiveHandle rcvObject)
{
#endif
#if defined ( C_MULTIPLE_RECEIVE_BUFFER )
canuint8 NM_INTERNAL_CALL_TYPE NmPrecopy(CanChipDataPtr rxDataPtr)
{
#endif
#if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) || defined ( C_SINGLE_RECEIVE_CHANNEL )
canuint8 NM_INTERNAL_CALL_TYPE NmPrecopy(CanRxInfoStructPtr rxStruct)
{
#endif
  #if defined ( NM_ENABLE_ONM_EXT_API )
  NmMsgType onmStateParam = NM_MSG_INVALID; 
  #endif

  /*-------------------- start of function -----------------------*/
  #if defined ( NM_ENABLE_INDEXED_NM )
    #if defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  CanChannelHandle channel = NmCanToNmIndirection[rxStruct->Channel];
    #else
  CanChannelHandle channel = rxStruct->Channel;
    #endif
  #endif

  #if defined ( NM_ENABLE_CONFIG )
  canuint8 configByte;
  #endif

  canuint8 validNmMsgReceived;


  StartMeasure(NmPrecopyTimings);

  #if defined ( C_SINGLE_RECEIVE_BUFFER )
    #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  rcvObject = rcvObject; /* avoid compiler warnings */
    #endif
  #endif

  validNmMsgReceived = 0;

  /* Get the source address valid until the next message will be received */
  NmSourceAddress = GetNmSourceAddress;



  #if defined ( NM_TYPE_DBAG_OSEK )
    #if defined ( NM_ENABLE_ONM_EXT_API )
  RecvUdCmd = RecvMsgSleep; /* Make backup copy for the further process with ONM module */
    #endif
  #endif

/*---------------------------------------------------------------------------*/
  if((RecvMessCmd == RING )||
     (RecvMessCmd == ALIVE)  )
/*---------------------------------------------------------------------------*/
  {
    /* ESCAN00007856 */

    validNmMsgReceived = 1;

    #if defined ( NM_ENABLE_CONFIG )
    /* set current configuration bit -------------------------------------*/
    /* ESCAN00028089 */
    #if defined ( NM_ENABLE_INDEXED_NM )
      /* ESCAN00033467 */
      #if defined ( NM_RANGE_MASK )
        #if ( (NM_RANGE_MASK+1) != NM_NUMBER_OF_CONFIG_NODES )
    if(NmSourceAddress <= ((canuint8)(NM_NUMBER_OF_CONFIG_NODES - 1)))
        #endif
      #else
    if(NmSourceAddress <= ((canuint8)(NM_NUMBER_OF_CONFIG_NODES - 1)))
      #endif
    #else
      #if ( (NM_RANGE_MASK+1) != NM_NUMBER_OF_CONFIG_NODES )
    if(NmSourceAddress <= ((canuint8)(NM_NUMBER_OF_CONFIG_NODES - 1)))
      #endif
    #endif
    {
      /* calculate the index for the config table */
      #if defined ( NM_ENABLE_INDEXED_NM )
      configByte = (canuint8)((canuint8)(NmSourceAddress >> 3) + (channel * (canuint8)(NM_NUMBER_OF_CONFIG_NODES/8)));
      #else
      configByte = (canuint8)(NmSourceAddress >> 3);
      #endif

      nmConfig.nmConfigChar[configByte] |= (canuint8)(1 << (NmSourceAddress & BYTE_OFFSET_MASK)); /* set the received ECU number as present */
    }
    #endif /* NM_ENABLE_CONFIG */

    /* calculate new log successor ------------------------------------- */
    if(logicalSuccessor > kNmEcuNr)
    {
      if((NmSourceAddress < logicalSuccessor)&&
         (NmSourceAddress > kNmEcuNr        )  )
      {
        logicalSuccessor = NmSourceAddress;
      }
    }
    else
    {
      if((NmSourceAddress < logicalSuccessor)||
         (NmSourceAddress > kNmEcuNr        )  )
      {
        logicalSuccessor = NmSourceAddress;
      }
    }

/*---------------------------------------------------------------------------*/
    if(RecvMessCmd == RING)                 /* RING message received */
/*---------------------------------------------------------------------------*/
    {
      #if defined ( NM_ENABLE_ONM_EXT_API )
      onmStateParam |= NM_MSG_RING; 
      #endif

      NmStatRingMsgRecv = 1;

/*---- check for own node was addressed --------------------------------------*/
      if((NmDestAddress == kNmEcuNr       )||   /*I'm addressed or    */
         (NmDestAddress == NmSourceAddress)  )  /*sender was addressed*/
      {
        #if defined ( NM_ENABLE_ONM_EXT_API )
        onmStateParam |= NM_MSG_WAIT_TX; 
        #endif

        NmStatImAddressed = 1;


        if(NmDestAddress == kNmEcuNr) /* I'm addressed   */
        {
          #if defined ( NM_ENABLE_RINGDATA_ACCESS )
          NmStatTxRingDataAllow = 1;/* allow user(ring)data access */
          #endif


          #if defined ( NM_TYPE_DBAG_OSEK )
            #if defined ( NM_ENABLE_USERDATA_ACCESS ) 
            /* Copy done in ONMX */ 
            #else
          if(NmStatRxTxLockUd == 0) /* ESCAN00008104 */
          {
            /* ESCAN00008104:
               Protect send buffer - User Data should not be copied until tx request was sent
            */
            SendMsgCmd   = nmRecvMess.c[0];  /* copy all bytes     */
            SendMsgSleep = RecvMsgSleep;  /* with user data     */
            SendMsgUser0 = RecvMsgUser0;

              #if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) || defined ( C_SINGLE_RECEIVE_CHANNEL )
            if(CanRxActualDLC(rxStruct) > 4)  /* dnm2.2 msg size  */
              #else
            if(CanRxActualDLC > 4)            /* dnm2.2 msg size  */
              #endif
            {
              SendMsgUser1 = RecvMsgUser1;  /* only 4 bytes :   */
              SendMsgUser2 = RecvMsgUser2;  /* avoid copying    */
              SendMsgUser3 = RecvMsgUser3;  /* invalid data     */
              SendMsgUser4 = RecvMsgUser4;
            }
          }
            #endif

          #else /* NM_TYPE_DBAG_OSEK */

          if(NmStatRxTxLockUd == 0) /* ESCAN00008104 */
          {
            /* ESCAN00008104:
               Protect send buffer - User Data should not be copied until tx request was sent
            */

            #if defined ( NM_ENABLE_COPY_RINGDATA )
            /* OSEK mechanism: copy received data to send buffer */

            SendMsgUser0 = RecvMsgUser0;
            SendMsgUser1 = RecvMsgUser1;
            SendMsgUser2 = RecvMsgUser2;
            SendMsgUser3 = RecvMsgUser3;
            SendMsgUser4 = RecvMsgUser4;
            SendMsgUser5 = RecvMsgUser5;
            #else

              #if defined ( NM_ENABLE_COPY_RINGDATA_TO_TEMPBUFFER )
            RecvCopyMsgUser0 = RecvMsgUser0;
            RecvCopyMsgUser1 = RecvMsgUser1;
            RecvCopyMsgUser2 = RecvMsgUser2;
            RecvCopyMsgUser3 = RecvMsgUser3;
            RecvCopyMsgUser4 = RecvMsgUser4;
            RecvCopyMsgUser5 = RecvMsgUser5;
              #endif

            /* Fill send buffer with specific pattern  */
            /* data may be modified by application */

            SendMsgUser0 = DATA_INIT;
            SendMsgUser1 = DATA_INIT;
            SendMsgUser2 = DATA_INIT;
            SendMsgUser3 = DATA_INIT;
            SendMsgUser4 = DATA_INIT;
            SendMsgUser5 = DATA_INIT;
            #endif
          }
          #endif  /* NM_TYPE_DBAG_OSEK */
        }
      }
      else
      {
/*---- own node not addressed , check for skipped ---------------------------*/
        NmStatImAddressed = 0;

      #if defined ( NM_ENABLE_INDEXED_NM ) || \
          defined ( NM_ENABLE_MULTIPLE_NODES )
        #define NM_INT_DISABLE_OPTIMIZED_SKIPPED_DETECTION
      #else
        #if ( kNmEcuNr == 0x00 )
          #define NM_INT_ENABLE_OPTIMIZED_SKIPPED_DETECTION
        #else
          #define NM_INT_DISABLE_OPTIMIZED_SKIPPED_DETECTION
        #endif
      #endif

      #if defined ( NM_INT_ENABLE_OPTIMIZED_SKIPPED_DETECTION )
        /* Code: Special use case: In this configuration, the kNmCfg_EcuNr is a preprocessor define with the value 0.
         *       This leads to some compiler warnings for the standard algorithm. 
         *       The warnings can be removed and the code can be optimized for this use case.*/
        /* ESCAN00020580 */
        if( NmSourceAddress >= NmDestAddress  )
        {
          NmStatImSkippedOver = 1;
        }
      #else
        if((cansint16)NmDestAddress < (cansint16)kNmEcuNr) /* ESCAN00007275 */
        {
          if((           NmSourceAddress >= NmDestAddress     )&& 
             ((cansint16)NmSourceAddress <  (cansint16)kNmEcuNr))
          {
            NmStatImSkippedOver = 1;
          }
        }
        else
        {
          if(NmSourceAddress < NmDestAddress)
          {
            if((cansint16)NmSourceAddress < (cansint16)kNmEcuNr)
            {
              NmStatImSkippedOver = 1;
            }
          }
          else
          {
            NmStatImSkippedOver = 1;
          }
        }
      #endif
      }
    }
/*---------------------------------------------------------------------------*/
    else                                           /* ALIVE message received */
/*---------------------------------------------------------------------------*/
    {
      #if defined ( NM_ENABLE_ONM_EXT_API )
      if(NmDestAddress == NmSourceAddress)  /* address is own nodenr. ? */
      {
        onmStateParam |= NM_MSG_RESET_ALIVE; 
      }
      else
      {
        onmStateParam |= NM_MSG_SKIPPED_ALIVE; 
      }
      #endif

      NmStatRingStable    = 0;
      NmStatRingPreStable = 0;

      #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )  /* ESCAN00007430 */
      /* Remote sleep indication depends only on received sleep indication flags */

      /*
        Any NM message without set Sleep Indication resets the Remote Sleep Indication.
        This will be done a few lines later ->  if(RecvSleepInd == 0) ... .
        That means, a Skipped Alive with a set Sleep Ind does not influence the network remote sleep state.
        A Startup Alive has ever! no set Sleep Ind.
      */
      #endif
    }
  }
/*---------------------------------------------------------------------------*/
  else                                          /* LIMPHOME message received */
/*---------------------------------------------------------------------------*/
  {
    if(RecvMessCmd == LIMPHOME)
    {
      #if defined ( NM_ENABLE_ONM_EXT_API )
      onmStateParam |= NM_MSG_LIMPHOME; 
      #endif

      validNmMsgReceived = 1;
    } /* endif RecvMessCmd == LIMPHOME */
  }

/*---------------------------------------------------------------------------*/
  if(validNmMsgReceived == 1)                        /* VALID NM message received */
/*---------------------------------------------------------------------------*/
  {
    NmStatNmMsgRecv = 1;
    #if defined ( NM_ENABLE_ONM_EXT_API )
    if(RecvSleepInd == 1)
    {
      onmStateParam |= NM_MSG_SLEEP_IND;  
    }
    #endif

    nmRxTxCnt &= (canuint8)~RX_CNT_MASK;  /* receive counter reset */

    /* Check for sleep prepare */
    if((RecvSleepInd == 0) || (NmStatBusSleep == 1)) /* ESCAN00007436 */
    {
      NmStatPrepSleep = 0;

      #if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION )
      PrepareSendSleepAck = 0;
      SendSleepAck        = 0;
      #endif

      #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
      RemotePrepareSleep = 0;
      RemoteSleepInd     = 0;
      #endif

    }

    if(RecvSleepAck == 1)
    {
      #if defined ( NM_ENABLE_ONM_EXT_API )
      onmStateParam |= NM_MSG_SLEEP_ACK;  
      #endif

      if((NmStatBusSleep == 0) && (NmStatWaitBusSleep == 0))  /* ESCAN00007535 */
      {
        /* Start transition to BUSSLEEP */

        if(NmStatBusSleepInd == 1)
        {
          /* Sleep-Acknowlege received a n d  ready to go to BusSleep */

          /* Stop transmission immediately, GO BUSSLEEP */
          CanOffline(NM_CHANNEL_CANPARA_ONLY);

          NmStatPrepSleep    = 1;
          NmStatWaitBusSleep = 1;
          NmStatRxTxLockUd   = 0; /* ESCAN00008104 */
          SendMessFlag       = 0; /* cancel nm tx request */

          #if defined ( NM_ENABLE_RINGDATA_ACCESS )
          NmStatTxRingDataAllow = 0;  /* disable user(ring)data access */
          #endif

          #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
          RemotePrepareSleep = 1;
          RemoteSleepInd     = 1;
          #endif


          TimeCnt  = NM_COUNT_WAIT_BUSSLEEP;
          nmAction = NM_ACTION_GO_BUSSLEEP;

          /*
            ESCAN00009711: SleepAck after BusOff:
                           Hold the Sleep state regardless of BusOff - restart always with Reset Alive.
                           The call of ApplNmBusOff() and ApplNmBusOffEnd() is not symmetric.
                           ApplNmWaitBusSleep(), has always a higher priority to stop the
                           communication (IL).
          */
        }
        else
        {
          /* Sleep-Acknowlege received but  n o t  ready to go to BusSleep */

          /*ESCAN00021051*/
          if( (nmAction == NM_ACTION_LH_WAIT_LIMPHOME_TX) || 
              (nmAction == NM_ACTION_LH_PREPARE_SLEEP) )
          {
            if(NmStatBusError == 1)
            {
              NmStatBusError = 0;

              #if defined( C_MULTIPLE_RECEIVE_CHANNEL )
              /* macros must be encapsulated in this way */
              CanResetBusOffEnd(NM_CHANNEL_CANPARA_ONLY, kNmInitObject);
              #else
              CanResetBusOffEnd(kNmInitObject);
              #endif

              #if defined( NM_ENABLE_EXTENDED_CALLBACK )
              ApplNmBusOffEnd(NM_CHANNEL_APPLPARA_ONLY);
              #endif
            }
          }

          #if defined ( NM_ENABLE_IMMEDIATE_ALIVE )
          NmStatPrepSleep = 0;
          nmAction = NM_ACTION_START; /* restart Network Management immediately */
          #endif

          #if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION )
          PrepareSendSleepAck = 0;
          SendSleepAck        = 0;
          #endif

          #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
          RemotePrepareSleep = 0;
          RemoteSleepInd     = 0;
          #endif

        }
      }
    }
  } /* endif NmStatNmMsgRecv */

  #if defined ( NM_ENABLE_ONM_EXT_API )
  OnmExtPrecopy(NM_CHANNEL_NMPARA_FIRST onmStateParam, &RecvMsgUser0); 
  #endif

  StopMeasure(NmPrecopyTimings);

  return(kCanNoCopyData);
} /* end of NmPrecopy() */
/* CODE CATEGORY 1 END*/

#if defined ( NM_ENABLE_SETINITOBJECT )
/************************************************************************
| NAME:               NmSetInitObject
| PROTOTYPE:          void NmSetInitObject(vuint8 initObjectHandle)
| INPUT PARAMETERS:   initObject: Handle of the CAN initialization object 
|                                 that shall be used for CAN re-init.
| RETURN VALUE:       -
| DESCRIPTION:        This API sets the init object that is used to 
|                     (re-)initialize the CAN controller (after a BusOff event).
|                     The init objects are defined in the configuration tool 
|                     and e.g. define the used baudrate.
|************************************************************************/
void NmSetInitObject(NM_CHANNEL_NMTYPE_FIRST CanInitHandle initObjectHandle)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && \
      defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  #if defined ( NM_ENABLE_INDEXED_NM )
  nmUserInitObject[channel] = initObjectHandle;
  #else
  nmUserInitObject[0] = initObjectHandle;
  #endif
}
#endif


/************************************************************************
| NAME:               NmOsekInit
| PROTOTYPE:          void NmOsekInit(NmInitType InitMode)
| CALLED BY:          StartNM / StopNM (internal)
|                     Station Management / Application
| PRECONDITIONS:      Bus Transceiver and CAN driver have to be initialized
| INPUT PARAMETERS:   mode: Init parameter
| RETURN VALUE:       -
| DESCRIPTION:        Init of network management
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* CODE CATEGORY 4 START*/
void NM_API_CALL_TYPE NmOsekInit(NM_CHANNEL_NMTYPE_FIRST NmInitType InitMode)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
    #if defined ( NM_ENABLE_MULTIPLE_NODES )
  CanChannelHandle canChannel = channel;
    #endif
  channel = NmCanToNmIndirection[channel];
  #endif

  nmAction = (NmActionType)InitMode; /* use nmAction as temporary variable */

  /*---- Disable and Save Interrupt Mask ------------*/
  CanInterruptDisable();

  #if defined ( NM_ENABLE_SETINITOBJECT )
    #if defined ( NM_ENABLE_INDEXED_NM )
  nmUserInitObject[channel] = NmCanPara_Field[channel];
    #else
  nmUserInitObject[0] = kNmCanPara;
    #endif
  #endif


  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_MULTIPLE_NODES )
    #if defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  kNmEcuNr = NmEcuNr_Field[channel][comMultipleECUCurrent[canChannel]];
  kNmTxObj = NmTxObj_Field[channel][comMultipleECUCurrent[canChannel]];
    #else
  kNmEcuNr = NmEcuNr_Field[channel][comMultipleECUCurrent[channel]];
  kNmTxObj = NmTxObj_Field[channel][comMultipleECUCurrent[channel]];
    #endif
  #endif

  NmStatGlobal    = 0;
  NmStatLocal     = 0;
  SendMessFlag    = 0;  /* ESCAN00004259 */

  TimeCnt         = 0;
  nmRxTxCnt       = 0;  /* reset watch counter */
  NmSourceAddress = kNmEcuNr;  /* initial value - self addressed */


  #if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION ) || defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
  NmStatGwMasterFlags = 0;
  NmStatGwMasterDummy = 0;
  #endif


  #if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION )
  if(InitMode != NM_SENDSLEEPACK)
  #endif
  {
    /*
       Standard default initialization.
       Else, leave NM message configuration for asynchron Sleep Ack.
       Reset only Sleep Acknowledge information, for next retrigger.
    */
    #if defined ( NM_TYPE_DBAG_OSEK )
      #if defined ( NM_ENABLE_USERDATA_ACCESS ) 
      /* nothing -- init. of tx-msg. moved to NmTask / NM_ACTION_START according UD-Spec. */
      #else
    SendMsgByte0 = CTRL_INIT;
    SendMsgByte1 = CTRL_INIT;
    SendMsgByte2 = CTRL_INIT;
      #endif
    #else /* NM_TYPE_DBAG_OSEK */
    SendMsgByte0 = CTRL_INIT; /* initialize Ring Address and Control Byte */
    SendMsgByte1 = CTRL_INIT;

    #endif  /* NM_TYPE_DBAG_OSEK */

    ResetConfig(NM_CHANNEL_NMPARA_ONLY); /* internal function */
  }

  #if defined ( NM_ENABLE_FAST_BUSOFF_RECOVERY ) 
  nmBusOffCounter = NM_COUNT_SHORT_NUMBER;
  #endif

  switch((NmInitType)nmAction)
  {
    case    NM_NORMAL:
/*---------------------------------------------------------------------------*/
            NmStatActive = 1;
            break;
/*---------------------------------------------------------------------------*/
    case    NM_NMPASSIVE:
/*---------------------------------------------------------------------------*/
            break;
/*---------------------------------------------------------------------------*/
    case    NM_SLEEPIND:
/*---------------------------------------------------------------------------*/
            NmStatActive      = 1;
            NmStatBusSleepInd = 1;

            break;
/*---------------------------------------------------------------------------*/
    case    NM_SLEEPIND_NMPASSIVE:
/*---------------------------------------------------------------------------*/
            NmStatBusSleepInd = 1;
            break;

            #if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION )
/*---------------------------------------------------------------------------*/
    case    NM_SENDSLEEPACK:
/*---------------------------------------------------------------------------*/
            NmStatActive       = 1;
            NmStatBusSleepInd  = 1;
            NmStatPrepSleep    = 1;
            nmPrepareSleepCnt   = 0;
            PrepareSendSleepAck = 1;
            SendSleepAck        = 0;
              #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
            RemotePrepareSleep  = 1;
            RemoteSleepInd      = 1;
              #endif

            /*
              NmStatImSkippedOver and/or NmStatRingMsgRecv could be cleared
              while re-initialization
            */

            if(logicalSuccessor == kNmEcuNr)
            {
              logicalSuccessor = (canuint8)(~kNmEcuNr);
            }
            /* else, leave the successor */

            nmAction = NM_ACTION_WAIT_SENDTOKEN;

            CanInterruptRestore();
            return;
            #endif /* NM_ENABLE_SLEEPACK_NOTIFICATION */
/*---------------------------------------------------------------------------*/
    case    NM_CANSLEEP:
/*---------------------------------------------------------------------------*/
            CanOffline(NM_CHANNEL_CANPARA_ONLY);

            NmStatActive      = 1;
            NmStatBusSleepInd = 1;
            NmStatPrepSleep   = 1;
            NmStatBusSleep    = 1;

            nmAction = NM_ACTION_BUS_SLEEP;


            #if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION )
            PrepareSendSleepAck = 1;
            SendSleepAck        = 1;
            #endif

            #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
            RemotePrepareSleep = 1;
            RemoteSleepInd     = 1;
            #endif

            #if defined ( NM_ENABLE_ONM_EXT_API )
            OnmExtInit(NM_CHANNEL_NMPARA_ONLY); 
            #endif

            ApplNmCanSleep(NM_CHANNEL_APPLPARA_ONLY);
            ApplNmCanBusSleep(NM_CHANNEL_APPLPARA_ONLY);

            CanInterruptRestore();
            return;
/*---------------------------------------------------------------------------*/
    case    NM_DISABLE:
    default :
/*---------------------------------------------------------------------------*/
            #if defined ( NM_ENABLE_ONM_EXT_API )
            OnmExtInit(NM_CHANNEL_NMPARA_ONLY); 
            #endif

            nmAction = NO_ACTION;

            CanInterruptRestore(); /*---- Restore old Interrupt Mask ----*/
            return;
  } /* switch((NmInitType)nmAction) */

  #if defined ( NM_ENABLE_ONM_EXT_API )
  OnmExtInit(NM_CHANNEL_NMPARA_ONLY); 
  #endif

  ApplNmCanNormal(NM_CHANNEL_APPLPARA_ONLY);  /* wakeup CAN-Chip; switch Tranceiver to normal state */
  CanOnline(NM_CHANNEL_CANPARA_ONLY); /* switch CAN driver to 'Online' */
  #if defined (NM_ENABLE_EXTENDED_CALLBACK)
  ApplNmBusStart(NM_CHANNEL_APPLPARA_ONLY);
  #endif

  nmAction = NM_ACTION_START;

  CanInterruptRestore(); /*---- Restore old Interrupt Mask ----*/
} /* end of NmOsekInit() */
/* CODE CATEGORY 4 END*/

/************************************************************************
| NAME:               NmTask
| PROTOTYPE:          void NmTask(void)
| CALLED BY:          Station Management / Application
| PRECONDITIONS:      NM has to be initialized
| INPUT PARAMETERS:   -
| RETURN VALUE:       -
| DESCRIPTION:        Main task of NM, contains state machine and has to be
|                     called by frequently
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* CODE CATEGORY 1 START*/
void NM_API_CALL_TYPE NmTask(NM_CHANNEL_NMTYPE_ONLY)
{
  #if defined ( NM_ENABLE_ONM_EXT_API )
  NmMsgType onmStateParam; 
  #endif

  StartMeasure(NmTaskTimings);

  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  CanInterruptDisable();

  if(TimeCnt > 0)
  {
    TimeCnt--;
  }

  CanInterruptRestore();

/*----------------------------------------------------------------------------
 * Loop for an immediate switch to the next state in time-critical cases.
 *  If source code is changed, pay attention that NM_ACTION_REPEAT does not
 *  provoke a multiple repetition (deadlock!).
 *---------------------------------------------------------------------------*/

  do
  {
    #if defined ( NM_ENABLE_ONM_EXT_API )
    /* collect new states always, because of REPEAT flag */
    onmStateParam = NM_MSG_INVALID; 
    #endif
/*---- Disable and Save Interrupt -------------------------------------------*/
    CanInterruptDisable();
/*---------------------------------------------------------------------------*/
    nmAction &= (NmActionType)~NM_ACTION_REPEAT;
 
/*---- Check transmit counter, if not ok, start limp home mode -----------*/
    if((canuint8)((nmRxTxCnt & TX_CNT_MASK)>>4) > TX_CNT_MAX)
    {                              /* tx counter run off-> state limp home */
      nmRxTxCnt = TX_CNT_STEP; /* set tx counter; use as Limphome tx mark*/
      TimeCnt = NM_COUNT_LIMPHOME;
      nmAction = NM_ACTION_LH_WAIT_LIMPHOME_TX; /* start state limp home */
    }

/*---- State machine for NM states ------------------------------------------*/
    switch(nmAction)
    {
/*---------------------------------------------------------------------------*/
      case    NM_ACTION_START:
/*---------------------------------------------------------------------------*/
        #if defined ( NM_ENABLE_ONM_EXT_API )
        /* Use SendMessFlag to detect a valid Tx entry */
        onmStateParam |= (NmMsgType)(NM_MSG_RESET_ALIVE | NM_MSG_WAIT_TX); 
        #endif

        ResetConfig( NM_CHANNEL_NMPARA_ONLY ); /* internal function */

        /* Reset all NmStatLocal and all non application dependend Bits of NmStatGlobal */
        NmStatLocal           = 0;
        NmStatTxRingDataAllow = 0;
        NmStatWaitBusSleep    = 0;  /* ESCAN00009420 */
        NmStatBusSleep        = 0; 
        NmStatLimpHome        = 0;
        NmStatRingStable      = 0; 
        NmStatBusError        = 0;  /* ESCAN00009711 */
        SendMessFlag          = 0;  /* ESCAN00004259 */

        NmSourceAddress = kNmEcuNr; /* initial value - self addressed */
        nmRxTxCnt += RX_CNT_STEP; /* increment receive counter */

        CanOnline(NM_CHANNEL_CANPARA_ONLY); /* unlock tx path */  /* ESCAN00004328 */

        #if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION )
        PrepareSendSleepAck = 0;
        SendSleepAck        = 0;
        #endif

        #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
        RemotePrepareSleep = 0;
        RemoteSleepInd     = 0;
        #endif

        if(NmStatActive == 1)
        { 
          #if defined ( NM_ENABLE_ONM_EXT_API )
          /* Use SendMessFlag to detect a valid Tx entry */
          onmStateParam |= NM_MSG_START_TX; 
          #endif

          NmStatRxTxLockUd = 1; /* ESCAN00008104 - wait for NmConfirmation() */
          SendMessFlag     = 1; /* send alive message */

          nmRxTxCnt += TX_CNT_STEP; /* increment tx counter */

          /* build Alive-Msg -------------------------------------------*/
          #if defined ( NM_TYPE_DBAG_OSEK )
            #if defined (NM_ENABLE_USERDATA_ACCESS)
          SendMsgCmd   = CTRL_INIT;
          SendMsgSleep = CTRL_INIT;  /* according to UD-spec */
            #endif
          #endif  /* NM_TYPE_DBAG_OSEK */

          SendMsgEcuNr     = kNmEcuNr;
          logicalSuccessor = kNmEcuNr;
          SendMsgCmdSet    = ALIVE;
          SendSleepAck     = 0;
          SendSleepInd     = 0;

          #if defined ( NM_TYPE_DBAG_OSEK )
            #if defined ( NM_ENABLE_SEND_ALIVE_BROADCAST )  
            #else
          /* initialize user data */
          SendMsgUser0 = DATA_INIT;
          SendMsgUser1 = DATA_INIT;
          SendMsgUser2 = DATA_INIT;
          SendMsgUser3 = DATA_INIT;
          SendMsgUser4 = DATA_INIT;
            #endif
          #else  /* NM_TYPE_DBAG_OSEK */
          /* initialize user data */
          SendMsgUser0 = DATA_INIT;
          SendMsgUser1 = DATA_INIT;
          SendMsgUser2 = DATA_INIT;
          SendMsgUser3 = DATA_INIT;
          SendMsgUser4 = DATA_INIT;
          SendMsgUser5 = DATA_INIT;
          #endif  /* NM_TYPE_DBAG_OSEK */
        }

        if((nmRxTxCnt & RX_CNT_MASK) <= RX_CNT_MAX)
        {
          TimeCnt  = (canuint8)(NM_COUNT_RING_TYP + 1);
          nmAction = NM_ACTION_WAIT_SENDTOKEN;  /* start normal mode */
        }
        else  /* Receive counter expired  --> LIMPHOME*/
        { /* set tx counter; use as Limphome tx mark */
          nmRxTxCnt = TX_CNT_STEP;

          TimeCnt   = NM_COUNT_LIMPHOME;
          nmAction  = NM_ACTION_LH_WAIT_LIMPHOME_TX;  /* start LIMPHOME */
        }

        break;

/*---------------------------------------------------------------------------*/
      case    NM_ACTION_WAIT_SENDTOKEN:
/*---------------------------------------------------------------------------*/
        #if defined ( NM_ENABLE_ONM_EXT_API )
        onmStateParam |= (NmMsgType)(NM_MSG_RING | NM_MSG_WAIT_TX); 
        #endif

        if(NmStatActive == 0)  /* NMPassive: no tx */
        {
          NmStatPrepSleep = NmStatBusSleepInd;

          #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
          /* Remote sleep indication is not defined in passive mode */                 
          #endif


          TimeCnt  = NM_COUNT_RING_MAX;
          nmAction = NM_ACTION_WAIT_RINGMSG;
        }
        else
        {
          if(NmStatImSkippedOver == 1)
          {
            /* ESCAN00014119 */
            /*
              Don't touch the counter, Token should be transmitted now or by the next task call,
              if NM_COUNT_RING_TYP expires. This message might be overwritten.
            */
            #if defined ( NM_ENABLE_ONM_EXT_API )
            onmStateParam |= (NmMsgType)(NM_MSG_SKIPPED_ALIVE | NM_MSG_START_TX); 
            #endif

            /* transmit SKIPPED ALIVE message ------------------------ */
            TransmitSkippedAlive(NM_CHANNEL_NMPARA_ONLY);
          }
          
          if(NmStatRingMsgRecv == 1)
          {
            if(NmStatImAddressed == 1) /* Refresh Timer - state not changed */
            {
              TimeCnt = NM_COUNT_RING_TYP;
            }
            else
            {
              /* cancel transmit token */
              TimeCnt  = NM_COUNT_RING_MAX;
              nmAction = NM_ACTION_WAIT_RINGMSG;
            }
          }
          else
          {
            if(TimeCnt == 0)
            {
              /* transmit ring message ------------------------ */

              #if defined ( NM_ENABLE_ONM_EXT_API )
              /* Use SendMessFlag to detect a valid Tx entry */
              onmStateParam |= NM_MSG_START_TX; 
              #endif

              #if defined ( NM_ENABLE_RINGDATA_ACCESS )
              NmStatTxRingDataAllow = 0;  /* disable user(ring)data access */
              #endif

              NmStatRxTxLockUd      = 1; /* ESCAN00008104 - wait for NmConfirmation() */
              SendMessFlag          = 1; /* tx-ring-msg-flag */

              nmRxTxCnt += TX_CNT_STEP; /* Increment transmit counter */
                              
              if(logicalSuccessor != kNmEcuNr)
              {
                if((NmStatPrepSleep == 1) && (NmStatBusSleepInd == 1))
                {
                  #if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION )
                  if(ApplNmSendSleepAck(NM_CHANNEL_APPLPARA_ONLY))
                  {
                    SendSleepAck = 1;  
                  }
                  else
                  {
                    SendSleepAck = 0;
                  }

                  PrepareSendSleepAck = 1;
                  #else
                  SendSleepAck = 1;
                  #endif
                }
                else
                {
                  SendSleepAck = 0;

                }

                SendSleepInd = NmStatBusSleepInd;
              }
              else
              {
                SendSleepAck = 0;
                SendSleepInd = 0;
              }

              if(NmStatRingPreStable == 1) /* check config  */
              {
                NmStatRingStable = 1; /* set config bit */
              }
              else
              {
                NmStatRingPreStable = 1;
              }

              #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
              if(RemotePrepareSleep == 1)
              {
                RemoteSleepInd = 1;
              }
              else
              {
                RemotePrepareSleep = 1;
              }
              #endif

              /* Build NM tx message */
              SendMsgCmdSet = RING;
              SendMsgEcuNr  = logicalSuccessor;

              TimeCnt  = NM_COUNT_RING_MAX;
              nmAction = NM_ACTION_WAIT_RINGMSG;
            }
          }
        }
        break;

/*---------------------------------------------------------------------------*/
      case    NM_ACTION_WAIT_RINGMSG:
/*---------------------------------------------------------------------------*/
        #if defined ( NM_ENABLE_ONM_EXT_API )
        onmStateParam |= (NmMsgType)(NM_MSG_RING | NM_MSG_WAIT_RX); 
        #endif

        if(NmStatRingMsgRecv == 1)
        {
          #if defined ( NM_ENABLE_ONM_EXT_API )
          onmStateParam |= NM_MSG_RECEIVED; 
          #endif

          if((NmStatImAddressed == 1) && (NmStatActive == 1))
          {
            #if defined ( NM_ENABLE_ONM_EXT_API )
            /* 1st entry to switch the state to RING transmit -> Token received */
            onmStateParam |= NM_MSG_TOKEN_RECEIVED; 
            #endif

            #if defined ( NM_ENABLE_RINGDATA_ACCESS )
            if(NmStatRingStable == 1)
            {
              ApplNmIndRingData(NM_CHANNEL_APPLPARA_ONLY);  /* indicate ring data access valid */
            }
            #endif

            TimeCnt  = NM_COUNT_RING_TYP;
            nmAction = NM_ACTION_WAIT_SENDTOKEN;
          }
          else
          {
            /* Wait for the next RING message */
            TimeCnt = NM_COUNT_RING_MAX;
          }
        }

        if(NmStatActive == 1)
        {
          if(NmStatImSkippedOver == 1)
          {
            /* ESCAN00014119 */
            /*
              Don't touch the counter, Token should be transmitted by the next task call,
              if NM_COUNT_RING_TYP expires.
              If there is no Token present for the node, NM_COUNT_RING_MAX expires.
            */

            #if defined ( NM_ENABLE_ONM_EXT_API )
            onmStateParam |= (NmMsgType)(NM_MSG_SKIPPED_ALIVE | NM_MSG_WAIT_TX | NM_MSG_START_TX); 
            #endif

            /* transmit SKIPPED ALIVE message ------------------------ */
            TransmitSkippedAlive(NM_CHANNEL_NMPARA_ONLY);
          }
        }
        else
        {
          /* set RingStable on nmOff */

          if(NmStatRingPreStable == 1)  /* check config */
          {
            NmStatRingStable = 1;       /* set config bit */
          }
          else
          {
            NmStatRingPreStable = 1;
          }

          NmStatPrepSleep = NmStatBusSleepInd;

          #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
          /* Remote sleep indication is not defined in passive mode */                 
          #endif

        }

        if(TimeCnt == 0)
        { 
          /* receive timeout T_RING_MAX, goto start state */

          #if defined ( NM_ENABLE_ONM_EXT_API )
          onmStateParam |= NM_MSG_TIMEOUT_RX; 
          #endif

          nmAction = NM_ACTION_START;
        }
        break;
/*---------------------------------------------------------------------------*/
      case    NM_ACTION_LH_WAIT_LIMPHOME_TX:
      case    NM_ACTION_LH_PREPARE_SLEEP:
/*---------------------------------------------------------------------------*/
        ResetConfig(NM_CHANNEL_NMPARA_ONLY); /* internal function */
        NmStatLimpHome = 1;

        nmRxTxCnt &= (canuint8)~RX_CNT_MASK;  /* reset receive counter */

        #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
        /* If GW is in limphome mode, other networks should */
        /* not be hindered to enter sleep mode */
        RemotePrepareSleep = 1;
        RemoteSleepInd     = 1;
        #endif

        if(NmStatNmMsgRecv == 1)
        {
          NmStatNmMsgRecvRemind = 1;
        }

        if((NmStatNmMsgRecvRemind == 1) &&
           (NmStatBusError == 0 /* ESCAN00047102 */) &&
           ((NmStatActive == 0) || (nmRxTxCnt == 0)))
        {
          nmRxTxCnt = 0;
          /* time critical case: work immediately on new state */
          nmAction = (NmActionType)(NM_ACTION_START | NM_ACTION_REPEAT);
        }
        else
        {
          if(nmAction == NM_ACTION_LH_WAIT_LIMPHOME_TX)
          {
            #if defined ( NM_ENABLE_ONM_EXT_API )
            onmStateParam |= (NmMsgType)(NM_MSG_LIMPHOME | NM_MSG_WAIT_TX); 
            #endif
/*---------------------------------------------------------------------------*/
/*                      NM_ACTION_LH_WAIT_LIMPHOME_TX only                   */
/*---------------------------------------------------------------------------*/
            if(TimeCnt == 0)
            {
              if(NmStatBusError == 1)
              {
                NmStatBusError = 0;

                #if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
                /* makros must be encapsulated in this way */
                CanResetBusOffEnd(NM_CHANNEL_CANPARA_ONLY, kNmInitObject);
                #else
                CanResetBusOffEnd(kNmInitObject);
                #endif

                #if defined ( NM_ENABLE_EXTENDED_CALLBACK )
                ApplNmBusOffEnd(NM_CHANNEL_APPLPARA_ONLY);
                #endif
              }

              CanOnline(NM_CHANNEL_CANPARA_ONLY);

              if(NmStatActive == 1)
              {
                /* Send LIMPHOME message */

                #if defined ( NM_ENABLE_ONM_EXT_API )
                onmStateParam |= NM_MSG_START_TX; 
                #endif

                NmStatPrepSleep  = NmStatBusSleepInd;
                NmStatRxTxLockUd = 1; /* ESCAN00008104 - wait for NmConfirmation() */
                SendMessFlag     = 1; /* transmit LimpHome msg */

                nmRxTxCnt = TX_CNT_STEP;  /* set tx counter; use as Limphome tx mark */

                #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
                /* Remote sleep indication depends only on received sleep indication flags */                 
                #endif


                /* Build LIMPHOME message */
                SendMsgCmdSet = LIMPHOME;
                SendMsgEcuNr  = logicalSuccessor;
                SendSleepAck  = 0; /* ESCAN00007382 */
                SendSleepInd  = NmStatBusSleepInd;
              }

              TimeCnt = NM_COUNT_LIMPHOME;
            }

            if(NmStatActive == 0)
            {
              NmStatPrepSleep = NmStatBusSleepInd;

              #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
              /* Remote sleep indication is not defined in passive mode */                 
              #endif

            }

            if(NmStatPrepSleep == 1)
            {

              TimeCnt = NM_COUNT_RING_MAX;  /* start Timeout-Timer */
              /* time critical case: work immediately on new state  */
              nmAction = (NmActionType)(NM_ACTION_LH_PREPARE_SLEEP | NM_ACTION_REPEAT);
            }
          }
/*---------------------------------------------------------------------------*/
/*                      NM_ACTION_LH_PREPARE_SLEEP                           */
/*---------------------------------------------------------------------------*/
          else
          {
            if(NmStatPrepSleep == 1)
            {

              if(NmStatRingMsgRecv == 1)
              {
                TimeCnt = NM_COUNT_RING_MAX;  /* reset timer */
              }
              else
              {
                if(TimeCnt == 0)  /* start BusSleep */
                {
                  CanOffline(NM_CHANNEL_CANPARA_ONLY);

                  NmStatWaitBusSleep = 1;
                  NmStatRxTxLockUd   = 0; /* ESCAN00008104 */
                  SendMessFlag       = 0; /* cancel nm tx request */


                  if(NmStatBusError == 1)
                  {
                    NmStatBusError = 0;

                    #if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
                    /* makros must be encapsulated in this way */
                    CanResetBusOffEnd(NM_CHANNEL_CANPARA_ONLY, kNmInitObject);
                    #else
                    CanResetBusOffEnd(kNmInitObject);
                    #endif

                    #if defined (NM_ENABLE_EXTENDED_CALLBACK)
                    ApplNmBusOffEnd(NM_CHANNEL_APPLPARA_ONLY);
                    #endif
                  }

                  TimeCnt  = NM_COUNT_WAIT_BUSSLEEP;
                  nmAction = NM_ACTION_GO_BUSSLEEP;
                }
              }
            }
            else
            {
              /* Application-WakeUp */
              NmStatNmMsgRecvRemind = 0;

              TimeCnt  = NM_COUNT_LIMPHOME;  /* stop PREPARE_SLEEP */
              nmAction = NM_ACTION_LH_WAIT_LIMPHOME_TX;
            }
          }

/*---------------------------------------------------------------------------*/
        }
        break;
/*---------------------------------------------------------------------------*/
      case    NM_ACTION_GO_BUSSLEEP:
/*---------------------------------------------------------------------------*/
        ResetConfig(NM_CHANNEL_NMPARA_ONLY); /* internal function */
        NmStatNmMsgRecvRemind = 0;

        nmRxTxCnt = 0;

        /*
          Check counter for entry of BusSleep state here. This will cause a
          latency of up to one call cycle. Do not compare with NM_COUNT_WAIT_BUSSLEEP
          due to the TimeCnt decrement at top of this task with a free interrupt
          between the decrement and the check!
        */

        #if defined ( NM_ENABLE_EXTENDED_CALLBACK )
        if(TimeCnt == ((canuint8)(NM_COUNT_WAIT_BUSSLEEP - 1)))
        {
          /*
            Just call the callback here on task level.
            Do it in each case for a symmetric call of start and cancel callback.
          */
          ApplNmWaitBusSleep(NM_CHANNEL_APPLPARA_ONLY);
        }
        #endif

        if(NmStatPrepSleep == 0)   /* BusWakeUp called or NM msg without SleepInd received -> stop PrepareSleep */
        {
          NmStatWaitBusSleep = 0;  /* Leave the context, because of possible WakeUp detection in GotoMode() */

          CanOnline(NM_CHANNEL_CANPARA_ONLY); /* ESCAN00008463 - unlock CAN-Transmit path immediately */


          if(NmStatLimpHome == 1)
          {
            nmRxTxCnt = TX_CNT_STEP;  /* set tx counter, use as LIMPHOME */

            #if defined ( NM_ENABLE_FAST_BUSOFF_RECOVERY )
            if((NmStatBusError == 1) && (nmBusOffCounter > 0)) /* ESCAN00010498 */
            {
              TimeCnt = NM_COUNT_LIMPHOME_SHORT;  /* stop PREPARE_SLEEP */
            } 
            else
            {
              TimeCnt = NM_COUNT_LIMPHOME;  /* stop PREPARE_SLEEP */
            }
            #else
            TimeCnt   = NM_COUNT_LIMPHOME;  /* stop PREPARE_SLEEP */
            #endif

            nmAction  = NM_ACTION_LH_WAIT_LIMPHOME_TX;  /* start state LIMPHOME */
          }
          else
          {
            nmAction  = (NmActionType)(NM_ACTION_START | NM_ACTION_REPEAT);
          }

          #if defined ( NM_ENABLE_EXTENDED_CALLBACK )
          /*
            WaitBusSleep leaved for LIMPHOME and for normal state.
            For LIMPHOME CAN is offline till next call of the NM task.
          */
          ApplNmWaitBusSleepCancel(NM_CHANNEL_APPLPARA_ONLY);
          #endif
        }
        else
        {
          if(TimeCnt == 1)
          {
            CanOffline(NM_CHANNEL_CANPARA_ONLY);

            NmStatRxTxLockUd = 0; /* ESCAN00008104 */
            SendMessFlag     = 0; /* cancel nm tx request */

            /* init CAN-Chip; clear Tx requets */
            #if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
            /* makros must be encapsulated in this way */
            CanResetBusSleep(NM_CHANNEL_CANPARA_ONLY, kNmInitObject);
            #else
            CanResetBusSleep(kNmInitObject);
            #endif
          }
          else
          {
            if(TimeCnt == 0)
            {
              NmStatWaitBusSleep = 0;
              NmStatBusSleep     = 1;

              ApplNmCanSleep(NM_CHANNEL_APPLPARA_ONLY);    /* switch off CAN path */
              ApplNmCanBusSleep(NM_CHANNEL_APPLPARA_ONLY); /* indicate bus sleep */

              nmAction = NM_ACTION_BUS_SLEEP;
            }
          }
        }
        break;
/*---------------------------------------------------------------------------*/
      case    NM_ACTION_BUS_SLEEP:
/*---------------------------------------------------------------------------*/
        NmStatLimpHome = 0;

        /* Application called wakeup or any NM message received */
        if(NmStatPrepSleep == 0) /* ESCAN00007436 */
        {
          NmStatBusSleep = 0;


          ApplNmCanNormal(NM_CHANNEL_APPLPARA_ONLY); /* wakeup CAN-chip and transceiver */
          CanOnline(NM_CHANNEL_CANPARA_ONLY); /* unlock tx path */
          #if defined ( NM_ENABLE_EXTENDED_CALLBACK )
          ApplNmBusStart(NM_CHANNEL_APPLPARA_ONLY);
          #endif

          nmAction = (NmActionType)(NM_ACTION_START | NM_ACTION_REPEAT);
        }
        break;
/*---------------------------------------------------------------------------*/
      case    NO_ACTION:
      case    NM_ACTION_REPEAT:
      default :
/*---------------------------------------------------------------------------*/
        ResetConfig( NM_CHANNEL_NMPARA_ONLY ); /* internal function */
        NmStatGlobal    = 0;
        NmStatLocal     = 0;
        SendMessFlag    = 0;  /* ESCAN00004259 */

        TimeCnt         = 0;
        nmRxTxCnt       = 0;  /* Reset watch counter */
        NmSourceAddress = kNmEcuNr;  /* initial value - self addressed */

        #if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION )
        PrepareSendSleepAck = 0;
        SendSleepAck        = 0;
        #endif

        #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
        RemotePrepareSleep = 0;
        RemoteSleepInd     = 0;
        #endif
        break;
    }/* switch(nmAction) */


    #if defined ( NM_ENABLE_ONM_EXT_API )
    OnmExtTask(NM_CHANNEL_NMPARA_FIRST onmStateParam); 
    #endif    

    ResetMessRecvFlags();

/*---- Restore old Interrupt Mask -------------------------------------------*/
    CanInterruptRestore();

/*---------------------------------------------------------------------------*/
  }while(nmAction & NM_ACTION_REPEAT); /*repeat immediately on new state*/
/*---------------------------------------------------------------------------*/

  /*---- Send if there is s.th to send -------------------------------------*/
  if((SendMessFlag == 1) && (NmStatActive == 1))
  {
    if(CanTransmit(kNmTxObj) == kCanTxOk)
    {
      SendMessFlag = 0; /* tx accepted, wait for NmConfirmation() */
    }
  }

  StopMeasure(NmTaskTimings);

} /* end of NmTask() */
/* CODE CATEGORY 1 END*/


/************************************************************************
| NAME:               GotoMode
| PROTOTYPE:          void GotoMode( NMModeName mode )
| CALLED BY:          Station Manager, Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   BusSleep: SM / Application is ready to sleep
|                     Awake:    CAN bus is required by SM / Application
| RETURN VALUE:       -
| DESCRIPTION:        Set/clear status bit 'BusSleepInd' and
|                     clear 'PrepareSleep'
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* CODE CATEGORY 2 START*/
void NM_API_CALL_TYPE GotoMode(NM_CHANNEL_NMTYPE_FIRST NMModeName mode)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  CanInterruptDisable();

  if(mode == BusSleep)
  {
    NmStatBusSleepInd = 1;
  }
  else if(mode == Awake)
  {

    #if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION )
    PrepareSendSleepAck = 0;
    SendSleepAck        = 0;
    #endif

    #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
    /* Change of local bus sleep indication state */
    /* does not effect remote sleep */
    #endif

    NmStatBusSleepInd = 0;
    NmStatPrepSleep   = 0;
  }

  CanInterruptRestore();
} /* end of GotoMode() */
/* CODE CATEGORY 2 END*/

/************************************************************************
| NAME:               GetStatus
| PROTOTYPE:          void GetStatus (NmStatusType* dest)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   Pointer to application specific variable
| RETURN VALUE:       -
| DESCRIPTION:        Copies the current NM state into an application
|                     specific variable
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
/* CODE CATEGORY 3 START*/
void NM_API_CALL_TYPE GetStatus(NM_CHANNEL_NMTYPE_FIRST NmStatusType *dest)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  *dest = (NmStatusType)(NmStatGlobal);
} /* end of GetStatus() */
/* CODE CATEGORY 3 END*/

/************************************************************************
| NAME:               NmGetStatus
| PROTOTYPE:          NmStatusType NmGetStatus(void)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   -
| RETURN VALUE:       Current NM status
| DESCRIPTION:        -
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
/* CODE CATEGORY 3 START*/
NmStatusType NM_API_CALL_TYPE NmGetStatus(NM_CHANNEL_NMTYPE_ONLY)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  return((NmStatusType)(NmStatGlobal));
} /* end of NmGetStatus()*/
/* CODE CATEGORY 3 END*/


/************************************************************************
| NAME:               StartNM
| PROTOTYPE:          void StartNM(void)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   -
| RETURN VALUE:       -
| DESCRIPTION:        Starts the local network management
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* CODE CATEGORY 3 START*/
void NM_API_CALL_TYPE StartNM ( NM_CHANNEL_NMTYPE_ONLY )
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  /* !!! Not used, because direct usage of CAN channel for NmOsekInit() call
    channel = NmCanToNmIndirection[channel];
  */
  #endif
  /* only here routing the physical channels directly */
  NmOsekInit(NM_CHANNEL_NMPARA_FIRST NM_NORMAL);
} /* end of StartNM() */
/* CODE CATEGORY 3 END*/


/************************************************************************
| NAME:               StopNM
| PROTOTYPE:          void StopNM(void)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   -
| RETURN VALUE:       -
| DESCRIPTION:        Stops the local network management
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* CODE CATEGORY 3 START*/

void NM_API_CALL_TYPE StopNM(NM_CHANNEL_NMTYPE_ONLY)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  /* !!! Not used, because direct usage of CAN channel for NmOsekInit() call
    channel = NmCanToNmIndirection[channel];
  */
  #endif
  /* only here routing the physical channels directly */
  NmOsekInit(NM_CHANNEL_NMPARA_FIRST NM_DISABLE);
} /* end of StopNM() */
/* CODE CATEGORY 3 END*/


/************************************************************************
| NAME:               TalkNM
| PROTOTYPE:          void TalkNM(void)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   -
| RETURN VALUE:       -
| DESCRIPTION:        Switching on of net management
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* CODE CATEGORY 3 START*/
void NM_API_CALL_TYPE TalkNM(NM_CHANNEL_NMTYPE_ONLY)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  CanInterruptDisable();
  NmStatActive = 1;
  CanInterruptRestore();
} /* end of TalkNM() */
/* CODE CATEGORY 3 END*/

/************************************************************************
| NAME:               SilentNM
| PROTOTYPE:          void SilentNM(void)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   -
| RETURN VALUE:       -
| DESCRIPTION:        Switching off of net management
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* CODE CATEGORY 3 START*/
void NM_API_CALL_TYPE SilentNM(NM_CHANNEL_NMTYPE_ONLY)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  CanInterruptDisable();
  NmStatActive = 0;
  CanInterruptRestore();
} /* end of SilentNM() */
/* CODE CATEGORY 3 END*/

#if defined ( NM_ENABLE_RINGDATA_ACCESS )
/************************************************************************
| NAME:               ReadRingData
| PROTOTYPE:          StatusType ReadRingData(canuint8 * ringData)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   DataPtr: Pointer to a target field, there the
|                              current user data are copied to
| RETURN VALUE:       -
| DESCRIPTION:        copies the current user data into an
|                     application specific buffer
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* CODE CATEGORY 2 START*/
StatusType NM_API_CALL_TYPE ReadRingData(NM_CHANNEL_NMTYPE_FIRST canuint8 *ringData)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  if(NmStatRingStable == 0)
  {
    return(E_NotOK);
  }
  else
  {
    #if defined ( NM_ENABLE_COPY_RINGDATA )
    CanInterruptDisable();
    /* normal OSEK mechanism - received ring data are in send buffer */
    *(ringData    ) = SendMsgUser0;
    *(ringData + 1) = SendMsgUser1;
    *(ringData + 2) = SendMsgUser2;
    *(ringData + 3) = SendMsgUser3;
    *(ringData + 4) = SendMsgUser4;
      #if defined ( NM_TYPE_DBAG_OSEK )
      #else
    *(ringData + 5) = SendMsgUser5;
      #endif  /* NM_TYPE_DBAG_OSEK */
    CanInterruptRestore();

    return(E_OK);
    #else
      #if defined ( NM_ENABLE_COPY_RINGDATA_TO_TEMPBUFFER )
    CanInterruptDisable();
    /* Read the received ring data, which have been copied to global buffer */
    *(ringData    ) = RecvCopyMsgUser0;
    *(ringData + 1) = RecvCopyMsgUser1;
    *(ringData + 2) = RecvCopyMsgUser2;
    *(ringData + 3) = RecvCopyMsgUser3;
    *(ringData + 4) = RecvCopyMsgUser4;
      #if defined ( NM_TYPE_DBAG_OSEK )
      #else
    *(ringData + 5) = RecvCopyMsgUser5;
      #endif  /* NM_TYPE_DBAG_OSEK */     
    CanInterruptRestore();

    return(E_OK);
      #else
        #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
    *ringData = *ringData;
        #endif
    /* The received data are not copied - there is nothing to read !*/
    return(E_NotOK);
      #endif
    #endif 
  }
} /* end of ReadRingData()*/
/* CODE CATEGORY 2 END*/


/************************************************************************
| NAME:               TransmitRingData
| PROTOTYPE:          StatusType TransmitRingData(canuint8 * ringData)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   DataPtr: Pointer to a source field, there the
|                              current user data are copied from
| RETURN VALUE:       -
| DESCRIPTION:        copies the current user data from application
|                     specific buffer into user data of nm message
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* CODE CATEGORY 2 START*/
StatusType NM_API_CALL_TYPE TransmitRingData( NM_CHANNEL_NMTYPE_FIRST canuint8 * ringData )
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  if(NmStatTxRingDataAllow == 0) /* user(ring)data access disabled? */
  {
    return(E_NotOK);
  }
  else
  {
    CanInterruptDisable();
    SendMsgUser0  = *(ringData    );
    SendMsgUser1  = *(ringData + 1);
    SendMsgUser2  = *(ringData + 2);
    SendMsgUser3  = *(ringData + 3);
    SendMsgUser4  = *(ringData + 4);
    #if defined ( NM_TYPE_DBAG_OSEK )
    #else
    SendMsgUser5  = *(ringData + 5);
    #endif  /* NM_TYPE_DBAG_OSEK */
    CanInterruptRestore();

    return(E_OK);
  }
} /* end of TransmitRingData()*/
/* CODE CATEGORY 2 END*/
#endif /* NM_ENABLE_RINGDATA_ACCESS ) */


#if defined ( NM_ENABLE_CONFIG )
/************************************************************************
| NAME:               CmpConfig
| PROTOTYPE:          NmReturnType CmpConfig(canuint8 idx)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   idx: Index in ConfigMaskTable and TargetConfigTable
| RETURN VALUE:       1: Current configuration is matching
|                     0: Current Configuration is wrong
| DESCRIPTION:        compares current configuration ( registered CAN nodes )
|                     with a expected config stored in memory
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* CODE CATEGORY 3 START*/
NmReturnType CmpConfig(NM_CHANNEL_NMTYPE_FIRST canuint8 idx)
{
  canuint8 configByte;

  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  CanInterruptDisable();

  #if defined ( NM_ENABLE_INDEXED_NM )
  for(configByte =   channel      * (canuint8)(NM_NUMBER_OF_CONFIG_NODES/8);
      configByte < ((channel + 1) * (canuint8)(NM_NUMBER_OF_CONFIG_NODES/8));
      configByte++)
  #else
  for(configByte = 0; configByte < (canuint8)(NM_NUMBER_OF_CONFIG_NODES/8); configByte++)
  #endif
  {
    if((TargetConfigTable[idx].nmConfigChar[configByte] ^ nmConfig.nmConfigChar[configByte])
        & ConfigMaskTable[idx].nmConfigChar[configByte])
    {
      CanInterruptRestore();
      return(0);
    }
  }

  CanInterruptRestore();
  return(1);
} /* end of CmpConfig() */
/* CODE CATEGORY 3 END*/

/************************************************************************
| NAME:               GetConfig
| PROTOTYPE:          void GetConfig(NmConfigType *DataPtr)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   DataPtr: Pointer to a target field, there the
|                              current configuration is copied to
| RETURN VALUE:       -
| DESCRIPTION:        copies the current configuration ( registered CAN nodes )
|                     into an application specific buffer
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* CODE CATEGORY 3 START*/
void NM_API_CALL_TYPE GetConfig(NM_CHANNEL_NMTYPE_FIRST NmConfigType *dataPtr)
{
  canuint8 configByte;

  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  CanInterruptDisable();

  #if defined ( NM_ENABLE_INDEXED_NM )
  for(configByte =   channel      * (canuint8)(NM_NUMBER_OF_CONFIG_NODES/8);
      configByte < ((channel + 1) * (canuint8)(NM_NUMBER_OF_CONFIG_NODES/8));
      configByte++)
  #else
  for(configByte = 0; configByte < (canuint8)(NM_NUMBER_OF_CONFIG_NODES/8); configByte++)
  #endif
  {
    dataPtr->nmConfigChar[configByte] = nmConfig.nmConfigChar[configByte];
  }

  CanInterruptRestore();
} /* end of GetConfig() */
/* CODE CATEGORY 3 END*/
#endif /* NM_ENABLE_CONFIG */


#if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION )
/************************************************************************
| NAME:               NmGetPrepareSendSleepAck
| PROTOTYPE:          canuint8 NmGetPrepareSendSleepAck(void)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   -
| RETURN VALUE:       Actual prepare sleep ack state
| DESCRIPTION:        Returns actual prepare sleep ack state of net management
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* CODE CATEGORY 3 START*/
canuint8 NM_API_CALL_TYPE NmGetPrepareSendSleepAck(NM_CHANNEL_NMTYPE_ONLY)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  if(PrepareSendSleepAck == 1)
  {
    return(1);
  }
  else
  {
    return(0);
  }
} /* end of NmGetPrepareSendSleepAck()*/
/* CODE CATEGORY 3 END*/


/************************************************************************
| NAME:               NmGetSendSleepAck
| PROTOTYPE:          canuint8 NmGetSendSleepAck(void)
| CALLED BY:          Application
| PRECONDITIONS:      Prepare Send Sleep Ack has to be set
| INPUT PARAMETERS:   -
| RETURN VALUE:       Actual state of sleep ack flag in send buffer
| DESCRIPTION:        Returns actual state of sleep ack flag in send buffer of net management
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* CODE CATEGORY 3 START*/
canuint8 NM_API_CALL_TYPE NmGetSendSleepAck(NM_CHANNEL_NMTYPE_ONLY)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  if(SendSleepAck == 1)
  {
    return(1);
  }
  else
  {
    return(0);
  }
} /* end of NmGetSendSleepAck()*/
/* CODE CATEGORY 3 END*/
#endif /* defined ( NM_ENABLE_SLEEPACK_NOTIFICATION ) */


#if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
/************************************************************************
| NAME:               NmGetRemoteSleepInd
| PROTOTYPE:          canuint8 NmGetRemoteSleepInd(void)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   -
| RETURN VALUE:       Actual remote sleep indication state
| DESCRIPTION:        Returns actual remote sleep indication state of net management
| GLOBAL DATA:
| STACK:
| RUNTIME:
|*************************************************************************/
/* CODE CATEGORY 3 START*/
canuint8 NM_API_CALL_TYPE NmGetRemoteSleepInd(NM_CHANNEL_NMTYPE_ONLY)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  channel = NmCanToNmIndirection[channel];
  #endif

  if(RemoteSleepInd == 1)
  {
    return(1);
  }
  else
  {
    return(0);
  }
} /* end of NmGetRemoteSleepInd()*/
/* CODE CATEGORY 3 END*/
#endif /* NM_ENABLE_REMOTESLEEP_INDICATION */


#if defined ( NM_ENABLE_ONM_EXT_API )
/************************************************************************
| NAME:               NmGetUdStartAddress
| PROTOTYPE:          canuint8* NmGetUdStartAddress(void)
| CALLED BY:          OnmExt functions
| PRECONDITIONS:      -
| INPUT PARAMETERS:   -
| RETURN VALUE:       Pointer to first User Data byte
| DESCRIPTION:        The pointer is valid after initialization for the
|                     whole running time.
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
/* CODE CATEGORY 3 START*/
canuint8* NM_API_CALL_TYPE NmGetUdStartAddress(NM_CHANNEL_NMTYPE_ONLY)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  /* !!! Not used, because only for module internal usage on NM cannel allowed
    channel = NmCanToNmIndirection[channel];
  */
  #endif

  return(&(SendMsgUser0));
} /* end of NmGetUdStartAddress() */
/* CODE CATEGORY 3 END*/

/************************************************************************
| NAME:               NmReadRecvSourceAddress
| PROTOTYPE:          StatusType NmReadRecvSourceAddress(canuint8* source)
| CALLED BY:          OnmExt functions
| PRECONDITIONS:      Interrupts disabled
| INPUT PARAMETERS:   source address by reference
| RETURN VALUE:       E_NotOK, E_OK, current received source address by reference
| DESCRIPTION:        -
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
/* CODE CATEGORY 2 START*/
StatusType NM_API_CALL_TYPE NmReadRecvSourceAddress(NM_CHANNEL_NMTYPE_FIRST NmNodeType* source)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  /* !!! Not used, because only for module internal usage on NM cannel allowed
    channel = NmCanToNmIndirection[channel];
  */
  #endif

  if((NmStatBusError     == 1) ||
     (NmStatWaitBusSleep == 1) ||
     (NmStatBusSleep     == 1))
  {
    return(E_NotOK); /* Source address undefined */
  }
  else
  {
    /* Interrupts already blocked, because usage only allowed in ONMX */
    *source = (NmNodeType)NmSourceAddress;
    /* Interrupts already blocked, because usage only allowed in ONMX */

    return(E_OK);
  }
} /* end of NmReadRecvSourceAddress() */
/* CODE CATEGORY 2 END*/
#endif  /* NM_ENABLE_ONM_EXT_API */




#if defined ( NM_TYPE_DBAG_OSEK )
  #if defined ( NM_ENABLE_ONM_EXT_API )
/************************************************************************
| NAME:               NmGetRecvUdProtocolCommand
| PROTOTYPE:          canuint8 NmGetRecvUdProtocolCommand(void)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   -
| RETURN VALUE:       -
| DESCRIPTION:        Gets the User Data Protocol Command from the appropriate receive byte.
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
/* CODE CATEGORY 2 START*/
canuint8 NM_API_CALL_TYPE NmGetRecvUdProtocolCommand(NM_CHANNEL_NMTYPE_ONLY)
{
  canuint8 ProtocolCmd;

  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  /* !!! Not used, because only for module internal usage on NM cannel allowed
    channel = NmCanToNmIndirection[channel];
  */
  #endif

  /* Interrupts already blocked, because usage only allowed in ONMX */
  ProtocolCmd = (canuint8)(RecvUdCmd & UD_CMD_MASK);
  /* Interrupts already blocked, because usage only allowed in ONMX */

  return(ProtocolCmd);
} /* end of NmGetRecvUdProtocolCommand() */
/* CODE CATEGORY 2 END*/


/************************************************************************
| NAME:               NmGetSendUdProtocolCommand
| PROTOTYPE:          canuint8 NmGetSendUdProtocolCommand(void)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   -
| RETURN VALUE:       -
| DESCRIPTION:        Gets the User Data Protocol Command from the appropriate send byte.
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
/* CODE CATEGORY 2 START*/
canuint8 NM_API_CALL_TYPE NmGetSendUdProtocolCommand(NM_CHANNEL_NMTYPE_ONLY)
{
  canuint8 ProtocolCmd;

  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  /* !!! Not used, because only for module internal usage on NM cannel allowed
    channel = NmCanToNmIndirection[channel];
  */
  #endif

  /* Interrupts already blocked, because usage only allowed in ONMX */
  ProtocolCmd = (canuint8)(SendMsgSleep & UD_CMD_MASK);
  /* Interrupts already blocked, because usage only allowed in ONMX */

  return(ProtocolCmd);
} /* end of NmGetSendUdProtocolCommand() */
/* CODE CATEGORY 2 END*/


/************************************************************************
| NAME:               NmSetSendUdProtocolCommand
| PROTOTYPE:          void NmSetSendUdProtocolCommand(canuint8 ProtocolCmd)
| CALLED BY:          Application
| PRECONDITIONS:      -
| INPUT PARAMETERS:   ProtocolCmd: UD Protocol Command to set into the NM send message
| RETURN VALUE:       -
| DESCRIPTION:        Sets the User Data Protocol Command in the appropriate byte.
| GLOBAL DATA:        -
| STACK:              -
| RUNTIME:            -
|*************************************************************************/
/* CODE CATEGORY 2 START*/
void NM_API_CALL_TYPE NmSetSendUdProtocolCommand(NM_CHANNEL_NMTYPE_FIRST canuint8 ProtocolCmd)
{
  #if defined ( NM_ENABLE_INDEXED_NM ) && defined ( NM_ENABLE_CHANNEL_INDIRECTION )
  /* !!! Not used, because only for module internal usage on NM cannel allowed
    channel = NmCanToNmIndirection[channel];
  */
  #endif

  /* Interrupts already blocked, because usage only allowed in ONMX */
  SendMsgSleep = (canuint8)((canuint8)(ProtocolCmd      & UD_CMD_MASK      ) |
                                (canuint8)(SendMsgSleep & NM_SLEEP_CMD_MASK));
  /* Interrupts already blocked, because usage only allowed in ONMX */
} /* end of NmSetSendUdProtocolCommand() */
/* CODE CATEGORY 2 END*/
  #endif  /* NM_ENABLE_ONM_EXT_API */
#endif  /* NM_TYPE_DBAG_OSEK */





/****************************************************************************/
/* End of File                                                              */
/****************************************************************************/
