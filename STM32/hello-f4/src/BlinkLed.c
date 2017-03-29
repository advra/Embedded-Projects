//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

#include "BlinkLed.h"

// ----------------------------------------------------------------------------

void
blink_led_init()
{

  // Enable GPIO Peripheral clock
  RCC->AHB1ENR |= 1 << 3;			//port D
  GPIOD->BSRR |= 1 << (12 +16);		//resets pin 14 (offset by 16bits)


  GPIO_InitTypeDef GPIO_GreenLED;

  GPIO_GreenLED.Pin = (1 << 12);		//pin 12
  GPIO_GreenLED.Mode = 0x01;			//GPIO_MODE_OUTPUT_PP
  GPIO_GreenLED.Speed = 0x02; 			//GPIO_SPEED_FAST
  GPIO_GreenLED.Pull = 0x01;			//GPIO_PULLUP
  HAL_GPIO_Init(BLINK_GPIOx(3), &GPIO_GreenLED);


  // Start with led turned off
  //blink_led_off();
}

// ----------------------------------------------------------------------------
