// ------------------------Blink LED - Digital output--------------------- //
/* LED on PN1, PN0, PF4, PF0
 * PF4 - LED 3
 * PN0 - LED 2
 * Blibk led PF4, PN0
 */


#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

void initializeGPIO(void);

int main(void) {
	initializeGPIO();
	
	while(1){
//		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
//		SysCtlDelay(2000000);
//		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, ~(GPIO_PIN_4));
//		SysCtlDelay(2000000);

		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, GPIO_PIN_2);

		GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
		SysCtlDelay(2000000);
		GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, ~(GPIO_PIN_0));
		SysCtlDelay(2000000);
	}
}

void initializeGPIO(){
	//Clock at ... MHz
	SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_25MHZ|SYSCTL_OSC_MAIN);

//	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
//	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)){
//		//wait
//	}
//
//	// Configure GPIO Port of digital output
//	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_4);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
		while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION)){
			//wait
		}

		// Configure GPIO Port of digital output
		GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0);
		GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_2);
}
