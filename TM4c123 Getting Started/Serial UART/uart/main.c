/* %%%%%%%%%%%%  UART  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * ------------Send DATA over UART on LaunchPAd - TM4C123 : Polling -------------------
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

#define USER_LED  GPIO_PIN_1

int main(void)
{
	char c;
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
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, USER_LED);

    //Configure UART functionality
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE,GPIO_PIN_0|GPIO_PIN_1);

    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200, (UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE));

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
    	//If there is a character in the reciever, it is read and written to the transmitter
       if(UARTCharsAvail(UART0_BASE)){
       	//Read the incoming bit
    	   c =  UARTCharGet(UART0_BASE);

    	   if(c == 'a' || c=='A'){
    		   //Turn on RED LED
    		   GPIOPinWrite(GPIO_PORTF_BASE, USER_LED, USER_LED); //Turn ON
    	   }else{
    		   GPIOPinWrite(GPIO_PORTF_BASE, USER_LED, ~(USER_LED));
    	   }

    	   //display the entered text on terminal
    	   UARTCharPut(UART0_BASE, c);

       }
    }
}
