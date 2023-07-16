#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_Private.h"
#include "GPIO_Interface.h"


#define MGPIOA_LOW_8	*((volatile u8*)&MGPIOA->ODR)


void MGPIO_VoidSetPinDirection(u8 Copy_U8PortID,u8 Copy_U8PinID,u8 Copy_U8Mode)
{

	switch(Copy_U8PortID)
	{
	case MGPIOA_PORT:	MGPIOA->MODER |=(u32) ((Copy_U8Mode)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	case MGPIOB_PORT:	MGPIOB->MODER |=(u32) ((Copy_U8Mode)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	case MGPIOC_PORT:	MGPIOC->MODER |=(u32) ((Copy_U8Mode)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	}

}


void MGPIO_VoidSetPinValue(u8 Copy_U8PortID,u8 Copy_U8PinID,u8 Copy_U8Value)
{
	if(Copy_U8Value==MGPIO_OUTPUT_HIGH)
	{
		switch(Copy_U8PortID)
		{
		case MGPIOA_PORT:	SET_BIT(MGPIOA->ODR,Copy_U8PinID); break;
		case MGPIOB_PORT:	SET_BIT(MGPIOB->ODR,Copy_U8PinID); break;
		case MGPIOC_PORT:	SET_BIT(MGPIOC->ODR,Copy_U8PinID); break;
		}	
	}
	else 
	{
		switch(Copy_U8PortID)
		{
		case MGPIOA_PORT:	CLR_BIT(MGPIOA->ODR,Copy_U8PinID); break;
		case MGPIOB_PORT:	CLR_BIT(MGPIOB->ODR,Copy_U8PinID); break;
		case MGPIOC_PORT:	CLR_BIT(MGPIOC->ODR,Copy_U8PinID); break;
		}
	}
}
void MGPIO_VoidSetOutputType(u8 Copy_U8PortID,u8 Copy_U8PinID,u8 Copy_U8Type)
{
	if(Copy_U8Type==MGPIO_TYPE_OPEN_DRAIN)
	{
		switch(Copy_U8PortID)
		{
		case MGPIOA_PORT:	SET_BIT(MGPIOA->OTYPER,Copy_U8PinID); break;
		case MGPIOB_PORT:	SET_BIT(MGPIOB->OTYPER,Copy_U8PinID); break;
		case MGPIOC_PORT:	SET_BIT(MGPIOC->OTYPER,Copy_U8PinID); break;
		}
	}
	else 
	{
		switch(Copy_U8PortID)
		{
		case MGPIOA_PORT:	CLR_BIT(MGPIOA->OTYPER,Copy_U8PinID); break;
		case MGPIOB_PORT:	CLR_BIT(MGPIOB->OTYPER,Copy_U8PinID); break;
		case MGPIOC_PORT:	CLR_BIT(MGPIOC->OTYPER,Copy_U8PinID); break;
		}
	}
}
void MGPIO_VoidSetPinSpeed(u8 Copy_U8PortID,u8 Copy_U8PinID,u8 Copy_U8Speed)
{
	switch(Copy_U8PortID)
	{
	case MGPIOA_PORT:	MGPIOA->OSPEEDR |= (u32) ((Copy_U8Speed)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	case MGPIOB_PORT:	MGPIOB->OSPEEDR |= (u32) ((Copy_U8Speed)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	case MGPIOC_PORT:	MGPIOC->OSPEEDR |= (u32) ((Copy_U8Speed)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	}	
}
void MGPIO_VoidSetPullState(u8 Copy_U8PortID,u8 Copy_U8PinID,u8 Copy_U8State)
{
	switch(Copy_U8PortID)
	{
	case MGPIOA_PORT:	MGPIOA->PUPDR |= (u32) ((Copy_U8State)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	case MGPIOB_PORT:	MGPIOB->PUPDR |= (u32) ((Copy_U8State)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	case MGPIOC_PORT:	MGPIOC->PUPDR |= (u32) ((Copy_U8State)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	}
}
u8 MGPIO_VoidGetPinValue(u8 Copy_U8PortID,u8 Copy_U8PinID)
{
	u8 result=0;
	switch(Copy_U8PortID)
	{
	case MGPIOA_PORT:	result = ((MGPIOA->IDR)>>Copy_U8PinID)&MGPIO_VALUE_ONE;	break;
	case MGPIOB_PORT:	result = ((MGPIOB->IDR)>>Copy_U8PinID)&MGPIO_VALUE_ONE;	break;
	case MGPIOC_PORT:	result = ((MGPIOC->IDR)>>Copy_U8PinID)&MGPIO_VALUE_ONE;	break;
	}
	return result;
}
void MGPIO_VoidDirectReset(u8 Copy_U8PortID,u8 Copy_U8PinID)
{
	switch(Copy_U8PortID)
	{
	case MGPIOA_PORT:	SET_BIT(MGPIOA->BSRR,Copy_U8PinID+MGPIO_VALUE_SIXTEEN); break;
	case MGPIOB_PORT:	SET_BIT(MGPIOB->BSRR,Copy_U8PinID+MGPIO_VALUE_SIXTEEN); break;
	case MGPIOC_PORT:	SET_BIT(MGPIOC->BSRR,Copy_U8PinID+MGPIO_VALUE_SIXTEEN); break;
	}
}
void MGPIO_VoidDirectSet(u8 Copy_U8PortID,u8 Copy_U8PinID)
{
	switch(Copy_U8PortID)
	{
	case MGPIOA_PORT:	SET_BIT(MGPIOA->BSRR,Copy_U8PinID); break;
	case MGPIOB_PORT:	SET_BIT(MGPIOB->BSRR,Copy_U8PinID); break;
	case MGPIOC_PORT:	SET_BIT(MGPIOC->BSRR,Copy_U8PinID); break;
	}	
}

void MGPIO_VoidTogglePin(u8 Copy_U8PortID,u8 Copy_U8PinID)
{
	switch(Copy_U8PortID)
	{
	case MGPIOA_PORT:	TOG_BIT(MGPIOA->ODR,Copy_U8PinID); break;
	case MGPIOB_PORT:	TOG_BIT(MGPIOB->ODR,Copy_U8PinID); break;
	case MGPIOC_PORT:	TOG_BIT(MGPIOC->ODR,Copy_U8PinID); break;
	}
}



void MGPIO_VoidSetPortValue(u8 Copy_U8PortID,u8 Copy_U8Value)
{
	MGPIOA_LOW_8=Copy_U8Value;
	/*
	MGPIO_VoidSetPinValue(MGPIOA,MGPIO_PIN0,(Copy_U8Value>>0)&0x01);
	MGPIO_VoidSetPinValue(MGPIOA,MGPIO_PIN1,(Copy_U8Value>>1)&0x01);
	MGPIO_VoidSetPinValue(MGPIOA,MGPIO_PIN2,(Copy_U8Value>>2)&0x01);
	MGPIO_VoidSetPinValue(MGPIOA,MGPIO_PIN3,(Copy_U8Value>>3)&0x01);
	MGPIO_VoidSetPinValue(MGPIOA,MGPIO_PIN4,(Copy_U8Value>>4)&0x01);
	MGPIO_VoidSetPinValue(MGPIOA,MGPIO_PIN5,(Copy_U8Value>>5)&0x01);
	MGPIO_VoidSetPinValue(MGPIOA,MGPIO_PIN6,(Copy_U8Value>>6)&0x01);
	MGPIO_VoidSetPinValue(MGPIOA,MGPIO_PIN7,(Copy_U8Value>>7)&0x01);
	*/
}



