
// ----------------------------------------------------------------------------
//	Note:
//
//	This is a simple blinky code written fro STM32F Discovery board. Below is a
//	sample of	two LEDS Green & Red in PD12 & PD14 respectively. This barebones
//	is prior to making a user-made driver. (as practice)


// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "Timer.h"


// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

int
main(int argc, char* argv[])
{
	  // At this stage the system clock should have already been configured
	  // at high speed.


		//Enable Clock Registers for GPIO D
		RCC->AHB1ENR = (1<<3);

		GPIOD->BSRR = 1 << (12 +16);				//pin12 (offset by 16 to reset)

		//enable GREEN LED on D12
		GPIOD->MODER |= ( (0<<25) | (1<<24));		//Output
		GPIOD->OSPEEDR |= ( (1<<25) | (0<<24));		//HS
		GPIOD->OTYPER |= 0 <<12;					//output push-pull
		GPIOD->PUPDR |= ( (0<<25) | (1<<24) );		//pull up

		//enable RED LED on D14
		GPIOD->MODER |= ( (0<<29) | (1<<28));		//Output
		GPIOD->OSPEEDR |= ( (1<<29) | (0<<28));		//HS
		GPIOD->OTYPER |= 0 <<14;					//output push-pull
		GPIOD->PUPDR |= ( (0<<29) | (1<<28) );		//pull up


		// Infinite loop
		while (1)
		{
			//Note: Yes I know using time wasting timers is extremely inefficient but its a place holder for now lol

			GPIOD->BSRR = 1<<12;					//sets D12 high
			GPIOD->BSRR = 1<<14;					//sets D12
			for(int i=0; i<= 5000000; i++);
			GPIOD->BSRR = 1<<(12+16);				//resets D12 high
			GPIOD->BSRR = 1<<(14+16);				//resets D14
			for(int i=0; i<= 5000000; i++);

		}
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
