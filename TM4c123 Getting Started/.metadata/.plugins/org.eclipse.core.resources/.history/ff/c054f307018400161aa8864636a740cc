/* %%%%%%%%%%%%  DIGITAL INPUT  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * ------------Blink Blue LEd on LaunchPAd on Switch press
 * */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#define USER_LED1  GPIO_PIN_1  //Red
#define USER_LED2  GPIO_PIN_2  //Blue
#define USER_SW1  GPIO_PIN_4   //SW1
#define USER_SW2  GPIO_PIN_0  //SW2, requires unlocking

int main(void)
{
	int32_t sw1;
    //
    // Setup the system clock to run at 50 Mhz from PLL with crystal reference
    //
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|
                    SYSCTL_OSC_MAIN);

    //
    // Enable and wait for the port to be ready for access
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }

    //
    // Configure the GPIO port for the LED and Switchoperation.
    //
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, USER_SW1);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, USER_LED1 | USER_LED2);

    GPIOPadConfigSet(GPIO_PORTF_BASE, USER_SW1, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    //
    // Loop Forever
    //
    while(1)
    {
    	// Read the switch 1 input
    	//sw1 = GPIOPinRead(GPIO_PORTF_BASE, USER_SW1);

        // Turn on the LED if Switch is pressed
    	if(((GPIOPinRead(GPIO_PORTF_BASE, USER_SW1))&USER_SW1) == 0){
            GPIOPinWrite(GPIO_PORTF_BASE, USER_LED1, USER_LED1);

    	}else{
    		GPIOPinWrite(GPIO_PORTF_BASE, USER_LED1, ~(USER_LED1));
    	}
    }
}
