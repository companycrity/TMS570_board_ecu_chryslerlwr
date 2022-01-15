/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */



/******************************************************************************
| Project Name: O S E K   N e t w o r k   M a n a g e m e n t
|    File Name: N_ONMDEF.H
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
| 1999-12-13           Be      Compatibility for SINGLE_/MULTIPLE_RECEIVE_BUFFER
| 2000-02-28  3.12.00  dH      adaptation to new GenTool CANgen
|                              renamed callback functions to ApplNm...
|                              renamed timing parameters to NM_COUNT...
|                              changed NM_NumberOfConfigNodes to NM_NUMBER_OF_CONFIG_NODES
|                              changed NM_NumberOfConfigBytes to NM_NUMBER_OF_CONFIG_BYTES
|                              added plausibility checks
| 2000-02-15  3.15.00  Mr      changes according to DC-ONM ver. 3.14d
|                      Mr      StateNetSleepInd, PreNetSleepInd (DC-ONM) implemented
|                      Mr      Userdata-Protocol (UDP for DC-ONM) implemented
| 2000-04-10  3.16.00  Rn      conditional check RANGES
| 2000-04-12           Fz      added C_COMP_NEC_V85X
| 2000-05-30  3.17.00  Gz      unchanged
| 2000-06-02  3.18.00  Et      range mechanism not necessary for C_COMP_FJVGC
| 2000-08-15  3.20.00  Gu      adapted prototypes for ApplCanErrorPinSend()/Receive()
| 2000-08-15           Js      C_COMP_MITSUBISHI_M32R added, revision
| 2000-09-04           Js      bus diagnostics added and ringdata mechanism changed
| 2000-09-09           Gu      deleted old prototypes NmCanOff and NmCanOn
|                              adapted function prototypes and external macros
|                              added #define NmStateErrBit
| 2000-09-29  3.21.00  Js      NM_NO_COMPATIBILITY channel dependend added
| 2000-10-09  3.22.00  Gu      Updated versions of supported compiler
| 2000-10-19           Fr      no changes
| 2000-11-13           Bd      no changes
| 2000-11-15           Gu      added variable kNmBugfixVersion Bugfix support
| 2000-12-04  3.23.00  Gz      no changes
| 2000-12-18  3.24.00  Gu      no changes
| 2001-01-08           Gu      NM_DBAG_... -> NM_TYPE_DBAG
|                              added compatibility mode for old usage of NM_DBAG define 
|                              moved compatibility switch for DC_ONM
| 2001-02-14           Gu      no changes
| 2001-02-22  3.25.00  Rn      no changes
| 2001-02-23  3.26.00  Bs      no changes
| 2001-03-01           Gu      no changes
| 2001-03-19  3.27.00  Gu      no changes
| 2001-04-06           Gu      added new customer switch
|                              added prototypes for extended NM Callbacks
|                              changed statement ConfigMaskTable TargetConfigTable
|                              to avoid compiler warnings
| 2001-04-06           Sa      no changes
| 2001-04-09           Pl      no changes
|                      Gu      added compatibility mode for nmEcuNr->kNmEcuNr,
|                              nmTxObj->kNmTxObj, nmCanPara->kNmCanPara
| 2001-04-19  3.28.00  Gu      no changes
| 2001-04-26  3.29.00  Gu                     no changes
| 2001-06-08  3.30.00  Ba, Js  ESCAN00000792: Implementation for indexed usage of the NM
|                                             Remark: Compatibility modes are not adapted
| 2001-07-16  3.31.00  Ht                     no changes
|                      Gu                     no changes
|                                             no changes
|                              ESCAN00000933: deleted unnecessary pragma-statement for M16C
|                              ESCAN00000980: Adaptions for Ford
| 2001-07-27  3.32.00  Gu                     no changes
|                      Rn      ESCAN00001055: tempCanRxActualDLC deleted
|                      Ml      ESCAN00001069: added cast to avoid HC12 compiler errors
|                                             when using -pck option
| 2001-08-03  3.33.00  Gu      ESCAN00001127: Using old API with indexed NM causes
|                                             no compiler error anymore
|                              ESCAN00001124: declaration of ConfigMask and
|                                             TargetConfigTable restored 
|                      Js                     no changes
| 2001-08-23  3.34.00  Gu                     no changes
| 2001-08-30  3.35.00  Ba      ESCAN00001358: Support of Hiware compiler with Motorola HC08
| 2001-09-03  3.36.00  Gu      ESCAN00001375: Special inquiry in case
|                                             NM_NUMBER_OF_CONFIG_NODES is not used
| 2001-09-12  3.37.00  Gu      ESCAN00001446: no changes
|                      Gu      ESCAN00001463: no changes
| 2001-09-21  3.38.00  Gu      ESCAN00001480: no changes
|                      Gu, Js  ESCAN00001468: temporary buffer for userdata access
|                                             used for BMW
|                      Gu      ESCAN00001516: no changes
| 2001-10-25  3.39.00  Gu      ESCAN00001688: no changes
| 2001-11-01  3.40.00  Rn      ESCAN00001731: no changes
| 2001-11-05           Gu      ESCAN00001733: no changes
|                              ESCAN00001712: no changes
|                              ESCAN00001737: no changes
|                              ESCAN00001738: compatibility defines encapsulated
| 2001-11-07           Rn      ESCAN00001748: no changes
| 2001-11-29           Gu      ESCAN00001842: no changes
| 2001-12-13           Gu      ESCAN00001901: no changes
|                              ESCAN00001917: no changes
| 2002-01-03  3.41.00  Ml      ESCAN00001855: Added keywords for paging support
| 2002-01-15           Gu      ESCAN00002062: ApplWriteWakeUpInfo does not support
|                                             MEMORY_NEAR for Hiware Compiler
| 2002-01-22  3.42.00  Gu      ESCAN00002111: New features according to the new
|                                             specification of a car manufacturer
|                      Js      ESCAN00002210: refer ESCAN00001855, missed one type
| 2002-03-04  3.43.00  Js      ESCAN00002413: missed prototype for NmCountRingTypInitial_Field
|                              ESCAN00002757: configuration check of
|                                             NM_COUNT_RING_TYP_INITIAL removed
|                      Gu      ESCAN00001900: no changes
|                              ESCAN00002594: no changes
|                              ESCAN00002759: no changes
|                              ESCAN00002760: no changes
|                              ESCAN00002807: no changes
| 2002-05-24           Fz      ESCAN00002926: No changes
| 2002-06-18           Et      ESCAN00003089: support of physical multiple ECUs
| 2002-07-25           Js      ESCAN00002906: UdTask() and UdInit() renamed to
|                                             NmUserDataTask() and UserDataInit()
|                              ESCAN00002952: Missing prototypes added
| 2002-11-11  3.45.00  Js      ESCAN00004376: Formal changes
|                              ESCAN00004259: Use SendMessFlag in own byte, split NmStateType in to
|                                             two state types to avoid data inconsistency in nmState
|                              ESCAN00004286: kNmEcuNr handling for indexed NM
|                                             according to implementation of
|                                             ESCAN00003089 corrected
|                              ESCAN00002905: Some missed volatile types added
|                              ESCAN00003570: Header file guarded against
|                                             multiple inclusion
|                              ESCAN00004500: Further status functions according to ESCAN00004259
| 2003-02-22  3.46.00  Js      ESCAN00003535: No channel-Paramter for NmSendUserDataProtected
|                                             and NmSendUserDataunProtected
|                              ESCAN00004844: DC Userdata support will not compile in a code
|                                             doubled system
| 2003-03-17  3.47.00  Js      ESCAN00005108: no changes
| 2003-03-28  3.48.00  Js      ESCAN00005245: no changes
|                              ESCAN00005246: no changes
|                              ESCAN00003524: Memory qualifier for zero page mapping
|                                             for C_COMP_HIWARE_08
| 2003-05-06  3.49.00  Js      ESCAN00005573: no changes
| 2003-06-17  3.50.00  Js      ESCAN00004601: no changes
| 2003-09-03  3.51.00  Js      ESCAN00006420: no changes
| 2003-10-06  3.52.00  Js      ESCAN00006646: New features (2nd step) according to the new
|                                             specification of a car manufacturer
|                              ESCAN00006727: Error Pin detection does not work on
|                                             indexed multi channel NM for special OEM
|                              ESCAN00006769: no changes
|                              ESCAN00005970: no changes
|                              ESCAN00006771: no changes
|                              ESCAN00006891: no changes
|                              ESCAN00006916: no changes
| 2003-11-27  3.53.00  Js      ESCAN00007008: WakeUp Type Indication for a car manufacturer added
|                              ESCAN00007091: Changes according GENy introduction
|                              ESCAN00007216: User Data extracted for special car manufacturer
|                              ESCAN00007217: Generic NM adaptation API introduced
|                              ESCAN00006970: no changes
|                              ESCAN00006361: no changes
|                              ESCAN00007275: no changes
|                              ESCAN00007287: no changes
| 2004-01-28  3.54.00  Js      ESCAN00007369: ONMX send data access changed
|                              ESCAN00007382: no changes
| 2004-02-13  3.55.00  Rn      ESCAN00007561: no changes
| 2004-02-17  3.56.00  Js      ESCAN00007430: no changes
|                              ESCAN00007436: no changes
|                              ESCAN00007437: no changes
| 2004-03-11  3.57.00  Js      ESCAN00007856: no changes
|                              ESCAN00007535: no changes
|                              ESCAN00007530: no changes
|                              ESCAN00007822: no changes
|                              ESCAN00007866: Usage of Multiple ECU for special configuration
| 2004-04-05  3.58.00  Js      ESCAN00007954: Driver plausibility check deleted
|                              ESCAN00008104: no changes
|                              ESCAN00008229: no changes
|                              ESCAN00008463: no changes
|                              ESCAN00008466: Feature review and rework
|                              ESCAN00008489: Formal adaptations for specific car manufacturer
| 2004-06-29  3.59.00  Js      ESCAN00008585: StatusType defined according OSEK Binding Specification
|                              ESCAN00008665: no changes
| 2004-10-01  3.60.00  Js      ESCAN00009420: no changes
|                              ESCAN00009728: New Version Defines introduced
|                              ESCAN00009711: no changes
| 2004-10-14  3.61.00  Js      ESCAN00009728: New Version Defines introduced
| 2004-10-29  3.62.00  Js      ESCAN00010055: no changes
| 2004-11-29  3.63.00  Js      ESCAN00010415: Support of 256 nodes
|                              ESCAN00010454: no changes
|                              ESCAN00010455: Compatibility section for special OEMs removed
|                              ESCAN00010456: no changes
|                              ESCAN00010463: Fast BusOff recovery introduced
|                              ESCAN00010468: Extensions for special OEM removed
|                              ESCAN00010471: Generic compatibility section removed
|                              ESCAN00010498: no changes
| 2005-01-18  3.64.00  Js      ESCAN00010855: CarWakeUp for special OEM introduced
| 2005-11-14  3.64.01  Bus     ESCAN00012702: insert comments for different resource categories
| 2006-02-17  3.64.02  Mas     ESCAN00015398: adapted memory qualifiers in header file
| 2006-06-23  3.64.03  Mas     ESCAN00015719: adapted type qualifier in header file
| 2006-11-20  3.64.04  Mas     ESCAN00017962: no changes
| 2007-01-09  3.64.05  Mas     ESCAN00018853: corrected memory category tag
| 2007-05-22  3.64.06  Mas     ESCAN00020303: adapted type for NmTxObj_Field[]
|                              ESCAN00020580: no changes in this file
| 2007-06-05  3.64.07  Mas     ESCAN00020990: no changes in this file
|                              ESCAN00021051: no changes in this file
| 2007-09-20  3.64.08  Mas     ESCAN00014458: no changes in this file
| 2007-10-09  3.64.09  Mas     ESCAN00022178: adapted prototype of OnmExtPrecopy to match memory qualifiers
| 2008-08-05  3.64.10  Oh      ESCAN00029003: no changes
| 2008-10-20  3.64.11  Mas     ESCAN00030171: moved platform-specific definition of MEMORY_CAN
| 2009-05-15  3.64.12  Mas     ESCAN00028757: added support for QNX
|                      Mas     ESCAN00028089: no changes
|                      Mas     ESCAN00033467: no changes
| 2009-12-03  3.64.13  Mas     ESCAN00035150: no changes
| 2010-12-21  3.64.14  vismdr  ESCAN00014119: no changes in this file
| 2011-10-05  3.64.15  vismdr  ESCAN00047102: no changes in this file
| 2012-01-02  3.64.16  vismas  ESCAN00055784: Added API NmSetInitObject
|                              ESCAN00046063: no changes in this file
| 2012-06-25  3.64.17  vismdr  ESCAN00059554: no changes in this file
|*****************************************************************************/

/*  *****   STOPSINGLE_OF_MULTIPLE_COMMENT    *****  */

#ifndef NM_OSEK_H
#define NM_OSEK_H

/* STARTSINGLE_OF_MULTIPLE */

#if defined ( NM_API_CALL_TYPE )
#else
  #define NM_API_CALL_TYPE
#endif

#if defined ( NM_API_CALLBACK_TYPE )
#else
  #define NM_API_CALLBACK_TYPE
#endif

#if defined ( NM_INTERNAL_CALL_TYPE )
#else
  #define NM_INTERNAL_CALL_TYPE
#endif

/***************************************************************************/
/* External Data                                                           */
/***************************************************************************/


/* NM version */
/* ROM CATEGORY 4 START*/
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 kNmMainVersion;
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 kNmSubVersion;
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 kNmBugfixVersion;
/* ROM CATEGORY 4 END*/


#if defined ( NM_ENABLE_INDEXED_NM )
/* ROM CATEGORY 4 START */
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 NmCallCycle_Field[kNmNumberOfChannels];
/* ROM CATEGORY 4 END */
/* ROM CATEGORY 2 START */ 
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 NmCountRingTyp_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 NmCountRingMax_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 NmCountLimphome_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 NmCountWaitBussleep_Field[kNmNumberOfChannels];
/* ROM CATEGORY 2 END */

  #if defined ( VGEN_GENY )
    #if ( kNmNumberOfRanges > 1 )
    /* Ranges differ in their sizes from one channel to another */
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 canuint8  V_MEMROM2 NmRangeMask_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 canuint32 V_MEMROM2 NmRangeCode_Field[kNmNumberOfChannels];
/* ROM CATEGORY 1 END */
    #endif
  #endif

  #if defined ( NM_ENABLE_CHANNEL_INDIRECTION )
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 CanChannelHandle V_MEMROM2 NmCanToNmIndirection[kCanNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 CanChannelHandle V_MEMROM2 NmNmToCanIndirection[kNmNumberOfChannels];
/* ROM CATEGORY 1 END */
  #endif

  #if defined ( NM_ENABLE_MULTIPLE_NODES )
/* RAM CATEGORY 1 START */
V_MEMRAM0 extern V_MEMRAM1 canuint8 V_MEMRAM2 comMultipleECUCurrent[kCanNumberOfChannels];
/* RAM CATEGORY 1 END */
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 NmEcuNr_Field[kNmNumberOfChannels][kComNumberOfNodes];
/* ROM CATEGORY 1 END */
/* ROM CATEGORY 3 START */
V_MEMROM0 extern V_MEMROM1 CanTransmitHandle V_MEMROM2 NmTxObj_Field[kNmNumberOfChannels][kComNumberOfNodes];
/* ROM CATEGORY 3 END */
  #else
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 NmEcuNr_Field[kNmNumberOfChannels];
/* ROM CATEGORY 1 END */
/* ROM CATEGORY 3 START */
V_MEMROM0 extern V_MEMROM1 CanTransmitHandle V_MEMROM2 NmTxObj_Field[kNmNumberOfChannels];
/* ROM CATEGORY 3 END */
  #endif

/* ROM CATEGORY 3 START */
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 NmCanPara_Field[kNmNumberOfChannels];
/* ROM CATEGORY 3 END */

  #if defined ( NM_ENABLE_FAST_BUSOFF_RECOVERY )
/* ROM CATEGORY 2 START */ 
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 NmCountLimphomeShort_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 NmCountShortNumber_Field[kNmNumberOfChannels];
/* ROM CATEGORY 2 END */ 
  #endif
#endif /* NM_ENABLE_INDEXED_NM */



/***************************************************************************/
/* Defines                                                                 */
/***************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject : Nm_DirOsek CQComponent : Implementation */
#define NM_DIROSEK_VERSION          0x0364u
#define NM_DIROSEK_RELEASE_VERSION  0x17u

/* different handling of channel parameter in prototypes and funcion calls */
/* used for NM and CAN Driver functions */
#if defined ( NM_ENABLE_INDEXED_NM )
  #if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
    #define NM_CHANNEL_NMTYPE_ONLY     CanChannelHandle channel
    #define NM_CHANNEL_NMTYPE_FIRST    CanChannelHandle channel,
    #define NM_CHANNEL_NMPARA_ONLY     channel
    #define NM_CHANNEL_NMPARA_FIRST    channel,

    #if defined ( NM_ENABLE_CHANNEL_INDIRECTION )
      #define NM_CHANNEL_CANTYPE_ONLY  CanChannelHandle canChannel
      #define NM_CHANNEL_CANTYPE_FIRST CanChannelHandle canChannel,
      #define NM_CHANNEL_CANPARA_ONLY  NmNmToCanIndirection[channel]
      #define NM_CHANNEL_CANPARA_FIRST NmNmToCanIndirection[channel],
    #else
      #define NM_CHANNEL_CANTYPE_ONLY  NM_CHANNEL_NMTYPE_ONLY
      #define NM_CHANNEL_CANTYPE_FIRST NM_CHANNEL_NMTYPE_FIRST
      #define NM_CHANNEL_CANPARA_ONLY  NM_CHANNEL_NMPARA_ONLY
      #define NM_CHANNEL_CANPARA_FIRST NM_CHANNEL_NMPARA_FIRST
    #endif

    #define NM_CHANNEL_APPLTYPE_ONLY   NM_CHANNEL_NMTYPE_ONLY
    #define NM_CHANNEL_APPLTYPE_FIRST  NM_CHANNEL_NMTYPE_FIRST
    #define NM_CHANNEL_APPLPARA_ONLY   NM_CHANNEL_CANPARA_ONLY
    #define NM_CHANNEL_APPLPARA_FIRST  NM_CHANNEL_CANPARA_FIRST
  #else
    #error "Configuration error in NM_DIROSEK: NM indexed on driver without C_MULTIPLE_RECEIVE_CHANNEL not possible!"
  #endif
#else
  #define NM_CHANNEL_NMTYPE_ONLY         void
  #define NM_CHANNEL_NMTYPE_FIRST
  #define NM_CHANNEL_NMPARA_ONLY    
  #define NM_CHANNEL_NMPARA_FIRST

  #if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
    #define NM_CHANNEL_CANTYPE_ONLY      CanChannelHandle canChannel
    #define NM_CHANNEL_CANTYPE_FIRST     CanChannelHandle canChannel,

    #if defined ( NM_CAN_CHANNEL )
      #define NM_CHANNEL_CANPARA_ONLY    NM_CAN_CHANNEL
      #define NM_CHANNEL_CANPARA_FIRST   NM_CAN_CHANNEL,
    #else
      #if ( kNmNumberOfChannels > 1 )
        #error "Configuration error in NM_DIROSEK: NM non indexed on more then one channels with C_MULTIPLE_RECEIVE_CHANNEL not possible!"
      #else
        #define NM_CHANNEL_CANPARA_ONLY  0
        #define NM_CHANNEL_CANPARA_FIRST 0,
      #endif
    #endif
  #else
    #define NM_CHANNEL_CANTYPE_ONLY      NM_CHANNEL_NMTYPE_ONLY
    #define NM_CHANNEL_CANTYPE_FIRST     NM_CHANNEL_NMTYPE_FIRST
    #define NM_CHANNEL_CANPARA_ONLY      NM_CHANNEL_NMPARA_ONLY
    #define NM_CHANNEL_CANPARA_FIRST     NM_CHANNEL_NMPARA_FIRST
  #endif

  #define NM_CHANNEL_APPLTYPE_ONLY       NM_CHANNEL_NMTYPE_ONLY
  #define NM_CHANNEL_APPLTYPE_FIRST      NM_CHANNEL_NMTYPE_FIRST
  #define NM_CHANNEL_APPLPARA_ONLY
  #define NM_CHANNEL_APPLPARA_FIRST
#endif  /* NM_ENABLE_INDEXED_NM */

#if defined ( MEMORY_CAN )  /* ESCAN00005246 */
#else
    #define MEMORY_CAN
#endif

#if defined ( NM_ENABLE_INDEXED_NM )
  #define NMVAR_CH_DEF(var)               var[kNmNumberOfChannels] 
  #define NMVAR(var)                      var[channel]
#else
  #define NMVAR_CH_DEF(var)               var
  #define NMVAR(var)                      var
#endif

/***************************************************************************/
/* Data types                                                              */
/***************************************************************************/

/*---- data type for nm mode sleep / awake --------------------------------*/
typedef enum
{
  BusSleep = 0,
  Awake
}NMModeName;

/*---- data type for initial operating mode of nm -------------------------*/
typedef enum
{
  NM_DISABLE = 0,         /* do not start nm                            */
  NM_NORMAL,              /* start NM in talking mode without sleep ind */
  NM_NMPASSIVE,           /* start NM in silent mode without sleep ind  */
  NM_SLEEPIND,            /* start NM in talking mode with slep ind set */
  NM_SLEEPIND_NMPASSIVE,  /* start NM in talking mode with sleep ind    */
  NM_SENDSLEEPACK,        /* start NM - send nm message with sleep ack  */
  NM_CANSLEEP             /* start NM bus is in sleeping mode           */
}NmInitType;

/*---- data type for VAG CarWakeUp ----------------------------------------*/
typedef enum
{
  CarWupOff = 0,
  CarWupOn,
  CarWupOn1stReq
}tNmCommStateType;

/*---- data type for return value of CmpConfig ----------------------------*/
typedef canuint8 NmReturnType;

/*---- data type for ONMX adaptation --------------------------------------*/
typedef canuint8  NmNodeType;
/*---- data type for ONMX message type flags ------------------------------*/
typedef canuint16 NmMsgType;

/*---- data type for OSEK status type according binding specification -----*/
#if defined ( STATUSTYPEDEFINED )
/* Another OSEK component has already defined the status type */
#else
  #define STATUSTYPEDEFINED
  #define E_OK 0

typedef unsigned char StatusType;
#endif


/***************************************************************************/
/* Constant defines                                                        */
/***************************************************************************/

/*-------------------------------------------------------------------------*/
/*---- OSEK NM ERROR CODES                               64 - 95 ----------*/
/*---- OSEK NM Standard Return Types                     64 - 79 ----------*/
#define E_NotOK 64
/*---- OSEK NM Implementation Specific Additional Errors 80 - 95 ----------*/
/*-------------------------------------------------------------------------*/


/*---- ONMX message type flags for NmMsgType ------------------------------*/

/*
  Flags for Precopy and Confirmation.
  Knowledge about Timeout and Path information not necessary.
*/
#define NM_MSG_INVALID        ((NmMsgType)0x0000)
#define NM_MSG_RESET_ALIVE    ((NmMsgType)0x0001)
#define NM_MSG_SKIPPED_ALIVE  ((NmMsgType)0x0002)
#define NM_MSG_RING           ((NmMsgType)0x0004)
#define NM_MSG_LIMPHOME       ((NmMsgType)0x0008)
#define NM_MSG_SLEEP_IND      ((NmMsgType)0x0010)
#define NM_MSG_SLEEP_ACK      ((NmMsgType)0x0020)
/*
  Flags for Task.
*/
#define NM_MSG_TIMEOUT_RX     ((NmMsgType)0x0080)
#define NM_MSG_TIMEOUT_TX     ((NmMsgType)0x0100)
#define NM_MSG_WAIT_RX        ((NmMsgType)0x0200)
#define NM_MSG_WAIT_TX        ((NmMsgType)0x0400)
#define NM_MSG_START_TX       ((NmMsgType)0x0800)
#define NM_MSG_RECEIVED       ((NmMsgType)0x1000)
#define NM_MSG_TOKEN_RECEIVED ((NmMsgType)0x2000)

/* STOPSINGLE_OF_MULTIPLE */

/******************************************************************************
|
|
|    Area of definitions for NM channel 
|
|
******************************************************************************/


  #if defined ( NM_OSEK_H_CHANNEL )
  #else
    #define NM_OSEK_H_CHANNEL

    /* Compatibility for old generation tool */
    #if defined ( VGEN_GENY )
    #else
      #if defined ( NM_CONFIG_USED )
        #define NM_ENABLE_CONFIG
      #endif
      #if defined ( NM_RINGDATA_ACCESS_USED )
        #define NM_ENABLE_RINGDATA_ACCESS
      #endif
      #if defined ( NM_COPY_RINGDATA_USED )
        #define NM_ENABLE_COPY_RINGDATA
      #endif
      #if defined ( NM_TEMPBUFFER_RINGDATA_USED )
        #define NM_ENABLE_COPY_RINGDATA_TO_TEMPBUFFER
      #endif
      #if defined ( NM_TYPE_DBAG_OSEK )
        #if defined ( NM_TYPE_DBAG_USERDATA_ACCESS_USED )
          #define NM_ENABLE_USERDATA_ACCESS
        #endif
        #if defined ( NM_TYPE_DBAG_SEND_ALIVE_BROADCAST )
          #define NM_ENABLE_SEND_ALIVE_BROADCAST
        #endif
      #endif  /* NM_TYPE_DBAG_OSEK */
    #endif  /* VGEN_GENY */

    /***************************************************************************/
    /* Plausibility checks                                                     */
    /***************************************************************************/


    #if defined ( NM_ENABLE_COPY_RINGDATA )
      #if defined ( NM_ENABLE_COPY_RINGDATA_TO_TEMPBUFFER )
        #error "Configuration error in NM_DIROSEK: Copy of Ringdata only possible if temporary buffer for Ringdata disabled!"
      #endif
    #endif


    /* Number of NM nodes for configuration table: */
    #if defined ( NM_ENABLE_CONFIG )
      #if defined ( NM_NUMBER_OF_CONFIG_NODES )
        #if (( NM_NUMBER_OF_CONFIG_NODES > 0      )&& \
             ((NM_NUMBER_OF_CONFIG_NODES % 8) == 0)&& \
             ( NM_NUMBER_OF_CONFIG_NODES <= 256   )  )



        #else
          #error "Configuration error in NM_DIROSEK: Illegal value of NM_NUMBER_OF_CONFIG_NODES!"
        #endif
      #else
        #error "Configuration error in NM_DIROSEK: NM_NUMBER_OF_CONFIG_NODES not defined!"
      #endif
    #endif  /* #if defined ( NM_ENABLE_CONFIG ) */

    typedef canuint8 NmStatusType;

    #if defined ( NM_ENABLE_CONFIG )
      #if defined ( NM_ENABLE_INDEXED_NM )
    typedef struct
    {
      canuint8 nmConfigChar[NM_NUMBER_OF_CONFIG_NODES/8 * kNmNumberOfChannels];
    }NmConfigType;
      #else
    typedef struct
    {
      canuint8 nmConfigChar[NM_NUMBER_OF_CONFIG_NODES/8];
    }NmConfigType;
      #endif
    #endif /* NM_ENABLE_CONFIG */



    #if defined ( NM_ENABLE_INDEXED_NM )
    /* refer indexed section */
    #else 
      #if defined ( NM_ENABLE_MULTIPLE_NODES )
/* RAM CATEGORY 1 START */
        #if defined ( NM_CAN_CHANNEL )
    extern canuint8 comMultipleECUCurrent[kCanNumberOfChannels];
        #else
    extern canuint8 comMultipleECUCurrent;
        #endif
/* RAM CATEGORY 1 END */

/* ROM CATEGORY 1 START */
    V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 NmEcuNr_Field[kComNumberOfNodes];
/* ROM CATEGORY 1 END */
/* ROM CATEGORY 3 START */
    V_MEMROM0 extern V_MEMROM1 CanTransmitHandle V_MEMROM2 NmTxObj_Field[kComNumberOfNodes];
/* ROM CATEGORY 3 END */
      #endif
    #endif


    #if defined ( NM_ENABLE_CONFIG )
/* ROM CATEGORY 3 START */
    V_MEMROM0 extern V_MEMROM1 NmConfigType V_MEMROM2 ConfigMaskTable[];
    V_MEMROM0 extern V_MEMROM1 NmConfigType V_MEMROM2 TargetConfigTable[];
/* ROM CATEGORY 3 END */    
    #endif /* defined ( NM_ENABLE_CONFIG ) */


    /* init parameter set after bus off / before entering sleep mode */
  



    /***************************************************************************/
    /* Function prototypes and external macros                                 */
    /***************************************************************************/
    #define NmStateRingStable(state)          (((state)   & 0x01) ? 1 : 0)
    #define NmStateBusError(state)            (((state)   & 0x02) ? 1 : 0)
    #define NmStateActive(state)              (((state)   & 0x04) ? 1 : 0)
    #define NmStatePassive(state)             (((state)   & 0x04) ? 0 : 1)
    #define NmStateLimphome(state)            (((state)   & 0x08) ? 1 : 0)
    #define NmStateBusSleep(state)            (((state)   & 0x10) ? 1 : 0)
    #define NmStateWaitBusSleep(state)        (((state)   & 0x20) ? 1 : 0)
    #define NmStateTxRingDataAllowed(state)   (((state)   & 0x40) ? 1 : 0)
    #define NmStateBusSleepInd(state)         (((state)   & 0x80) ? 1 : 0)
    #define NmStateBusWakeUp(state)           (((state)   & 0x80) ? 0 : 1)

    /*--- functions called by NM ; defined by application -----------------------------*/
/* CODE CATEGORY 2 START*/
    extern void NM_API_CALLBACK_TYPE ApplNmCanNormal(NM_CHANNEL_APPLTYPE_ONLY);           /* switch bus hardware to running mode   */
/* CODE CATEGORY 2 END*/
/* CODE CATEGORY 2 START*/
    extern void NM_API_CALLBACK_TYPE ApplNmCanSleep(NM_CHANNEL_APPLTYPE_ONLY);            /* switch bus hardware to sleep mode     */
/* CODE CATEGORY 2 END*/
/* CODE CATEGORY 2 START*/
    extern void NM_API_CALLBACK_TYPE ApplNmCanBusSleep(NM_CHANNEL_APPLTYPE_ONLY);         /* indicates bus is sleeping now         */
/* CODE CATEGORY 2 END*/
/* CODE CATEGORY 1 START*/
    extern void NM_API_CALLBACK_TYPE ApplNmBusOff(NM_CHANNEL_APPLTYPE_ONLY);              /* indicates BusOff error occured        */
/* CODE CATEGORY 1 END*/

    #if defined ( NM_ENABLE_EXTENDED_CALLBACK )
/* CODE CATEGORY 1 START*/
    extern void NM_API_CALLBACK_TYPE ApplNmBusOffEnd(NM_CHANNEL_APPLTYPE_ONLY);           /* indicates end off BusOff error        */
/* CODE CATEGORY 1 END*/
/* CODE CATEGORY 1 START*/
    extern void NM_API_CALLBACK_TYPE ApplNmBusStart(NM_CHANNEL_APPLTYPE_ONLY);            /* indicates NM switches to normal mode  */
/* CODE CATEGORY 1 END*/
/* CODE CATEGORY 2 START*/
    extern void NM_API_CALLBACK_TYPE ApplNmWaitBusSleep(NM_CHANNEL_APPLTYPE_ONLY);        /* internal WaitBusSleep-Mode is entered */
/* CODE CATEGORY 2 END*/
/* CODE CATEGORY 2 START*/
    extern void NM_API_CALLBACK_TYPE ApplNmWaitBusSleepCancel(NM_CHANNEL_APPLTYPE_ONLY);  /* internal WaitBusSleep-Mode is left    */
/* CODE CATEGORY 2 END*/
    #endif

    #if defined ( NM_ENABLE_RINGDATA_ACCESS )
/* CODE CATEGORY 1 START*/
    extern void NM_API_CALLBACK_TYPE ApplNmIndRingData(NM_CHANNEL_APPLTYPE_ONLY);         /* indicates receiving of ring data      */
/* CODE CATEGORY 1 END*/
    #endif

    #if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION )
/* CODE CATEGORY 2 START*/
    extern canuint8 NM_API_CALLBACK_TYPE ApplNmSendSleepAck(NM_CHANNEL_APPLTYPE_ONLY);    /* indicates SleepAck transmission       */
/* CODE CATEGORY 2 END*/
    #endif


    /*--- functions exported by NM --------------------------------------------*/
/* CODE CATEGORY 3 START*/
    extern void NM_API_CALL_TYPE StartNM(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 3 END*/
/* CODE CATEGORY 3 START*/
    extern void NM_API_CALL_TYPE StopNM(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 3 END*/
/* CODE CATEGORY 2 START*/
    extern void NM_API_CALL_TYPE GotoMode(NM_CHANNEL_NMTYPE_FIRST NMModeName);
/* CODE CATEGORY 2 END*/
/* CODE CATEGORY 3 START*/
    extern void NM_API_CALL_TYPE TalkNM(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 3 END*/
/* CODE CATEGORY 3 START*/
    extern void NM_API_CALL_TYPE SilentNM(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 3 END*/
/* CODE CATEGORY 4 START*/
    extern void NM_API_CALL_TYPE NmOsekInit(NM_CHANNEL_NMTYPE_FIRST NmInitType);
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 1 START*/
    extern void NM_API_CALL_TYPE NmTask(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 1 END*/

/* CODE CATEGORY 3 START*/
    extern void             NM_API_CALL_TYPE   GetStatus(NM_CHANNEL_NMTYPE_FIRST NmStatusType*);
/* CODE CATEGORY 3 END*/
/* CODE CATEGORY 3 START*/
    extern NmStatusType NM_API_CALL_TYPE NmGetStatus(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 3 END*/

    #if defined ( NM_ENABLE_CONFIG )
/* CODE CATEGORY 3 START*/
    extern void         NM_API_CALL_TYPE GetConfig(NM_CHANNEL_NMTYPE_FIRST NmConfigType*);
/* CODE CATEGORY 3 END*/
/* CODE CATEGORY 3 START*/
    extern NmReturnType NM_API_CALL_TYPE CmpConfig(NM_CHANNEL_NMTYPE_FIRST canuint8);
/* CODE CATEGORY 3 END*/
    #endif

    #if defined ( NM_ENABLE_RINGDATA_ACCESS )
/* CODE CATEGORY 2 START*/
    extern StatusType NM_API_CALL_TYPE ReadRingData(NM_CHANNEL_NMTYPE_FIRST canuint8*);
/* CODE CATEGORY 2 END*/
/* CODE CATEGORY 2 START*/
    extern StatusType NM_API_CALL_TYPE TransmitRingData(NM_CHANNEL_NMTYPE_FIRST canuint8*);
/* CODE CATEGORY 2 END*/
    #endif

    #if defined ( NM_ENABLE_SLEEPACK_NOTIFICATION )
/* CODE CATEGORY 3 START*/
    extern canuint8 NM_API_CALL_TYPE NmGetPrepareSendSleepAck(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 3 END*/
/* CODE CATEGORY 3 START*/
    extern canuint8 NM_API_CALL_TYPE NmGetSendSleepAck(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 3 END*/
    #endif

    #if defined ( NM_ENABLE_REMOTESLEEP_INDICATION )
/* CODE CATEGORY 3 START*/
    extern canuint8 NM_API_CALL_TYPE NmGetRemoteSleepInd(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 3 END*/
    #endif

    #if defined ( NM_ENABLE_ONM_EXT_API )
    /* ONMX function work with already calculated internal NM channel */
/* CODE CATEGORY 1 START */
    extern void NM_INTERNAL_CALL_TYPE  OnmExtConfirmation(NM_CHANNEL_NMTYPE_FIRST NmMsgType);
/* CODE CATEGORY 1 END */
/* CODE CATEGORY 1 START */
    extern void NM_INTERNAL_CALL_TYPE  OnmExtPrecopy(NM_CHANNEL_NMTYPE_FIRST NmMsgType, canuint8 MEMORY_CAN*); /* ESCAN00022178 */
/* CODE CATEGORY 1 END */
/* CODE CATEGORY 4 START */
    extern void NM_API_CALL_TYPE       OnmExtInit(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 4 END */
/* CODE CATEGORY 2 START */
    extern void NM_API_CALL_TYPE       OnmExtTask(NM_CHANNEL_NMTYPE_FIRST NmMsgType);
/* CODE CATEGORY 2 END */
/* CODE CATEGORY 3 START*/
    extern canuint8*  NM_API_CALL_TYPE NmGetUdStartAddress(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 3 END*/
/* CODE CATEGORY 2 START*/
    extern StatusType NM_API_CALL_TYPE NmReadRecvSourceAddress(NM_CHANNEL_NMTYPE_FIRST NmNodeType*);
/* CODE CATEGORY 2 END */
    #endif


    #if defined ( NM_TYPE_DBAG_OSEK )
      #if defined ( NM_ENABLE_ONM_EXT_API )
/* CODE CATEGORY 2 START*/
    extern canuint8 NM_API_CALL_TYPE NmGetRecvUdProtocolCommand(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 2 END */
/* CODE CATEGORY 2 START*/
    extern canuint8 NM_API_CALL_TYPE NmGetSendUdProtocolCommand(NM_CHANNEL_NMTYPE_ONLY);
/* CODE CATEGORY 2 END */
/* CODE CATEGORY 2 START*/
    extern void     NM_API_CALL_TYPE NmSetSendUdProtocolCommand(NM_CHANNEL_NMTYPE_FIRST canuint8);
/* CODE CATEGORY 2 END */
      #endif
    #endif  /* NM_TYPE_DBAG_OSEK */




    #if defined ( NM_ENABLE_SETINITOBJECT )
extern void NmSetInitObject(NM_CHANNEL_NMTYPE_FIRST CanInitHandle initObject);
    #endif
  #endif /* #if defined ( NM_OSEK_H_CHANNEL ) */

#endif /* NM_OSEK_H */
