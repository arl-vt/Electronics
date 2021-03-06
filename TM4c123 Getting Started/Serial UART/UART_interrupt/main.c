/* %%%%%%%%%%%%  UART  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * ------------Send DATA over UART on LaunchPAd - TM4C123 : Inmterrupt -------------------
 *
 * UART on port A, pin 0 -Rx and Pin1- Tx: UART 0
 * */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"

#define USER_LED  GPIO_PIN_1

//UART Interupt habdle
void UARTIntHandler(void){
	uint32_t status;
	status = UARTIntStatus(UART0_BASE, true); //get the interrupt status
	UARTIntClear(UART0_BASE, status); //clear the interrupts
	while(UARTCharsAvail(UART0_BASE)){
		UARTCharPutNonBlocking(UART0_BASE, UARTCharGetNonBlocking(UART0_BASE)); //Echo Character
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2); //blink LED
		SysCtlDelay(SysCtlClockGet()/(1000*3)); //delay ~1ms
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, ~(GPIO_PIN_2)); //blink LED
	}
}


int main(void)
{
    // Setup the system clock to run at 50 Mhz from PLL with crystal reference
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);


    // Enable and wait for the port to be ready for access
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    // Configure port F for LED operation
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
        {
        }
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, USER_LED|GPIO_PIN_2);

    //Enable Interrupts
    IntMasterEnable();
    IntEnable(INT_UART0);

    //Configure UART functionality
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE,GPIO_PIN_0|GPIO_PIN_1);
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200, (UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE));
    UARTIntEnable(UART0_BASE, UART_INT_RX|UART_INT_RT); //Enable RX and RT inyterrupt sources only


    // Intial UART message
    UARTCharPut(UART0_BASE, 'E');
    UARTCharPut(UART0_BASE, 'n');
    UARTCharPut(UART0_BASE, 't');
    UARTCharPut(UART0_BASE, 'e');
    UARTCharPut(UART0_BASE, 'r');
    UARTCharPut(UART0_BASE, ' ');
    UARTCharPut(UART0_BASE, 'T');
    UARTCharPut(UART0_BASE, 'e');
    UARTCharPut(UART0_BASE, 'x');
    UARTCharPut(UART0_BASE, 't');
    UARTCharPut(UART0_BASE, ':');
    UARTCharPut(UART0_BASE, ' ');

    while(1)
    {
    	// Interrupt handler does everything
    }
}




