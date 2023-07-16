/*
 * MNVIC_Interface.h
 *
 *  Created on: May 30, 2023
 *      Author: Mohamed Said
 */

#ifndef MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_


typedef enum
{
	NVIC_G16_S0=3,
	NVIC_G8_S2,
	NVIC_G4_S4,
	NVIC_G2_S8,
	NVIC_G0_S16
}NVIC_GROUP_MODE;




#define MNVIC_WWDG					0U
#define MNVIC_PVD					1U
#define MNVIC_TAMP_STAMP			2U
#define MNVIC_RTC_WKUP				3U
#define MNVIC_FLASH					4U
#define MNVIC_RCC					5U
#define MNVIC_EXTI0					6U
#define MNVIC_EXTI1					7U
#define MNVIC_EXTI2					8U
#define MNVIC_EXTI3					9U
#define MNVIC_EXTI4					10U
#define MNVIC_DMA1_STREAM0			11U
#define MNVIC_DMA1_STREAM1			12U
#define MNVIC_DMA1_STREAM2			13U
#define MNVIC_DMA1_STREAM3			14U
#define MNVIC_DMA1_STREAM4			15U
#define MNVIC_DMA1_STREAM5			16U
#define MNVIC_DMA1_STREAM			17U
#define MNVIC_ADC					18U
#define MNVIC_EXTI9_5				23U
#define MNVIC_TIM1_BRK_TIM9			24U
#define MNVIC_TIM1_UP_TIM10			25U
#define MNVIC_TIM1_TRG_COM_TIM11	26U
#define MNVIC_TIM_CC				27U
#define MNVIC_TIM2					28U
#define MNVIC_TIM3					29U
#define MNVIC_TIM4					30U
#define MNVIC_I2C1_EV				31U
#define MNVIC_I2C1_ER				32U
#define MNVIC_I2C2_EV				33U
#define MNVIC_I2C2_ER				34U
#define MNVIC_SPI1					35U
#define MNVIC_SPI2					36U
#define MNVIC_USART1				37U
#define MNVIC_USART2				38U
#define MNVIC_EXTI15_10				40U
#define MNVIC_RTC_ALARM				41U
#define MNVIC_OTG_FS_WKUP			42U
#define MNVIC_DMA1_STREAM7			47U
#define MNVIC_SDIO					49U
#define MNVIC_TIM5					50U
#define MNVIC_SPI3					51U
#define MNVIC_DMA2_STREAM0			56U
#define MNVIC_DMA2_STREAM1			57U
#define MNVIC_DMA2_STREAM2			58U
#define MNVIC_DMA2_STREAM3			59U
#define MNVIC_DMA2_STREAM4			60U
#define MNVIC_OTG_FS 				67U
#define MNVIC_DMA2_STREAM5			68U
#define MNVIC_DMA2_STREAM6			69U
#define MNVIC_DMA2_STREAM7			70U
#define MNVIC_USART6				71U
#define MNVIC_I2C3_EV				72U
#define MNVIC_I2C3_ER				73U
#define MNVIC_FPU					81U
#define MNVIC_SPI4					84U


void MNVIC_VoidEnableInterrupt(u8 Copy_U8Pin);
void MNVIC_VoidDisableInterrupt(u8 Copy_U8Pin);
void MNVIC_VoidSetPending(u8 Copy_U8Pin);
void MNVIC_VoidClearPending(u8 Copy_U8Pin);
u8 	 MNVIC_VoidGetPending(u8 Copy_U8Pin);
void MNVIC_VoidSetGroupMode(NVIC_GROUP_MODE	Copy_NVIC_GROUP_MODE);
void MNVIC_VoidSetInterruptPriority(u8 Copy_u8IntPin ,NVIC_GROUP_MODE Copy_NVIC_Group_Mode,u8 Copy_U8GroupPriority,u8 Copy_U8SubGroupPriority);

#endif /* MNVIC_INTERFACE_H_ */
