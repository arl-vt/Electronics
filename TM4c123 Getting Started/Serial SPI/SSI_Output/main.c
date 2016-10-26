/* %%%%%%%%%%%% SSI OUTPUT - Control LED MAtrix  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * ------------On LaunchPAd - TM4C123 -----------------------------------------------------
 * */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_ssi.h"
#include "driverlib/ssi.h"
#include "driverlib/pin_map.h"

#define USER_LED  GPIO_PIN_1
#define NUM_SSI_DATA 8
const uint8_t dataTx[NUM_SSI_DATA] = {0x88, 0xF8, 0xF8, 0x88, 0x01, 0x1F, 0x1F, 0x01}; //For a 8x8 matrix

//Bit reverse number so that 16 bit data can be sent over SPI
uint8_t Reverse(uint8_t Number){
	uint8_t Index;
	uint8_t ReverseNumber = 0;
	for(Index=0; Index<8; Index++){
		ReverseNumber = ReverseNumber << 1;
		ReverseNumber |= ((1<< Index)&Number) >> Index;
	}
	return ReverseNumber;
}


int main(void)
{
	uint32_t Index;
	uint32_t Data;

    // Setup the system clock to run at 50 Mhz from PLL with crystal reference
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ| SYSCTL_OSC_MAIN);

    // Enable and wait for the port to be ready for access
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, USER_LED);

    //Enable SSI
    SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    GPIOPinConfigure(GPIO_PA2_SSI0CLK);
    GPIOPinConfigure(GPIO_PA3_SSI0FSS);
    GPIOPinConfigure(GPIO_PA5_SSI0TX);
    GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_3|GPIO_PIN_2);
    //Configure clock source, mode, master/slave, bit rate, data width
    SSIConfigSetExpClk(SSI0_BASE, SysCtlClockGet(), SSI_FRF_MOTO_MODE_0,SSI_MODE_MASTER, 10000, 16);
    SSIEnable(SSI0_BASE);

    while(1)
    {
    	// Stream data continuosly
    	for(Index=0; Index<NUM_SSI_DATA; Index++){
    		Data = Reverse(dataTx[Index] << 8)+(1<<Index);
    		SSIDataPut(SSI0_BASE, Data);

    		SysCtlDelay(20000000);
    		while(SSIBusy(SSI0_BASE)){

    		}
    	}
    }
}
