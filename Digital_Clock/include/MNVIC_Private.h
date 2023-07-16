/*
 * MNVIC_Private.h
 *
 *  Created on: May 30, 2023
 *      Author: Mohamed Said
 */

#ifndef MNVIC_PRIVATE_H_
#define MNVIC_PRIVATE_H_
/**/
#define MNVIC_BASE_ADDRESS	0xE000E100

#define INSTRUCTION_LENGTH				32U
#define MNVIC_VALUE_ZERO				0U
#define MNVIC_VALUE_ONE					1U
#define MNVIC_VALUE_TWO					2U
#define MNVIC_VALUE_THREE				3U
#define MNVIC_VALUE_FOUR				4U
#define MNVIC_VALUE_EIGHT				8U



typedef struct
{
	u32 ISER[8];
	u32 RESERVED_0[24];
	u32	ICER[8];
	u32 RESERVED_4[24];
	u32 ISPR[8];
	u32 RESERVED_1[24];
	u32 ICPR[8];
	u32 RESERVED_5[24];
	u32 IABR[8];
	u32 RESERVED_2[56];
	u8  IPR[240];
	u32 RESERVED_3[580];
	u32 STIR;
}MNVIC_t;

#define MNVIC_REG	((volatile MNVIC_t*)MNVIC_BASE_ADDRESS)


#define MSCB_AIRCR		*((volatile u32*)0xE000ED0C)
#define MNVIC_VECTKEY	0x05FA0000

#endif /* MNVIC_PRIVATE_H_ */
