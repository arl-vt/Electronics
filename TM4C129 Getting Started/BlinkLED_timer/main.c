// ------------------------Blink LED using Timers and Interrupts--------------------- //
/* LED on PN1, PN0, PF4, PF0
 * PF4 - LED 3
 * PN0 - LED 2
 * Switch - PJ0 and PJ1
 * BLINK LED 2 - PN0
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"

void initializeLED(void);
void initializeSwitch(void);
void setupClock(void);
void configureTimer(void);

int main(void) {
	
	setupClock();
	initializeLED();
	configureTimer();

	while(1){
		GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
	}
}

// ---------------------------------------------------------------------------------------//
/* ##########    Initialization functions #############  */
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
		GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_1);
}

void configureTimer(){
	//Enable Peripheral
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
	TimerConfigure(TIMER1_BASE, TIMER_CFG_PERIODIC);

	//Define periods for the periodic timer
	uint32_t periods;
	periods = SysCtlClockGet()/10;
	TimerLoadSet(TIMER1_BASE, TIMER_A, 120000000);

	//Enable Interrupts
	IntEnable(INT_TIMER1A);
	TimerIntEnable(TIMER1_BASE, TIMER_TIMA_TIMEOUT); //timeout interrupt
	IntMasterEnable();

	//Timer Enable
	TimerEnable(TIMER1_BASE, TIMER_A);
}

// ---------------------------------------------------------------------------------------//
/* ##########  ISR #############  */
void Timer1IntHandler(void){
	TimerIntClear(TIMER1_BASE, TIMER_TIMA_TIMEOUT);

	//Blink LED
	//Read current state and write back the opposite state
	if(GPIOPinRead(GPIO_PORTN_BASE, GPIO_PIN_0)){
		GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
	}else{
		GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0, ~(GPIO_PIN_0));
}
}
