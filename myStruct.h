/*
 * myStruct.h
 *
 *  Created on: 2017/05/22
 *      Author: yuki
 */

#ifndef MYSTRUCT_H_
#define MYSTRUCT_H_
// NOTE: __IO is needed to operate correctly.

typedef struct { // SYSCON
	__IO uint32_t SYSMEMREMAP;            /*!< Offset: 0x000 System memory remap (R/W) */
	union { // PRESETCTRL
		__IO uint32_t WORD;             /*!< Offset: 0x004 Peripheral reset control (R/W) */
		struct {
			__IO uint32_t SSP0_RST_N:1;
			__IO uint32_t I2C_RST_N:1;
			__IO uint32_t SSP1_RST_N:1;
			__IO uint32_t CAN_RST_N:1;
		} BIT;
	} PRESETCTRL;
	__IO uint32_t SYSPLLCTRL;             /*!< Offset: 0x008 System PLL control (R/W) */
	__I uint32_t SYSPLLSTAT;             /*!< Offset: 0x00C System PLL status (R/ ) */
	uint32_t RESERVED0[4];

	__IO uint32_t SYSOSCCTRL;             /*!< Offset: 0x020 System oscillator control (R/W) */
	__IO uint32_t WDTOSCCTRL;             /*!< Offset: 0x024 Watchdog oscillator control (R/W) */
	__IO uint32_t IRCCTRL;                /*!< Offset: 0x028 IRC control (R/W) */
	uint32_t RESERVED1[1];
	__IO uint32_t SYSRSTSTAT;             /*!< Offset: 0x030 System reset status Register (R/ ) */
	uint32_t RESERVED2[3];
	__IO uint32_t SYSPLLCLKSEL;           /*!< Offset: 0x040 System PLL clock source select (R/W) */
	__IO uint32_t SYSPLLCLKUEN;           /*!< Offset: 0x044 System PLL clock source update enable (R/W) */
	uint32_t RESERVED3[10];

	__IO uint32_t MAINCLKSEL;             /*!< Offset: 0x070 Main clock source select (R/W) */
	__IO uint32_t MAINCLKUEN;             /*!< Offset: 0x074 Main clock source update enable (R/W) */
	__IO uint32_t SYSAHBCLKDIV;           /*!< Offset: 0x078 System AHB clock divider (R/W) */
	uint32_t RESERVED4[1];

	union { // SYSAHBCLKCTRL
		__IO uint32_t WORD;          /*!< Offset: 0x080 System AHB clock control (R/W) */
		struct {
			__IO uint32_t SYS:1;
			__IO uint32_t ROM:1;
			__IO uint32_t RAM:1;
			__IO uint32_t FLASHREG:1;
			__IO uint32_t FLASHARRAY:1;
			__IO uint32_t I2C:1;
			__IO uint32_t GPIO:1;
			__IO uint32_t CT16B0:1;
			__IO uint32_t CT16B1:1;
			__IO uint32_t CT32B0:1;
			__IO uint32_t CT32B1:1;
			__IO uint32_t SSP0:1;
			__IO uint32_t UART:1;
			__IO uint32_t ADC:1;
			uint32_t RESERVED:1;
			__IO uint32_t WDT:1;
			__IO uint32_t IOCON:1;
			__IO uint32_t CAN:1;
			__IO uint32_t SSP1:1;
		} BIT;
	} SYSAHBCLKCTRL;
	uint32_t RESERVED5[4];
	__IO uint32_t SSP0CLKDIV;             /*!< Offset: 0x094 SSP0 clock divider (R/W) */
	__IO uint32_t UARTCLKDIV;             /*!< Offset: 0x098 UART clock divider (R/W) */
	__IO uint32_t SSP1CLKDIV;             /*!< Offset: 0x09C SSP1 clock divider (R/W) */
	uint32_t RESERVED6[12];

	__IO uint32_t WDTCLKSEL;              /*!< Offset: 0x0D0 WDT clock source select (R/W) */
	__IO uint32_t WDTCLKUEN;              /*!< Offset: 0x0D4 WDT clock source update enable (R/W) */
	__IO uint32_t WDTCLKDIV;              /*!< Offset: 0x0D8 WDT clock divider (R/W) */
	uint32_t RESERVED8[1];
	__IO uint32_t CLKOUTCLKSEL;           /*!< Offset: 0x0E0 CLKOUT clock source select (R/W) */
	__IO uint32_t CLKOUTUEN;              /*!< Offset: 0x0E4 CLKOUT clock source update enable (R/W) */
	__IO uint32_t CLKOUTDIV;              /*!< Offset: 0x0E8 CLKOUT clock divider (R/W) */
	uint32_t RESERVED9[5];

	__IO uint32_t PIOPORCAP0;             /*!< Offset: 0x100 POR captured PIO status 0 (R/ ) */
	__IO uint32_t PIOPORCAP1;             /*!< Offset: 0x104 POR captured PIO status 1 (R/ ) */
	uint32_t RESERVED10[18];
	__IO uint32_t BODCTRL;                /*!< Offset: 0x150 BOD control (R/W) */
	__IO uint32_t SYSTCKCAL;              /*!< Offset: 0x154 System tick counter calibration (R/W) */

	uint32_t RESERVED13[7];
	__IO uint32_t NMISRC;                 /*!< Offset: 0x174 NMI source selection register (R/W) */
	uint32_t RESERVED14[34];

	__IO uint32_t STARTAPRP0;             /*!< Offset: 0x200 Start logic edge control Register 0 (R/W) */
	__IO uint32_t STARTERP0;              /*!< Offset: 0x204 Start logic signal enable Register 0 (R/W) */
	__O  uint32_t STARTRSRP0CLR;          /*!< Offset: 0x208 Start logic reset Register 0  ( /W) */
	__IO uint32_t STARTSRP0;              /*!< Offset: 0x20C Start logic status Register 0 (R/W) */
	__IO uint32_t STARTAPRP1;             /*!< Offset: 0x210 Start logic edge control Register 0 (R/W). (LPC11UXX only) */
	__IO uint32_t STARTERP1;              /*!< Offset: 0x214 Start logic signal enable Register 0 (R/W). (LPC11UXX only) */
	__O  uint32_t STARTRSRP1CLR;          /*!< Offset: 0x218 Start logic reset Register 0  ( /W). (LPC11UXX only) */
	__IO uint32_t STARTSRP1;              /*!< Offset: 0x21C Start logic status Register 0 (R/W). (LPC11UXX only) */
	uint32_t RESERVED17[4];

	__IO uint32_t PDSLEEPCFG;             /*!< Offset: 0x230 Power-down states in Deep-sleep mode (R/W) */
	__IO uint32_t PDAWAKECFG;             /*!< Offset: 0x234 Power-down states after wake-up (R/W) */
	__IO uint32_t PDRUNCFG;               /*!< Offset: 0x238 Power-down configuration Register (R/W) */
	uint32_t RESERVED15[110];
	__I  uint32_t DEVICE_ID;              /*!< Offset: 0x3F4 Device ID (R/ ) */
} LPC_SYSCON_TypeDef_My;

typedef struct { // NVIC
	// For priority, just use NVIC_SetPriority() instead.
	union { // ISER
		__IO uint32_t WORD;                 /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register           */
		struct {
			__IO uint32_t WAKEUP0_IRQ:1;
			__IO uint32_t WAKEUP1_IRQ:1;
			__IO uint32_t WAKEUP2_IRQ:1;
			__IO uint32_t WAKEUP3_IRQ:1;
			__IO uint32_t WAKEUP4_IRQ:1;
			__IO uint32_t WAKEUP5_IRQ:1;
			__IO uint32_t WAKEUP6_IRQ:1;
			__IO uint32_t WAKEUP7_IRQ:1;
			__IO uint32_t WAKEUP8_IRQ:1;
			__IO uint32_t WAKEUP9_IRQ:1;
			__IO uint32_t WAKEUP10_IRQ:1;
			__IO uint32_t WAKEUP11_IRQ:1;
			__IO uint32_t WAKEUP12_IRQ:1;
			__IO uint32_t CAN_IRQ:1;
			__IO uint32_t SSP1_IRQ:1;
			__IO uint32_t I2C_IRQ:1;
			__IO uint32_t TIMER_16_0_IRQ:1;
			__IO uint32_t TIMER_16_1_IRQ:1;
			__IO uint32_t TIMER_32_0_IRQ:1;
			__IO uint32_t TIMER_32_1_IRQ:1;
			__IO uint32_t SSP0_IRQ:1;
			__IO uint32_t UART_IRQ:1;
			__IO uint32_t Reserved0_IRQ:1;
			__IO uint32_t Reserved1_IRQ:1;
			__IO uint32_t ADC_IRQ:1;
			__IO uint32_t WDT_IRQ:1;
			__IO uint32_t BOD_IRQ:1;
			__IO uint32_t FMC_IRQ:1;
			__IO uint32_t EINT3_IRQ:1;
			__IO uint32_t EINT2_IRQ:1;
			__IO uint32_t EINT1_IRQ:1;
			__IO uint32_t EINT0_IRQ:1;
		} BIT;
	}ISER;
	uint32_t RESERVED0[31];
	union { // ICER
		__IO uint32_t WORD;                 /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register          */
		struct {
			__IO uint32_t WAKEUP0_IRQ:1;
			__IO uint32_t WAKEUP1_IRQ:1;
			__IO uint32_t WAKEUP2_IRQ:1;
			__IO uint32_t WAKEUP3_IRQ:1;
			__IO uint32_t WAKEUP4_IRQ:1;
			__IO uint32_t WAKEUP5_IRQ:1;
			__IO uint32_t WAKEUP6_IRQ:1;
			__IO uint32_t WAKEUP7_IRQ:1;
			__IO uint32_t WAKEUP8_IRQ:1;
			__IO uint32_t WAKEUP9_IRQ:1;
			__IO uint32_t WAKEUP10_IRQ:1;
			__IO uint32_t WAKEUP11_IRQ:1;
			__IO uint32_t WAKEUP12_IRQ:1;
			__IO uint32_t CAN_IRQ:1;
			__IO uint32_t SSP1_IRQ:1;
			__IO uint32_t I2C_IRQ:1;
			__IO uint32_t TIMER_16_0_IRQ:1;
			__IO uint32_t TIMER_16_1_IRQ:1;
			__IO uint32_t TIMER_32_0_IRQ:1;
			__IO uint32_t TIMER_32_1_IRQ:1;
			__IO uint32_t SSP0_IRQ:1;
			__IO uint32_t UART_IRQ:1;
			__IO uint32_t Reserved0_IRQ:1;
			__IO uint32_t Reserved1_IRQ:1;
			__IO uint32_t ADC_IRQ:1;
			__IO uint32_t WDT_IRQ:1;
			__IO uint32_t BOD_IRQ:1;
			__IO uint32_t FMC_IRQ:1;
			__IO uint32_t EINT3_IRQ:1;
			__IO uint32_t EINT2_IRQ:1;
			__IO uint32_t EINT1_IRQ:1;
			__IO uint32_t EINT0_IRQ:1;
		} BIT;
	} ICER;
	uint32_t RSERVED1[31];
	__IO uint32_t ISPR;                 /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register           */
	uint32_t RESERVED2[31];
	__IO uint32_t ICPR;                 /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register         */
	uint32_t RESERVED3[31];
	uint32_t RESERVED4[64];
	__IO uint32_t IPR[8];                  /*!< Offset: 0x3EC (R/W)  Interrupt Priority Register              */
}  NVIC_Type_My;

typedef struct { // SysTick
	union { // CTRL
		__IO uint32_t WORD;                    /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
		struct {
			__IO uint32_t ENABLE:1;
			__IO uint32_t TICKINT:1;
			__IO uint32_t CLKSOURCE:1;
			int32_t RESERVED:13;
			__IO int32_t COUNTFLAG:1;
		} BIT;
	} CTRL;
	__IO uint32_t LOAD;                    /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register       */
	__IO uint32_t VAL;                     /*!< Offset: 0x008 (R/W)  SysTick Current Value Register      */
	__I  uint32_t CALIB;                   /*!< Offset: 0x00C (R/ )  SysTick Calibration Register        */
} SysTick_Type_My;

typedef struct { // GPIO
	union {
		__IO uint32_t MASKED_ACCESS[4096];  /*!< Offset: 0x0000 to 0x3FFC Port data Register for pins PIOn_0 to PIOn_11 (R/W) */
		struct {
			uint32_t RESERVED0[4095];
			union {
				__IO uint32_t WORD;                 /*!< Offset: 0x3FFC Port data Register (R/W) */
				struct {
					__IO uint32_t B0:1;
					__IO uint32_t B1:1;
					__IO uint32_t B2:1;
					__IO uint32_t B3:1;
					__IO uint32_t B4:1;
					__IO uint32_t B5:1;
					__IO uint32_t B6:1;
					__IO uint32_t B7:1;
					__IO uint32_t B8:1;
					__IO uint32_t B9:1;
					__IO uint32_t B10:1;
					__IO uint32_t B11:1;
				} BIT;
			};
		} DATA;
	};

	uint32_t RESERVED1[4096];
	union {
		__IO uint32_t WORD;                    /*!< Offset: 0x8000 Data direction Register (R/W) */
		struct {
			__IO uint32_t B0:1;
			__IO uint32_t B1:1;
			__IO uint32_t B2:1;
			__IO uint32_t B3:1;
			__IO uint32_t B4:1;
			__IO uint32_t B5:1;
			__IO uint32_t B6:1;
			__IO uint32_t B7:1;
			__IO uint32_t B8:1;
			__IO uint32_t B9:1;
			__IO uint32_t B10:1;
			__IO uint32_t B11:1;
		} BIT;
	} DIR;

	__IO uint32_t IS;                     /*!< Offset: 0x8004 Interrupt sense Register (R/W) */
	__IO uint32_t IBE;                    /*!< Offset: 0x8008 Interrupt both edges Register (R/W) */
	__IO uint32_t IEV;                    /*!< Offset: 0x800C Interrupt event Register  (R/W) */
	__IO uint32_t IE;                     /*!< Offset: 0x8010 Interrupt mask Register (R/W) */
	__I uint32_t RIS;                    /*!< Offset: 0x8014 Raw interrupt status Register (R/ ) */
	__I uint32_t MIS;                    /*!< Offset: 0x8018 Masked interrupt status Register (R/ ) */
	__O uint32_t IC;                     /*!< Offset: 0x801C Interrupt clear Register (/W) */
} LPC_GPIO_My;

typedef struct{ // IOCON
	union { // PIO2_6
		__IO uint32_t WORD;                 /*!< Offset: 0x000 I/O configuration for pin PIO2_6 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO2_6;
	uint32_t RESERVED0[1];
	union { // PIO2_0
		__IO uint32_t WORD;                 /*!< Offset: 0x008 I/O configuration for pin PIO2_0/DTR/SSEL1 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO2_0;
	union { // RESET_PIO0_0
		__IO uint32_t WORD;           /*!< Offset: 0x00C I/O configuration for pin RESET/PIO0_0  (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} RESET_PIO0_0;
	union { // PIO0_1
		__IO uint32_t WORD;                 /*!< Offset: 0x010 I/O configuration for pin PIO0_1/CLKOUT/CT32B0_MAT2 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO0_1;
	union { // PIO1_8
		__IO uint32_t WORD;                 /*!< Offset: 0x014 I/O configuration for pin PIO1_8/CT16B1_CAP0 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO1_8;
	__IO uint32_t SSEL1_LOC;              /*!< Offset: 0x018 IOCON SSEL1 location register (IOCON_SSEL1_LOC, address 0x4004 4018) */
	union { // PIO0_2
		__IO uint32_t WORD;                 /*!< Offset: 0x01C I/O configuration for pin PIO0_2/SSEL0/CT16B0_CAP0 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO0_2;
	union { // PIO2_7
		__IO uint32_t WORD;                 /*!< Offset: 0x020 I/O configuration for pin PIO2_7 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO2_7;
	union { // PIO2_8
		__IO uint32_t WORD;                 /*!< Offset: 0x024 I/O configuration for pin PIO2_8 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO2_8;
	union { // PIO2_1
		__IO uint32_t WORD;                 /*!< Offset: 0x028 I/O configuration for pin PIO2_1/nDSR/SCK1 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO2_1;
	union { // PIO0_3
		__IO uint32_t WORD;                 /*!< Offset: 0x02C I/O configuration for pin PIO0_3 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO0_3;
	union { // PIO0_4
		__IO uint32_t WORD;                 /*!< Offset: 0x030 I/O configuration for pin PIO0_4/SCL (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			uint32_t RESERVED:5;
			__IO uint32_t I2CMODE:2;
		} BIT;
	} PIO0_4;
	union { // PIO0_5
		__IO uint32_t WORD;                 /*!< Offset: 0x034 I/O configuration for pin PIO0_5/SDA (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			uint32_t RESERVED:5;
			__IO uint32_t I2CMODE:2;
		} BIT;
	};
	union { // PIO1_9
		__IO uint32_t WORD;                 /*!< Offset: 0x038 I/O configuration for pin PIO1_9/CT16B1_MAT0 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO1_9;
	union { // PIO3_4
		__IO uint32_t WORD;                 /*!< Offset: 0x03C I/O configuration for pin PIO3_4 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO3_4;
	union { // PIO2_4
		__IO uint32_t WORD;                 /*!< Offset: 0x040 I/O configuration for pin PIO2_4 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO2_4;
	union { // PIO2_5
		__IO uint32_t WORD;                 /*!< Offset: 0x044 I/O configuration for pin PIO2_5 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO2_5;
	union { // PIO3_5
		__IO uint32_t WORD;                 /*!< Offset: 0x048 I/O configuration for pin PIO3_5 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO3_5;
	union { // PIO0_6
		__IO uint32_t WORD;                 /*!< Offset: 0x04C I/O configuration for pin PIO0_6/SCK0 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO0_6;
	union { // PIO0_7
		__IO uint32_t WORD;                 /*!< Offset: 0x050 I/O configuration for pin PIO0_7/nCTS (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO0_7;
	union { // PIO2_9
		__IO uint32_t WORD;                 /*!< Offset: 0x054 I/O configuration for pin PIO2_9 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO2_9;
	union { // PIO2_10
		__IO uint32_t WORD;                /*!< Offset: 0x058 I/O configuration for pin PIO2_10 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO2_10;
	union { // PIO2_2
		__IO uint32_t WORD;                 /*!< Offset: 0x05C I/O configuration for pin PIO2_2/DCD/MISO1 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO2_2;
	union { // PIO0_8
		__IO uint32_t WORD;                 /*!< Offset: 0x060 I/O configuration for pin PIO0_8/MISO0/CT16B0_MAT0 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO0_8;
	union { // PIO0_9
		__IO uint32_t WORD;                 /*!< Offset: 0x064 I/O configuration for pin PIO0_9/MOSI0/CT16B0_MAT1 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO0_9;
	union { // SWCLK_PIO0_10
		__IO uint32_t WORD;          /*!< Offset: 0x068 I/O configuration for pin SWCLK/PIO0_10/SCK0/CT16B0_MAT2 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} SWCLK_PIO0_10;
	union { // PIO1_10
		__IO uint32_t WORD;                /*!< Offset: 0x06C I/O configuration for pin PIO1_10/AD6/CT16B1_MAT1 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
			uint32_t RESERVED:1;
			__IO uint32_t ADMODE:1;
		} BIT;
	} PIO1_10;
	union { // PIO2_11
		__IO uint32_t WORD;                /*!< Offset: 0x070 I/O configuration for pin PIO2_11/SCK0 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO2_11;
	union { // R_PIO0_11
		__IO uint32_t WORD;              /*!< Offset: 0x074 I/O configuration for pin TDI/PIO0_11/AD0/CT32B0_MAT3 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
			uint32_t RESERVED:1;
			__IO uint32_t ADMODE:1;
		} BIT;
	} R_PIO0_11;
	union { // R_PIO1_0
		__IO uint32_t WORD;               /*!< Offset: 0x078 I/O configuration for pin TMS/PIO1_0/AD1/CT32B1_CAP0 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
			uint32_t RESERVED:1;
			__IO uint32_t ADMODE:1;
		} BIT;
	} R_PIO1_0;
	union { // R_PIO1_1
		__IO uint32_t WORD;               /*!< Offset: 0x07C I/O configuration for pin TDO/PIO1_1/AD2/CT32B1_MAT0 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
			uint32_t RESERVED:1;
			__IO uint32_t ADMODE:1;
		} BIT;
	} R_PIO1_1;
	union { // R_PIO1_2
		__IO uint32_t WORD;               /*!< Offset: 0x080 I/O configuration for pin nTRST/PIO1_2/AD3/CT32B1_MAT1 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
			uint32_t RESERVED:1;
			__IO uint32_t ADMODE:1;
		} BIT;
	} R_PIO1_2;

	union { // PIO3_0
		__IO uint32_t WORD;                 /*!< Offset: 0x084 I/O configuration for pin PIO3_0/nDTR (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO3_0;
	union { // PIO3_1
		__IO uint32_t WORD;                 /*!< Offset: 0x088 I/O configuration for pin PIO3_1/nDSR (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO3_1;
	union { // PIO2_3
		__IO uint32_t WORD;                 /*!< Offset: 0x08C I/O configuration for pin PIO2_3/RI/MOSI1 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
		} BIT;
	} PIO2_3;
	union { // SWDIO_PIO1_3
		__IO uint32_t WORD;           /*!< Offset: 0x090 I/O configuration for pin SWDIO/PIO1_3/AD4/CT32B1_MAT2 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
			uint32_t RESERVED:1;
			__IO uint32_t ADMODE:1;
		} BIT;
	} SWDIO_PIO1_3;
	union { // PIO1_4
		__IO uint32_t WORD;                 /*!< Offset: 0x094 I/O configuration for pin PIO1_4/AD5/CT32B1_MAT3 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
			uint32_t RESERVED:1;
			__IO uint32_t ADMODE:1;
		} BIT;
	} PIO1_4;
	union { // PIO1_11
		__IO uint32_t WORD;                /*!< Offset: 0x098 I/O configuration for pin PIO1_11/AD7 (R/W) */
		struct {
			__IO uint32_t FUNC:3;
			__IO uint32_t MODE:2;
			__IO uint32_t HYS:1;
			uint32_t RESERVED:1;
			__IO uint32_t ADMODE:1;
		} BIT;
	} PIO1_11;
	union { // PIO3_2
		__IO uint32_t WORD;                 /*!< Offset: 0x09C I/O configuration for pin PIO3_2/nDCD (R/W) */
		struct {
			uint32_t FUNC:3;
			uint32_t MODE:2;
			uint32_t HYS:1;
		} BIT;
	} PIO3_2;
	union { // PIO1_5
		__IO uint32_t WORD;                 /*!< Offset: 0x0A0 I/O configuration for pin PIO1_5/nRTS/CT32B0_CAP0 (R/W) */
		struct {
			uint32_t FUNC:3;
			uint32_t MODE:2;
			uint32_t HYS:1;
		} BIT;
	} PIO1_5;
	union { // PIO1_6
		__IO uint32_t WORD;                 /*!< Offset: 0x0A4 I/O configuration for pin PIO1_6/RXD/CT32B0_MAT0 (R/W) */
		struct {
			uint32_t FUNC:3;
			uint32_t MODE:2;
			uint32_t HYS:1;
		} BIT;
	} PIO1_6;
	union { // PIO1_7
		__IO uint32_t WORD;                 /*!< Offset: 0x0A8 I/O configuration for pin PIO1_7/TXD/CT32B0_MAT1 (R/W) */
		struct {
			uint32_t FUNC:3;
			uint32_t MODE:2;
			uint32_t HYS:1;
		} BIT;
	} PIO1_7;
	union { // PIO3_3
		__IO uint32_t WORD;                 /*!< Offset: 0x0AC I/O configuration for pin PIO3_3/nRI (R/W) */
		struct {
			uint32_t FUNC:3;
			uint32_t MODE:2;
			uint32_t HYS:1;
		} BIT;
	} PIO3_3;
	__IO uint32_t SCK_LOC;                /*!< Offset: 0x0B0 SCK pin location select Register (R/W) */
	__IO uint32_t DSR_LOC;                /*!< Offset: 0x0B4 DSR pin location select Register (R/W) */
	__IO uint32_t DCD_LOC;                /*!< Offset: 0x0B8 DCD pin location select Register (R/W) */
	__IO uint32_t RI_LOC;                 /*!< Offset: 0x0BC RI pin location Register (R/W) */
	__IO uint32_t CT16B0_CAP0_LOC;        /*!< Offset: 0x0C0 IOCON CT16B0_CAP0 location register (IOCON_CT16B0_CAP0_LOC, address 0x4004 40C0) */
	__IO uint32_t SCK1_LOC;               /*!< Offset: 0x0C4 IOCON SCK1 location register (IOCON_SCK1_LOC, address 0x4004 40C4) */
	__IO uint32_t MISO1_LOC;              /*!< Offset: 0x0C8 IOCON MISO1 location register (IOCON_MISO1_LOC, address 0x4004 40C8) */
	__IO uint32_t MOSI1_LOC;              /*!< Offset: 0x0CC IOCON MOSI1 location register (IOCON_MOSI1_LOC, address 0x4004 40CC) */
	__IO uint32_t CT32B0_CAP0_LOC;        /*!< Offset: 0x0D0 IOCON CT32B0_CAP0 location register (IOCON_CT32B0_CAP0_LOC, address 0x4004 40D0) */
	__IO uint32_t RXD_LOC;                /*!< Offset: 0x0D4 IOCON RXD location register (IOCON_RXD_LOC, address 0x4004 40D4) */
} LPC_IOCON_TypeDef_My;

typedef struct { // TMR
  union { // IR
	  __IO uint32_t WORD;                     /*!< Offset: 0x000 Interrupt Register (R/W) */
	  struct {
		  __IO uint32_t MR0INT_EN:1;
		  __IO uint32_t MR1INT_EN:1;
		  __IO uint32_t MR2INT_EN:1;
		  __IO uint32_t MR3INT_EN:1;
		  __IO uint32_t CR0INT_EN:1;
	  } BIT;
  } IR;
  union { // TCR
	  __IO uint32_t WORD;                    /*!< Offset: 0x004 Timer Control Register (R/W) */
	  struct {
		  __IO uint32_t CNT_EN:1;
		  __IO uint32_t CNT_RES:1;
	  } BIT;
  } TCR;
  __IO uint32_t TC;                     /*!< Offset: 0x008 Timer Counter Register (R/W) */
  __IO uint32_t PR;                     /*!< Offset: 0x00C Prescale Register (R/W) */
  __IO uint32_t PC;                     /*!< Offset: 0x010 Prescale Counter Register (R/W) */
  union { // MCR
	  __IO uint32_t WORD;                    /*!< Offset: 0x014 Match Control Register (R/W) */
	  struct {
		  __IO uint32_t MR0I:1;
		  __IO uint32_t MR0R:1;
		  __IO uint32_t MR0S:1;
		  __IO uint32_t MR1I:1;
		  __IO uint32_t MR1R:1;
		  __IO uint32_t MR1S:1;
		  __IO uint32_t MR2I:1;
		  __IO uint32_t MR2R:1;
		  __IO uint32_t MR2S:1;
		  __IO uint32_t MR3I:1;
		  __IO uint32_t MR3R:1;
		  __IO uint32_t MR3S:1;
	  } BIT;
  } MCR;
  __IO uint32_t MR0;                    /*!< Offset: 0x018 Match Register 0 (R/W) */
  __IO uint32_t MR1;                    /*!< Offset: 0x01C Match Register 1 (R/W) */
  __IO uint32_t MR2;                    /*!< Offset: 0x020 Match Register 2 (R/W) */
  __IO uint32_t MR3;                    /*!< Offset: 0x024 Match Register 3 (R/W) */
  __IO uint32_t CCR;                    /*!< Offset: 0x028 Capture Control Register (R/W) */
  __I  uint32_t CR0;                    /*!< Offset: 0x02C Capture Register 0 (R/ ) */
  __I  uint32_t CR1;                    /*!< Offset: 0x030 Capture Register 1 (R/ ) */
       uint32_t RESERVED1[2];
  __IO uint32_t EMR;                    /*!< Offset: 0x03C External Match Register (R/W) */
       uint32_t RESERVED2[12];
  __IO uint32_t CTCR;                   /*!< Offset: 0x070 Count Control Register (R/W) */
  union { // PWMC
	  __IO uint32_t WORD;                   /*!< Offset: 0x074 PWM Control Register (R/W) */
	  struct {
		  __IO uint32_t EN_MAT0:1;
		  __IO uint32_t EN_MAT1:1;
		  __IO uint32_t EN_MAT2:1;
		  __IO uint32_t EN_MAT3:1;
	  } BIT;
  } PWMC;
} LPC_TMR_TypeDef_My;

typedef struct { // I2C
	union { // CONSET
		__IO uint32_t WORD;                 /*!< Offset: 0x000 I2C Control Set Register (R/W) */
		struct {
			uint32_t RESERVED:2;
			__IO uint32_t AA:2;
			__IO uint32_t SI:1;
			__IO uint32_t STO:1;
			__IO uint32_t STA:1;
			__IO uint32_t I2EN:1;
		} BIT;
	} CONSET;
	__I  uint32_t STAT;                   /*!< Offset: 0x004 I2C Status Register (R/ ) */
	__IO uint32_t DAT;                    /*!< Offset: 0x008 I2C Data Register (R/W) */
	__IO uint32_t ADR0;                   /*!< Offset: 0x00C I2C Slave Address Register 0 (R/W) */
	union { // SCLH
		__IO uint32_t WORD;                   /*!< Offset: 0x010 SCH Duty Cycle Register High Half Word (R/W) */
		struct {
			__IO uint32_t SCLH:15;
		} BIT;
	} SCLH;
	union { // SCLL
		__IO uint32_t WORD;                   /*!< Offset: 0x014 SCL Duty Cycle Register Low Half Word (R/W) */
		struct {
			__IO uint32_t SCLH:15;
		} BIT;;
	} SCLL;
	union { // CONCLR
		__O  uint32_t WORD;                 /*!< Offset: 0x018 I2C Control Clear Register ( /W) */
		struct {
			uint32_t RESERVED1:2;
			__IO uint32_t AAC:1;
			__IO uint32_t SIC:1;
			uint32_t RESERVED2:1;
			__IO uint32_t STAC:1;
			__IO uint32_t I2ENC;
		} BIT;
	} CONCLR;
	__IO uint32_t MMCTRL;                 /*!< Offset: 0x01C Monitor mode control register (R/W) */
	__IO uint32_t ADR1;                   /*!< Offset: 0x020 I2C Slave Address Register 1 (R/W) */
	__IO uint32_t ADR2;                   /*!< Offset: 0x024 I2C Slave Address Register 2 (R/W) */
	__IO uint32_t ADR3;                   /*!< Offset: 0x028 I2C Slave Address Register 3 (R/W) */
	__I  uint32_t DATA_BUFFER;            /*!< Offset: 0x02C Data buffer register ( /W) */
	__IO uint32_t MASK0;                  /*!< Offset: 0x030 I2C Slave address mask register 0 (R/W) */
	__IO uint32_t MASK1;                  /*!< Offset: 0x034 I2C Slave address mask register 1 (R/W) */
	__IO uint32_t MASK2;                  /*!< Offset: 0x038 I2C Slave address mask register 2 (R/W) */
	__IO uint32_t MASK3;                  /*!< Offset: 0x03C I2C Slave address mask register 3 (R/W) */
} LPC_I2C_TypeDef_My;


LPC_GPIO_My *const GPIO[4] = {
	(LPC_GPIO_My *)LPC_GPIO0,
	(LPC_GPIO_My *)LPC_GPIO1,
	(LPC_GPIO_My *)LPC_GPIO2,
	(LPC_GPIO_My *)LPC_GPIO3
};

#define IOCON (*(LPC_IOCON_TypeDef_My *)LPC_IOCON)
#define GPIO0 (*(LPC_GPIO_My *)LPC_GPIO0)
#define GPIO1 (*(LPC_GPIO_My *)LPC_GPIO1)
#define GPIO2 (*(LPC_GPIO_My *)LPC_GPIO2)
#define GPIO3 (*(LPC_GPIO_My *)LPC_GPIO3)
#define Systick (*(SysTick_Type_My *)SysTick)
#define SYSCON (*(LPC_SYSCON_TypeDef_My *)LPC_SYSCON)
#define TMR32B1 (*(LPC_TMR_TypeDef_My *)LPC_TMR32B1)
#define INTVEC (*(NVIC_Type_My *)NVIC_BASE)
#endif /* MYSTRUCT_H_ */
