/*
 * File			: registers mapping related to stm32f103 device
 * Description	: This file contains register mapping for direct access from code.
 * Author		: Shrenik Shikhare.
 * Date			: 12th May 2013
 * Email ID		: engineershrenik@gmail.com
 */


#ifndef _STM32F103_H_
#define _STM32F103_H_
#endif
#ifdef _STM32F103_H_

//RCC configuration register map
#define RCC_CR 				(*((volatile unsigned long*)0x40021000))
#define RCC_CFGR 			(*((volatile unsigned long*)0x40021004))
#define RCC_APB2ENR 	(*((volatile unsigned long*)0x40021018))

//GPIO Register map
#define GPIOF_CRL			(*((volatile unsigned long*)0x40011C00))
#define GPIOF_CHR			(*((volatile unsigned long*)0x40011C04))
#define GPIOF_BSRR		(*((volatile unsigned long*)0x40011C10))

#define GPIOA_CRL			(*((volatile unsigned long*)0x40010800))
#define GPIOA_CHR			(*((volatile unsigned long*)0x40010804))
#define GPIOA_BSRR		(*((volatile unsigned long*)0x40010810))


//USART1

#define USART1_SR 			(*((volatile unsigned long*)0x40013800))
#define USART1_DR 		(*((volatile unsigned long*)0x40013804))
#define USART1_BRR 		(*((volatile unsigned long*)0x40013808))
#define USART1_CR1		(*((volatile unsigned long*)0x4001380C))
#define USART1_CR2		(*((volatile unsigned long*)0x40013810))
#define USART1_CR3		(*((volatile unsigned long*)0x40013814))
#define USART1_GTPR		(*((volatile unsigned long*)0x40013818))

//USART 2 register map
#define USART2_SR 			(*((volatile unsigned long*)0x40004400))
#define USART2_DR 		(*((volatile unsigned long*)0x40004404))
#define USART2_BRR 		(*((volatile unsigned long*)0x40004408))
#define USART2_CR1		(*((volatile unsigned long*)0x4000440C))
#define USART2_CR2		(*((volatile unsigned long*)0x40004410))
#define USART2_CR3		(*((volatile unsigned long*)0x40004414))
#define USART2_GTPR		(*((volatile unsigned long*)0x40004418))



#define AFIO_MAPR			(*((volatile unsigned long*)0x40010004))


//typedefs
typedef signed char 				int8_t;
typedef unsigned char 			uint8_t;
typedef signed int 					int16_t;
typedef unsigned int 				uint16_t;
typedef signed long int 			int32_t;
typedef unsigned long int 		uint32_t;
typedef signed long long int 	int64_t;
typedef unsigned long long int 	uint64_t;

#endif //_STM32F103_H_

