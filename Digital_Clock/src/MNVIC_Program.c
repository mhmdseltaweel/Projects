/*
 * MNVIC_Program.c
 *
 *  Created on: May 30, 2023
 *      Author: Mohamed Said
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MNVIC_Interface.h"
#include "MNVIC_Private.h"
void MNVIC_VoidEnableInterrupt(u8 Copy_U8Pin)
{
	MNVIC_REG->ISER[Copy_U8Pin/INSTRUCTION_LENGTH]= (MNVIC_VALUE_ONE<<(Copy_U8Pin%INSTRUCTION_LENGTH));
}
void MNVIC_VoidDisableInterrupt(u8 Copy_U8Pin)
{
	MNVIC_REG->ICER[Copy_U8Pin/INSTRUCTION_LENGTH]= (MNVIC_VALUE_ONE<<(Copy_U8Pin%INSTRUCTION_LENGTH));
}
void MNVIC_VoidSetPending(u8 Copy_U8Pin)
{
	MNVIC_REG->ISPR[Copy_U8Pin/INSTRUCTION_LENGTH]= (MNVIC_VALUE_ONE<<(Copy_U8Pin%INSTRUCTION_LENGTH));
}

void MNVIC_VoidClearPending(u8 Copy_U8Pin)
{
	MNVIC_REG->ICPR[Copy_U8Pin/INSTRUCTION_LENGTH]= (MNVIC_VALUE_ONE<<(Copy_U8Pin%INSTRUCTION_LENGTH));
}
u8 	 MNVIC_VoidGetPending(u8 Copy_U8Pin)
{
	return GET_BIT(MNVIC_REG->ISPR[Copy_U8Pin/INSTRUCTION_LENGTH],(Copy_U8Pin%INSTRUCTION_LENGTH));
}
void MNVIC_VoidSetGroupMode(NVIC_GROUP_MODE	Copy_NVIC_GROUP_MODE)
{
	MSCB_AIRCR=MNVIC_VECTKEY;
	MSCB_AIRCR= MNVIC_VECTKEY | (u32)(Copy_NVIC_GROUP_MODE<<MNVIC_VALUE_EIGHT);
}
void MNVIC_VoidSetInterruptPriority(u8 Copy_u8IntPin ,NVIC_GROUP_MODE Copy_NVIC_Group_Mode,u8 Copy_U8GroupPriority,u8 Copy_U8SubGroupPriority)
{
	u8 LocalPriority;
	switch(Copy_NVIC_Group_Mode)
	{
	case NVIC_G16_S0:	LocalPriority=Copy_U8GroupPriority;														break;
	case NVIC_G8_S2:	LocalPriority=((Copy_U8GroupPriority<<MNVIC_VALUE_ONE) | Copy_U8SubGroupPriority); 		break;
	case NVIC_G4_S4:	LocalPriority=((Copy_U8GroupPriority<<MNVIC_VALUE_TWO) | Copy_U8SubGroupPriority); 		break;
	case NVIC_G2_S8:	LocalPriority=((Copy_U8GroupPriority<<MNVIC_VALUE_THREE) | Copy_U8SubGroupPriority); 	break;
	case NVIC_G0_S16:	LocalPriority=Copy_U8SubGroupPriority;													break;
	}

	MNVIC_REG->IPR[Copy_u8IntPin]=LocalPriority<<MNVIC_VALUE_FOUR;

}





