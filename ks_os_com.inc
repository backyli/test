/***********************************************************************************************************************
* Copyright (C) 2019 Shanghai Kindroid Network Tech Ltd. All rights reserved
*
* License:
*
* Description:
*
* Author:
*
* Revision History:
* 1.0 2019-06-17 created by can.yin
***********************************************************************************************************************/
.IFNDEF _KS_OS_COM_INC_
.EQU _KS_OS_COM_INC_
.ENDIF

/***********************************************************************************************************************
* TYPE DEFINITION
***********************************************************************************************************************/
.DSECT OAL_DTCM_DATA_SYS_STACK_SECTION
.DSECT OAL_DTCM_DATA_IRQ_STACK_SECTION
.DSECT OAL_DATA_BOOT_STACK_SECTION
/***********************************************************************************************************************
* MACRO DEFINITION
***********************************************************************************************************************/
.EQU OAL_FATAL_ERROR                        (0xFFFF)

.IF CORE_X1643

.EQU CORE_ID                                (0x0)
.EQU DMSS_CCOCR_OT_INVALIDATE               (0x20)
.EQU CONTEXT_SAVE_REG_NUM                   (372)
.EQU MODP_REG_OFFSET                        (104)

.ELIF CORE_XC4500

.EQU CORE_ID                                (0x1)
.EQU DMSS_CCOCR_OT_INVALIDATE               (0x10)
.EQU CONTEXT_SAVE_REG_NUM                   (1808)
.EQU MODP_REG_OFFSET                        (1524)

.ENDIF

.EQU DMSS_CCOCR_L1DCO_ENABLE                (0x2)
.EQU DCACHE_INVALIDATE_CFG_VALUE            (DMSS_CCOCR_OS_ENTIRE_CACHE | DMSS_CCOCR_OT_INVALIDATE | DMSS_CCOCR_L1DCO_ENABLE)

.EQU PMSS_INVALID_COMPLETE_BIT              (30)

.EQU ICACHE_DISABLE_VALUE                   (0x3)
.EQU ICACHE_ENABLE_VALUE                    (0xD)
.EQU ICACHE_PF_ENABLE_VALUE                 (0x5)
.EQU ICACHE_INVALIDATE_VALUE                (0x40000000)

.IFDEF CORE_X1643
.EQU DMSS_CCR_L1DCE_ENABLE                  (0x002)
.EQU DMSS_CCR_L1DC_DISABLE                  (0x000)
.EQU DMSS_CCR_MOM_SO                        (0x080)
.EQU DMSS_CCR_DAPE_ENABLE                   (0x200)

/* Default dcache is disable */
.EQU DCACHE_CFG_VALUE                       (DMSS_CCR_DAPE_ENABLE | DMSS_CCR_MOM_SO | DMSS_CCR_L1DC_DISABLE | DMSS_CCR_L1DCE_ENABLE)

.EQU DMSS_CDACR0L_BA                        (0x02E450)  ;17228000 stack/heap sharemem start addr DMSS_CDACR_L1W_WRITE_THROUGH
.EQU DMSS_CDACR1L_BA                        (0x02E462)  ;17231000 stack/heap ddr start addr DMSS_CDACR_L1W_COPY_BACK
/* REGION0 for SHRAM1 copy back cache, start addr 32KB align */
;.EQU DMSS_CDACR0L_BA                        (0x102230)  ;0x81118000 [31:15] => [20:4]  = 0x102230 range[0x81118000:0x8111FFFF] SHRAM1
/* REGION1 for DRAM data copy back cache, start addr 4M align */
;.EQU DMSS_CDACR1L_BA                        (0x001800)  ;0x00C00000 [31:22] => [20:11] = 0x001800 range[0x00C00000:0x00FFFFFF] DATA
.EQU DMSS_CDACR2L_BA                        (0x102000)  ;0x81000000 [31:19] => [20:08] = 0x003000 range[0x81000000:0x81054000] SHRAM0
.EQU DMSS_CDACR3L_BA                        (0x002000)  ;0x01000000 [31:22] => [20:11] = 0x002000 range[0x01000000:0x01400000] X1643 LONG DURATION
.EQU DMSS_CDACR4L_BA                        (0x002800)  ;0x01400000 [31:22] => [20:11] = 0x002800 range[0x01400000:0x01800000] X1643 LONG DURATION
.EQU DMSS_CDACR5L_BA                        (0x004800)  ;0x02400000 [31:22] => [20:11] = 0x004800 range[0x02400000:0x02800000] HLS STACK
.EQU DMSS_CDACR6L_BA                        (0x005000)  ;0x02800000 [31:22] => [20:11] = 0x005000 range[0x02800000:0x02C00000] HLS STACK
.EQU DMSS_CDACR7L_BA                        (0x005800)  ;0x03000000 [31:22] => [20:11] = 0x005800 range[0x02C00000:0x03000000] HLS STACK

.EQU DMSS_CDACRL_PS_16KB                    (0x0000000)
.EQU DMSS_CDACRL_PS_32KB                    (0x0200000)
.EQU DMSS_CDACRL_PS_64KB                    (0x0400000)
.EQU DMSS_CDACRL_PS_512KB                   (0x0600000)
.EQU DMSS_CDACRL_PS_1MB                     (0x0A00000)
.EQU DMSS_CDACRL_PS_2MB                     (0x1C00000)
.EQU DMSS_CDACRL_PS_4MB                     (0x1E00000)

.EQU DMSS_CDACR_L1DC_DI                     (0)
.EQU DMSS_CDACR_L1DC_EN                     (1)
.EQU DMSS_CDACR_L1DC_BIT                    (25)
.EQU DMSS_CDACR_L1DC_ENABLE                 (DMSS_CDACR_L1DC_EN << DMSS_CDACR_L1DC_BIT)
.EQU DMSS_CDACR_L1DC_DISABLE                (DMSS_CDACR_L1DC_DI << DMSS_CDACR_L1DC_BIT)

.EQU DMSS_CDACR_L1W_WT                      (0)
.EQU DMSS_CDACR_L1W_CB                      (1)
.EQU DMSS_CDACR_L1W_BIT                     (26)
.EQU DMSS_CDACR_L1W_WRITE_THROUGH           (DMSS_CDACR_L1W_WT << DMSS_CDACR_L1W_BIT)
.EQU DMSS_CDACR_L1W_COPY_BACK               (DMSS_CDACR_L1W_CB << DMSS_CDACR_L1W_BIT)

.EQU DMSS_CDACRL_VALID                      (0x1)
.EQU DMSS_CDACRL_INVALID                    (0x0)

.EQU DCACHE_CFG_FOR_REGION0                 (DMSS_CDACR_L1DC_ENABLE | DMSS_CDACR_L1W_WRITE_THROUGH | DMSS_CDACRL_PS_16KB | DMSS_CDACR0L_BA | DMSS_CDACRL_VALID)
.EQU DCACHE_CFG_FOR_REGION1                 (DMSS_CDACR_L1DC_ENABLE | DMSS_CDACR_L1W_COPY_BACK | DMSS_CDACRL_PS_16KB | DMSS_CDACR1L_BA | DMSS_CDACRL_VALID)
.EQU DCACHE_CFG_FOR_REGION2                 (DMSS_CDACR_L1DC_DISABLE | DMSS_CDACR_L1W_COPY_BACK | DMSS_CDACRL_PS_512KB | DMSS_CDACR2L_BA | DMSS_CDACRL_VALID)
.EQU DCACHE_CFG_FOR_REGION3                 (DMSS_CDACR_L1DC_DISABLE | DMSS_CDACR_L1W_COPY_BACK | DMSS_CDACRL_PS_4MB | DMSS_CDACR3L_BA | DMSS_CDACRL_VALID)
.EQU DCACHE_CFG_FOR_REGION4                 (DMSS_CDACR_L1DC_DISABLE | DMSS_CDACR_L1W_COPY_BACK | DMSS_CDACRL_PS_4MB | DMSS_CDACR4L_BA | DMSS_CDACRL_VALID)
.EQU DCACHE_CFG_FOR_REGION5                 (DMSS_CDACR_L1DC_DISABLE | DMSS_CDACRL_PS_4MB | DMSS_CDACR5L_BA | DMSS_CDACRL_VALID)
.EQU DCACHE_CFG_FOR_REGION6                 (DMSS_CDACR_L1DC_DISABLE | DMSS_CDACRL_PS_4MB | DMSS_CDACR6L_BA | DMSS_CDACRL_VALID)
.EQU DCACHE_CFG_FOR_REGION7                 (DMSS_CDACR_L1DC_DISABLE | DMSS_CDACRL_PS_4MB | DMSS_CDACR7L_BA | DMSS_CDACRL_VALID)

.EQU AP_READ_OR_WRITE_ENABLE                (0x0)

.EQU DCACHE_CFG_FOR_REGION0_AP              (AP_READ_OR_WRITE_ENABLE)
.EQU DCACHE_CFG_FOR_REGION1_AP              (AP_READ_OR_WRITE_ENABLE)
.EQU DCACHE_CFG_FOR_REGION2_AP              (AP_READ_OR_WRITE_ENABLE)
.EQU DCACHE_CFG_FOR_REGION3_AP              (AP_READ_OR_WRITE_ENABLE)
.EQU DCACHE_CFG_FOR_REGION4_AP              (AP_READ_OR_WRITE_ENABLE)
.EQU DCACHE_CFG_FOR_REGION5_AP              (AP_READ_OR_WRITE_ENABLE)
.EQU DCACHE_CFG_FOR_REGION6_AP              (AP_READ_OR_WRITE_ENABLE)
.EQU DCACHE_CFG_FOR_REGION7_AP              (AP_READ_OR_WRITE_ENABLE)

.EQU DMSS_CCOCR_OT_FLUSH                    (0x28)
.EQU DMSS_CCOCR_OT_LOCK                     (0x10)
.EQU DMSS_CCOCR_OT_UNLOCK                   (0x18)
.EQU DMSS_CCOCR_OT_FLUSH_INVALIDATE         (0x30)

.EQU DMSS_CCOCR_OS_ADDR_BASE                (0x00)
.EQU DMSS_CCOCR_OS_ALL_LINE                 (0x80)

.EQU DCACHE_FLUSH_ALL_VALUE                 (DMSS_CCOCR_OS_ALL_LINE | DMSS_CCOCR_OT_FLUSH | DMSS_CCOCR_L1DCO_ENABLE)

.EQU DCACHE_INVALIDATE_ALL_VALUE            (DMSS_CCOCR_OS_ALL_LINE | DMSS_CCOCR_OT_INVALIDATE | DMSS_CCOCR_L1DCO_ENABLE)

.EQU DCACHE_FLUSH_ADDR_BASE_VALUE           (DMSS_CCOCR_OS_ADDR_BASE | DMSS_CCOCR_OT_FLUSH | DMSS_CCOCR_L1DCO_ENABLE)
.EQU DCACHE_INVALIDATE_ADDR_BASE_VALUE      (DMSS_CCOCR_OS_ADDR_BASE | DMSS_CCOCR_OT_INVALIDATE | DMSS_CCOCR_L1DCO_ENABLE)
.EQU DCACHE_INVALIDATE_FLUSH_ALL_VALUE      (DMSS_CCOCR_OS_ALL_LINE | DMSS_CCOCR_OT_FLUSH_INVALIDATE | DMSS_CCOCR_L1DCO_ENABLE)

.ELIF CORE_XC4500

.EQU DMSS_CCOCR_OS_ADDR_BASE                (0x00)
.EQU DMSS_CCOCR_OS_ALL_LINE                 (0x80)

.EQU CORE_IO_DMSS_CCOSAR                    (0x1340)
.EQU CORE_IO_DMSS_CCOSLR                    (0x1344)
.EQU CORE_IO_DMSS_CCOCR                     (0x1348)

.EQU DCACHE_FLUSH_ALL_VALUE                 (DMSS_CCOCR_OS_ALL_LINE | DMSS_CCOCR_OT_FLUSH | DMSS_CCOCR_L1DCO_ENABLE)
.EQU DCACHE_INVALIDATE_ALL_VALUE            (DMSS_CCOCR_OS_ALL_LINE | DMSS_CCOCR_OT_INVALIDATE | DMSS_CCOCR_L1DCO_ENABLE)
.EQU DCACHE_FLUSH_ADDR_BASE_VALUE           (DMSS_CCOCR_OS_ADDR_BASE | DMSS_CCOCR_OT_FLUSH | DMSS_CCOCR_L1DCO_ENABLE)
.EQU DCACHE_INVALIDATE_ADDR_BASE_VALUE      (DMSS_CCOCR_OS_ADDR_BASE | DMSS_CCOCR_OT_INVALIDATE | DMSS_CCOCR_L1DCO_ENABLE)

.ENDIF

.EQU OAL_MEM_SPECIAL_TAG                    (0x12345678)

.EQU CORE_MSS_IO_BASE                       (0x00000000)
.EQU CORE_IO_PMSS_PCR                       (CORE_MSS_IO_BASE + 0x0)
.EQU CORE_IO_PMSS_PB1BA                     (CORE_MSS_IO_BASE + 0x4)

.EQU CORE_OCEM_IO_BASE                      (0x00000100)
.EQU CORE_IO_OCM_OFIO5                      (CORE_OCEM_IO_BASE + 0x038)

.EQU CORE_IO_PMSS_PDIA                      (CORE_MSS_IO_BASE + 0xC)
.EQU CORE_IO_PMSS_PDEA                      (CORE_MSS_IO_BASE + 0x8)
.EQU CORE_IO_PMSS_PDTC                      (CORE_MSS_IO_BASE + 0x10)

.IFDEF CORE_XC4500
.EQU CORE_IO_DMSS_DMBA                      (CORE_MSS_IO_BASE + 0x14)
.EQU CORE_IO_DMSS_DMBE                      (CORE_MSS_IO_BASE + 0x18)
.EQU CORE_IO_DMSS_DDIA                      (CORE_MSS_IO_BASE + 0x20)
.EQU CORE_IO_DMSS_DDEA                      (CORE_MSS_IO_BASE + 0x1C)
.EQU CORE_IO_DMSS_DDTC                      (CORE_MSS_IO_BASE + 0x24)
.EQU CORE_IO_DMSS_DDQS                      (CORE_MSS_IO_BASE + 0x28)
.EQU CORE_IO_DMSS_DDRS                      (CORE_MSS_IO_BASE + 0x2C)
.EQU CORE_IO_DMSS_GPIN                      (CORE_MSS_IO_BASE + 0x34)
.EQU CORE_IO_DMSS_GPOUT                     (CORE_MSS_IO_BASE + 0x38)

.EQU CORE_IO_PSU_PSVM_LO                    (CORE_MSS_IO_BASE + 0x250)

.EQU CORE_IO_FICS_COR                       (CORE_MSS_IO_BASE + 0x1504)
.EQU CORE_IO_FICMR_COR                      (CORE_MSS_IO_BASE + 0x1508)

.EQU DMSS_ADD0_START_ADDR                   (0x1520)
.EQU DMSS_ADD1_START_ADDR                   (0x1530)
.EQU DMSS_ADD2_START_ADDR                   (0x1540)
.EQU DMSS_ADD3_START_ADDR                   (0x1550)
.EQU DMSS_ADD4_START_ADDR                   (0x1560)
.EQU DMSS_ADD5_START_ADDR                   (0x1570)
.EQU DMSS_ADD6_START_ADDR                   (0x1580)
.EQU DMSS_ADD7_START_ADDR                   (0x1590)

.EQU DMSS_ADD0_ATT0_ADDR                    (0x1524)
.EQU DMSS_ADD1_ATT0_ADDR                    (0x1534)
.EQU DMSS_ADD2_ATT0_ADDR                    (0x1544)
.EQU DMSS_ADD3_ATT0_ADDR                    (0x1554)
.EQU DMSS_ADD4_ATT0_ADDR                    (0x1564)
.EQU DMSS_ADD5_ATT0_ADDR                    (0x1574)
.EQU DMSS_ADD6_ATT0_ADDR                    (0x1584)
.EQU DMSS_ADD7_ATT0_ADDR                    (0x1594)

.ENDIF

.IFDEF CORE_X1643

.EQU CORE_DMSS_IO_BASE                      (0x00000300)
.EQU CORE_IO_DMSS_CHRR1                     (CORE_DMSS_IO_BASE + 0x00)
.EQU CORE_IO_DMSS_DTAP                      (CORE_DMSS_IO_BASE + 0x04)
.EQU CORE_IO_DMSS_CHRR2                     (CORE_DMSS_IO_BASE + 0x08)
.EQU CORE_IO_DMSS_CCR                       (CORE_DMSS_IO_BASE + 0x0C)
.EQU CORE_IO_DMSS_CCOSAR                    (CORE_DMSS_IO_BASE + 0x10)
.EQU CORE_IO_DMSS_CCOSLR                    (CORE_DMSS_IO_BASE + 0x14)
.EQU CORE_IO_DMSS_CCOCR                     (CORE_DMSS_IO_BASE + 0x18)
.EQU CORE_IO_DMSS_CAR                       (CORE_DMSS_IO_BASE + 0x48)
.EQU CORE_IO_DMSS_CDACR0L                   (CORE_DMSS_IO_BASE + 0x6C)
.EQU CORE_IO_DMSS_CDACR0H                   (CORE_DMSS_IO_BASE + 0x70)
.EQU CORE_IO_DMSS_CDACR1L                   (CORE_DMSS_IO_BASE + 0x74)
.EQU CORE_IO_DMSS_CDACR1H                   (CORE_DMSS_IO_BASE + 0x78)
.EQU CORE_IO_DMSS_CDACR2L                   (CORE_DMSS_IO_BASE + 0x7C)
.EQU CORE_IO_DMSS_CDACR2H                   (CORE_DMSS_IO_BASE + 0x80)
.EQU CORE_IO_DMSS_CDACR3L                   (CORE_DMSS_IO_BASE + 0x84)
.EQU CORE_IO_DMSS_CDACR3H                   (CORE_DMSS_IO_BASE + 0x88)
.EQU CORE_IO_DMSS_CDACR4L                   (CORE_DMSS_IO_BASE + 0x8C)
.EQU CORE_IO_DMSS_CDACR4H                   (CORE_DMSS_IO_BASE + 0x90)
.EQU CORE_IO_DMSS_CDACR5L                   (CORE_DMSS_IO_BASE + 0x94)
.EQU CORE_IO_DMSS_CDACR5H                   (CORE_DMSS_IO_BASE + 0x98)
.EQU CORE_IO_DMSS_CDACR6L                   (CORE_DMSS_IO_BASE + 0x9C)
.EQU CORE_IO_DMSS_CDACR6H                   (CORE_DMSS_IO_BASE + 0xA0)
.EQU CORE_IO_DMSS_CDACR7L                   (CORE_DMSS_IO_BASE + 0xA4)
.EQU CORE_IO_DMSS_CDACR7H                   (CORE_DMSS_IO_BASE + 0xA8)
.EQU CORE_IO_DMSS_CAPAR                     (CORE_DMSS_IO_BASE + 0xAC)
.EQU CORE_IO_DMSS_CAPSR                     (CORE_DMSS_IO_BASE + 0xB0)
.EQU CORE_IO_DMSS_DPCON                     (CORE_DMSS_IO_BASE + 0xB8)
.EQU CORE_IO_DMSS_WRC                       (CORE_DMSS_IO_BASE + 0xBC)

.ENDIF

.EQU CORE_IO_UOP_STS                        (CORE_MSS_IO_BASE + 0x58)
.EQU CORE_IO_UOP_PAR                        (CORE_MSS_IO_BASE + 0x5C)
.EQU CORE_IO_XCI_COR                        (CORE_MSS_IO_BASE + 0x60)

.EQU CORE_IO_LRU_SLT_LO                     (CORE_MSS_IO_BASE + 0x2A0)
.EQU CORE_IO_LRU_SLT_HI                     (CORE_MSS_IO_BASE + 0x2A4)
.EQU CORE_IO_LRU_SLT_PRI                    (CORE_MSS_IO_BASE + 0x2A8)
.EQU CORE_IO_LRU_WEIGHT_LO                  (CORE_MSS_IO_BASE + 0x2AC)
.EQU CORE_IO_LRU_WEIGHT_HI                  (CORE_MSS_IO_BASE + 0x2B0)

.EQU PMSS_PDTC_PDST_BIT                     (29)

.EQU DMSS_DDTC_DDST_BIT                     (29)

.EQU DMSS_DDTC_DDIR_BIT                     (30)
.EQU DMSS_DDTC_DDIE_BIT                     (31)

.EQU DMSS_DDTC_DDIR_DL                      (0); copy from ext to dtcm
.EQU DMSS_DDTC_DDIR_UL                      (1); copy from dtcm to ext

.EQU DMSS_DDTC_DDIE_EN                      (1); enable ddma int
.EQU DMSS_DDTC_DDIE_DISABLE                 (0); disable ddma int

.EQU DMSS_DDTC_REG_DL_VALUE                 (DMSS_DDTC_DDIR_DL << DMSS_DDTC_DDIR_BIT | DMSS_DDTC_DDIE_DISABLE << DMSS_DDTC_DDIE_BIT)
.EQU DMSS_DDTC_REG_UL_VALUE                 (DMSS_DDTC_DDIR_UL << DMSS_DDTC_DDIR_BIT | DMSS_DDTC_DDIE_DISABLE << DMSS_DDTC_DDIE_BIT)

.IF CORE_X1643

.EQU ICTL0_IRQ_INTMASK_L                    (0x17500008)
.EQU ICTL0_IRQ_INTMASK_H                    (0x1750000C)
.EQU ICTL0_IRQ_FINALSTATUS_L                (0x17500030)
.EQU ICTL0_IRQ_FINALSTATUS_H                (0x17500034)

.EQU ICTL1_IRQ_INTMASK_L                    (0x17580008)
.EQU ICTL1_IRQ_INTMASK_H                    (0x1758000C)
.EQU ICTL1_IRQ_FINALSTATUS_L                (0x17580030)
.EQU ICTL1_IRQ_FINALSTATUS_H                (0x17580034)

.ELIF CORE_XC4500

.EQU ICTL0_IRQ_INTMASK_L                    (0x17540008)
.EQU ICTL0_IRQ_INTMASK_H                    (0x1754000C)
.EQU ICTL0_IRQ_FINALSTATUS_L                (0x17540030)
.EQU ICTL0_IRQ_FINALSTATUS_H                (0x17540034)

.EQU ICTL1_IRQ_INTMASK_L                    (0x175C0008)
.EQU ICTL1_IRQ_INTMASK_H                    (0x175C000C)
.EQU ICTL1_IRQ_FINALSTATUS_L                (0x175C0030)
.EQU ICTL1_IRQ_FINALSTATUS_H                (0x175C0034)

.ENDIF

.EQU SIZEOF_UINT16                          (2)
.EQU SIZEOF_UINT32                          (4)

.EQU OAL_IRQ_LVL_0                          (0)
.EQU OAL_IRQ_LVL_1                          (1)
.EQU OAL_IRQ_LVL_2                          (2)

.EQU OAL_IRQ_AMT_PER_LVL                    (16)

.IF CORE_XC4500
.EQU CORE_DTCM_SIZE                         (0x100000); 1MB
.ENDIF

.EQU OAL_IRQ_INVALID_INDEX                  (0xFFFF)

.EQU OAL_TASK_TCB_VP_STACK_PTR_OFFSET       (28) /* byte */
.EQU OAL_TASK_TCB_VP_STACK_BOTTOM_OFFSET    (32) /* byte */
.EQU OAL_TASK_TCB_VP_STACK_TOP_OFFSET       (36) /* byte */
.EQU OAL_TASK_TCB_U16_RUN_COUNTER_OFFSET    (2)  /* byte */

.EQU OAL_L1OS_TASK_STACK_OVERWRITE          (0xB05)

.IF CORE_X1643

.MACRO PROLOGUE_DD
    ;push {dw} retreg
    ;push {dw} retregi
    pushspa {dw}

    push{dw} modp
    push{dw} modq

    ;push {dw} a8
    LS1.push {dw, ext} a8e || LS0.push {dw} a8
    mov moda, a8
    ;push {dw} a8
    LS1.push{dw, ext} a8e || LS0.push {dw} a8
    mov #0x000001B, moda

    push {dw} r4
    mov mod0, r4
    push {dw} r4

    mov mod2, r4
    push {dw} r4
.ENDM

.MACRO EPILOGUE_DD
    pop{dw} r4
    nop
    nop
    mov r4, mod2

    pop {dw} r4
    nop
    nop
    mov r4, mod0
    pop {dw} r4

    ;pop {dw} a8
    LS0.pop {dw} a8 || LS1.pop {dw, ext} a8e
    nop
    mov a8, moda
    ;pop {dw} a8
    LS0.pop {dw} a8 || LS1.pop {dw, ext} a8e

    pop{dw} modq
    pop{dw} modp

    pop{dw} retreg    /* pop SP */
    nop
    nop
    nop
    mov retreg, sp
    nop
    nop
    ;pop {dw} retregi
    nop
    nop
    ;pop {dw} retreg

.ENDM

.ELIF CORE_XC4500

.MACRO PROLOGUE_DD
    nop
    nop
    nop
    nop
    LS1.push {dw, ext} a8e || LS0.push {dw} a8
    nop
    nop
    nop
    nop
    pushspa {dw}
    mov #0x00000e0f, a8
    push {4dw} modx
    nop
    nop
    nop
    nop
    vpush {dw} modv0
    vb.vmova a8, modv0
    vpush {dw} modv1
    vpush {dw} modv2
    mov #0x00606000, a8
    mov #0x1b, modg
    mov #0xc1, mod1
    vb.vmova a8, modv2
    push {16dw} auxreg0
    push {16dw} auxreg1
    push {dw} lc
.ENDM

.MACRO EPILOGUE_DD
    pop {dw} lc
    pop {16dw} auxreg1
    pop {16dw} auxreg0
    vpop {dw} modv2
    vpop {dw} modv1
    vpop {dw} modv0
    nop
    nop
    nop
    nop
    pop {4dw} modx
    nop
    nop
    nop
    nop
    pop {dw} sp
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    LS0.pop {dw} a8 || LS1.pop {dw, ext} a8e
    nop
    nop
    nop
    nop
.ENDM

.ENDIF

/***********************************************************************************************************************
* GLOBAL VARIABLES DEFINITION
***********************************************************************************************************************/
.EXTERN _g_u32_error_sp_save
.EXTERN _g_u32_error_sp_save2
.EXTERN _g_u32p_error_stack_bottom
.EXTERN _g_st_context_save
.EXTERN _g_u32_reg_save_area
.EXTERN _g_u32_arx_save_area
.EXTERN _g_u32_arx_save_area2
.EXTERN _g_u32_retreg_save_area
.EXTERN _g_st_oal_mss_reg

.EXTERN _g_u16_oal_irq_index
.EXTERN _g_fp_oal_irq_vector_tbl
.EXTERN _g_u16_oal_irq_read_offset
.EXTERN _g_u16_oal_irq_write_offset

.EXTERN _g_u32_sp_save
.EXTERN _g_u32_retreg_save
.EXTERN _g_u32_retregi_save

.EXTERN _g_stp_ready_to_run_task
.EXTERN _g_stp_current_running_task
.EXTERN _g_u16_l1os_int_nesting_cnt

.EXTERN _g_u32p_boot_stack_bottom
.EXTERN _g_u32_boot_addr_flag
.EXTERN _g_u32_int_cnt_l0
.EXTERN _g_u32_int_cnt_l1
.EXTERN _g_u32_int_cnt_l2
/***********************************************************************************************************************
* EXTERN FUNCTION DECLARATION
***********************************************************************************************************************/
.EXTERN .bss
.EXTERN _main
.EXTERN _ks_oal_error_handler_ext_c

.EXTERN __call_saved_store_w_frame
.EXTERN __call_saved_restore_w_frame
.EXTERN _ks_print_os_error_handler
.EXTERN _ks_oal_assert

/***********************************************************************************************************************
* GLOBAL FUNCTION DECLARATION
***********************************************************************************************************************/
.GLOBAL __int0_handler
.GLOBAL __int1_handler
.GLOBAL __trap0_handler
.GLOBAL __trap1_handler
.GLOBAL __trap2_handler

.GLOBAL __init_cache

.GLOBAL __init_bss_section
.GLOBAL _ks_oal_bootload

.GLOBAL __init_fic
.GLOBAL __init_psvm_reg

.GLOBAL __mem_copy_asm
.GLOBAL __mem_set_asm

.IFDEF CORE_XC4500
.GLOBAL __ddma_mem_copy
.GLOBAL __mem_copy_asm_ext
.GLOBAL __mem_set_asm_ext
.ENDIF

.GLOBAL __init_sys_stack
.GLOBAL __init_irq_stack

.GLOBAL __init_modx_regs
.GLOBAL __init_ccr_reg
.GLOBAL __pdma_mem_copy

.GLOBAL __ks_os_task_sch
.GLOBAL __ks_os_task_context_save
.GLOBAL __ks_os_task_context_restore
.GLOBAL __ks_os_task_switch_to_kernel

.GLOBAL __ks_os_delay
.GLOBAL __ks_os_error_handler
.GLOBAL __ks_os_context_save
.GLOBAL __ks_os_mss_reg_save
.GLOBAL __dcache_flush
/**************************************************** END OF FILE *****************************************************/

