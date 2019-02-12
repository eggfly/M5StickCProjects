                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module ch554_conf
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _UART0_Init
                                     12 	.globl _USBDevice_Init
                                     13 	.globl _ConfigSysClock
                                     14 	.globl _mDelaymS
                                     15 	.globl _UIF_BUS_RST
                                     16 	.globl _UIF_DETECT
                                     17 	.globl _UIF_TRANSFER
                                     18 	.globl _UIF_SUSPEND
                                     19 	.globl _UIF_HST_SOF
                                     20 	.globl _UIF_FIFO_OV
                                     21 	.globl _U_SIE_FREE
                                     22 	.globl _U_TOG_OK
                                     23 	.globl _U_IS_NAK
                                     24 	.globl _ADC_CHAN0
                                     25 	.globl _ADC_CHAN1
                                     26 	.globl _CMP_CHAN
                                     27 	.globl _ADC_START
                                     28 	.globl _ADC_IF
                                     29 	.globl _CMP_IF
                                     30 	.globl _CMPO
                                     31 	.globl _U1RI
                                     32 	.globl _U1TI
                                     33 	.globl _U1RB8
                                     34 	.globl _U1TB8
                                     35 	.globl _U1REN
                                     36 	.globl _U1SMOD
                                     37 	.globl _U1SM0
                                     38 	.globl _S0_R_FIFO
                                     39 	.globl _S0_T_FIFO
                                     40 	.globl _S0_FREE
                                     41 	.globl _S0_IF_BYTE
                                     42 	.globl _S0_IF_FIRST
                                     43 	.globl _S0_IF_OV
                                     44 	.globl _S0_FST_ACT
                                     45 	.globl _CP_RL2
                                     46 	.globl _C_T2
                                     47 	.globl _TR2
                                     48 	.globl _EXEN2
                                     49 	.globl _TCLK
                                     50 	.globl _RCLK
                                     51 	.globl _EXF2
                                     52 	.globl _CAP1F
                                     53 	.globl _TF2
                                     54 	.globl _RI
                                     55 	.globl _TI
                                     56 	.globl _RB8
                                     57 	.globl _TB8
                                     58 	.globl _REN
                                     59 	.globl _SM2
                                     60 	.globl _SM1
                                     61 	.globl _SM0
                                     62 	.globl _IT0
                                     63 	.globl _IE0
                                     64 	.globl _IT1
                                     65 	.globl _IE1
                                     66 	.globl _TR0
                                     67 	.globl _TF0
                                     68 	.globl _TR1
                                     69 	.globl _TF1
                                     70 	.globl _RXD
                                     71 	.globl _PWM1_
                                     72 	.globl _TXD
                                     73 	.globl _PWM2_
                                     74 	.globl _AIN3
                                     75 	.globl _VBUS1
                                     76 	.globl _INT0
                                     77 	.globl _TXD1_
                                     78 	.globl _INT1
                                     79 	.globl _T0
                                     80 	.globl _RXD1_
                                     81 	.globl _PWM2
                                     82 	.globl _T1
                                     83 	.globl _UDP
                                     84 	.globl _UDM
                                     85 	.globl _TIN0
                                     86 	.globl _CAP1
                                     87 	.globl _T2
                                     88 	.globl _AIN0
                                     89 	.globl _VBUS2
                                     90 	.globl _TIN1
                                     91 	.globl _CAP2
                                     92 	.globl _T2EX
                                     93 	.globl _RXD_
                                     94 	.globl _TXD_
                                     95 	.globl _AIN1
                                     96 	.globl _UCC1
                                     97 	.globl _TIN2
                                     98 	.globl _SCS
                                     99 	.globl _CAP1_
                                    100 	.globl _T2_
                                    101 	.globl _AIN2
                                    102 	.globl _UCC2
                                    103 	.globl _TIN3
                                    104 	.globl _PWM1
                                    105 	.globl _MOSI
                                    106 	.globl _TIN4
                                    107 	.globl _RXD1
                                    108 	.globl _MISO
                                    109 	.globl _TIN5
                                    110 	.globl _TXD1
                                    111 	.globl _SCK
                                    112 	.globl _IE_SPI0
                                    113 	.globl _IE_TKEY
                                    114 	.globl _IE_USB
                                    115 	.globl _IE_ADC
                                    116 	.globl _IE_UART1
                                    117 	.globl _IE_PWMX
                                    118 	.globl _IE_GPIO
                                    119 	.globl _IE_WDOG
                                    120 	.globl _PX0
                                    121 	.globl _PT0
                                    122 	.globl _PX1
                                    123 	.globl _PT1
                                    124 	.globl _PS
                                    125 	.globl _PT2
                                    126 	.globl _PL_FLAG
                                    127 	.globl _PH_FLAG
                                    128 	.globl _EX0
                                    129 	.globl _ET0
                                    130 	.globl _EX1
                                    131 	.globl _ET1
                                    132 	.globl _ES
                                    133 	.globl _ET2
                                    134 	.globl _E_DIS
                                    135 	.globl _EA
                                    136 	.globl _P
                                    137 	.globl _F1
                                    138 	.globl _OV
                                    139 	.globl _RS0
                                    140 	.globl _RS1
                                    141 	.globl _F0
                                    142 	.globl _AC
                                    143 	.globl _CY
                                    144 	.globl _UEP1_DMA_H
                                    145 	.globl _UEP1_DMA_L
                                    146 	.globl _UEP1_DMA
                                    147 	.globl _UEP0_DMA_H
                                    148 	.globl _UEP0_DMA_L
                                    149 	.globl _UEP0_DMA
                                    150 	.globl _UEP2_3_MOD
                                    151 	.globl _UEP4_1_MOD
                                    152 	.globl _UEP3_DMA_H
                                    153 	.globl _UEP3_DMA_L
                                    154 	.globl _UEP3_DMA
                                    155 	.globl _UEP2_DMA_H
                                    156 	.globl _UEP2_DMA_L
                                    157 	.globl _UEP2_DMA
                                    158 	.globl _USB_DEV_AD
                                    159 	.globl _USB_CTRL
                                    160 	.globl _USB_INT_EN
                                    161 	.globl _UEP4_T_LEN
                                    162 	.globl _UEP4_CTRL
                                    163 	.globl _UEP0_T_LEN
                                    164 	.globl _UEP0_CTRL
                                    165 	.globl _USB_RX_LEN
                                    166 	.globl _USB_MIS_ST
                                    167 	.globl _USB_INT_ST
                                    168 	.globl _USB_INT_FG
                                    169 	.globl _UEP3_T_LEN
                                    170 	.globl _UEP3_CTRL
                                    171 	.globl _UEP2_T_LEN
                                    172 	.globl _UEP2_CTRL
                                    173 	.globl _UEP1_T_LEN
                                    174 	.globl _UEP1_CTRL
                                    175 	.globl _UDEV_CTRL
                                    176 	.globl _USB_C_CTRL
                                    177 	.globl _TKEY_DATH
                                    178 	.globl _TKEY_DATL
                                    179 	.globl _TKEY_DAT
                                    180 	.globl _TKEY_CTRL
                                    181 	.globl _ADC_DATA
                                    182 	.globl _ADC_CFG
                                    183 	.globl _ADC_CTRL
                                    184 	.globl _SBAUD1
                                    185 	.globl _SBUF1
                                    186 	.globl _SCON1
                                    187 	.globl _SPI0_SETUP
                                    188 	.globl _SPI0_CK_SE
                                    189 	.globl _SPI0_CTRL
                                    190 	.globl _SPI0_DATA
                                    191 	.globl _SPI0_STAT
                                    192 	.globl _PWM_CK_SE
                                    193 	.globl _PWM_CTRL
                                    194 	.globl _PWM_DATA1
                                    195 	.globl _PWM_DATA2
                                    196 	.globl _T2CAP1H
                                    197 	.globl _T2CAP1L
                                    198 	.globl _T2CAP1
                                    199 	.globl _TH2
                                    200 	.globl _TL2
                                    201 	.globl _T2COUNT
                                    202 	.globl _RCAP2H
                                    203 	.globl _RCAP2L
                                    204 	.globl _RCAP2
                                    205 	.globl _T2MOD
                                    206 	.globl _T2CON
                                    207 	.globl _SBUF
                                    208 	.globl _SCON
                                    209 	.globl _TH1
                                    210 	.globl _TH0
                                    211 	.globl _TL1
                                    212 	.globl _TL0
                                    213 	.globl _TMOD
                                    214 	.globl _TCON
                                    215 	.globl _XBUS_AUX
                                    216 	.globl _PIN_FUNC
                                    217 	.globl _P3_DIR_PU
                                    218 	.globl _P3_MOD_OC
                                    219 	.globl _P3
                                    220 	.globl _P2
                                    221 	.globl _P1_DIR_PU
                                    222 	.globl _P1_MOD_OC
                                    223 	.globl _P1
                                    224 	.globl _ROM_CTRL
                                    225 	.globl _ROM_DATA_H
                                    226 	.globl _ROM_DATA_L
                                    227 	.globl _ROM_DATA
                                    228 	.globl _ROM_ADDR_H
                                    229 	.globl _ROM_ADDR_L
                                    230 	.globl _ROM_ADDR
                                    231 	.globl _GPIO_IE
                                    232 	.globl _IP_EX
                                    233 	.globl _IE_EX
                                    234 	.globl _IP
                                    235 	.globl _IE
                                    236 	.globl _WDOG_COUNT
                                    237 	.globl _RESET_KEEP
                                    238 	.globl _WAKE_CTRL
                                    239 	.globl _CLOCK_CFG
                                    240 	.globl _PCON
                                    241 	.globl _GLOBAL_CFG
                                    242 	.globl _SAFE_MOD
                                    243 	.globl _DPH
                                    244 	.globl _DPL
                                    245 	.globl _SP
                                    246 	.globl _B
                                    247 	.globl _ACC
                                    248 	.globl _PSW
                                    249 	.globl _CH554_Init
                                    250 	.globl _CH554UART0RcvByte
                                    251 	.globl _CH554UART0SendByte
                                    252 ;--------------------------------------------------------
                                    253 ; special function registers
                                    254 ;--------------------------------------------------------
                                    255 	.area RSEG    (ABS,DATA)
      000000                        256 	.org 0x0000
                           0000D0   257 _PSW	=	0x00d0
                           0000E0   258 _ACC	=	0x00e0
                           0000F0   259 _B	=	0x00f0
                           000081   260 _SP	=	0x0081
                           000082   261 _DPL	=	0x0082
                           000083   262 _DPH	=	0x0083
                           0000A1   263 _SAFE_MOD	=	0x00a1
                           0000B1   264 _GLOBAL_CFG	=	0x00b1
                           000087   265 _PCON	=	0x0087
                           0000B9   266 _CLOCK_CFG	=	0x00b9
                           0000A9   267 _WAKE_CTRL	=	0x00a9
                           0000FE   268 _RESET_KEEP	=	0x00fe
                           0000FF   269 _WDOG_COUNT	=	0x00ff
                           0000A8   270 _IE	=	0x00a8
                           0000B8   271 _IP	=	0x00b8
                           0000E8   272 _IE_EX	=	0x00e8
                           0000E9   273 _IP_EX	=	0x00e9
                           0000C7   274 _GPIO_IE	=	0x00c7
                           008584   275 _ROM_ADDR	=	0x8584
                           000084   276 _ROM_ADDR_L	=	0x0084
                           000085   277 _ROM_ADDR_H	=	0x0085
                           008F8E   278 _ROM_DATA	=	0x8f8e
                           00008E   279 _ROM_DATA_L	=	0x008e
                           00008F   280 _ROM_DATA_H	=	0x008f
                           000086   281 _ROM_CTRL	=	0x0086
                           000090   282 _P1	=	0x0090
                           000092   283 _P1_MOD_OC	=	0x0092
                           000093   284 _P1_DIR_PU	=	0x0093
                           0000A0   285 _P2	=	0x00a0
                           0000B0   286 _P3	=	0x00b0
                           000096   287 _P3_MOD_OC	=	0x0096
                           000097   288 _P3_DIR_PU	=	0x0097
                           0000C6   289 _PIN_FUNC	=	0x00c6
                           0000A2   290 _XBUS_AUX	=	0x00a2
                           000088   291 _TCON	=	0x0088
                           000089   292 _TMOD	=	0x0089
                           00008A   293 _TL0	=	0x008a
                           00008B   294 _TL1	=	0x008b
                           00008C   295 _TH0	=	0x008c
                           00008D   296 _TH1	=	0x008d
                           000098   297 _SCON	=	0x0098
                           000099   298 _SBUF	=	0x0099
                           0000C8   299 _T2CON	=	0x00c8
                           0000C9   300 _T2MOD	=	0x00c9
                           00CBCA   301 _RCAP2	=	0xcbca
                           0000CA   302 _RCAP2L	=	0x00ca
                           0000CB   303 _RCAP2H	=	0x00cb
                           00CDCC   304 _T2COUNT	=	0xcdcc
                           0000CC   305 _TL2	=	0x00cc
                           0000CD   306 _TH2	=	0x00cd
                           00CFCE   307 _T2CAP1	=	0xcfce
                           0000CE   308 _T2CAP1L	=	0x00ce
                           0000CF   309 _T2CAP1H	=	0x00cf
                           00009B   310 _PWM_DATA2	=	0x009b
                           00009C   311 _PWM_DATA1	=	0x009c
                           00009D   312 _PWM_CTRL	=	0x009d
                           00009E   313 _PWM_CK_SE	=	0x009e
                           0000F8   314 _SPI0_STAT	=	0x00f8
                           0000F9   315 _SPI0_DATA	=	0x00f9
                           0000FA   316 _SPI0_CTRL	=	0x00fa
                           0000FB   317 _SPI0_CK_SE	=	0x00fb
                           0000FC   318 _SPI0_SETUP	=	0x00fc
                           0000C0   319 _SCON1	=	0x00c0
                           0000C1   320 _SBUF1	=	0x00c1
                           0000C2   321 _SBAUD1	=	0x00c2
                           000080   322 _ADC_CTRL	=	0x0080
                           00009A   323 _ADC_CFG	=	0x009a
                           00009F   324 _ADC_DATA	=	0x009f
                           0000C3   325 _TKEY_CTRL	=	0x00c3
                           00C5C4   326 _TKEY_DAT	=	0xc5c4
                           0000C4   327 _TKEY_DATL	=	0x00c4
                           0000C5   328 _TKEY_DATH	=	0x00c5
                           000091   329 _USB_C_CTRL	=	0x0091
                           0000D1   330 _UDEV_CTRL	=	0x00d1
                           0000D2   331 _UEP1_CTRL	=	0x00d2
                           0000D3   332 _UEP1_T_LEN	=	0x00d3
                           0000D4   333 _UEP2_CTRL	=	0x00d4
                           0000D5   334 _UEP2_T_LEN	=	0x00d5
                           0000D6   335 _UEP3_CTRL	=	0x00d6
                           0000D7   336 _UEP3_T_LEN	=	0x00d7
                           0000D8   337 _USB_INT_FG	=	0x00d8
                           0000D9   338 _USB_INT_ST	=	0x00d9
                           0000DA   339 _USB_MIS_ST	=	0x00da
                           0000DB   340 _USB_RX_LEN	=	0x00db
                           0000DC   341 _UEP0_CTRL	=	0x00dc
                           0000DD   342 _UEP0_T_LEN	=	0x00dd
                           0000DE   343 _UEP4_CTRL	=	0x00de
                           0000DF   344 _UEP4_T_LEN	=	0x00df
                           0000E1   345 _USB_INT_EN	=	0x00e1
                           0000E2   346 _USB_CTRL	=	0x00e2
                           0000E3   347 _USB_DEV_AD	=	0x00e3
                           00E5E4   348 _UEP2_DMA	=	0xe5e4
                           0000E4   349 _UEP2_DMA_L	=	0x00e4
                           0000E5   350 _UEP2_DMA_H	=	0x00e5
                           00E7E6   351 _UEP3_DMA	=	0xe7e6
                           0000E6   352 _UEP3_DMA_L	=	0x00e6
                           0000E7   353 _UEP3_DMA_H	=	0x00e7
                           0000EA   354 _UEP4_1_MOD	=	0x00ea
                           0000EB   355 _UEP2_3_MOD	=	0x00eb
                           00EDEC   356 _UEP0_DMA	=	0xedec
                           0000EC   357 _UEP0_DMA_L	=	0x00ec
                           0000ED   358 _UEP0_DMA_H	=	0x00ed
                           00EFEE   359 _UEP1_DMA	=	0xefee
                           0000EE   360 _UEP1_DMA_L	=	0x00ee
                           0000EF   361 _UEP1_DMA_H	=	0x00ef
                                    362 ;--------------------------------------------------------
                                    363 ; special function bits
                                    364 ;--------------------------------------------------------
                                    365 	.area RSEG    (ABS,DATA)
      000000                        366 	.org 0x0000
                           0000D7   367 _CY	=	0x00d7
                           0000D6   368 _AC	=	0x00d6
                           0000D5   369 _F0	=	0x00d5
                           0000D4   370 _RS1	=	0x00d4
                           0000D3   371 _RS0	=	0x00d3
                           0000D2   372 _OV	=	0x00d2
                           0000D1   373 _F1	=	0x00d1
                           0000D0   374 _P	=	0x00d0
                           0000AF   375 _EA	=	0x00af
                           0000AE   376 _E_DIS	=	0x00ae
                           0000AD   377 _ET2	=	0x00ad
                           0000AC   378 _ES	=	0x00ac
                           0000AB   379 _ET1	=	0x00ab
                           0000AA   380 _EX1	=	0x00aa
                           0000A9   381 _ET0	=	0x00a9
                           0000A8   382 _EX0	=	0x00a8
                           0000BF   383 _PH_FLAG	=	0x00bf
                           0000BE   384 _PL_FLAG	=	0x00be
                           0000BD   385 _PT2	=	0x00bd
                           0000BC   386 _PS	=	0x00bc
                           0000BB   387 _PT1	=	0x00bb
                           0000BA   388 _PX1	=	0x00ba
                           0000B9   389 _PT0	=	0x00b9
                           0000B8   390 _PX0	=	0x00b8
                           0000EF   391 _IE_WDOG	=	0x00ef
                           0000EE   392 _IE_GPIO	=	0x00ee
                           0000ED   393 _IE_PWMX	=	0x00ed
                           0000EC   394 _IE_UART1	=	0x00ec
                           0000EB   395 _IE_ADC	=	0x00eb
                           0000EA   396 _IE_USB	=	0x00ea
                           0000E9   397 _IE_TKEY	=	0x00e9
                           0000E8   398 _IE_SPI0	=	0x00e8
                           000097   399 _SCK	=	0x0097
                           000097   400 _TXD1	=	0x0097
                           000097   401 _TIN5	=	0x0097
                           000096   402 _MISO	=	0x0096
                           000096   403 _RXD1	=	0x0096
                           000096   404 _TIN4	=	0x0096
                           000095   405 _MOSI	=	0x0095
                           000095   406 _PWM1	=	0x0095
                           000095   407 _TIN3	=	0x0095
                           000095   408 _UCC2	=	0x0095
                           000095   409 _AIN2	=	0x0095
                           000094   410 _T2_	=	0x0094
                           000094   411 _CAP1_	=	0x0094
                           000094   412 _SCS	=	0x0094
                           000094   413 _TIN2	=	0x0094
                           000094   414 _UCC1	=	0x0094
                           000094   415 _AIN1	=	0x0094
                           000093   416 _TXD_	=	0x0093
                           000092   417 _RXD_	=	0x0092
                           000091   418 _T2EX	=	0x0091
                           000091   419 _CAP2	=	0x0091
                           000091   420 _TIN1	=	0x0091
                           000091   421 _VBUS2	=	0x0091
                           000091   422 _AIN0	=	0x0091
                           000090   423 _T2	=	0x0090
                           000090   424 _CAP1	=	0x0090
                           000090   425 _TIN0	=	0x0090
                           0000B7   426 _UDM	=	0x00b7
                           0000B6   427 _UDP	=	0x00b6
                           0000B5   428 _T1	=	0x00b5
                           0000B4   429 _PWM2	=	0x00b4
                           0000B4   430 _RXD1_	=	0x00b4
                           0000B4   431 _T0	=	0x00b4
                           0000B3   432 _INT1	=	0x00b3
                           0000B2   433 _TXD1_	=	0x00b2
                           0000B2   434 _INT0	=	0x00b2
                           0000B2   435 _VBUS1	=	0x00b2
                           0000B2   436 _AIN3	=	0x00b2
                           0000B1   437 _PWM2_	=	0x00b1
                           0000B1   438 _TXD	=	0x00b1
                           0000B0   439 _PWM1_	=	0x00b0
                           0000B0   440 _RXD	=	0x00b0
                           00008F   441 _TF1	=	0x008f
                           00008E   442 _TR1	=	0x008e
                           00008D   443 _TF0	=	0x008d
                           00008C   444 _TR0	=	0x008c
                           00008B   445 _IE1	=	0x008b
                           00008A   446 _IT1	=	0x008a
                           000089   447 _IE0	=	0x0089
                           000088   448 _IT0	=	0x0088
                           00009F   449 _SM0	=	0x009f
                           00009E   450 _SM1	=	0x009e
                           00009D   451 _SM2	=	0x009d
                           00009C   452 _REN	=	0x009c
                           00009B   453 _TB8	=	0x009b
                           00009A   454 _RB8	=	0x009a
                           000099   455 _TI	=	0x0099
                           000098   456 _RI	=	0x0098
                           0000CF   457 _TF2	=	0x00cf
                           0000CF   458 _CAP1F	=	0x00cf
                           0000CE   459 _EXF2	=	0x00ce
                           0000CD   460 _RCLK	=	0x00cd
                           0000CC   461 _TCLK	=	0x00cc
                           0000CB   462 _EXEN2	=	0x00cb
                           0000CA   463 _TR2	=	0x00ca
                           0000C9   464 _C_T2	=	0x00c9
                           0000C8   465 _CP_RL2	=	0x00c8
                           0000FF   466 _S0_FST_ACT	=	0x00ff
                           0000FE   467 _S0_IF_OV	=	0x00fe
                           0000FD   468 _S0_IF_FIRST	=	0x00fd
                           0000FC   469 _S0_IF_BYTE	=	0x00fc
                           0000FB   470 _S0_FREE	=	0x00fb
                           0000FA   471 _S0_T_FIFO	=	0x00fa
                           0000F8   472 _S0_R_FIFO	=	0x00f8
                           0000C7   473 _U1SM0	=	0x00c7
                           0000C5   474 _U1SMOD	=	0x00c5
                           0000C4   475 _U1REN	=	0x00c4
                           0000C3   476 _U1TB8	=	0x00c3
                           0000C2   477 _U1RB8	=	0x00c2
                           0000C1   478 _U1TI	=	0x00c1
                           0000C0   479 _U1RI	=	0x00c0
                           000087   480 _CMPO	=	0x0087
                           000086   481 _CMP_IF	=	0x0086
                           000085   482 _ADC_IF	=	0x0085
                           000084   483 _ADC_START	=	0x0084
                           000083   484 _CMP_CHAN	=	0x0083
                           000081   485 _ADC_CHAN1	=	0x0081
                           000080   486 _ADC_CHAN0	=	0x0080
                           0000DF   487 _U_IS_NAK	=	0x00df
                           0000DE   488 _U_TOG_OK	=	0x00de
                           0000DD   489 _U_SIE_FREE	=	0x00dd
                           0000DC   490 _UIF_FIFO_OV	=	0x00dc
                           0000DB   491 _UIF_HST_SOF	=	0x00db
                           0000DA   492 _UIF_SUSPEND	=	0x00da
                           0000D9   493 _UIF_TRANSFER	=	0x00d9
                           0000D8   494 _UIF_DETECT	=	0x00d8
                           0000D8   495 _UIF_BUS_RST	=	0x00d8
                                    496 ;--------------------------------------------------------
                                    497 ; overlayable register banks
                                    498 ;--------------------------------------------------------
                                    499 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        500 	.ds 8
                                    501 ;--------------------------------------------------------
                                    502 ; internal ram data
                                    503 ;--------------------------------------------------------
                                    504 	.area DSEG    (DATA)
                                    505 ;--------------------------------------------------------
                                    506 ; overlayable items in internal ram 
                                    507 ;--------------------------------------------------------
                                    508 	.area	OSEG    (OVR,DATA)
                                    509 	.area	OSEG    (OVR,DATA)
                                    510 ;--------------------------------------------------------
                                    511 ; indirectly addressable internal ram data
                                    512 ;--------------------------------------------------------
                                    513 	.area ISEG    (DATA)
                                    514 ;--------------------------------------------------------
                                    515 ; absolute internal ram data
                                    516 ;--------------------------------------------------------
                                    517 	.area IABS    (ABS,DATA)
                                    518 	.area IABS    (ABS,DATA)
                                    519 ;--------------------------------------------------------
                                    520 ; bit data
                                    521 ;--------------------------------------------------------
                                    522 	.area BSEG    (BIT)
                                    523 ;--------------------------------------------------------
                                    524 ; paged external ram data
                                    525 ;--------------------------------------------------------
                                    526 	.area PSEG    (PAG,XDATA)
                                    527 ;--------------------------------------------------------
                                    528 ; external ram data
                                    529 ;--------------------------------------------------------
                                    530 	.area XSEG    (XDATA)
                                    531 ;--------------------------------------------------------
                                    532 ; absolute external ram data
                                    533 ;--------------------------------------------------------
                                    534 	.area XABS    (ABS,XDATA)
                                    535 ;--------------------------------------------------------
                                    536 ; external initialized ram data
                                    537 ;--------------------------------------------------------
                                    538 	.area XISEG   (XDATA)
                                    539 	.area HOME    (CODE)
                                    540 	.area GSINIT0 (CODE)
                                    541 	.area GSINIT1 (CODE)
                                    542 	.area GSINIT2 (CODE)
                                    543 	.area GSINIT3 (CODE)
                                    544 	.area GSINIT4 (CODE)
                                    545 	.area GSINIT5 (CODE)
                                    546 	.area GSINIT  (CODE)
                                    547 	.area GSFINAL (CODE)
                                    548 	.area CSEG    (CODE)
                                    549 ;--------------------------------------------------------
                                    550 ; global & static initialisations
                                    551 ;--------------------------------------------------------
                                    552 	.area HOME    (CODE)
                                    553 	.area GSINIT  (CODE)
                                    554 	.area GSFINAL (CODE)
                                    555 	.area GSINIT  (CODE)
                                    556 ;--------------------------------------------------------
                                    557 ; Home
                                    558 ;--------------------------------------------------------
                                    559 	.area HOME    (CODE)
                                    560 	.area HOME    (CODE)
                                    561 ;--------------------------------------------------------
                                    562 ; code
                                    563 ;--------------------------------------------------------
                                    564 	.area CSEG    (CODE)
                                    565 ;------------------------------------------------------------
                                    566 ;Allocation info for local variables in function 'ConfigSysClock'
                                    567 ;------------------------------------------------------------
                                    568 ;	ch554_conf.c:8: void ConfigSysClock() {
                                    569 ;	-----------------------------------------
                                    570 ;	 function ConfigSysClock
                                    571 ;	-----------------------------------------
      0003F1                        572 _ConfigSysClock:
                           000007   573 	ar7 = 0x07
                           000006   574 	ar6 = 0x06
                           000005   575 	ar5 = 0x05
                           000004   576 	ar4 = 0x04
                           000003   577 	ar3 = 0x03
                           000002   578 	ar2 = 0x02
                           000001   579 	ar1 = 0x01
                           000000   580 	ar0 = 0x00
                                    581 ;	ch554_conf.c:15: SAFE_MOD = 0x55;
      0003F1 75 A1 55         [24]  582 	mov	_SAFE_MOD,#0x55
                                    583 ;	ch554_conf.c:16: SAFE_MOD = 0xAA;
      0003F4 75 A1 AA         [24]  584 	mov	_SAFE_MOD,#0xaa
                                    585 ;	ch554_conf.c:21: CLOCK_CFG = CLOCK_CFG & ~ MASK_SYS_CK_SEL | 0x06;  // 24MHz
      0003F7 74 F8            [12]  586 	mov	a,#0xf8
      0003F9 55 B9            [12]  587 	anl	a,_CLOCK_CFG
      0003FB FF               [12]  588 	mov	r7,a
      0003FC 43 07 06         [24]  589 	orl	ar7,#0x06
      0003FF 8F B9            [24]  590 	mov	_CLOCK_CFG,r7
                                    591 ;	ch554_conf.c:38: SAFE_MOD = 0x00;	
      000401 75 A1 00         [24]  592 	mov	_SAFE_MOD,#0x00
                                    593 ;	ch554_conf.c:39: }
      000404 22               [24]  594 	ret
                                    595 ;------------------------------------------------------------
                                    596 ;Allocation info for local variables in function 'USBDevice_Init'
                                    597 ;------------------------------------------------------------
                                    598 ;	ch554_conf.c:41: void USBDevice_Init() {
                                    599 ;	-----------------------------------------
                                    600 ;	 function USBDevice_Init
                                    601 ;	-----------------------------------------
      000405                        602 _USBDevice_Init:
                                    603 ;	ch554_conf.c:42: IE_USB = 0;					// Disable USB interrupt (for setup)
                                    604 ;	assignBit
      000405 C2 EA            [12]  605 	clr	_IE_USB
                                    606 ;	ch554_conf.c:43: USB_CTRL = 0x00;			// Device mode, Full speed(12Mbps), Disable pull up(Invisible to host), Reset stuff
      000407 75 E2 00         [24]  607 	mov	_USB_CTRL,#0x00
                                    608 ;	ch554_conf.c:47: UEP0_DMA_L = (uint8_t) Ep0Buffer; // Address of Endpoint 0 buffer
      00040A 75 EC 00         [24]  609 	mov	_UEP0_DMA_L,#_Ep0Buffer
                                    610 ;	ch554_conf.c:49: UEP4_1_MOD &= ~(bUEP4_RX_EN | bUEP4_TX_EN);		// EP0 64-byte buffer
      00040D 53 EA F3         [24]  611 	anl	_UEP4_1_MOD,#0xf3
                                    612 ;	ch554_conf.c:50: UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;		// SETUP/OUT -> ACK, IN -> NAK
      000410 75 DC 02         [24]  613 	mov	_UEP0_CTRL,#0x02
                                    614 ;	ch554_conf.c:53: UEP1_DMA_L = (uint8_t) Ep1Buffer; // Address of Endpoint 1 buffer
      000413 75 EE 0A         [24]  615 	mov	_UEP1_DMA_L,#_Ep1Buffer
                                    616 ;	ch554_conf.c:55: UEP4_1_MOD &=~bUEP1_BUF_MOD;	//See table 16.3.3
      000416 53 EA EF         [24]  617 	anl	_UEP4_1_MOD,#0xef
                                    618 ;	ch554_conf.c:56: UEP4_1_MOD |= bUEP1_TX_EN;		// EP1 Tx only, 64 bytes of buffer
      000419 AE EA            [24]  619 	mov	r6,_UEP4_1_MOD
      00041B 43 06 40         [24]  620 	orl	ar6,#0x40
      00041E 8E EA            [24]  621 	mov	_UEP4_1_MOD,r6
                                    622 ;	ch554_conf.c:58: UEP1_CTRL = bUEP_AUTO_TOG | UEP_T_RES_NAK;
      000420 75 D2 12         [24]  623 	mov	_UEP1_CTRL,#0x12
                                    624 ;	ch554_conf.c:61: UEP2_DMA_L = (uint8_t) Ep2Buffer;	// Address of Endpoint 2 buffer
      000423 75 E4 4A         [24]  625 	mov	_UEP2_DMA_L,#_Ep2Buffer
                                    626 ;	ch554_conf.c:63: UEP2_3_MOD &=~bUEP2_BUF_MOD;	// Disable Endpoint2 buffer mode
      000426 53 EB FE         [24]  627 	anl	_UEP2_3_MOD,#0xfe
                                    628 ;	ch554_conf.c:64: UEP2_3_MOD |= bUEP2_TX_EN;		// Enable Endpoint2 Tx
      000429 AE EB            [24]  629 	mov	r6,_UEP2_3_MOD
      00042B 43 06 04         [24]  630 	orl	ar6,#0x04
      00042E 8E EB            [24]  631 	mov	_UEP2_3_MOD,r6
                                    632 ;	ch554_conf.c:65: UEP2_3_MOD |= bUEP2_RX_EN;		// Enable Endpoint2 Rx
      000430 AE EB            [24]  633 	mov	r6,_UEP2_3_MOD
      000432 43 06 08         [24]  634 	orl	ar6,#0x08
      000435 8E EB            [24]  635 	mov	_UEP2_3_MOD,r6
                                    636 ;	ch554_conf.c:67: UEP2_CTRL = bUEP_AUTO_TOG | UEP_T_RES_NAK | UEP_R_RES_ACK;
      000437 75 D4 12         [24]  637 	mov	_UEP2_CTRL,#0x12
                                    638 ;	ch554_conf.c:70: USB_INT_FG = 0xFF;			 // Clear interrupt flags
      00043A 75 D8 FF         [24]  639 	mov	_USB_INT_FG,#0xff
                                    640 ;	ch554_conf.c:72: USB_INT_EN = bUIE_SUSPEND | bUIE_TRANSFER | bUIE_BUS_RST;
      00043D 75 E1 07         [24]  641 	mov	_USB_INT_EN,#0x07
                                    642 ;	ch554_conf.c:73: IE_USB = 1;	//Enable USB interrupt
                                    643 ;	assignBit
      000440 D2 EA            [12]  644 	setb	_IE_USB
                                    645 ;	ch554_conf.c:77: USB_DEV_AD = 0x00;	//Set USB address to 0, get ready for enumeration
      000442 75 E3 00         [24]  646 	mov	_USB_DEV_AD,#0x00
                                    647 ;	ch554_conf.c:79: USB_CTRL = bUC_DEV_PU_EN | bUC_INT_BUSY | bUC_DMA_EN;
      000445 75 E2 29         [24]  648 	mov	_USB_CTRL,#0x29
                                    649 ;	ch554_conf.c:80: UDEV_CTRL |= bUD_PORT_EN;	// Enable USB Port
      000448 AE D1            [24]  650 	mov	r6,_UDEV_CTRL
      00044A 43 06 01         [24]  651 	orl	ar6,#0x01
      00044D 8E D1            [24]  652 	mov	_UDEV_CTRL,r6
                                    653 ;	ch554_conf.c:83: UEP1_T_LEN = 0;
      00044F 75 D3 00         [24]  654 	mov	_UEP1_T_LEN,#0x00
                                    655 ;	ch554_conf.c:84: UEP2_T_LEN = 0;  
      000452 75 D5 00         [24]  656 	mov	_UEP2_T_LEN,#0x00
                                    657 ;	ch554_conf.c:85: }
      000455 22               [24]  658 	ret
                                    659 ;------------------------------------------------------------
                                    660 ;Allocation info for local variables in function 'UART0_Init'
                                    661 ;------------------------------------------------------------
                                    662 ;x                         Allocated to registers 
                                    663 ;x2                        Allocated to registers 
                                    664 ;------------------------------------------------------------
                                    665 ;	ch554_conf.c:87: void UART0_Init(void) {
                                    666 ;	-----------------------------------------
                                    667 ;	 function UART0_Init
                                    668 ;	-----------------------------------------
      000456                        669 _UART0_Init:
                                    670 ;	ch554_conf.c:91: SM0 = 0;
                                    671 ;	assignBit
      000456 C2 9F            [12]  672 	clr	_SM0
                                    673 ;	ch554_conf.c:92: SM1 = 1;
                                    674 ;	assignBit
      000458 D2 9E            [12]  675 	setb	_SM1
                                    676 ;	ch554_conf.c:93: SM2 = 0;	// UART0 Mode 0
                                    677 ;	assignBit
      00045A C2 9D            [12]  678 	clr	_SM2
                                    679 ;	ch554_conf.c:96: RCLK = 0;
                                    680 ;	assignBit
      00045C C2 CD            [12]  681 	clr	_RCLK
                                    682 ;	ch554_conf.c:97: TCLK = 0;
                                    683 ;	assignBit
      00045E C2 CC            [12]  684 	clr	_TCLK
                                    685 ;	ch554_conf.c:98: PCON |= SMOD;
      000460 AE 87            [24]  686 	mov	r6,_PCON
      000462 43 06 80         [24]  687 	orl	ar6,#0x80
      000465 8E 87            [24]  688 	mov	_PCON,r6
                                    689 ;	ch554_conf.c:104: TMOD = TMOD & ~ bT1_GATE & ~ bT1_CT & ~ MASK_T1_MOD | bT1_M1;	// Timer1: 8-bit auto reload
      000467 74 0F            [12]  690 	mov	a,#0x0f
      000469 55 89            [12]  691 	anl	a,_TMOD
      00046B FF               [12]  692 	mov	r7,a
      00046C 43 07 20         [24]  693 	orl	ar7,#0x20
      00046F 8F 89            [24]  694 	mov	_TMOD,r7
                                    695 ;	ch554_conf.c:105: T2MOD = T2MOD | bTMR_CLK | bT1_CLK;	// Select input clock for Timer1
      000471 43 C9 A0         [24]  696 	orl	_T2MOD,#0xa0
                                    697 ;	ch554_conf.c:106: TH1 = 0-x;
      000474 75 8D F3         [24]  698 	mov	_TH1,#0xf3
                                    699 ;	ch554_conf.c:107: TR1 = 1;  // Start Timer1
                                    700 ;	assignBit
      000477 D2 8E            [12]  701 	setb	_TR1
                                    702 ;	ch554_conf.c:108: TI = 1;
                                    703 ;	assignBit
      000479 D2 99            [12]  704 	setb	_TI
                                    705 ;	ch554_conf.c:109: REN = 1;	// Enable UART1
                                    706 ;	assignBit
      00047B D2 9C            [12]  707 	setb	_REN
                                    708 ;	ch554_conf.c:110: }
      00047D 22               [24]  709 	ret
                                    710 ;------------------------------------------------------------
                                    711 ;Allocation info for local variables in function 'CH554_Init'
                                    712 ;------------------------------------------------------------
                                    713 ;	ch554_conf.c:112: void CH554_Init(void) {
                                    714 ;	-----------------------------------------
                                    715 ;	 function CH554_Init
                                    716 ;	-----------------------------------------
      00047E                        717 _CH554_Init:
                                    718 ;	ch554_conf.c:113: ConfigSysClock();
      00047E 12 03 F1         [24]  719 	lcall	_ConfigSysClock
                                    720 ;	ch554_conf.c:114: mDelaymS(5);	// Wait until the internal crystal becomes stable
      000481 90 00 05         [24]  721 	mov	dptr,#0x0005
      000484 12 04 B4         [24]  722 	lcall	_mDelaymS
                                    723 ;	ch554_conf.c:116: UART0_Init();
      000487 12 04 56         [24]  724 	lcall	_UART0_Init
                                    725 ;	ch554_conf.c:118: USBDevice_Init();
      00048A 12 04 05         [24]  726 	lcall	_USBDevice_Init
                                    727 ;	ch554_conf.c:120: EA = 1;
                                    728 ;	assignBit
      00048D D2 AF            [12]  729 	setb	_EA
                                    730 ;	ch554_conf.c:121: }
      00048F 22               [24]  731 	ret
                                    732 ;------------------------------------------------------------
                                    733 ;Allocation info for local variables in function 'CH554UART0RcvByte'
                                    734 ;------------------------------------------------------------
                                    735 ;	ch554_conf.c:123: uint8_t  CH554UART0RcvByte( )
                                    736 ;	-----------------------------------------
                                    737 ;	 function CH554UART0RcvByte
                                    738 ;	-----------------------------------------
      000490                        739 _CH554UART0RcvByte:
                                    740 ;	ch554_conf.c:125: while(RI == 0);                                                            //查询接收，中断方式可不用
      000490                        741 00101$:
                                    742 ;	ch554_conf.c:126: RI = 0;
                                    743 ;	assignBit
      000490 10 98 02         [24]  744 	jbc	_RI,00114$
      000493 80 FB            [24]  745 	sjmp	00101$
      000495                        746 00114$:
                                    747 ;	ch554_conf.c:127: return SBUF;
      000495 85 99 82         [24]  748 	mov	dpl,_SBUF
                                    749 ;	ch554_conf.c:128: }
      000498 22               [24]  750 	ret
                                    751 ;------------------------------------------------------------
                                    752 ;Allocation info for local variables in function 'CH554UART0SendByte'
                                    753 ;------------------------------------------------------------
                                    754 ;SendDat                   Allocated to registers 
                                    755 ;------------------------------------------------------------
                                    756 ;	ch554_conf.c:130: void CH554UART0SendByte(uint8_t SendDat)
                                    757 ;	-----------------------------------------
                                    758 ;	 function CH554UART0SendByte
                                    759 ;	-----------------------------------------
      000499                        760 _CH554UART0SendByte:
      000499 85 82 99         [24]  761 	mov	_SBUF,dpl
                                    762 ;	ch554_conf.c:133: while(TI ==0);
      00049C                        763 00101$:
                                    764 ;	ch554_conf.c:134: TI = 0;
                                    765 ;	assignBit
      00049C 10 99 02         [24]  766 	jbc	_TI,00114$
      00049F 80 FB            [24]  767 	sjmp	00101$
      0004A1                        768 00114$:
                                    769 ;	ch554_conf.c:135: }
      0004A1 22               [24]  770 	ret
                                    771 	.area CSEG    (CODE)
                                    772 	.area CONST   (CODE)
                                    773 	.area XINIT   (CODE)
                                    774 	.area CABS    (ABS,CODE)
