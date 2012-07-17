/** @file

  Copyright (c) 2008 - 2009, Apple Inc. All rights reserved.<BR>
  
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

/** PAY ATTENTION: TI81XX
#define SRAM0_START			0x402F0400
#define UART0_BASE			0x44E09000
#define UART1_BASE			0x48022000
#define UART2_BASE			0x48024000
#define UART3_BASE			0x481A6000
#define DM_TIMER0_BASE			0x4802C000
#define DM_TIMER1_BASE			0x4802E000
#define DM_TIMER2_BASE			0x48040000
#define DM_TIMER3_BASE			0x48042000
#define DM_TIMER4_BASE			0x48044000
#define DM_TIMER5_BASE			0x48046000
#define DM_TIMER6_BASE			0x48048000
#define DM_TIMER7_BASE			0x4804A000
#define GPIO2_BASE			0x481AC000
#define ELM_BASE			0x48080000
#define WDT_BASE			0x44E35000
#define CTRL_BASE			0x44E10000
#define PRCM_BASE			0x44E00000
#define EMIF4_0_CFG_BASE		0x4C000000
#define EMIF4_1_CFG_BASE		0x4D000000
#define DMM_BASE			0x4E000000
#define GPMC_BASE			0x50000000
#define DDRPHY_0_CONFIG_BASE		(CTRL_BASE + 0x1400)
#define DDRPHY_CONFIG_BASE		DDRPHY_0_CONFIG_BASE
#define AM335X_CPSW_BASE               0x4A100000
#define AM335X_CPSW_MDIO_BASE          0x4A101000
#define AM335X_RTC_BASE			0x44E3E000
# define OMAP_HSMMC1_BASE		0x48060100
# define OMAP_HSMMC2_BASE		0x481D8100
 */


#include <PiPei.h>
#include <Library/IoLib.h>
#include <Library/DebugLib.h>
#include <Am335x/Am335x.h>
#include <BeagleBone.h>

/**
#define NUM_PINS_SHARED 232
#define NUM_PINS_ABC 6
#define NUM_PINS_XM 12
**/

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

#define CTRL_BASE 0x44E10000
#define PAD_CTRL_BASE	0x800
#define OFFSET(x)	(unsigned int) (&((struct pad_signals *) (PAD_CTRL_BASE))->x + CTRL_BASE)

PAD_CONFIGURATION PadConfigurationTableBone[] = {
//  Pin							MuxMode,  PullConfig,    		InputEnable
//  UART0
	{OFFSET(uart0_rxd), 		MUXMODE0, PULL_UP_SELECTED, 	INPUT},
	{OFFSET(uart0_txd),			MUXMODE0, PULL_DOWN_SELECTED, 	OUTPUT},
//  UART3
	//{OFFSET(spi0_cs1), 			MUXMODE1, PULL_DOWN_SELECTED, 	INPUT},
	//{OFFSET(ecap0_in_pwm0_out),	MUXMODE1, PULL_DOWN_SELECTED, 	OUTPUT},
//  NAND
	/**
	{OFFSET(gpmc_ad0), 			MUXMODE0, PULL_UP_SELECTED, 	INPUT},
	{OFFSET(gpmc_ad1), 			MUXMODE0, PULL_UP_SELECTED, 	INPUT},
	{OFFSET(gpmc_ad2), 			MUXMODE0, PULL_UP_SELECTED, 	INPUT},
	{OFFSET(gpmc_ad3), 			MUXMODE0, PULL_UP_SELECTED, 	INPUT},
	{OFFSET(gpmc_ad4), 			MUXMODE0, PULL_UP_SELECTED, 	INPUT},
	{OFFSET(gpmc_ad5), 			MUXMODE0, PULL_UP_SELECTED, 	INPUT},
	{OFFSET(gpmc_ad6), 			MUXMODE0, PULL_UP_SELECTED, 	INPUT},
	{OFFSET(gpmc_ad7), 			MUXMODE0, PULL_UP_SELECTED, 	INPUT},
	{OFFSET(gpmc_wait0), 		MUXMODE0, PULL_UP_SELECTED, 	INPUT},
	{OFFSET(gpmc_wpn), 			MUXMODE7, PULL_UP_SELECTED, 	INPUT},
	{OFFSET(gpmc_csn0), 		MUXMODE0, PULL_DOWN_SELECTED, 	OUTPUT},
	{OFFSET(gpmc_advn_ale), 	MUXMODE0, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(gpmc_oen_ren), 		MUXMODE0, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(gpmc_wen), 			MUXMODE0, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(gpmc_be0n_cle), 	MUXMODE0, PULL_DOWN_SELECTED,	OUTPUT},
	**/
//	I2C0
	{OFFSET(i2c0_sda), 			MUXMODE0, PULL_DOWN_SELECTED, 	INPUT},	/* I2C_DATA */ /*SLEWCTRL*/
	{OFFSET(i2c0_scl), 			MUXMODE0, PULL_DOWN_SELECTED, 	INPUT},	/* I2C_SCLK */ /*SLEWCTRL*/
//	I2C1
	{OFFSET(spi0_d1), 			MUXMODE2, PULL_DOWN_SELECTED, 	INPUT},	/* I2C_DATA */ /*SLEWCTRL*/
	{OFFSET(spi0_cs0), 			MUXMODE2, PULL_DOWN_SELECTED, 	INPUT},	/* I2C_SCLK */ /*SLEWCTRL*/
//	RGMII1
/**
	{OFFSET(mii1_txen), 		MUXMODE2, PULL_DISABLED,		OUTPUT},
	{OFFSET(mii1_rxdv), 		MUXMODE2, PULL_DISABLED,		INPUT},
	{OFFSET(mii1_txd3), 		MUXMODE2, PULL_DISABLED,		OUTPUT},
	{OFFSET(mii1_txd2), 		MUXMODE2, PULL_DISABLED,		OUTPUT},
	{OFFSET(mii1_txd1), 		MUXMODE2, PULL_DISABLED,		OUTPUT},
	{OFFSET(mii1_txd0), 		MUXMODE2, PULL_DISABLED,		OUTPUT},
	{OFFSET(mii1_txclk), 		MUXMODE2, PULL_DISABLED,		OUTPUT},
	{OFFSET(mii1_rxclk), 		MUXMODE2, PULL_DISABLED,		INPUT},
	{OFFSET(mii1_rxd3), 		MUXMODE2, PULL_DISABLED,		INPUT},
	{OFFSET(mii1_rxd2), 		MUXMODE2, PULL_DISABLED,		INPUT},
	{OFFSET(mii1_rxd1), 		MUXMODE2, PULL_DISABLED,		INPUT},
	{OFFSET(mii1_rxd0), 		MUXMODE2, PULL_DISABLED,		INPUT},
	{OFFSET(mdio_data), 		MUXMODE0, PULL_UP_SELECTED, 	INPUT},
	{OFFSET(mdio_clk), 			MUXMODE0, PULL_UP_SELECTED, 	OUTPUT},
//	RGMII2
	{OFFSET(gpmc_a0), 			MUXMODE2, PULL_DISABLED,		OUTPUT},
	{OFFSET(gpmc_a1), 			MUXMODE2, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_a2), 			MUXMODE2, PULL_DISABLED,		OUTPUT},
	{OFFSET(gpmc_a3), 			MUXMODE2, PULL_DISABLED,		OUTPUT},
	{OFFSET(gpmc_a4), 			MUXMODE2, PULL_DISABLED,		OUTPUT},
	{OFFSET(gpmc_a5), 			MUXMODE2, PULL_DISABLED,		OUTPUT},
	{OFFSET(gpmc_a6), 			MUXMODE2, PULL_DISABLED,		OUTPUT},
	{OFFSET(gpmc_a7), 			MUXMODE2, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_a8), 			MUXMODE2, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_a9), 			MUXMODE2, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_a10), 			MUXMODE2, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_a11), 			MUXMODE2, PULL_DISABLED,		INPUT},
	{OFFSET(mdio_data), 		MUXMODE0, PULL_UP_SELECTED, 	INPUT},
	{OFFSET(mdio_clk), 			MUXMODE0, PULL_UP_SELECTED, 	OUTPUT},
**/
//	MII1
	{OFFSET(mii1_rxerr), 		MUXMODE0, PULL_DISABLED,		INPUT},	/* MII1_RXERR */
	{OFFSET(mii1_txen), 		MUXMODE0, PULL_DISABLED,		OUTPUT},/* MII1_TXEN */
	{OFFSET(mii1_rxdv), 		MUXMODE0, PULL_DISABLED,		INPUT},	/* MII1_RXDV */
	{OFFSET(mii1_txd3), 		MUXMODE0, PULL_DISABLED,		OUTPUT},/* MII1_TXD3 */
	{OFFSET(mii1_txd2), 		MUXMODE0, PULL_DISABLED,		OUTPUT},/* MII1_TXD2 */
	{OFFSET(mii1_txd1), 		MUXMODE0, PULL_DISABLED,		OUTPUT},/* MII1_TXD1 */
	{OFFSET(mii1_txd0), 		MUXMODE0, PULL_DISABLED,		OUTPUT},/* MII1_TXD0 */
	{OFFSET(mii1_txclk), 		MUXMODE0, PULL_DISABLED,		INPUT},	/* MII1_TXCLK */
	{OFFSET(mii1_rxclk), 		MUXMODE0, PULL_DISABLED,		INPUT},	/* MII1_RXCLK */
	{OFFSET(mii1_rxd3),			MUXMODE0, PULL_DISABLED,		INPUT},	/* MII1_RXD3 */
	{OFFSET(mii1_rxd2), 		MUXMODE0, PULL_DISABLED,		INPUT},	/* MII1_RXD2 */
	{OFFSET(mii1_rxd1), 		MUXMODE0, PULL_DISABLED,		INPUT},	/* MII1_RXD1 */
	{OFFSET(mii1_rxd0), 		MUXMODE0, PULL_DISABLED,		INPUT},	/* MII1_RXD0 */
	{OFFSET(mdio_data), 		MUXMODE0, PULL_UP_SELECTED,		INPUT}, /* MDIO_DATA */
	{OFFSET(mdio_clk), 			MUXMODE0, PULL_UP_SELECTED, 	OUTPUT},/* MDIO_CLK */
//	RMII1
/**
	{OFFSET(mii1_crs), 			MUXMODE1, PULL_DISABLED,		INPUT},
	{OFFSET(mii1_rxerr), 		MUXMODE1, PULL_DISABLED,		INPUT},
	{OFFSET(mii1_txen), 		MUXMODE1, PULL_DISABLED,		OUTPUT},
	{OFFSET(mii1_txd1), 		MUXMODE1, PULL_DISABLED,		OUTPUT},
	{OFFSET(mii1_txd0), 		MUXMODE1, PULL_DISABLED,		OUTPUT},
	{OFFSET(mii1_rxd1), 		MUXMODE1, PULL_DISABLED,		INPUT},
	{OFFSET(mii1_rxd0), 		MUXMODE1, PULL_DISABLED,		INPUT},
	{OFFSET(mdio_data), 		MUXMODE0, PULL_UP_SELECTED, 	INPUT},
	{OFFSET(mdio_clk), 			MUXMODE0, PULL_UP_SELECTED,		OUTPUT},
	{OFFSET(rmii1_refclk), 		MUXMODE0, PULL_DISABLED,		INPUT},
**/
//	NOR
/**
	{OFFSET(lcd_data0), 		MUXMODE1, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(lcd_data1), 		MUXMODE1, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(lcd_data2), 		MUXMODE1, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(lcd_data3), 		MUXMODE1, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(lcd_data4), 		MUXMODE1, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(lcd_data5), 		MUXMODE1, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(lcd_data6), 		MUXMODE1, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(lcd_data7), 		MUXMODE1, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(gpmc_a8), 			MUXMODE0, PULL_DISABLED,		OUTPUT},
	{OFFSET(gpmc_a9), 			MUXMODE0, PULL_DISABLED,		OUTPUT},
	{OFFSET(gpmc_a10), 			MUXMODE0, PULL_DISABLED,		OUTPUT},
	{OFFSET(gpmc_a11), 			MUXMODE0, PULL_DISABLED,		OUTPUT},
	{OFFSET(lcd_data8), 		MUXMODE1, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(lcd_data9), 		MUXMODE1, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(lcd_data10), 		MUXMODE1, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(lcd_data11), 		MUXMODE1, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(lcd_data12), 		MUXMODE1, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(lcd_data13), 		MUXMODE1, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(lcd_data14),		MUXMODE1, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(lcd_data15), 		MUXMODE1, PULL_DOWN_SELECTED,	OUTPUT},
	{OFFSET(gpmc_a4), 			MUXMODE4, PULL_DISABLED,		OUTPUT},
	{OFFSET(gpmc_a5), 			MUXMODE4, PULL_DISABLED,		OUTPUT},
	{OFFSET(gpmc_a6), 			MUXMODE4, PULL_DISABLED,		OUTPUT},
	{OFFSET(gpmc_ad0), 			MUXMODE0, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_ad1), 			MUXMODE0, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_ad2), 			MUXMODE0, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_ad3), 			MUXMODE0, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_ad4), 			MUXMODE0, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_ad5), 			MUXMODE0, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_ad6), 			MUXMODE0, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_ad7), 			MUXMODE0, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_ad8), 			MUXMODE0, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_ad9), 			MUXMODE0, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_ad10), 		MUXMODE0, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_ad11), 		MUXMODE0, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_ad12), 		MUXMODE0, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_ad13), 		MUXMODE0, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_ad14), 		MUXMODE0, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_ad15), 		MUXMODE0, PULL_DISABLED,		INPUT},
	{OFFSET(gpmc_csn0), 		MUXMODE0, PULL_UP_SELECTED,		OUTPUT},
	{OFFSET(gpmc_oen_ren), 		MUXMODE0, PULL_UP_SELECTED,		OUTPUT},
	{OFFSET(gpmc_wen),			MUXMODE0, PULL_UP_SELECTED,		OUTPUT},
	{OFFSET(gpmc_wait0), 		MUXMODE0, PULL_UP_SELECTED,		INPUT},
	{OFFSET(lcd_ac_bias_en), 	MUXMODE7, PULL_DOWN_SELECTED,	INPUT},
**/
//	MMC0
	{OFFSET(mmc0_dat3), 		MUXMODE0, PULL_UP_SELECTED, 	INPUT},	/* MMC0_DAT3 */
	{OFFSET(mmc0_dat2), 		MUXMODE0, PULL_UP_SELECTED, 	INPUT},	/* MMC0_DAT2 */
	{OFFSET(mmc0_dat1), 		MUXMODE0, PULL_UP_SELECTED, 	INPUT},	/* MMC0_DAT1 */
	{OFFSET(mmc0_dat0), 		MUXMODE0, PULL_UP_SELECTED, 	INPUT},	/* MMC0_DAT0 */
	{OFFSET(mmc0_clk), 			MUXMODE0, PULL_UP_SELECTED, 	INPUT},	/* MMC0_CLK */
	{OFFSET(mmc0_cmd), 			MUXMODE0, PULL_UP_SELECTED, 	INPUT},	/* MMC0_CMD */
	{OFFSET(mcasp0_aclkr), 		MUXMODE4, PULL_DISABLED,		INPUT},	/* MMC0_WP */
	{OFFSET(spi0_cs1), 			MUXMODE5, PULL_UP_SELECTED,		INPUT},	/* MMC0_CD */
//	MMC1
	{OFFSET(gpmc_ad3), 			MUXMODE1, PULL_UP_SELECTED,		INPUT},	/* MMC1_DAT3 */
	{OFFSET(gpmc_ad2), 			MUXMODE1, PULL_UP_SELECTED,		INPUT},	/* MMC1_DAT2 */
	{OFFSET(gpmc_ad1), 			MUXMODE1, PULL_UP_SELECTED,		INPUT},	/* MMC1_DAT1 */
	{OFFSET(gpmc_ad0), 			MUXMODE1, PULL_UP_SELECTED,		INPUT},	/* MMC1_DAT0 */
	{OFFSET(gpmc_csn1), 		MUXMODE2, PULL_UP_SELECTED,		INPUT},	/* MMC1_CLK */
	{OFFSET(gpmc_csn2), 		MUXMODE2, PULL_UP_SELECTED,		INPUT},	/* MMC1_CMD */
	{OFFSET(gpmc_csn0), 		MUXMODE7, PULL_UP_SELECTED,		INPUT},	/* MMC1_WP */
	{OFFSET(gpmc_advn_ale),		MUXMODE7, PULL_UP_SELECTED,		INPUT},	/* MMC1_CD */
//	SPI0
	{OFFSET(spi0_sclk), 		MUXMODE0, PULL_DOWN_SELECTED, 	INPUT},	/*SPI0_SCLK */
	{OFFSET(spi0_d0), 			MUXMODE0, PULL_DOWN_SELECTED | PULL_UP_SELECTED, INPUT}, /*SPI0_D0 */
	{OFFSET(spi0_d1), 			MUXMODE0, PULL_DOWN_SELECTED, 	INPUT}, /*SPI0_D1 */
	{OFFSET(spi0_cs0), 			MUXMODE0, PULL_DOWN_SELECTED | PULL_UP_SELECTED, INPUT},	/*SPI0_CS0 */
//	SPI1
	//{OFFSET(mcasp0_aclkx), 		MUXMODE3, PULL_DOWN_SELECTED, 	INPUT},	/*SPI0_SCLK */
	//{OFFSET(mcasp0_fsx), 		MUXMODE3, PULL_DOWN_SELECTED | PULL_UP_SELECTED, INPUT}, /*SPI0_D0 */
	//{OFFSET(mcasp0_axr0), 		MUXMODE3, PULL_DOWN_SELECTED, 	INPUT}, /*SPI0_D1 */
	//{OFFSET(mcasp0_ahclkr), 	MUXMODE3, PULL_DOWN_SELECTED | PULL_UP_SELECTED, INPUT}, /*SPI0_CS0 */
//	GPIO0_7
	//{OFFSET(ecap0_in_pwm0_out), MUXMODE7, PULL_DOWN_SELECTED,	OUTPUT},	/* GPIO0_7 */
	{-1},
};

VOID
PadConfiguration (
  BEAGLEBOARD_REVISION Revision
  )
{
  UINTN             Index;
  UINT16            PadConfiguration;
  //PAD_CONFIGURATION *BoardConfiguration;
  //UINTN             NumPinsToConfigure;

  for (Index = 0; PadConfigurationTableBone[Index].Pin > -1; Index++) {
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
