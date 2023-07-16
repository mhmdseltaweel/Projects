#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_
/*RCC Base address*/
#define RCC_base_address 		0x40023800
/*RCC CONTROL REGISTER*/
#define RCC_CR 				*((volatile u32*)(0x00+RCC_base_address))
/*RCC PLL Configuration Register*/
#define RCC_PLLCFGR 		*((volatile u32*)(0x04+RCC_base_address))
/*RCC Clock Configuration Register*/
#define RCC_CFGR			*((volatile u32*)(0x08+RCC_base_address))
/*RCC Clock Interrupt Register*/
#define RCC_CIR				*((volatile u32*)(0x0C+RCC_base_address))
/*RCC AHB1 Peripheral Reset Register*/
#define RCC_AHB1RSTR		*((volatile u32*)(0x10+RCC_base_address))
/*RCC AHB2 Peripheral Reset Register*/
#define RCC_AHB2RSTR		*((volatile u32*)(0x14+RCC_base_address))
/*RCC APB1 Peripheral Reset Register*/
#define RCC_APB1RSTR		*((volatile u32*)(0x20+RCC_base_address))
/*RCC APB2 Peripheral Reset Register*/
#define RCC_APB2RSTR		*((volatile u32*)(0x24+RCC_base_address))
/*RCC AHB1 Peripheral Clock Enable Register*/
#define RCC_AHB1ENR			*((volatile u32*)(0x30+RCC_base_address))
/*RCC AHB2 Peripheral Clock Enable Register*/
#define RCC_AHB2ENR			*((volatile u32*)(0x34+RCC_base_address))
/*RCC APB1 Peripheral Clock Enable Register*/
#define RCC_APB1ENR			*((volatile u32*)(0x40+RCC_base_address))
/*RCC APB2 Peripheral Clock Enable Register*/
#define RCC_APB2ENR			*((volatile u32*)(0x44+RCC_base_address))
/*RCC AHB1 Peripheral Clock Enabled in low power mode register*/
#define RCC_AHB1LPENR		*((volatile u32*)(0x50+RCC_base_address))
/*RCC AHB2 Peripheral Clock Enabled in low power mode register*/
#define RCC_AHB2LPENR		*((volatile u32*)(0x54+RCC_base_address))
/*RCC APB1 eripheral Clock Enabled in low power mode register*/
#define RCC_APB1LPENR		*((volatile u32*)(0x60+RCC_base_address))
/*RCC APB2 Peripheral Clock Enabled in low power mode register*/
#define RCC_APB2LPENR		*((volatile u32*)(0x64+RCC_base_address))
/*RCC Backup Domain Control Register*/
#define RCC_BDCR			*((volatile u32*)(0x70+RCC_base_address))
/*RCC Clock control & Status Register*/
#define RCC_CSR				*((volatile u32*)(0x74+RCC_base_address))
/*RCC Spread Spectrum Clock Generation Register*/
#define RCC_SSCGR			*((volatile u32*)(0x80+RCC_base_address))
/*RCC PLLI2S Configuration Register*/
#define RCC_PLLI2SCFGR		*((volatile u32*)(0x84+RCC_base_address))
/*RCC Dedicated Clocks Configuration Register*/
#define RCC_DCKCFGR			*((volatile u32*)(0x8C+RCC_base_address))


#define RCC_HSE_CRYSTAL 	0
#define RCC_HSE_RC 			1
#define RCC_HSI				2
#define RCC_PLL				3


#define PLL_SRC_HSE			0U
#define PLL_SRC_HSI			1U

#define RCC_CR_HSE_ON		16U
#define RCC_CR_HSE_BYP		18U
#define RCC_CR_HSI_ON		0U
#define RCC_CR_PLL_ON		24U

#define RCC_CFGR_SW0		0U
#define RCC_CFGR_SW1		1U

#define RCC_PLLP0			16U
#define RCC_PLLP1			17U
#define RCC_PLLSRC			22U

#define RCC_VALUE_ZERO		0U
#define RCC_VALUE_ONE		1U
#define RCC_VALUE_TWO		2U
#define RCC_VALUE_FOUR		4U
#define RCC_VALUE_SIX		6U
#define RCC_VALUE_EIGHT		8U
#define RCC_VALUE_63		63U
#define RCC_VALUE_433		433U
#define RCC_VALUE_511		511U







#endif
