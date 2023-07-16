/*
 * EXTI_Interface.h
 *
 *  Created on: May 31, 2023
 *      Author: Mohamed Said
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "STD_TYPES.h"

typedef enum
{
	MEXTI_LINE0,
	MEXTI_LINE1,
	MEXTI_LINE2,
	MEXTI_LINE3,
	MEXTI_LINE4,
	MEXTI_LINE5,
	MEXTI_LINE6,
	MEXTI_LINE7,
	MEXTI_LINE8,
	MEXTI_LINE9,
	MEXTI_LINE10,
	MEXTI_LINE11,
	MEXTI_LINE12,
	MEXTI_LINE13,
	MEXTI_LINE14,
	MEXTI_LINE15
}MEXTI_LINE;


typedef enum
{
	MEXTI_RISING,
	MEXTI_FALLING,
	MEXTI_ANY_CHANGE
}TRIGGERING_MODE;

typedef enum
{
	MEXTI_GPIOA,
	MEXTI_GPIOB,
	MEXTI_GPIOC
}MEXTI_GPIO;


void MEXTI_VoidEnableInterrupt(MEXTI_LINE Copy_MEXTI_LINE);
void MEXTI_VoidDisableInterrupt(MEXTI_LINE Copy_MEXTI_LINE);
void MEXTI_VoidSetTriggeringMode(MEXTI_LINE Copy_MEXTI_LINE,TRIGGERING_MODE Copy_TRIGGERING_MODE);
void MEXTI_VoidSetEXTIConfig(MEXTI_LINE Copy_MEXTI_LINE,MEXTI_GPIO Copy_MEXTI_GPIO);
void MEXTI_ClearEXTIFlag(MEXTI_LINE Copy_MEXTI_LINE);
void MEXTI0_VoidSetCallBack (void(*ptr)(void));
void MEXTI1_VoidSetCallBack (void(*ptr)(void));
void MEXTI2_VoidSetCallBack (void(*ptr)(void));
void MEXTI3_VoidSetCallBack (void(*ptr)(void));
void MEXTI4_VoidSetCallBack (void(*ptr)(void));
void MEXTI9_5_VoidSetCallBack (void(*ptr)(void));
void MEXTI15_10_VoidSetCallBack(void(*ptr)(void));



#endif /* EXTI_INTERFACE_H_ */
