/*
 * _HAL_GPIO.h
 *
 *  Created on: Mar 29, 2017
 *      Author: Admin
 */

#ifndef _HAL_GPIO
#define _HAL_GPIO

#include "stm32f4xx_hal_conf.h"

//GPIO Ports
#define PortA				GPIOA
#define PortB				GPIOB
#define PortC				GPIOC
#define PortD				GPIOD

//GPIO Ports
#define GPIOA_RCC_Enable	(RCC->AHB1ENR = (1<<0))
#define GPIOB_RCC_Enable	(RCC->AHB1ENR = (1<<1))
#define GPIOC_RCC_Enable	(RCC->AHB1ENR = (1<<2))
#define GPIOD_RCC_Enable	(RCC->AHB1ENR = (1<<3))

//Input Mode Types
#define Input				((uint32_t) 0x0)
#define Output 				((uint32_t) 0x1)
#define Alt_Func			((uint32_t) 0x2)
#define Analog		 		((uint32_t) 0x3)

//GPIO Output Types
#define	Output_Psh_Pl		((uint32_t) 0x0)
#define	Output_OD			((uint32_t) 0x1)

//GPIO Speed Types
#define Low_Spd 			((uint32_t) 0x0)
#define Med_Spd 			((uint32_t) 0x1)
#define High_Spd 			((uint32_t) 0x2)
#define VHigh_Spd 			((uint32_t) 0x2)

//Pullup/PullDown Types
#define No_PuPd 			((uint32_t) 0x0)
#define Pull_Up 			((uint32_t) 0x1)
#define Pull_Down 			((uint32_t) 0x2)

//GPIO Alt Functions
#define AF0 				((uint32_t) 0x0)
#define AF1 				((uint32_t) 0x1)
#define AF2 				((uint32_t) 0x2)
#define AF3 				((uint32_t) 0x3)
#define AF4 				((uint32_t) 0x4)
#define AF5 				((uint32_t) 0x5)
#define AF6 				((uint32_t) 0x6)
#define AF7 				((uint32_t) 0x7)
#define AF8 				((uint32_t) 0x8)
#define AF9 				((uint32_t) 0x9)
#define AF10 				((uint32_t) 0x10)
#define AF11 				((uint32_t) 0x11)
#define AF12				((uint32_t) 0x12)
#define AF13 				((uint32_t) 0x13)
#define AF14 				((uint32_t) 0x14)
#define AF15 				((uint32_t) 0x15)

//LED On or Off
#define LED_On(_N)			(GPIOD->BSRR = 1<<(_N))
#define LED_Off(_N)			(GPIOD->BSRR = 1<<(_N+16))

//BSRR High
#define GPIOA_Set_High_Pin(_N)		(GPIOA->BSRR = 1<<(_N))
#define GPIOB_Set_High_Pin(_N)		(GPIOB->BSRR = 1<<(_N))
#define GPIOC_Set_High_Pin(_N)		(GPIOC->BSRR = 1<<(_N))
#define GPIOD_Set_High_Pin(_N)		(GPIOD->BSRR = 1<<(_N))

//BSRR Low (Clear)
#define GPIOA_Reset_Pin(_N)		(GPIOA->BSRR = 1<<(_N+16))
#define GPIOB_Reset_Pin(_N)		(GPIOB->BSRR = 1<<(_N+16))
#define GPIOC_Reset_Pin(_N)		(GPIOC->BSRR = 1<<(_N+16))
#define GPIOD_Reset_Pin(_N)		(GPIOD->BSRR = 1<<(_N+16))

#endif /* USER_LIBRARIES__STM32F4XX_HAL_H_ */
