/*
 * SYSTICK_Private.h
 *
 *  Created on: May 31, 2023
 *      Author: Mohamed Said
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#define SYSTICK_BASE_ADDRESS	0xE000E010

#define SYSTICK_SINGLE_INT		0U
#define SYSTICK_PERODIC_INT		1U

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}SYSTICK_t;


#define MSYSTICK_REG				((volatile SYSTICK_t*)SYSTICK_BASE_ADDRESS)





#endif /* SYSTICK_PRIVATE_H_ */
