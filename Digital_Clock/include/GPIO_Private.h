#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_



#define GPIOA_BASE_ADDRESS			0x40020000
#define GPIOB_BASE_ADDRESS			0x40020400
#define GPIOC_BASE_ADDRESS			0x40020800
/*
#define GPIOA_MODER					*((volatile u32*)0x00+GPIOA_BASE_ADDRESS)
#define GPIOA_OTYPER				*((volatile u32*)0x04+GPIOA_BASE_ADDRESS)
#define GPIOA_OSPEEDR				*((volatile u32*)0x08+GPIOA_BASE_ADDRESS)
#define GPIOA_PUPDR					*((volatile u32*)0x0c+GPIOA_BASE_ADDRESS)
#define GPIOA_IDR					*((volatile u32*)0x10+GPIOA_BASE_ADDRESS)
#define GPIOA_ODR					*((volatile u32*)0x14+GPIOA_BASE_ADDRESS)
#define GPIOA_BSSR					*((volatile u32*)0x18+GPIOA_BASE_ADDRESS)
#define GPIOA_LCKR					*((volatile u32*)0x1C+GPIOA_BASE_ADDRESS)
#define GPIOA_AFRL					*((volaitle u32*)0x20+GPIOA_BASE_ADDRESS)
#define GPIOA_AFRH					*((volatile u32*)0x24+GPIOA_BASE_ADDRESS)
*/
typedef struct {
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDR;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}GPIOx_t;

#define MGPIOA ((GPIOx_t*)GPIOA_BASE_ADDRESS)
#define MGPIOB ((GPIOx_t*)GPIOB_BASE_ADDRESS)
#define MGPIOC ((GPIOx_t*)GPIOC_BASE_ADDRESS)
//#define MGPIOA_LOW_8	*((volatile u8*)(GPIOA_BASE_ADDRESS+0x14))

#define MGPIO_VALUE_ONE				1U
#define MGPIO_VALUE_TWO				2U
#define MGPIO_VALUE_SIXTEEN			16U


#endif
