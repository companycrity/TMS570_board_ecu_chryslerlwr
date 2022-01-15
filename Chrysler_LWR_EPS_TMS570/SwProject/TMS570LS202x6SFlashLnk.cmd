/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : TMS570LS202x6SFlashLnk.cmd
* Module Description: Linker Command File
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec 14 14:58:07 2010
* %version:          EA3#27.1.6 %
* %derived_by:       gz324f %
* %date_modified:    Fri Feb 14 11:07:46 2014 %
*---------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Linker Settings                                                            */
--retain="*(.intvecs)"

/*----------------------------------------------------------------------------*/
/* Memory Map                                                                 */
MEMORY{

  /* Bootmanager                0x0000 0000 - 0x0000 BFFF                                  */
   BOOT_VECTOR      (RX) : origin=0x00000000 length=0x00000040 /* BOOTMANAGER STARTUP CODE */
   BOOT_FLASH       (RX) : origin=0x00000040 length=0x0000BFB8 /* BOOTMANAGER              */
   BOOT_CRC	        (R)  : origin=0x0000BFF8 length=0x8        /* BOOT CRC				   */
 
  /* Application                                */  
   APP_BLSHARED     (RX) : origin=0x0000C000 length=0x000000F8  fill=0xFFFFFFFF /* APPLICATION   		   */
   APP_CRC		    (RX) : origin=0x0000C0F8 length=0x00000008  fill=0xFFFFFFFF /* APPLICATION   		   */
   APPVECTOR        (RX) : origin=0x0000C100 length=0x00000100  fill=0xFFFFFFFF /* APPLICATION   		   */
   APP_FLASH        (RX) : origin=0x0000C200 length=0x00073DE0  fill=0xFFFFFFFF /* APPLICATION              */
   NO_CRC			(RX) : origin=0x0007FFE0 length=0x00000010  fill=0xFFFFFFFF /* APPLICATION              */
   BOOTCHK			(RX) : origin=0x0007FFF0 length=0x00000008  fill=0xFFFFFFFF /* APPLICATION              */
   APPVALID		    (RX) : origin=0x0007FFF8 length=0x00000008  fill=0xFFFFFFFF /* APPLICATION              */
   CAL2_BLSHARED    (RX) : origin=0x00080000 length=0x00000040  fill=0xFFFFFFFF /* APPLICATION              */
   CAL_FLASH        (RX) : origin=0x00080040 length=0x0007FFB0  fill=0xFFFFFFFF /* APPLICATION              */
   CAL_CRC          (RX) : origin=0x000FFFF0 length=0x00000008  fill=0xFFFFFFFF /* APPLICATION              */
   CALVALID	    	(RX) : origin=0x000FFFF8 length=0x00000008  fill=0xFFFFFFFF /* APPLICATION              */
   /*MEM_FILL         (RX) : origin=0x00100000 length=0x00040000  fill=0xFFFFFFFF /* APPLICATION              */


  /* RAM Memory Regions                                                                    */	
   RAM              (RW) : origin=0x08000000 length=0x0001DC04 /* BOOTLOADER               */
   RAM_FLASHCODE    (RW) : origin=0x0801DC04 length=0x00002000 /* BOOTLOADER               */
   STACKS           (RW) : origin=0x0801FC04 length=0x000003FC /* BOOTLOADER               */

   
   
   MMC     (RW)   :  origin=0xFFFFFD00   length=0x40                                      
   DEC     (RW)   :  origin=0xFFFFFE00   length=0x60                                  
   SYS     (RW)   :  origin=0xFFFFFFD0   length=0x30  
   
   NHET2RAM         (RW) : origin=0xFF440000 length=0x00000800
   NHETRAM          (RW) : origin=0xFF460000 length=0x00000800
}

/*----------------------------------------------------------------------------*/
/* Section Configuration                                                      */
SECTIONS{

	.FixedAdd_CalVersionCheck : { } > 		0x00080000
	.FixedAdd_ECUPartNumber : { } > 		0x00080004
	.FixedAdd_AppVersionCheck : { } > 		0x0000C000
	.FixedAdd_BlocksizeSTMinParam : { } > 	0x0000C004
	.FixedAdd_NxtrSWPN : { } > 				0x0000C008
	.FixedAdd_SwVer : { } > 				0x0000C080
	.FixedAdd_AppValidPattern : { } > 		APPVALID
	.FixedAdd_CalValidPattern : { } > 		CALVALID
	.FixedAdd_BootApplValidChk : { } > 		BOOTCHK
	
	.osresetvect : { } >  0x0000C100
	.osarmvect : { } >  0x0000C104

	.cinit     : { } > APP_FLASH
	
	.resetcause : { } >  0x0801FFFC

	.bss     :  LOAD_END(Lnk_BSS_End),
				LOAD_START(Lnk_BSS_Start)
				{
    			 #include "./Source/GenDataOS/osobjs.inc"
						*(.ossctxdata)
    			} > RAM
    .data    : {
    			 #include "./Source/GenDataOS/osobjs_init.inc"
				 *(.osstack)
    			} > RAM
    			
	.sysmem  : {} > RAM
	.noclear   : {} > RAM
	.stack   : {
                    _StackSVC_   = .+ (0x0100);
                    _StackFIQ_   = .+ (0x0200);
                    _StackIRQ_   = .+ (0x0300);
                    _StackUSER_  = .+ (0x0300);
                    _StackABORT_ = .+ (0x0380);
                    _StackUND_   = .+ (0x03FC);
                    } > STACKS       /* SOFTWARE SYSTEM STACK             */

	
	.MMC     : {_e_SARMMC_ST = .;}  > MMC                                        
	.DEC     : {_e_SARDEC_ST = .;}  > DEC                                          
	.SYS     : {_e_SARSYS_ST = .;}  > SYS                            
                                                                                    
	/* locate diagbuffer to ((32bit-align)-1byte), because the flashalgo needs the data */
	/* aligned to 32bit, and first byte is the ID.                                      */
	.FLASHDRV         : {} > RAM_FLASHCODE  /* locate FlashCode into RAM */               
	.CANINITTABLE     : {} > RAM /* base address of the Application Vectortable */   
	.FBLMAGIC         : {} > RAM /* base address of the Application Vectortable */  

	/* Union of the Calibration RAM and the Flash API/ECC Update Algorithm        */
	/*  This union was created due to convienence with the exisitng memory map    */
	/*  and the fact that the CAL_RAM and Flash API/ECC Update Algorithm  were    */
	/*  mutually exclusive, i.e. that data in each one was accessed at deifferent */
	/*  point in the start-up process.                                            *
	UNION run = RAM
	{
	    /* Load in FLASH, Run from RAM FLASH API *
	    .text:flash_api : LOAD = APP_FLASH,
               RUN_START(Lnk_FlsApiRunStart), 
               LOAD_SIZE(Lnk_FlsApiLen),
               LOAD_START(Lnk_FlsApiLoadStart)
               { 
			   		F021_API_CortexR4_BE_v3D16.lib(.text .tramp .const)
			   		Fapi_UserDefinedFunctions.obj(.text .tramp .const)
			   					   		
     
               }    
	}*/


    .APPFLASH: > APP_FLASH, palign(64)
		LOAD_START(Lnk_PrgFlash_Start)
		LOAD_SIZE(Lnk_PrgFlash_Length)
    {   	
    	
    	
    	*(.osvtable)
	    *(.text)
	    *(.const)
	    *(.oscode)
	    *(.osconst)
	    .=((.-1)/4)*4+4;  /* Force align to 32bits as osconfig is structure */
	    /* Note this checksum has to run prior to the overall flash checksum */
	    CCT_Range_00_Start = .;
	    CCT_Range_00_BitAddrGran = 8;
        CCT_Range_00_Category = 300; 
        CCT_Range_00_Algorithm = 10;
	    *(.osconfig)     
        CCT_Range_00_Length = . - CCT_Range_00_Start-2;
        CCT_Range_00_Address = CCT_Range_00_Start + CCT_Range_00_Length;
	    
    }
               
    .HETCODE : { e_HETPROGRAM0_UN = .;} > 0xFF460000	  /* HET PROGRAM */
    .HET2CODE : { e_HETPROGRAM1_UN = .;} > 0xFF440000	  /* HET2 PROGRAM */
	/* locate here the vectortable of your application               */
	/* .APPLVECT        : {} > 0x0000C100 */ /* base address of the Application Vectortable */
	
	.APPCHECKSUM: > APP_CRC,
	{
		_CCT_Range_01_Address = .;
		_CCT_Range_01_Length = 0x73EE0;
		_CCT_Range_01_Start = 0xC100;
		_CCT_Range_01_BitAddrGran = 8;
		_CCT_Range_01_Category = 300;
		_CCT_Range_01_Algorithm = 12;
		
	}
	
	.CALCHECKSUM: > CAL_CRC,
	{
		_CCT_Range_10_Address = .;
		_CCT_Range_10_Length = 0x7FFF0;
		_CCT_Range_10_Start = 0x80000;
		_CCT_Range_10_BitAddrGran = 8;
		_CCT_Range_10_Category = 200;
		_CCT_Range_10_Algorithm = 12;

		Lnk_BootRelNum_Addr = 0x0000BFC0;
	}

	.BOOTCHECKSUM: > BOOT_CRC
	{
		_CRC_Boot_Start = 0;
		_CRC_Boot_Address = 0x0000BFF8;
	}


	/* Load and Execute from Flash Calibrations */
    .FlashCal1Seg : {} > CAL_FLASH
    .TunCal0 : {} > CAL_FLASH
    .TunCal0Per0 : {} > CAL_FLASH
    .TunCal0Per1 : {} > CAL_FLASH
    .TunCal0Per2 : {} > CAL_FLASH
    .TunCal1 : {} > CAL_FLASH
    .TunCal1Per0 : {} > CAL_FLASH
    .TunCal1Per1 : {} > CAL_FLASH
    .TunCal1Per2 : {} > CAL_FLASH
    .TunCal2 : {} > CAL_FLASH
    .TunCal2Per0 : {} > CAL_FLASH
    .TunCal2Per1 : {} > CAL_FLASH
    .TunCal2Per2 : {} > CAL_FLASH
    .TunCal3 : {} > CAL_FLASH
    .TunCal3Per0 : {} > CAL_FLASH
    .TunCal3Per1 : {} > CAL_FLASH
    .TunCal3Per2 : {} > CAL_FLASH
    .TunCal4 : {} > CAL_FLASH
    .TunCal4Per0 : {} > CAL_FLASH
    .TunCal4Per1 : {} > CAL_FLASH
    .TunCal4Per2 : {} > CAL_FLASH
    .TunCal5 : {} > CAL_FLASH
    .TunCal5Per0 : {} > CAL_FLASH
    .TunCal5Per1 : {} > CAL_FLASH
    .TunCal5Per2 : {} > CAL_FLASH
    .TunCal6 : {} > CAL_FLASH
    .TunCal6Per0 : {} > CAL_FLASH
    .TunCal6Per1 : {} > CAL_FLASH
    .TunCal6Per2 : {} > CAL_FLASH
    .TunCal7 : {} > CAL_FLASH
    .TunCal7Per0 : {} > CAL_FLASH
    .TunCal7Per1 : {} > CAL_FLASH
    .TunCal7Per2 : {} > CAL_FLASH
    .TunCal8 : {} > CAL_FLASH
    .TunCal8Per0 : {} > CAL_FLASH
    .TunCal8Per1 : {} > CAL_FLASH
    .TunCal8Per2 : {} > CAL_FLASH
    .TunCal9 : {} > CAL_FLASH
    .TunCal9Per0 : {} > CAL_FLASH
    .TunCal9Per1 : {} > CAL_FLASH
    .TunCal9Per2 : {} > CAL_FLASH
    .TunCal10 : {} > CAL_FLASH
    .TunCal10Per0 : {} > CAL_FLASH
    .TunCal10Per1 : {} > CAL_FLASH
    .TunCal10Per2 : {} > CAL_FLASH
    .TunCal11 : {} > CAL_FLASH
    .TunCal11Per0 : {} > CAL_FLASH
    .TunCal11Per1 : {} > CAL_FLASH
    .TunCal11Per2 : {} > CAL_FLASH
    .TunCal12 : {} > CAL_FLASH
    .TunCal12Per0 : {} > CAL_FLASH
    .TunCal12Per1 : {} > CAL_FLASH
    .TunCal12Per2 : {} > CAL_FLASH
    .TunCal13 : {} > CAL_FLASH
    .TunCal13Per0 : {} > CAL_FLASH
    .TunCal13Per1 : {} > CAL_FLASH
    .TunCal13Per2 : {} > CAL_FLASH
    .TunCal14 : {} > CAL_FLASH
    .TunCal14Per0 : {} > CAL_FLASH
    .TunCal14Per1 : {} > CAL_FLASH
    .TunCal14Per2 : {} > CAL_FLASH

}

/*****************************************************************************
CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
08/09/12    4.0     SAH     Initial Chrysler Creation
08/21/12    5      	SAH     Locked down locations for app and cal check.
08/31/12	6		SAH		Changed MEM_FILL length for 1.25M part
10/05/12	7		SAH		Locked down location for sw version
10/10/12	8		SAH		Locked down address for bootloader rel number
11/12/12	9		SAH		Changed typeH symbol to typeHD for compatibility.
11/20/12	10		SAH		Added AbsHwPosScom to typeH
01/04/13	13		SAH		Added CAL4_FLASH section for tuning sets and pers
01/11/13	14		SAH		Changed Cal CRC range
01/15/13	15		SAH		Added cal version check for both cal regions
01/30/13	17		SAH		Updated the Flash CRC starting address and length
03/01/13    19	    JJW     Os 5.06 integration, removal of .fiqarmvect now
							 generated by Os and addition of new os section.
03/01/13	20		SAH		Made SwVer and SwModuleInfo fixed locations.
05/01/13	21		SAH		Added WIR typeH section.
05/09/13	22		SAH		Added ThrmlDutyCycle typeH section.
06/18/13	23		SAH		Change SwModuleInfo from fixed address to RAM
07/09/13	25		JJW		SwModuleInfo segment chnaged to Ap9 Os segment, so
                            its allocation here was removed.
07/27/13	27		SAH		Added Boot CRC
08/26/13	27.1.1	SAH		Added app and cal valid flags and 5 more tuning sets
09/30/13	27.1.2	SAH		Updates for flshtest memory regions
01/10/14	27.1.3	SAH		Updates for 128k RAM
02/14/14	27.1.5	SAH		Added boot compatibility check
******************************************************************************/


