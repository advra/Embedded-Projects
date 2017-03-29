
// ----------------------------------------------------------------------------
//	Note:
//
//	This uses S1-barebones project file ase the base code and a usermade Driver
//	reflecting the new code. (:


// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "Timer.h"
#include "User Libraries/_HAL_GPIO.h"


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
		GPIOD_RCC_Enable;
		//reset D pins
		GPIOD_Reset_Pin(12);
		GPIOD_Reset_Pin(14);

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

			LED_On(12);
			LED_Off(14);
			for(int i=0; i<= 5000000; i++);
			LED_Off(12);
			LED_On(14);
			for(int i=0; i<= 5000000; i++);

		}
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
