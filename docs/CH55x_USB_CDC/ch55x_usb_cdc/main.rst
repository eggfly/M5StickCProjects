                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _Port1Cfg_PARM_2
                                     12 	.globl _UART0_RX
                                     13 	.globl _USBInterruptEntry
                                     14 	.globl _main
                                     15 	.globl _TypeC_UPF_PDInit
                                     16 	.globl _Port1Cfg
                                     17 	.globl _CDC_PutChar
                                     18 	.globl _CDC_UART_Poll
                                     19 	.globl _CDC_USB_Poll
                                     20 	.globl _CDC_InitBaud
                                     21 	.globl _USBInterrupt
                                     22 	.globl _CH554_Init
                                     23 	.globl _SCL
                                     24 	.globl _SDA
                                     25 	.globl _resetPin
                                     26 	.globl _bootPin
                                     27 	.globl _UIF_BUS_RST
                                     28 	.globl _UIF_DETECT
                                     29 	.globl _UIF_TRANSFER
                                     30 	.globl _UIF_SUSPEND
                                     31 	.globl _UIF_HST_SOF
                                     32 	.globl _UIF_FIFO_OV
                                     33 	.globl _U_SIE_FREE
                                     34 	.globl _U_TOG_OK
                                     35 	.globl _U_IS_NAK
                                     36 	.globl _ADC_CHAN0
                                     37 	.globl _ADC_CHAN1
                                     38 	.globl _CMP_CHAN
                                     39 	.globl _ADC_START
                                     40 	.globl _ADC_IF
                                     41 	.globl _CMP_IF
                                     42 	.globl _CMPO
                                     43 	.globl _U1RI
                                     44 	.globl _U1TI
                                     45 	.globl _U1RB8
                                     46 	.globl _U1TB8
                                     47 	.globl _U1REN
                                     48 	.globl _U1SMOD
                                     49 	.globl _U1SM0
                                     50 	.globl _S0_R_FIFO
                                     51 	.globl _S0_T_FIFO
                                     52 	.globl _S0_FREE
                                     53 	.globl _S0_IF_BYTE
                                     54 	.globl _S0_IF_FIRST
                                     55 	.globl _S0_IF_OV
                                     56 	.globl _S0_FST_ACT
                                     57 	.globl _CP_RL2
                                     58 	.globl _C_T2
                                     59 	.globl _TR2
                                     60 	.globl _EXEN2
                                     61 	.globl _TCLK
                                     62 	.globl _RCLK
                                     63 	.globl _EXF2
                                     64 	.globl _CAP1F
                                     65 	.globl _TF2
                                     66 	.globl _RI
                                     67 	.globl _TI
                                     68 	.globl _RB8
                                     69 	.globl _TB8
                                     70 	.globl _REN
                                     71 	.globl _SM2
                                     72 	.globl _SM1
                                     73 	.globl _SM0
                                     74 	.globl _IT0
                                     75 	.globl _IE0
                                     76 	.globl _IT1
                                     77 	.globl _IE1
                                     78 	.globl _TR0
                                     79 	.globl _TF0
                                     80 	.globl _TR1
                                     81 	.globl _TF1
                                     82 	.globl _RXD
                                     83 	.globl _PWM1_
                                     84 	.globl _TXD
                                     85 	.globl _PWM2_
                                     86 	.globl _AIN3
                                     87 	.globl _VBUS1
                                     88 	.globl _INT0
                                     89 	.globl _TXD1_
                                     90 	.globl _INT1
                                     91 	.globl _T0
                                     92 	.globl _RXD1_
                                     93 	.globl _PWM2
                                     94 	.globl _T1
                                     95 	.globl _UDP
                                     96 	.globl _UDM
                                     97 	.globl _TIN0
                                     98 	.globl _CAP1
                                     99 	.globl _T2
                                    100 	.globl _AIN0
                                    101 	.globl _VBUS2
                                    102 	.globl _TIN1
                                    103 	.globl _CAP2
                                    104 	.globl _T2EX
                                    105 	.globl _RXD_
                                    106 	.globl _TXD_
                                    107 	.globl _AIN1
                                    108 	.globl _UCC1
                                    109 	.globl _TIN2
                                    110 	.globl _SCS
                                    111 	.globl _CAP1_
                                    112 	.globl _T2_
                                    113 	.globl _AIN2
                                    114 	.globl _UCC2
                                    115 	.globl _TIN3
                                    116 	.globl _PWM1
                                    117 	.globl _MOSI
                                    118 	.globl _TIN4
                                    119 	.globl _RXD1
                                    120 	.globl _MISO
                                    121 	.globl _TIN5
                                    122 	.globl _TXD1
                                    123 	.globl _SCK
                                    124 	.globl _IE_SPI0
                                    125 	.globl _IE_TKEY
                                    126 	.globl _IE_USB
                                    127 	.globl _IE_ADC
                                    128 	.globl _IE_UART1
                                    129 	.globl _IE_PWMX
                                    130 	.globl _IE_GPIO
                                    131 	.globl _IE_WDOG
                                    132 	.globl _PX0
                                    133 	.globl _PT0
                                    134 	.globl _PX1
                                    135 	.globl _PT1
                                    136 	.globl _PS
                                    137 	.globl _PT2
                                    138 	.globl _PL_FLAG
                                    139 	.globl _PH_FLAG
                                    140 	.globl _EX0
                                    141 	.globl _ET0
                                    142 	.globl _EX1
                                    143 	.globl _ET1
                                    144 	.globl _ES
                                    145 	.globl _ET2
                                    146 	.globl _E_DIS
                                    147 	.globl _EA
                                    148 	.globl _P
                                    149 	.globl _F1
                                    150 	.globl _OV
                                    151 	.globl _RS0
                                    152 	.globl _RS1
                                    153 	.globl _F0
                                    154 	.globl _AC
                                    155 	.globl _CY
                                    156 	.globl _UEP1_DMA_H
                                    157 	.globl _UEP1_DMA_L
                                    158 	.globl _UEP1_DMA
                                    159 	.globl _UEP0_DMA_H
                                    160 	.globl _UEP0_DMA_L
                                    161 	.globl _UEP0_DMA
                                    162 	.globl _UEP2_3_MOD
                                    163 	.globl _UEP4_1_MOD
                                    164 	.globl _UEP3_DMA_H
                                    165 	.globl _UEP3_DMA_L
                                    166 	.globl _UEP3_DMA
                                    167 	.globl _UEP2_DMA_H
                                    168 	.globl _UEP2_DMA_L
                                    169 	.globl _UEP2_DMA
                                    170 	.globl _USB_DEV_AD
                                    171 	.globl _USB_CTRL
                                    172 	.globl _USB_INT_EN
                                    173 	.globl _UEP4_T_LEN
                                    174 	.globl _UEP4_CTRL
                                    175 	.globl _UEP0_T_LEN
                                    176 	.globl _UEP0_CTRL
                                    177 	.globl _USB_RX_LEN
                                    178 	.globl _USB_MIS_ST
                                    179 	.globl _USB_INT_ST
                                    180 	.globl _USB_INT_FG
                                    181 	.globl _UEP3_T_LEN
                                    182 	.globl _UEP3_CTRL
                                    183 	.globl _UEP2_T_LEN
                                    184 	.globl _UEP2_CTRL
                                    185 	.globl _UEP1_T_LEN
                                    186 	.globl _UEP1_CTRL
                                    187 	.globl _UDEV_CTRL
                                    188 	.globl _USB_C_CTRL
                                    189 	.globl _TKEY_DATH
                                    190 	.globl _TKEY_DATL
                                    191 	.globl _TKEY_DAT
                                    192 	.globl _TKEY_CTRL
                                    193 	.globl _ADC_DATA
                                    194 	.globl _ADC_CFG
                                    195 	.globl _ADC_CTRL
                                    196 	.globl _SBAUD1
                                    197 	.globl _SBUF1
                                    198 	.globl _SCON1
                                    199 	.globl _SPI0_SETUP
                                    200 	.globl _SPI0_CK_SE
                                    201 	.globl _SPI0_CTRL
                                    202 	.globl _SPI0_DATA
                                    203 	.globl _SPI0_STAT
                                    204 	.globl _PWM_CK_SE
                                    205 	.globl _PWM_CTRL
                                    206 	.globl _PWM_DATA1
                                    207 	.globl _PWM_DATA2
                                    208 	.globl _T2CAP1H
                                    209 	.globl _T2CAP1L
                                    210 	.globl _T2CAP1
                                    211 	.globl _TH2
                                    212 	.globl _TL2
                                    213 	.globl _T2COUNT
                                    214 	.globl _RCAP2H
                                    215 	.globl _RCAP2L
                                    216 	.globl _RCAP2
                                    217 	.globl _T2MOD
                                    218 	.globl _T2CON
                                    219 	.globl _SBUF
                                    220 	.globl _SCON
                                    221 	.globl _TH1
                                    222 	.globl _TH0
                                    223 	.globl _TL1
                                    224 	.globl _TL0
                                    225 	.globl _TMOD
                                    226 	.globl _TCON
                                    227 	.globl _XBUS_AUX
                                    228 	.globl _PIN_FUNC
                                    229 	.globl _P3_DIR_PU
                                    230 	.globl _P3_MOD_OC
                                    231 	.globl _P3
                                    232 	.globl _P2
                                    233 	.globl _P1_DIR_PU
                                    234 	.globl _P1_MOD_OC
                                    235 	.globl _P1
                                    236 	.globl _ROM_CTRL
                                    237 	.globl _ROM_DATA_H
                                    238 	.globl _ROM_DATA_L
                                    239 	.globl _ROM_DATA
                                    240 	.globl _ROM_ADDR_H
                                    241 	.globl _ROM_ADDR_L
                                    242 	.globl _ROM_ADDR
                                    243 	.globl _GPIO_IE
                                    244 	.globl _IP_EX
                                    245 	.globl _IE_EX
                                    246 	.globl _IP
                                    247 	.globl _IE
                                    248 	.globl _WDOG_COUNT
                                    249 	.globl _RESET_KEEP
                                    250 	.globl _WAKE_CTRL
                                    251 	.globl _CLOCK_CFG
                                    252 	.globl _PCON
                                    253 	.globl _GLOBAL_CFG
                                    254 	.globl _SAFE_MOD
                                    255 	.globl _DPH
                                    256 	.globl _DPL
                                    257 	.globl _SP
                                    258 	.globl _B
                                    259 	.globl _ACC
                                    260 	.globl _PSW
                                    261 	.globl _wasInDownloadMode
                                    262 	.globl _state
                                    263 	.globl _count
                                    264 ;--------------------------------------------------------
                                    265 ; special function registers
                                    266 ;--------------------------------------------------------
                                    267 	.area RSEG    (ABS,DATA)
      000000                        268 	.org 0x0000
                           0000D0   269 _PSW	=	0x00d0
                           0000E0   270 _ACC	=	0x00e0
                           0000F0   271 _B	=	0x00f0
                           000081   272 _SP	=	0x0081
                           000082   273 _DPL	=	0x0082
                           000083   274 _DPH	=	0x0083
                           0000A1   275 _SAFE_MOD	=	0x00a1
                           0000B1   276 _GLOBAL_CFG	=	0x00b1
                           000087   277 _PCON	=	0x0087
                           0000B9   278 _CLOCK_CFG	=	0x00b9
                           0000A9   279 _WAKE_CTRL	=	0x00a9
                           0000FE   280 _RESET_KEEP	=	0x00fe
                           0000FF   281 _WDOG_COUNT	=	0x00ff
                           0000A8   282 _IE	=	0x00a8
                           0000B8   283 _IP	=	0x00b8
                           0000E8   284 _IE_EX	=	0x00e8
                           0000E9   285 _IP_EX	=	0x00e9
                           0000C7   286 _GPIO_IE	=	0x00c7
                           008584   287 _ROM_ADDR	=	0x8584
                           000084   288 _ROM_ADDR_L	=	0x0084
                           000085   289 _ROM_ADDR_H	=	0x0085
                           008F8E   290 _ROM_DATA	=	0x8f8e
                           00008E   291 _ROM_DATA_L	=	0x008e
                           00008F   292 _ROM_DATA_H	=	0x008f
                           000086   293 _ROM_CTRL	=	0x0086
                           000090   294 _P1	=	0x0090
                           000092   295 _P1_MOD_OC	=	0x0092
                           000093   296 _P1_DIR_PU	=	0x0093
                           0000A0   297 _P2	=	0x00a0
                           0000B0   298 _P3	=	0x00b0
                           000096   299 _P3_MOD_OC	=	0x0096
                           000097   300 _P3_DIR_PU	=	0x0097
                           0000C6   301 _PIN_FUNC	=	0x00c6
                           0000A2   302 _XBUS_AUX	=	0x00a2
                           000088   303 _TCON	=	0x0088
                           000089   304 _TMOD	=	0x0089
                           00008A   305 _TL0	=	0x008a
                           00008B   306 _TL1	=	0x008b
                           00008C   307 _TH0	=	0x008c
                           00008D   308 _TH1	=	0x008d
                           000098   309 _SCON	=	0x0098
                           000099   310 _SBUF	=	0x0099
                           0000C8   311 _T2CON	=	0x00c8
                           0000C9   312 _T2MOD	=	0x00c9
                           00CBCA   313 _RCAP2	=	0xcbca
                           0000CA   314 _RCAP2L	=	0x00ca
                           0000CB   315 _RCAP2H	=	0x00cb
                           00CDCC   316 _T2COUNT	=	0xcdcc
                           0000CC   317 _TL2	=	0x00cc
                           0000CD   318 _TH2	=	0x00cd
                           00CFCE   319 _T2CAP1	=	0xcfce
                           0000CE   320 _T2CAP1L	=	0x00ce
                           0000CF   321 _T2CAP1H	=	0x00cf
                           00009B   322 _PWM_DATA2	=	0x009b
                           00009C   323 _PWM_DATA1	=	0x009c
                           00009D   324 _PWM_CTRL	=	0x009d
                           00009E   325 _PWM_CK_SE	=	0x009e
                           0000F8   326 _SPI0_STAT	=	0x00f8
                           0000F9   327 _SPI0_DATA	=	0x00f9
                           0000FA   328 _SPI0_CTRL	=	0x00fa
                           0000FB   329 _SPI0_CK_SE	=	0x00fb
                           0000FC   330 _SPI0_SETUP	=	0x00fc
                           0000C0   331 _SCON1	=	0x00c0
                           0000C1   332 _SBUF1	=	0x00c1
                           0000C2   333 _SBAUD1	=	0x00c2
                           000080   334 _ADC_CTRL	=	0x0080
                           00009A   335 _ADC_CFG	=	0x009a
                           00009F   336 _ADC_DATA	=	0x009f
                           0000C3   337 _TKEY_CTRL	=	0x00c3
                           00C5C4   338 _TKEY_DAT	=	0xc5c4
                           0000C4   339 _TKEY_DATL	=	0x00c4
                           0000C5   340 _TKEY_DATH	=	0x00c5
                           000091   341 _USB_C_CTRL	=	0x0091
                           0000D1   342 _UDEV_CTRL	=	0x00d1
                           0000D2   343 _UEP1_CTRL	=	0x00d2
                           0000D3   344 _UEP1_T_LEN	=	0x00d3
                           0000D4   345 _UEP2_CTRL	=	0x00d4
                           0000D5   346 _UEP2_T_LEN	=	0x00d5
                           0000D6   347 _UEP3_CTRL	=	0x00d6
                           0000D7   348 _UEP3_T_LEN	=	0x00d7
                           0000D8   349 _USB_INT_FG	=	0x00d8
                           0000D9   350 _USB_INT_ST	=	0x00d9
                           0000DA   351 _USB_MIS_ST	=	0x00da
                           0000DB   352 _USB_RX_LEN	=	0x00db
                           0000DC   353 _UEP0_CTRL	=	0x00dc
                           0000DD   354 _UEP0_T_LEN	=	0x00dd
                           0000DE   355 _UEP4_CTRL	=	0x00de
                           0000DF   356 _UEP4_T_LEN	=	0x00df
                           0000E1   357 _USB_INT_EN	=	0x00e1
                           0000E2   358 _USB_CTRL	=	0x00e2
                           0000E3   359 _USB_DEV_AD	=	0x00e3
                           00E5E4   360 _UEP2_DMA	=	0xe5e4
                           0000E4   361 _UEP2_DMA_L	=	0x00e4
                           0000E5   362 _UEP2_DMA_H	=	0x00e5
                           00E7E6   363 _UEP3_DMA	=	0xe7e6
                           0000E6   364 _UEP3_DMA_L	=	0x00e6
                           0000E7   365 _UEP3_DMA_H	=	0x00e7
                           0000EA   366 _UEP4_1_MOD	=	0x00ea
                           0000EB   367 _UEP2_3_MOD	=	0x00eb
                           00EDEC   368 _UEP0_DMA	=	0xedec
                           0000EC   369 _UEP0_DMA_L	=	0x00ec
                           0000ED   370 _UEP0_DMA_H	=	0x00ed
                           00EFEE   371 _UEP1_DMA	=	0xefee
                           0000EE   372 _UEP1_DMA_L	=	0x00ee
                           0000EF   373 _UEP1_DMA_H	=	0x00ef
                                    374 ;--------------------------------------------------------
                                    375 ; special function bits
                                    376 ;--------------------------------------------------------
                                    377 	.area RSEG    (ABS,DATA)
      000000                        378 	.org 0x0000
                           0000D7   379 _CY	=	0x00d7
                           0000D6   380 _AC	=	0x00d6
                           0000D5   381 _F0	=	0x00d5
                           0000D4   382 _RS1	=	0x00d4
                           0000D3   383 _RS0	=	0x00d3
                           0000D2   384 _OV	=	0x00d2
                           0000D1   385 _F1	=	0x00d1
                           0000D0   386 _P	=	0x00d0
                           0000AF   387 _EA	=	0x00af
                           0000AE   388 _E_DIS	=	0x00ae
                           0000AD   389 _ET2	=	0x00ad
                           0000AC   390 _ES	=	0x00ac
                           0000AB   391 _ET1	=	0x00ab
                           0000AA   392 _EX1	=	0x00aa
                           0000A9   393 _ET0	=	0x00a9
                           0000A8   394 _EX0	=	0x00a8
                           0000BF   395 _PH_FLAG	=	0x00bf
                           0000BE   396 _PL_FLAG	=	0x00be
                           0000BD   397 _PT2	=	0x00bd
                           0000BC   398 _PS	=	0x00bc
                           0000BB   399 _PT1	=	0x00bb
                           0000BA   400 _PX1	=	0x00ba
                           0000B9   401 _PT0	=	0x00b9
                           0000B8   402 _PX0	=	0x00b8
                           0000EF   403 _IE_WDOG	=	0x00ef
                           0000EE   404 _IE_GPIO	=	0x00ee
                           0000ED   405 _IE_PWMX	=	0x00ed
                           0000EC   406 _IE_UART1	=	0x00ec
                           0000EB   407 _IE_ADC	=	0x00eb
                           0000EA   408 _IE_USB	=	0x00ea
                           0000E9   409 _IE_TKEY	=	0x00e9
                           0000E8   410 _IE_SPI0	=	0x00e8
                           000097   411 _SCK	=	0x0097
                           000097   412 _TXD1	=	0x0097
                           000097   413 _TIN5	=	0x0097
                           000096   414 _MISO	=	0x0096
                           000096   415 _RXD1	=	0x0096
                           000096   416 _TIN4	=	0x0096
                           000095   417 _MOSI	=	0x0095
                           000095   418 _PWM1	=	0x0095
                           000095   419 _TIN3	=	0x0095
                           000095   420 _UCC2	=	0x0095
                           000095   421 _AIN2	=	0x0095
                           000094   422 _T2_	=	0x0094
                           000094   423 _CAP1_	=	0x0094
                           000094   424 _SCS	=	0x0094
                           000094   425 _TIN2	=	0x0094
                           000094   426 _UCC1	=	0x0094
                           000094   427 _AIN1	=	0x0094
                           000093   428 _TXD_	=	0x0093
                           000092   429 _RXD_	=	0x0092
                           000091   430 _T2EX	=	0x0091
                           000091   431 _CAP2	=	0x0091
                           000091   432 _TIN1	=	0x0091
                           000091   433 _VBUS2	=	0x0091
                           000091   434 _AIN0	=	0x0091
                           000090   435 _T2	=	0x0090
                           000090   436 _CAP1	=	0x0090
                           000090   437 _TIN0	=	0x0090
                           0000B7   438 _UDM	=	0x00b7
                           0000B6   439 _UDP	=	0x00b6
                           0000B5   440 _T1	=	0x00b5
                           0000B4   441 _PWM2	=	0x00b4
                           0000B4   442 _RXD1_	=	0x00b4
                           0000B4   443 _T0	=	0x00b4
                           0000B3   444 _INT1	=	0x00b3
                           0000B2   445 _TXD1_	=	0x00b2
                           0000B2   446 _INT0	=	0x00b2
                           0000B2   447 _VBUS1	=	0x00b2
                           0000B2   448 _AIN3	=	0x00b2
                           0000B1   449 _PWM2_	=	0x00b1
                           0000B1   450 _TXD	=	0x00b1
                           0000B0   451 _PWM1_	=	0x00b0
                           0000B0   452 _RXD	=	0x00b0
                           00008F   453 _TF1	=	0x008f
                           00008E   454 _TR1	=	0x008e
                           00008D   455 _TF0	=	0x008d
                           00008C   456 _TR0	=	0x008c
                           00008B   457 _IE1	=	0x008b
                           00008A   458 _IT1	=	0x008a
                           000089   459 _IE0	=	0x0089
                           000088   460 _IT0	=	0x0088
                           00009F   461 _SM0	=	0x009f
                           00009E   462 _SM1	=	0x009e
                           00009D   463 _SM2	=	0x009d
                           00009C   464 _REN	=	0x009c
                           00009B   465 _TB8	=	0x009b
                           00009A   466 _RB8	=	0x009a
                           000099   467 _TI	=	0x0099
                           000098   468 _RI	=	0x0098
                           0000CF   469 _TF2	=	0x00cf
                           0000CF   470 _CAP1F	=	0x00cf
                           0000CE   471 _EXF2	=	0x00ce
                           0000CD   472 _RCLK	=	0x00cd
                           0000CC   473 _TCLK	=	0x00cc
                           0000CB   474 _EXEN2	=	0x00cb
                           0000CA   475 _TR2	=	0x00ca
                           0000C9   476 _C_T2	=	0x00c9
                           0000C8   477 _CP_RL2	=	0x00c8
                           0000FF   478 _S0_FST_ACT	=	0x00ff
                           0000FE   479 _S0_IF_OV	=	0x00fe
                           0000FD   480 _S0_IF_FIRST	=	0x00fd
                           0000FC   481 _S0_IF_BYTE	=	0x00fc
                           0000FB   482 _S0_FREE	=	0x00fb
                           0000FA   483 _S0_T_FIFO	=	0x00fa
                           0000F8   484 _S0_R_FIFO	=	0x00f8
                           0000C7   485 _U1SM0	=	0x00c7
                           0000C5   486 _U1SMOD	=	0x00c5
                           0000C4   487 _U1REN	=	0x00c4
                           0000C3   488 _U1TB8	=	0x00c3
                           0000C2   489 _U1RB8	=	0x00c2
                           0000C1   490 _U1TI	=	0x00c1
                           0000C0   491 _U1RI	=	0x00c0
                           000087   492 _CMPO	=	0x0087
                           000086   493 _CMP_IF	=	0x0086
                           000085   494 _ADC_IF	=	0x0085
                           000084   495 _ADC_START	=	0x0084
                           000083   496 _CMP_CHAN	=	0x0083
                           000081   497 _ADC_CHAN1	=	0x0081
                           000080   498 _ADC_CHAN0	=	0x0080
                           0000DF   499 _U_IS_NAK	=	0x00df
                           0000DE   500 _U_TOG_OK	=	0x00de
                           0000DD   501 _U_SIE_FREE	=	0x00dd
                           0000DC   502 _UIF_FIFO_OV	=	0x00dc
                           0000DB   503 _UIF_HST_SOF	=	0x00db
                           0000DA   504 _UIF_SUSPEND	=	0x00da
                           0000D9   505 _UIF_TRANSFER	=	0x00d9
                           0000D8   506 _UIF_DETECT	=	0x00d8
                           0000D8   507 _UIF_BUS_RST	=	0x00d8
                           000097   508 _bootPin	=	0x0097
                           000090   509 _resetPin	=	0x0090
                           0000B3   510 _SDA	=	0x00b3
                           0000B4   511 _SCL	=	0x00b4
                                    512 ;--------------------------------------------------------
                                    513 ; overlayable register banks
                                    514 ;--------------------------------------------------------
                                    515 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        516 	.ds 8
                                    517 ;--------------------------------------------------------
                                    518 ; overlayable bit register bank
                                    519 ;--------------------------------------------------------
                                    520 	.area BIT_BANK	(REL,OVR,DATA)
      000020                        521 bits:
      000020                        522 	.ds 1
                           008000   523 	b0 = bits[0]
                           008100   524 	b1 = bits[1]
                           008200   525 	b2 = bits[2]
                           008300   526 	b3 = bits[3]
                           008400   527 	b4 = bits[4]
                           008500   528 	b5 = bits[5]
                           008600   529 	b6 = bits[6]
                           008700   530 	b7 = bits[7]
                                    531 ;--------------------------------------------------------
                                    532 ; internal ram data
                                    533 ;--------------------------------------------------------
                                    534 	.area DSEG    (DATA)
      000008                        535 _count::
      000008                        536 	.ds 4
      00000C                        537 _state::
      00000C                        538 	.ds 1
      00000D                        539 _wasInDownloadMode::
      00000D                        540 	.ds 1
                                    541 ;--------------------------------------------------------
                                    542 ; overlayable items in internal ram 
                                    543 ;--------------------------------------------------------
                                    544 	.area	OSEG    (OVR,DATA)
      00006C                        545 _Port1Cfg_PARM_2:
      00006C                        546 	.ds 1
                                    547 ;--------------------------------------------------------
                                    548 ; Stack segment in internal ram 
                                    549 ;--------------------------------------------------------
                                    550 	.area	SSEG
      0000BD                        551 __start__stack:
      0000BD                        552 	.ds	1
                                    553 
                                    554 ;--------------------------------------------------------
                                    555 ; indirectly addressable internal ram data
                                    556 ;--------------------------------------------------------
                                    557 	.area ISEG    (DATA)
                                    558 ;--------------------------------------------------------
                                    559 ; absolute internal ram data
                                    560 ;--------------------------------------------------------
                                    561 	.area IABS    (ABS,DATA)
                                    562 	.area IABS    (ABS,DATA)
                                    563 ;--------------------------------------------------------
                                    564 ; bit data
                                    565 ;--------------------------------------------------------
                                    566 	.area BSEG    (BIT)
                                    567 ;--------------------------------------------------------
                                    568 ; paged external ram data
                                    569 ;--------------------------------------------------------
                                    570 	.area PSEG    (PAG,XDATA)
                                    571 ;--------------------------------------------------------
                                    572 ; external ram data
                                    573 ;--------------------------------------------------------
                                    574 	.area XSEG    (XDATA)
                                    575 ;--------------------------------------------------------
                                    576 ; absolute external ram data
                                    577 ;--------------------------------------------------------
                                    578 	.area XABS    (ABS,XDATA)
                                    579 ;--------------------------------------------------------
                                    580 ; external initialized ram data
                                    581 ;--------------------------------------------------------
                                    582 	.area XISEG   (XDATA)
                                    583 	.area HOME    (CODE)
                                    584 	.area GSINIT0 (CODE)
                                    585 	.area GSINIT1 (CODE)
                                    586 	.area GSINIT2 (CODE)
                                    587 	.area GSINIT3 (CODE)
                                    588 	.area GSINIT4 (CODE)
                                    589 	.area GSINIT5 (CODE)
                                    590 	.area GSINIT  (CODE)
                                    591 	.area GSFINAL (CODE)
                                    592 	.area CSEG    (CODE)
                                    593 ;--------------------------------------------------------
                                    594 ; interrupt vector 
                                    595 ;--------------------------------------------------------
                                    596 	.area HOME    (CODE)
      000000                        597 __interrupt_vect:
      000000 02 00 4B         [24]  598 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  599 	reti
      000004                        600 	.ds	7
      00000B 32               [24]  601 	reti
      00000C                        602 	.ds	7
      000013 32               [24]  603 	reti
      000014                        604 	.ds	7
      00001B 32               [24]  605 	reti
      00001C                        606 	.ds	7
      000023 02 03 9F         [24]  607 	ljmp	_UART0_RX
      000026                        608 	.ds	5
      00002B 32               [24]  609 	reti
      00002C                        610 	.ds	7
      000033 32               [24]  611 	reti
      000034                        612 	.ds	7
      00003B 32               [24]  613 	reti
      00003C                        614 	.ds	7
      000043 02 03 60         [24]  615 	ljmp	_USBInterruptEntry
                                    616 ;--------------------------------------------------------
                                    617 ; global & static initialisations
                                    618 ;--------------------------------------------------------
                                    619 	.area HOME    (CODE)
                                    620 	.area GSINIT  (CODE)
                                    621 	.area GSFINAL (CODE)
                                    622 	.area GSINIT  (CODE)
                                    623 	.globl __sdcc_gsinit_startup
                                    624 	.globl __sdcc_program_startup
                                    625 	.globl __start__stack
                                    626 	.globl __mcs51_genXINIT
                                    627 	.globl __mcs51_genXRAMCLEAR
                                    628 	.globl __mcs51_genRAMCLEAR
                                    629 ;	main.c:53: uint32_t count = 0;
      0000A4 E4               [12]  630 	clr	a
      0000A5 F5 08            [12]  631 	mov	_count,a
      0000A7 F5 09            [12]  632 	mov	(_count + 1),a
      0000A9 F5 0A            [12]  633 	mov	(_count + 2),a
      0000AB F5 0B            [12]  634 	mov	(_count + 3),a
                                    635 ;	main.c:54: uint8_t state = 0;
                                    636 ;	1-genFromRTrack replaced	mov	_state,#0x00
      0000AD F5 0C            [12]  637 	mov	_state,a
                                    638 ;	main.c:56: uint8_t wasInDownloadMode = 0;
                                    639 ;	1-genFromRTrack replaced	mov	_wasInDownloadMode,#0x00
      0000AF F5 0D            [12]  640 	mov	_wasInDownloadMode,a
                                    641 	.area GSFINAL (CODE)
      0001AD 02 00 46         [24]  642 	ljmp	__sdcc_program_startup
                                    643 ;--------------------------------------------------------
                                    644 ; Home
                                    645 ;--------------------------------------------------------
                                    646 	.area HOME    (CODE)
                                    647 	.area HOME    (CODE)
      000046                        648 __sdcc_program_startup:
      000046 02 02 43         [24]  649 	ljmp	_main
                                    650 ;	return from main will return to caller
                                    651 ;--------------------------------------------------------
                                    652 ; code
                                    653 ;--------------------------------------------------------
                                    654 	.area CSEG    (CODE)
                                    655 ;------------------------------------------------------------
                                    656 ;Allocation info for local variables in function 'Port1Cfg'
                                    657 ;------------------------------------------------------------
                                    658 ;Pin                       Allocated with name '_Port1Cfg_PARM_2'
                                    659 ;Mode                      Allocated to registers r7 
                                    660 ;------------------------------------------------------------
                                    661 ;	main.c:19: void Port1Cfg(uint8_t Mode,uint8_t Pin)
                                    662 ;	-----------------------------------------
                                    663 ;	 function Port1Cfg
                                    664 ;	-----------------------------------------
      0001B0                        665 _Port1Cfg:
                           000007   666 	ar7 = 0x07
                           000006   667 	ar6 = 0x06
                           000005   668 	ar5 = 0x05
                           000004   669 	ar4 = 0x04
                           000003   670 	ar3 = 0x03
                           000002   671 	ar2 = 0x02
                           000001   672 	ar1 = 0x01
                           000000   673 	ar0 = 0x00
                                    674 ;	main.c:21: switch(Mode){
      0001B0 E5 82            [12]  675 	mov	a,dpl
      0001B2 FF               [12]  676 	mov	r7,a
      0001B3 24 FC            [12]  677 	add	a,#0xff - 0x03
      0001B5 50 01            [24]  678 	jnc	00113$
      0001B7 22               [24]  679 	ret
      0001B8                        680 00113$:
      0001B8 EF               [12]  681 	mov	a,r7
      0001B9 2F               [12]  682 	add	a,r7
                                    683 ;	main.c:22: case 0:
      0001BA 90 01 BE         [24]  684 	mov	dptr,#00114$
      0001BD 73               [24]  685 	jmp	@a+dptr
      0001BE                        686 00114$:
      0001BE 80 06            [24]  687 	sjmp	00101$
      0001C0 80 21            [24]  688 	sjmp	00102$
      0001C2 80 3C            [24]  689 	sjmp	00103$
      0001C4 80 57            [24]  690 	sjmp	00104$
      0001C6                        691 00101$:
                                    692 ;	main.c:23: P1_MOD_OC = P1_MOD_OC & ~(1<<Pin);
      0001C6 AF 6C            [24]  693 	mov	r7,_Port1Cfg_PARM_2
      0001C8 8F F0            [24]  694 	mov	b,r7
      0001CA 05 F0            [12]  695 	inc	b
      0001CC 74 01            [12]  696 	mov	a,#0x01
      0001CE 80 02            [24]  697 	sjmp	00117$
      0001D0                        698 00115$:
      0001D0 25 E0            [12]  699 	add	a,acc
      0001D2                        700 00117$:
      0001D2 D5 F0 FB         [24]  701 	djnz	b,00115$
      0001D5 F4               [12]  702 	cpl	a
      0001D6 FF               [12]  703 	mov	r7,a
      0001D7 AE 92            [24]  704 	mov	r6,_P1_MOD_OC
      0001D9 5E               [12]  705 	anl	a,r6
      0001DA F5 92            [12]  706 	mov	_P1_MOD_OC,a
                                    707 ;	main.c:24: P1_DIR_PU = P1_DIR_PU &	~(1<<Pin);	
      0001DC AE 93            [24]  708 	mov	r6,_P1_DIR_PU
      0001DE EF               [12]  709 	mov	a,r7
      0001DF 5E               [12]  710 	anl	a,r6
      0001E0 F5 93            [12]  711 	mov	_P1_DIR_PU,a
                                    712 ;	main.c:25: break;
                                    713 ;	main.c:26: case 1:
      0001E2 22               [24]  714 	ret
      0001E3                        715 00102$:
                                    716 ;	main.c:27: P1_MOD_OC = P1_MOD_OC & ~(1<<Pin);
      0001E3 AF 6C            [24]  717 	mov	r7,_Port1Cfg_PARM_2
      0001E5 8F F0            [24]  718 	mov	b,r7
      0001E7 05 F0            [12]  719 	inc	b
      0001E9 74 01            [12]  720 	mov	a,#0x01
      0001EB 80 02            [24]  721 	sjmp	00120$
      0001ED                        722 00118$:
      0001ED 25 E0            [12]  723 	add	a,acc
      0001EF                        724 00120$:
      0001EF D5 F0 FB         [24]  725 	djnz	b,00118$
      0001F2 FF               [12]  726 	mov	r7,a
      0001F3 F4               [12]  727 	cpl	a
      0001F4 AD 92            [24]  728 	mov	r5,_P1_MOD_OC
      0001F6 5D               [12]  729 	anl	a,r5
      0001F7 F5 92            [12]  730 	mov	_P1_MOD_OC,a
                                    731 ;	main.c:28: P1_DIR_PU = P1_DIR_PU |	(1<<Pin);				
      0001F9 AE 93            [24]  732 	mov	r6,_P1_DIR_PU
      0001FB EF               [12]  733 	mov	a,r7
      0001FC 4E               [12]  734 	orl	a,r6
      0001FD F5 93            [12]  735 	mov	_P1_DIR_PU,a
                                    736 ;	main.c:29: break;		
                                    737 ;	main.c:30: case 2:
      0001FF 22               [24]  738 	ret
      000200                        739 00103$:
                                    740 ;	main.c:31: P1_MOD_OC = P1_MOD_OC | (1<<Pin);
      000200 AF 6C            [24]  741 	mov	r7,_Port1Cfg_PARM_2
      000202 8F F0            [24]  742 	mov	b,r7
      000204 05 F0            [12]  743 	inc	b
      000206 74 01            [12]  744 	mov	a,#0x01
      000208 80 02            [24]  745 	sjmp	00123$
      00020A                        746 00121$:
      00020A 25 E0            [12]  747 	add	a,acc
      00020C                        748 00123$:
      00020C D5 F0 FB         [24]  749 	djnz	b,00121$
      00020F FF               [12]  750 	mov	r7,a
      000210 AE 92            [24]  751 	mov	r6,_P1_MOD_OC
      000212 4E               [12]  752 	orl	a,r6
      000213 F5 92            [12]  753 	mov	_P1_MOD_OC,a
                                    754 ;	main.c:32: P1_DIR_PU = P1_DIR_PU &	~(1<<Pin);				
      000215 EF               [12]  755 	mov	a,r7
      000216 F4               [12]  756 	cpl	a
      000217 AE 93            [24]  757 	mov	r6,_P1_DIR_PU
      000219 5E               [12]  758 	anl	a,r6
      00021A F5 93            [12]  759 	mov	_P1_DIR_PU,a
                                    760 ;	main.c:33: break;		
                                    761 ;	main.c:34: case 3:
      00021C 22               [24]  762 	ret
      00021D                        763 00104$:
                                    764 ;	main.c:35: P1_MOD_OC = P1_MOD_OC | (1<<Pin);
      00021D AF 6C            [24]  765 	mov	r7,_Port1Cfg_PARM_2
      00021F 8F F0            [24]  766 	mov	b,r7
      000221 05 F0            [12]  767 	inc	b
      000223 74 01            [12]  768 	mov	a,#0x01
      000225 80 02            [24]  769 	sjmp	00126$
      000227                        770 00124$:
      000227 25 E0            [12]  771 	add	a,acc
      000229                        772 00126$:
      000229 D5 F0 FB         [24]  773 	djnz	b,00124$
      00022C FF               [12]  774 	mov	r7,a
      00022D AE 92            [24]  775 	mov	r6,_P1_MOD_OC
      00022F 4E               [12]  776 	orl	a,r6
      000230 F5 92            [12]  777 	mov	_P1_MOD_OC,a
                                    778 ;	main.c:36: P1_DIR_PU = P1_DIR_PU |	(1<<Pin);			
      000232 AE 93            [24]  779 	mov	r6,_P1_DIR_PU
      000234 EF               [12]  780 	mov	a,r7
      000235 4E               [12]  781 	orl	a,r6
      000236 F5 93            [12]  782 	mov	_P1_DIR_PU,a
                                    783 ;	main.c:40: }
                                    784 ;	main.c:41: }
      000238 22               [24]  785 	ret
                                    786 ;------------------------------------------------------------
                                    787 ;Allocation info for local variables in function 'TypeC_UPF_PDInit'
                                    788 ;------------------------------------------------------------
                                    789 ;	main.c:43: void TypeC_UPF_PDInit( void )
                                    790 ;	-----------------------------------------
                                    791 ;	 function TypeC_UPF_PDInit
                                    792 ;	-----------------------------------------
      000239                        793 _TypeC_UPF_PDInit:
                                    794 ;	main.c:45: P1_MOD_OC &= ~(bUCC2|bUCC1);                                                   
      000239 53 92 CF         [24]  795 	anl	_P1_MOD_OC,#0xcf
                                    796 ;	main.c:46: P1_DIR_PU &= ~(bUCC2|bUCC1);                                                   //UCC1 UCC2 设置浮空输入
      00023C 53 93 CF         [24]  797 	anl	_P1_DIR_PU,#0xcf
                                    798 ;	main.c:47: UPF_DisableRd(1);                                                              //开启UCC下拉电阻
      00023F 43 91 44         [24]  799 	orl	_USB_C_CTRL,#0x44
                                    800 ;	main.c:51: }
      000242 22               [24]  801 	ret
                                    802 ;------------------------------------------------------------
                                    803 ;Allocation info for local variables in function 'main'
                                    804 ;------------------------------------------------------------
                                    805 ;	main.c:58: void main(void) {
                                    806 ;	-----------------------------------------
                                    807 ;	 function main
                                    808 ;	-----------------------------------------
      000243                        809 _main:
                                    810 ;	main.c:59: TypeC_UPF_PDInit();
      000243 12 02 39         [24]  811 	lcall	_TypeC_UPF_PDInit
                                    812 ;	main.c:60: CDC_InitBaud();
      000246 12 04 D2         [24]  813 	lcall	_CDC_InitBaud
                                    814 ;	main.c:61: CH554_Init();
      000249 12 04 7E         [24]  815 	lcall	_CH554_Init
                                    816 ;	main.c:63: Port1Cfg(3, 0);
      00024C 75 6C 00         [24]  817 	mov	_Port1Cfg_PARM_2,#0x00
      00024F 75 82 03         [24]  818 	mov	dpl,#0x03
      000252 12 01 B0         [24]  819 	lcall	_Port1Cfg
                                    820 ;	main.c:64: Port1Cfg(3, 1);
      000255 75 6C 01         [24]  821 	mov	_Port1Cfg_PARM_2,#0x01
      000258 75 82 03         [24]  822 	mov	dpl,#0x03
      00025B 12 01 B0         [24]  823 	lcall	_Port1Cfg
                                    824 ;	main.c:66: SDA = 1;
                                    825 ;	assignBit
      00025E D2 B3            [12]  826 	setb	_SDA
                                    827 ;	main.c:67: SCL = 1;
                                    828 ;	assignBit
      000260 D2 B4            [12]  829 	setb	_SCL
                                    830 ;	main.c:69: P3_MOD_OC = P3_MOD_OC | (1<<3);
      000262 43 96 08         [24]  831 	orl	_P3_MOD_OC,#0x08
                                    832 ;	main.c:70: P3_DIR_PU = P3_DIR_PU | (1<<3);
      000265 43 97 08         [24]  833 	orl	_P3_DIR_PU,#0x08
                                    834 ;	main.c:72: P3_MOD_OC = P3_MOD_OC | (1<<4);
      000268 43 96 10         [24]  835 	orl	_P3_MOD_OC,#0x10
                                    836 ;	main.c:73: P3_DIR_PU = P3_DIR_PU | (1<<4);	
      00026B 43 97 10         [24]  837 	orl	_P3_DIR_PU,#0x10
                                    838 ;	main.c:75: bootPin = 1;
                                    839 ;	assignBit
      00026E D2 97            [12]  840 	setb	_bootPin
                                    841 ;	main.c:76: resetPin = 1;
                                    842 ;	assignBit
      000270 D2 90            [12]  843 	setb	_resetPin
                                    844 ;	main.c:80: while(1) {
      000272                        845 00121$:
                                    846 ;	main.c:81: if(RI != 0){
                                    847 ;	main.c:82: RI = 0;
                                    848 ;	assignBit
      000272 10 98 02         [24]  849 	jbc	_RI,00177$
      000275 80 06            [24]  850 	sjmp	00102$
      000277                        851 00177$:
                                    852 ;	main.c:83: CDC_PutChar(SBUF);
      000277 85 99 82         [24]  853 	mov	dpl,_SBUF
      00027A 12 06 0F         [24]  854 	lcall	_CDC_PutChar
      00027D                        855 00102$:
                                    856 ;	main.c:85: CDC_USB_Poll();
      00027D 12 06 6D         [24]  857 	lcall	_CDC_USB_Poll
                                    858 ;	main.c:87: CDC_UART_Poll();
      000280 12 07 A4         [24]  859 	lcall	_CDC_UART_Poll
                                    860 ;	main.c:88: ++count;
      000283 05 08            [12]  861 	inc	_count
      000285 E4               [12]  862 	clr	a
      000286 B5 08 0C         [24]  863 	cjne	a,_count,00178$
      000289 05 09            [12]  864 	inc	(_count + 1)
      00028B B5 09 07         [24]  865 	cjne	a,(_count + 1),00178$
      00028E 05 0A            [12]  866 	inc	(_count + 2)
      000290 B5 0A 02         [24]  867 	cjne	a,(_count + 2),00178$
      000293 05 0B            [12]  868 	inc	(_count + 3)
      000295                        869 00178$:
                                    870 ;	main.c:89: if(RI != 0){
                                    871 ;	main.c:90: RI = 0;
                                    872 ;	assignBit
      000295 10 98 02         [24]  873 	jbc	_RI,00179$
      000298 80 06            [24]  874 	sjmp	00104$
      00029A                        875 00179$:
                                    876 ;	main.c:91: CDC_PutChar(SBUF);
      00029A 85 99 82         [24]  877 	mov	dpl,_SBUF
      00029D 12 06 0F         [24]  878 	lcall	_CDC_PutChar
      0002A0                        879 00104$:
                                    880 ;	main.c:95: if(resetToBoot == 1 && state == 0){
      0002A0 74 01            [12]  881 	mov	a,#0x01
      0002A2 B5 2F 14         [24]  882 	cjne	a,_resetToBoot,00106$
      0002A5 E5 0C            [12]  883 	mov	a,_state
      0002A7 70 10            [24]  884 	jnz	00106$
                                    885 ;	main.c:96: resetPin = 0;
                                    886 ;	assignBit
      0002A9 C2 90            [12]  887 	clr	_resetPin
                                    888 ;	main.c:97: bootPin = 0;
                                    889 ;	assignBit
      0002AB C2 97            [12]  890 	clr	_bootPin
                                    891 ;	main.c:98: state = 1;
      0002AD 75 0C 01         [24]  892 	mov	_state,#0x01
                                    893 ;	main.c:99: count = 0;
      0002B0 E4               [12]  894 	clr	a
      0002B1 F5 08            [12]  895 	mov	_count,a
      0002B3 F5 09            [12]  896 	mov	(_count + 1),a
      0002B5 F5 0A            [12]  897 	mov	(_count + 2),a
      0002B7 F5 0B            [12]  898 	mov	(_count + 3),a
      0002B9                        899 00106$:
                                    900 ;	main.c:102: if(state == 1 && count == 100000){
      0002B9 74 01            [12]  901 	mov	a,#0x01
      0002BB B5 0C 25         [24]  902 	cjne	a,_state,00109$
      0002BE 74 A0            [12]  903 	mov	a,#0xa0
      0002C0 B5 08 10         [24]  904 	cjne	a,_count,00185$
      0002C3 74 86            [12]  905 	mov	a,#0x86
      0002C5 B5 09 0B         [24]  906 	cjne	a,(_count + 1),00185$
      0002C8 74 01            [12]  907 	mov	a,#0x01
      0002CA B5 0A 06         [24]  908 	cjne	a,(_count + 2),00185$
      0002CD 14               [12]  909 	dec	a
      0002CE B5 0B 02         [24]  910 	cjne	a,(_count + 3),00185$
      0002D1 80 02            [24]  911 	sjmp	00186$
      0002D3                        912 00185$:
      0002D3 80 0E            [24]  913 	sjmp	00109$
      0002D5                        914 00186$:
                                    915 ;	main.c:103: resetPin = 1;
                                    916 ;	assignBit
      0002D5 D2 90            [12]  917 	setb	_resetPin
                                    918 ;	main.c:104: state = 2;
      0002D7 75 0C 02         [24]  919 	mov	_state,#0x02
                                    920 ;	main.c:105: count = 0;
      0002DA E4               [12]  921 	clr	a
      0002DB F5 08            [12]  922 	mov	_count,a
      0002DD F5 09            [12]  923 	mov	(_count + 1),a
      0002DF F5 0A            [12]  924 	mov	(_count + 2),a
      0002E1 F5 0B            [12]  925 	mov	(_count + 3),a
      0002E3                        926 00109$:
                                    927 ;	main.c:108: if(state == 3 && count == 40000){
      0002E3 74 03            [12]  928 	mov	a,#0x03
      0002E5 B5 0C 22         [24]  929 	cjne	a,_state,00112$
      0002E8 74 40            [12]  930 	mov	a,#0x40
      0002EA B5 08 0E         [24]  931 	cjne	a,_count,00189$
      0002ED 74 9C            [12]  932 	mov	a,#0x9c
      0002EF B5 09 09         [24]  933 	cjne	a,(_count + 1),00189$
      0002F2 E4               [12]  934 	clr	a
      0002F3 B5 0A 05         [24]  935 	cjne	a,(_count + 2),00189$
      0002F6 B5 0B 02         [24]  936 	cjne	a,(_count + 3),00189$
      0002F9 80 02            [24]  937 	sjmp	00190$
      0002FB                        938 00189$:
      0002FB 80 0D            [24]  939 	sjmp	00112$
      0002FD                        940 00190$:
                                    941 ;	main.c:109: resetPin = 1;
                                    942 ;	assignBit
      0002FD D2 90            [12]  943 	setb	_resetPin
                                    944 ;	main.c:110: state = 0;
                                    945 ;	main.c:111: count = 0;
      0002FF E4               [12]  946 	clr	a
      000300 F5 0C            [12]  947 	mov	_state,a
      000302 F5 08            [12]  948 	mov	_count,a
      000304 F5 09            [12]  949 	mov	(_count + 1),a
      000306 F5 0A            [12]  950 	mov	(_count + 2),a
      000308 F5 0B            [12]  951 	mov	(_count + 3),a
      00030A                        952 00112$:
                                    953 ;	main.c:114: if(state == 4 && count == 40000){
      00030A 74 04            [12]  954 	mov	a,#0x04
      00030C B5 0C 23         [24]  955 	cjne	a,_state,00115$
      00030F 74 40            [12]  956 	mov	a,#0x40
      000311 B5 08 0E         [24]  957 	cjne	a,_count,00193$
      000314 74 9C            [12]  958 	mov	a,#0x9c
      000316 B5 09 09         [24]  959 	cjne	a,(_count + 1),00193$
      000319 E4               [12]  960 	clr	a
      00031A B5 0A 05         [24]  961 	cjne	a,(_count + 2),00193$
      00031D B5 0B 02         [24]  962 	cjne	a,(_count + 3),00193$
      000320 80 02            [24]  963 	sjmp	00194$
      000322                        964 00193$:
      000322 80 0E            [24]  965 	sjmp	00115$
      000324                        966 00194$:
                                    967 ;	main.c:115: resetPin = 0;
                                    968 ;	assignBit
      000324 C2 90            [12]  969 	clr	_resetPin
                                    970 ;	main.c:116: state = 3;
      000326 75 0C 03         [24]  971 	mov	_state,#0x03
                                    972 ;	main.c:117: count = 0;
      000329 E4               [12]  973 	clr	a
      00032A F5 08            [12]  974 	mov	_count,a
      00032C F5 09            [12]  975 	mov	(_count + 1),a
      00032E F5 0A            [12]  976 	mov	(_count + 2),a
      000330 F5 0B            [12]  977 	mov	(_count + 3),a
      000332                        978 00115$:
                                    979 ;	main.c:120: if(state == 2 && count == 800000){
      000332 74 02            [12]  980 	mov	a,#0x02
      000334 B5 0C 02         [24]  981 	cjne	a,_state,00195$
      000337 80 03            [24]  982 	sjmp	00196$
      000339                        983 00195$:
      000339 02 02 72         [24]  984 	ljmp	00121$
      00033C                        985 00196$:
      00033C E4               [12]  986 	clr	a
      00033D B5 08 0F         [24]  987 	cjne	a,_count,00197$
      000340 B5 0B 0C         [24]  988 	cjne	a,(_count + 3),00197$
      000343 74 35            [12]  989 	mov	a,#0x35
      000345 B5 09 07         [24]  990 	cjne	a,(_count + 1),00197$
      000348 74 0C            [12]  991 	mov	a,#0x0c
      00034A B5 0A 02         [24]  992 	cjne	a,(_count + 2),00197$
      00034D 80 03            [24]  993 	sjmp	00198$
      00034F                        994 00197$:
      00034F 02 02 72         [24]  995 	ljmp	00121$
      000352                        996 00198$:
                                    997 ;	main.c:121: bootPin = 1;
                                    998 ;	assignBit
      000352 D2 97            [12]  999 	setb	_bootPin
                                   1000 ;	main.c:122: state = 0;
      000354 75 0C 00         [24] 1001 	mov	_state,#0x00
                                   1002 ;	main.c:123: wasInDownloadMode = 1;
      000357 75 0D 01         [24] 1003 	mov	_wasInDownloadMode,#0x01
                                   1004 ;	main.c:124: resetToBoot = 0;
      00035A 75 2F 00         [24] 1005 	mov	_resetToBoot,#0x00
                                   1006 ;	main.c:128: }
      00035D 02 02 72         [24] 1007 	ljmp	00121$
                                   1008 ;------------------------------------------------------------
                                   1009 ;Allocation info for local variables in function 'USBInterruptEntry'
                                   1010 ;------------------------------------------------------------
                                   1011 ;	main.c:136: void USBInterruptEntry(void) interrupt INT_NO_USB {
                                   1012 ;	-----------------------------------------
                                   1013 ;	 function USBInterruptEntry
                                   1014 ;	-----------------------------------------
      000360                       1015 _USBInterruptEntry:
      000360 C0 20            [24] 1016 	push	bits
      000362 C0 E0            [24] 1017 	push	acc
      000364 C0 F0            [24] 1018 	push	b
      000366 C0 82            [24] 1019 	push	dpl
      000368 C0 83            [24] 1020 	push	dph
      00036A C0 07            [24] 1021 	push	(0+7)
      00036C C0 06            [24] 1022 	push	(0+6)
      00036E C0 05            [24] 1023 	push	(0+5)
      000370 C0 04            [24] 1024 	push	(0+4)
      000372 C0 03            [24] 1025 	push	(0+3)
      000374 C0 02            [24] 1026 	push	(0+2)
      000376 C0 01            [24] 1027 	push	(0+1)
      000378 C0 00            [24] 1028 	push	(0+0)
      00037A C0 D0            [24] 1029 	push	psw
      00037C 75 D0 00         [24] 1030 	mov	psw,#0x00
                                   1031 ;	main.c:137: USBInterrupt();
      00037F 12 0C 04         [24] 1032 	lcall	_USBInterrupt
                                   1033 ;	main.c:138: }
      000382 D0 D0            [24] 1034 	pop	psw
      000384 D0 00            [24] 1035 	pop	(0+0)
      000386 D0 01            [24] 1036 	pop	(0+1)
      000388 D0 02            [24] 1037 	pop	(0+2)
      00038A D0 03            [24] 1038 	pop	(0+3)
      00038C D0 04            [24] 1039 	pop	(0+4)
      00038E D0 05            [24] 1040 	pop	(0+5)
      000390 D0 06            [24] 1041 	pop	(0+6)
      000392 D0 07            [24] 1042 	pop	(0+7)
      000394 D0 83            [24] 1043 	pop	dph
      000396 D0 82            [24] 1044 	pop	dpl
      000398 D0 F0            [24] 1045 	pop	b
      00039A D0 E0            [24] 1046 	pop	acc
      00039C D0 20            [24] 1047 	pop	bits
      00039E 32               [24] 1048 	reti
                                   1049 ;------------------------------------------------------------
                                   1050 ;Allocation info for local variables in function 'UART0_RX'
                                   1051 ;------------------------------------------------------------
                                   1052 ;	main.c:140: void UART0_RX(void) interrupt INT_NO_UART0 {
                                   1053 ;	-----------------------------------------
                                   1054 ;	 function UART0_RX
                                   1055 ;	-----------------------------------------
      00039F                       1056 _UART0_RX:
      00039F C0 20            [24] 1057 	push	bits
      0003A1 C0 E0            [24] 1058 	push	acc
      0003A3 C0 F0            [24] 1059 	push	b
      0003A5 C0 82            [24] 1060 	push	dpl
      0003A7 C0 83            [24] 1061 	push	dph
      0003A9 C0 07            [24] 1062 	push	(0+7)
      0003AB C0 06            [24] 1063 	push	(0+6)
      0003AD C0 05            [24] 1064 	push	(0+5)
      0003AF C0 04            [24] 1065 	push	(0+4)
      0003B1 C0 03            [24] 1066 	push	(0+3)
      0003B3 C0 02            [24] 1067 	push	(0+2)
      0003B5 C0 01            [24] 1068 	push	(0+1)
      0003B7 C0 00            [24] 1069 	push	(0+0)
      0003B9 C0 D0            [24] 1070 	push	psw
      0003BB 75 D0 00         [24] 1071 	mov	psw,#0x00
                                   1072 ;	main.c:141: USBInterrupt();
      0003BE 12 0C 04         [24] 1073 	lcall	_USBInterrupt
                                   1074 ;	main.c:142: }
      0003C1 D0 D0            [24] 1075 	pop	psw
      0003C3 D0 00            [24] 1076 	pop	(0+0)
      0003C5 D0 01            [24] 1077 	pop	(0+1)
      0003C7 D0 02            [24] 1078 	pop	(0+2)
      0003C9 D0 03            [24] 1079 	pop	(0+3)
      0003CB D0 04            [24] 1080 	pop	(0+4)
      0003CD D0 05            [24] 1081 	pop	(0+5)
      0003CF D0 06            [24] 1082 	pop	(0+6)
      0003D1 D0 07            [24] 1083 	pop	(0+7)
      0003D3 D0 83            [24] 1084 	pop	dph
      0003D5 D0 82            [24] 1085 	pop	dpl
      0003D7 D0 F0            [24] 1086 	pop	b
      0003D9 D0 E0            [24] 1087 	pop	acc
      0003DB D0 20            [24] 1088 	pop	bits
      0003DD 32               [24] 1089 	reti
                                   1090 	.area CSEG    (CODE)
                                   1091 	.area CONST   (CODE)
                                   1092 	.area XINIT   (CODE)
                                   1093 	.area CABS    (ABS,CODE)
