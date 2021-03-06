/* %%%%%%%%%%%%  DIGITAL OUTPUT  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * ------------Blink Blue LEd on LaunchPAd - TM4C129
 * */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#define USER_LED1  GPIO_PIN_0
#define USER_LED2  GPIO_PIN_1
#define USER_LED3  GPIO_PIN_3

int main(void)
{
    //
    // Setup the system clock to run at 50 Mhz from PLL with crystal reference
    //
    SysCtlClockFreqSet((SYSCTL_CFG_VCO_480|SYSCTL_USE_PLL|SYSCTL_XTAL_25MHZ|
                    SYSCTL_OSC_MAIN), 120000000);

    //
    // Enable and wait for the port to be ready for access
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION))
    {
    }

    //
    // Configure the GPIO port for the LED operation.
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, (USER_LED1|USER_LED2));
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, (USER_LED1|USER_LED3));
    //
    // Loop Forever
    //
    while(1)
    {
        //
        // Turn on the LED
        //
        GPIOPinWrite(GPIO_PORTN_BASE, USER_LED1, USER_LED1);
        GPIOPinWrite(GPIO_PORTF_BASE, USER_LED1, USER_LED1);

        //
        // Delay for a bit
        //
        SysCtlDelay(2000000);

        //
        // Turn on the LED
        //
        GPIOPinWrite(GPIO_PORTN_BASE, USER_LED1, ~(USER_LED1));
        GPIOPinWrite(GPIO_PORTF_BASE, USER_LED1, ~(USER_LED1));

        //
        // Delay for a bit
        //
        SysCtlDelay(2000000);
    }
}
