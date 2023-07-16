/*
 * EXTI_Private.h
 *
 *  Created on: May 31, 2023
 *      Author: Mohamed Said
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define EXTI_BASE_ADDRESS		0x40013C00
#define SYSCNFG_BASE_ADDRESS	0x40013800


#define EXTI_VALUE_0			0U
#define EXTI_VALUE_4			4U
#define EXTI_VALUE_8			8U
#define EXTI_VALUE_12			12U



#define EXTI_IMR				*((volatile u32*)(EXTI_BASE_ADDRESS+0x00))
#define EXTI_EMR				*((volatile u32*)(EXTI_BASE_ADDRESS+0x04))
#define EXTI_RTSR				*((volatile u32*)(EXTI_BASE_ADDRESS+0x08))
#define EXTI_FTSR				*((volatile u32*)(EXTI_BASE_ADDRESS+0x0c))
#define EXTI_SWIER				*((volatile u32*)(EXTI_BASE_ADDRESS+0x10))
#define EXTI_PR					*((volatile u32*)(EXTI_BASE_ADDRESS+0x14))
#define SYSCFG_EXTICR1			*((volatile u32*)(SYSCNFG_BASE_ADDRESS+0x08))
#define SYSCFG_EXTICR2			*((volatile u32*)(SYSCNFG_BASE_ADDRESS+0x0C))
#define SYSCFG_EXTICR3			*((volatile u32*)(SYSCNFG_BASE_ADDRESS+0x10))
#define SYSCFG_EXTICR4			*((volatile u32*)(SYSCNFG_BASE_ADDRESS+0x14))


#endif /* EXTI_PRIVATE_H_ */
