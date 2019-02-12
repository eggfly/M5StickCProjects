                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module usb_ep0
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _memcpy
                                     12 	.globl _CDC_SetBaud
                                     13 	.globl _USB_EP_HALT_CLEAR
                                     14 	.globl _USB_EP_HALT_SET
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
                                    249 	.globl _Ep0Buffer
                                    250 	.globl _controlStates
                                    251 	.globl _pDescr
                                    252 	.globl _UsbConfig
                                    253 	.globl _SetupLen
                                    254 	.globl _SetupReq
                                    255 	.globl _USB_EP0_SETUP
                                    256 	.globl _USB_EP0_IN
                                    257 	.globl _USB_EP0_OUT
                                    258 ;--------------------------------------------------------
                                    259 ; special function registers
                                    260 ;--------------------------------------------------------
                                    261 	.area RSEG    (ABS,DATA)
      000000                        262 	.org 0x0000
                           0000D0   263 _PSW	=	0x00d0
                           0000E0   264 _ACC	=	0x00e0
                           0000F0   265 _B	=	0x00f0
                           000081   266 _SP	=	0x0081
                           000082   267 _DPL	=	0x0082
                           000083   268 _DPH	=	0x0083
                           0000A1   269 _SAFE_MOD	=	0x00a1
                           0000B1   270 _GLOBAL_CFG	=	0x00b1
                           000087   271 _PCON	=	0x0087
                           0000B9   272 _CLOCK_CFG	=	0x00b9
                           0000A9   273 _WAKE_CTRL	=	0x00a9
                           0000FE   274 _RESET_KEEP	=	0x00fe
                           0000FF   275 _WDOG_COUNT	=	0x00ff
                           0000A8   276 _IE	=	0x00a8
                           0000B8   277 _IP	=	0x00b8
                           0000E8   278 _IE_EX	=	0x00e8
                           0000E9   279 _IP_EX	=	0x00e9
                           0000C7   280 _GPIO_IE	=	0x00c7
                           008584   281 _ROM_ADDR	=	0x8584
                           000084   282 _ROM_ADDR_L	=	0x0084
                           000085   283 _ROM_ADDR_H	=	0x0085
                           008F8E   284 _ROM_DATA	=	0x8f8e
                           00008E   285 _ROM_DATA_L	=	0x008e
                           00008F   286 _ROM_DATA_H	=	0x008f
                           000086   287 _ROM_CTRL	=	0x0086
                           000090   288 _P1	=	0x0090
                           000092   289 _P1_MOD_OC	=	0x0092
                           000093   290 _P1_DIR_PU	=	0x0093
                           0000A0   291 _P2	=	0x00a0
                           0000B0   292 _P3	=	0x00b0
                           000096   293 _P3_MOD_OC	=	0x0096
                           000097   294 _P3_DIR_PU	=	0x0097
                           0000C6   295 _PIN_FUNC	=	0x00c6
                           0000A2   296 _XBUS_AUX	=	0x00a2
                           000088   297 _TCON	=	0x0088
                           000089   298 _TMOD	=	0x0089
                           00008A   299 _TL0	=	0x008a
                           00008B   300 _TL1	=	0x008b
                           00008C   301 _TH0	=	0x008c
                           00008D   302 _TH1	=	0x008d
                           000098   303 _SCON	=	0x0098
                           000099   304 _SBUF	=	0x0099
                           0000C8   305 _T2CON	=	0x00c8
                           0000C9   306 _T2MOD	=	0x00c9
                           00CBCA   307 _RCAP2	=	0xcbca
                           0000CA   308 _RCAP2L	=	0x00ca
                           0000CB   309 _RCAP2H	=	0x00cb
                           00CDCC   310 _T2COUNT	=	0xcdcc
                           0000CC   311 _TL2	=	0x00cc
                           0000CD   312 _TH2	=	0x00cd
                           00CFCE   313 _T2CAP1	=	0xcfce
                           0000CE   314 _T2CAP1L	=	0x00ce
                           0000CF   315 _T2CAP1H	=	0x00cf
                           00009B   316 _PWM_DATA2	=	0x009b
                           00009C   317 _PWM_DATA1	=	0x009c
                           00009D   318 _PWM_CTRL	=	0x009d
                           00009E   319 _PWM_CK_SE	=	0x009e
                           0000F8   320 _SPI0_STAT	=	0x00f8
                           0000F9   321 _SPI0_DATA	=	0x00f9
                           0000FA   322 _SPI0_CTRL	=	0x00fa
                           0000FB   323 _SPI0_CK_SE	=	0x00fb
                           0000FC   324 _SPI0_SETUP	=	0x00fc
                           0000C0   325 _SCON1	=	0x00c0
                           0000C1   326 _SBUF1	=	0x00c1
                           0000C2   327 _SBAUD1	=	0x00c2
                           000080   328 _ADC_CTRL	=	0x0080
                           00009A   329 _ADC_CFG	=	0x009a
                           00009F   330 _ADC_DATA	=	0x009f
                           0000C3   331 _TKEY_CTRL	=	0x00c3
                           00C5C4   332 _TKEY_DAT	=	0xc5c4
                           0000C4   333 _TKEY_DATL	=	0x00c4
                           0000C5   334 _TKEY_DATH	=	0x00c5
                           000091   335 _USB_C_CTRL	=	0x0091
                           0000D1   336 _UDEV_CTRL	=	0x00d1
                           0000D2   337 _UEP1_CTRL	=	0x00d2
                           0000D3   338 _UEP1_T_LEN	=	0x00d3
                           0000D4   339 _UEP2_CTRL	=	0x00d4
                           0000D5   340 _UEP2_T_LEN	=	0x00d5
                           0000D6   341 _UEP3_CTRL	=	0x00d6
                           0000D7   342 _UEP3_T_LEN	=	0x00d7
                           0000D8   343 _USB_INT_FG	=	0x00d8
                           0000D9   344 _USB_INT_ST	=	0x00d9
                           0000DA   345 _USB_MIS_ST	=	0x00da
                           0000DB   346 _USB_RX_LEN	=	0x00db
                           0000DC   347 _UEP0_CTRL	=	0x00dc
                           0000DD   348 _UEP0_T_LEN	=	0x00dd
                           0000DE   349 _UEP4_CTRL	=	0x00de
                           0000DF   350 _UEP4_T_LEN	=	0x00df
                           0000E1   351 _USB_INT_EN	=	0x00e1
                           0000E2   352 _USB_CTRL	=	0x00e2
                           0000E3   353 _USB_DEV_AD	=	0x00e3
                           00E5E4   354 _UEP2_DMA	=	0xe5e4
                           0000E4   355 _UEP2_DMA_L	=	0x00e4
                           0000E5   356 _UEP2_DMA_H	=	0x00e5
                           00E7E6   357 _UEP3_DMA	=	0xe7e6
                           0000E6   358 _UEP3_DMA_L	=	0x00e6
                           0000E7   359 _UEP3_DMA_H	=	0x00e7
                           0000EA   360 _UEP4_1_MOD	=	0x00ea
                           0000EB   361 _UEP2_3_MOD	=	0x00eb
                           00EDEC   362 _UEP0_DMA	=	0xedec
                           0000EC   363 _UEP0_DMA_L	=	0x00ec
                           0000ED   364 _UEP0_DMA_H	=	0x00ed
                           00EFEE   365 _UEP1_DMA	=	0xefee
                           0000EE   366 _UEP1_DMA_L	=	0x00ee
                           0000EF   367 _UEP1_DMA_H	=	0x00ef
                                    368 ;--------------------------------------------------------
                                    369 ; special function bits
                                    370 ;--------------------------------------------------------
                                    371 	.area RSEG    (ABS,DATA)
      000000                        372 	.org 0x0000
                           0000D7   373 _CY	=	0x00d7
                           0000D6   374 _AC	=	0x00d6
                           0000D5   375 _F0	=	0x00d5
                           0000D4   376 _RS1	=	0x00d4
                           0000D3   377 _RS0	=	0x00d3
                           0000D2   378 _OV	=	0x00d2
                           0000D1   379 _F1	=	0x00d1
                           0000D0   380 _P	=	0x00d0
                           0000AF   381 _EA	=	0x00af
                           0000AE   382 _E_DIS	=	0x00ae
                           0000AD   383 _ET2	=	0x00ad
                           0000AC   384 _ES	=	0x00ac
                           0000AB   385 _ET1	=	0x00ab
                           0000AA   386 _EX1	=	0x00aa
                           0000A9   387 _ET0	=	0x00a9
                           0000A8   388 _EX0	=	0x00a8
                           0000BF   389 _PH_FLAG	=	0x00bf
                           0000BE   390 _PL_FLAG	=	0x00be
                           0000BD   391 _PT2	=	0x00bd
                           0000BC   392 _PS	=	0x00bc
                           0000BB   393 _PT1	=	0x00bb
                           0000BA   394 _PX1	=	0x00ba
                           0000B9   395 _PT0	=	0x00b9
                           0000B8   396 _PX0	=	0x00b8
                           0000EF   397 _IE_WDOG	=	0x00ef
                           0000EE   398 _IE_GPIO	=	0x00ee
                           0000ED   399 _IE_PWMX	=	0x00ed
                           0000EC   400 _IE_UART1	=	0x00ec
                           0000EB   401 _IE_ADC	=	0x00eb
                           0000EA   402 _IE_USB	=	0x00ea
                           0000E9   403 _IE_TKEY	=	0x00e9
                           0000E8   404 _IE_SPI0	=	0x00e8
                           000097   405 _SCK	=	0x0097
                           000097   406 _TXD1	=	0x0097
                           000097   407 _TIN5	=	0x0097
                           000096   408 _MISO	=	0x0096
                           000096   409 _RXD1	=	0x0096
                           000096   410 _TIN4	=	0x0096
                           000095   411 _MOSI	=	0x0095
                           000095   412 _PWM1	=	0x0095
                           000095   413 _TIN3	=	0x0095
                           000095   414 _UCC2	=	0x0095
                           000095   415 _AIN2	=	0x0095
                           000094   416 _T2_	=	0x0094
                           000094   417 _CAP1_	=	0x0094
                           000094   418 _SCS	=	0x0094
                           000094   419 _TIN2	=	0x0094
                           000094   420 _UCC1	=	0x0094
                           000094   421 _AIN1	=	0x0094
                           000093   422 _TXD_	=	0x0093
                           000092   423 _RXD_	=	0x0092
                           000091   424 _T2EX	=	0x0091
                           000091   425 _CAP2	=	0x0091
                           000091   426 _TIN1	=	0x0091
                           000091   427 _VBUS2	=	0x0091
                           000091   428 _AIN0	=	0x0091
                           000090   429 _T2	=	0x0090
                           000090   430 _CAP1	=	0x0090
                           000090   431 _TIN0	=	0x0090
                           0000B7   432 _UDM	=	0x00b7
                           0000B6   433 _UDP	=	0x00b6
                           0000B5   434 _T1	=	0x00b5
                           0000B4   435 _PWM2	=	0x00b4
                           0000B4   436 _RXD1_	=	0x00b4
                           0000B4   437 _T0	=	0x00b4
                           0000B3   438 _INT1	=	0x00b3
                           0000B2   439 _TXD1_	=	0x00b2
                           0000B2   440 _INT0	=	0x00b2
                           0000B2   441 _VBUS1	=	0x00b2
                           0000B2   442 _AIN3	=	0x00b2
                           0000B1   443 _PWM2_	=	0x00b1
                           0000B1   444 _TXD	=	0x00b1
                           0000B0   445 _PWM1_	=	0x00b0
                           0000B0   446 _RXD	=	0x00b0
                           00008F   447 _TF1	=	0x008f
                           00008E   448 _TR1	=	0x008e
                           00008D   449 _TF0	=	0x008d
                           00008C   450 _TR0	=	0x008c
                           00008B   451 _IE1	=	0x008b
                           00008A   452 _IT1	=	0x008a
                           000089   453 _IE0	=	0x0089
                           000088   454 _IT0	=	0x0088
                           00009F   455 _SM0	=	0x009f
                           00009E   456 _SM1	=	0x009e
                           00009D   457 _SM2	=	0x009d
                           00009C   458 _REN	=	0x009c
                           00009B   459 _TB8	=	0x009b
                           00009A   460 _RB8	=	0x009a
                           000099   461 _TI	=	0x0099
                           000098   462 _RI	=	0x0098
                           0000CF   463 _TF2	=	0x00cf
                           0000CF   464 _CAP1F	=	0x00cf
                           0000CE   465 _EXF2	=	0x00ce
                           0000CD   466 _RCLK	=	0x00cd
                           0000CC   467 _TCLK	=	0x00cc
                           0000CB   468 _EXEN2	=	0x00cb
                           0000CA   469 _TR2	=	0x00ca
                           0000C9   470 _C_T2	=	0x00c9
                           0000C8   471 _CP_RL2	=	0x00c8
                           0000FF   472 _S0_FST_ACT	=	0x00ff
                           0000FE   473 _S0_IF_OV	=	0x00fe
                           0000FD   474 _S0_IF_FIRST	=	0x00fd
                           0000FC   475 _S0_IF_BYTE	=	0x00fc
                           0000FB   476 _S0_FREE	=	0x00fb
                           0000FA   477 _S0_T_FIFO	=	0x00fa
                           0000F8   478 _S0_R_FIFO	=	0x00f8
                           0000C7   479 _U1SM0	=	0x00c7
                           0000C5   480 _U1SMOD	=	0x00c5
                           0000C4   481 _U1REN	=	0x00c4
                           0000C3   482 _U1TB8	=	0x00c3
                           0000C2   483 _U1RB8	=	0x00c2
                           0000C1   484 _U1TI	=	0x00c1
                           0000C0   485 _U1RI	=	0x00c0
                           000087   486 _CMPO	=	0x0087
                           000086   487 _CMP_IF	=	0x0086
                           000085   488 _ADC_IF	=	0x0085
                           000084   489 _ADC_START	=	0x0084
                           000083   490 _CMP_CHAN	=	0x0083
                           000081   491 _ADC_CHAN1	=	0x0081
                           000080   492 _ADC_CHAN0	=	0x0080
                           0000DF   493 _U_IS_NAK	=	0x00df
                           0000DE   494 _U_TOG_OK	=	0x00de
                           0000DD   495 _U_SIE_FREE	=	0x00dd
                           0000DC   496 _UIF_FIFO_OV	=	0x00dc
                           0000DB   497 _UIF_HST_SOF	=	0x00db
                           0000DA   498 _UIF_SUSPEND	=	0x00da
                           0000D9   499 _UIF_TRANSFER	=	0x00d9
                           0000D8   500 _UIF_DETECT	=	0x00d8
                           0000D8   501 _UIF_BUS_RST	=	0x00d8
                                    502 ;--------------------------------------------------------
                                    503 ; overlayable register banks
                                    504 ;--------------------------------------------------------
                                    505 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        506 	.ds 8
                                    507 ;--------------------------------------------------------
                                    508 ; internal ram data
                                    509 ;--------------------------------------------------------
                                    510 	.area DSEG    (DATA)
      00000E                        511 _SetupReq::
      00000E                        512 	.ds 1
      00000F                        513 _SetupLen::
      00000F                        514 	.ds 1
      000010                        515 _UsbConfig::
      000010                        516 	.ds 1
      000011                        517 _pDescr::
      000011                        518 	.ds 3
      000014                        519 _controlStates::
      000014                        520 	.ds 2
                                    521 ;--------------------------------------------------------
                                    522 ; overlayable items in internal ram 
                                    523 ;--------------------------------------------------------
                                    524 ;--------------------------------------------------------
                                    525 ; indirectly addressable internal ram data
                                    526 ;--------------------------------------------------------
                                    527 	.area ISEG    (DATA)
                                    528 ;--------------------------------------------------------
                                    529 ; absolute internal ram data
                                    530 ;--------------------------------------------------------
                                    531 	.area IABS    (ABS,DATA)
                                    532 	.area IABS    (ABS,DATA)
                                    533 ;--------------------------------------------------------
                                    534 ; bit data
                                    535 ;--------------------------------------------------------
                                    536 	.area BSEG    (BIT)
                                    537 ;--------------------------------------------------------
                                    538 ; paged external ram data
                                    539 ;--------------------------------------------------------
                                    540 	.area PSEG    (PAG,XDATA)
                                    541 ;--------------------------------------------------------
                                    542 ; external ram data
                                    543 ;--------------------------------------------------------
                                    544 	.area XSEG    (XDATA)
                           000000   545 _Ep0Buffer	=	0x0000
                                    546 ;--------------------------------------------------------
                                    547 ; absolute external ram data
                                    548 ;--------------------------------------------------------
                                    549 	.area XABS    (ABS,XDATA)
                                    550 ;--------------------------------------------------------
                                    551 ; external initialized ram data
                                    552 ;--------------------------------------------------------
                                    553 	.area XISEG   (XDATA)
                                    554 	.area HOME    (CODE)
                                    555 	.area GSINIT0 (CODE)
                                    556 	.area GSINIT1 (CODE)
                                    557 	.area GSINIT2 (CODE)
                                    558 	.area GSINIT3 (CODE)
                                    559 	.area GSINIT4 (CODE)
                                    560 	.area GSINIT5 (CODE)
                                    561 	.area GSINIT  (CODE)
                                    562 	.area GSFINAL (CODE)
                                    563 	.area CSEG    (CODE)
                                    564 ;--------------------------------------------------------
                                    565 ; global & static initialisations
                                    566 ;--------------------------------------------------------
                                    567 	.area HOME    (CODE)
                                    568 	.area GSINIT  (CODE)
                                    569 	.area GSFINAL (CODE)
                                    570 	.area GSINIT  (CODE)
                                    571 ;	usb_ep0.c:24: uint8_t controlStates[2] = {0x00, 0x00};
      000117 75 14 00         [24]  572 	mov	_controlStates,#0x00
      00011A 75 15 00         [24]  573 	mov	(_controlStates + 0x0001),#0x00
                                    574 ;--------------------------------------------------------
                                    575 ; Home
                                    576 ;--------------------------------------------------------
                                    577 	.area HOME    (CODE)
                                    578 	.area HOME    (CODE)
                                    579 ;--------------------------------------------------------
                                    580 ; code
                                    581 ;--------------------------------------------------------
                                    582 	.area CSEG    (CODE)
                                    583 ;------------------------------------------------------------
                                    584 ;Allocation info for local variables in function 'USB_EP0_SETUP'
                                    585 ;------------------------------------------------------------
                                    586 ;len                       Allocated to registers r5 
                                    587 ;------------------------------------------------------------
                                    588 ;	usb_ep0.c:28: void USB_EP0_SETUP(void) {
                                    589 ;	-----------------------------------------
                                    590 ;	 function USB_EP0_SETUP
                                    591 ;	-----------------------------------------
      00091C                        592 _USB_EP0_SETUP:
                           000007   593 	ar7 = 0x07
                           000006   594 	ar6 = 0x06
                           000005   595 	ar5 = 0x05
                           000004   596 	ar4 = 0x04
                           000003   597 	ar3 = 0x03
                           000002   598 	ar2 = 0x02
                           000001   599 	ar1 = 0x01
                           000000   600 	ar0 = 0x00
                                    601 ;	usb_ep0.c:29: uint8_t len = USB_RX_LEN;
      00091C AF DB            [24]  602 	mov	r7,_USB_RX_LEN
                                    603 ;	usb_ep0.c:30: if (len == (sizeof(USB_SETUP_REQ))) {
      00091E BF 08 02         [24]  604 	cjne	r7,#0x08,00289$
      000921 80 03            [24]  605 	sjmp	00290$
      000923                        606 00289$:
      000923 02 0B 5B         [24]  607 	ljmp	00158$
      000926                        608 00290$:
                                    609 ;	usb_ep0.c:31: SetupLen = UsbSetupBuf->wLengthL;
      000926 90 00 06         [24]  610 	mov	dptr,#(_Ep0Buffer + 0x0006)
      000929 E0               [24]  611 	movx	a,@dptr
      00092A F5 0F            [12]  612 	mov	_SetupLen,a
                                    613 ;	usb_ep0.c:32: if (UsbSetupBuf->wLengthH || SetupLen > 0x7F)
      00092C 90 00 07         [24]  614 	mov	dptr,#(_Ep0Buffer + 0x0007)
      00092F E0               [24]  615 	movx	a,@dptr
      000930 70 06            [24]  616 	jnz	00101$
      000932 E5 0F            [12]  617 	mov	a,_SetupLen
      000934 24 80            [12]  618 	add	a,#0xff - 0x7f
      000936 50 03            [24]  619 	jnc	00102$
      000938                        620 00101$:
                                    621 ;	usb_ep0.c:33: SetupLen = 0x7F;	// Limit the total length
      000938 75 0F 7F         [24]  622 	mov	_SetupLen,#0x7f
      00093B                        623 00102$:
                                    624 ;	usb_ep0.c:35: len = 0;	// Assume success -> Tx 0-length packet
      00093B 7F 00            [12]  625 	mov	r7,#0x00
                                    626 ;	usb_ep0.c:36: SetupReq = UsbSetupBuf->bRequest;
      00093D 90 00 01         [24]  627 	mov	dptr,#(_Ep0Buffer + 0x0001)
      000940 E0               [24]  628 	movx	a,@dptr
      000941 F5 0E            [12]  629 	mov	_SetupReq,a
                                    630 ;	usb_ep0.c:38: if ((UsbSetupBuf->bRequestType & USB_REQ_TYP_MASK) == USB_REQ_TYP_STANDARD) {
      000943 90 00 00         [24]  631 	mov	dptr,#_Ep0Buffer
      000946 E0               [24]  632 	movx	a,@dptr
      000947 FE               [12]  633 	mov	r6,a
      000948 54 60            [12]  634 	anl	a,#0x60
      00094A 60 03            [24]  635 	jz	00294$
      00094C 02 0A E0         [24]  636 	ljmp	00155$
      00094F                        637 00294$:
                                    638 ;	usb_ep0.c:40: switch (SetupReq) {
      00094F E5 0E            [12]  639 	mov	a,_SetupReq
      000951 24 F5            [12]  640 	add	a,#0xff - 0x0a
      000953 50 03            [24]  641 	jnc	00295$
      000955 02 0A DB         [24]  642 	ljmp	00140$
      000958                        643 00295$:
      000958 E5 0E            [12]  644 	mov	a,_SetupReq
      00095A 24 0B            [12]  645 	add	a,#(00296$-3-.)
      00095C 83               [24]  646 	movc	a,@a+pc
      00095D F5 82            [12]  647 	mov	dpl,a
      00095F E5 0E            [12]  648 	mov	a,_SetupReq
      000961 24 0F            [12]  649 	add	a,#(00297$-3-.)
      000963 83               [24]  650 	movc	a,@a+pc
      000964 F5 83            [12]  651 	mov	dph,a
      000966 E4               [12]  652 	clr	a
      000967 73               [24]  653 	jmp	@a+dptr
      000968                        654 00296$:
      000968 C2                     655 	.db	00136$
      000969 60                     656 	.db	00125$
      00096A DB                     657 	.db	00140$
      00096B 83                     658 	.db	00129$
      00096C DB                     659 	.db	00140$
      00096D 3A                     660 	.db	00119$
      00096E 7E                     661 	.db	00104$
      00096F DB                     662 	.db	00140$
      000970 43                     663 	.db	00120$
      000971 57                     664 	.db	00123$
      000972 5D                     665 	.db	00159$
      000973                        666 00297$:
      000973 0A                     667 	.db	00136$>>8
      000974 0A                     668 	.db	00125$>>8
      000975 0A                     669 	.db	00140$>>8
      000976 0A                     670 	.db	00129$>>8
      000977 0A                     671 	.db	00140$>>8
      000978 0A                     672 	.db	00119$>>8
      000979 09                     673 	.db	00104$>>8
      00097A 0A                     674 	.db	00140$>>8
      00097B 0A                     675 	.db	00120$>>8
      00097C 0A                     676 	.db	00123$>>8
      00097D 0B                     677 	.db	00159$>>8
                                    678 ;	usb_ep0.c:41: case USB_GET_DESCRIPTOR: 
      00097E                        679 00104$:
                                    680 ;	usb_ep0.c:42: switch (UsbSetupBuf->wValueH) {
      00097E 90 00 03         [24]  681 	mov	dptr,#(_Ep0Buffer + 0x0003)
      000981 E0               [24]  682 	movx	a,@dptr
      000982 FE               [12]  683 	mov	r6,a
      000983 BE 01 02         [24]  684 	cjne	r6,#0x01,00298$
      000986 80 0F            [24]  685 	sjmp	00105$
      000988                        686 00298$:
      000988 BE 02 02         [24]  687 	cjne	r6,#0x02,00299$
      00098B 80 17            [24]  688 	sjmp	00106$
      00098D                        689 00299$:
      00098D BE 03 02         [24]  690 	cjne	r6,#0x03,00300$
      000990 80 1F            [24]  691 	sjmp	00107$
      000992                        692 00300$:
                                    693 ;	usb_ep0.c:43: case 1:												// Device Descriptor
      000992 BE 22 5B         [24]  694 	cjne	r6,#0x22,00115$
      000995 80 4B            [24]  695 	sjmp	00111$
      000997                        696 00105$:
                                    697 ;	usb_ep0.c:44: pDescr = (uint8_t*)&DevDesc;
      000997 75 11 6B         [24]  698 	mov	_pDescr,#_DevDesc
      00099A 75 12 0E         [24]  699 	mov	(_pDescr + 1),#(_DevDesc >> 8)
      00099D 75 13 80         [24]  700 	mov	(_pDescr + 2),#0x80
                                    701 ;	usb_ep0.c:45: len = USB_DESCSIZE_DEVICE;
      0009A0 7E 12            [12]  702 	mov	r6,#0x12
                                    703 ;	usb_ep0.c:46: break;
                                    704 ;	usb_ep0.c:47: case 2:												// Configure Descriptor
      0009A2 80 4E            [24]  705 	sjmp	00116$
      0009A4                        706 00106$:
                                    707 ;	usb_ep0.c:48: pDescr = (uint8_t*)CfgDesc;
      0009A4 75 11 7D         [24]  708 	mov	_pDescr,#_CfgDesc
      0009A7 75 12 0E         [24]  709 	mov	(_pDescr + 1),#(_CfgDesc >> 8)
      0009AA 75 13 80         [24]  710 	mov	(_pDescr + 2),#0x80
                                    711 ;	usb_ep0.c:49: len = (USB_DESCSIZE_CONFIG_H << 8) | USB_DESCSIZE_CONFIG_L;
      0009AD 7E 4B            [12]  712 	mov	r6,#0x4b
                                    713 ;	usb_ep0.c:50: break;
                                    714 ;	usb_ep0.c:51: case 3:												// String Descriptor
      0009AF 80 41            [24]  715 	sjmp	00116$
      0009B1                        716 00107$:
                                    717 ;	usb_ep0.c:52: len = UsbSetupBuf->wValueL;	// Index
      0009B1 90 00 02         [24]  718 	mov	dptr,#(_Ep0Buffer + 0x0002)
      0009B4 E0               [24]  719 	movx	a,@dptr
      0009B5 FD               [12]  720 	mov	r5,a
                                    721 ;	usb_ep0.c:53: if (len < USB_STRINGDESC_COUNT) {
      0009B6 BD 04 00         [24]  722 	cjne	r5,#0x04,00302$
      0009B9                        723 00302$:
      0009B9 50 23            [24]  724 	jnc	00109$
                                    725 ;	usb_ep0.c:54: pDescr = (uint8_t*)(StringDescs[len]);
      0009BB ED               [12]  726 	mov	a,r5
      0009BC 2D               [12]  727 	add	a,r5
      0009BD 24 16            [12]  728 	add	a,#_StringDescs
      0009BF F9               [12]  729 	mov	r1,a
      0009C0 87 04            [24]  730 	mov	ar4,@r1
      0009C2 09               [12]  731 	inc	r1
      0009C3 87 05            [24]  732 	mov	ar5,@r1
      0009C5 8C 11            [24]  733 	mov	_pDescr,r4
      0009C7 8D 12            [24]  734 	mov	(_pDescr + 1),r5
      0009C9 75 13 80         [24]  735 	mov	(_pDescr + 2),#0x80
                                    736 ;	usb_ep0.c:55: len = pDescr[0];
      0009CC AB 11            [24]  737 	mov	r3,_pDescr
      0009CE AC 12            [24]  738 	mov	r4,(_pDescr + 1)
      0009D0 AD 13            [24]  739 	mov	r5,(_pDescr + 2)
      0009D2 8B 82            [24]  740 	mov	dpl,r3
      0009D4 8C 83            [24]  741 	mov	dph,r4
      0009D6 8D F0            [24]  742 	mov	b,r5
      0009D8 12 0E 4B         [24]  743 	lcall	__gptrget
      0009DB FE               [12]  744 	mov	r6,a
      0009DC 80 14            [24]  745 	sjmp	00116$
      0009DE                        746 00109$:
                                    747 ;	usb_ep0.c:57: len = 0xFF;								// Not supported
      0009DE 7E FF            [12]  748 	mov	r6,#0xff
                                    749 ;	usb_ep0.c:59: break;
                                    750 ;	usb_ep0.c:60: case 0x22:										// Report Descriptor
      0009E0 80 10            [24]  751 	sjmp	00116$
      0009E2                        752 00111$:
                                    753 ;	usb_ep0.c:61: len = UsbSetupBuf->wIndexL;
      0009E2 90 00 04         [24]  754 	mov	dptr,#(_Ep0Buffer + 0x0004)
      0009E5 E0               [24]  755 	movx	a,@dptr
      0009E6 FE               [12]  756 	mov	r6,a
                                    757 ;	usb_ep0.c:62: if (len < USB_INTERFACES) {
      0009E7 BE 02 00         [24]  758 	cjne	r6,#0x02,00304$
      0009EA                        759 00304$:
      0009EA 40 06            [24]  760 	jc	00116$
                                    761 ;	usb_ep0.c:67: len = 0xff;		// The host is trying to config invalid interfaces
      0009EC 7E FF            [12]  762 	mov	r6,#0xff
                                    763 ;	usb_ep0.c:69: break;
                                    764 ;	usb_ep0.c:70: default:
      0009EE 80 02            [24]  765 	sjmp	00116$
      0009F0                        766 00115$:
                                    767 ;	usb_ep0.c:71: len = 0xff;		// Unsupported descriptors
      0009F0 7E FF            [12]  768 	mov	r6,#0xff
                                    769 ;	usb_ep0.c:73: }	// switch (UsbSetupBuf->wValueH)
      0009F2                        770 00116$:
                                    771 ;	usb_ep0.c:74: if (SetupLen > len) {
      0009F2 C3               [12]  772 	clr	c
      0009F3 EE               [12]  773 	mov	a,r6
      0009F4 95 0F            [12]  774 	subb	a,_SetupLen
      0009F6 50 02            [24]  775 	jnc	00118$
                                    776 ;	usb_ep0.c:75: SetupLen = len;		// Limit length
      0009F8 8E 0F            [24]  777 	mov	_SetupLen,r6
      0009FA                        778 00118$:
                                    779 ;	usb_ep0.c:77: len = SetupLen >= 8 ? 8 : SetupLen;
      0009FA 74 F8            [12]  780 	mov	a,#0x100 - 0x08
      0009FC 25 0F            [12]  781 	add	a,_SetupLen
      0009FE 50 06            [24]  782 	jnc	00165$
      000A00 7D 08            [12]  783 	mov	r5,#0x08
      000A02 7E 00            [12]  784 	mov	r6,#0x00
      000A04 80 04            [24]  785 	sjmp	00166$
      000A06                        786 00165$:
      000A06 AD 0F            [24]  787 	mov	r5,_SetupLen
      000A08 7E 00            [12]  788 	mov	r6,#0x00
      000A0A                        789 00166$:
      000A0A 8D 07            [24]  790 	mov	ar7,r5
                                    791 ;	usb_ep0.c:78: memcpy(Ep0Buffer, pDescr, len);
      000A0C 85 11 6C         [24]  792 	mov	_memcpy_PARM_2,_pDescr
      000A0F 85 12 6D         [24]  793 	mov	(_memcpy_PARM_2 + 1),(_pDescr + 1)
      000A12 85 13 6E         [24]  794 	mov	(_memcpy_PARM_2 + 2),(_pDescr + 2)
      000A15 8F 6F            [24]  795 	mov	_memcpy_PARM_3,r7
      000A17 75 70 00         [24]  796 	mov	(_memcpy_PARM_3 + 1),#0x00
      000A1A 90 00 00         [24]  797 	mov	dptr,#_Ep0Buffer
      000A1D 75 F0 00         [24]  798 	mov	b,#0x00
      000A20 C0 07            [24]  799 	push	ar7
      000A22 12 0D DB         [24]  800 	lcall	_memcpy
      000A25 D0 07            [24]  801 	pop	ar7
                                    802 ;	usb_ep0.c:79: SetupLen -= len;
      000A27 E5 0F            [12]  803 	mov	a,_SetupLen
      000A29 C3               [12]  804 	clr	c
      000A2A 9F               [12]  805 	subb	a,r7
      000A2B F5 0F            [12]  806 	mov	_SetupLen,a
                                    807 ;	usb_ep0.c:80: pDescr += len;
      000A2D EF               [12]  808 	mov	a,r7
      000A2E 25 11            [12]  809 	add	a,_pDescr
      000A30 F5 11            [12]  810 	mov	_pDescr,a
      000A32 E4               [12]  811 	clr	a
      000A33 35 12            [12]  812 	addc	a,(_pDescr + 1)
      000A35 F5 12            [12]  813 	mov	(_pDescr + 1),a
                                    814 ;	usb_ep0.c:81: break;
      000A37 02 0B 5D         [24]  815 	ljmp	00159$
                                    816 ;	usb_ep0.c:82: case USB_SET_ADDRESS:
      000A3A                        817 00119$:
                                    818 ;	usb_ep0.c:83: SetupLen = UsbSetupBuf->wValueL;	// Save the assigned address
      000A3A 90 00 02         [24]  819 	mov	dptr,#(_Ep0Buffer + 0x0002)
      000A3D E0               [24]  820 	movx	a,@dptr
      000A3E F5 0F            [12]  821 	mov	_SetupLen,a
                                    822 ;	usb_ep0.c:84: break;
      000A40 02 0B 5D         [24]  823 	ljmp	00159$
                                    824 ;	usb_ep0.c:85: case USB_GET_CONFIGURATION:
      000A43                        825 00120$:
                                    826 ;	usb_ep0.c:86: Ep0Buffer[0] = UsbConfig;
      000A43 90 00 00         [24]  827 	mov	dptr,#_Ep0Buffer
      000A46 E5 10            [12]  828 	mov	a,_UsbConfig
      000A48 F0               [24]  829 	movx	@dptr,a
                                    830 ;	usb_ep0.c:87: if (SetupLen >= 1)
      000A49 74 FF            [12]  831 	mov	a,#0x100 - 0x01
      000A4B 25 0F            [12]  832 	add	a,_SetupLen
      000A4D 40 03            [24]  833 	jc	00308$
      000A4F 02 0B 5D         [24]  834 	ljmp	00159$
      000A52                        835 00308$:
                                    836 ;	usb_ep0.c:88: len = 1;
      000A52 7F 01            [12]  837 	mov	r7,#0x01
                                    838 ;	usb_ep0.c:89: break;
      000A54 02 0B 5D         [24]  839 	ljmp	00159$
                                    840 ;	usb_ep0.c:90: case USB_SET_CONFIGURATION:
      000A57                        841 00123$:
                                    842 ;	usb_ep0.c:91: UsbConfig = UsbSetupBuf->wValueL;
      000A57 90 00 02         [24]  843 	mov	dptr,#(_Ep0Buffer + 0x0002)
      000A5A E0               [24]  844 	movx	a,@dptr
      000A5B F5 10            [12]  845 	mov	_UsbConfig,a
                                    846 ;	usb_ep0.c:92: break;
      000A5D 02 0B 5D         [24]  847 	ljmp	00159$
                                    848 ;	usb_ep0.c:95: case USB_CLEAR_FEATURE:                                            //Clear Feature
      000A60                        849 00125$:
                                    850 ;	usb_ep0.c:96: if ((UsbSetupBuf->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_ENDP) {	// Endpoint
      000A60 90 00 00         [24]  851 	mov	dptr,#_Ep0Buffer
      000A63 E0               [24]  852 	movx	a,@dptr
      000A64 FE               [12]  853 	mov	r6,a
      000A65 53 06 1F         [24]  854 	anl	ar6,#0x1f
      000A68 7D 00            [12]  855 	mov	r5,#0x00
      000A6A BE 02 11         [24]  856 	cjne	r6,#0x02,00127$
      000A6D BD 00 0E         [24]  857 	cjne	r5,#0x00,00127$
                                    858 ;	usb_ep0.c:97: len = USB_EP_HALT_CLEAR(UsbSetupBuf->wIndexL);
      000A70 90 00 04         [24]  859 	mov	dptr,#(_Ep0Buffer + 0x0004)
      000A73 E0               [24]  860 	movx	a,@dptr
      000A74 F5 82            [12]  861 	mov	dpl,a
      000A76 12 08 BD         [24]  862 	lcall	_USB_EP_HALT_CLEAR
      000A79 AF 82            [24]  863 	mov	r7,dpl
      000A7B 02 0B 5D         [24]  864 	ljmp	00159$
      000A7E                        865 00127$:
                                    866 ;	usb_ep0.c:99: len = 0xFF;			// Unsupported
      000A7E 7F FF            [12]  867 	mov	r7,#0xff
                                    868 ;	usb_ep0.c:101: break;
      000A80 02 0B 5D         [24]  869 	ljmp	00159$
                                    870 ;	usb_ep0.c:102: case USB_SET_FEATURE:                                              /* Set Feature */
      000A83                        871 00129$:
                                    872 ;	usb_ep0.c:103: if ((UsbSetupBuf->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_ENDP) { // Endpoint
      000A83 90 00 00         [24]  873 	mov	dptr,#_Ep0Buffer
      000A86 E0               [24]  874 	movx	a,@dptr
      000A87 FE               [12]  875 	mov	r6,a
      000A88 53 06 1F         [24]  876 	anl	ar6,#0x1f
      000A8B 7D 00            [12]  877 	mov	r5,#0x00
      000A8D BE 02 2D         [24]  878 	cjne	r6,#0x02,00134$
      000A90 BD 00 2A         [24]  879 	cjne	r5,#0x00,00134$
                                    880 ;	usb_ep0.c:104: if ((((uint16_t)UsbSetupBuf->wValueH << 8) | UsbSetupBuf->wValueL) == USB_FEATURE_ENDPOINT_HALT) {
      000A93 90 00 03         [24]  881 	mov	dptr,#(_Ep0Buffer + 0x0003)
      000A96 E0               [24]  882 	movx	a,@dptr
      000A97 FD               [12]  883 	mov	r5,a
      000A98 7E 00            [12]  884 	mov	r6,#0x00
      000A9A 90 00 02         [24]  885 	mov	dptr,#(_Ep0Buffer + 0x0002)
      000A9D E0               [24]  886 	movx	a,@dptr
      000A9E FC               [12]  887 	mov	r4,a
      000A9F 7B 00            [12]  888 	mov	r3,#0x00
      000AA1 42 06            [12]  889 	orl	ar6,a
      000AA3 EB               [12]  890 	mov	a,r3
      000AA4 42 05            [12]  891 	orl	ar5,a
      000AA6 EE               [12]  892 	mov	a,r6
      000AA7 4D               [12]  893 	orl	a,r5
      000AA8 70 0E            [24]  894 	jnz	00131$
                                    895 ;	usb_ep0.c:105: len = USB_EP_HALT_SET(UsbSetupBuf->wIndexL);
      000AAA 90 00 04         [24]  896 	mov	dptr,#(_Ep0Buffer + 0x0004)
      000AAD E0               [24]  897 	movx	a,@dptr
      000AAE F5 82            [12]  898 	mov	dpl,a
      000AB0 12 08 58         [24]  899 	lcall	_USB_EP_HALT_SET
      000AB3 AF 82            [24]  900 	mov	r7,dpl
      000AB5 02 0B 5D         [24]  901 	ljmp	00159$
      000AB8                        902 00131$:
                                    903 ;	usb_ep0.c:107: len = 0xFF;		// Unsupported
      000AB8 7F FF            [12]  904 	mov	r7,#0xff
      000ABA 02 0B 5D         [24]  905 	ljmp	00159$
      000ABD                        906 00134$:
                                    907 ;	usb_ep0.c:110: len = 0xFF;			// Unsupported
      000ABD 7F FF            [12]  908 	mov	r7,#0xff
                                    909 ;	usb_ep0.c:112: break;
      000ABF 02 0B 5D         [24]  910 	ljmp	00159$
                                    911 ;	usb_ep0.c:113: case USB_GET_STATUS:
      000AC2                        912 00136$:
                                    913 ;	usb_ep0.c:125: Ep0Buffer[0] = 0x00;
      000AC2 90 00 00         [24]  914 	mov	dptr,#_Ep0Buffer
      000AC5 E4               [12]  915 	clr	a
      000AC6 F0               [24]  916 	movx	@dptr,a
                                    917 ;	usb_ep0.c:126: Ep0Buffer[1] = 0x00;
      000AC7 90 00 01         [24]  918 	mov	dptr,#(_Ep0Buffer + 0x0001)
      000ACA F0               [24]  919 	movx	@dptr,a
                                    920 ;	usb_ep0.c:127: if (SetupLen >= 2) {
      000ACB 74 FE            [12]  921 	mov	a,#0x100 - 0x02
      000ACD 25 0F            [12]  922 	add	a,_SetupLen
      000ACF 50 05            [24]  923 	jnc	00138$
                                    924 ;	usb_ep0.c:128: len = 2;
      000AD1 7F 02            [12]  925 	mov	r7,#0x02
      000AD3 02 0B 5D         [24]  926 	ljmp	00159$
      000AD6                        927 00138$:
                                    928 ;	usb_ep0.c:130: len = SetupLen;
      000AD6 AF 0F            [24]  929 	mov	r7,_SetupLen
                                    930 ;	usb_ep0.c:132: break;
      000AD8 02 0B 5D         [24]  931 	ljmp	00159$
                                    932 ;	usb_ep0.c:133: default:
      000ADB                        933 00140$:
                                    934 ;	usb_ep0.c:134: len = 0xff;				// Unsupported
      000ADB 7F FF            [12]  935 	mov	r7,#0xff
                                    936 ;	usb_ep0.c:136: }	// switch (SetupReq)
      000ADD 02 0B 5D         [24]  937 	ljmp	00159$
      000AE0                        938 00155$:
                                    939 ;	usb_ep0.c:139: else if ((UsbSetupBuf->bRequestType & USB_REQ_TYP_MASK) == USB_REQ_TYP_CLASS) {
      000AE0 90 00 00         [24]  940 	mov	dptr,#_Ep0Buffer
      000AE3 E0               [24]  941 	movx	a,@dptr
      000AE4 FE               [12]  942 	mov	r6,a
      000AE5 53 06 60         [24]  943 	anl	ar6,#0x60
      000AE8 7D 00            [12]  944 	mov	r5,#0x00
      000AEA BE 20 70         [24]  945 	cjne	r6,#0x20,00159$
      000AED BD 00 6D         [24]  946 	cjne	r5,#0x00,00159$
                                    947 ;	usb_ep0.c:141: if (UsbSetupBuf->bRequestType & USB_REQ_TYP_IN) {
      000AF0 90 00 00         [24]  948 	mov	dptr,#_Ep0Buffer
      000AF3 E0               [24]  949 	movx	a,@dptr
      000AF4 FE               [12]  950 	mov	r6,a
      000AF5 30 E7 51         [24]  951 	jnb	acc.7,00150$
                                    952 ;	usb_ep0.c:143: switch( SetupReq ) {
      000AF8 74 21            [12]  953 	mov	a,#0x21
      000AFA B5 0E 48         [24]  954 	cjne	a,_SetupReq,00143$
                                    955 ;	usb_ep0.c:149: pDescr = LineCoding;
      000AFD 75 11 CA         [24]  956 	mov	_pDescr,#_LineCoding
      000B00 75 12 00         [24]  957 	mov	(_pDescr + 1),#(_LineCoding >> 8)
      000B03 75 13 00         [24]  958 	mov	(_pDescr + 2),#0x00
                                    959 ;	usb_ep0.c:151: len = SetupLen >= DEFAULT_ENDP0_SIZE ? DEFAULT_ENDP0_SIZE : SetupLen;  // ���δ��䳤��
      000B06 74 F8            [12]  960 	mov	a,#0x100 - 0x08
      000B08 25 0F            [12]  961 	add	a,_SetupLen
      000B0A 50 06            [24]  962 	jnc	00167$
      000B0C 7D 08            [12]  963 	mov	r5,#0x08
      000B0E 7E 00            [12]  964 	mov	r6,#0x00
      000B10 80 04            [24]  965 	sjmp	00168$
      000B12                        966 00167$:
      000B12 AD 0F            [24]  967 	mov	r5,_SetupLen
      000B14 7E 00            [12]  968 	mov	r6,#0x00
      000B16                        969 00168$:
      000B16 8D 07            [24]  970 	mov	ar7,r5
                                    971 ;	usb_ep0.c:152: memcpy(Ep0Buffer, pDescr, len);
      000B18 85 11 6C         [24]  972 	mov	_memcpy_PARM_2,_pDescr
      000B1B 85 12 6D         [24]  973 	mov	(_memcpy_PARM_2 + 1),(_pDescr + 1)
      000B1E 85 13 6E         [24]  974 	mov	(_memcpy_PARM_2 + 2),(_pDescr + 2)
      000B21 8F 6F            [24]  975 	mov	_memcpy_PARM_3,r7
      000B23 75 70 00         [24]  976 	mov	(_memcpy_PARM_3 + 1),#0x00
      000B26 90 00 00         [24]  977 	mov	dptr,#_Ep0Buffer
      000B29 75 F0 00         [24]  978 	mov	b,#0x00
      000B2C C0 07            [24]  979 	push	ar7
      000B2E 12 0D DB         [24]  980 	lcall	_memcpy
      000B31 D0 07            [24]  981 	pop	ar7
                                    982 ;	usb_ep0.c:153: SetupLen -= len;
      000B33 E5 0F            [12]  983 	mov	a,_SetupLen
      000B35 C3               [12]  984 	clr	c
      000B36 9F               [12]  985 	subb	a,r7
      000B37 F5 0F            [12]  986 	mov	_SetupLen,a
                                    987 ;	usb_ep0.c:154: pDescr += len;
      000B39 EF               [12]  988 	mov	a,r7
      000B3A 25 11            [12]  989 	add	a,_pDescr
      000B3C F5 11            [12]  990 	mov	_pDescr,a
      000B3E E4               [12]  991 	clr	a
      000B3F 35 12            [12]  992 	addc	a,(_pDescr + 1)
      000B41 F5 12            [12]  993 	mov	(_pDescr + 1),a
                                    994 ;	usb_ep0.c:155: break;
                                    995 ;	usb_ep0.c:156: default:
      000B43 80 18            [24]  996 	sjmp	00159$
      000B45                        997 00143$:
                                    998 ;	usb_ep0.c:157: len = 0xFF;
      000B45 7F FF            [12]  999 	mov	r7,#0xff
                                   1000 ;	usb_ep0.c:159: }
      000B47 80 14            [24] 1001 	sjmp	00159$
      000B49                       1002 00150$:
                                   1003 ;	usb_ep0.c:162: switch( SetupReq ) {
      000B49 74 20            [12] 1004 	mov	a,#0x20
      000B4B B5 0E 02         [24] 1005 	cjne	a,_SetupReq,00321$
      000B4E 80 0D            [24] 1006 	sjmp	00159$
      000B50                       1007 00321$:
      000B50 74 22            [12] 1008 	mov	a,#0x22
      000B52 B5 0E 02         [24] 1009 	cjne	a,_SetupReq,00322$
      000B55 80 06            [24] 1010 	sjmp	00159$
      000B57                       1011 00322$:
                                   1012 ;	usb_ep0.c:174: len = 0xFF;
      000B57 7F FF            [12] 1013 	mov	r7,#0xff
                                   1014 ;	usb_ep0.c:176: }
      000B59 80 02            [24] 1015 	sjmp	00159$
      000B5B                       1016 00158$:
                                   1017 ;	usb_ep0.c:182: len = 0xff;						// Wrong packet length
      000B5B 7F FF            [12] 1018 	mov	r7,#0xff
      000B5D                       1019 00159$:
                                   1020 ;	usb_ep0.c:187: if (len == 0xff) {	// Return STALL to host if operation is not supported
      000B5D BF FF 07         [24] 1021 	cjne	r7,#0xff,00161$
                                   1022 ;	usb_ep0.c:188: SetupReq = 0xFF;
      000B60 75 0E FF         [24] 1023 	mov	_SetupReq,#0xff
                                   1024 ;	usb_ep0.c:189: UEP0_CTRL = bUEP_R_TOG | bUEP_T_TOG | UEP_R_RES_STALL | UEP_T_RES_STALL;//STALL
      000B63 75 DC CF         [24] 1025 	mov	_UEP0_CTRL,#0xcf
      000B66 22               [24] 1026 	ret
      000B67                       1027 00161$:
                                   1028 ;	usb_ep0.c:191: UEP0_T_LEN = len;
      000B67 8F DD            [24] 1029 	mov	_UEP0_T_LEN,r7
                                   1030 ;	usb_ep0.c:192: UEP0_CTRL = bUEP_R_TOG | bUEP_T_TOG | UEP_R_RES_ACK | UEP_T_RES_ACK;	// Expect DATA1, Answer ACK
      000B69 75 DC C0         [24] 1031 	mov	_UEP0_CTRL,#0xc0
                                   1032 ;	usb_ep0.c:194: }
      000B6C 22               [24] 1033 	ret
                                   1034 ;------------------------------------------------------------
                                   1035 ;Allocation info for local variables in function 'USB_EP0_IN'
                                   1036 ;------------------------------------------------------------
                                   1037 ;len                       Allocated to registers r6 
                                   1038 ;------------------------------------------------------------
                                   1039 ;	usb_ep0.c:197: void USB_EP0_IN(void) {
                                   1040 ;	-----------------------------------------
                                   1041 ;	 function USB_EP0_IN
                                   1042 ;	-----------------------------------------
      000B6D                       1043 _USB_EP0_IN:
                                   1044 ;	usb_ep0.c:199: switch (SetupReq)
      000B6D 74 05            [12] 1045 	mov	a,#0x05
      000B6F B5 0E 02         [24] 1046 	cjne	a,_SetupReq,00121$
      000B72 80 4A            [24] 1047 	sjmp	00102$
      000B74                       1048 00121$:
      000B74 74 06            [12] 1049 	mov	a,#0x06
      000B76 B5 0E 50         [24] 1050 	cjne	a,_SetupReq,00103$
                                   1051 ;	usb_ep0.c:202: len = SetupLen >= 8 ? 8 : SetupLen;		// Fix length
      000B79 74 F8            [12] 1052 	mov	a,#0x100 - 0x08
      000B7B 25 0F            [12] 1053 	add	a,_SetupLen
      000B7D 50 06            [24] 1054 	jnc	00107$
      000B7F 7E 08            [12] 1055 	mov	r6,#0x08
      000B81 7F 00            [12] 1056 	mov	r7,#0x00
      000B83 80 04            [24] 1057 	sjmp	00108$
      000B85                       1058 00107$:
      000B85 AE 0F            [24] 1059 	mov	r6,_SetupLen
      000B87 7F 00            [12] 1060 	mov	r7,#0x00
      000B89                       1061 00108$:
                                   1062 ;	usb_ep0.c:203: memcpy(Ep0Buffer, pDescr, len);			// Copy data to Ep0Buffer, ready to Tx
      000B89 85 11 6C         [24] 1063 	mov	_memcpy_PARM_2,_pDescr
      000B8C 85 12 6D         [24] 1064 	mov	(_memcpy_PARM_2 + 1),(_pDescr + 1)
      000B8F 85 13 6E         [24] 1065 	mov	(_memcpy_PARM_2 + 2),(_pDescr + 2)
      000B92 8E 6F            [24] 1066 	mov	_memcpy_PARM_3,r6
      000B94 75 70 00         [24] 1067 	mov	(_memcpy_PARM_3 + 1),#0x00
      000B97 90 00 00         [24] 1068 	mov	dptr,#_Ep0Buffer
      000B9A 75 F0 00         [24] 1069 	mov	b,#0x00
      000B9D C0 06            [24] 1070 	push	ar6
      000B9F 12 0D DB         [24] 1071 	lcall	_memcpy
      000BA2 D0 06            [24] 1072 	pop	ar6
                                   1073 ;	usb_ep0.c:204: SetupLen -= len;
      000BA4 E5 0F            [12] 1074 	mov	a,_SetupLen
      000BA6 C3               [12] 1075 	clr	c
      000BA7 9E               [12] 1076 	subb	a,r6
      000BA8 F5 0F            [12] 1077 	mov	_SetupLen,a
                                   1078 ;	usb_ep0.c:205: pDescr += len;
      000BAA EE               [12] 1079 	mov	a,r6
      000BAB 25 11            [12] 1080 	add	a,_pDescr
      000BAD F5 11            [12] 1081 	mov	_pDescr,a
      000BAF E4               [12] 1082 	clr	a
      000BB0 35 12            [12] 1083 	addc	a,(_pDescr + 1)
      000BB2 F5 12            [12] 1084 	mov	(_pDescr + 1),a
                                   1085 ;	usb_ep0.c:206: UEP0_T_LEN = len;
      000BB4 8E DD            [24] 1086 	mov	_UEP0_T_LEN,r6
                                   1087 ;	usb_ep0.c:207: UEP0_CTRL ^= bUEP_T_TOG;				// Switch between DATA0 and DATA1
      000BB6 AE DC            [24] 1088 	mov	r6,_UEP0_CTRL
      000BB8 63 06 40         [24] 1089 	xrl	ar6,#0x40
      000BBB 8E DC            [24] 1090 	mov	_UEP0_CTRL,r6
                                   1091 ;	usb_ep0.c:208: break;
                                   1092 ;	usb_ep0.c:209: case USB_SET_ADDRESS:
      000BBD 22               [24] 1093 	ret
      000BBE                       1094 00102$:
                                   1095 ;	usb_ep0.c:210: USB_DEV_AD = bUDA_GP_BIT | SetupLen;
      000BBE AE 0F            [24] 1096 	mov	r6,_SetupLen
      000BC0 43 06 80         [24] 1097 	orl	ar6,#0x80
      000BC3 8E E3            [24] 1098 	mov	_USB_DEV_AD,r6
                                   1099 ;	usb_ep0.c:211: UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
      000BC5 75 DC 02         [24] 1100 	mov	_UEP0_CTRL,#0x02
                                   1101 ;	usb_ep0.c:212: break;
                                   1102 ;	usb_ep0.c:213: default:
      000BC8 22               [24] 1103 	ret
      000BC9                       1104 00103$:
                                   1105 ;	usb_ep0.c:214: UEP0_T_LEN = 0;							// End of transaction
      000BC9 75 DD 00         [24] 1106 	mov	_UEP0_T_LEN,#0x00
                                   1107 ;	usb_ep0.c:215: UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
      000BCC 75 DC 02         [24] 1108 	mov	_UEP0_CTRL,#0x02
                                   1109 ;	usb_ep0.c:217: }
                                   1110 ;	usb_ep0.c:218: }
      000BCF 22               [24] 1111 	ret
                                   1112 ;------------------------------------------------------------
                                   1113 ;Allocation info for local variables in function 'USB_EP0_OUT'
                                   1114 ;------------------------------------------------------------
                                   1115 ;len                       Allocated to registers 
                                   1116 ;------------------------------------------------------------
                                   1117 ;	usb_ep0.c:221: void USB_EP0_OUT(void) {
                                   1118 ;	-----------------------------------------
                                   1119 ;	 function USB_EP0_OUT
                                   1120 ;	-----------------------------------------
      000BD0                       1121 _USB_EP0_OUT:
                                   1122 ;	usb_ep0.c:222: uint8_t len = USB_RX_LEN;
      000BD0 E5 DB            [12] 1123 	mov	a,_USB_RX_LEN
                                   1124 ;	usb_ep0.c:223: if (SetupReq == SET_LINE_CODING) {
      000BD2 74 20            [12] 1125 	mov	a,#0x20
      000BD4 B5 0E 24         [24] 1126 	cjne	a,_SetupReq,00105$
                                   1127 ;	usb_ep0.c:224: if( U_TOG_OK ) {
      000BD7 30 DE 21         [24] 1128 	jnb	_U_TOG_OK,00105$
                                   1129 ;	usb_ep0.c:225: memcpy(LineCoding,UsbSetupBuf,USB_RX_LEN);
      000BDA 75 6C 00         [24] 1130 	mov	_memcpy_PARM_2,#_Ep0Buffer
      000BDD 75 6D 00         [24] 1131 	mov	(_memcpy_PARM_2 + 1),#(_Ep0Buffer >> 8)
      000BE0 75 6E 00         [24] 1132 	mov	(_memcpy_PARM_2 + 2),#0x00
      000BE3 85 DB 6F         [24] 1133 	mov	_memcpy_PARM_3,_USB_RX_LEN
      000BE6 75 70 00         [24] 1134 	mov	(_memcpy_PARM_3 + 1),#0x00
      000BE9 90 00 CA         [24] 1135 	mov	dptr,#_LineCoding
      000BEC 75 F0 00         [24] 1136 	mov	b,#0x00
      000BEF 12 0D DB         [24] 1137 	lcall	_memcpy
                                   1138 ;	usb_ep0.c:226: CDC_SetBaud();
      000BF2 12 04 F5         [24] 1139 	lcall	_CDC_SetBaud
                                   1140 ;	usb_ep0.c:228: UEP0_T_LEN = 0;
      000BF5 75 DD 00         [24] 1141 	mov	_UEP0_T_LEN,#0x00
                                   1142 ;	usb_ep0.c:229: UEP0_CTRL |= UEP_R_RES_ACK | UEP_T_RES_ACK;  // ׼���ϴ�0��
      000BF8 85 DC DC         [24] 1143 	mov	_UEP0_CTRL,_UEP0_CTRL
                                   1144 ;	usb_ep0.c:232: else if(SetupReq == SET_CONTROL_LINE_STATE){
      000BFB                       1145 00105$:
                                   1146 ;	usb_ep0.c:254: UEP0_CTRL ^= bUEP_R_TOG;	// Switch between DATA0 and DATA1	
      000BFB AE DC            [24] 1147 	mov	r6,_UEP0_CTRL
      000BFD 63 06 80         [24] 1148 	xrl	ar6,#0x80
      000C00 8E DC            [24] 1149 	mov	_UEP0_CTRL,r6
                                   1150 ;	usb_ep0.c:255: }
      000C02 22               [24] 1151 	ret
                                   1152 	.area CSEG    (CODE)
                                   1153 	.area CONST   (CODE)
                                   1154 	.area XINIT   (CODE)
                                   1155 	.area CABS    (ABS,CODE)
