#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define AHB1					0U
#define AHB2					1U
#define APB1					2U	
#define APB2					3U

#define RCC_AHB1_GPIOA			0U
#define RCC_AHB1_GPIOB			1U
#define RCC_AHB1_GPIOC			2U
#define RCC_AHB1_GPIOD			3U
#define RCC_AHB1_GPIOE			4U
#define RCC_AHB1_GPIOH			7U
#define RCC_AHB1_CRC			12U
#define RCC_AHB1_DMA1			21U
#define RCC_AHB1_DMA2			22U
#define RCC_AHB2_OTGFS			7U
#define RCC_APB1_TIM2			0U
#define RCC_APB1_TIM3			1U
#define RCC_APB1_TIM4			2U
#define RCC_APB1_TIM5			3U
#define RCC_APB1_WWDG			11U
#define RCC_APB1_SPI2			14U
#define RCC_APB1_SPI3			15U
#define RCC_APB1_USART2			17U
#define RCC_APB1_I2C1			21U
#define RCC_APB1_I2C2			22U
#define RCC_APB1_I2C3			23U
#define RCC_APB1_PWR			28U
#define RCC_APB2_TIM1			0U
#define RCC_APB2_USART1			4U
#define RCC_APB2_USART6			5U
#define RCC_APB2_ADC1			8U
#define RCC_APB2_SDIO			11U
#define RCC_APB2_SPI1			12U
#define RCC_APB2_SPI4			13U
#define RCC_APB2_SYSCFG			14U
#define RCC_APB2_TIM9			16U
#define RCC_APB2_TIM10			17U
#define RCC_APB2_TIM11			18U




void RCC_VoidInit(void);
void RCC_VoidEnableClock(u8 Copy_U8BusID,u8 Copy_U8PeripheralID);
void RCC_VoidDisableClock(u8 Copy_U8BusID,u8 Copy_U8PeripheralID);
void RCC_VoidSetPLLConfigurations(void);






#endif