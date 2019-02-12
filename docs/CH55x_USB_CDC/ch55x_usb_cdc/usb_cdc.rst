                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module usb_cdc
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _CDC_PutChar
                                     12 	.globl _JumpToBootloader
                                     13 	.globl _memcpy
                                     14 	.globl _CH554UART0SendByte
                                     15 	.globl _rstPin
                                     16 	.globl _bootPin
                                     17 	.globl _UIF_BUS_RST
                                     18 	.globl _UIF_DETECT
                                     19 	.globl _UIF_TRANSFER
                                     20 	.globl _UIF_SUSPEND
                                     21 	.globl _UIF_HST_SOF
                                     22 	.globl _UIF_FIFO_OV
                                     23 	.globl _U_SIE_FREE
                                     24 	.globl _U_TOG_OK
                                     25 	.globl _U_IS_NAK
                                     26 	.globl _ADC_CHAN0
                                     27 	.globl _ADC_CHAN1
                                     28 	.globl _CMP_CHAN
                                     29 	.globl _ADC_START
                                     30 	.globl _ADC_IF
                                     31 	.globl _CMP_IF
                                     32 	.globl _CMPO
                                     33 	.globl _U1RI
                                     34 	.globl _U1TI
                                     35 	.globl _U1RB8
                                     36 	.globl _U1TB8
                                     37 	.globl _U1REN
                                     38 	.globl _U1SMOD
                                     39 	.globl _U1SM0
                                     40 	.globl _S0_R_FIFO
                                     41 	.globl _S0_T_FIFO
                                     42 	.globl _S0_FREE
                                     43 	.globl _S0_IF_BYTE
                                     44 	.globl _S0_IF_FIRST
                                     45 	.globl _S0_IF_OV
                                     46 	.globl _S0_FST_ACT
                                     47 	.globl _CP_RL2
                                     48 	.globl _C_T2
                                     49 	.globl _TR2
                                     50 	.globl _EXEN2
                                     51 	.globl _TCLK
                                     52 	.globl _RCLK
                                     53 	.globl _EXF2
                                     54 	.globl _CAP1F
                                     55 	.globl _TF2
                                     56 	.globl _RI
                                     57 	.globl _TI
                                     58 	.globl _RB8
                                     59 	.globl _TB8
                                     60 	.globl _REN
                                     61 	.globl _SM2
                                     62 	.globl _SM1
                                     63 	.globl _SM0
                                     64 	.globl _IT0
                                     65 	.globl _IE0
                                     66 	.globl _IT1
                                     67 	.globl _IE1
                                     68 	.globl _TR0
                                     69 	.globl _TF0
                                     70 	.globl _TR1
                                     71 	.globl _TF1
                                     72 	.globl _RXD
                                     73 	.globl _PWM1_
                                     74 	.globl _TXD
                                     75 	.globl _PWM2_
                                     76 	.globl _AIN3
                                     77 	.globl _VBUS1
                                     78 	.globl _INT0
                                     79 	.globl _TXD1_
                                     80 	.globl _INT1
                                     81 	.globl _T0
                                     82 	.globl _RXD1_
                                     83 	.globl _PWM2
                                     84 	.globl _T1
                                     85 	.globl _UDP
                                     86 	.globl _UDM
                                     87 	.globl _TIN0
                                     88 	.globl _CAP1
                                     89 	.globl _T2
                                     90 	.globl _AIN0
                                     91 	.globl _VBUS2
                                     92 	.globl _TIN1
                                     93 	.globl _CAP2
                                     94 	.globl _T2EX
                                     95 	.globl _RXD_
                                     96 	.globl _TXD_
                                     97 	.globl _AIN1
                                     98 	.globl _UCC1
                                     99 	.globl _TIN2
                                    100 	.globl _SCS
                                    101 	.globl _CAP1_
                                    102 	.globl _T2_
                                    103 	.globl _AIN2
                                    104 	.globl _UCC2
                                    105 	.globl _TIN3
                                    106 	.globl _PWM1
                                    107 	.globl _MOSI
                                    108 	.globl _TIN4
                                    109 	.globl _RXD1
                                    110 	.globl _MISO
                                    111 	.globl _TIN5
                                    112 	.globl _TXD1
                                    113 	.globl _SCK
                                    114 	.globl _IE_SPI0
                                    115 	.globl _IE_TKEY
                                    116 	.globl _IE_USB
                                    117 	.globl _IE_ADC
                                    118 	.globl _IE_UART1
                                    119 	.globl _IE_PWMX
                                    120 	.globl _IE_GPIO
                                    121 	.globl _IE_WDOG
                                    122 	.globl _PX0
                                    123 	.globl _PT0
                                    124 	.globl _PX1
                                    125 	.globl _PT1
                                    126 	.globl _PS
                                    127 	.globl _PT2
                                    128 	.globl _PL_FLAG
                                    129 	.globl _PH_FLAG
                                    130 	.globl _EX0
                                    131 	.globl _ET0
                                    132 	.globl _EX1
                                    133 	.globl _ET1
                                    134 	.globl _ES
                                    135 	.globl _ET2
                                    136 	.globl _E_DIS
                                    137 	.globl _EA
                                    138 	.globl _P
                                    139 	.globl _F1
                                    140 	.globl _OV
                                    141 	.globl _RS0
                                    142 	.globl _RS1
                                    143 	.globl _F0
                                    144 	.globl _AC
                                    145 	.globl _CY
                                    146 	.globl _UEP1_DMA_H
                                    147 	.globl _UEP1_DMA_L
                                    148 	.globl _UEP1_DMA
                                    149 	.globl _UEP0_DMA_H
                                    150 	.globl _UEP0_DMA_L
                                    151 	.globl _UEP0_DMA
                                    152 	.globl _UEP2_3_MOD
                                    153 	.globl _UEP4_1_MOD
                                    154 	.globl _UEP3_DMA_H
                                    155 	.globl _UEP3_DMA_L
                                    156 	.globl _UEP3_DMA
                                    157 	.globl _UEP2_DMA_H
                                    158 	.globl _UEP2_DMA_L
                                    159 	.globl _UEP2_DMA
                                    160 	.globl _USB_DEV_AD
                                    161 	.globl _USB_CTRL
                                    162 	.globl _USB_INT_EN
                                    163 	.globl _UEP4_T_LEN
                                    164 	.globl _UEP4_CTRL
                                    165 	.globl _UEP0_T_LEN
                                    166 	.globl _UEP0_CTRL
                                    167 	.globl _USB_RX_LEN
                                    168 	.globl _USB_MIS_ST
                                    169 	.globl _USB_INT_ST
                                    170 	.globl _USB_INT_FG
                                    171 	.globl _UEP3_T_LEN
                                    172 	.globl _UEP3_CTRL
                                    173 	.globl _UEP2_T_LEN
                                    174 	.globl _UEP2_CTRL
                                    175 	.globl _UEP1_T_LEN
                                    176 	.globl _UEP1_CTRL
                                    177 	.globl _UDEV_CTRL
                                    178 	.globl _USB_C_CTRL
                                    179 	.globl _TKEY_DATH
                                    180 	.globl _TKEY_DATL
                                    181 	.globl _TKEY_DAT
                                    182 	.globl _TKEY_CTRL
                                    183 	.globl _ADC_DATA
                                    184 	.globl _ADC_CFG
                                    185 	.globl _ADC_CTRL
                                    186 	.globl _SBAUD1
                                    187 	.globl _SBUF1
                                    188 	.globl _SCON1
                                    189 	.globl _SPI0_SETUP
                                    190 	.globl _SPI0_CK_SE
                                    191 	.globl _SPI0_CTRL
                                    192 	.globl _SPI0_DATA
                                    193 	.globl _SPI0_STAT
                                    194 	.globl _PWM_CK_SE
                                    195 	.globl _PWM_CTRL
                                    196 	.globl _PWM_DATA1
                                    197 	.globl _PWM_DATA2
                                    198 	.globl _T2CAP1H
                                    199 	.globl _T2CAP1L
                                    200 	.globl _T2CAP1
                                    201 	.globl _TH2
                                    202 	.globl _TL2
                                    203 	.globl _T2COUNT
                                    204 	.globl _RCAP2H
                                    205 	.globl _RCAP2L
                                    206 	.globl _RCAP2
                                    207 	.globl _T2MOD
                                    208 	.globl _T2CON
                                    209 	.globl _SBUF
                                    210 	.globl _SCON
                                    211 	.globl _TH1
                                    212 	.globl _TH0
                                    213 	.globl _TL1
                                    214 	.globl _TL0
                                    215 	.globl _TMOD
                                    216 	.globl _TCON
                                    217 	.globl _XBUS_AUX
                                    218 	.globl _PIN_FUNC
                                    219 	.globl _P3_DIR_PU
                                    220 	.globl _P3_MOD_OC
                                    221 	.globl _P3
                                    222 	.globl _P2
                                    223 	.globl _P1_DIR_PU
                                    224 	.globl _P1_MOD_OC
                                    225 	.globl _P1
                                    226 	.globl _ROM_CTRL
                                    227 	.globl _ROM_DATA_H
                                    228 	.globl _ROM_DATA_L
                                    229 	.globl _ROM_DATA
                                    230 	.globl _ROM_ADDR_H
                                    231 	.globl _ROM_ADDR_L
                                    232 	.globl _ROM_ADDR
                                    233 	.globl _GPIO_IE
                                    234 	.globl _IP_EX
                                    235 	.globl _IE_EX
                                    236 	.globl _IP
                                    237 	.globl _IE
                                    238 	.globl _WDOG_COUNT
                                    239 	.globl _RESET_KEEP
                                    240 	.globl _WAKE_CTRL
                                    241 	.globl _CLOCK_CFG
                                    242 	.globl _PCON
                                    243 	.globl _GLOBAL_CFG
                                    244 	.globl _SAFE_MOD
                                    245 	.globl _DPH
                                    246 	.globl _DPL
                                    247 	.globl _SP
                                    248 	.globl _B
                                    249 	.globl _ACC
                                    250 	.globl _PSW
                                    251 	.globl _LineCoding
                                    252 	.globl _CDC_Rx_CurPos
                                    253 	.globl _CDC_Rx_Pending
                                    254 	.globl _CDC_Tx_Full
                                    255 	.globl _CDC_Tx_Busy
                                    256 	.globl _CDC_PutCharBuf_First
                                    257 	.globl _CDC_PutCharBuf_Last
                                    258 	.globl _CDC_PutCharBuf
                                    259 	.globl _countESP32Endl
                                    260 	.globl _rebootESP32
                                    261 	.globl _resetToBoot
                                    262 	.globl _espBootCount
                                    263 	.globl _CDC_Baud
                                    264 	.globl _CDC_InitBaud
                                    265 	.globl _CDC_SetBaud
                                    266 	.globl _USB_EP1_IN
                                    267 	.globl _USB_EP2_IN
                                    268 	.globl _USB_EP2_OUT
                                    269 	.globl _CDC_Puts
                                    270 	.globl _CDC_USB_Poll
                                    271 	.globl _CDC_UART_Poll
                                    272 ;--------------------------------------------------------
                                    273 ; special function registers
                                    274 ;--------------------------------------------------------
                                    275 	.area RSEG    (ABS,DATA)
      000000                        276 	.org 0x0000
                           0000D0   277 _PSW	=	0x00d0
                           0000E0   278 _ACC	=	0x00e0
                           0000F0   279 _B	=	0x00f0
                           000081   280 _SP	=	0x0081
                           000082   281 _DPL	=	0x0082
                           000083   282 _DPH	=	0x0083
                           0000A1   283 _SAFE_MOD	=	0x00a1
                           0000B1   284 _GLOBAL_CFG	=	0x00b1
                           000087   285 _PCON	=	0x0087
                           0000B9   286 _CLOCK_CFG	=	0x00b9
                           0000A9   287 _WAKE_CTRL	=	0x00a9
                           0000FE   288 _RESET_KEEP	=	0x00fe
                           0000FF   289 _WDOG_COUNT	=	0x00ff
                           0000A8   290 _IE	=	0x00a8
                           0000B8   291 _IP	=	0x00b8
                           0000E8   292 _IE_EX	=	0x00e8
                           0000E9   293 _IP_EX	=	0x00e9
                           0000C7   294 _GPIO_IE	=	0x00c7
                           008584   295 _ROM_ADDR	=	0x8584
                           000084   296 _ROM_ADDR_L	=	0x0084
                           000085   297 _ROM_ADDR_H	=	0x0085
                           008F8E   298 _ROM_DATA	=	0x8f8e
                           00008E   299 _ROM_DATA_L	=	0x008e
                           00008F   300 _ROM_DATA_H	=	0x008f
                           000086   301 _ROM_CTRL	=	0x0086
                           000090   302 _P1	=	0x0090
                           000092   303 _P1_MOD_OC	=	0x0092
                           000093   304 _P1_DIR_PU	=	0x0093
                           0000A0   305 _P2	=	0x00a0
                           0000B0   306 _P3	=	0x00b0
                           000096   307 _P3_MOD_OC	=	0x0096
                           000097   308 _P3_DIR_PU	=	0x0097
                           0000C6   309 _PIN_FUNC	=	0x00c6
                           0000A2   310 _XBUS_AUX	=	0x00a2
                           000088   311 _TCON	=	0x0088
                           000089   312 _TMOD	=	0x0089
                           00008A   313 _TL0	=	0x008a
                           00008B   314 _TL1	=	0x008b
                           00008C   315 _TH0	=	0x008c
                           00008D   316 _TH1	=	0x008d
                           000098   317 _SCON	=	0x0098
                           000099   318 _SBUF	=	0x0099
                           0000C8   319 _T2CON	=	0x00c8
                           0000C9   320 _T2MOD	=	0x00c9
                           00CBCA   321 _RCAP2	=	0xcbca
                           0000CA   322 _RCAP2L	=	0x00ca
                           0000CB   323 _RCAP2H	=	0x00cb
                           00CDCC   324 _T2COUNT	=	0xcdcc
                           0000CC   325 _TL2	=	0x00cc
                           0000CD   326 _TH2	=	0x00cd
                           00CFCE   327 _T2CAP1	=	0xcfce
                           0000CE   328 _T2CAP1L	=	0x00ce
                           0000CF   329 _T2CAP1H	=	0x00cf
                           00009B   330 _PWM_DATA2	=	0x009b
                           00009C   331 _PWM_DATA1	=	0x009c
                           00009D   332 _PWM_CTRL	=	0x009d
                           00009E   333 _PWM_CK_SE	=	0x009e
                           0000F8   334 _SPI0_STAT	=	0x00f8
                           0000F9   335 _SPI0_DATA	=	0x00f9
                           0000FA   336 _SPI0_CTRL	=	0x00fa
                           0000FB   337 _SPI0_CK_SE	=	0x00fb
                           0000FC   338 _SPI0_SETUP	=	0x00fc
                           0000C0   339 _SCON1	=	0x00c0
                           0000C1   340 _SBUF1	=	0x00c1
                           0000C2   341 _SBAUD1	=	0x00c2
                           000080   342 _ADC_CTRL	=	0x0080
                           00009A   343 _ADC_CFG	=	0x009a
                           00009F   344 _ADC_DATA	=	0x009f
                           0000C3   345 _TKEY_CTRL	=	0x00c3
                           00C5C4   346 _TKEY_DAT	=	0xc5c4
                           0000C4   347 _TKEY_DATL	=	0x00c4
                           0000C5   348 _TKEY_DATH	=	0x00c5
                           000091   349 _USB_C_CTRL	=	0x0091
                           0000D1   350 _UDEV_CTRL	=	0x00d1
                           0000D2   351 _UEP1_CTRL	=	0x00d2
                           0000D3   352 _UEP1_T_LEN	=	0x00d3
                           0000D4   353 _UEP2_CTRL	=	0x00d4
                           0000D5   354 _UEP2_T_LEN	=	0x00d5
                           0000D6   355 _UEP3_CTRL	=	0x00d6
                           0000D7   356 _UEP3_T_LEN	=	0x00d7
                           0000D8   357 _USB_INT_FG	=	0x00d8
                           0000D9   358 _USB_INT_ST	=	0x00d9
                           0000DA   359 _USB_MIS_ST	=	0x00da
                           0000DB   360 _USB_RX_LEN	=	0x00db
                           0000DC   361 _UEP0_CTRL	=	0x00dc
                           0000DD   362 _UEP0_T_LEN	=	0x00dd
                           0000DE   363 _UEP4_CTRL	=	0x00de
                           0000DF   364 _UEP4_T_LEN	=	0x00df
                           0000E1   365 _USB_INT_EN	=	0x00e1
                           0000E2   366 _USB_CTRL	=	0x00e2
                           0000E3   367 _USB_DEV_AD	=	0x00e3
                           00E5E4   368 _UEP2_DMA	=	0xe5e4
                           0000E4   369 _UEP2_DMA_L	=	0x00e4
                           0000E5   370 _UEP2_DMA_H	=	0x00e5
                           00E7E6   371 _UEP3_DMA	=	0xe7e6
                           0000E6   372 _UEP3_DMA_L	=	0x00e6
                           0000E7   373 _UEP3_DMA_H	=	0x00e7
                           0000EA   374 _UEP4_1_MOD	=	0x00ea
                           0000EB   375 _UEP2_3_MOD	=	0x00eb
                           00EDEC   376 _UEP0_DMA	=	0xedec
                           0000EC   377 _UEP0_DMA_L	=	0x00ec
                           0000ED   378 _UEP0_DMA_H	=	0x00ed
                           00EFEE   379 _UEP1_DMA	=	0xefee
                           0000EE   380 _UEP1_DMA_L	=	0x00ee
                           0000EF   381 _UEP1_DMA_H	=	0x00ef
                                    382 ;--------------------------------------------------------
                                    383 ; special function bits
                                    384 ;--------------------------------------------------------
                                    385 	.area RSEG    (ABS,DATA)
      000000                        386 	.org 0x0000
                           0000D7   387 _CY	=	0x00d7
                           0000D6   388 _AC	=	0x00d6
                           0000D5   389 _F0	=	0x00d5
                           0000D4   390 _RS1	=	0x00d4
                           0000D3   391 _RS0	=	0x00d3
                           0000D2   392 _OV	=	0x00d2
                           0000D1   393 _F1	=	0x00d1
                           0000D0   394 _P	=	0x00d0
                           0000AF   395 _EA	=	0x00af
                           0000AE   396 _E_DIS	=	0x00ae
                           0000AD   397 _ET2	=	0x00ad
                           0000AC   398 _ES	=	0x00ac
                           0000AB   399 _ET1	=	0x00ab
                           0000AA   400 _EX1	=	0x00aa
                           0000A9   401 _ET0	=	0x00a9
                           0000A8   402 _EX0	=	0x00a8
                           0000BF   403 _PH_FLAG	=	0x00bf
                           0000BE   404 _PL_FLAG	=	0x00be
                           0000BD   405 _PT2	=	0x00bd
                           0000BC   406 _PS	=	0x00bc
                           0000BB   407 _PT1	=	0x00bb
                           0000BA   408 _PX1	=	0x00ba
                           0000B9   409 _PT0	=	0x00b9
                           0000B8   410 _PX0	=	0x00b8
                           0000EF   411 _IE_WDOG	=	0x00ef
                           0000EE   412 _IE_GPIO	=	0x00ee
                           0000ED   413 _IE_PWMX	=	0x00ed
                           0000EC   414 _IE_UART1	=	0x00ec
                           0000EB   415 _IE_ADC	=	0x00eb
                           0000EA   416 _IE_USB	=	0x00ea
                           0000E9   417 _IE_TKEY	=	0x00e9
                           0000E8   418 _IE_SPI0	=	0x00e8
                           000097   419 _SCK	=	0x0097
                           000097   420 _TXD1	=	0x0097
                           000097   421 _TIN5	=	0x0097
                           000096   422 _MISO	=	0x0096
                           000096   423 _RXD1	=	0x0096
                           000096   424 _TIN4	=	0x0096
                           000095   425 _MOSI	=	0x0095
                           000095   426 _PWM1	=	0x0095
                           000095   427 _TIN3	=	0x0095
                           000095   428 _UCC2	=	0x0095
                           000095   429 _AIN2	=	0x0095
                           000094   430 _T2_	=	0x0094
                           000094   431 _CAP1_	=	0x0094
                           000094   432 _SCS	=	0x0094
                           000094   433 _TIN2	=	0x0094
                           000094   434 _UCC1	=	0x0094
                           000094   435 _AIN1	=	0x0094
                           000093   436 _TXD_	=	0x0093
                           000092   437 _RXD_	=	0x0092
                           000091   438 _T2EX	=	0x0091
                           000091   439 _CAP2	=	0x0091
                           000091   440 _TIN1	=	0x0091
                           000091   441 _VBUS2	=	0x0091
                           000091   442 _AIN0	=	0x0091
                           000090   443 _T2	=	0x0090
                           000090   444 _CAP1	=	0x0090
                           000090   445 _TIN0	=	0x0090
                           0000B7   446 _UDM	=	0x00b7
                           0000B6   447 _UDP	=	0x00b6
                           0000B5   448 _T1	=	0x00b5
                           0000B4   449 _PWM2	=	0x00b4
                           0000B4   450 _RXD1_	=	0x00b4
                           0000B4   451 _T0	=	0x00b4
                           0000B3   452 _INT1	=	0x00b3
                           0000B2   453 _TXD1_	=	0x00b2
                           0000B2   454 _INT0	=	0x00b2
                           0000B2   455 _VBUS1	=	0x00b2
                           0000B2   456 _AIN3	=	0x00b2
                           0000B1   457 _PWM2_	=	0x00b1
                           0000B1   458 _TXD	=	0x00b1
                           0000B0   459 _PWM1_	=	0x00b0
                           0000B0   460 _RXD	=	0x00b0
                           00008F   461 _TF1	=	0x008f
                           00008E   462 _TR1	=	0x008e
                           00008D   463 _TF0	=	0x008d
                           00008C   464 _TR0	=	0x008c
                           00008B   465 _IE1	=	0x008b
                           00008A   466 _IT1	=	0x008a
                           000089   467 _IE0	=	0x0089
                           000088   468 _IT0	=	0x0088
                           00009F   469 _SM0	=	0x009f
                           00009E   470 _SM1	=	0x009e
                           00009D   471 _SM2	=	0x009d
                           00009C   472 _REN	=	0x009c
                           00009B   473 _TB8	=	0x009b
                           00009A   474 _RB8	=	0x009a
                           000099   475 _TI	=	0x0099
                           000098   476 _RI	=	0x0098
                           0000CF   477 _TF2	=	0x00cf
                           0000CF   478 _CAP1F	=	0x00cf
                           0000CE   479 _EXF2	=	0x00ce
                           0000CD   480 _RCLK	=	0x00cd
                           0000CC   481 _TCLK	=	0x00cc
                           0000CB   482 _EXEN2	=	0x00cb
                           0000CA   483 _TR2	=	0x00ca
                           0000C9   484 _C_T2	=	0x00c9
                           0000C8   485 _CP_RL2	=	0x00c8
                           0000FF   486 _S0_FST_ACT	=	0x00ff
                           0000FE   487 _S0_IF_OV	=	0x00fe
                           0000FD   488 _S0_IF_FIRST	=	0x00fd
                           0000FC   489 _S0_IF_BYTE	=	0x00fc
                           0000FB   490 _S0_FREE	=	0x00fb
                           0000FA   491 _S0_T_FIFO	=	0x00fa
                           0000F8   492 _S0_R_FIFO	=	0x00f8
                           0000C7   493 _U1SM0	=	0x00c7
                           0000C5   494 _U1SMOD	=	0x00c5
                           0000C4   495 _U1REN	=	0x00c4
                           0000C3   496 _U1TB8	=	0x00c3
                           0000C2   497 _U1RB8	=	0x00c2
                           0000C1   498 _U1TI	=	0x00c1
                           0000C0   499 _U1RI	=	0x00c0
                           000087   500 _CMPO	=	0x0087
                           000086   501 _CMP_IF	=	0x0086
                           000085   502 _ADC_IF	=	0x0085
                           000084   503 _ADC_START	=	0x0084
                           000083   504 _CMP_CHAN	=	0x0083
                           000081   505 _ADC_CHAN1	=	0x0081
                           000080   506 _ADC_CHAN0	=	0x0080
                           0000DF   507 _U_IS_NAK	=	0x00df
                           0000DE   508 _U_TOG_OK	=	0x00de
                           0000DD   509 _U_SIE_FREE	=	0x00dd
                           0000DC   510 _UIF_FIFO_OV	=	0x00dc
                           0000DB   511 _UIF_HST_SOF	=	0x00db
                           0000DA   512 _UIF_SUSPEND	=	0x00da
                           0000D9   513 _UIF_TRANSFER	=	0x00d9
                           0000D8   514 _UIF_DETECT	=	0x00d8
                           0000D8   515 _UIF_BUS_RST	=	0x00d8
                           000097   516 _bootPin	=	0x0097
                           000090   517 _rstPin	=	0x0090
                                    518 ;--------------------------------------------------------
                                    519 ; overlayable register banks
                                    520 ;--------------------------------------------------------
                                    521 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        522 	.ds 8
                                    523 ;--------------------------------------------------------
                                    524 ; internal ram data
                                    525 ;--------------------------------------------------------
                                    526 	.area DSEG    (DATA)
      000021                        527 _CDC_Baud::
      000021                        528 	.ds 4
      000025                        529 _CDC_SetBaud_x_65537_44:
      000025                        530 	.ds 4
      000029                        531 _CDC_SetBaud_x2_65537_44:
      000029                        532 	.ds 1
      00002A                        533 _CDC_USB_Poll_usb_frame_count_65536_59:
      00002A                        534 	.ds 1
      00002B                        535 _jumptoBoot:
      00002B                        536 	.ds 1
      00002C                        537 _resetESP32:
      00002C                        538 	.ds 1
      00002D                        539 _printIO:
      00002D                        540 	.ds 1
      00002E                        541 _espBootCount::
      00002E                        542 	.ds 1
      00002F                        543 _resetToBoot::
      00002F                        544 	.ds 1
      000030                        545 _rebootESP32::
      000030                        546 	.ds 1
      000031                        547 _countESP32Endl::
      000031                        548 	.ds 1
      000032                        549 _esp32EndlFlash:
      000032                        550 	.ds 12
      00003E                        551 _CDC_UART_Poll_former_data_65536_69:
      00003E                        552 	.ds 1
      00003F                        553 _CDC_UART_Poll_cdc_rx_state_65536_69:
      00003F                        554 	.ds 1
      000040                        555 _CDC_UART_Poll_dontstop_65536_69:
      000040                        556 	.ds 1
      000041                        557 _CDC_UART_Poll_frame_len_65536_69:
      000041                        558 	.ds 1
      000042                        559 _CDC_UART_Poll_frame_sent_65536_69:
      000042                        560 	.ds 1
      000043                        561 _CDC_UART_Poll_i2c_error_no_65536_69:
      000043                        562 	.ds 1
                                    563 ;--------------------------------------------------------
                                    564 ; overlayable items in internal ram 
                                    565 ;--------------------------------------------------------
                                    566 ;--------------------------------------------------------
                                    567 ; indirectly addressable internal ram data
                                    568 ;--------------------------------------------------------
                                    569 	.area ISEG    (DATA)
      000077                        570 _CDC_PutCharBuf::
      000077                        571 	.ds 64
      0000B7                        572 _CDC_PutCharBuf_Last::
      0000B7                        573 	.ds 1
      0000B8                        574 _CDC_PutCharBuf_First::
      0000B8                        575 	.ds 1
      0000B9                        576 _CDC_Tx_Busy::
      0000B9                        577 	.ds 1
      0000BA                        578 _CDC_Tx_Full::
      0000BA                        579 	.ds 1
      0000BB                        580 _CDC_Rx_Pending::
      0000BB                        581 	.ds 1
      0000BC                        582 _CDC_Rx_CurPos::
      0000BC                        583 	.ds 1
                                    584 ;--------------------------------------------------------
                                    585 ; absolute internal ram data
                                    586 ;--------------------------------------------------------
                                    587 	.area IABS    (ABS,DATA)
                                    588 	.area IABS    (ABS,DATA)
                                    589 ;--------------------------------------------------------
                                    590 ; bit data
                                    591 ;--------------------------------------------------------
                                    592 	.area BSEG    (BIT)
                                    593 ;--------------------------------------------------------
                                    594 ; paged external ram data
                                    595 ;--------------------------------------------------------
                                    596 	.area PSEG    (PAG,XDATA)
                                    597 ;--------------------------------------------------------
                                    598 ; external ram data
                                    599 ;--------------------------------------------------------
                                    600 	.area XSEG    (XDATA)
                           0000CA   601 _LineCoding	=	0x00ca
                                    602 ;--------------------------------------------------------
                                    603 ; absolute external ram data
                                    604 ;--------------------------------------------------------
                                    605 	.area XABS    (ABS,XDATA)
                                    606 ;--------------------------------------------------------
                                    607 ; external initialized ram data
                                    608 ;--------------------------------------------------------
                                    609 	.area XISEG   (XDATA)
                                    610 	.area HOME    (CODE)
                                    611 	.area GSINIT0 (CODE)
                                    612 	.area GSINIT1 (CODE)
                                    613 	.area GSINIT2 (CODE)
                                    614 	.area GSINIT3 (CODE)
                                    615 	.area GSINIT4 (CODE)
                                    616 	.area GSINIT5 (CODE)
                                    617 	.area GSINIT  (CODE)
                                    618 	.area GSFINAL (CODE)
                                    619 	.area CSEG    (CODE)
                                    620 ;--------------------------------------------------------
                                    621 ; global & static initialisations
                                    622 ;--------------------------------------------------------
                                    623 	.area HOME    (CODE)
                                    624 	.area GSINIT  (CODE)
                                    625 	.area GSFINAL (CODE)
                                    626 	.area GSINIT  (CODE)
                                    627 ;------------------------------------------------------------
                                    628 ;Allocation info for local variables in function 'CDC_USB_Poll'
                                    629 ;------------------------------------------------------------
                                    630 ;usb_frame_count           Allocated with name '_CDC_USB_Poll_usb_frame_count_65536_59'
                                    631 ;usb_tx_len                Allocated to registers r7 
                                    632 ;------------------------------------------------------------
                                    633 ;	usb_cdc.c:113: static uint8_t usb_frame_count = 0;
      0000B1 75 2A 00         [24]  634 	mov	_CDC_USB_Poll_usb_frame_count_65536_59,#0x00
                                    635 ;------------------------------------------------------------
                                    636 ;Allocation info for local variables in function 'CDC_UART_Poll'
                                    637 ;------------------------------------------------------------
                                    638 ;former_data               Allocated with name '_CDC_UART_Poll_former_data_65536_69'
                                    639 ;cdc_rx_state              Allocated with name '_CDC_UART_Poll_cdc_rx_state_65536_69'
                                    640 ;dontstop                  Allocated with name '_CDC_UART_Poll_dontstop_65536_69'
                                    641 ;frame_len                 Allocated with name '_CDC_UART_Poll_frame_len_65536_69'
                                    642 ;frame_sent                Allocated with name '_CDC_UART_Poll_frame_sent_65536_69'
                                    643 ;i2c_error_no              Allocated with name '_CDC_UART_Poll_i2c_error_no_65536_69'
                                    644 ;cur_byte                  Allocated to registers r7 
                                    645 ;------------------------------------------------------------
                                    646 ;	usb_cdc.c:194: static uint8_t former_data = 0;		// Previous byte
      0000B4 75 3E 00         [24]  647 	mov	_CDC_UART_Poll_former_data_65536_69,#0x00
                                    648 ;	usb_cdc.c:195: static uint8_t cdc_rx_state = 0;	// Rx processing state machine
      0000B7 75 3F 00         [24]  649 	mov	_CDC_UART_Poll_cdc_rx_state_65536_69,#0x00
                                    650 ;	usb_cdc.c:207: static uint8_t dontstop = 0;
      0000BA 75 40 00         [24]  651 	mov	_CDC_UART_Poll_dontstop_65536_69,#0x00
                                    652 ;	usb_cdc.c:208: static uint8_t frame_len = 0;
      0000BD 75 41 00         [24]  653 	mov	_CDC_UART_Poll_frame_len_65536_69,#0x00
                                    654 ;	usb_cdc.c:211: static uint8_t frame_sent = 0;
      0000C0 75 42 00         [24]  655 	mov	_CDC_UART_Poll_frame_sent_65536_69,#0x00
                                    656 ;	usb_cdc.c:214: static uint8_t i2c_error_no = 0;
      0000C3 75 43 00         [24]  657 	mov	_CDC_UART_Poll_i2c_error_no_65536_69,#0x00
                                    658 ;	usb_cdc.c:182: static uint8_t jumptoBoot = 0;
      0000C6 75 2B 00         [24]  659 	mov	_jumptoBoot,#0x00
                                    660 ;	usb_cdc.c:183: static uint8_t resetESP32 = 0;
      0000C9 75 2C 00         [24]  661 	mov	_resetESP32,#0x00
                                    662 ;	usb_cdc.c:184: static uint8_t printIO = 0;
      0000CC 75 2D 00         [24]  663 	mov	_printIO,#0x00
                                    664 ;	usb_cdc.c:185: uint8_t espBootCount = 0;
      0000CF 75 2E 00         [24]  665 	mov	_espBootCount,#0x00
                                    666 ;	usb_cdc.c:186: uint8_t resetToBoot = 0;
      0000D2 75 2F 00         [24]  667 	mov	_resetToBoot,#0x00
                                    668 ;	usb_cdc.c:188: uint8_t rebootESP32 = 0;
      0000D5 75 30 00         [24]  669 	mov	_rebootESP32,#0x00
                                    670 ;	usb_cdc.c:189: uint8_t countESP32Endl = 0;
      0000D8 75 31 00         [24]  671 	mov	_countESP32Endl,#0x00
                                    672 ;	usb_cdc.c:190: static uint8_t esp32EndlFlash[12] = {0x00, 0x12, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00};
      0000DB 75 32 00         [24]  673 	mov	_esp32EndlFlash,#0x00
      0000DE 75 33 12         [24]  674 	mov	(_esp32EndlFlash + 0x0001),#0x12
      0000E1 75 34 04         [24]  675 	mov	(_esp32EndlFlash + 0x0002),#0x04
      0000E4 75 35 00         [24]  676 	mov	(_esp32EndlFlash + 0x0003),#0x00
      0000E7 75 36 00         [24]  677 	mov	(_esp32EndlFlash + 0x0004),#0x00
      0000EA 75 37 00         [24]  678 	mov	(_esp32EndlFlash + 0x0005),#0x00
      0000ED 75 38 00         [24]  679 	mov	(_esp32EndlFlash + 0x0006),#0x00
      0000F0 75 39 00         [24]  680 	mov	(_esp32EndlFlash + 0x0007),#0x00
      0000F3 75 3A 01         [24]  681 	mov	(_esp32EndlFlash + 0x0008),#0x01
      0000F6 75 3B 00         [24]  682 	mov	(_esp32EndlFlash + 0x0009),#0x00
      0000F9 75 3C 00         [24]  683 	mov	(_esp32EndlFlash + 0x000a),#0x00
      0000FC 75 3D 00         [24]  684 	mov	(_esp32EndlFlash + 0x000b),#0x00
                                    685 ;	usb_cdc.c:24: idata volatile uint8_t CDC_PutCharBuf_Last = 0;		// Point to the last char in the buffer
      0000FF 78 B7            [12]  686 	mov	r0,#_CDC_PutCharBuf_Last
      000101 76 00            [12]  687 	mov	@r0,#0x00
                                    688 ;	usb_cdc.c:25: idata volatile uint8_t CDC_PutCharBuf_First = 0;	// Point to the first char in the buffer
      000103 78 B8            [12]  689 	mov	r0,#_CDC_PutCharBuf_First
      000105 76 00            [12]  690 	mov	@r0,#0x00
                                    691 ;	usb_cdc.c:26: idata volatile uint8_t CDC_Tx_Busy  = 0;
      000107 78 B9            [12]  692 	mov	r0,#_CDC_Tx_Busy
      000109 76 00            [12]  693 	mov	@r0,#0x00
                                    694 ;	usb_cdc.c:27: idata volatile uint8_t CDC_Tx_Full = 0;
      00010B 78 BA            [12]  695 	mov	r0,#_CDC_Tx_Full
      00010D 76 00            [12]  696 	mov	@r0,#0x00
                                    697 ;	usb_cdc.c:30: idata volatile uint8_t CDC_Rx_Pending = 0;	// Number of bytes need to be processed before accepting more USB packets
      00010F 78 BB            [12]  698 	mov	r0,#_CDC_Rx_Pending
      000111 76 00            [12]  699 	mov	@r0,#0x00
                                    700 ;	usb_cdc.c:31: idata volatile uint8_t CDC_Rx_CurPos = 0;
      000113 78 BC            [12]  701 	mov	r0,#_CDC_Rx_CurPos
      000115 76 00            [12]  702 	mov	@r0,#0x00
                                    703 ;--------------------------------------------------------
                                    704 ; Home
                                    705 ;--------------------------------------------------------
                                    706 	.area HOME    (CODE)
                                    707 	.area HOME    (CODE)
                                    708 ;--------------------------------------------------------
                                    709 ; code
                                    710 ;--------------------------------------------------------
                                    711 	.area CSEG    (CODE)
                                    712 ;------------------------------------------------------------
                                    713 ;Allocation info for local variables in function 'CDC_InitBaud'
                                    714 ;------------------------------------------------------------
                                    715 ;	usb_cdc.c:37: void CDC_InitBaud(void) {
                                    716 ;	-----------------------------------------
                                    717 ;	 function CDC_InitBaud
                                    718 ;	-----------------------------------------
      0004D2                        719 _CDC_InitBaud:
                           000007   720 	ar7 = 0x07
                           000006   721 	ar6 = 0x06
                           000005   722 	ar5 = 0x05
                           000004   723 	ar4 = 0x04
                           000003   724 	ar3 = 0x03
                           000002   725 	ar2 = 0x02
                           000001   726 	ar1 = 0x01
                           000000   727 	ar0 = 0x00
                                    728 ;	usb_cdc.c:38: LineCoding[0] = 0x00;
      0004D2 90 00 CA         [24]  729 	mov	dptr,#_LineCoding
      0004D5 E4               [12]  730 	clr	a
      0004D6 F0               [24]  731 	movx	@dptr,a
                                    732 ;	usb_cdc.c:39: LineCoding[1] = 0xE1;
      0004D7 90 00 CB         [24]  733 	mov	dptr,#(_LineCoding + 0x0001)
      0004DA 74 E1            [12]  734 	mov	a,#0xe1
      0004DC F0               [24]  735 	movx	@dptr,a
                                    736 ;	usb_cdc.c:40: LineCoding[2] = 0x00;
      0004DD 90 00 CC         [24]  737 	mov	dptr,#(_LineCoding + 0x0002)
      0004E0 E4               [12]  738 	clr	a
      0004E1 F0               [24]  739 	movx	@dptr,a
                                    740 ;	usb_cdc.c:41: LineCoding[3] = 0x00;
      0004E2 90 00 CD         [24]  741 	mov	dptr,#(_LineCoding + 0x0003)
      0004E5 F0               [24]  742 	movx	@dptr,a
                                    743 ;	usb_cdc.c:42: LineCoding[4] = 0x00;
      0004E6 90 00 CE         [24]  744 	mov	dptr,#(_LineCoding + 0x0004)
      0004E9 F0               [24]  745 	movx	@dptr,a
                                    746 ;	usb_cdc.c:43: LineCoding[5] = 0x00;
      0004EA 90 00 CF         [24]  747 	mov	dptr,#(_LineCoding + 0x0005)
      0004ED F0               [24]  748 	movx	@dptr,a
                                    749 ;	usb_cdc.c:44: LineCoding[6] = 0x08;
      0004EE 90 00 D0         [24]  750 	mov	dptr,#(_LineCoding + 0x0006)
      0004F1 74 08            [12]  751 	mov	a,#0x08
      0004F3 F0               [24]  752 	movx	@dptr,a
                                    753 ;	usb_cdc.c:45: }
      0004F4 22               [24]  754 	ret
                                    755 ;------------------------------------------------------------
                                    756 ;Allocation info for local variables in function 'CDC_SetBaud'
                                    757 ;------------------------------------------------------------
                                    758 ;x                         Allocated with name '_CDC_SetBaud_x_65537_44'
                                    759 ;x2                        Allocated with name '_CDC_SetBaud_x2_65537_44'
                                    760 ;------------------------------------------------------------
                                    761 ;	usb_cdc.c:47: void CDC_SetBaud(void) {
                                    762 ;	-----------------------------------------
                                    763 ;	 function CDC_SetBaud
                                    764 ;	-----------------------------------------
      0004F5                        765 _CDC_SetBaud:
                                    766 ;	usb_cdc.c:49: U32_XLittle(&CDC_Baud, LineCoding);
      0004F5 90 00 CA         [24]  767 	mov	dptr,#_LineCoding
      0004F8 E0               [24]  768 	movx	a,@dptr
      0004F9 FF               [12]  769 	mov	r7,a
      0004FA 8F 21            [24]  770 	mov	_CDC_Baud,r7
      0004FC 90 00 CB         [24]  771 	mov	dptr,#(_LineCoding + 0x0001)
      0004FF E0               [24]  772 	movx	a,@dptr
      000500 FF               [12]  773 	mov	r7,a
      000501 8F 22            [24]  774 	mov	(_CDC_Baud + 0x0001),r7
      000503 90 00 CC         [24]  775 	mov	dptr,#(_LineCoding + 0x0002)
      000506 E0               [24]  776 	movx	a,@dptr
      000507 FF               [12]  777 	mov	r7,a
      000508 8F 23            [24]  778 	mov	(_CDC_Baud + 0x0002),r7
      00050A 90 00 CD         [24]  779 	mov	dptr,#(_LineCoding + 0x0003)
      00050D E0               [24]  780 	movx	a,@dptr
      00050E FF               [12]  781 	mov	r7,a
      00050F 8F 24            [24]  782 	mov	(_CDC_Baud + 0x0003),r7
                                    783 ;	usb_cdc.c:54: x = 10 * FREQ_SYS / CDC_Baud / 16;                                       //���������Ƶ��ע��x��ֵ��Ҫ���
      000511 85 21 6C         [24]  784 	mov	__divulong_PARM_2,_CDC_Baud
      000514 85 22 6D         [24]  785 	mov	(__divulong_PARM_2 + 1),(_CDC_Baud + 1)
      000517 85 23 6E         [24]  786 	mov	(__divulong_PARM_2 + 2),(_CDC_Baud + 2)
      00051A 85 24 6F         [24]  787 	mov	(__divulong_PARM_2 + 3),(_CDC_Baud + 3)
      00051D 90 1C 00         [24]  788 	mov	dptr,#0x1c00
      000520 75 F0 4E         [24]  789 	mov	b,#0x4e
      000523 74 0E            [12]  790 	mov	a,#0x0e
      000525 12 0D 76         [24]  791 	lcall	__divulong
      000528 AC 82            [24]  792 	mov	r4,dpl
      00052A AD 83            [24]  793 	mov	r5,dph
      00052C AE F0            [24]  794 	mov	r6,b
      00052E FF               [12]  795 	mov	r7,a
      00052F 8C 25            [24]  796 	mov	_CDC_SetBaud_x_65537_44,r4
      000531 ED               [12]  797 	mov	a,r5
      000532 C4               [12]  798 	swap	a
      000533 C5 25            [12]  799 	xch	a,_CDC_SetBaud_x_65537_44
      000535 C4               [12]  800 	swap	a
      000536 54 0F            [12]  801 	anl	a,#0x0f
      000538 65 25            [12]  802 	xrl	a,_CDC_SetBaud_x_65537_44
      00053A C5 25            [12]  803 	xch	a,_CDC_SetBaud_x_65537_44
      00053C 54 0F            [12]  804 	anl	a,#0x0f
      00053E C5 25            [12]  805 	xch	a,_CDC_SetBaud_x_65537_44
      000540 65 25            [12]  806 	xrl	a,_CDC_SetBaud_x_65537_44
      000542 C5 25            [12]  807 	xch	a,_CDC_SetBaud_x_65537_44
      000544 F5 26            [12]  808 	mov	(_CDC_SetBaud_x_65537_44 + 1),a
      000546 EE               [12]  809 	mov	a,r6
      000547 C4               [12]  810 	swap	a
      000548 54 F0            [12]  811 	anl	a,#0xf0
      00054A 45 26            [12]  812 	orl	a,(_CDC_SetBaud_x_65537_44 + 1)
      00054C F5 26            [12]  813 	mov	(_CDC_SetBaud_x_65537_44 + 1),a
      00054E 8E 27            [24]  814 	mov	(_CDC_SetBaud_x_65537_44 + 2),r6
      000550 EF               [12]  815 	mov	a,r7
      000551 C4               [12]  816 	swap	a
      000552 C5 27            [12]  817 	xch	a,(_CDC_SetBaud_x_65537_44 + 2)
      000554 C4               [12]  818 	swap	a
      000555 54 0F            [12]  819 	anl	a,#0x0f
      000557 65 27            [12]  820 	xrl	a,(_CDC_SetBaud_x_65537_44 + 2)
      000559 C5 27            [12]  821 	xch	a,(_CDC_SetBaud_x_65537_44 + 2)
      00055B 54 0F            [12]  822 	anl	a,#0x0f
      00055D C5 27            [12]  823 	xch	a,(_CDC_SetBaud_x_65537_44 + 2)
      00055F 65 27            [12]  824 	xrl	a,(_CDC_SetBaud_x_65537_44 + 2)
      000561 C5 27            [12]  825 	xch	a,(_CDC_SetBaud_x_65537_44 + 2)
      000563 F5 28            [12]  826 	mov	(_CDC_SetBaud_x_65537_44 + 3),a
                                    827 ;	usb_cdc.c:55: x2 = x % 10;
      000565 75 6C 0A         [24]  828 	mov	__modulong_PARM_2,#0x0a
      000568 E4               [12]  829 	clr	a
      000569 F5 6D            [12]  830 	mov	(__modulong_PARM_2 + 1),a
      00056B F5 6E            [12]  831 	mov	(__modulong_PARM_2 + 2),a
      00056D F5 6F            [12]  832 	mov	(__modulong_PARM_2 + 3),a
      00056F 85 25 82         [24]  833 	mov	dpl,_CDC_SetBaud_x_65537_44
      000572 85 26 83         [24]  834 	mov	dph,(_CDC_SetBaud_x_65537_44 + 1)
      000575 85 27 F0         [24]  835 	mov	b,(_CDC_SetBaud_x_65537_44 + 2)
      000578 E5 28            [12]  836 	mov	a,(_CDC_SetBaud_x_65537_44 + 3)
      00057A 12 0C F3         [24]  837 	lcall	__modulong
      00057D AC 82            [24]  838 	mov	r4,dpl
      00057F 8C 29            [24]  839 	mov	_CDC_SetBaud_x2_65537_44,r4
                                    840 ;	usb_cdc.c:56: x /= 10;
      000581 75 6C 0A         [24]  841 	mov	__divulong_PARM_2,#0x0a
      000584 E4               [12]  842 	clr	a
      000585 F5 6D            [12]  843 	mov	(__divulong_PARM_2 + 1),a
      000587 F5 6E            [12]  844 	mov	(__divulong_PARM_2 + 2),a
      000589 F5 6F            [12]  845 	mov	(__divulong_PARM_2 + 3),a
      00058B 85 25 82         [24]  846 	mov	dpl,_CDC_SetBaud_x_65537_44
      00058E 85 26 83         [24]  847 	mov	dph,(_CDC_SetBaud_x_65537_44 + 1)
      000591 85 27 F0         [24]  848 	mov	b,(_CDC_SetBaud_x_65537_44 + 2)
      000594 E5 28            [12]  849 	mov	a,(_CDC_SetBaud_x_65537_44 + 3)
      000596 12 0D 76         [24]  850 	lcall	__divulong
      000599 85 82 25         [24]  851 	mov	_CDC_SetBaud_x_65537_44,dpl
      00059C 85 83 26         [24]  852 	mov	(_CDC_SetBaud_x_65537_44 + 1),dph
      00059F 85 F0 27         [24]  853 	mov	(_CDC_SetBaud_x_65537_44 + 2),b
      0005A2 F5 28            [12]  854 	mov	(_CDC_SetBaud_x_65537_44 + 3),a
                                    855 ;	usb_cdc.c:57: if ( x2 >= 5 ) x ++;    
      0005A4 74 FB            [12]  856 	mov	a,#0x100 - 0x05
      0005A6 25 29            [12]  857 	add	a,_CDC_SetBaud_x2_65537_44
      0005A8 50 15            [24]  858 	jnc	00102$
      0005AA 74 01            [12]  859 	mov	a,#0x01
      0005AC 25 25            [12]  860 	add	a,_CDC_SetBaud_x_65537_44
      0005AE F5 25            [12]  861 	mov	_CDC_SetBaud_x_65537_44,a
      0005B0 E4               [12]  862 	clr	a
      0005B1 35 26            [12]  863 	addc	a,(_CDC_SetBaud_x_65537_44 + 1)
      0005B3 F5 26            [12]  864 	mov	(_CDC_SetBaud_x_65537_44 + 1),a
      0005B5 E4               [12]  865 	clr	a
      0005B6 35 27            [12]  866 	addc	a,(_CDC_SetBaud_x_65537_44 + 2)
      0005B8 F5 27            [12]  867 	mov	(_CDC_SetBaud_x_65537_44 + 2),a
      0005BA E4               [12]  868 	clr	a
      0005BB 35 28            [12]  869 	addc	a,(_CDC_SetBaud_x_65537_44 + 3)
      0005BD F5 28            [12]  870 	mov	(_CDC_SetBaud_x_65537_44 + 3),a
      0005BF                        871 00102$:
                                    872 ;	usb_cdc.c:58: TH1 = 0-x;  
      0005BF AF 25            [24]  873 	mov	r7,_CDC_SetBaud_x_65537_44
      0005C1 C3               [12]  874 	clr	c
      0005C2 E4               [12]  875 	clr	a
      0005C3 9F               [12]  876 	subb	a,r7
      0005C4 F5 8D            [12]  877 	mov	_TH1,a
                                    878 ;	usb_cdc.c:59: }
      0005C6 22               [24]  879 	ret
                                    880 ;------------------------------------------------------------
                                    881 ;Allocation info for local variables in function 'USB_EP1_IN'
                                    882 ;------------------------------------------------------------
                                    883 ;	usb_cdc.c:61: void USB_EP1_IN(void) {
                                    884 ;	-----------------------------------------
                                    885 ;	 function USB_EP1_IN
                                    886 ;	-----------------------------------------
      0005C7                        887 _USB_EP1_IN:
                                    888 ;	usb_cdc.c:62: UEP1_T_LEN = 0;
      0005C7 75 D3 00         [24]  889 	mov	_UEP1_T_LEN,#0x00
                                    890 ;	usb_cdc.c:63: UEP1_CTRL = UEP1_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_NAK;
      0005CA 74 FC            [12]  891 	mov	a,#0xfc
      0005CC 55 D2            [12]  892 	anl	a,_UEP1_CTRL
      0005CE FF               [12]  893 	mov	r7,a
      0005CF 43 07 02         [24]  894 	orl	ar7,#0x02
      0005D2 8F D2            [24]  895 	mov	_UEP1_CTRL,r7
                                    896 ;	usb_cdc.c:64: }
      0005D4 22               [24]  897 	ret
                                    898 ;------------------------------------------------------------
                                    899 ;Allocation info for local variables in function 'USB_EP2_IN'
                                    900 ;------------------------------------------------------------
                                    901 ;	usb_cdc.c:66: void USB_EP2_IN(void) {
                                    902 ;	-----------------------------------------
                                    903 ;	 function USB_EP2_IN
                                    904 ;	-----------------------------------------
      0005D5                        905 _USB_EP2_IN:
                                    906 ;	usb_cdc.c:67: UEP2_T_LEN = 0;
      0005D5 75 D5 00         [24]  907 	mov	_UEP2_T_LEN,#0x00
                                    908 ;	usb_cdc.c:68: if (CDC_Tx_Full) {
      0005D8 78 BA            [12]  909 	mov	r0,#_CDC_Tx_Full
      0005DA E6               [12]  910 	mov	a,@r0
      0005DB 60 0C            [24]  911 	jz	00102$
                                    912 ;	usb_cdc.c:70: UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_ACK;	// ACK next IN transfer
      0005DD 74 FC            [12]  913 	mov	a,#0xfc
      0005DF 55 D4            [12]  914 	anl	a,_UEP2_CTRL
      0005E1 FF               [12]  915 	mov	r7,a
      0005E2 8F D4            [24]  916 	mov	_UEP2_CTRL,r7
                                    917 ;	usb_cdc.c:71: CDC_Tx_Full = 0;
      0005E4 78 BA            [12]  918 	mov	r0,#_CDC_Tx_Full
      0005E6 76 00            [12]  919 	mov	@r0,#0x00
      0005E8 22               [24]  920 	ret
      0005E9                        921 00102$:
                                    922 ;	usb_cdc.c:74: UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_NAK;
      0005E9 74 FC            [12]  923 	mov	a,#0xfc
      0005EB 55 D4            [12]  924 	anl	a,_UEP2_CTRL
      0005ED FF               [12]  925 	mov	r7,a
      0005EE 43 07 02         [24]  926 	orl	ar7,#0x02
      0005F1 8F D4            [24]  927 	mov	_UEP2_CTRL,r7
                                    928 ;	usb_cdc.c:75: CDC_Tx_Busy = 0;
      0005F3 78 B9            [12]  929 	mov	r0,#_CDC_Tx_Busy
      0005F5 76 00            [12]  930 	mov	@r0,#0x00
                                    931 ;	usb_cdc.c:77: }
      0005F7 22               [24]  932 	ret
                                    933 ;------------------------------------------------------------
                                    934 ;Allocation info for local variables in function 'USB_EP2_OUT'
                                    935 ;------------------------------------------------------------
                                    936 ;	usb_cdc.c:79: void USB_EP2_OUT(void) {
                                    937 ;	-----------------------------------------
                                    938 ;	 function USB_EP2_OUT
                                    939 ;	-----------------------------------------
      0005F8                        940 _USB_EP2_OUT:
                                    941 ;	usb_cdc.c:80: if (!U_TOG_OK )
      0005F8 20 DE 01         [24]  942 	jb	_U_TOG_OK,00102$
                                    943 ;	usb_cdc.c:81: return;
      0005FB 22               [24]  944 	ret
      0005FC                        945 00102$:
                                    946 ;	usb_cdc.c:83: CDC_Rx_Pending = USB_RX_LEN;
      0005FC 78 BB            [12]  947 	mov	r0,#_CDC_Rx_Pending
      0005FE A6 DB            [24]  948 	mov	@r0,_USB_RX_LEN
                                    949 ;	usb_cdc.c:84: CDC_Rx_CurPos = 0;				// Reset Rx pointer
      000600 78 BC            [12]  950 	mov	r0,#_CDC_Rx_CurPos
      000602 76 00            [12]  951 	mov	@r0,#0x00
                                    952 ;	usb_cdc.c:86: UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_R_RES | UEP_R_RES_NAK;
      000604 74 F3            [12]  953 	mov	a,#0xf3
      000606 55 D4            [12]  954 	anl	a,_UEP2_CTRL
      000608 FF               [12]  955 	mov	r7,a
      000609 43 07 08         [24]  956 	orl	ar7,#0x08
      00060C 8F D4            [24]  957 	mov	_UEP2_CTRL,r7
                                    958 ;	usb_cdc.c:87: }
      00060E 22               [24]  959 	ret
                                    960 ;------------------------------------------------------------
                                    961 ;Allocation info for local variables in function 'CDC_PutChar'
                                    962 ;------------------------------------------------------------
                                    963 ;tdata                     Allocated to registers r7 
                                    964 ;------------------------------------------------------------
                                    965 ;	usb_cdc.c:89: void CDC_PutChar(uint8_t tdata) {
                                    966 ;	-----------------------------------------
                                    967 ;	 function CDC_PutChar
                                    968 ;	-----------------------------------------
      00060F                        969 _CDC_PutChar:
      00060F AF 82            [24]  970 	mov	r7,dpl
                                    971 ;	usb_cdc.c:91: CDC_PutCharBuf[CDC_PutCharBuf_Last++] = tdata;
      000611 78 B7            [12]  972 	mov	r0,#_CDC_PutCharBuf_Last
      000613 86 06            [24]  973 	mov	ar6,@r0
      000615 78 B7            [12]  974 	mov	r0,#_CDC_PutCharBuf_Last
      000617 06               [12]  975 	inc	@r0
      000618 EE               [12]  976 	mov	a,r6
      000619 24 77            [12]  977 	add	a,#_CDC_PutCharBuf
      00061B F8               [12]  978 	mov	r0,a
      00061C A6 07            [24]  979 	mov	@r0,ar7
                                    980 ;	usb_cdc.c:92: if(CDC_PutCharBuf_Last >= CDC_PUTCHARBUF_LEN) {
      00061E 78 B7            [12]  981 	mov	r0,#_CDC_PutCharBuf_Last
      000620 B6 40 00         [24]  982 	cjne	@r0,#0x40,00126$
      000623                        983 00126$:
      000623 40 04            [24]  984 	jc	00102$
                                    985 ;	usb_cdc.c:94: CDC_PutCharBuf_Last = 0;
      000625 78 B7            [12]  986 	mov	r0,#_CDC_PutCharBuf_Last
      000627 76 00            [12]  987 	mov	@r0,#0x00
      000629                        988 00102$:
                                    989 ;	usb_cdc.c:97: if (CDC_PutCharBuf_Last == CDC_PutCharBuf_First) {
      000629 78 B7            [12]  990 	mov	r0,#_CDC_PutCharBuf_Last
      00062B 79 B8            [12]  991 	mov	r1,#_CDC_PutCharBuf_First
      00062D 86 F0            [24]  992 	mov	b,@r0
      00062F E7               [12]  993 	mov	a,@r1
      000630 B5 F0 0E         [24]  994 	cjne	a,b,00108$
                                    995 ;	usb_cdc.c:99: CDC_Tx_Full = 1;
      000633 78 BA            [12]  996 	mov	r0,#_CDC_Tx_Full
      000635 76 01            [12]  997 	mov	@r0,#0x01
                                    998 ;	usb_cdc.c:101: while(CDC_Tx_Full)	// Wait until the buffer has vacancy
      000637                        999 00103$:
      000637 78 BA            [12] 1000 	mov	r0,#_CDC_Tx_Full
      000639 E6               [12] 1001 	mov	a,@r0
      00063A 60 05            [24] 1002 	jz	00108$
                                   1003 ;	usb_cdc.c:102: CDC_USB_Poll();
      00063C 12 06 6D         [24] 1004 	lcall	_CDC_USB_Poll
      00063F 80 F6            [24] 1005 	sjmp	00103$
      000641                       1006 00108$:
                                   1007 ;	usb_cdc.c:104: }
      000641 22               [24] 1008 	ret
                                   1009 ;------------------------------------------------------------
                                   1010 ;Allocation info for local variables in function 'CDC_Puts'
                                   1011 ;------------------------------------------------------------
                                   1012 ;str                       Allocated to registers 
                                   1013 ;------------------------------------------------------------
                                   1014 ;	usb_cdc.c:106: void CDC_Puts(char *str) {
                                   1015 ;	-----------------------------------------
                                   1016 ;	 function CDC_Puts
                                   1017 ;	-----------------------------------------
      000642                       1018 _CDC_Puts:
      000642 AD 82            [24] 1019 	mov	r5,dpl
      000644 AE 83            [24] 1020 	mov	r6,dph
      000646 AF F0            [24] 1021 	mov	r7,b
                                   1022 ;	usb_cdc.c:107: while(*str)
      000648                       1023 00101$:
      000648 8D 82            [24] 1024 	mov	dpl,r5
      00064A 8E 83            [24] 1025 	mov	dph,r6
      00064C 8F F0            [24] 1026 	mov	b,r7
      00064E 12 0E 4B         [24] 1027 	lcall	__gptrget
      000651 FC               [12] 1028 	mov	r4,a
      000652 60 18            [24] 1029 	jz	00104$
                                   1030 ;	usb_cdc.c:108: CDC_PutChar(*(str++));
      000654 8C 82            [24] 1031 	mov	dpl,r4
      000656 0D               [12] 1032 	inc	r5
      000657 BD 00 01         [24] 1033 	cjne	r5,#0x00,00116$
      00065A 0E               [12] 1034 	inc	r6
      00065B                       1035 00116$:
      00065B C0 07            [24] 1036 	push	ar7
      00065D C0 06            [24] 1037 	push	ar6
      00065F C0 05            [24] 1038 	push	ar5
      000661 12 06 0F         [24] 1039 	lcall	_CDC_PutChar
      000664 D0 05            [24] 1040 	pop	ar5
      000666 D0 06            [24] 1041 	pop	ar6
      000668 D0 07            [24] 1042 	pop	ar7
      00066A 80 DC            [24] 1043 	sjmp	00101$
      00066C                       1044 00104$:
                                   1045 ;	usb_cdc.c:109: }
      00066C 22               [24] 1046 	ret
                                   1047 ;------------------------------------------------------------
                                   1048 ;Allocation info for local variables in function 'CDC_USB_Poll'
                                   1049 ;------------------------------------------------------------
                                   1050 ;usb_frame_count           Allocated with name '_CDC_USB_Poll_usb_frame_count_65536_59'
                                   1051 ;usb_tx_len                Allocated to registers r7 
                                   1052 ;------------------------------------------------------------
                                   1053 ;	usb_cdc.c:112: void CDC_USB_Poll() {
                                   1054 ;	-----------------------------------------
                                   1055 ;	 function CDC_USB_Poll
                                   1056 ;	-----------------------------------------
      00066D                       1057 _CDC_USB_Poll:
                                   1058 ;	usb_cdc.c:116: if(UsbConfig) {
      00066D E5 10            [12] 1059 	mov	a,_UsbConfig
      00066F 70 01            [24] 1060 	jnz	00168$
      000671 22               [24] 1061 	ret
      000672                       1062 00168$:
                                   1063 ;	usb_cdc.c:117: if(usb_frame_count++ > 100) {
      000672 AF 2A            [24] 1064 	mov	r7,_CDC_USB_Poll_usb_frame_count_65536_59
      000674 05 2A            [12] 1065 	inc	_CDC_USB_Poll_usb_frame_count_65536_59
      000676 EF               [12] 1066 	mov	a,r7
      000677 24 9B            [12] 1067 	add	a,#0xff - 0x64
      000679 40 01            [24] 1068 	jc	00169$
      00067B 22               [24] 1069 	ret
      00067C                       1070 00169$:
                                   1071 ;	usb_cdc.c:118: usb_frame_count = 0;
      00067C 75 2A 00         [24] 1072 	mov	_CDC_USB_Poll_usb_frame_count_65536_59,#0x00
                                   1073 ;	usb_cdc.c:120: if(!CDC_Tx_Busy) {
      00067F 78 B9            [12] 1074 	mov	r0,#_CDC_Tx_Busy
      000681 E6               [12] 1075 	mov	a,@r0
      000682 60 01            [24] 1076 	jz	00170$
      000684 22               [24] 1077 	ret
      000685                       1078 00170$:
                                   1079 ;	usb_cdc.c:121: if(CDC_PutCharBuf_First == CDC_PutCharBuf_Last) {
      000685 78 B8            [12] 1080 	mov	r0,#_CDC_PutCharBuf_First
      000687 79 B7            [12] 1081 	mov	r1,#_CDC_PutCharBuf_Last
      000689 86 F0            [24] 1082 	mov	b,@r0
      00068B E7               [12] 1083 	mov	a,@r1
      00068C B5 F0 64         [24] 1084 	cjne	a,b,00113$
                                   1085 ;	usb_cdc.c:122: if (CDC_Tx_Full) { // Buffer is full
      00068F 78 BA            [12] 1086 	mov	r0,#_CDC_Tx_Full
      000691 E6               [12] 1087 	mov	a,@r0
      000692 60 5E            [24] 1088 	jz	00104$
                                   1089 ;	usb_cdc.c:123: CDC_Tx_Busy = 1;
      000694 78 B9            [12] 1090 	mov	r0,#_CDC_Tx_Busy
      000696 76 01            [12] 1091 	mov	@r0,#0x01
                                   1092 ;	usb_cdc.c:126: usb_tx_len = CDC_PUTCHARBUF_LEN - CDC_PutCharBuf_First;
      000698 78 B8            [12] 1093 	mov	r0,#_CDC_PutCharBuf_First
      00069A 86 07            [24] 1094 	mov	ar7,@r0
      00069C 74 40            [12] 1095 	mov	a,#0x40
      00069E C3               [12] 1096 	clr	c
      00069F 9F               [12] 1097 	subb	a,r7
      0006A0 FF               [12] 1098 	mov	r7,a
                                   1099 ;	usb_cdc.c:127: memcpy(EP2_TX_BUF, &CDC_PutCharBuf[CDC_PutCharBuf_First], usb_tx_len);
      0006A1 78 B8            [12] 1100 	mov	r0,#_CDC_PutCharBuf_First
      0006A3 E6               [12] 1101 	mov	a,@r0
      0006A4 24 77            [12] 1102 	add	a,#_CDC_PutCharBuf
      0006A6 FE               [12] 1103 	mov	r6,a
      0006A7 8E 6C            [24] 1104 	mov	_memcpy_PARM_2,r6
      0006A9 75 6D 00         [24] 1105 	mov	(_memcpy_PARM_2 + 1),#0x00
      0006AC 75 6E 40         [24] 1106 	mov	(_memcpy_PARM_2 + 2),#0x40
      0006AF 8F 6F            [24] 1107 	mov	_memcpy_PARM_3,r7
      0006B1 75 70 00         [24] 1108 	mov	(_memcpy_PARM_3 + 1),#0x00
      0006B4 90 00 8A         [24] 1109 	mov	dptr,#(_Ep2Buffer + 0x0040)
      0006B7 75 F0 00         [24] 1110 	mov	b,#0x00
      0006BA C0 07            [24] 1111 	push	ar7
      0006BC 12 0D DB         [24] 1112 	lcall	_memcpy
      0006BF D0 07            [24] 1113 	pop	ar7
                                   1114 ;	usb_cdc.c:130: if (CDC_PutCharBuf_Last > 0)
      0006C1 78 B7            [12] 1115 	mov	r0,#_CDC_PutCharBuf_Last
      0006C3 E6               [12] 1116 	mov	a,@r0
      0006C4 60 21            [24] 1117 	jz	00102$
                                   1118 ;	usb_cdc.c:131: memcpy(&EP2_TX_BUF[usb_tx_len], CDC_PutCharBuf, CDC_PutCharBuf_Last);
      0006C6 EF               [12] 1119 	mov	a,r7
      0006C7 24 8A            [12] 1120 	add	a,#(_Ep2Buffer + 0x0040)
      0006C9 FF               [12] 1121 	mov	r7,a
      0006CA E4               [12] 1122 	clr	a
      0006CB 34 00            [12] 1123 	addc	a,#((_Ep2Buffer + 0x0040) >> 8)
      0006CD FE               [12] 1124 	mov	r6,a
      0006CE 7D 00            [12] 1125 	mov	r5,#0x00
      0006D0 75 6C 77         [24] 1126 	mov	_memcpy_PARM_2,#_CDC_PutCharBuf
                                   1127 ;	1-genFromRTrack replaced	mov	(_memcpy_PARM_2 + 1),#0x00
      0006D3 8D 6D            [24] 1128 	mov	(_memcpy_PARM_2 + 1),r5
      0006D5 75 6E 40         [24] 1129 	mov	(_memcpy_PARM_2 + 2),#0x40
      0006D8 78 B7            [12] 1130 	mov	r0,#_CDC_PutCharBuf_Last
      0006DA 86 6F            [24] 1131 	mov	_memcpy_PARM_3,@r0
                                   1132 ;	1-genFromRTrack replaced	mov	(_memcpy_PARM_3 + 1),#0x00
      0006DC 8D 70            [24] 1133 	mov	(_memcpy_PARM_3 + 1),r5
      0006DE 8F 82            [24] 1134 	mov	dpl,r7
      0006E0 8E 83            [24] 1135 	mov	dph,r6
      0006E2 8D F0            [24] 1136 	mov	b,r5
      0006E4 12 0D DB         [24] 1137 	lcall	_memcpy
      0006E7                       1138 00102$:
                                   1139 ;	usb_cdc.c:134: UEP2_T_LEN = CDC_PUTCHARBUF_LEN;
      0006E7 75 D5 40         [24] 1140 	mov	_UEP2_T_LEN,#0x40
                                   1141 ;	usb_cdc.c:135: UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_ACK;	// ACK next IN transfer
      0006EA 74 FC            [12] 1142 	mov	a,#0xfc
      0006EC 55 D4            [12] 1143 	anl	a,_UEP2_CTRL
      0006EE FF               [12] 1144 	mov	r7,a
      0006EF 8F D4            [24] 1145 	mov	_UEP2_CTRL,r7
                                   1146 ;	usb_cdc.c:139: return;
      0006F1 22               [24] 1147 	ret
      0006F2                       1148 00104$:
                                   1149 ;	usb_cdc.c:143: return;
      0006F2 22               [24] 1150 	ret
      0006F3                       1151 00113$:
                                   1152 ;	usb_cdc.c:145: CDC_Tx_Busy = 1;
      0006F3 78 B9            [12] 1153 	mov	r0,#_CDC_Tx_Busy
      0006F5 76 01            [12] 1154 	mov	@r0,#0x01
                                   1155 ;	usb_cdc.c:150: if(CDC_PutCharBuf_First > CDC_PutCharBuf_Last) { // Rollback
      0006F7 78 B8            [12] 1156 	mov	r0,#_CDC_PutCharBuf_First
      0006F9 79 B7            [12] 1157 	mov	r1,#_CDC_PutCharBuf_Last
      0006FB C3               [12] 1158 	clr	c
      0006FC E7               [12] 1159 	mov	a,@r1
      0006FD 96               [12] 1160 	subb	a,@r0
      0006FE 50 5C            [24] 1161 	jnc	00108$
                                   1162 ;	usb_cdc.c:152: usb_tx_len = CDC_PUTCHARBUF_LEN - CDC_PutCharBuf_First;
      000700 78 B8            [12] 1163 	mov	r0,#_CDC_PutCharBuf_First
      000702 86 07            [24] 1164 	mov	ar7,@r0
      000704 74 40            [12] 1165 	mov	a,#0x40
      000706 C3               [12] 1166 	clr	c
      000707 9F               [12] 1167 	subb	a,r7
      000708 FF               [12] 1168 	mov	r7,a
                                   1169 ;	usb_cdc.c:153: memcpy(EP2_TX_BUF, &CDC_PutCharBuf[CDC_PutCharBuf_First], usb_tx_len);
      000709 78 B8            [12] 1170 	mov	r0,#_CDC_PutCharBuf_First
      00070B E6               [12] 1171 	mov	a,@r0
      00070C 24 77            [12] 1172 	add	a,#_CDC_PutCharBuf
      00070E FE               [12] 1173 	mov	r6,a
      00070F 8E 6C            [24] 1174 	mov	_memcpy_PARM_2,r6
      000711 75 6D 00         [24] 1175 	mov	(_memcpy_PARM_2 + 1),#0x00
      000714 75 6E 40         [24] 1176 	mov	(_memcpy_PARM_2 + 2),#0x40
      000717 8F 6F            [24] 1177 	mov	_memcpy_PARM_3,r7
      000719 75 70 00         [24] 1178 	mov	(_memcpy_PARM_3 + 1),#0x00
      00071C 90 00 8A         [24] 1179 	mov	dptr,#(_Ep2Buffer + 0x0040)
      00071F 75 F0 00         [24] 1180 	mov	b,#0x00
      000722 C0 07            [24] 1181 	push	ar7
      000724 12 0D DB         [24] 1182 	lcall	_memcpy
      000727 D0 07            [24] 1183 	pop	ar7
                                   1184 ;	usb_cdc.c:156: if (CDC_PutCharBuf_Last > 0) {
      000729 78 B7            [12] 1185 	mov	r0,#_CDC_PutCharBuf_Last
      00072B E6               [12] 1186 	mov	a,@r0
      00072C 60 2A            [24] 1187 	jz	00106$
                                   1188 ;	usb_cdc.c:157: memcpy(&EP2_TX_BUF[usb_tx_len], CDC_PutCharBuf, CDC_PutCharBuf_Last);
      00072E EF               [12] 1189 	mov	a,r7
      00072F 24 8A            [12] 1190 	add	a,#(_Ep2Buffer + 0x0040)
      000731 FD               [12] 1191 	mov	r5,a
      000732 E4               [12] 1192 	clr	a
      000733 34 00            [12] 1193 	addc	a,#((_Ep2Buffer + 0x0040) >> 8)
      000735 FE               [12] 1194 	mov	r6,a
      000736 7C 00            [12] 1195 	mov	r4,#0x00
      000738 75 6C 77         [24] 1196 	mov	_memcpy_PARM_2,#_CDC_PutCharBuf
                                   1197 ;	1-genFromRTrack replaced	mov	(_memcpy_PARM_2 + 1),#0x00
      00073B 8C 6D            [24] 1198 	mov	(_memcpy_PARM_2 + 1),r4
      00073D 75 6E 40         [24] 1199 	mov	(_memcpy_PARM_2 + 2),#0x40
      000740 78 B7            [12] 1200 	mov	r0,#_CDC_PutCharBuf_Last
      000742 86 6F            [24] 1201 	mov	_memcpy_PARM_3,@r0
                                   1202 ;	1-genFromRTrack replaced	mov	(_memcpy_PARM_3 + 1),#0x00
      000744 8C 70            [24] 1203 	mov	(_memcpy_PARM_3 + 1),r4
      000746 8D 82            [24] 1204 	mov	dpl,r5
      000748 8E 83            [24] 1205 	mov	dph,r6
      00074A 8C F0            [24] 1206 	mov	b,r4
      00074C C0 07            [24] 1207 	push	ar7
      00074E 12 0D DB         [24] 1208 	lcall	_memcpy
      000751 D0 07            [24] 1209 	pop	ar7
                                   1210 ;	usb_cdc.c:158: usb_tx_len += CDC_PutCharBuf_Last;
      000753 78 B7            [12] 1211 	mov	r0,#_CDC_PutCharBuf_Last
      000755 E6               [12] 1212 	mov	a,@r0
      000756 2F               [12] 1213 	add	a,r7
      000757 FF               [12] 1214 	mov	r7,a
      000758                       1215 00106$:
                                   1216 ;	usb_cdc.c:161: UEP2_T_LEN = usb_tx_len;
      000758 8F D5            [24] 1217 	mov	_UEP2_T_LEN,r7
      00075A 80 2A            [24] 1218 	sjmp	00109$
      00075C                       1219 00108$:
                                   1220 ;	usb_cdc.c:163: usb_tx_len = CDC_PutCharBuf_Last - CDC_PutCharBuf_First;
      00075C 78 B7            [12] 1221 	mov	r0,#_CDC_PutCharBuf_Last
      00075E 79 B8            [12] 1222 	mov	r1,#_CDC_PutCharBuf_First
      000760 E6               [12] 1223 	mov	a,@r0
      000761 C3               [12] 1224 	clr	c
      000762 97               [12] 1225 	subb	a,@r1
      000763 FF               [12] 1226 	mov	r7,a
                                   1227 ;	usb_cdc.c:164: memcpy(EP2_TX_BUF, &CDC_PutCharBuf[CDC_PutCharBuf_First], usb_tx_len);
      000764 78 B8            [12] 1228 	mov	r0,#_CDC_PutCharBuf_First
      000766 E6               [12] 1229 	mov	a,@r0
      000767 24 77            [12] 1230 	add	a,#_CDC_PutCharBuf
      000769 FE               [12] 1231 	mov	r6,a
      00076A 8E 6C            [24] 1232 	mov	_memcpy_PARM_2,r6
      00076C 75 6D 00         [24] 1233 	mov	(_memcpy_PARM_2 + 1),#0x00
      00076F 75 6E 40         [24] 1234 	mov	(_memcpy_PARM_2 + 2),#0x40
      000772 8F 6F            [24] 1235 	mov	_memcpy_PARM_3,r7
      000774 75 70 00         [24] 1236 	mov	(_memcpy_PARM_3 + 1),#0x00
      000777 90 00 8A         [24] 1237 	mov	dptr,#(_Ep2Buffer + 0x0040)
      00077A 75 F0 00         [24] 1238 	mov	b,#0x00
      00077D C0 07            [24] 1239 	push	ar7
      00077F 12 0D DB         [24] 1240 	lcall	_memcpy
      000782 D0 07            [24] 1241 	pop	ar7
                                   1242 ;	usb_cdc.c:166: UEP2_T_LEN = usb_tx_len;
      000784 8F D5            [24] 1243 	mov	_UEP2_T_LEN,r7
      000786                       1244 00109$:
                                   1245 ;	usb_cdc.c:169: CDC_PutCharBuf_First += usb_tx_len;
      000786 78 B8            [12] 1246 	mov	r0,#_CDC_PutCharBuf_First
      000788 EF               [12] 1247 	mov	a,r7
      000789 26               [12] 1248 	add	a,@r0
      00078A F6               [12] 1249 	mov	@r0,a
                                   1250 ;	usb_cdc.c:170: if(CDC_PutCharBuf_First>=CDC_PUTCHARBUF_LEN)
      00078B 78 B8            [12] 1251 	mov	r0,#_CDC_PutCharBuf_First
      00078D B6 40 00         [24] 1252 	cjne	@r0,#0x40,00177$
      000790                       1253 00177$:
      000790 40 0A            [24] 1254 	jc	00111$
                                   1255 ;	usb_cdc.c:171: CDC_PutCharBuf_First -= CDC_PUTCHARBUF_LEN;
      000792 78 B8            [12] 1256 	mov	r0,#_CDC_PutCharBuf_First
      000794 86 07            [24] 1257 	mov	ar7,@r0
      000796 78 B8            [12] 1258 	mov	r0,#_CDC_PutCharBuf_First
      000798 EF               [12] 1259 	mov	a,r7
      000799 24 C0            [12] 1260 	add	a,#0xc0
      00079B F6               [12] 1261 	mov	@r0,a
      00079C                       1262 00111$:
                                   1263 ;	usb_cdc.c:174: UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_ACK;
      00079C 74 FC            [12] 1264 	mov	a,#0xfc
      00079E 55 D4            [12] 1265 	anl	a,_UEP2_CTRL
      0007A0 FF               [12] 1266 	mov	r7,a
      0007A1 8F D4            [24] 1267 	mov	_UEP2_CTRL,r7
                                   1268 ;	usb_cdc.c:180: }
      0007A3 22               [24] 1269 	ret
                                   1270 ;------------------------------------------------------------
                                   1271 ;Allocation info for local variables in function 'CDC_UART_Poll'
                                   1272 ;------------------------------------------------------------
                                   1273 ;former_data               Allocated with name '_CDC_UART_Poll_former_data_65536_69'
                                   1274 ;cdc_rx_state              Allocated with name '_CDC_UART_Poll_cdc_rx_state_65536_69'
                                   1275 ;dontstop                  Allocated with name '_CDC_UART_Poll_dontstop_65536_69'
                                   1276 ;frame_len                 Allocated with name '_CDC_UART_Poll_frame_len_65536_69'
                                   1277 ;frame_sent                Allocated with name '_CDC_UART_Poll_frame_sent_65536_69'
                                   1278 ;i2c_error_no              Allocated with name '_CDC_UART_Poll_i2c_error_no_65536_69'
                                   1279 ;cur_byte                  Allocated to registers r7 
                                   1280 ;------------------------------------------------------------
                                   1281 ;	usb_cdc.c:192: void CDC_UART_Poll() {
                                   1282 ;	-----------------------------------------
                                   1283 ;	 function CDC_UART_Poll
                                   1284 ;	-----------------------------------------
      0007A4                       1285 _CDC_UART_Poll:
                                   1286 ;	usb_cdc.c:217: if(CDC_Rx_Pending) {
      0007A4 78 BB            [12] 1287 	mov	r0,#_CDC_Rx_Pending
      0007A6 E6               [12] 1288 	mov	a,@r0
      0007A7 70 01            [24] 1289 	jnz	00179$
      0007A9 22               [24] 1290 	ret
      0007AA                       1291 00179$:
                                   1292 ;	usb_cdc.c:218: cur_byte = EP2_RX_BUF[CDC_Rx_CurPos++];
      0007AA 78 BC            [12] 1293 	mov	r0,#_CDC_Rx_CurPos
      0007AC 86 07            [24] 1294 	mov	ar7,@r0
      0007AE 78 BC            [12] 1295 	mov	r0,#_CDC_Rx_CurPos
      0007B0 06               [12] 1296 	inc	@r0
      0007B1 EF               [12] 1297 	mov	a,r7
      0007B2 24 4A            [12] 1298 	add	a,#_Ep2Buffer
      0007B4 F5 82            [12] 1299 	mov	dpl,a
      0007B6 E4               [12] 1300 	clr	a
      0007B7 34 00            [12] 1301 	addc	a,#(_Ep2Buffer >> 8)
      0007B9 F5 83            [12] 1302 	mov	dph,a
      0007BB E0               [24] 1303 	movx	a,@dptr
      0007BC FF               [12] 1304 	mov	r7,a
                                   1305 ;	usb_cdc.c:220: if(cdc_rx_state == CDC_STATE_IDLE) {
      0007BD E5 3F            [12] 1306 	mov	a,_CDC_UART_Poll_cdc_rx_state_65536_69
      0007BF 60 03            [24] 1307 	jz	00180$
      0007C1 02 08 44         [24] 1308 	ljmp	00124$
      0007C4                       1309 00180$:
                                   1310 ;	usb_cdc.c:221: CH554UART0SendByte(cur_byte);
      0007C4 8F 82            [24] 1311 	mov	dpl,r7
      0007C6 C0 07            [24] 1312 	push	ar7
      0007C8 12 04 99         [24] 1313 	lcall	_CH554UART0SendByte
      0007CB D0 07            [24] 1314 	pop	ar7
                                   1315 ;	usb_cdc.c:222: if(cur_byte == '^') {
      0007CD BF 5E 11         [24] 1316 	cjne	r7,#0x5e,00104$
                                   1317 ;	usb_cdc.c:223: ++jumptoBoot;
      0007D0 05 2B            [12] 1318 	inc	_jumptoBoot
                                   1319 ;	usb_cdc.c:224: if(jumptoBoot > 10){
      0007D2 E5 2B            [12] 1320 	mov	a,_jumptoBoot
      0007D4 24 F5            [12] 1321 	add	a,#0xff - 0x0a
      0007D6 50 0C            [24] 1322 	jnc	00105$
                                   1323 ;	usb_cdc.c:225: JumpToBootloader();
      0007D8 C0 07            [24] 1324 	push	ar7
      0007DA 12 03 DE         [24] 1325 	lcall	_JumpToBootloader
      0007DD D0 07            [24] 1326 	pop	ar7
      0007DF 80 03            [24] 1327 	sjmp	00105$
      0007E1                       1328 00104$:
                                   1329 ;	usb_cdc.c:228: jumptoBoot = 0;
      0007E1 75 2B 00         [24] 1330 	mov	_jumptoBoot,#0x00
      0007E4                       1331 00105$:
                                   1332 ;	usb_cdc.c:231: if(cur_byte == '%') {
      0007E4 BF 25 18         [24] 1333 	cjne	r7,#0x25,00109$
                                   1334 ;	usb_cdc.c:232: ++resetESP32;
      0007E7 05 2C            [12] 1335 	inc	_resetESP32
                                   1336 ;	usb_cdc.c:233: if(resetESP32 > 5){
      0007E9 E5 2C            [12] 1337 	mov	a,_resetESP32
      0007EB 24 FA            [12] 1338 	add	a,#0xff - 0x05
      0007ED 50 13            [24] 1339 	jnc	00110$
                                   1340 ;	usb_cdc.c:234: rstPin  = 0;
                                   1341 ;	assignBit
      0007EF C2 90            [12] 1342 	clr	_rstPin
                                   1343 ;	usb_cdc.c:235: state = 3;
      0007F1 75 0C 03         [24] 1344 	mov	_state,#0x03
                                   1345 ;	usb_cdc.c:236: count = 0;
      0007F4 E4               [12] 1346 	clr	a
      0007F5 F5 08            [12] 1347 	mov	_count,a
      0007F7 F5 09            [12] 1348 	mov	(_count + 1),a
      0007F9 F5 0A            [12] 1349 	mov	(_count + 2),a
      0007FB F5 0B            [12] 1350 	mov	(_count + 3),a
      0007FD 80 03            [24] 1351 	sjmp	00110$
      0007FF                       1352 00109$:
                                   1353 ;	usb_cdc.c:239: resetESP32 = 0;
      0007FF 75 2C 00         [24] 1354 	mov	_resetESP32,#0x00
      000802                       1355 00110$:
                                   1356 ;	usb_cdc.c:242: if(cur_byte == esp32EndlFlash[countESP32Endl]) {
      000802 E5 31            [12] 1357 	mov	a,_countESP32Endl
      000804 24 32            [12] 1358 	add	a,#_esp32EndlFlash
      000806 F9               [12] 1359 	mov	r1,a
      000807 87 06            [24] 1360 	mov	ar6,@r1
      000809 EF               [12] 1361 	mov	a,r7
      00080A B5 06 1E         [24] 1362 	cjne	a,ar6,00116$
                                   1363 ;	usb_cdc.c:243: ++countESP32Endl;
      00080D 05 31            [12] 1364 	inc	_countESP32Endl
                                   1365 ;	usb_cdc.c:244: if(countESP32Endl == 12){
      00080F 74 0C            [12] 1366 	mov	a,#0x0c
      000811 B5 31 0C         [24] 1367 	cjne	a,_countESP32Endl,00112$
                                   1368 ;	usb_cdc.c:245: state = 4;
      000814 75 0C 04         [24] 1369 	mov	_state,#0x04
                                   1370 ;	usb_cdc.c:246: count = 0;
      000817 E4               [12] 1371 	clr	a
      000818 F5 08            [12] 1372 	mov	_count,a
      00081A F5 09            [12] 1373 	mov	(_count + 1),a
      00081C F5 0A            [12] 1374 	mov	(_count + 2),a
      00081E F5 0B            [12] 1375 	mov	(_count + 3),a
      000820                       1376 00112$:
                                   1377 ;	usb_cdc.c:248: if(countESP32Endl > 12){
      000820 E5 31            [12] 1378 	mov	a,_countESP32Endl
      000822 24 F3            [12] 1379 	add	a,#0xff - 0x0c
      000824 50 08            [24] 1380 	jnc	00117$
                                   1381 ;	usb_cdc.c:249: countESP32Endl = 0;
      000826 75 31 00         [24] 1382 	mov	_countESP32Endl,#0x00
      000829 80 03            [24] 1383 	sjmp	00117$
      00082B                       1384 00116$:
                                   1385 ;	usb_cdc.c:252: countESP32Endl = 0;
      00082B 75 31 00         [24] 1386 	mov	_countESP32Endl,#0x00
      00082E                       1387 00117$:
                                   1388 ;	usb_cdc.c:255: if(cur_byte == 0x55) {
      00082E BF 55 10         [24] 1389 	cjne	r7,#0x55,00121$
                                   1390 ;	usb_cdc.c:256: ++espBootCount;
      000831 05 2E            [12] 1391 	inc	_espBootCount
                                   1392 ;	usb_cdc.c:257: if(espBootCount > 16){
      000833 E5 2E            [12] 1393 	mov	a,_espBootCount
      000835 24 EF            [12] 1394 	add	a,#0xff - 0x10
      000837 50 0B            [24] 1395 	jnc	00124$
                                   1396 ;	usb_cdc.c:258: resetToBoot = 1;
      000839 75 2F 01         [24] 1397 	mov	_resetToBoot,#0x01
                                   1398 ;	usb_cdc.c:259: espBootCount = 0;
      00083C 75 2E 00         [24] 1399 	mov	_espBootCount,#0x00
      00083F 80 03            [24] 1400 	sjmp	00124$
      000841                       1401 00121$:
                                   1402 ;	usb_cdc.c:262: espBootCount = 0;
      000841 75 2E 00         [24] 1403 	mov	_espBootCount,#0x00
      000844                       1404 00124$:
                                   1405 ;	usb_cdc.c:268: former_data = cur_byte;
      000844 8F 3E            [24] 1406 	mov	_CDC_UART_Poll_former_data_65536_69,r7
                                   1407 ;	usb_cdc.c:270: CDC_Rx_Pending--;
      000846 78 BB            [12] 1408 	mov	r0,#_CDC_Rx_Pending
      000848 16               [12] 1409 	dec	@r0
                                   1410 ;	usb_cdc.c:272: if(CDC_Rx_Pending == 0)
      000849 78 BB            [12] 1411 	mov	r0,#_CDC_Rx_Pending
      00084B E6               [12] 1412 	mov	a,@r0
      00084C 70 09            [24] 1413 	jnz	00129$
                                   1414 ;	usb_cdc.c:273: UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_R_RES | UEP_R_RES_ACK;
      00084E 74 F3            [12] 1415 	mov	a,#0xf3
      000850 55 D4            [12] 1416 	anl	a,_UEP2_CTRL
      000852 FF               [12] 1417 	mov	r7,a
      000853 7E 00            [12] 1418 	mov	r6,#0x00
      000855 8F D4            [24] 1419 	mov	_UEP2_CTRL,r7
      000857                       1420 00129$:
                                   1421 ;	usb_cdc.c:275: }
      000857 22               [24] 1422 	ret
                                   1423 	.area CSEG    (CODE)
                                   1424 	.area CONST   (CODE)
                                   1425 	.area XINIT   (CODE)
                                   1426 	.area CABS    (ABS,CODE)
