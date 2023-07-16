#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_Private.h"
#include "RCC_CNFG.h"
#include "RCC_Interface.h"


void RCC_VoidInit(void)
{
	#if RCC_CLOCK_TYPE==RCC_HSE_CRYSTAL
	SET_BIT(RCC_CR,RCC_CR_HSE_ON);
	CLR_BIT(RCC_CR,RCC_CR_HSE_BYP);
	
	SET_BIT(RCC_CFGR,RCC_CFGR_SW0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_SW1);

	#elif RCC_CLOCK_TYPE==RCC_HSE_RC
	SET_BIT(RCC_CR,RCC_CR_HSE_ON);
	SET_BIT(RCC_CR,RCC_CR_HSE_BYP);
	
	SET_BIT(RCC_CFGR,RCC_CFGR_SW0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_SW1);
	#elif RCC_CLOCK_TYPE==RCC_HSI
	SET_BIT(RCC_CR,RCC_CR_HSI_ON);
	
	CLR_BIT(RCC_CFGR,RCC_CFGR_SW0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_SW1);
	#elif RCC_CLOCK_TYPE==RCC_PLL
	SET_BIT(RCC_CR,RCC_CR_PLL_ON);
	
	
	CLR_BIT(RCC_CFGR,RCC_CFGR_SW0);
	SET_BIT(RCC_CFGR,RCC_CFGR_SW1);
	
	#else
		#error("wrong configuration for system clock")
	#endif
}

void RCC_VoidEnableClock(u8 Copy_U8BusID,u8 Copy_U8PeripheralID)
{
	switch(Copy_U8BusID)
	{
		case AHB1: SET_BIT(RCC_AHB1ENR,Copy_U8PeripheralID);  break;
		case AHB2: SET_BIT(RCC_AHB2ENR,Copy_U8PeripheralID);  break;
		case APB1: SET_BIT(RCC_APB1ENR,Copy_U8PeripheralID);  break;
		case APB2: SET_BIT(RCC_APB2ENR,Copy_U8PeripheralID);  break;
	}
}


void RCC_VoidDisableClock(u8 Copy_U8BusID,u8 Copy_U8PeripheralID)
{
	switch(Copy_U8BusID)
	{
		case AHB1: CLR_BIT(RCC_AHB1ENR,Copy_U8PeripheralID);  break;
		case AHB2: CLR_BIT(RCC_AHB2ENR,Copy_U8PeripheralID);  break;
		case APB1: CLR_BIT(RCC_APB1ENR,Copy_U8PeripheralID);  break;
		case APB2: CLR_BIT(RCC_APB2ENR,Copy_U8PeripheralID);  break;
	}
}

void RCC_VoidSetPLLConfigurations(void)
{
	#if RCC_PLL_CLOCK_SOURCE == PLL_SRC_HSE
		SET_BIT(RCC_PLLCFGR,RCC_PLLSRC);
	#elif RCC_PLL_CLOCK_SOURCE == PLL_SRC_HSI
		CLR_BIT(RCC_PLLCFGR,RCC_PLLSRC);
	#else 
		#error("Wrong PLL SOURCE")
	#endif
	#if RCC_PLLM == RCC_VALUE_ZERO || RCC_PLLM == RCC_VALUE_ONE	|| RCC_PLLM > RCC_VALUE_63
		#error("Wrong PLLM")
	#else	
		RCC_PLLCFGR|=(u32)(RCC_PLLM);
	#endif
	
	#if RCC_PLLN == RCC_VALUE_ZERO || RCC_PLLN == RCC_VALUE_ONE || RCC_PLLN ==RCC_VALUE_433 || RCC >=RCC_VALUE_511
		#error("Wrong PLLN")
	#else 
		RCC_PLLCFGR|= (u32)(RCC_PLLN<<RCC_VALUE_SIX);
	#endif
	
	#if 	RCC_PLLP == RCC_VALUE_TWO
		CLR_BIT(RCC_PLLCFGR,RCC_PLLP0);
		CLR_BIT(RCC_PLLCFGR,RCC_PLLP1);
	#elif	PLLP == RCC_VALUE_FOUR
		SET_BIT(RCC_PLLCFGR,RCC_PLLP0);
		CLR_BIT(RCC_PLLCFGR,RCC_PLLP1);
	#elif	PLLP == RCC_VALUE_SIX
		CLR_BIT(RCC_PLLCFGR,RCC_PLLP0);
		SET_BIT(RCC_PLLCFGR,RCC_PLLP1);
	#elif	PLLP == RCC_VALUE_EIGHT
		SET_BIT(RCC_PLLCFGR,RCC_PLLP0);
		SET_BIT(RCC_PLLCFGR,RCC_PLLP1);
	#else
		#error("Wrong PLLP")
	#endif
	
	
	
}

