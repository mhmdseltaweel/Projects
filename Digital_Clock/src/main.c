/*
 * main.c
 *
 *  Created on: Jun 9, 2023
 *      Author: Mohamed Said
 */
#include "STD_TYPES.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"
#include "NUMBERS.h"
#include "MNVIC_Interface.h"
#include "EXTI_Interface.h"
u8 num[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
void out_number(u8 Copy_U8Number);
void display_func(void);
void Start_Stop_the_Clock(void);
void decrement(void);
void increment(void);
void SetCursor(void);
u8 seconds;
u8 minutes;
u8 hours;
u8 volatile HoldFlag;
u8 Cursor_indication;
void main (void)
{
	RCC_VoidInit();
	RCC_VoidEnableClock(AHB1,RCC_AHB1_GPIOA);
	RCC_VoidEnableClock(AHB1,RCC_AHB1_GPIOB);
	RCC_VoidEnableClock(APB2,RCC_APB2_SYSCFG);

	MNVIC_VoidSetGroupMode(NVIC_G4_S4);
	MNVIC_VoidSetInterruptPriority(MNVIC_EXTI0,NVIC_G4_S4,3,0);
	MNVIC_VoidSetInterruptPriority(MNVIC_EXTI1,NVIC_G4_S4,2,0);
	MNVIC_VoidSetInterruptPriority(MNVIC_EXTI2,NVIC_G4_S4,1,0);
	MNVIC_VoidSetInterruptPriority(MNVIC_EXTI9_5,NVIC_G4_S4,0,0);


	MGPIO_VoidSetPinDirection(MGPIOB_PORT,MGPIO_PIN5,MGPIO_MODE_INPUT);
	MGPIO_VoidSetPullState(MGPIOB_PORT,MGPIO_PIN5,MGPIO_PULL_UP);
	MGPIO_VoidSetPinDirection(MGPIOB_PORT,MGPIO_PIN0,MGPIO_MODE_INPUT);
	MGPIO_VoidSetPullState(MGPIOB_PORT,MGPIO_PIN0,MGPIO_PULL_UP);
	MGPIO_VoidSetPinDirection(MGPIOB_PORT,MGPIO_PIN1,MGPIO_MODE_INPUT);
	MGPIO_VoidSetPullState(MGPIOB_PORT,MGPIO_PIN1,MGPIO_PULL_UP);
	MGPIO_VoidSetPinDirection(MGPIOB_PORT,MGPIO_PIN2,MGPIO_MODE_INPUT);
	MGPIO_VoidSetPullState(MGPIOB_PORT,MGPIO_PIN2,MGPIO_PULL_UP);
	MEXTI_VoidSetTriggeringMode(MEXTI_LINE0,MEXTI_FALLING);
	MEXTI_VoidSetTriggeringMode(MEXTI_LINE1,MEXTI_FALLING);
	MEXTI_VoidSetTriggeringMode(MEXTI_LINE2,MEXTI_FALLING);
	MEXTI_VoidSetTriggeringMode(MEXTI_LINE5,MEXTI_FALLING);
	MEXTI_VoidSetEXTIConfig(MEXTI_LINE0,MEXTI_GPIOB);
	MEXTI_VoidSetEXTIConfig(MEXTI_LINE1,MEXTI_GPIOB);
	MEXTI_VoidSetEXTIConfig(MEXTI_LINE2,MEXTI_GPIOB);
	MEXTI_VoidSetEXTIConfig(MEXTI_LINE5,MEXTI_GPIOB);
	MEXTI0_VoidSetCallBack(Start_Stop_the_Clock);
	MEXTI1_VoidSetCallBack(SetCursor);
	MEXTI2_VoidSetCallBack(increment);
	MEXTI9_5_VoidSetCallBack(decrement);
	MEXTI_VoidEnableInterrupt(MEXTI_LINE0);
	MEXTI_VoidEnableInterrupt(MEXTI_LINE1);
	MEXTI_VoidEnableInterrupt(MEXTI_LINE2);
	MEXTI_VoidEnableInterrupt(MEXTI_LINE5);


	/*set the direction configuration for port a and port b*/
	for (u8 i=0;i<8;i++)
	{
		MGPIO_VoidSetPinDirection(MGPIOA_PORT,i,MGPIO_MODE_OUTPUT);
		MGPIO_VoidSetPinSpeed(MGPIOA_PORT,i,MGPIO_OUTPUT_SPEED_lOW);
		MGPIO_VoidSetOutputType(MGPIOA_PORT,i,MGPIO_TYPE_PUSH_PULL);
	}
	for(u8 i=9;i<16;i++)
	{
		MGPIO_VoidSetPinDirection(MGPIOB_PORT,i,MGPIO_MODE_OUTPUT);
		MGPIO_VoidSetPinSpeed(MGPIOB_PORT,i,MGPIO_OUTPUT_SPEED_lOW);
		MGPIO_VoidSetOutputType(MGPIOB_PORT,i,MGPIO_TYPE_PUSH_PULL);
		MGPIO_VoidSetPinValue(MGPIOB_PORT,i,MGPIO_OUTPUT_HIGH);
	}
	MNVIC_VoidEnableInterrupt(MNVIC_EXTI0);
	MNVIC_VoidEnableInterrupt(MNVIC_EXTI1);
	MNVIC_VoidEnableInterrupt(MNVIC_EXTI2);
	MNVIC_VoidEnableInterrupt(MNVIC_EXTI9_5);
	while (1)
	{
		if(HoldFlag==0)
		{
			display_func();
			if(seconds<59)
			{
				seconds++;
			}
			else if(seconds == 59)
			{
				seconds=0;
				minutes++;
				if(minutes>=59)
				{
					hours++;
					minutes=0;
					if(hours>=23)
					{
						hours=0;
						minutes=0;
						seconds=0;
					}
				}
			}
		}
		else
		{
			display_func();
		}


	}
}

void out_number(u8 Copy_U8Number)
{
	MGPIO_VoidSetPortValue(MGPIOA_PORT,num[Copy_U8Number]);
/*
	MGPIO_VoidSetPinValue(MGPIOA_PORT,MGPIO_PIN0,(num[Copy_U8Number]>>0&0x01));
	MGPIO_VoidSetPinValue(MGPIOA_PORT,MGPIO_PIN1,(num[Copy_U8Number]>>1&0x01));
	MGPIO_VoidSetPinValue(MGPIOA_PORT,MGPIO_PIN2,(num[Copy_U8Number]>>2&0x01));
	MGPIO_VoidSetPinValue(MGPIOA_PORT,MGPIO_PIN3,(num[Copy_U8Number]>>3&0x01));
	MGPIO_VoidSetPinValue(MGPIOA_PORT,MGPIO_PIN4,(num[Copy_U8Number]>>4&0x01));
	MGPIO_VoidSetPinValue(MGPIOA_PORT,MGPIO_PIN5,(num[Copy_U8Number]>>5&0x01));
	MGPIO_VoidSetPinValue(MGPIOA_PORT,MGPIO_PIN6,(num[Copy_U8Number]>>6&0x01));
*/
}

void display_func()
{
	u8 first_num=seconds%10;
	u8 second_num=seconds/10;
	u8 third_num=minutes%10;
	u8 fourth_num=minutes/10;
	u8 fifth_num=hours%10;
	u8 sixth_num=hours/10;
	for (u8 iterator=0;iterator<50;iterator++)
	{
		/*enable for segment 1*/
		MGPIO_VoidSetPinValue(MGPIOB_PORT,MGPIO_PIN9,MGPIO_OUTPUT_LOW);
		out_number(first_num);
		MSYSTICK_VoidSetBusyDelay(6667);
		/*DISABLE SEGMENT 1*/
		MGPIO_VoidSetPinValue(MGPIOB_PORT,MGPIO_PIN9,MGPIO_OUTPUT_HIGH);
		/*ENABLE SEMGENT 2*/
		MGPIO_VoidSetPinValue(MGPIOB_PORT,MGPIO_PIN10,MGPIO_OUTPUT_LOW);
		out_number(second_num);
		MSYSTICK_VoidSetBusyDelay(6667);
		/*DISABLE SEGMENT 2*/
		MGPIO_VoidSetPinValue(MGPIOB_PORT,MGPIO_PIN10,MGPIO_OUTPUT_HIGH);
		/*enable segment 3*/
		MGPIO_VoidSetPinValue(MGPIOB_PORT,MGPIO_PIN12,MGPIO_OUTPUT_LOW);
		out_number(third_num);
		MSYSTICK_VoidSetBusyDelay(6667);
		/*disable segment 3*/
		MGPIO_VoidSetPinValue(MGPIOB_PORT,MGPIO_PIN12,MGPIO_OUTPUT_HIGH);
		/*enable segment 4*/
		MGPIO_VoidSetPinValue(MGPIOB_PORT,MGPIO_PIN13,MGPIO_OUTPUT_LOW);
		out_number(fourth_num);
		MSYSTICK_VoidSetBusyDelay(6667);
		/*disable segment 4*/
		MGPIO_VoidSetPinValue(MGPIOB_PORT,MGPIO_PIN13,MGPIO_OUTPUT_HIGH);
		/*enable segment 5*/
		MGPIO_VoidSetPinValue(MGPIOB_PORT,MGPIO_PIN14,MGPIO_OUTPUT_LOW);
		out_number(fifth_num);
		MSYSTICK_VoidSetBusyDelay(6667);
		/*disable segment 5*/
		MGPIO_VoidSetPinValue(MGPIOB_PORT,MGPIO_PIN14,MGPIO_OUTPUT_HIGH);
		/*enable segment 6*/
		MGPIO_VoidSetPinValue(MGPIOB_PORT,MGPIO_PIN15,MGPIO_OUTPUT_LOW);
		out_number(sixth_num);
		MSYSTICK_VoidSetBusyDelay(6667);
		/*disable segment 6*/
		MGPIO_VoidSetPinValue(MGPIOB_PORT,MGPIO_PIN15,MGPIO_OUTPUT_HIGH);
	}
}

void Start_Stop_the_Clock(void)
{
	if(HoldFlag==0)
	{
		HoldFlag=1;
	}
	else
	{
		HoldFlag=0;
		Cursor_indication=0;
	}
}
void SetCursor(void)
{
	if(HoldFlag==1)
	{
		Cursor_indication++;
		if(Cursor_indication>=6)
		{
			Cursor_indication=0;
		}
	}

}
void increment(void)
{
	if(HoldFlag==1)
	{
		switch(Cursor_indication)
		{
		case 0: seconds++;		if((seconds%10)==0) seconds-=10;		   	break;
		case 1: seconds+=10;	if(seconds>=60) seconds%=10;				break;
		case 2: minutes++; 		if((minutes%10)==0) minutes-=10; 			break;
		case 3: minutes+=10; 	if(minutes>=60)	minutes%=10; 				break;
		case 4: hours++; 		if((hours%10)==0) hours-=10;				break;
		case 5: hours+=10;		if(hours>=24)	hours%=10;					break;
		}
	}

}
void decrement(void)
{
	/*
	switch(Cursor_indication)
	{
	case 0: seconds--;		if((seconds%10)==9)	seconds+=10;			break;
	case 1: seconds-=10;	if((seconds/10)==0)	seconds+=50;			break;
	case 2: minutes--;		if((minutes%10)==9)	minutes+=10;			break;
	case 3: minutes-=10;	if((minutes/10)==0)	minutes+=50;			break;
	case 4: hours--;		if((hours%10)==9)	hours+=10;				break;
	case 5: hours-=10;		if((hours/10)==0&&(hours%10)>3)	hours+=10;
	if((hours/10)==0&&(hours%10)<4)	hours+=20;							break;
	}
	 */
	if(HoldFlag==1)
	{
		switch(Cursor_indication)
		{
		case 0:
		{
			if((seconds%10)==0)
			{
				seconds+=9;
			}
			else
			{
				seconds--;
			}
			break;
		}
		case 1:
		{
			if((seconds/10)==0)
			{
				seconds+=50;
			}
			else
			{
				seconds-=10;
			}
			break;
		}
		case 2:
		{
			if((minutes%10)==0)
			{
				minutes+=9;
			}
			else
			{
				minutes--;
			}
			break;
		}
		case 3:
		{
			if((minutes/10)==0)
			{
				minutes+=50;
			}
			else
			{
				minutes-=10;
			}
			break;
		}
		case 4:
		{
			if((hours%10)==0)
			{
				hours+=9;
			}
			else
			{
				hours--;
			}
			break;
		}
		case 5:
		{
			if((hours/10)==0)
			{
				if(hours>=4)
				{
					hours+=10;
				}
				else
				{
					hours+=20;
				}
			}
			else
			{
				hours-=10;
			}
		}
		}
	}

}
