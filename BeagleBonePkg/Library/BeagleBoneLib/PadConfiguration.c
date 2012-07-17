/** @file

  Copyright (c) 2008 - 2009, Apple Inc. All rights reserved.<BR>
  
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <PiPei.h>
#include <Library/IoLib.h>
#include <Library/DebugLib.h>
#include <Omap3530/Omap3530.h>
#include <BeagleBone.h>

#define NUM_PINS_SHARED 232
#define NUM_PINS_ABC 6
#define NUM_PINS_XM 12

struct pad_signals {
	int gpmc_ad0;
	int gpmc_ad1;
	int gpmc_ad2;
	int gpmc_ad3;
	int gpmc_ad4;
	int gpmc_ad5;
	int gpmc_ad6;
	int gpmc_ad7;
	int gpmc_ad8;
	int gpmc_ad9;
	int gpmc_ad10;
	int gpmc_ad11;
	int gpmc_ad12;
	int gpmc_ad13;
	int gpmc_ad14;
	int gpmc_ad15;
	int gpmc_a0;
	int gpmc_a1;
	int gpmc_a2;
	int gpmc_a3;
	int gpmc_a4;
	int gpmc_a5;
	int gpmc_a6;
	int gpmc_a7;
	int gpmc_a8;
	int gpmc_a9;
	int gpmc_a10;
	int gpmc_a11;
	int gpmc_wait0;
	int gpmc_wpn;
	int gpmc_be1n;
	int gpmc_csn0;
	int gpmc_csn1;
	int gpmc_csn2;
	int gpmc_csn3;
	int gpmc_clk;
	int gpmc_advn_ale;
	int gpmc_oen_ren;
	int gpmc_wen;
	int gpmc_be0n_cle;
	int lcd_data0;
	int lcd_data1;
	int lcd_data2;
	int lcd_data3;
	int lcd_data4;
	int lcd_data5;
	int lcd_data6;
	int lcd_data7;
	int lcd_data8;
	int lcd_data9;
	int lcd_data10;
	int lcd_data11;
	int lcd_data12;
	int lcd_data13;
	int lcd_data14;
	int lcd_data15;
	int lcd_vsync;
	int lcd_hsync;
	int lcd_pclk;
	int lcd_ac_bias_en;
	int mmc0_dat3;
	int mmc0_dat2;
	int mmc0_dat1;
	int mmc0_dat0;
	int mmc0_clk;
	int mmc0_cmd;
	int mii1_col;
	int mii1_crs;
	int mii1_rxerr;
	int mii1_txen;
	int mii1_rxdv;
	int mii1_txd3;
	int mii1_txd2;
	int mii1_txd1;
	int mii1_txd0;
	int mii1_txclk;
	int mii1_rxclk;
	int mii1_rxd3;
	int mii1_rxd2;
	int mii1_rxd1;
	int mii1_rxd0;
	int rmii1_refclk;
	int mdio_data;
	int mdio_clk;
	int spi0_sclk;
	int spi0_d0;
	int spi0_d1;
	int spi0_cs0;
	int spi0_cs1;
	int ecap0_in_pwm0_out;
	int uart0_ctsn;
	int uart0_rtsn;
	int uart0_rxd;
	int uart0_txd;
	int uart1_ctsn;
	int uart1_rtsn;
	int uart1_rxd;
	int uart1_txd;
	int i2c0_sda;
	int i2c0_scl;
	int mcasp0_aclkx;
	int mcasp0_fsx;
	int mcasp0_axr0;
	int mcasp0_ahclkr;
	int mcasp0_aclkr;
	int mcasp0_fsr;
	int mcasp0_axr1;
	int mcasp0_ahclkx;
	int xdma_event_intr0;
	int xdma_event_intr1;
	int nresetin_out;
	int porz;
	int nnmi;
	int osc0_in;
	int osc0_out;
	int rsvd1;
	int tms;
	int tdi;
	int tdo;
	int tck;
	int ntrst;
	int emu0;
	int emu1;
	int osc1_in;
	int osc1_out;
	int pmic_power_en;
	int rtc_porz;
	int rsvd2;
	int ext_wakeup;
	int enz_kaldo_1p8v;
	int usb0_dm;
	int usb0_dp;
	int usb0_ce;
	int usb0_id;
	int usb0_vbus;
	int usb0_drvvbus;
	int usb1_dm;
	int usb1_dp;
	int usb1_ce;
	int usb1_id;
	int usb1_vbus;
	int usb1_drvvbus;
	int ddr_resetn;
	int ddr_csn0;
	int ddr_cke;
	int ddr_ck;
	int ddr_nck;
	int ddr_casn;
	int ddr_rasn;
	int ddr_wen;
	int ddr_ba0;
	int ddr_ba1;
	int ddr_ba2;
	int ddr_a0;
	int ddr_a1;
	int ddr_a2;
	int ddr_a3;
	int ddr_a4;
	int ddr_a5;
	int ddr_a6;
	int ddr_a7;
	int ddr_a8;
	int ddr_a9;
	int ddr_a10;
	int ddr_a11;
	int ddr_a12;
	int ddr_a13;
	int ddr_a14;
	int ddr_a15;
	int ddr_odt;
	int ddr_d0;
	int ddr_d1;
	int ddr_d2;
	int ddr_d3;
	int ddr_d4;
	int ddr_d5;
	int ddr_d6;
	int ddr_d7;
	int ddr_d8;
	int ddr_d9;
	int ddr_d10;
	int ddr_d11;
	int ddr_d12;
	int ddr_d13;
	int ddr_d14;
	int ddr_d15;
	int ddr_dqm0;
	int ddr_dqm1;
	int ddr_dqs0;
	int ddr_dqsn0;
	int ddr_dqs1;
	int ddr_dqsn1;
	int ddr_vref;
	int ddr_vtp;
	int ddr_strben0;
	int ddr_strben1;
	int ain7;
	int ain6;
	int ain5;
	int ain4;
	int ain3;
	int ain2;
	int ain1;
	int ain0;
	int vrefp;
	int vrefn;
};

struct module_pin_mux {
	short reg_offset;
	unsigned char val;
};

struct evm_pin_mux {
	struct module_pin_mux *mod_pin_mux;
	unsigned short profile;
/*
* If the device is required on both baseboard & daughter board (ex i2c),
* specify DEV_ON_BASEBOARD
*/
#define DEV_ON_BASEBOARD       0
#define DEV_ON_DGHTR_BRD       1
	unsigned short device_on;
};

#define PAD_CTRL_BASE	0x800
#define OFFSET(x)	(unsigned int) (&((struct pad_signals *) \
				(PAD_CTRL_BASE))->x)

PAD_CONFIGURATION PadConfigurationTableBone[] = {
//  Pin						MuxMode,  PullConfig,    InputEnable
	{OFFSET(uart0_rxd), 	MUXMODE0, PULL_DISABLED, INPUT},
	{OFFSET(uart0_txd),		MUXMODE0, PULL_DISABLED, OUTPUT},
};

PAD_CONFIGURATION PadConfigurationTableShared[] = {
  //Pin,           MuxMode,    PullConfig,                      InputEnable
  { SDRC_D0,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D1,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D2,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D3,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D4,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D5,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D6,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D7,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D8,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D9,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D10,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D11,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D12,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D13,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D14,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D15,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D16,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D17,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D18,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D19,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D20,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D21,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D22,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D23,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D24,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D25,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D26,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D27,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D28,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D29,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D30,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_D31,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_CLK,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_DQS0,     MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_CKE0,     MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { SDRC_CKE1,     MUXMODE7,   PULL_DISABLED,                INPUT  },
  { SDRC_DQS1,     MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_DQS2,     MUXMODE0,   PULL_DISABLED,                INPUT  },
  { SDRC_DQS3,     MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_A1,       MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { GPMC_A2,       MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { GPMC_A3,       MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { GPMC_A4,       MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { GPMC_A5,       MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { GPMC_A6,       MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { GPMC_A7,       MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { GPMC_A8,       MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { GPMC_A9,       MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { GPMC_A10,      MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { GPMC_D0,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_D1,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_D2,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_D3,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_D4,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_D5,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_D6,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_D7,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_D8,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_D9,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_D10,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_D11,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_D12,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_D13,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_D14,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_D15,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_NCS0,     MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_NCS1,     MUXMODE0,   PULL_UP_SELECTED,             OUTPUT },
  { GPMC_NCS2,     MUXMODE0,   PULL_UP_SELECTED,             OUTPUT },
  { GPMC_NCS3,     MUXMODE0,   PULL_UP_SELECTED,             OUTPUT },
  { GPMC_NCS4,     MUXMODE0,   PULL_UP_SELECTED,             OUTPUT },
  { GPMC_NCS5,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { GPMC_NCS6,     MUXMODE1,   PULL_DISABLED,                INPUT  },
  { GPMC_NCS7,     MUXMODE1,   PULL_UP_SELECTED,             INPUT  },
  { GPMC_CLK,      MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { GPMC_NADV_ALE, MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_NOE,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_NWE,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_NBE0_CLE, MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { GPMC_NBE1,     MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_NWP,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { GPMC_WAIT0,    MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { GPMC_WAIT1,    MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { GPMC_WAIT2,    MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { GPMC_WAIT3,    MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { DSS_PCLK,      MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_HSYNC,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_PSYNC,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_ACBIAS,    MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA0,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA1,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA2,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA3,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA4,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA5,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA6,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA7,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA8,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA9,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA10,    MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA11,    MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA12,    MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA13,    MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA14,    MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA15,    MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA16,    MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { DSS_DATA17,    MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { CAM_HS,        MUXMODE0,   PULL_UP_SELECTED,             INPUT },
  { CAM_VS,        MUXMODE0,   PULL_UP_SELECTED,             INPUT },
  { CAM_XCLKA,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { CAM_PCLK,      MUXMODE0,   PULL_UP_SELECTED,             INPUT },
  { CAM_FLD,       MUXMODE4,   PULL_DISABLED,                OUTPUT },
  { CAM_D0,        MUXMODE0,   PULL_DISABLED,                INPUT  },
  { CAM_D1,        MUXMODE0,   PULL_DISABLED,                INPUT  },
  { CAM_D2,        MUXMODE0,   PULL_DISABLED,                INPUT  },
  { CAM_D3,        MUXMODE0,   PULL_DISABLED,                INPUT  },
  { CAM_D4,        MUXMODE0,   PULL_DISABLED,                INPUT  },
  { CAM_D5,        MUXMODE0,   PULL_DISABLED,                INPUT  },
  { CAM_D6,        MUXMODE0,   PULL_DISABLED,                INPUT  },
  { CAM_D7,        MUXMODE0,   PULL_DISABLED,                INPUT  },
  { CAM_D8,        MUXMODE0,   PULL_DISABLED,                INPUT  },
  { CAM_D9,        MUXMODE0,   PULL_DISABLED,                INPUT  },
  { CAM_D10,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { CAM_D11,       MUXMODE0,   PULL_DISABLED,                INPUT  },
  { CAM_XCLKB,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { CAM_WEN,       MUXMODE4,   PULL_DISABLED,                INPUT  },
  { CAM_STROBE,    MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { CSI2_DX0,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { CSI2_DY0,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { CSI2_DX1,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { CSI2_DY1,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { MCBSP2_FSX,    MUXMODE0,   PULL_DISABLED,                INPUT  },
  { MCBSP2_CLKX,   MUXMODE0,   PULL_DISABLED,                INPUT  },
  { MCBSP2_DR,     MUXMODE0,   PULL_DISABLED,                INPUT  },
  { MCBSP2_DX,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { MMC1_CLK,      MUXMODE0,   PULL_UP_SELECTED,             OUTPUT },
  { MMC1_CMD,      MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { MMC1_DAT0,     MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { MMC1_DAT1,     MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { MMC1_DAT2,     MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { MMC1_DAT3,     MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { MMC1_DAT4,     MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { MMC1_DAT5,     MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { MMC1_DAT6,     MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { MMC1_DAT7,     MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { MMC2_CLK,      MUXMODE4,   PULL_UP_SELECTED,             INPUT  },
  { MMC2_CMD,      MUXMODE4,   PULL_UP_SELECTED,             INPUT  },
  { MMC2_DAT0,     MUXMODE4,   PULL_UP_SELECTED,             INPUT  },
  { MMC2_DAT1,     MUXMODE4,   PULL_UP_SELECTED,             INPUT  },
  { MMC2_DAT2,     MUXMODE4,   PULL_UP_SELECTED,             INPUT  },
  { MMC2_DAT3,     MUXMODE4,   PULL_UP_SELECTED,             INPUT  },
  { MMC2_DAT4,     MUXMODE4,   PULL_UP_SELECTED,             INPUT  },
  { MMC2_DAT5,     MUXMODE4,   PULL_UP_SELECTED,             INPUT  },
  { MMC2_DAT6,     MUXMODE4,   PULL_UP_SELECTED,             INPUT  },
  { MMC2_DAT7,     MUXMODE4,   PULL_UP_SELECTED,             INPUT  },
  { MCBSP3_DX,     MUXMODE4,   PULL_DISABLED,                OUTPUT },
  { MCBSP3_DR,     MUXMODE4,   PULL_DISABLED,                OUTPUT },
  { MCBSP3_CLKX,   MUXMODE4,   PULL_DISABLED,                OUTPUT },
  { MCBSP3_FSX,    MUXMODE4,   PULL_DISABLED,                OUTPUT },
  { UART2_CTS,     MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { UART2_RTS,     MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { UART2_TX,      MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { UART2_RX,      MUXMODE4,   PULL_DISABLED,                OUTPUT },
  { UART1_TX,      MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { UART1_RTS,     MUXMODE4,   PULL_DISABLED,                OUTPUT },
  { UART1_CTS,     MUXMODE4,   PULL_DISABLED,                OUTPUT },
  { UART1_RX,      MUXMODE0,   PULL_DISABLED,                INPUT  },
  { MCBSP4_CLKX,   MUXMODE1,   PULL_DISABLED,                INPUT  },
  { MCBSP4_DR,     MUXMODE1,   PULL_DISABLED,                INPUT  },
  { MCBSP4_DX,     MUXMODE1,   PULL_DISABLED,                INPUT  },
  { MCBSP4_FSX,    MUXMODE1,   PULL_DISABLED,                INPUT  },
  { MCBSP1_CLKR,   MUXMODE4,   PULL_DISABLED,                OUTPUT },
  { MCBSP1_FSR,    MUXMODE4,   PULL_UP_SELECTED,             OUTPUT },
  { MCBSP1_DX,     MUXMODE4,   PULL_DISABLED,                OUTPUT },
  { MCBSP1_DR,     MUXMODE4,   PULL_DISABLED,                OUTPUT },
  { MCBSP1_CLKS,   MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { MCBSP1_FSX,    MUXMODE4,   PULL_DISABLED,                OUTPUT },
  { MCBSP1_CLKX,   MUXMODE4,   PULL_DISABLED,                OUTPUT },
  { UART3_CTS_RCTX,MUXMODE0,   PULL_UP_SELECTED,                 INPUT  },
  { UART3_RTS_SD,  MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { UART3_RX_IRRX, MUXMODE0,   PULL_DISABLED,                INPUT  },
  { UART3_TX_IRTX, MUXMODE0,   PULL_DISABLED,                OUTPUT },
  { HSUSB0_CLK,    MUXMODE0,   PULL_DISABLED,                INPUT  },
  { HSUSB0_STP,    MUXMODE0,   PULL_UP_SELECTED,             OUTPUT },
  { HSUSB0_DIR,    MUXMODE0,   PULL_DISABLED,                INPUT  },
  { HSUSB0_NXT,    MUXMODE0,   PULL_DISABLED,                INPUT  },
  { HSUSB0_DATA0,  MUXMODE0,   PULL_DISABLED,                INPUT  },
  { HSUSB0_DATA1,  MUXMODE0,   PULL_DISABLED,                INPUT  },
  { HSUSB0_DATA2,  MUXMODE0,   PULL_DISABLED,                INPUT  },
  { HSUSB0_DATA3,  MUXMODE0,   PULL_DISABLED,                INPUT  },
  { HSUSB0_DATA4,  MUXMODE0,   PULL_DISABLED,                INPUT  },
  { HSUSB0_DATA5,  MUXMODE0,   PULL_DISABLED,                INPUT  },
  { HSUSB0_DATA6,  MUXMODE0,   PULL_DISABLED,                INPUT  },
  { HSUSB0_DATA7,  MUXMODE0,   PULL_DISABLED,                INPUT  },
  { I2C1_SCL,      MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { I2C1_SDA,      MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { I2C2_SCL,      MUXMODE4,   PULL_UP_SELECTED,             INPUT  },
  { I2C2_SDA,      MUXMODE4,   PULL_UP_SELECTED,             INPUT  },
  { I2C3_SCL,      MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { I2C3_SDA,      MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { HDQ_SIO,       MUXMODE4,   PULL_DISABLED,                OUTPUT },
  { MCSPI1_CLK,    MUXMODE4,   PULL_UP_SELECTED,             INPUT  },
  { MCSPI1_SIMO,   MUXMODE4,   PULL_UP_SELECTED,             INPUT  },
  { MCSPI1_SOMI,   MUXMODE0,   PULL_DISABLED,                INPUT  },
  { MCSPI1_CS0,    MUXMODE0,   PULL_UP_SELECTED,                 INPUT  },
  { MCSPI1_CS1,    MUXMODE0,   PULL_UP_SELECTED,                 OUTPUT },
  { MCSPI1_CS2,    MUXMODE4,   PULL_DISABLED,                OUTPUT },
  { MCSPI1_CS3,    MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { MCSPI2_CLK,    MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { MCSPI2_SIMO,   MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { MCSPI2_SOMI,   MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { MCSPI2_CS0,    MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { MCSPI2_CS1,    MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { SYS_NIRQ,      MUXMODE0,   PULL_UP_SELECTED,             INPUT  },
  { SYS_CLKOUT2,   MUXMODE4,   PULL_UP_SELECTED,             INPUT  },
  { ETK_CLK,       MUXMODE3,   PULL_UP_SELECTED,             OUTPUT },
  { ETK_CTL,       MUXMODE3,   PULL_UP_SELECTED,             OUTPUT },
  { ETK_D0,        MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { ETK_D1,        MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { ETK_D2,        MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { ETK_D3,        MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { ETK_D4,        MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { ETK_D5,        MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { ETK_D6,        MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { ETK_D7,        MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { ETK_D8,        MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { ETK_D9,        MUXMODE4,   PULL_UP_SELECTED,             INPUT  },
  { ETK_D10,       MUXMODE3,   PULL_UP_SELECTED,             OUTPUT },
  { ETK_D11,       MUXMODE3,   PULL_UP_SELECTED,             OUTPUT },
  { ETK_D12,       MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { ETK_D13,       MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { ETK_D14,       MUXMODE3,   PULL_UP_SELECTED,             INPUT  },
  { ETK_D15,       MUXMODE3,   PULL_UP_SELECTED,             INPUT  }
};


VOID
PadConfiguration (
  BEAGLEBOARD_REVISION Revision
  )
{
  UINTN             Index;
  UINT16            PadConfiguration;
  PAD_CONFIGURATION *BoardConfiguration;
  UINTN             NumPinsToConfigure;

  for (Index = 0; Index < NUM_PINS_SHARED; Index++) {
    // Set up Pad configuration for particular pin.
    PadConfiguration =  (PadConfigurationTableShared[Index].MuxMode << MUXMODE_OFFSET);
    PadConfiguration |= (PadConfigurationTableShared[Index].PullConfig << PULL_CONFIG_OFFSET);
    PadConfiguration |= (PadConfigurationTableShared[Index].InputEnable << INPUTENABLE_OFFSET);

    // Configure the pin with specific Pad configuration.
    MmioWrite16(PadConfigurationTableShared[Index].Pin, PadConfiguration);
  }

  /*
  if (Revision == REVISION_XM) {
    BoardConfiguration = PadConfigurationTableXm;
    NumPinsToConfigure = NUM_PINS_XM;
  } else {
    BoardConfiguration = PadConfigurationTableAbc;
    NumPinsToConfigure = NUM_PINS_ABC;
  }

  for (Index = 0; Index < NumPinsToConfigure; Index++) {
    //Set up Pad configuration for particular pin.
    PadConfiguration =  (BoardConfiguration[Index].MuxMode << MUXMODE_OFFSET);
    PadConfiguration |= (BoardConfiguration[Index].PullConfig << PULL_CONFIG_OFFSET);
    PadConfiguration |= (BoardConfiguration[Index].InputEnable << INPUTENABLE_OFFSET);

    //Configure the pin with specific Pad configuration.
    MmioWrite16(BoardConfiguration[Index].Pin, PadConfiguration);
  }*/
}
