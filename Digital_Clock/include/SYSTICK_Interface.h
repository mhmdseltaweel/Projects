/*
 * SYSTICK_Interface.h
 *
 *  Created on: May 31, 2023
 *      Author: Mohamed Said
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_
#include "STD_TYPES.h"


#define SYSTICK_CLOCK_AHB		0U
#define SYSTICK_CLOCK_AHB_8		1U






void MSYSTICK_VoidInit(void);
void MSYSTICK_VoidStopTimer(void);
void MSYSTICK_VoidSetBusyDelay(u32 Copy_U32LoadValue);
void MSYSTICK_VoidSetIntervalSingle(u32 Copy_U32LoadValue);
void MSYSTICK_VoidSetIntervalPerodic(u32 Copy_U32LoadValue);
u32  MSYSTICK_U32GetElabsedTimer(void);
u32  MSYSTICK_U32GetRemainingTime(void);
void MSYSTICK_VoidSetCallBack(void (*ptr)(void));



#endif /* SYSTICK_INTERFACE_H_ */
