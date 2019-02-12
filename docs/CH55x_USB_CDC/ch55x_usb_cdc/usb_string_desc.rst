                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module usb_string_desc
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _ManuName
                                     12 	.globl _ProductName
                                     13 	.globl _DevName1
                                     14 	.globl _LangDesc
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
                                    249 	.globl _StringDescs
                                    250 ;--------------------------------------------------------
                                    251 ; special function registers
                                    252 ;--------------------------------------------------------
                                    253 	.area RSEG    (ABS,DATA)
      000000                        254 	.org 0x0000
                           0000D0   255 _PSW	=	0x00d0
                           0000E0   256 _ACC	=	0x00e0
                           0000F0   257 _B	=	0x00f0
                           000081   258 _SP	=	0x0081
                           000082   259 _DPL	=	0x0082
                           000083   260 _DPH	=	0x0083
                           0000A1   261 _SAFE_MOD	=	0x00a1
                           0000B1   262 _GLOBAL_CFG	=	0x00b1
                           000087   263 _PCON	=	0x0087
                           0000B9   264 _CLOCK_CFG	=	0x00b9
                           0000A9   265 _WAKE_CTRL	=	0x00a9
                           0000FE   266 _RESET_KEEP	=	0x00fe
                           0000FF   267 _WDOG_COUNT	=	0x00ff
                           0000A8   268 _IE	=	0x00a8
                           0000B8   269 _IP	=	0x00b8
                           0000E8   270 _IE_EX	=	0x00e8
                           0000E9   271 _IP_EX	=	0x00e9
                           0000C7   272 _GPIO_IE	=	0x00c7
                           008584   273 _ROM_ADDR	=	0x8584
                           000084   274 _ROM_ADDR_L	=	0x0084
                           000085   275 _ROM_ADDR_H	=	0x0085
                           008F8E   276 _ROM_DATA	=	0x8f8e
                           00008E   277 _ROM_DATA_L	=	0x008e
                           00008F   278 _ROM_DATA_H	=	0x008f
                           000086   279 _ROM_CTRL	=	0x0086
                           000090   280 _P1	=	0x0090
                           000092   281 _P1_MOD_OC	=	0x0092
                           000093   282 _P1_DIR_PU	=	0x0093
                           0000A0   283 _P2	=	0x00a0
                           0000B0   284 _P3	=	0x00b0
                           000096   285 _P3_MOD_OC	=	0x0096
                           000097   286 _P3_DIR_PU	=	0x0097
                           0000C6   287 _PIN_FUNC	=	0x00c6
                           0000A2   288 _XBUS_AUX	=	0x00a2
                           000088   289 _TCON	=	0x0088
                           000089   290 _TMOD	=	0x0089
                           00008A   291 _TL0	=	0x008a
                           00008B   292 _TL1	=	0x008b
                           00008C   293 _TH0	=	0x008c
                           00008D   294 _TH1	=	0x008d
                           000098   295 _SCON	=	0x0098
                           000099   296 _SBUF	=	0x0099
                           0000C8   297 _T2CON	=	0x00c8
                           0000C9   298 _T2MOD	=	0x00c9
                           00CBCA   299 _RCAP2	=	0xcbca
                           0000CA   300 _RCAP2L	=	0x00ca
                           0000CB   301 _RCAP2H	=	0x00cb
                           00CDCC   302 _T2COUNT	=	0xcdcc
                           0000CC   303 _TL2	=	0x00cc
                           0000CD   304 _TH2	=	0x00cd
                           00CFCE   305 _T2CAP1	=	0xcfce
                           0000CE   306 _T2CAP1L	=	0x00ce
                           0000CF   307 _T2CAP1H	=	0x00cf
                           00009B   308 _PWM_DATA2	=	0x009b
                           00009C   309 _PWM_DATA1	=	0x009c
                           00009D   310 _PWM_CTRL	=	0x009d
                           00009E   311 _PWM_CK_SE	=	0x009e
                           0000F8   312 _SPI0_STAT	=	0x00f8
                           0000F9   313 _SPI0_DATA	=	0x00f9
                           0000FA   314 _SPI0_CTRL	=	0x00fa
                           0000FB   315 _SPI0_CK_SE	=	0x00fb
                           0000FC   316 _SPI0_SETUP	=	0x00fc
                           0000C0   317 _SCON1	=	0x00c0
                           0000C1   318 _SBUF1	=	0x00c1
                           0000C2   319 _SBAUD1	=	0x00c2
                           000080   320 _ADC_CTRL	=	0x0080
                           00009A   321 _ADC_CFG	=	0x009a
                           00009F   322 _ADC_DATA	=	0x009f
                           0000C3   323 _TKEY_CTRL	=	0x00c3
                           00C5C4   324 _TKEY_DAT	=	0xc5c4
                           0000C4   325 _TKEY_DATL	=	0x00c4
                           0000C5   326 _TKEY_DATH	=	0x00c5
                           000091   327 _USB_C_CTRL	=	0x0091
                           0000D1   328 _UDEV_CTRL	=	0x00d1
                           0000D2   329 _UEP1_CTRL	=	0x00d2
                           0000D3   330 _UEP1_T_LEN	=	0x00d3
                           0000D4   331 _UEP2_CTRL	=	0x00d4
                           0000D5   332 _UEP2_T_LEN	=	0x00d5
                           0000D6   333 _UEP3_CTRL	=	0x00d6
                           0000D7   334 _UEP3_T_LEN	=	0x00d7
                           0000D8   335 _USB_INT_FG	=	0x00d8
                           0000D9   336 _USB_INT_ST	=	0x00d9
                           0000DA   337 _USB_MIS_ST	=	0x00da
                           0000DB   338 _USB_RX_LEN	=	0x00db
                           0000DC   339 _UEP0_CTRL	=	0x00dc
                           0000DD   340 _UEP0_T_LEN	=	0x00dd
                           0000DE   341 _UEP4_CTRL	=	0x00de
                           0000DF   342 _UEP4_T_LEN	=	0x00df
                           0000E1   343 _USB_INT_EN	=	0x00e1
                           0000E2   344 _USB_CTRL	=	0x00e2
                           0000E3   345 _USB_DEV_AD	=	0x00e3
                           00E5E4   346 _UEP2_DMA	=	0xe5e4
                           0000E4   347 _UEP2_DMA_L	=	0x00e4
                           0000E5   348 _UEP2_DMA_H	=	0x00e5
                           00E7E6   349 _UEP3_DMA	=	0xe7e6
                           0000E6   350 _UEP3_DMA_L	=	0x00e6
                           0000E7   351 _UEP3_DMA_H	=	0x00e7
                           0000EA   352 _UEP4_1_MOD	=	0x00ea
                           0000EB   353 _UEP2_3_MOD	=	0x00eb
                           00EDEC   354 _UEP0_DMA	=	0xedec
                           0000EC   355 _UEP0_DMA_L	=	0x00ec
                           0000ED   356 _UEP0_DMA_H	=	0x00ed
                           00EFEE   357 _UEP1_DMA	=	0xefee
                           0000EE   358 _UEP1_DMA_L	=	0x00ee
                           0000EF   359 _UEP1_DMA_H	=	0x00ef
                                    360 ;--------------------------------------------------------
                                    361 ; special function bits
                                    362 ;--------------------------------------------------------
                                    363 	.area RSEG    (ABS,DATA)
      000000                        364 	.org 0x0000
                           0000D7   365 _CY	=	0x00d7
                           0000D6   366 _AC	=	0x00d6
                           0000D5   367 _F0	=	0x00d5
                           0000D4   368 _RS1	=	0x00d4
                           0000D3   369 _RS0	=	0x00d3
                           0000D2   370 _OV	=	0x00d2
                           0000D1   371 _F1	=	0x00d1
                           0000D0   372 _P	=	0x00d0
                           0000AF   373 _EA	=	0x00af
                           0000AE   374 _E_DIS	=	0x00ae
                           0000AD   375 _ET2	=	0x00ad
                           0000AC   376 _ES	=	0x00ac
                           0000AB   377 _ET1	=	0x00ab
                           0000AA   378 _EX1	=	0x00aa
                           0000A9   379 _ET0	=	0x00a9
                           0000A8   380 _EX0	=	0x00a8
                           0000BF   381 _PH_FLAG	=	0x00bf
                           0000BE   382 _PL_FLAG	=	0x00be
                           0000BD   383 _PT2	=	0x00bd
                           0000BC   384 _PS	=	0x00bc
                           0000BB   385 _PT1	=	0x00bb
                           0000BA   386 _PX1	=	0x00ba
                           0000B9   387 _PT0	=	0x00b9
                           0000B8   388 _PX0	=	0x00b8
                           0000EF   389 _IE_WDOG	=	0x00ef
                           0000EE   390 _IE_GPIO	=	0x00ee
                           0000ED   391 _IE_PWMX	=	0x00ed
                           0000EC   392 _IE_UART1	=	0x00ec
                           0000EB   393 _IE_ADC	=	0x00eb
                           0000EA   394 _IE_USB	=	0x00ea
                           0000E9   395 _IE_TKEY	=	0x00e9
                           0000E8   396 _IE_SPI0	=	0x00e8
                           000097   397 _SCK	=	0x0097
                           000097   398 _TXD1	=	0x0097
                           000097   399 _TIN5	=	0x0097
                           000096   400 _MISO	=	0x0096
                           000096   401 _RXD1	=	0x0096
                           000096   402 _TIN4	=	0x0096
                           000095   403 _MOSI	=	0x0095
                           000095   404 _PWM1	=	0x0095
                           000095   405 _TIN3	=	0x0095
                           000095   406 _UCC2	=	0x0095
                           000095   407 _AIN2	=	0x0095
                           000094   408 _T2_	=	0x0094
                           000094   409 _CAP1_	=	0x0094
                           000094   410 _SCS	=	0x0094
                           000094   411 _TIN2	=	0x0094
                           000094   412 _UCC1	=	0x0094
                           000094   413 _AIN1	=	0x0094
                           000093   414 _TXD_	=	0x0093
                           000092   415 _RXD_	=	0x0092
                           000091   416 _T2EX	=	0x0091
                           000091   417 _CAP2	=	0x0091
                           000091   418 _TIN1	=	0x0091
                           000091   419 _VBUS2	=	0x0091
                           000091   420 _AIN0	=	0x0091
                           000090   421 _T2	=	0x0090
                           000090   422 _CAP1	=	0x0090
                           000090   423 _TIN0	=	0x0090
                           0000B7   424 _UDM	=	0x00b7
                           0000B6   425 _UDP	=	0x00b6
                           0000B5   426 _T1	=	0x00b5
                           0000B4   427 _PWM2	=	0x00b4
                           0000B4   428 _RXD1_	=	0x00b4
                           0000B4   429 _T0	=	0x00b4
                           0000B3   430 _INT1	=	0x00b3
                           0000B2   431 _TXD1_	=	0x00b2
                           0000B2   432 _INT0	=	0x00b2
                           0000B2   433 _VBUS1	=	0x00b2
                           0000B2   434 _AIN3	=	0x00b2
                           0000B1   435 _PWM2_	=	0x00b1
                           0000B1   436 _TXD	=	0x00b1
                           0000B0   437 _PWM1_	=	0x00b0
                           0000B0   438 _RXD	=	0x00b0
                           00008F   439 _TF1	=	0x008f
                           00008E   440 _TR1	=	0x008e
                           00008D   441 _TF0	=	0x008d
                           00008C   442 _TR0	=	0x008c
                           00008B   443 _IE1	=	0x008b
                           00008A   444 _IT1	=	0x008a
                           000089   445 _IE0	=	0x0089
                           000088   446 _IT0	=	0x0088
                           00009F   447 _SM0	=	0x009f
                           00009E   448 _SM1	=	0x009e
                           00009D   449 _SM2	=	0x009d
                           00009C   450 _REN	=	0x009c
                           00009B   451 _TB8	=	0x009b
                           00009A   452 _RB8	=	0x009a
                           000099   453 _TI	=	0x0099
                           000098   454 _RI	=	0x0098
                           0000CF   455 _TF2	=	0x00cf
                           0000CF   456 _CAP1F	=	0x00cf
                           0000CE   457 _EXF2	=	0x00ce
                           0000CD   458 _RCLK	=	0x00cd
                           0000CC   459 _TCLK	=	0x00cc
                           0000CB   460 _EXEN2	=	0x00cb
                           0000CA   461 _TR2	=	0x00ca
                           0000C9   462 _C_T2	=	0x00c9
                           0000C8   463 _CP_RL2	=	0x00c8
                           0000FF   464 _S0_FST_ACT	=	0x00ff
                           0000FE   465 _S0_IF_OV	=	0x00fe
                           0000FD   466 _S0_IF_FIRST	=	0x00fd
                           0000FC   467 _S0_IF_BYTE	=	0x00fc
                           0000FB   468 _S0_FREE	=	0x00fb
                           0000FA   469 _S0_T_FIFO	=	0x00fa
                           0000F8   470 _S0_R_FIFO	=	0x00f8
                           0000C7   471 _U1SM0	=	0x00c7
                           0000C5   472 _U1SMOD	=	0x00c5
                           0000C4   473 _U1REN	=	0x00c4
                           0000C3   474 _U1TB8	=	0x00c3
                           0000C2   475 _U1RB8	=	0x00c2
                           0000C1   476 _U1TI	=	0x00c1
                           0000C0   477 _U1RI	=	0x00c0
                           000087   478 _CMPO	=	0x0087
                           000086   479 _CMP_IF	=	0x0086
                           000085   480 _ADC_IF	=	0x0085
                           000084   481 _ADC_START	=	0x0084
                           000083   482 _CMP_CHAN	=	0x0083
                           000081   483 _ADC_CHAN1	=	0x0081
                           000080   484 _ADC_CHAN0	=	0x0080
                           0000DF   485 _U_IS_NAK	=	0x00df
                           0000DE   486 _U_TOG_OK	=	0x00de
                           0000DD   487 _U_SIE_FREE	=	0x00dd
                           0000DC   488 _UIF_FIFO_OV	=	0x00dc
                           0000DB   489 _UIF_HST_SOF	=	0x00db
                           0000DA   490 _UIF_SUSPEND	=	0x00da
                           0000D9   491 _UIF_TRANSFER	=	0x00d9
                           0000D8   492 _UIF_DETECT	=	0x00d8
                           0000D8   493 _UIF_BUS_RST	=	0x00d8
                                    494 ;--------------------------------------------------------
                                    495 ; overlayable register banks
                                    496 ;--------------------------------------------------------
                                    497 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        498 	.ds 8
                                    499 ;--------------------------------------------------------
                                    500 ; internal ram data
                                    501 ;--------------------------------------------------------
                                    502 	.area DSEG    (DATA)
      000016                        503 _StringDescs::
      000016                        504 	.ds 8
                                    505 ;--------------------------------------------------------
                                    506 ; overlayable items in internal ram 
                                    507 ;--------------------------------------------------------
                                    508 ;--------------------------------------------------------
                                    509 ; indirectly addressable internal ram data
                                    510 ;--------------------------------------------------------
                                    511 	.area ISEG    (DATA)
                                    512 ;--------------------------------------------------------
                                    513 ; absolute internal ram data
                                    514 ;--------------------------------------------------------
                                    515 	.area IABS    (ABS,DATA)
                                    516 	.area IABS    (ABS,DATA)
                                    517 ;--------------------------------------------------------
                                    518 ; bit data
                                    519 ;--------------------------------------------------------
                                    520 	.area BSEG    (BIT)
                                    521 ;--------------------------------------------------------
                                    522 ; paged external ram data
                                    523 ;--------------------------------------------------------
                                    524 	.area PSEG    (PAG,XDATA)
                                    525 ;--------------------------------------------------------
                                    526 ; external ram data
                                    527 ;--------------------------------------------------------
                                    528 	.area XSEG    (XDATA)
                                    529 ;--------------------------------------------------------
                                    530 ; absolute external ram data
                                    531 ;--------------------------------------------------------
                                    532 	.area XABS    (ABS,XDATA)
                                    533 ;--------------------------------------------------------
                                    534 ; external initialized ram data
                                    535 ;--------------------------------------------------------
                                    536 	.area XISEG   (XDATA)
                                    537 	.area HOME    (CODE)
                                    538 	.area GSINIT0 (CODE)
                                    539 	.area GSINIT1 (CODE)
                                    540 	.area GSINIT2 (CODE)
                                    541 	.area GSINIT3 (CODE)
                                    542 	.area GSINIT4 (CODE)
                                    543 	.area GSINIT5 (CODE)
                                    544 	.area GSINIT  (CODE)
                                    545 	.area GSFINAL (CODE)
                                    546 	.area CSEG    (CODE)
                                    547 ;--------------------------------------------------------
                                    548 ; global & static initialisations
                                    549 ;--------------------------------------------------------
                                    550 	.area HOME    (CODE)
                                    551 	.area GSINIT  (CODE)
                                    552 	.area GSFINAL (CODE)
                                    553 	.area GSINIT  (CODE)
                                    554 ;	usb_string_desc.c:27: code const uint8_t* StringDescs[USB_STRINGDESC_COUNT] = {	
      000195 75 16 C8         [24]  555 	mov	(_StringDescs + 0),#_LangDesc
      000198 75 17 0E         [24]  556 	mov	(_StringDescs + 1),#(_LangDesc >> 8)
      00019B 75 18 E0         [24]  557 	mov	((_StringDescs + 0x0002) + 0),#_ProductName
      00019E 75 19 0E         [24]  558 	mov	((_StringDescs + 0x0002) + 1),#(_ProductName >> 8)
      0001A1 75 1A 06         [24]  559 	mov	((_StringDescs + 0x0004) + 0),#_ManuName
      0001A4 75 1B 0F         [24]  560 	mov	((_StringDescs + 0x0004) + 1),#(_ManuName >> 8)
      0001A7 75 1C CC         [24]  561 	mov	((_StringDescs + 0x0006) + 0),#_DevName1
      0001AA 75 1D 0E         [24]  562 	mov	((_StringDescs + 0x0006) + 1),#(_DevName1 >> 8)
                                    563 ;--------------------------------------------------------
                                    564 ; Home
                                    565 ;--------------------------------------------------------
                                    566 	.area HOME    (CODE)
                                    567 	.area HOME    (CODE)
                                    568 ;--------------------------------------------------------
                                    569 ; code
                                    570 ;--------------------------------------------------------
                                    571 	.area CSEG    (CODE)
                                    572 	.area CSEG    (CODE)
                                    573 	.area CONST   (CODE)
      000EC8                        574 _LangDesc:
      000EC8 04                     575 	.db #0x04	; 4
      000EC9 03                     576 	.db #0x03	; 3
      000ECA 09                     577 	.db #0x09	; 9
      000ECB 04                     578 	.db #0x04	; 4
      000ECC                        579 _DevName1:
      000ECC 14                     580 	.db #0x14	; 20
      000ECD 03                     581 	.db #0x03	; 3
      000ECE 43                     582 	.db #0x43	; 67	'C'
      000ECF 00                     583 	.db #0x00	; 0
      000ED0 48                     584 	.db #0x48	; 72	'H'
      000ED1 00                     585 	.db #0x00	; 0
      000ED2 35                     586 	.db #0x35	; 53	'5'
      000ED3 00                     587 	.db #0x00	; 0
      000ED4 35                     588 	.db #0x35	; 53	'5'
      000ED5 00                     589 	.db #0x00	; 0
      000ED6 34                     590 	.db #0x34	; 52	'4'
      000ED7 00                     591 	.db #0x00	; 0
      000ED8 20                     592 	.db #0x20	; 32
      000ED9 00                     593 	.db #0x00	; 0
      000EDA 43                     594 	.db #0x43	; 67	'C'
      000EDB 00                     595 	.db #0x00	; 0
      000EDC 44                     596 	.db #0x44	; 68	'D'
      000EDD 00                     597 	.db #0x00	; 0
      000EDE 43                     598 	.db #0x43	; 67	'C'
      000EDF 00                     599 	.db #0x00	; 0
      000EE0                        600 _ProductName:
      000EE0 26                     601 	.db #0x26	; 38
      000EE1 03                     602 	.db #0x03	; 3
      000EE2 52                     603 	.db #0x52	; 82	'R'
      000EE3 00                     604 	.db #0x00	; 0
      000EE4 69                     605 	.db #0x69	; 105	'i'
      000EE5 00                     606 	.db #0x00	; 0
      000EE6 6B                     607 	.db #0x6b	; 107	'k'
      000EE7 00                     608 	.db #0x00	; 0
      000EE8 6B                     609 	.db #0x6b	; 107	'k'
      000EE9 00                     610 	.db #0x00	; 0
      000EEA 61                     611 	.db #0x61	; 97	'a'
      000EEB 00                     612 	.db #0x00	; 0
      000EEC 60                     613 	.db #0x60	; 96
      000EED 00                     614 	.db #0x00	; 0
      000EEE 73                     615 	.db #0x73	; 115	's'
      000EEF 00                     616 	.db #0x00	; 0
      000EF0 20                     617 	.db #0x20	; 32
      000EF1 00                     618 	.db #0x00	; 0
      000EF2 43                     619 	.db #0x43	; 67	'C'
      000EF3 00                     620 	.db #0x00	; 0
      000EF4 48                     621 	.db #0x48	; 72	'H'
      000EF5 00                     622 	.db #0x00	; 0
      000EF6 35                     623 	.db #0x35	; 53	'5'
      000EF7 00                     624 	.db #0x00	; 0
      000EF8 35                     625 	.db #0x35	; 53	'5'
      000EF9 00                     626 	.db #0x00	; 0
      000EFA 34                     627 	.db #0x34	; 52	'4'
      000EFB 00                     628 	.db #0x00	; 0
      000EFC 20                     629 	.db #0x20	; 32
      000EFD 00                     630 	.db #0x00	; 0
      000EFE 44                     631 	.db #0x44	; 68	'D'
      000EFF 00                     632 	.db #0x00	; 0
      000F00 65                     633 	.db #0x65	; 101	'e'
      000F01 00                     634 	.db #0x00	; 0
      000F02 6D                     635 	.db #0x6d	; 109	'm'
      000F03 00                     636 	.db #0x00	; 0
      000F04 6F                     637 	.db #0x6f	; 111	'o'
      000F05 00                     638 	.db #0x00	; 0
      000F06                        639 _ManuName:
      000F06 12                     640 	.db #0x12	; 18
      000F07 03                     641 	.db #0x03	; 3
      000F08 52                     642 	.db #0x52	; 82	'R'
      000F09 00                     643 	.db #0x00	; 0
      000F0A 69                     644 	.db #0x69	; 105	'i'
      000F0B 00                     645 	.db #0x00	; 0
      000F0C 6B                     646 	.db #0x6b	; 107	'k'
      000F0D 00                     647 	.db #0x00	; 0
      000F0E 6B                     648 	.db #0x6b	; 107	'k'
      000F0F 00                     649 	.db #0x00	; 0
      000F10 61                     650 	.db #0x61	; 97	'a'
      000F11 00                     651 	.db #0x00	; 0
      000F12 30                     652 	.db #0x30	; 48	'0'
      000F13 00                     653 	.db #0x00	; 0
      000F14 77                     654 	.db #0x77	; 119	'w'
      000F15 00                     655 	.db #0x00	; 0
      000F16 30                     656 	.db #0x30	; 48	'0'
      000F17 00                     657 	.db #0x00	; 0
                                    658 	.area XINIT   (CODE)
                                    659 	.area CABS    (ABS,CODE)
