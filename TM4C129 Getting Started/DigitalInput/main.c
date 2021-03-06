// ------------------------LED and Digital Input--------------------- //
/* LED on PN1, PN0, PF4, PF0
 * PF4 - LED 3
 * PN0 - LED 2
 * Switch - PJ0 and PJ1
 * Turn on LED 2 PN0 on pressing Switch 1 PJ0
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

void initializeLED(void);
void initializeSwitch(void);
void setupClock(void);

int main(void) {
	
	setupClock();
	initializeLED();
	initializeSwitch();

	while(1){

		if((GPIOPinRead(GPIO_PORTJ_BASE, GPIO_PIN_0)&GPIO_PIN_0) == 0){ //Switch pressed
			GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0); //Write on LED 2
		}else{
			GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, ~(GPIO_PIN_0)); //Write on LED 2
		}
	}
}

void setupClock(){
	//Clock at ... MHz
		SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_25MHZ|SYSCTL_OSC_MAIN);
}
void initializeLED(){
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
		while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION)){
			//wait
		}

		// Configure GPIO Port of digital output
		GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0);
}

void initializeSwitch(){
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOJ)){
				//wait
	}

	// Configure GPIO Port of digital input
	GPIOPinTypeGPIOInput(GPIO_PORTJ_BASE, GPIO_PIN_0); //PJ0

	GPIOPadConfigSet(GPIO_PORTJ_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
}
