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
                                     11 	.globl _main
                                     12 	.globl _mDelaymS
                                     13 	.globl _CfgFsys
                                     14 	.globl _UIF_BUS_RST
                                     15 	.globl _UIF_DETECT
                                     16 	.globl _UIF_TRANSFER
                                     17 	.globl _UIF_SUSPEND
                                     18 	.globl _UIF_HST_SOF
                                     19 	.globl _UIF_FIFO_OV
                                     20 	.globl _U_SIE_FREE
                                     21 	.globl _U_TOG_OK
                                     22 	.globl _U_IS_NAK
                                     23 	.globl _ADC_CHAN0
                                     24 	.globl _ADC_CHAN1
                                     25 	.globl _CMP_CHAN
                                     26 	.globl _ADC_START
                                     27 	.globl _ADC_IF
                                     28 	.globl _CMP_IF
                                     29 	.globl _CMPO
                                     30 	.globl _U1RI
                                     31 	.globl _U1TI
                                     32 	.globl _U1RB8
                                     33 	.globl _U1TB8
                                     34 	.globl _U1REN
                                     35 	.globl _U1SMOD
                                     36 	.globl _U1SM0
                                     37 	.globl _S0_R_FIFO
                                     38 	.globl _S0_T_FIFO
                                     39 	.globl _S0_FREE
                                     40 	.globl _S0_IF_BYTE
                                     41 	.globl _S0_IF_FIRST
                                     42 	.globl _S0_IF_OV
                                     43 	.globl _S0_FST_ACT
                                     44 	.globl _CP_RL2
                                     45 	.globl _C_T2
                                     46 	.globl _TR2
                                     47 	.globl _EXEN2
                                     48 	.globl _TCLK
                                     49 	.globl _RCLK
                                     50 	.globl _EXF2
                                     51 	.globl _CAP1F
                                     52 	.globl _TF2
                                     53 	.globl _RI
                                     54 	.globl _TI
                                     55 	.globl _RB8
                                     56 	.globl _TB8
                                     57 	.globl _REN
                                     58 	.globl _SM2
                                     59 	.globl _SM1
                                     60 	.globl _SM0
                                     61 	.globl _IT0
                                     62 	.globl _IE0
                                     63 	.globl _IT1
                                     64 	.globl _IE1
                                     65 	.globl _TR0
                                     66 	.globl _TF0
                                     67 	.globl _TR1
                                     68 	.globl _TF1
                                     69 	.globl _RXD
                                     70 	.globl _PWM1_
                                     71 	.globl _TXD
                                     72 	.globl _PWM2_
                                     73 	.globl _AIN3
                                     74 	.globl _VBUS1
                                     75 	.globl _INT0
                                     76 	.globl _TXD1_
                                     77 	.globl _INT1
                                     78 	.globl _T0
                                     79 	.globl _RXD1_
                                     80 	.globl _PWM2
                                     81 	.globl _T1
                                     82 	.globl _UDP
                                     83 	.globl _UDM
                                     84 	.globl _TIN0
                                     85 	.globl _CAP1
                                     86 	.globl _T2
                                     87 	.globl _AIN0
                                     88 	.globl _VBUS2
                                     89 	.globl _TIN1
                                     90 	.globl _CAP2
                                     91 	.globl _T2EX
                                     92 	.globl _RXD_
                                     93 	.globl _TXD_
                                     94 	.globl _AIN1
                                     95 	.globl _UCC1
                                     96 	.globl _TIN2
                                     97 	.globl _SCS
                                     98 	.globl _CAP1_
                                     99 	.globl _T2_
                                    100 	.globl _AIN2
                                    101 	.globl _UCC2
                                    102 	.globl _TIN3
                                    103 	.globl _PWM1
                                    104 	.globl _MOSI
                                    105 	.globl _TIN4
                                    106 	.globl _RXD1
                                    107 	.globl _MISO
                                    108 	.globl _TIN5
                                    109 	.globl _TXD1
                                    110 	.globl _SCK
                                    111 	.globl _IE_SPI0
                                    112 	.globl _IE_TKEY
                                    113 	.globl _IE_USB
                                    114 	.globl _IE_ADC
                                    115 	.globl _IE_UART1
                                    116 	.globl _IE_PWMX
                                    117 	.globl _IE_GPIO
                                    118 	.globl _IE_WDOG
                                    119 	.globl _PX0
                                    120 	.globl _PT0
                                    121 	.globl _PX1
                                    122 	.globl _PT1
                                    123 	.globl _PS
                                    124 	.globl _PT2
                                    125 	.globl _PL_FLAG
                                    126 	.globl _PH_FLAG
                                    127 	.globl _EX0
                                    128 	.globl _ET0
                                    129 	.globl _EX1
                                    130 	.globl _ET1
                                    131 	.globl _ES
                                    132 	.globl _ET2
                                    133 	.globl _E_DIS
                                    134 	.globl _EA
                                    135 	.globl _P
                                    136 	.globl _F1
                                    137 	.globl _OV
                                    138 	.globl _RS0
                                    139 	.globl _RS1
                                    140 	.globl _F0
                                    141 	.globl _AC
                                    142 	.globl _CY
                                    143 	.globl _UEP1_DMA_H
                                    144 	.globl _UEP1_DMA_L
                                    145 	.globl _UEP1_DMA
                                    146 	.globl _UEP0_DMA_H
                                    147 	.globl _UEP0_DMA_L
                                    148 	.globl _UEP0_DMA
                                    149 	.globl _UEP2_3_MOD
                                    150 	.globl _UEP4_1_MOD
                                    151 	.globl _UEP3_DMA_H
                                    152 	.globl _UEP3_DMA_L
                                    153 	.globl _UEP3_DMA
                                    154 	.globl _UEP2_DMA_H
                                    155 	.globl _UEP2_DMA_L
                                    156 	.globl _UEP2_DMA
                                    157 	.globl _USB_DEV_AD
                                    158 	.globl _USB_CTRL
                                    159 	.globl _USB_INT_EN
                                    160 	.globl _UEP4_T_LEN
                                    161 	.globl _UEP4_CTRL
                                    162 	.globl _UEP0_T_LEN
                                    163 	.globl _UEP0_CTRL
                                    164 	.globl _USB_RX_LEN
                                    165 	.globl _USB_MIS_ST
                                    166 	.globl _USB_INT_ST
                                    167 	.globl _USB_INT_FG
                                    168 	.globl _UEP3_T_LEN
                                    169 	.globl _UEP3_CTRL
                                    170 	.globl _UEP2_T_LEN
                                    171 	.globl _UEP2_CTRL
                                    172 	.globl _UEP1_T_LEN
                                    173 	.globl _UEP1_CTRL
                                    174 	.globl _UDEV_CTRL
                                    175 	.globl _USB_C_CTRL
                                    176 	.globl _TKEY_DATH
                                    177 	.globl _TKEY_DATL
                                    178 	.globl _TKEY_DAT
                                    179 	.globl _TKEY_CTRL
                                    180 	.globl _ADC_DATA
                                    181 	.globl _ADC_CFG
                                    182 	.globl _ADC_CTRL
                                    183 	.globl _SBAUD1
                                    184 	.globl _SBUF1
                                    185 	.globl _SCON1
                                    186 	.globl _SPI0_SETUP
                                    187 	.globl _SPI0_CK_SE
                                    188 	.globl _SPI0_CTRL
                                    189 	.globl _SPI0_DATA
                                    190 	.globl _SPI0_STAT
                                    191 	.globl _PWM_CK_SE
                                    192 	.globl _PWM_CTRL
                                    193 	.globl _PWM_DATA1
                                    194 	.globl _PWM_DATA2
                                    195 	.globl _T2CAP1H
                                    196 	.globl _T2CAP1L
                                    197 	.globl _T2CAP1
                                    198 	.globl _TH2
                                    199 	.globl _TL2
                                    200 	.globl _T2COUNT
                                    201 	.globl _RCAP2H
                                    202 	.globl _RCAP2L
                                    203 	.globl _RCAP2
                                    204 	.globl _T2MOD
                                    205 	.globl _T2CON
                                    206 	.globl _SBUF
                                    207 	.globl _SCON
                                    208 	.globl _TH1
                                    209 	.globl _TH0
                                    210 	.globl _TL1
                                    211 	.globl _TL0
                                    212 	.globl _TMOD
                                    213 	.globl _TCON
                                    214 	.globl _XBUS_AUX
                                    215 	.globl _PIN_FUNC
                                    216 	.globl _P3_DIR_PU
                                    217 	.globl _P3_MOD_OC
                                    218 	.globl _P3
                                    219 	.globl _P2
                                    220 	.globl _P1_DIR_PU
                                    221 	.globl _P1_MOD_OC
                                    222 	.globl _P1
                                    223 	.globl _ROM_CTRL
                                    224 	.globl _ROM_DATA_H
                                    225 	.globl _ROM_DATA_L
                                    226 	.globl _ROM_DATA
                                    227 	.globl _ROM_ADDR_H
                                    228 	.globl _ROM_ADDR_L
                                    229 	.globl _ROM_ADDR
                                    230 	.globl _GPIO_IE
                                    231 	.globl _IP_EX
                                    232 	.globl _IE_EX
                                    233 	.globl _IP
                                    234 	.globl _IE
                                    235 	.globl _WDOG_COUNT
                                    236 	.globl _RESET_KEEP
                                    237 	.globl _WAKE_CTRL
                                    238 	.globl _CLOCK_CFG
                                    239 	.globl _PCON
                                    240 	.globl _GLOBAL_CFG
                                    241 	.globl _SAFE_MOD
                                    242 	.globl _DPH
                                    243 	.globl _DPL
                                    244 	.globl _SP
                                    245 	.globl _B
                                    246 	.globl _ACC
                                    247 	.globl _PSW
                                    248 ;--------------------------------------------------------
                                    249 ; special function registers
                                    250 ;--------------------------------------------------------
                                    251 	.area RSEG    (ABS,DATA)
      000000                        252 	.org 0x0000
                           0000D0   253 _PSW	=	0x00d0
                           0000E0   254 _ACC	=	0x00e0
                           0000F0   255 _B	=	0x00f0
                           000081   256 _SP	=	0x0081
                           000082   257 _DPL	=	0x0082
                           000083   258 _DPH	=	0x0083
                           0000A1   259 _SAFE_MOD	=	0x00a1
                           0000B1   260 _GLOBAL_CFG	=	0x00b1
                           000087   261 _PCON	=	0x0087
                           0000B9   262 _CLOCK_CFG	=	0x00b9
                           0000A9   263 _WAKE_CTRL	=	0x00a9
                           0000FE   264 _RESET_KEEP	=	0x00fe
                           0000FF   265 _WDOG_COUNT	=	0x00ff
                           0000A8   266 _IE	=	0x00a8
                           0000B8   267 _IP	=	0x00b8
                           0000E8   268 _IE_EX	=	0x00e8
                           0000E9   269 _IP_EX	=	0x00e9
                           0000C7   270 _GPIO_IE	=	0x00c7
                           008584   271 _ROM_ADDR	=	0x8584
                           000084   272 _ROM_ADDR_L	=	0x0084
                           000085   273 _ROM_ADDR_H	=	0x0085
                           008F8E   274 _ROM_DATA	=	0x8f8e
                           00008E   275 _ROM_DATA_L	=	0x008e
                           00008F   276 _ROM_DATA_H	=	0x008f
                           000086   277 _ROM_CTRL	=	0x0086
                           000090   278 _P1	=	0x0090
                           000092   279 _P1_MOD_OC	=	0x0092
                           000093   280 _P1_DIR_PU	=	0x0093
                           0000A0   281 _P2	=	0x00a0
                           0000B0   282 _P3	=	0x00b0
                           000096   283 _P3_MOD_OC	=	0x0096
                           000097   284 _P3_DIR_PU	=	0x0097
                           0000C6   285 _PIN_FUNC	=	0x00c6
                           0000A2   286 _XBUS_AUX	=	0x00a2
                           000088   287 _TCON	=	0x0088
                           000089   288 _TMOD	=	0x0089
                           00008A   289 _TL0	=	0x008a
                           00008B   290 _TL1	=	0x008b
                           00008C   291 _TH0	=	0x008c
                           00008D   292 _TH1	=	0x008d
                           000098   293 _SCON	=	0x0098
                           000099   294 _SBUF	=	0x0099
                           0000C8   295 _T2CON	=	0x00c8
                           0000C9   296 _T2MOD	=	0x00c9
                           00CBCA   297 _RCAP2	=	0xcbca
                           0000CA   298 _RCAP2L	=	0x00ca
                           0000CB   299 _RCAP2H	=	0x00cb
                           00CDCC   300 _T2COUNT	=	0xcdcc
                           0000CC   301 _TL2	=	0x00cc
                           0000CD   302 _TH2	=	0x00cd
                           00CFCE   303 _T2CAP1	=	0xcfce
                           0000CE   304 _T2CAP1L	=	0x00ce
                           0000CF   305 _T2CAP1H	=	0x00cf
                           00009B   306 _PWM_DATA2	=	0x009b
                           00009C   307 _PWM_DATA1	=	0x009c
                           00009D   308 _PWM_CTRL	=	0x009d
                           00009E   309 _PWM_CK_SE	=	0x009e
                           0000F8   310 _SPI0_STAT	=	0x00f8
                           0000F9   311 _SPI0_DATA	=	0x00f9
                           0000FA   312 _SPI0_CTRL	=	0x00fa
                           0000FB   313 _SPI0_CK_SE	=	0x00fb
                           0000FC   314 _SPI0_SETUP	=	0x00fc
                           0000C0   315 _SCON1	=	0x00c0
                           0000C1   316 _SBUF1	=	0x00c1
                           0000C2   317 _SBAUD1	=	0x00c2
                           000080   318 _ADC_CTRL	=	0x0080
                           00009A   319 _ADC_CFG	=	0x009a
                           00009F   320 _ADC_DATA	=	0x009f
                           0000C3   321 _TKEY_CTRL	=	0x00c3
                           00C5C4   322 _TKEY_DAT	=	0xc5c4
                           0000C4   323 _TKEY_DATL	=	0x00c4
                           0000C5   324 _TKEY_DATH	=	0x00c5
                           000091   325 _USB_C_CTRL	=	0x0091
                           0000D1   326 _UDEV_CTRL	=	0x00d1
                           0000D2   327 _UEP1_CTRL	=	0x00d2
                           0000D3   328 _UEP1_T_LEN	=	0x00d3
                           0000D4   329 _UEP2_CTRL	=	0x00d4
                           0000D5   330 _UEP2_T_LEN	=	0x00d5
                           0000D6   331 _UEP3_CTRL	=	0x00d6
                           0000D7   332 _UEP3_T_LEN	=	0x00d7
                           0000D8   333 _USB_INT_FG	=	0x00d8
                           0000D9   334 _USB_INT_ST	=	0x00d9
                           0000DA   335 _USB_MIS_ST	=	0x00da
                           0000DB   336 _USB_RX_LEN	=	0x00db
                           0000DC   337 _UEP0_CTRL	=	0x00dc
                           0000DD   338 _UEP0_T_LEN	=	0x00dd
                           0000DE   339 _UEP4_CTRL	=	0x00de
                           0000DF   340 _UEP4_T_LEN	=	0x00df
                           0000E1   341 _USB_INT_EN	=	0x00e1
                           0000E2   342 _USB_CTRL	=	0x00e2
                           0000E3   343 _USB_DEV_AD	=	0x00e3
                           00E5E4   344 _UEP2_DMA	=	0xe5e4
                           0000E4   345 _UEP2_DMA_L	=	0x00e4
                           0000E5   346 _UEP2_DMA_H	=	0x00e5
                           00E7E6   347 _UEP3_DMA	=	0xe7e6
                           0000E6   348 _UEP3_DMA_L	=	0x00e6
                           0000E7   349 _UEP3_DMA_H	=	0x00e7
                           0000EA   350 _UEP4_1_MOD	=	0x00ea
                           0000EB   351 _UEP2_3_MOD	=	0x00eb
                           00EDEC   352 _UEP0_DMA	=	0xedec
                           0000EC   353 _UEP0_DMA_L	=	0x00ec
                           0000ED   354 _UEP0_DMA_H	=	0x00ed
                           00EFEE   355 _UEP1_DMA	=	0xefee
                           0000EE   356 _UEP1_DMA_L	=	0x00ee
                           0000EF   357 _UEP1_DMA_H	=	0x00ef
                                    358 ;--------------------------------------------------------
                                    359 ; special function bits
                                    360 ;--------------------------------------------------------
                                    361 	.area RSEG    (ABS,DATA)
      000000                        362 	.org 0x0000
                           0000D7   363 _CY	=	0x00d7
                           0000D6   364 _AC	=	0x00d6
                           0000D5   365 _F0	=	0x00d5
                           0000D4   366 _RS1	=	0x00d4
                           0000D3   367 _RS0	=	0x00d3
                           0000D2   368 _OV	=	0x00d2
                           0000D1   369 _F1	=	0x00d1
                           0000D0   370 _P	=	0x00d0
                           0000AF   371 _EA	=	0x00af
                           0000AE   372 _E_DIS	=	0x00ae
                           0000AD   373 _ET2	=	0x00ad
                           0000AC   374 _ES	=	0x00ac
                           0000AB   375 _ET1	=	0x00ab
                           0000AA   376 _EX1	=	0x00aa
                           0000A9   377 _ET0	=	0x00a9
                           0000A8   378 _EX0	=	0x00a8
                           0000BF   379 _PH_FLAG	=	0x00bf
                           0000BE   380 _PL_FLAG	=	0x00be
                           0000BD   381 _PT2	=	0x00bd
                           0000BC   382 _PS	=	0x00bc
                           0000BB   383 _PT1	=	0x00bb
                           0000BA   384 _PX1	=	0x00ba
                           0000B9   385 _PT0	=	0x00b9
                           0000B8   386 _PX0	=	0x00b8
                           0000EF   387 _IE_WDOG	=	0x00ef
                           0000EE   388 _IE_GPIO	=	0x00ee
                           0000ED   389 _IE_PWMX	=	0x00ed
                           0000EC   390 _IE_UART1	=	0x00ec
                           0000EB   391 _IE_ADC	=	0x00eb
                           0000EA   392 _IE_USB	=	0x00ea
                           0000E9   393 _IE_TKEY	=	0x00e9
                           0000E8   394 _IE_SPI0	=	0x00e8
                           000097   395 _SCK	=	0x0097
                           000097   396 _TXD1	=	0x0097
                           000097   397 _TIN5	=	0x0097
                           000096   398 _MISO	=	0x0096
                           000096   399 _RXD1	=	0x0096
                           000096   400 _TIN4	=	0x0096
                           000095   401 _MOSI	=	0x0095
                           000095   402 _PWM1	=	0x0095
                           000095   403 _TIN3	=	0x0095
                           000095   404 _UCC2	=	0x0095
                           000095   405 _AIN2	=	0x0095
                           000094   406 _T2_	=	0x0094
                           000094   407 _CAP1_	=	0x0094
                           000094   408 _SCS	=	0x0094
                           000094   409 _TIN2	=	0x0094
                           000094   410 _UCC1	=	0x0094
                           000094   411 _AIN1	=	0x0094
                           000093   412 _TXD_	=	0x0093
                           000092   413 _RXD_	=	0x0092
                           000091   414 _T2EX	=	0x0091
                           000091   415 _CAP2	=	0x0091
                           000091   416 _TIN1	=	0x0091
                           000091   417 _VBUS2	=	0x0091
                           000091   418 _AIN0	=	0x0091
                           000090   419 _T2	=	0x0090
                           000090   420 _CAP1	=	0x0090
                           000090   421 _TIN0	=	0x0090
                           0000B7   422 _UDM	=	0x00b7
                           0000B6   423 _UDP	=	0x00b6
                           0000B5   424 _T1	=	0x00b5
                           0000B4   425 _PWM2	=	0x00b4
                           0000B4   426 _RXD1_	=	0x00b4
                           0000B4   427 _T0	=	0x00b4
                           0000B3   428 _INT1	=	0x00b3
                           0000B2   429 _TXD1_	=	0x00b2
                           0000B2   430 _INT0	=	0x00b2
                           0000B2   431 _VBUS1	=	0x00b2
                           0000B2   432 _AIN3	=	0x00b2
                           0000B1   433 _PWM2_	=	0x00b1
                           0000B1   434 _TXD	=	0x00b1
                           0000B0   435 _PWM1_	=	0x00b0
                           0000B0   436 _RXD	=	0x00b0
                           00008F   437 _TF1	=	0x008f
                           00008E   438 _TR1	=	0x008e
                           00008D   439 _TF0	=	0x008d
                           00008C   440 _TR0	=	0x008c
                           00008B   441 _IE1	=	0x008b
                           00008A   442 _IT1	=	0x008a
                           000089   443 _IE0	=	0x0089
                           000088   444 _IT0	=	0x0088
                           00009F   445 _SM0	=	0x009f
                           00009E   446 _SM1	=	0x009e
                           00009D   447 _SM2	=	0x009d
                           00009C   448 _REN	=	0x009c
                           00009B   449 _TB8	=	0x009b
                           00009A   450 _RB8	=	0x009a
                           000099   451 _TI	=	0x0099
                           000098   452 _RI	=	0x0098
                           0000CF   453 _TF2	=	0x00cf
                           0000CF   454 _CAP1F	=	0x00cf
                           0000CE   455 _EXF2	=	0x00ce
                           0000CD   456 _RCLK	=	0x00cd
                           0000CC   457 _TCLK	=	0x00cc
                           0000CB   458 _EXEN2	=	0x00cb
                           0000CA   459 _TR2	=	0x00ca
                           0000C9   460 _C_T2	=	0x00c9
                           0000C8   461 _CP_RL2	=	0x00c8
                           0000FF   462 _S0_FST_ACT	=	0x00ff
                           0000FE   463 _S0_IF_OV	=	0x00fe
                           0000FD   464 _S0_IF_FIRST	=	0x00fd
                           0000FC   465 _S0_IF_BYTE	=	0x00fc
                           0000FB   466 _S0_FREE	=	0x00fb
                           0000FA   467 _S0_T_FIFO	=	0x00fa
                           0000F8   468 _S0_R_FIFO	=	0x00f8
                           0000C7   469 _U1SM0	=	0x00c7
                           0000C5   470 _U1SMOD	=	0x00c5
                           0000C4   471 _U1REN	=	0x00c4
                           0000C3   472 _U1TB8	=	0x00c3
                           0000C2   473 _U1RB8	=	0x00c2
                           0000C1   474 _U1TI	=	0x00c1
                           0000C0   475 _U1RI	=	0x00c0
                           000087   476 _CMPO	=	0x0087
                           000086   477 _CMP_IF	=	0x0086
                           000085   478 _ADC_IF	=	0x0085
                           000084   479 _ADC_START	=	0x0084
                           000083   480 _CMP_CHAN	=	0x0083
                           000081   481 _ADC_CHAN1	=	0x0081
                           000080   482 _ADC_CHAN0	=	0x0080
                           0000DF   483 _U_IS_NAK	=	0x00df
                           0000DE   484 _U_TOG_OK	=	0x00de
                           0000DD   485 _U_SIE_FREE	=	0x00dd
                           0000DC   486 _UIF_FIFO_OV	=	0x00dc
                           0000DB   487 _UIF_HST_SOF	=	0x00db
                           0000DA   488 _UIF_SUSPEND	=	0x00da
                           0000D9   489 _UIF_TRANSFER	=	0x00d9
                           0000D8   490 _UIF_DETECT	=	0x00d8
                           0000D8   491 _UIF_BUS_RST	=	0x00d8
                                    492 ;--------------------------------------------------------
                                    493 ; overlayable register banks
                                    494 ;--------------------------------------------------------
                                    495 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        496 	.ds 8
                                    497 ;--------------------------------------------------------
                                    498 ; internal ram data
                                    499 ;--------------------------------------------------------
                                    500 	.area DSEG    (DATA)
                                    501 ;--------------------------------------------------------
                                    502 ; overlayable items in internal ram 
                                    503 ;--------------------------------------------------------
                                    504 ;--------------------------------------------------------
                                    505 ; Stack segment in internal ram 
                                    506 ;--------------------------------------------------------
                                    507 	.area	SSEG
      000011                        508 __start__stack:
      000011                        509 	.ds	1
                                    510 
                                    511 ;--------------------------------------------------------
                                    512 ; indirectly addressable internal ram data
                                    513 ;--------------------------------------------------------
                                    514 	.area ISEG    (DATA)
                                    515 ;--------------------------------------------------------
                                    516 ; absolute internal ram data
                                    517 ;--------------------------------------------------------
                                    518 	.area IABS    (ABS,DATA)
                                    519 	.area IABS    (ABS,DATA)
                                    520 ;--------------------------------------------------------
                                    521 ; bit data
                                    522 ;--------------------------------------------------------
                                    523 	.area BSEG    (BIT)
                                    524 ;--------------------------------------------------------
                                    525 ; paged external ram data
                                    526 ;--------------------------------------------------------
                                    527 	.area PSEG    (PAG,XDATA)
                                    528 ;--------------------------------------------------------
                                    529 ; external ram data
                                    530 ;--------------------------------------------------------
                                    531 	.area XSEG    (XDATA)
                                    532 ;--------------------------------------------------------
                                    533 ; absolute external ram data
                                    534 ;--------------------------------------------------------
                                    535 	.area XABS    (ABS,XDATA)
                                    536 ;--------------------------------------------------------
                                    537 ; external initialized ram data
                                    538 ;--------------------------------------------------------
                                    539 	.area XISEG   (XDATA)
                                    540 	.area HOME    (CODE)
                                    541 	.area GSINIT0 (CODE)
                                    542 	.area GSINIT1 (CODE)
                                    543 	.area GSINIT2 (CODE)
                                    544 	.area GSINIT3 (CODE)
                                    545 	.area GSINIT4 (CODE)
                                    546 	.area GSINIT5 (CODE)
                                    547 	.area GSINIT  (CODE)
                                    548 	.area GSFINAL (CODE)
                                    549 	.area CSEG    (CODE)
                                    550 ;--------------------------------------------------------
                                    551 ; interrupt vector 
                                    552 ;--------------------------------------------------------
                                    553 	.area HOME    (CODE)
      000000                        554 __interrupt_vect:
      000000 02 00 06         [24]  555 	ljmp	__sdcc_gsinit_startup
                                    556 ;--------------------------------------------------------
                                    557 ; global & static initialisations
                                    558 ;--------------------------------------------------------
                                    559 	.area HOME    (CODE)
                                    560 	.area GSINIT  (CODE)
                                    561 	.area GSFINAL (CODE)
                                    562 	.area GSINIT  (CODE)
                                    563 	.globl __sdcc_gsinit_startup
                                    564 	.globl __sdcc_program_startup
                                    565 	.globl __start__stack
                                    566 	.globl __mcs51_genXINIT
                                    567 	.globl __mcs51_genXRAMCLEAR
                                    568 	.globl __mcs51_genRAMCLEAR
                                    569 	.area GSFINAL (CODE)
      00005F 02 00 03         [24]  570 	ljmp	__sdcc_program_startup
                                    571 ;--------------------------------------------------------
                                    572 ; Home
                                    573 ;--------------------------------------------------------
                                    574 	.area HOME    (CODE)
                                    575 	.area HOME    (CODE)
      000003                        576 __sdcc_program_startup:
      000003 02 00 62         [24]  577 	ljmp	_main
                                    578 ;	return from main will return to caller
                                    579 ;--------------------------------------------------------
                                    580 ; code
                                    581 ;--------------------------------------------------------
                                    582 	.area CSEG    (CODE)
                                    583 ;------------------------------------------------------------
                                    584 ;Allocation info for local variables in function 'main'
                                    585 ;------------------------------------------------------------
                                    586 ;	main.c:4: void main() {
                                    587 ;	-----------------------------------------
                                    588 ;	 function main
                                    589 ;	-----------------------------------------
      000062                        590 _main:
                           000007   591 	ar7 = 0x07
                           000006   592 	ar6 = 0x06
                           000005   593 	ar5 = 0x05
                           000004   594 	ar4 = 0x04
                           000003   595 	ar3 = 0x03
                           000002   596 	ar2 = 0x02
                           000001   597 	ar1 = 0x01
                           000000   598 	ar0 = 0x00
                                    599 ;	main.c:5: CfgFsys();
      000062 12 00 78         [24]  600 	lcall	_CfgFsys
                                    601 ;	main.c:7: P1_MOD_OC = 0xff;
      000065 75 92 FF         [24]  602 	mov	_P1_MOD_OC,#0xff
                                    603 ;	main.c:8: P1_DIR_PU = 0xff;
      000068 75 93 FF         [24]  604 	mov	_P1_DIR_PU,#0xff
                                    605 ;	main.c:10: while (1) {
      00006B                        606 00102$:
                                    607 ;	main.c:11: mDelaymS(100);
      00006B 90 00 64         [24]  608 	mov	dptr,#0x0064
      00006E 12 00 A2         [24]  609 	lcall	_mDelaymS
                                    610 ;	main.c:12: P1 = ~P1;
      000071 E5 90            [12]  611 	mov	a,_P1
      000073 F4               [12]  612 	cpl	a
      000074 F5 90            [12]  613 	mov	_P1,a
                                    614 ;	main.c:14: }
      000076 80 F3            [24]  615 	sjmp	00102$
                                    616 	.area CSEG    (CODE)
                                    617 	.area CONST   (CODE)
                                    618 	.area XINIT   (CODE)
                                    619 	.area CABS    (ABS,CODE)
