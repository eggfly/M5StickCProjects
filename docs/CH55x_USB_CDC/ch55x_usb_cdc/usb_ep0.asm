;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (MINGW64)
;--------------------------------------------------------
	.module usb_ep0
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _memcpy
	.globl _CDC_SetBaud
	.globl _USB_EP_HALT_CLEAR
	.globl _USB_EP_HALT_SET
	.globl _UIF_BUS_RST
	.globl _UIF_DETECT
	.globl _UIF_TRANSFER
	.globl _UIF_SUSPEND
	.globl _UIF_HST_SOF
	.globl _UIF_FIFO_OV
	.globl _U_SIE_FREE
	.globl _U_TOG_OK
	.globl _U_IS_NAK
	.globl _ADC_CHAN0
	.globl _ADC_CHAN1
	.globl _CMP_CHAN
	.globl _ADC_START
	.globl _ADC_IF
	.globl _CMP_IF
	.globl _CMPO
	.globl _U1RI
	.globl _U1TI
	.globl _U1RB8
	.globl _U1TB8
	.globl _U1REN
	.globl _U1SMOD
	.globl _U1SM0
	.globl _S0_R_FIFO
	.globl _S0_T_FIFO
	.globl _S0_FREE
	.globl _S0_IF_BYTE
	.globl _S0_IF_FIRST
	.globl _S0_IF_OV
	.globl _S0_FST_ACT
	.globl _CP_RL2
	.globl _C_T2
	.globl _TR2
	.globl _EXEN2
	.globl _TCLK
	.globl _RCLK
	.globl _EXF2
	.globl _CAP1F
	.globl _TF2
	.globl _RI
	.globl _TI
	.globl _RB8
	.globl _TB8
	.globl _REN
	.globl _SM2
	.globl _SM1
	.globl _SM0
	.globl _IT0
	.globl _IE0
	.globl _IT1
	.globl _IE1
	.globl _TR0
	.globl _TF0
	.globl _TR1
	.globl _TF1
	.globl _RXD
	.globl _PWM1_
	.globl _TXD
	.globl _PWM2_
	.globl _AIN3
	.globl _VBUS1
	.globl _INT0
	.globl _TXD1_
	.globl _INT1
	.globl _T0
	.globl _RXD1_
	.globl _PWM2
	.globl _T1
	.globl _UDP
	.globl _UDM
	.globl _TIN0
	.globl _CAP1
	.globl _T2
	.globl _AIN0
	.globl _VBUS2
	.globl _TIN1
	.globl _CAP2
	.globl _T2EX
	.globl _RXD_
	.globl _TXD_
	.globl _AIN1
	.globl _UCC1
	.globl _TIN2
	.globl _SCS
	.globl _CAP1_
	.globl _T2_
	.globl _AIN2
	.globl _UCC2
	.globl _TIN3
	.globl _PWM1
	.globl _MOSI
	.globl _TIN4
	.globl _RXD1
	.globl _MISO
	.globl _TIN5
	.globl _TXD1
	.globl _SCK
	.globl _IE_SPI0
	.globl _IE_TKEY
	.globl _IE_USB
	.globl _IE_ADC
	.globl _IE_UART1
	.globl _IE_PWMX
	.globl _IE_GPIO
	.globl _IE_WDOG
	.globl _PX0
	.globl _PT0
	.globl _PX1
	.globl _PT1
	.globl _PS
	.globl _PT2
	.globl _PL_FLAG
	.globl _PH_FLAG
	.globl _EX0
	.globl _ET0
	.globl _EX1
	.globl _ET1
	.globl _ES
	.globl _ET2
	.globl _E_DIS
	.globl _EA
	.globl _P
	.globl _F1
	.globl _OV
	.globl _RS0
	.globl _RS1
	.globl _F0
	.globl _AC
	.globl _CY
	.globl _UEP1_DMA_H
	.globl _UEP1_DMA_L
	.globl _UEP1_DMA
	.globl _UEP0_DMA_H
	.globl _UEP0_DMA_L
	.globl _UEP0_DMA
	.globl _UEP2_3_MOD
	.globl _UEP4_1_MOD
	.globl _UEP3_DMA_H
	.globl _UEP3_DMA_L
	.globl _UEP3_DMA
	.globl _UEP2_DMA_H
	.globl _UEP2_DMA_L
	.globl _UEP2_DMA
	.globl _USB_DEV_AD
	.globl _USB_CTRL
	.globl _USB_INT_EN
	.globl _UEP4_T_LEN
	.globl _UEP4_CTRL
	.globl _UEP0_T_LEN
	.globl _UEP0_CTRL
	.globl _USB_RX_LEN
	.globl _USB_MIS_ST
	.globl _USB_INT_ST
	.globl _USB_INT_FG
	.globl _UEP3_T_LEN
	.globl _UEP3_CTRL
	.globl _UEP2_T_LEN
	.globl _UEP2_CTRL
	.globl _UEP1_T_LEN
	.globl _UEP1_CTRL
	.globl _UDEV_CTRL
	.globl _USB_C_CTRL
	.globl _TKEY_DATH
	.globl _TKEY_DATL
	.globl _TKEY_DAT
	.globl _TKEY_CTRL
	.globl _ADC_DATA
	.globl _ADC_CFG
	.globl _ADC_CTRL
	.globl _SBAUD1
	.globl _SBUF1
	.globl _SCON1
	.globl _SPI0_SETUP
	.globl _SPI0_CK_SE
	.globl _SPI0_CTRL
	.globl _SPI0_DATA
	.globl _SPI0_STAT
	.globl _PWM_CK_SE
	.globl _PWM_CTRL
	.globl _PWM_DATA1
	.globl _PWM_DATA2
	.globl _T2CAP1H
	.globl _T2CAP1L
	.globl _T2CAP1
	.globl _TH2
	.globl _TL2
	.globl _T2COUNT
	.globl _RCAP2H
	.globl _RCAP2L
	.globl _RCAP2
	.globl _T2MOD
	.globl _T2CON
	.globl _SBUF
	.globl _SCON
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _XBUS_AUX
	.globl _PIN_FUNC
	.globl _P3_DIR_PU
	.globl _P3_MOD_OC
	.globl _P3
	.globl _P2
	.globl _P1_DIR_PU
	.globl _P1_MOD_OC
	.globl _P1
	.globl _ROM_CTRL
	.globl _ROM_DATA_H
	.globl _ROM_DATA_L
	.globl _ROM_DATA
	.globl _ROM_ADDR_H
	.globl _ROM_ADDR_L
	.globl _ROM_ADDR
	.globl _GPIO_IE
	.globl _IP_EX
	.globl _IE_EX
	.globl _IP
	.globl _IE
	.globl _WDOG_COUNT
	.globl _RESET_KEEP
	.globl _WAKE_CTRL
	.globl _CLOCK_CFG
	.globl _PCON
	.globl _GLOBAL_CFG
	.globl _SAFE_MOD
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _Ep0Buffer
	.globl _controlStates
	.globl _pDescr
	.globl _UsbConfig
	.globl _SetupLen
	.globl _SetupReq
	.globl _USB_EP0_SETUP
	.globl _USB_EP0_IN
	.globl _USB_EP0_OUT
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_SAFE_MOD	=	0x00a1
_GLOBAL_CFG	=	0x00b1
_PCON	=	0x0087
_CLOCK_CFG	=	0x00b9
_WAKE_CTRL	=	0x00a9
_RESET_KEEP	=	0x00fe
_WDOG_COUNT	=	0x00ff
_IE	=	0x00a8
_IP	=	0x00b8
_IE_EX	=	0x00e8
_IP_EX	=	0x00e9
_GPIO_IE	=	0x00c7
_ROM_ADDR	=	0x8584
_ROM_ADDR_L	=	0x0084
_ROM_ADDR_H	=	0x0085
_ROM_DATA	=	0x8f8e
_ROM_DATA_L	=	0x008e
_ROM_DATA_H	=	0x008f
_ROM_CTRL	=	0x0086
_P1	=	0x0090
_P1_MOD_OC	=	0x0092
_P1_DIR_PU	=	0x0093
_P2	=	0x00a0
_P3	=	0x00b0
_P3_MOD_OC	=	0x0096
_P3_DIR_PU	=	0x0097
_PIN_FUNC	=	0x00c6
_XBUS_AUX	=	0x00a2
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_SCON	=	0x0098
_SBUF	=	0x0099
_T2CON	=	0x00c8
_T2MOD	=	0x00c9
_RCAP2	=	0xcbca
_RCAP2L	=	0x00ca
_RCAP2H	=	0x00cb
_T2COUNT	=	0xcdcc
_TL2	=	0x00cc
_TH2	=	0x00cd
_T2CAP1	=	0xcfce
_T2CAP1L	=	0x00ce
_T2CAP1H	=	0x00cf
_PWM_DATA2	=	0x009b
_PWM_DATA1	=	0x009c
_PWM_CTRL	=	0x009d
_PWM_CK_SE	=	0x009e
_SPI0_STAT	=	0x00f8
_SPI0_DATA	=	0x00f9
_SPI0_CTRL	=	0x00fa
_SPI0_CK_SE	=	0x00fb
_SPI0_SETUP	=	0x00fc
_SCON1	=	0x00c0
_SBUF1	=	0x00c1
_SBAUD1	=	0x00c2
_ADC_CTRL	=	0x0080
_ADC_CFG	=	0x009a
_ADC_DATA	=	0x009f
_TKEY_CTRL	=	0x00c3
_TKEY_DAT	=	0xc5c4
_TKEY_DATL	=	0x00c4
_TKEY_DATH	=	0x00c5
_USB_C_CTRL	=	0x0091
_UDEV_CTRL	=	0x00d1
_UEP1_CTRL	=	0x00d2
_UEP1_T_LEN	=	0x00d3
_UEP2_CTRL	=	0x00d4
_UEP2_T_LEN	=	0x00d5
_UEP3_CTRL	=	0x00d6
_UEP3_T_LEN	=	0x00d7
_USB_INT_FG	=	0x00d8
_USB_INT_ST	=	0x00d9
_USB_MIS_ST	=	0x00da
_USB_RX_LEN	=	0x00db
_UEP0_CTRL	=	0x00dc
_UEP0_T_LEN	=	0x00dd
_UEP4_CTRL	=	0x00de
_UEP4_T_LEN	=	0x00df
_USB_INT_EN	=	0x00e1
_USB_CTRL	=	0x00e2
_USB_DEV_AD	=	0x00e3
_UEP2_DMA	=	0xe5e4
_UEP2_DMA_L	=	0x00e4
_UEP2_DMA_H	=	0x00e5
_UEP3_DMA	=	0xe7e6
_UEP3_DMA_L	=	0x00e6
_UEP3_DMA_H	=	0x00e7
_UEP4_1_MOD	=	0x00ea
_UEP2_3_MOD	=	0x00eb
_UEP0_DMA	=	0xedec
_UEP0_DMA_L	=	0x00ec
_UEP0_DMA_H	=	0x00ed
_UEP1_DMA	=	0xefee
_UEP1_DMA_L	=	0x00ee
_UEP1_DMA_H	=	0x00ef
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_CY	=	0x00d7
_AC	=	0x00d6
_F0	=	0x00d5
_RS1	=	0x00d4
_RS0	=	0x00d3
_OV	=	0x00d2
_F1	=	0x00d1
_P	=	0x00d0
_EA	=	0x00af
_E_DIS	=	0x00ae
_ET2	=	0x00ad
_ES	=	0x00ac
_ET1	=	0x00ab
_EX1	=	0x00aa
_ET0	=	0x00a9
_EX0	=	0x00a8
_PH_FLAG	=	0x00bf
_PL_FLAG	=	0x00be
_PT2	=	0x00bd
_PS	=	0x00bc
_PT1	=	0x00bb
_PX1	=	0x00ba
_PT0	=	0x00b9
_PX0	=	0x00b8
_IE_WDOG	=	0x00ef
_IE_GPIO	=	0x00ee
_IE_PWMX	=	0x00ed
_IE_UART1	=	0x00ec
_IE_ADC	=	0x00eb
_IE_USB	=	0x00ea
_IE_TKEY	=	0x00e9
_IE_SPI0	=	0x00e8
_SCK	=	0x0097
_TXD1	=	0x0097
_TIN5	=	0x0097
_MISO	=	0x0096
_RXD1	=	0x0096
_TIN4	=	0x0096
_MOSI	=	0x0095
_PWM1	=	0x0095
_TIN3	=	0x0095
_UCC2	=	0x0095
_AIN2	=	0x0095
_T2_	=	0x0094
_CAP1_	=	0x0094
_SCS	=	0x0094
_TIN2	=	0x0094
_UCC1	=	0x0094
_AIN1	=	0x0094
_TXD_	=	0x0093
_RXD_	=	0x0092
_T2EX	=	0x0091
_CAP2	=	0x0091
_TIN1	=	0x0091
_VBUS2	=	0x0091
_AIN0	=	0x0091
_T2	=	0x0090
_CAP1	=	0x0090
_TIN0	=	0x0090
_UDM	=	0x00b7
_UDP	=	0x00b6
_T1	=	0x00b5
_PWM2	=	0x00b4
_RXD1_	=	0x00b4
_T0	=	0x00b4
_INT1	=	0x00b3
_TXD1_	=	0x00b2
_INT0	=	0x00b2
_VBUS1	=	0x00b2
_AIN3	=	0x00b2
_PWM2_	=	0x00b1
_TXD	=	0x00b1
_PWM1_	=	0x00b0
_RXD	=	0x00b0
_TF1	=	0x008f
_TR1	=	0x008e
_TF0	=	0x008d
_TR0	=	0x008c
_IE1	=	0x008b
_IT1	=	0x008a
_IE0	=	0x0089
_IT0	=	0x0088
_SM0	=	0x009f
_SM1	=	0x009e
_SM2	=	0x009d
_REN	=	0x009c
_TB8	=	0x009b
_RB8	=	0x009a
_TI	=	0x0099
_RI	=	0x0098
_TF2	=	0x00cf
_CAP1F	=	0x00cf
_EXF2	=	0x00ce
_RCLK	=	0x00cd
_TCLK	=	0x00cc
_EXEN2	=	0x00cb
_TR2	=	0x00ca
_C_T2	=	0x00c9
_CP_RL2	=	0x00c8
_S0_FST_ACT	=	0x00ff
_S0_IF_OV	=	0x00fe
_S0_IF_FIRST	=	0x00fd
_S0_IF_BYTE	=	0x00fc
_S0_FREE	=	0x00fb
_S0_T_FIFO	=	0x00fa
_S0_R_FIFO	=	0x00f8
_U1SM0	=	0x00c7
_U1SMOD	=	0x00c5
_U1REN	=	0x00c4
_U1TB8	=	0x00c3
_U1RB8	=	0x00c2
_U1TI	=	0x00c1
_U1RI	=	0x00c0
_CMPO	=	0x0087
_CMP_IF	=	0x0086
_ADC_IF	=	0x0085
_ADC_START	=	0x0084
_CMP_CHAN	=	0x0083
_ADC_CHAN1	=	0x0081
_ADC_CHAN0	=	0x0080
_U_IS_NAK	=	0x00df
_U_TOG_OK	=	0x00de
_U_SIE_FREE	=	0x00dd
_UIF_FIFO_OV	=	0x00dc
_UIF_HST_SOF	=	0x00db
_UIF_SUSPEND	=	0x00da
_UIF_TRANSFER	=	0x00d9
_UIF_DETECT	=	0x00d8
_UIF_BUS_RST	=	0x00d8
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_SetupReq::
	.ds 1
_SetupLen::
	.ds 1
_UsbConfig::
	.ds 1
_pDescr::
	.ds 3
_controlStates::
	.ds 2
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
_Ep0Buffer	=	0x0000
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;	usb_ep0.c:24: uint8_t controlStates[2] = {0x00, 0x00};
	mov	_controlStates,#0x00
	mov	(_controlStates + 0x0001),#0x00
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'USB_EP0_SETUP'
;------------------------------------------------------------
;len                       Allocated to registers r5 
;------------------------------------------------------------
;	usb_ep0.c:28: void USB_EP0_SETUP(void) {
;	-----------------------------------------
;	 function USB_EP0_SETUP
;	-----------------------------------------
_USB_EP0_SETUP:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	usb_ep0.c:29: uint8_t len = USB_RX_LEN;
	mov	r7,_USB_RX_LEN
;	usb_ep0.c:30: if (len == (sizeof(USB_SETUP_REQ))) {
	cjne	r7,#0x08,00289$
	sjmp	00290$
00289$:
	ljmp	00158$
00290$:
;	usb_ep0.c:31: SetupLen = UsbSetupBuf->wLengthL;
	mov	dptr,#(_Ep0Buffer + 0x0006)
	movx	a,@dptr
	mov	_SetupLen,a
;	usb_ep0.c:32: if (UsbSetupBuf->wLengthH || SetupLen > 0x7F)
	mov	dptr,#(_Ep0Buffer + 0x0007)
	movx	a,@dptr
	jnz	00101$
	mov	a,_SetupLen
	add	a,#0xff - 0x7f
	jnc	00102$
00101$:
;	usb_ep0.c:33: SetupLen = 0x7F;	// Limit the total length
	mov	_SetupLen,#0x7f
00102$:
;	usb_ep0.c:35: len = 0;	// Assume success -> Tx 0-length packet
	mov	r7,#0x00
;	usb_ep0.c:36: SetupReq = UsbSetupBuf->bRequest;
	mov	dptr,#(_Ep0Buffer + 0x0001)
	movx	a,@dptr
	mov	_SetupReq,a
;	usb_ep0.c:38: if ((UsbSetupBuf->bRequestType & USB_REQ_TYP_MASK) == USB_REQ_TYP_STANDARD) {
	mov	dptr,#_Ep0Buffer
	movx	a,@dptr
	mov	r6,a
	anl	a,#0x60
	jz	00294$
	ljmp	00155$
00294$:
;	usb_ep0.c:40: switch (SetupReq) {
	mov	a,_SetupReq
	add	a,#0xff - 0x0a
	jnc	00295$
	ljmp	00140$
00295$:
	mov	a,_SetupReq
	add	a,#(00296$-3-.)
	movc	a,@a+pc
	mov	dpl,a
	mov	a,_SetupReq
	add	a,#(00297$-3-.)
	movc	a,@a+pc
	mov	dph,a
	clr	a
	jmp	@a+dptr
00296$:
	.db	00136$
	.db	00125$
	.db	00140$
	.db	00129$
	.db	00140$
	.db	00119$
	.db	00104$
	.db	00140$
	.db	00120$
	.db	00123$
	.db	00159$
00297$:
	.db	00136$>>8
	.db	00125$>>8
	.db	00140$>>8
	.db	00129$>>8
	.db	00140$>>8
	.db	00119$>>8
	.db	00104$>>8
	.db	00140$>>8
	.db	00120$>>8
	.db	00123$>>8
	.db	00159$>>8
;	usb_ep0.c:41: case USB_GET_DESCRIPTOR: 
00104$:
;	usb_ep0.c:42: switch (UsbSetupBuf->wValueH) {
	mov	dptr,#(_Ep0Buffer + 0x0003)
	movx	a,@dptr
	mov	r6,a
	cjne	r6,#0x01,00298$
	sjmp	00105$
00298$:
	cjne	r6,#0x02,00299$
	sjmp	00106$
00299$:
	cjne	r6,#0x03,00300$
	sjmp	00107$
00300$:
;	usb_ep0.c:43: case 1:												// Device Descriptor
	cjne	r6,#0x22,00115$
	sjmp	00111$
00105$:
;	usb_ep0.c:44: pDescr = (uint8_t*)&DevDesc;
	mov	_pDescr,#_DevDesc
	mov	(_pDescr + 1),#(_DevDesc >> 8)
	mov	(_pDescr + 2),#0x80
;	usb_ep0.c:45: len = USB_DESCSIZE_DEVICE;
	mov	r6,#0x12
;	usb_ep0.c:46: break;
;	usb_ep0.c:47: case 2:												// Configure Descriptor
	sjmp	00116$
00106$:
;	usb_ep0.c:48: pDescr = (uint8_t*)CfgDesc;
	mov	_pDescr,#_CfgDesc
	mov	(_pDescr + 1),#(_CfgDesc >> 8)
	mov	(_pDescr + 2),#0x80
;	usb_ep0.c:49: len = (USB_DESCSIZE_CONFIG_H << 8) | USB_DESCSIZE_CONFIG_L;
	mov	r6,#0x4b
;	usb_ep0.c:50: break;
;	usb_ep0.c:51: case 3:												// String Descriptor
	sjmp	00116$
00107$:
;	usb_ep0.c:52: len = UsbSetupBuf->wValueL;	// Index
	mov	dptr,#(_Ep0Buffer + 0x0002)
	movx	a,@dptr
	mov	r5,a
;	usb_ep0.c:53: if (len < USB_STRINGDESC_COUNT) {
	cjne	r5,#0x04,00302$
00302$:
	jnc	00109$
;	usb_ep0.c:54: pDescr = (uint8_t*)(StringDescs[len]);
	mov	a,r5
	add	a,r5
	add	a,#_StringDescs
	mov	r1,a
	mov	ar4,@r1
	inc	r1
	mov	ar5,@r1
	mov	_pDescr,r4
	mov	(_pDescr + 1),r5
	mov	(_pDescr + 2),#0x80
;	usb_ep0.c:55: len = pDescr[0];
	mov	r3,_pDescr
	mov	r4,(_pDescr + 1)
	mov	r5,(_pDescr + 2)
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	lcall	__gptrget
	mov	r6,a
	sjmp	00116$
00109$:
;	usb_ep0.c:57: len = 0xFF;								// Not supported
	mov	r6,#0xff
;	usb_ep0.c:59: break;
;	usb_ep0.c:60: case 0x22:										// Report Descriptor
	sjmp	00116$
00111$:
;	usb_ep0.c:61: len = UsbSetupBuf->wIndexL;
	mov	dptr,#(_Ep0Buffer + 0x0004)
	movx	a,@dptr
	mov	r6,a
;	usb_ep0.c:62: if (len < USB_INTERFACES) {
	cjne	r6,#0x02,00304$
00304$:
	jc	00116$
;	usb_ep0.c:67: len = 0xff;		// The host is trying to config invalid interfaces
	mov	r6,#0xff
;	usb_ep0.c:69: break;
;	usb_ep0.c:70: default:
	sjmp	00116$
00115$:
;	usb_ep0.c:71: len = 0xff;		// Unsupported descriptors
	mov	r6,#0xff
;	usb_ep0.c:73: }	// switch (UsbSetupBuf->wValueH)
00116$:
;	usb_ep0.c:74: if (SetupLen > len) {
	clr	c
	mov	a,r6
	subb	a,_SetupLen
	jnc	00118$
;	usb_ep0.c:75: SetupLen = len;		// Limit length
	mov	_SetupLen,r6
00118$:
;	usb_ep0.c:77: len = SetupLen >= 8 ? 8 : SetupLen;
	mov	a,#0x100 - 0x08
	add	a,_SetupLen
	jnc	00165$
	mov	r5,#0x08
	mov	r6,#0x00
	sjmp	00166$
00165$:
	mov	r5,_SetupLen
	mov	r6,#0x00
00166$:
	mov	ar7,r5
;	usb_ep0.c:78: memcpy(Ep0Buffer, pDescr, len);
	mov	_memcpy_PARM_2,_pDescr
	mov	(_memcpy_PARM_2 + 1),(_pDescr + 1)
	mov	(_memcpy_PARM_2 + 2),(_pDescr + 2)
	mov	_memcpy_PARM_3,r7
	mov	(_memcpy_PARM_3 + 1),#0x00
	mov	dptr,#_Ep0Buffer
	mov	b,#0x00
	push	ar7
	lcall	_memcpy
	pop	ar7
;	usb_ep0.c:79: SetupLen -= len;
	mov	a,_SetupLen
	clr	c
	subb	a,r7
	mov	_SetupLen,a
;	usb_ep0.c:80: pDescr += len;
	mov	a,r7
	add	a,_pDescr
	mov	_pDescr,a
	clr	a
	addc	a,(_pDescr + 1)
	mov	(_pDescr + 1),a
;	usb_ep0.c:81: break;
	ljmp	00159$
;	usb_ep0.c:82: case USB_SET_ADDRESS:
00119$:
;	usb_ep0.c:83: SetupLen = UsbSetupBuf->wValueL;	// Save the assigned address
	mov	dptr,#(_Ep0Buffer + 0x0002)
	movx	a,@dptr
	mov	_SetupLen,a
;	usb_ep0.c:84: break;
	ljmp	00159$
;	usb_ep0.c:85: case USB_GET_CONFIGURATION:
00120$:
;	usb_ep0.c:86: Ep0Buffer[0] = UsbConfig;
	mov	dptr,#_Ep0Buffer
	mov	a,_UsbConfig
	movx	@dptr,a
;	usb_ep0.c:87: if (SetupLen >= 1)
	mov	a,#0x100 - 0x01
	add	a,_SetupLen
	jc	00308$
	ljmp	00159$
00308$:
;	usb_ep0.c:88: len = 1;
	mov	r7,#0x01
;	usb_ep0.c:89: break;
	ljmp	00159$
;	usb_ep0.c:90: case USB_SET_CONFIGURATION:
00123$:
;	usb_ep0.c:91: UsbConfig = UsbSetupBuf->wValueL;
	mov	dptr,#(_Ep0Buffer + 0x0002)
	movx	a,@dptr
	mov	_UsbConfig,a
;	usb_ep0.c:92: break;
	ljmp	00159$
;	usb_ep0.c:95: case USB_CLEAR_FEATURE:                                            //Clear Feature
00125$:
;	usb_ep0.c:96: if ((UsbSetupBuf->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_ENDP) {	// Endpoint
	mov	dptr,#_Ep0Buffer
	movx	a,@dptr
	mov	r6,a
	anl	ar6,#0x1f
	mov	r5,#0x00
	cjne	r6,#0x02,00127$
	cjne	r5,#0x00,00127$
;	usb_ep0.c:97: len = USB_EP_HALT_CLEAR(UsbSetupBuf->wIndexL);
	mov	dptr,#(_Ep0Buffer + 0x0004)
	movx	a,@dptr
	mov	dpl,a
	lcall	_USB_EP_HALT_CLEAR
	mov	r7,dpl
	ljmp	00159$
00127$:
;	usb_ep0.c:99: len = 0xFF;			// Unsupported
	mov	r7,#0xff
;	usb_ep0.c:101: break;
	ljmp	00159$
;	usb_ep0.c:102: case USB_SET_FEATURE:                                              /* Set Feature */
00129$:
;	usb_ep0.c:103: if ((UsbSetupBuf->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_ENDP) { // Endpoint
	mov	dptr,#_Ep0Buffer
	movx	a,@dptr
	mov	r6,a
	anl	ar6,#0x1f
	mov	r5,#0x00
	cjne	r6,#0x02,00134$
	cjne	r5,#0x00,00134$
;	usb_ep0.c:104: if ((((uint16_t)UsbSetupBuf->wValueH << 8) | UsbSetupBuf->wValueL) == USB_FEATURE_ENDPOINT_HALT) {
	mov	dptr,#(_Ep0Buffer + 0x0003)
	movx	a,@dptr
	mov	r5,a
	mov	r6,#0x00
	mov	dptr,#(_Ep0Buffer + 0x0002)
	movx	a,@dptr
	mov	r4,a
	mov	r3,#0x00
	orl	ar6,a
	mov	a,r3
	orl	ar5,a
	mov	a,r6
	orl	a,r5
	jnz	00131$
;	usb_ep0.c:105: len = USB_EP_HALT_SET(UsbSetupBuf->wIndexL);
	mov	dptr,#(_Ep0Buffer + 0x0004)
	movx	a,@dptr
	mov	dpl,a
	lcall	_USB_EP_HALT_SET
	mov	r7,dpl
	ljmp	00159$
00131$:
;	usb_ep0.c:107: len = 0xFF;		// Unsupported
	mov	r7,#0xff
	ljmp	00159$
00134$:
;	usb_ep0.c:110: len = 0xFF;			// Unsupported
	mov	r7,#0xff
;	usb_ep0.c:112: break;
	ljmp	00159$
;	usb_ep0.c:113: case USB_GET_STATUS:
00136$:
;	usb_ep0.c:125: Ep0Buffer[0] = 0x00;
	mov	dptr,#_Ep0Buffer
	clr	a
	movx	@dptr,a
;	usb_ep0.c:126: Ep0Buffer[1] = 0x00;
	mov	dptr,#(_Ep0Buffer + 0x0001)
	movx	@dptr,a
;	usb_ep0.c:127: if (SetupLen >= 2) {
	mov	a,#0x100 - 0x02
	add	a,_SetupLen
	jnc	00138$
;	usb_ep0.c:128: len = 2;
	mov	r7,#0x02
	ljmp	00159$
00138$:
;	usb_ep0.c:130: len = SetupLen;
	mov	r7,_SetupLen
;	usb_ep0.c:132: break;
	ljmp	00159$
;	usb_ep0.c:133: default:
00140$:
;	usb_ep0.c:134: len = 0xff;				// Unsupported
	mov	r7,#0xff
;	usb_ep0.c:136: }	// switch (SetupReq)
	ljmp	00159$
00155$:
;	usb_ep0.c:139: else if ((UsbSetupBuf->bRequestType & USB_REQ_TYP_MASK) == USB_REQ_TYP_CLASS) {
	mov	dptr,#_Ep0Buffer
	movx	a,@dptr
	mov	r6,a
	anl	ar6,#0x60
	mov	r5,#0x00
	cjne	r6,#0x20,00159$
	cjne	r5,#0x00,00159$
;	usb_ep0.c:141: if (UsbSetupBuf->bRequestType & USB_REQ_TYP_IN) {
	mov	dptr,#_Ep0Buffer
	movx	a,@dptr
	mov	r6,a
	jnb	acc.7,00150$
;	usb_ep0.c:143: switch( SetupReq ) {
	mov	a,#0x21
	cjne	a,_SetupReq,00143$
;	usb_ep0.c:149: pDescr = LineCoding;
	mov	_pDescr,#_LineCoding
	mov	(_pDescr + 1),#(_LineCoding >> 8)
	mov	(_pDescr + 2),#0x00
;	usb_ep0.c:151: len = SetupLen >= DEFAULT_ENDP0_SIZE ? DEFAULT_ENDP0_SIZE : SetupLen;  // ���δ��䳤��
	mov	a,#0x100 - 0x08
	add	a,_SetupLen
	jnc	00167$
	mov	r5,#0x08
	mov	r6,#0x00
	sjmp	00168$
00167$:
	mov	r5,_SetupLen
	mov	r6,#0x00
00168$:
	mov	ar7,r5
;	usb_ep0.c:152: memcpy(Ep0Buffer, pDescr, len);
	mov	_memcpy_PARM_2,_pDescr
	mov	(_memcpy_PARM_2 + 1),(_pDescr + 1)
	mov	(_memcpy_PARM_2 + 2),(_pDescr + 2)
	mov	_memcpy_PARM_3,r7
	mov	(_memcpy_PARM_3 + 1),#0x00
	mov	dptr,#_Ep0Buffer
	mov	b,#0x00
	push	ar7
	lcall	_memcpy
	pop	ar7
;	usb_ep0.c:153: SetupLen -= len;
	mov	a,_SetupLen
	clr	c
	subb	a,r7
	mov	_SetupLen,a
;	usb_ep0.c:154: pDescr += len;
	mov	a,r7
	add	a,_pDescr
	mov	_pDescr,a
	clr	a
	addc	a,(_pDescr + 1)
	mov	(_pDescr + 1),a
;	usb_ep0.c:155: break;
;	usb_ep0.c:156: default:
	sjmp	00159$
00143$:
;	usb_ep0.c:157: len = 0xFF;
	mov	r7,#0xff
;	usb_ep0.c:159: }
	sjmp	00159$
00150$:
;	usb_ep0.c:162: switch( SetupReq ) {
	mov	a,#0x20
	cjne	a,_SetupReq,00321$
	sjmp	00159$
00321$:
	mov	a,#0x22
	cjne	a,_SetupReq,00322$
	sjmp	00159$
00322$:
;	usb_ep0.c:174: len = 0xFF;
	mov	r7,#0xff
;	usb_ep0.c:176: }
	sjmp	00159$
00158$:
;	usb_ep0.c:182: len = 0xff;						// Wrong packet length
	mov	r7,#0xff
00159$:
;	usb_ep0.c:187: if (len == 0xff) {	// Return STALL to host if operation is not supported
	cjne	r7,#0xff,00161$
;	usb_ep0.c:188: SetupReq = 0xFF;
	mov	_SetupReq,#0xff
;	usb_ep0.c:189: UEP0_CTRL = bUEP_R_TOG | bUEP_T_TOG | UEP_R_RES_STALL | UEP_T_RES_STALL;//STALL
	mov	_UEP0_CTRL,#0xcf
	ret
00161$:
;	usb_ep0.c:191: UEP0_T_LEN = len;
	mov	_UEP0_T_LEN,r7
;	usb_ep0.c:192: UEP0_CTRL = bUEP_R_TOG | bUEP_T_TOG | UEP_R_RES_ACK | UEP_T_RES_ACK;	// Expect DATA1, Answer ACK
	mov	_UEP0_CTRL,#0xc0
;	usb_ep0.c:194: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'USB_EP0_IN'
;------------------------------------------------------------
;len                       Allocated to registers r6 
;------------------------------------------------------------
;	usb_ep0.c:197: void USB_EP0_IN(void) {
;	-----------------------------------------
;	 function USB_EP0_IN
;	-----------------------------------------
_USB_EP0_IN:
;	usb_ep0.c:199: switch (SetupReq)
	mov	a,#0x05
	cjne	a,_SetupReq,00121$
	sjmp	00102$
00121$:
	mov	a,#0x06
	cjne	a,_SetupReq,00103$
;	usb_ep0.c:202: len = SetupLen >= 8 ? 8 : SetupLen;		// Fix length
	mov	a,#0x100 - 0x08
	add	a,_SetupLen
	jnc	00107$
	mov	r6,#0x08
	mov	r7,#0x00
	sjmp	00108$
00107$:
	mov	r6,_SetupLen
	mov	r7,#0x00
00108$:
;	usb_ep0.c:203: memcpy(Ep0Buffer, pDescr, len);			// Copy data to Ep0Buffer, ready to Tx
	mov	_memcpy_PARM_2,_pDescr
	mov	(_memcpy_PARM_2 + 1),(_pDescr + 1)
	mov	(_memcpy_PARM_2 + 2),(_pDescr + 2)
	mov	_memcpy_PARM_3,r6
	mov	(_memcpy_PARM_3 + 1),#0x00
	mov	dptr,#_Ep0Buffer
	mov	b,#0x00
	push	ar6
	lcall	_memcpy
	pop	ar6
;	usb_ep0.c:204: SetupLen -= len;
	mov	a,_SetupLen
	clr	c
	subb	a,r6
	mov	_SetupLen,a
;	usb_ep0.c:205: pDescr += len;
	mov	a,r6
	add	a,_pDescr
	mov	_pDescr,a
	clr	a
	addc	a,(_pDescr + 1)
	mov	(_pDescr + 1),a
;	usb_ep0.c:206: UEP0_T_LEN = len;
	mov	_UEP0_T_LEN,r6
;	usb_ep0.c:207: UEP0_CTRL ^= bUEP_T_TOG;				// Switch between DATA0 and DATA1
	mov	r6,_UEP0_CTRL
	xrl	ar6,#0x40
	mov	_UEP0_CTRL,r6
;	usb_ep0.c:208: break;
;	usb_ep0.c:209: case USB_SET_ADDRESS:
	ret
00102$:
;	usb_ep0.c:210: USB_DEV_AD = bUDA_GP_BIT | SetupLen;
	mov	r6,_SetupLen
	orl	ar6,#0x80
	mov	_USB_DEV_AD,r6
;	usb_ep0.c:211: UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
	mov	_UEP0_CTRL,#0x02
;	usb_ep0.c:212: break;
;	usb_ep0.c:213: default:
	ret
00103$:
;	usb_ep0.c:214: UEP0_T_LEN = 0;							// End of transaction
	mov	_UEP0_T_LEN,#0x00
;	usb_ep0.c:215: UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
	mov	_UEP0_CTRL,#0x02
;	usb_ep0.c:217: }
;	usb_ep0.c:218: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'USB_EP0_OUT'
;------------------------------------------------------------
;len                       Allocated to registers 
;------------------------------------------------------------
;	usb_ep0.c:221: void USB_EP0_OUT(void) {
;	-----------------------------------------
;	 function USB_EP0_OUT
;	-----------------------------------------
_USB_EP0_OUT:
;	usb_ep0.c:222: uint8_t len = USB_RX_LEN;
	mov	a,_USB_RX_LEN
;	usb_ep0.c:223: if (SetupReq == SET_LINE_CODING) {
	mov	a,#0x20
	cjne	a,_SetupReq,00105$
;	usb_ep0.c:224: if( U_TOG_OK ) {
	jnb	_U_TOG_OK,00105$
;	usb_ep0.c:225: memcpy(LineCoding,UsbSetupBuf,USB_RX_LEN);
	mov	_memcpy_PARM_2,#_Ep0Buffer
	mov	(_memcpy_PARM_2 + 1),#(_Ep0Buffer >> 8)
	mov	(_memcpy_PARM_2 + 2),#0x00
	mov	_memcpy_PARM_3,_USB_RX_LEN
	mov	(_memcpy_PARM_3 + 1),#0x00
	mov	dptr,#_LineCoding
	mov	b,#0x00
	lcall	_memcpy
;	usb_ep0.c:226: CDC_SetBaud();
	lcall	_CDC_SetBaud
;	usb_ep0.c:228: UEP0_T_LEN = 0;
	mov	_UEP0_T_LEN,#0x00
;	usb_ep0.c:229: UEP0_CTRL |= UEP_R_RES_ACK | UEP_T_RES_ACK;  // ׼���ϴ�0��
	mov	_UEP0_CTRL,_UEP0_CTRL
;	usb_ep0.c:232: else if(SetupReq == SET_CONTROL_LINE_STATE){
00105$:
;	usb_ep0.c:254: UEP0_CTRL ^= bUEP_R_TOG;	// Switch between DATA0 and DATA1	
	mov	r6,_UEP0_CTRL
	xrl	ar6,#0x80
	mov	_UEP0_CTRL,r6
;	usb_ep0.c:255: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
