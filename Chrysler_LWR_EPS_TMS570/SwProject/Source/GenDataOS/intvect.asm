; file: intvect.asm, automatically generated by genTMS570SafeCtxAS.exe, Version: 5.06
; configuration read from: C:\Users\pznywf\AppData\Local\Temp\~cfg4_301_EPS.ecuc.arxml.oil
; generation at  : Tue Jul 19 18:16:23 2016
; Unlimited license CBD1010124 for Nexteer Automotive
; Implementation: TMS570LS3x
; Version of general code: 5.23c


osdVrmAsmGenMajRelNum     .set 5
osdVrmAsmGenMinRelNum     .set 6


   .sect ".oscode"


   .state32
   .ref osUnhandledExceptionWrapper
   .ref osEnterCallLeaveISR

   .ref _undefinst
   .ref osSWI
   .ref osProtectionTrap
   .ref osPrefetchAbort
   .ref osDataAbort
   .ref Isr_ESMH
   .ref Isr_MtrCtrl
   .ref DCan1_level0_Irqfunc
   .ref Isr_ESMH
   .ref Gpt_IsrInt0func
   .ref Isr_ESMLfunc
   .ref FlsTst_CrcIrqfunc


DCan1_level0_Irq_cat2
   stmfd  sp!,{r0,r1,lr}
   stmfd  sp!,{r2,r3,r4,ip}
   mov    r3,#0   ; r3 = ISR ID for DCan1_level0_Irq
   bl osEnterCallLeaveISR
   .word DCan1_level0_Irqfunc


Gpt_IsrInt0_cat2
   stmfd  sp!,{r0,r1,lr}
   stmfd  sp!,{r2,r3,r4,ip}
   mov    r3,#1   ; r3 = ISR ID for Gpt_IsrInt0
   bl osEnterCallLeaveISR
   .word Gpt_IsrInt0func


Isr_ESML_cat2
   stmfd  sp!,{r0,r1,lr}
   stmfd  sp!,{r2,r3,r4,ip}
   mov    r3,#2   ; r3 = ISR ID for Isr_ESML
   bl osEnterCallLeaveISR
   .word Isr_ESMLfunc


FlsTst_CrcIrq_cat2
   stmfd  sp!,{r0,r1,lr}
   stmfd  sp!,{r2,r3,r4,ip}
   mov    r3,#3   ; r3 = ISR ID for FlsTst_CrcIrq
   bl osEnterCallLeaveISR
   .word FlsTst_CrcIrqfunc





osDefVect
   subs   pc,lr,#4


   .ref osUnhandledExceptionWrapper
   .sect ".osvtable"
   .global     osaIRQTable
osaIRQTable     ; interrupt vector table
   .word osDefVect
   .word Isr_ESMH
     ; 0 (INTR0)
   .word osUnhandledExceptionWrapper
     ; 1 (INTR3)
   .word Isr_MtrCtrl
     ; 2 (INTR50)
   .word osUnhandledExceptionWrapper
     ; 3 (INTR3)
   .word Gpt_IsrInt0_cat2
     ; 4 (INTR2)
   .word osUnhandledExceptionWrapper
     ; 5 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 6 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 7 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 8 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 9 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 10 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 11 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 12 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 13 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 14 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 15 (INTR3)
   .word DCan1_level0_Irq_cat2
     ; 16 (INTR16)
   .word osUnhandledExceptionWrapper
     ; 17 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 18 (INTR3)
   .word FlsTst_CrcIrq_cat2
     ; 19 (INTR19)
   .word Isr_ESML_cat2
     ; 20 (INTR20)
   .word osUnhandledExceptionWrapper
     ; 21 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 22 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 23 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 24 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 25 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 26 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 27 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 28 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 29 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 30 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 31 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 32 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 33 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 34 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 35 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 36 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 37 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 38 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 39 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 40 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 41 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 42 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 43 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 44 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 45 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 46 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 47 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 48 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 49 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 50 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 51 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 52 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 53 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 54 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 55 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 56 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 57 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 58 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 59 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 60 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 61 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 62 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 63 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 64 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 65 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 66 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 67 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 68 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 69 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 70 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 71 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 72 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 73 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 74 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 75 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 76 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 77 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 78 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 79 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 80 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 81 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 82 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 83 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 84 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 85 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 86 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 87 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 88 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 89 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 90 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 91 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 92 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 93 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 94 (INTR3)
   .word osUnhandledExceptionWrapper
     ; 95 (INTR3)


   .sect ".osresetvect"
osResetVector
   .ref _c_int00
    b _c_int00    ; Reset
   .sect ".osarmvect"
osARMVectTable
    b _undefinst    ; Undefined Instruction
    b osSWI                       ; SWI
    b osPrefetchAbort             ; Prefetch Abort
    b osDataAbort                 ; Data Abort
    .word 0                        ; reserved
    b osUnhandledExceptionWrapper                ; IRQ
    b Isr_ESMH    ; FIQ




; Empty sections for all possible task, ISR and application data
; Note: use the following linker option --retain="*(.oss*:*init)"
;       to suppress warning "no matching section"
   .sect ".ossDataTask_10ms_SchM9:noinit"
   .sect ".ossDataTask_10ms_SchM9:init"
   .sect ".ossDataTask_Bkgnd:noinit"
   .sect ".ossDataTask_Bkgnd:init"
   .sect ".ossDataTask_4ms_SchM0:noinit"
   .sect ".ossDataTask_4ms_SchM0:init"
   .sect ".ossDataTask_Init_SchM9:noinit"
   .sect ".ossDataTask_Init_SchM9:init"
   .sect ".ossDataTask_100ms_10:noinit"
   .sect ".ossDataTask_100ms_10:init"
   .sect ".ossDataTask_100ms_8:noinit"
   .sect ".ossDataTask_100ms_8:init"
   .sect ".ossDataTask_100ms_9:noinit"
   .sect ".ossDataTask_100ms_9:init"
   .sect ".ossDataTask_10ms_10:noinit"
   .sect ".ossDataTask_10ms_10:init"
   .sect ".ossDataTask_10ms_9:noinit"
   .sect ".ossDataTask_10ms_9:init"
   .sect ".ossDataTask_2ms_10:noinit"
   .sect ".ossDataTask_2ms_10:init"
   .sect ".ossDataTask_2ms_8:noinit"
   .sect ".ossDataTask_2ms_8:init"
   .sect ".ossDataTask_2ms_9:noinit"
   .sect ".ossDataTask_2ms_9:init"
   .sect ".ossDataTask_4ms_10:noinit"
   .sect ".ossDataTask_4ms_10:init"
   .sect ".ossDataTask_4ms_8:noinit"
   .sect ".ossDataTask_4ms_8:init"
   .sect ".ossDataTask_Trans_10:noinit"
   .sect ".ossDataTask_Trans_10:init"
   .sect ".ossDataTask_Trans_9:noinit"
   .sect ".ossDataTask_Trans_9:init"
   .sect ".ossDataTask_Init_10:noinit"
   .sect ".ossDataTask_Init_10:init"
   .sect ".ossDataTask_Init_8:noinit"
   .sect ".ossDataTask_Init_8:init"
   .sect ".ossDataTask_Init_9:noinit"
   .sect ".ossDataTask_Init_9:init"
   .sect ".ossDataTask_Trans_8:noinit"
   .sect ".ossDataTask_Trans_8:init"
   .sect ".ossDataTask_4ms_9:noinit"
   .sect ".ossDataTask_4ms_9:init"
   .sect ".ossDataTask_TransB_9:noinit"
   .sect ".ossDataTask_TransB_9:init"
   .sect ".ossDataTask_100ms_SchM0:noinit"
   .sect ".ossDataTask_100ms_SchM0:init"
   .sect ".ossDataTask_100ms_SchM9:noinit"
   .sect ".ossDataTask_100ms_SchM9:init"
   .sect ".ossDataIsr_MtrCtrl:noinit"
   .sect ".ossDataIsr_MtrCtrl:init"
   .sect ".ossDataDCan1_level0_Irq:noinit"
   .sect ".ossDataDCan1_level0_Irq:init"
   .sect ".ossDataIsr_ESMH:noinit"
   .sect ".ossDataIsr_ESMH:init"
   .sect ".ossDataGpt_IsrInt0:noinit"
   .sect ".ossDataGpt_IsrInt0:init"
   .sect ".ossDataIsr_ESML:noinit"
   .sect ".ossDataIsr_ESML:init"
   .sect ".ossDataFlsTst_CrcIrq:noinit"
   .sect ".ossDataFlsTst_CrcIrq:init"
   .sect ".ossDataAp_10:noinit"
   .sect ".ossDataAp_10:init"
   .sect ".ossDataAp_8:noinit"
   .sect ".ossDataAp_8:init"
   .sect ".ossDataAp_9:noinit"
   .sect ".ossDataAp_9:init"
   .sect ".ossDataAp_0:noinit"
   .sect ".ossDataAp_0:init"
   .end


; END OF C:\Sankar\Chrysler\Synergy\CL\Temp_work\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\..\..\SwProject\Source\GenData\\..\GenDataOs\intvect.asm

