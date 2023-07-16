/*
 * EXTI_Program.c
 *
 *  Created on: May 31, 2023
 *      Author: Mohamed Said
 */
#include "BIT_MATH.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
static void (*ptf0)(void);
static void (*ptf1)(void);
static void (*ptf2)(void);
static void (*ptf3)(void);
static void (*ptf4)(void);
static void (*ptf9_5)(void);
static void (*ptf15_10)(void);




void MEXTI_VoidEnableInterrupt(MEXTI_LINE Copy_MEXTI_LINE)
{
	SET_BIT(EXTI_IMR,Copy_MEXTI_LINE);
}
void MEXTI_VoidDisableInterrupt(MEXTI_LINE Copy_MEXTI_LINE)
{
	CLR_BIT(EXTI_IMR,Copy_MEXTI_LINE);
}
void MEXTI_VoidSetTriggeringMode(MEXTI_LINE Copy_MEXTI_LINE,TRIGGERING_MODE Copy_TRIGGERING_MODE)
{
	switch(Copy_TRIGGERING_MODE)
	{
	case MEXTI_RISING:		SET_BIT(EXTI_RTSR,Copy_MEXTI_LINE); break;
	case MEXTI_FALLING:		SET_BIT(EXTI_FTSR,Copy_MEXTI_LINE); break;
	case MEXTI_ANY_CHANGE:	SET_BIT(EXTI_RTSR,Copy_MEXTI_LINE);
							SET_BIT(EXTI_FTSR,Copy_MEXTI_LINE); break;
	}
}
void MEXTI_VoidSetEXTIConfig(MEXTI_LINE Copy_MEXTI_LINE,MEXTI_GPIO Copy_MEXTI_GPIO)
{
	switch(Copy_MEXTI_LINE)
	{
	case MEXTI_LINE0:	SYSCFG_EXTICR1|=(u32)(Copy_MEXTI_GPIO<<EXTI_VALUE_0);	break;
	case MEXTI_LINE1:	SYSCFG_EXTICR1|=(u32)(Copy_MEXTI_GPIO<<EXTI_VALUE_4); 	break;
	case MEXTI_LINE2: 	SYSCFG_EXTICR1|=(u32)(Copy_MEXTI_GPIO<<EXTI_VALUE_8); 	break;
	case MEXTI_LINE3: 	SYSCFG_EXTICR1|=(u32)(Copy_MEXTI_GPIO<<EXTI_VALUE_12); break;
	case MEXTI_LINE4:	SYSCFG_EXTICR2|=(u32)(Copy_MEXTI_GPIO<<EXTI_VALUE_0); 	break;
	case MEXTI_LINE5:	SYSCFG_EXTICR2|=(u32)(Copy_MEXTI_GPIO<<EXTI_VALUE_4); 	break;
	case MEXTI_LINE6: 	SYSCFG_EXTICR2|=(u32)(Copy_MEXTI_GPIO<<EXTI_VALUE_8); 	break;
	case MEXTI_LINE7: 	SYSCFG_EXTICR2|=(u32)(Copy_MEXTI_GPIO<<EXTI_VALUE_12); break;
	case MEXTI_LINE8:	SYSCFG_EXTICR3|=(u32)(Copy_MEXTI_GPIO<<EXTI_VALUE_0);	break;
	case MEXTI_LINE9:	SYSCFG_EXTICR3|=(u32)(Copy_MEXTI_GPIO<<EXTI_VALUE_4); 	break;
	case MEXTI_LINE10: 	SYSCFG_EXTICR3|=(u32)(Copy_MEXTI_GPIO<<EXTI_VALUE_8); 	break;
	case MEXTI_LINE11: 	SYSCFG_EXTICR3|=(u32)(Copy_MEXTI_GPIO<<EXTI_VALUE_12); break;
	case MEXTI_LINE12:	SYSCFG_EXTICR4|=(u32)(Copy_MEXTI_GPIO<<EXTI_VALUE_0); 	break;
	case MEXTI_LINE13:	SYSCFG_EXTICR4|=(u32)(Copy_MEXTI_GPIO<<EXTI_VALUE_4); 	break;
	case MEXTI_LINE14: 	SYSCFG_EXTICR4|=(u32)(Copy_MEXTI_GPIO<<EXTI_VALUE_8); 	break;
	case MEXTI_LINE15: 	SYSCFG_EXTICR4|=(u32)(Copy_MEXTI_GPIO<<EXTI_VALUE_12); break;
	}
}

void MEXTI_ClearEXTIFlag(MEXTI_LINE Copy_MEXTI_LINE)
{
	SET_BIT(EXTI_PR,Copy_MEXTI_LINE);
}

void MEXTI0_VoidSetCallBack (void(*ptr)(void))
{
	ptf0=ptr;
}
void MEXTI1_VoidSetCallBack (void(*ptr)(void))
{
	ptf1=ptr;
}
void MEXTI2_VoidSetCallBack (void(*ptr)(void))
{
	ptf2=ptr;
}
void MEXTI3_VoidSetCallBack (void(*ptr)(void))
{
	ptf3=ptr;
}
void MEXTI4_VoidSetCallBack (void(*ptr)(void))
{
	ptf4=ptr;
}
void MEXTI9_5_VoidSetCallBack (void(*ptr)(void))
{
	ptf9_5=ptr;
}
void MEXTI15_10_VoidSetCallBack (void(*ptr)(void))
{
	ptf15_10=ptr;
}


void EXTI0_IRQHandler(void)
{
	ptf0();
}
void EXTI1_IRQHandler(void)
{
	ptf1();
}
void EXTI2_IRQHandler(void)
{
	ptf2();
}
void EXTI3_IRQHandler(void)
{
	ptf3();
}
void EXTI4_IRQHandler(void)
{
	ptf4();
}
void EXTI9_5_IRQHandler(void)
{
	ptf9_5();
}
void EXTI15_10_IRQHandler(void)
{
	ptf15_10();
}

