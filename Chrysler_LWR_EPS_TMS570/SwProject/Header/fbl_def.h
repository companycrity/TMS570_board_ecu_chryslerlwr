/****************************************************************************
|    File Name: FBL_DEF.H
|
|  Description: Main definitions for the Flash Boot Loader
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2003-2010 by Vector Informatik GmbH, all rights reserved.
|
| This software is copyright protected and proprietary 
| to Vector Informatik GmbH. Vector Informatik GmbH 
| grants to you only those rights as set out in the 
| license conditions. All other rights remain with 
| Vector Informatik GmbH.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| CB           Christian Baeuerle        Vector Informatik GmbH
| Fz           Ralf Fritz                Vector Informatik GmbH
| Hp           Armin Happel              Vector Informatik GmbH
| Ls           Konrad Lazarus            Vector Informatik GmbH
| ThS          Thomas Sommer             Vector Informatik GmbH
| WM           Marco Wierer              Vector Informatik GmbH
| ACP          Alexandre C. Plombin      Vector CANtech, Inc.
| An           Ahmad Nasser              Vector CANtech, Inc.
| Rr           Robert Schaeffner         Vector Informatik GmbH
| Ap           Andreas Pick              Vector Informatik GmbH
| MFR          Michael Radwick           Vector CANtech, Inc.
| Et           Thomas Ebert              Vector Informatik GmbH
| BJE          Ben Erickson              Vector CANtech, Inc.
| QPs          Quetty Palacios           Vector Informatik GmbH
| FHe          Florian Hees              Vector Informatik GmbH
| SWk          Slawomir Wilk             Vector Informatik GmbH
| Ci           Andre Caspari             Vector Informatik GmbH
| AWh          Andreas Wenckebach        Vector Informatik GmbH
| JHg          Joern Herwig              Vector Informatik GmbH
| Kak          Keith Kalski              Vector CANtech, Inc.
| Pal          Phil Lapczynski           Vector CANtech, Inc.
| Ach          Achim Strobelt            Vector Informatik GmbH
| TBe          Thomas Bezold             Vector Informatik GmbH
| MVi          Marcel Viole              Vector Informatik GmbH
| RLB          Ron Brockmiller           Vector CANtech, Inc.
| DJO          Dennis O'Donnell          Vector CANtech, Inc.
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  ----------------------------------------------
| 2002-01-16  00.09.00  CB      Creation
| 2002-02-21  00.91.00  Ls      Minor changes for the TMS470
|                               kCanTxOk/kCanTxFailed and kFblOk/kFblFailed added
|                               TMS470 added: start from appl over reset
| 2002-04-05  00.92.00  Ls      Define for SWM_DATA_ROW_SIZE updated
|                       ThS     Support for HC08 and VWTP1.6
| 2002-04-09  00.93.00  CB      Minor changes
|                               Definition of logical block table changed
|                               Definition of tLogicalBlockHeader removed (not used)
|                       ThS     tSWMI_PMA not necessary for VAG
| 2002-04-29  00.94.00  Ls      tSwmStoredDataTable: GM-section changed, 
|                               tSwmDataStdTable added
| 2002-05-07  00.95.00  Ls      tSwmDataStdTable only for GM
|                               FBL_ADDR_TYPE/FBL_MEMSIZE_TYPE for 
|                               C_COMP_TASKING_C16X changed
|                               MEMORY_HUGE added
| 2002-05-08            WM      Support for Hiware HC12 added
| 2002-05-16  00.96.00  Fz      Default value for FBL_REPEAT_CALL_CYCLE added
| 2002-05-16            Th      Added support of extended CAN identifier in 
|                               CanInitTable
| 2002-05-15            CB      ESCAN00002873: Additional definition of the MTAB
|                               magic flag value
| 2002-05-23            Ls      changes in the GM-section for GMW3110V1.4
| 2002-06-12            Ls      #pragma for IAR_M16C added to FblLogicalBlockTable
| 2002-07-02  00.97.00  CB      FBL_ADDR_TYPE and FBL_MEMSIZE_TYPE changed for HC12
|                       Ls      const -> MEMORY_ROM
|                       WM      Adaptation for PPC
| 2002-07-17  00.98.00  CB      ENABLE_PROGRAMMING_MODE added
|                       WM      Added FBL_BOTTOM_BOOT_BLOCK define for PPC
|                       Ls      Added FBL_BOTTOM_BOOT_BLOCK define for TMS470
| 2002-07-18  00.99.00  CB      ESCAN00003274: Additional assign flags in the LBT
| 2002-07-29            Ls      kBlockTypeExt added
| 2002-08-06            WM      ESCAN00003438: Removed block disposability from
|                               tBlockDescriptor
| 2002-08-26  01.00.00  CB      ESCAN00003600: Added address member in tSegmentInfo
| 2002-09-04  01.01.00  Ls      Modeswitches of TMS470 removed
| 2002-09-12  01.02.00  CB      ESCAN00003773: tFblHeader structure definition
|                                expanded
|                       Ls      ESCAN00003764: FblLogicalBlockTable mapping
|                                changed for M16C
| 2002-09-18  01.03.00  Fz      Erase counter of V850 removed
| 2002-09-16  01.04.00  ACP     Added ST9 + Security Access Defines for FORD
| 2002-09-26            ACP     Modified MEMORY_HUGE setting so that it still 
|                               works with FNOS
| 2002-10-07            WM      Minor changes for METROWERKS_PPC
| 2002-10-15  01.05.00  Fz      Support for Hitachi SH7047 added
| 2002-10-25            ACP     "_COMMENT" added to some C_COMP_GNU_ST9 ifdef's
| 2002-10-25  01.06.00  WM      Changes for DC version
| 2002-11-13  01.07.00  WM      Added paging support for HC12/STAR12
|                       WM      Added result types
| 2002-12-11  01.08.00  WM      Moved tSegmentInfo, tSegmentList to secmod.h
|                       WM      Added tFblAddress, tFblLength and tFblData for DC
| 2003-01-14  01.09.00  WM      ESCAN00004713: Fixed tFblAddress, tFblLength define
|                               Added tFblErrorType, tFblErrorCode and error 
|                               defines for DC
| 2003-02-04  01.10.00  An      Added C_COMP_TASKING_XC16X
| 2003-02-18  01.11.00  CB      Changed C_COMP_HEW_SH7055 -> C_COMP_HEW_SH705X
| 2003-03-20  01.12.00  CB      Minor changes for XC16X
| 2003-04-01  01.13.00  Rr      Minor changes for NEC v850SCx
| 2003-04-07  01.14.00  Rr      Removed C_COMP_ANSI_TMS_470
| 2003-04-30  01.15.00  WM      Minor changes for PPC
|                       WM      Minor changes for VAG
| 2003-05-20  01.16.00  WM      ESCAN00005703: Adaptations for C_COMP_HIWARE_12
|                       CB      ESCAN00005681: Support for ST10-CCAN
| 2003-06-04  01.17.00  WM      ESCAN00005759: Added COMP_COSMIC_12 support
|                               for VAG
| 2003-06-11  01.18.00  WM      ESCAN00005848: Adaptations for MB90F394H
| 2003-06-11  01.19.00  Ls      ESCAN00005966: minor changes for M16C, 
|                               tSwmStoredDataTable removed
| 2003-06-11  01.20.00  Rr      M32C added
|                               GM-Bootloader header added to the FBL-Header
| 2003-08-07  01.21.00  Ls      ESCAN00006198: M16C Mitsubishi added
|                       Th      ESCAN00006294: Changed C_ENABLE_EXTENDED_ID
|                               in FBL_ENABLE_EXTENDED_ID
|                       CB      Minor changes
| 2003-08-25  01.22.00  Ls      ESCAN00006477: FBL_ENABLE_START_OVER_RESET added
| 2003-09-05  01.23.00  WM      ESCAN00006539: Minor changes for PPC
| 2003-09-19  01.24.00  Rr      V850 added
| 2003-09-19  01.25.00  Rr      V850 NEC Compiler switch added
| 2003-11-05  01.26.00  Rr      ESCAN00006817: Add define
|                       Ls      ESCAN00006949: C_COMP_IAR_H8S added
| 2004-02-10  01.27.00  CB      ESCAN00007119: New OEM 
|                       Ls      ESCAN00007291: New OEM
|                       WM      ESCAN00007465: Adaptations for C_COMP_IAR_12
| 2004-02-27  01.28.00  Rr      Added new OEM
| 2004-03-23  01.29.00  ACP     Added new OEM
|                       Ls      ESCAN00007291: Minor changes for one OEM
|                       Hp      ESCAN00007972: Internal defines not properly 
|                                closed by #endif
|                       WM      ESCAN00008101: Minor changes for CLIENT_DC_UDS
|                       ACP     Added tSegmentInfo for Ford_GGDS
|                       AMN     Added GGDS to fblMode definitions, added 
|                               FBL_START_WITH_RESP
| 2004-05-13  01.30.00  Hp      Removing section definition of FBLMTAB for FJ16LX
| 2004-05-19  01.31.00  CB      Additional seed-key constant added
| 2004-06-28  01.32.00  Ls      ESCAN00008376: New OEM
|                       WM      Changes for new Organi version
|                       Fz      ESCAN00008684: Add changeable CGMCS for NEC V850
| 2004-08-03  01.33.00  WM      ESCAN00009056: Added space modifier to tExportFct
|                               for C_COMP_COSMIC_12
|                               ESCAN00009075: Added maximum number of 
|                                reprogramming cycles to tLogicalBlockTable
| 2004-08-18  01.34.00  WM      ESCAN00009216: Extended ECU PIN handling for
|                                CLIENT_CLAAS
|                               ESCAN00009267: Removed mtab related stuff from
|                                CLIENT_CLAAS section
| 2004-09-08  01.35.00  Ls      ESCAN00009561: Added C_COMP_HEW_H8S to 16Bit 
|                               declaration of FBL_XXX_TYPE
| 2004-09-11  01.36.00  AP      ESCAN00009454: Removing section definition of 
|                                FblLogicalBlockTable for NECV850/NEC
| 2004-09-11  01.37.00  Ls      ESCAN00009508: changed define dependencies for 
|                                FORD and GM in the mtab section
| 2004-09-23  01.38.00  Rr      ESCAN00009454: Corrected section definition of
|                               FblLogicalBlockTable for NECV850/NEC
|                       AMN     Added bitrate parameters for C_COMP_TASKING_ST10_CCAN
| 2004-10-05  01.39.00  Rr      ESCAN00009768: Naming convention
| 2004-10-26  01.40.00  Rr      Add support for M32R
|                       Ap      ESCAN00010007: Support for Vector canbedded
|                                components
| 2004-11-05  01.41.00  MFR     ESCAN00009049: Add return codes for SecurityAccess
|                                response
|                               Remove flash-driver version record from 
|                                SWMI-Root Table
|                               Add kFblBufferAlign to handle Flash source-buffer
|                                alignment
| 2004-11-08  01.42.00  Rr      Section definition changes for V850 GHS to support 
|                                different compiler options
| 2004-11-12  01.43.00  Hp      Adding TLCS-900 to the CanInit structure
|                       Rr      Minor changes due to version defines changes 
| 2004-11-29  01.44.00  Fz      Add error handling datatypes for VAG
| 2004-12-23  01.45.00  AMN     Converted FBL_CLIENT_GGDS to FBL_CLIENT_FORD_GGDS
|                       CB      Support for new OEM
| 2005-01-06  01.46.00  Fz      Add of NEC V850 PS2 
|                       Et      ESCAN00010695: Support TX19 series (TMP1984)
|                       WM      Minor change for MC9S12X
|                       AMN     Changed FBL_VERSION to FBLOEM_FORD_RELEASE_VERSION 
|                                for CLIENT_FORD
| 2005-01-25  01.47.00  CB      Changes for SLP8 
|                       CB      ESCAN00010787: Names of FblHeader members changed
| 2005-01-31  01.48.00  AMN     Added support for TMS320
|                       MHz     Addded support for SA level 2 (upload)
|                               changed define kProgRequest and kNoProgRequest
| 2005-02-28  01.49.00  AMN     Added START_OVER_RESET support for FORD_SLP3  
|                       CB      Added defines for FblHeader data and FblStart
|                               Minor changes for 78k0
| 2005-04-15  01.50.00  BJE     Changed FBL_MEMSIZE_TYPE to canuint32 for ST9
|                       BJE     Added ST9 specific CallFblStart macro and deleted
|                                extra #if defined(FBL_ENABLE_FBL_START)
| 2005-04-28  01.51.00  MHz     Removed double definition of access macros 
|                                for FblHeader, added tDecParam for CLIENT_FORD_GGDS
| 2005-04-29  01.52.00  WM      ESCAN00012128: Unbalanced parenthesis in macro
|                                definition (FBL_CLIENT_FORD)
| 2005-05-11  01.53.00  Hp      Add support for V85x/IAR+NEC
|                       Rr      Add OEM
|                               Minor changes
| 2005-04-29  01.54.00  WM      ESCAN00012128: Unbalanced parenthesis in macro
|                                definition
| 2005-07-26  01.55.00  Ls      C_COMP_HEW_SH2_RCAN added
|                       QPs     C_COMP_FUJITSU_FR60_CCAN added with CanInitBT2 
|                                definition for small baudrate
|                       FHe     Added support for C_COMP_METROWERKS_DSP5683X
| 2005-07-28  01.56.00  Rr      Added support for C_COMP_HEW_H8S_COMMENT
| 2005-08-10  01.57.00  AMN     Added defines of FblHeader and FblStart for FORD_GGDS
|                               Removed unnecessary FblSetStartWithResp macros for
|                                FORD_GGDS
| 2005-08-23  01.58.00  Rr      Added C_COMP_IAR_CR16 support
|                       QPs     Added C_COMP_FUJITSU_FR60_CCAN support
| 2005-09-13  01.59.00  Ls      ESCAN00013178: FBL_ENABLE_ROMMASK_FLAG added (PAG)
| 2005-11-09  01.60.00  MFR     Support for FBL_CLIENT_GM_SLP2
|                       BJE     Add support for 78k0 banked
|                       WM      ESCAN00013678: C_COMP_IAR_M16C/M32C added
|                       Rr      ESCAN00014218: removed possible compiler error if
|                                application and FBL are configured by GENy
| 2005-11-17  01.61.00  MFR     Match definition of tFblHeader to GENy for GM.
| 2005-12-08  01.62.00  swk     ESCAN00014459: Added C_COMP_KEIL_XC16X_COMMENT 
|                       QPs     ESCAN00014563: Added C_COMP_QCC_MGT5X00_MSCAN12
| 2005-12-29  01.63.00  FHe     Added NONBANKED pragma for FblStackInit and
|                               C_COMP_HIWARE_12 
| 2006-01-16  01.64.00  swk     ESCAN00014910: Encapsulated FblStackInit() 
|                               with FBL_CLIENT_FORD_SLP3_COMMENT
| 2006-01-25  01.65.00  QPs     ESCAN00015074: Added support for C_COMP_MTRWRKS_MPC5X00
| 2006-03-03  01.66.00  QPs     ESCAN00015168: Added support for C_COMP_DIABDATA_MPC55XX 
|                       Hp      Add PAG_SLP3 support
|                       Ci      Resolved Metrowerks compiler warnings C1020 and C4200
|                       AMN     Removed the redefinition of CallFblStart in case of Ford/SLP5
|                       FHe     Added CanInitTable support for MAC710X 
| 2006-04-11  01.67.00  Ls      Minor changes for PAG_SLP3
|                       ACP     ESCAN0015874: updated memory qualifiers to V_MEMROMx
|                                in "extern const tFlashEraseTable FlashEraseTable"
|                       Ci      Added section definitions for MTAB and magic 
|                                flags with C_COMP_NEC_V85X
|                       Rr      Added missing _COMMENT for C_COMP_xx_470
|                       ACP     Updated MEMORY_ROM to use V_MEMROMx for Ford GGDS section
|                                in "extern MEMORY_ROM tFblHeader FblHeader"
| 2006-05-03  01.68.00  BJE     ESCAN00016212: updated 78k0 memory type definition for mtab
| 2006-05-03  01.69.00  ACP     ESCAN00016400: updated FBL_ADDR/MEMSIZE_TYPE for PIC18
|                               ESCAN00016438:  Added kStartupPreInit/PostInit definition
|                                for new ApplFblStartup() parameter
| 2006-06-12  01.70.00  FHe     Added blockIndex for PAG SLP3 to logical block table
|                               Added flags for response after reset for PAG SLP3
|                               Added support for Vector SLP3 and VAG SLP2
| 2006-07-27  01.71.00  Rr      ESCAN00016815: Added support for C_PROCESSOR_FX3
|                       QPs     Added section definition for fblStartMagicFlag for
|                                C_COMP_GHS_V85X 
|                       Hp      ESCAN00017109: Added support for Avccore
| 2006-08-22  01.72.00  Ci      Added support for C_COMP_NEC_V85X
|                       Hp      ESCAN00017238: Add support for GM SLP3
|                       FHe     Added GM specific section to tSegmentInfo structure 
|                       QPs     Changed fblStartMagicFlag pragma for C_COMP_IAR_12 
| 2006-08-25  01.73.00  Hp      Use common definition of tSegmentInfo for GM-SLP3
|                       WM      ESCAN00017455: Changed prototypes of FblStackInit
|                                and ApplFblStart
|                       QPs     ESCAN00017629: Added support for 16FX - OEM Renault 
|                       swk     ESCAN00017711: Added support for KEIL and ST10F276x
|                       WM      ESCAN00017714: Additional entries in FBL header
|                               t able for FBL_ENABLE_META_DATA_ROM
|                       swk     ESCAN00017729: Added support for C_COMP_MTRWRKS_MCS08_MSCAN_COMMENT 
| 2006-10-04  01.74.00  swk     ESCAN00017851: New tBlockDescriptor and tLogicalBlockTable
|                                definition for GM SLP3. Add several macros.
|                       Hp      ESCAN00017919: Provide optionally include-file for memory mapping
| 2006-12-18  01.75.00  FHe     Added support for V850 PH derivatives
|                       QPs     ESCAN00018021: Changed fblStartMagicFlag pragma definition
|                                 for C_COMP_GHS_V85X
|                       CB      ESCAN00018080: New OEM 
|                       Hp      ESCAN00018246: Add support for new OEM HMC
|                       Hp      ESCAN00018248: Introduction of FBL assertions.
|                       Ci      ESCAN00018357: Corrected erroneous ifdef statement
|                       swk     ESCAN00018460: Warning supression fpr R8C and Metrowerks compiler
|                       Ci      ESCAN00018687: Add new assertion for missing forced RCRRP
|                       CB      ESCAN00018080: Minor changes
| 2007-02-07 01.76.00   Hp      ESCAN00018849: Remove CAN-specific defines
|                       AWh     Added Dx3 define for bustiming registers in tCanInitTable 
|                       QPs     ESCAN00018849: Minor changes
|                       Hp      Improvements for MISRA compliance.
|                               ESCAN00019414:  GetFblXXXVersion() macro cannot be used for some OEMs
| 2007-02-21 01.77.00   FHe     Added support for C_COMP_VDSP_BF5XX
| 2007-06-29 01.78.00   Pal     ESCAN00019752: Support for C_COMP_GHS_V85X
|                       Ls      Added support for 16FX_CCAN (tCanInitTable)
|                       FHe     ESCAN00020931: VAG SLP2 renamed to SLP3
|                       Rr      ESCAN00019752: Harmonized C_COMP_GHS_V85X section names, where available
|                       JHg     Add support for FBL_ENABLE_ENCRYPTION_MODE to PAG SLP3 and VAG SLP3
|                       Kak     ESCAN00021246: Removed MEMORY_HUGE qualifier from FblStartFct for IAR/V850
| 2007-07-31 01.79.00   Rr      ESCAN00021415: Added support for Mcf Coldfire
|                       Kak     ESCAN00021678: Added GM_SLP2 to #if to enable memmap for fblStartMagicFlag
|                       Swk     ESCAN00021682: Added support for PIC18(tCanInitTable) 
| 2007-08-03 01.80.00   Hp      ESCAN00021728: Separate Assertion defines in Fbl_Def into system and OEM-group
|                       Swk     ESCAN00021733: Added support for C_COMP_MICROCHIP_PIC18 new define of FblHeaderTable
| 2007-08-19 01.81.00   FHe     ESCAN00021732: Modernization Steps for Vector SLP1 (14230)
|                       JHg     ESCAN00021868: Use V850 FCAN derivatives to distinguish between
|                                FCAN and aFCAN specific options in tCanInitTable
|                       Fz      ESCAN00021812: Extern for CanInitTable added
| 2007-10-10 01.82.00   FHe     ESCAN00013178: FBL_ENABLE_ROMMASK_FLAG added (PAG UDS)
|                       Fz      ESCAN00022365: Macro GetFblSWMI causes compiler error
|                       Ci      ESCAN00022471: Added support for GNU compiler
| 2007-11-22 01.83.00   AWh     ESCAN00022936: Added support for C_COMP_GHS_470
|                       JHg     ESCAN00023241: Added support for C_COMP_TASKING_XC2000_MULTICAN
|                               Added flags for response after reset for DC UDS
| 2007-12-03 01.84.00   WM      ESCAN00024160: Added banking support for MCS08
| 2008-01-23 01.85.00   Ci      ESCAN00024044: Added type definition tTpDataType
|                                for TPMC configurations
|                       WM      ESCAN00024160: Added banking support for MCS08
| 2008-02-06 01.86.00   WM      ESCAN00024160: Modified FblStart definition for
|                                MCS08 to support banked FBL
| 2008-03-07 01.87.00   Hp      ESCAN00024986: Extending tDecParam structure with elements:
|                                mode, dataOutBuffer, dataOutLength and 
|                                dataOutMaxLength (data decompression)
|                       JHg     ESCAN00025270: Added support for Volvo AB
|                       Ci      ESCAN00025085: Removed unused tFblHeader
|                                 members for OEM Ford
| 2008-03-13 01.88.00   Ci      ESCAN00025071: Added kStartup constant for
|                                stay-in-boot configurations
|                       Ci      ESCAN00025264: Added fblMode WAIT_FOR_PING and
|                                corresponding access macro
|                       CB      ESCAN00025384: Watchdog function pointer def. in tDecParam
| 2008-07-05 01.89.00   JHg     Added ROM flash driver array to header
|                               Added RSA seed/key decryption callbacks to header
|                               Added RESET_RESPONSE_KEYOFFON_REQUIRED
|                               Added flag value for VPM reprogramming
|                       WM      ESCAN00026795: Missing far declaration for
|                                logical blocktable pointer in FblHeader for
|                                C_COMP_X_M16C
|                       QPs     ESCAN00027628: Updated MEMORY_FAR to V_MEMRAM2_FAR
|                                in tLogicalBlockTable for 16LX, added 16FX support
|                       JHg     Added flag value for silent reprogramming request
|                       SWk     ESCAN00028564: Added Support for C_COMP_MICROCHIP_DSPIC33
|                                changed memory qualifier for FblLogicalBlockTable
|                       AWh     ESCAN00028718: Added support for C_COMP_COSMIC_STM8A_BECAN3
|                               ESCAN00028719: Introduction of typedef tFblStrtFct
|                               ESCAN00028731: Reorganized FBL_ADDR_TYPE FBL_MEMSIZE_TYPE
|                                controller specific exceptions
|                       JHg     Added type definitions for memory identifier
| 2008-09-10 01.90.00   Ci      ESCAN00029506: Invalid #pragma causes compiler warning
|                               ESCAN00029510: Invalid type qualifier causes compiler error
|                       JHg     ESCAN00029713: Include SecM_cfg.h in case Vector security
|                                module is active
|                               Added support for HIS interface specification >= v1.02
|                               Added function callbacks for RSA-Seed/Key decryption
|                               Removed flag value for silent reprogramming request
|                               Added flag value for link control request
|                               Added export of security keys for signature and
|                                seed key calculation to FblHeader
|                       Rr      ESCAN00029868: Add new OEM/SLP
| 2009-02-09 01.91.00   SWk     ESCAN00030607: Added support for C_COMP_MICROCHIP_DSPIC33
|                       AWh     ESCAN00030380: Compiler error/warning for scope internal
|                                declaration of struct tCanInitTable in tFblStrtFct 
|                               ESCAN00030626: Support for DIABDATA MPC55XX
|                       JHg     ESCAN00031429: Added CanInitTable support for TC17xx and XC2000 
| 2009-05-08 01.92.00   AWh     ESCAN00034506: Added CanInitTable support for C_COMP_X_R32C
| 2009-05-13 01.93.00   Ci      ESCAN00034981: Added support for Atmel AVR
|                       Ach     ESCAN00035008: Add memory qualifier for FblHeader (Fiat) on Fj16fx
| 2009-05-11 01.94.00   QPs     ESCAN00035262: Added FBL_CLIENT_DC_SLP10 to support GenyVersion
|                                in tFblHeader structure.
| 2009-06-28 01.95.00   Ach     ESCAN00035772: Add new OEM GAC (SLP1)
|                       AWh     ESCAN00035997: Add new OEM Fisker
|                       Rr      ESCAN00036009: Add new OEM SAIC
| 2009-07-01 01.96.00   Ach     ESCAN00036081: Remove memory qualifier from typedef of tFblHeader
| 2009-07-17 01.97.00   Ls      ESCAN00036507: [M16C only] MEMORY_ROM added
| 2009-08-18 01.98.00   Rr      ESCAN00037195: Add FblSetShutdownRequest, fblMode prototype is
|                                now always available due to changes in fbl_main::FblRepeat
| 2009-10-01 01.99.00   AWh     ESCAN00035997: Add new OEM Fisker (Additional items)
|                       QPs     ESCAN00038135: Extended Usage of tDecParam structure for DC
| 2009-10-29 02.00.00   AWh     ESCAN00038531: Added compiler pragmas for C_COMP_GHS_SH4_RCAN2
|                               ESCAN00038824: Corrected definitions for Oem Claas
| 2009-10-29 02.01.00   MVi     ESCAN00038952: Encapsulated pSecTaskFct by FBL_ENABLE_SECM_TASK for VAG SLP3
|                       Ci      ESCAN00038916: Added support for Ford SLP6
|                       TBe     ESCAN00039364: Adaptions for +strict option in Cosmic compiler
| 2010-01-29 02.02.00   Ci      ESCAN00040275: Added support for AVR32/IAR
| 2010-02-25 02.03.00   Ci      ESCAN00040658: Ford: Enhanced block descriptor
|                               ESCAN00040665: Added dedicated return type for
|                                flash erased detection
|                               ESCAN00040853: Replaced decryption interface by
|                                data processing API
|                       AWh     ESCAN00040940: Define common reprogramming magic pattern,
|                                replaced ~-operator in kNoProgRequest macro
| 2010-04-22 02.04.00   CB      ESCAN00042462: New OEM
| 2010-07-15 02.05.00   MVi     ESCAN00042953: Changed VAG/PAG BlockDescriptor typedef
|                       AWh     ESCAN00043586: Gm only: Added CanInitTableStruct definitions for 
|                                C_COMP_METROWERKS_MPC55XX_COMMENT, added tDecParam
|                       CB      ESCAN00043653: Encapsulation of export pointer pSecTaskFct
|                       SWk     ESCAN00043683: Add support for C_COMP_IAR_78K0R. Adapt 
|                                kLbtAddress and pFlashDrvBlk for newest memory qualifier.
|                       RLB     ESCAN00044112: Added support for C_COMP_IAR_SH2_RCAN
| 2010-10-04 02.06.00   DJO     ESCAN00044750: Add CanInit registers to CanInitTable for GHS MPC55XX
|                       SWk     ESCAN00044973: Adapt flashSegmentSize and  CallFblStart() for 
|                                C_COMP_MICROCHIP_DSPIC33_COMMENT 
| 2010-11-29 02.07.00  AWh      ESCAN00045586: OEM Fisker: Added support for FBL_ENABLE_EEPMGR configuration
|                      TBe      ESCAN00047086: Adaptions for 78K0R 
| 2011-01-11 02.08.00  Ach      ESCAN00047946: Use explicit __far qualifiers to access constants from FblHeader/GM SLP2
| 2011-02-10 02.09.00  TBe      ESCAN00048403: Adaptions for 78K0R NEC compiler 
|                      AWh      ESCAN00048547: Reorganization of CanInitTableStrct bus timing registers
|*****************************************************************************/

#ifndef FBL_DEF_H
#define FBL_DEF_H

/* Includes ******************************************************************/
/* Basic configurations */
#include "v_cfg.h"

#if defined( VGEN_GENY ) && !defined( VGEN_ENABLE_CANFBL )
/* this file was obviously not included in FBL, so it's used in user application
   check if MAGIC_NUMBER was generated. In this case we have to remove the check for the 
   following include because FBL generation use different number than application */
# if defined( MAGIC_NUMBER )
#  undef MAGIC_NUMBER
# endif
#endif
/* Configuration file for flash boot loader */
#include "fbl_cfg.h"
#if defined( VGEN_GENY ) && !defined( VGEN_ENABLE_CANFBL )
/* the last include redefine MAGIC_NUMBER, which is not relevant for application so 
   invalidate it */
# if defined( MAGIC_NUMBER )
#  undef MAGIC_NUMBER
# endif
#endif

/* Basic type definitions */
#include "v_def.h"

/* Defines *******************************************************************/
/* --- Version --- */
/* ##V_CFG_MANAGEMENT ##CQProject : FblDef CQComponent : Implementation */
#define FBLDEF_VERSION          0x0209u
#define FBLDEF_RELEASE_VERSION  0x00u

#ifndef NULL
# define NULL ((void *)0)
#endif

# define assertFbl(p, e)
# define assertFblUser(p, e)
# define assertFblGen(p, e)
# define assertFblInternal(p, e)

/*-- End of assertion definition --------------------------------------------*/

#ifndef SWM_DATA_ALIGN
# define SWM_DATA_ALIGN 0
#endif

/* CanTransmit return values */
#ifndef kCanTxOk
# define kCanTxOk             0     /* Msg transmitted                        */
#endif
#ifndef kCanTxFailed
# define kCanTxFailed         1     /* Tx path switched off                   */
#endif
#define kCanTxInProcess       2

/* Define return code of several functions   */
#define kFblOk                0
#define kFblFailed            1

/* Parameters for ApplFblStartup() */
#define kStartupPreInit       0
#define kStartupPostInit      1
#define kStartupStayInBoot    2

/* Programming request flag */
#define kProgRequest         (tFblProgStatus)0x01u
#define kNoProgRequest       FblInvertBits(kProgRequest,tFblProgStatus)

/* Application validation  */
#define kApplValid            1     /* Application is fully programmed */
#define kApplInvalid          0     /* Operational software is missing */

#define kNrOfValidationBytes  2

/* Define to access the FBL header structure */
#define FblHeaderTable ((tFblHeader MEMORY_HUGE MEMORY_FAR *)(FBL_HEADER_ADDRESS))

/* Position of boot block: */
/* FBL_TOP_BOOT_BLOCK: The boot block is mapped to the high addresses */
/* FBL_BOTTOM_BOOT_BLOCK: The boot block is mapped to the low addresses */

#if !defined(FBL_REPEAT_CALL_CYCLE)
/* Set default to 1ms for repeat time of main loop */
# define FBL_REPEAT_CALL_CYCLE 1
#endif

# define FBL_CALL_TYPE

#ifndef V_CALLBACK_NEAR
# define V_CALLBACK_NEAR
#endif
#ifndef V_API_NEAR
# define V_API_NEAR
#endif

#if defined( FBL_ENABLE_FBL_START )
/* Define pattern for magic flags used for reprogramming indication */
#define kFblStartMagicByte0   0xA5u
#define kFblStartMagicByte1   0xC3u
#define kFblStartMagicByte2   0x9Bu
#define kFblStartMagicByte3   0xE7u

# define FblSetFblStartMagicFlag()\
{\
   fblStartMagicFlag[0] = kFblStartMagicByte0;\
   fblStartMagicFlag[1] = kFblStartMagicByte1;\
   fblStartMagicFlag[2] = kFblStartMagicByte2;\
   fblStartMagicFlag[3] = kFblStartMagicByte3;\
}

# define FblChkFblStartMagicFlag()\
   ((    (fblStartMagicFlag[0] == kFblStartMagicByte0)\
      && (fblStartMagicFlag[1] == kFblStartMagicByte1)\
      && (fblStartMagicFlag[2] == kFblStartMagicByte2)\
      && (fblStartMagicFlag[3] == kFblStartMagicByte3))?1:0)

# define FblClrFblStartMagicFlag()\
{\
   fblStartMagicFlag[0] = 0x00;\
   fblStartMagicFlag[1] = 0x00;\
   fblStartMagicFlag[2] = 0x00;\
   fblStartMagicFlag[3] = 0x00;\
}

/** Defines to convert BigEndian bytes into short or long values ********************/
# ifdef C_CPUTYPE_BIGENDIAN
#  ifdef C_CPUTYPE_32BIT
#   define FblBytesToShort(hi,lo)            (((vuint16)(hi) << 8) | ((vuint16)(lo) ))
#  else
#   define FblBytesToShort(hi,lo)            (vuint16)*(V_MEMRAM0 V_MEMRAM1_FAR vuint16 V_MEMRAM2_FAR *)(&(hi))
#  endif
# endif
# ifdef C_CPUTYPE_LITTLEENDIAN
#  define FblBytesToShort(hi,lo)              (((vuint16)(hi) << 8) | ((vuint16)(lo) ))
# endif

# ifdef C_CPUTYPE_BIGENDIAN
#  ifdef C_CPUTYPE_32BIT
#   define FblBytesToLong(hiWrd_hiByt,hiWrd_loByt,loWrd_hiByt,loWrd_loByt)  \
                                         (((vuint32)(hiWrd_hiByt) << 24) |  \
                                          ((vuint32)(hiWrd_loByt) << 16) |  \
                                          ((vuint32)(loWrd_hiByt) <<  8) |  \
                                          ((vuint32)(loWrd_loByt)      )  )
#  else
#   define FblBytesToLong(hiWrd_hiByt,hiWrd_loByt,loWrd_hiByt, loWrd_loByt)  \
            (vuint32)*(V_MEMRAM0 V_MEMRAM1_FAR vuint32 V_MEMRAM2_FAR *)(&(hiWrd_hiByt))
#  endif
# endif
# ifdef C_CPUTYPE_LITTLEENDIAN
#  define FblBytesToLong(hiWrd_hiByt,hiWrd_loByt,loWrd_hiByt,loWrd_loByt)  \
                                        (((vuint32)(hiWrd_hiByt) << 24) |  \
                                         ((vuint32)(hiWrd_loByt) << 16) |  \
                                         ((vuint32)(loWrd_hiByt) <<  8) |  \
                                         ((vuint32)(loWrd_loByt)      )  )
# endif

#endif   /* #if defined( FBL_ENABLE_FBL_START ) */

#define BIT0   0x01u
#define BIT1   0x02u
#define BIT2   0x04u
#define BIT3   0x08u
#define BIT4   0x10u
#define BIT5   0x20u
#define BIT6   0x40u
#define BIT7   0x80u

/* Macros and values for fblMode */
#define START_FROM_APPL          BIT0
#define START_FROM_RESET         BIT1
#define APPL_CORRUPT             BIT2
#define STAY_IN_FLASHER          BIT3
#define FBL_RESET_REQUEST        BIT4
#define WAIT_FOR_PING            BIT5
#define FBL_START_WITH_RESP      BIT6
#define FBL_START_WITH_PING      BIT7
#define SetFblMode(state)        (fblMode = (vuint8)((fblMode & 0xF0u) | (state)))
#define GetFblMode()             ((vuint8)(fblMode & 0x0Fu))
#if defined( FBL_ENABLE_STAY_IN_BOOT )
#define GetFblWaitForPing()      (fblMode & WAIT_FOR_PING)
#endif
#define FblSetShutdownRequest()  SetFblMode(FBL_RESET_REQUEST)
extern MEMORY_NEAR vuint8 fblMode;

/* Access macros for FblHeader elements for application */
#define GetFblMainVersion()    (FblHeaderTable->kFblMainVersion)
#define GetFblSubVersion()     (FblHeaderTable->kFblSubVersion)
#define GetFblReleaseVersion() (FblHeaderTable->kFblBugFixVersion)
#define GetFblBuildVersion()   (FblHeaderTable->kFblBuildVersion)
#define  GetFblDCID0()         (FblHeaderTable->DCID[0])
#define  GetFblDCID1()         (FblHeaderTable->DCID[1])
#define  GetFblSWMI(i)         (FblHeaderTable->SWMI[(i)])
#define  GetFblSWMI0()         (FblHeaderTable->SWMI[0])
#define  GetFblSWMI1()         (FblHeaderTable->SWMI[1])
#define  GetFblSWMI2()         (FblHeaderTable->SWMI[2])
#define  GetFblSWMI3()         (FblHeaderTable->SWMI[3])
#define  GetFblDLS0()          (FblHeaderTable->DLS[0])
#define  GetFblDLS1()          (FblHeaderTable->DLS[1])

#define FBL_START_PARAM       ((void *)0)
#define CallFblStart(pParam)  (FblHeaderTable->FblStartFct)((pParam))

/* macros to harmonize type casts for inverting bits */
#define FblInvertBits(x,type)  ( (type)  ~((type) (x))      )
#define FblInvert8Bit(x)       ( FblInvertBits((x),vuint8)  )
#define FblInvert16Bit(x)      ( FblInvertBits((x),vuint16) )
#define FblInvert32Bit(x)      ( FblInvertBits((x),vuint32) )

/* Unless otherwise specified, STAY_IN_BOOT mode is disabled. */
#if !defined( FBL_ENABLE_STAY_IN_BOOT ) && !defined( FBL_DISABLE_STAY_IN_BOOT )
# define FBL_DISABLE_STAY_IN_BOOT
#endif

/* Field sizes in GM's File Header */
#define SWM_CS_MAX_LEN     ((vuint8)2)    /* Checksum field length */
#define SWM_MID_MAX_LEN    ((vuint8)2)    /* Module-ID field length */
#define SWM_HFI_MAX_LEN    ((vuint8)2)    /* Header-Format-Identifier field length */
#define SWM_SWMI_MAX_LEN   ((vuint8)16)   /* Software-Module-Identifier field length */
#define SWM_DLS_MAX_LEN    ((vuint8)3)    /* Design-Level-Suffex (Alpha Code) field length */
#define SWM_PN_MAX_LEN     ((vuint8)16)   /* Part-Number field length */
#define SWM_DCID_MAX_LEN   ((vuint8)2)    /* Data-Compatibility-Identifier field length */
#define SWM_NOAR_MAX_LEN   ((vuint8)2)    /* Number-Of-Address-Regions field length */
#define SWM_NOAM_MAX_LEN   ((vuint8)2)    /* Number-Of-Additional-Modules field length */
#define SWM_PMA_MAX_LEN    ((vuint8)4)    /* Product-Memory-Address field length */
#define SWM_NOB_MAX_LEN    ((vuint8)4)    /* Number-Of-Bytes field length */

#define SWM_SWMI_DFLT_LEN  ((vuint8)4)    /* Required SWMI field length for "Global Bootloader Specification" */

/* Types *********************************************************************/
typedef vuint8 tFblResult;                    /* FBL result codes */
typedef vuint8 tFblProgStatus;                /* Status of reprogramming flag */
typedef vuint8 tApplStatus;                   /* Application valid status */
typedef vuint8 tMagicFlag;                    /* Application valid flag */

#ifdef C_CPUTYPE_8BIT
typedef vuint16 FBL_ADDR_TYPE;
typedef vuint16 FBL_MEMSIZE_TYPE;
#define MEMSIZE_OK
#endif /* C_CPUTYPE_8BIT */
#ifdef C_CPUTYPE_16BIT
typedef vuint16 FBL_ADDR_TYPE;
typedef vuint16 FBL_MEMSIZE_TYPE;
#define MEMSIZE_OK
#endif /* C_CPUTYPE_16BIT */
#ifdef C_CPUTYPE_32BIT
typedef vuint32 FBL_ADDR_TYPE;
typedef vuint32 FBL_MEMSIZE_TYPE;
#define MEMSIZE_OK
#endif /* C_CPUTYPE_32BIT */

typedef vuint8 FBL_MEMID_TYPE;

#ifdef MEMSIZE_OK
#else
# error "Error in FBL_DEF.H: C_CPUTYPE_ not defined."
#endif

typedef struct CanInitTableStrct tCanInitTable;

typedef MEMORY_HUGE MEMORY_FAR void (*tFblStrtFct)( tCanInitTable* );

/* Defines *******************************************************************/
#define kFblDiagTimeP2        FBL_DIAG_TIME_P2MAX
#define kFblDiagTimeP2Star    FBL_DIAG_TIME_P3MAX

/* Structure for address and length information of segments */
typedef struct tSegmentInfo
{
   FBL_ADDR_TYPE     address;
   FBL_MEMSIZE_TYPE  length;
} tSegmentInfo;

/* Segment data structure */
typedef struct tSegmentList
{
   vuint8         nrOfSegments;
   tSegmentInfo   segmentInfo[SWM_DATA_MAX_NOAR];
} tSegmentList;

typedef vuint16 tChecksum;

/*****************************************************************************/
/* Increment this version when changing the structure     */
/* "CanInitTableStrct". This provides version control for */
/* the function FblStackInit() in FBL_HW.C.               */
#define FBL_CAN_INIT_TABLE_VERSION  0x0101

/* CAN initialization data structure */
struct CanInitTableStrct
{
   vuint8 TpRxIdHigh;       /* CAN receive identifier */
   vuint8 TpRxIdLow;
   vuint8 TpTxIdHigh;       /* CAN transmit identifer */
   vuint8 TpTxIdLow;
   vuint16 CanInitBT0;
   vuint16 CanInitBT1;
   vuint8 ProgrammedState;             /* Mode byte for ReportProgrammedState service      */
   vuint8 ErrorCode;                   /* This byte determines SPS_TYPE_B or SPS_TYPE_C    */
   vuint8 RequestProgrammingMode;      /* Highspeed programming or normal mode             */
   vuint8 requestDownloadFormatID;     /* Subparameter of Request download                 */
   vuint32 requestDownloadMemorySize;  /* unCompressedMemorySize param of Request Download */
   MEMORY_HUGE MEMORY_FAR void (*PlaceHolder_func)(void);/* need not to be initialized. For internal use only */
};

/* Memory address field for address and length information of segments */
typedef struct tSWMI_PMA
{
   FBL_ADDR_TYPE     address;
   FBL_MEMSIZE_TYPE  length;
   vuint16         CheckSum;               /* Checksum of a section */
} tSWMI_PMA;

#   if defined (FBL_ENABLE_ENCRYPTION_MODE) 
typedef struct tDecParam
{
   vuint8*        dataBuffer;
   vuint16        dataLength;
   vuint8         (* wdTriggerFct)(void);
}tDecParam;
#   endif
/* SWM data structure. This is an export for the application            */
/* to get access to the software module information stored in Flash.    */
/* Since FBL uses the same data struct internally -> Do not change !!!  */
typedef struct tSwmRootInfo
{
   vuint8    MagicFlag;
   vuint8    eraseCount;
   vuint32   SWMIBaseAddress;
} tSwmRootInfo;

typedef struct tFblHeader
{
   vuint8      CS[2];      /* Module Checksum              */
   vuint8      MID[2];     /* Module ID                    */
   vuint8      HFI[2];     /* Header Format Identifier     */
   vuint8      SWMI[4];    /* SoftWare Module Identifier   */
   vuint8      DLS[2];     /* Design Level Suffix          */
   vuint8      DCID[2];    /* Data Compatiblity Identifier */
   vuint8      NOAR[2];    /* Number Of Address Regions    */
                         /* Product Memory Address + Number Of Bytes */
   vuint8      AddressRegions[FBL_GMHEADER_NOAR_FBL * 8];
   tFblStrtFct FblStartFct;
   vuint8      kFblMainVersion;
   vuint8      kFblSubVersion;
   vuint8      kFblBugFixVersion;
   vuint8      kFblBuildVersion;
} tFblHeader;

#define SwmDataTable ((MEMORY_HUGE MEMORY_FAR tSwmDataTable *)(SWM_DATA_ADDR))

typedef vuint16 tBlockDescriptor;         /* Used for Module-Id */

/* Structure for module information */
typedef struct tModule
{
   vuint8         swmiLen;
   vuint8         SWMI[SWM_SWMI_MAX_LEN];     /* Software-Module-Identifier */
   vuint8         dlsLen;
   vuint8         DLS[SWM_DLS_MAX_LEN];       /* Design-Level-Suffix */
   vuint8         PN[SWM_PN_MAX_LEN];         /* Part-Number */
   vuint8         DCID[SWM_DCID_MAX_LEN];     /* Data-Compatibility-Identifier */
   vuint8         NOAR;                       /* Number-of-Address-Regions */
   tSegmentList   PMA;                        /* Product Memory Address table */
} tModule;

/* GM File-Header data structure.                             */
typedef struct tSwmDataTable
{
   vuint16        CS;                         /* Checksum */
   vuint16        MID;                        /* Module-ID */
   vuint8         HFI[SWM_HFI_MAX_LEN];       /* Header-Format-Identifier */
   vuint8         NOAM;                       /* Number Of Additional Modules  */
   tModule        module;                     /* Module-specific information */
} tSwmDataTable;

/* Prototypes ****************************************************************/
void FblStackInit( MEMORY_HUGE MEMORY_FAR tCanInitTable *CanInitTable );
/* Start flash boot loader out of application */
void ApplFblStart( MEMORY_HUGE MEMORY_FAR tCanInitTable *CanInitTable );

#if defined(FBL_ENABLE_FBL_START)
 /* Example implementation on entering bootloader with 4 byte special ('FBLSTARTMAGIC') values */
 extern vuint8 fblStartMagicFlag[4];

 extern tCanInitTable CanInitTable;
#endif /* FBL_ENABLE_FBL_START */

/* Value of parameter 'RequestProgrammingMode'  */
/* Defines the service request type used to     */
/* jump into bootloader.                        */
#define REQUEST_DOWNLOAD_MODE_LOWSPEED       0x03
#define REQUEST_DOWNLOAD_MODE_HIGHSPEED      0x04

#endif /* #ifndef FBL_DEF_H */

/* End of file *************************************************************/
