/*
 * thermo.c
 *
 *  Created on: Aug 24, 2016
 *      Author: thpesek
 */

#include "thermo.h"





void Setup_SPI(void){
		MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);
		SysCtlDelay(100);
		//Setup SPI Devices
		SSIConfigSetExpClk(SSI0_BASE, 120000000, SSI_FRF_MOTO_MODE_3, SSI_MODE_MASTER, 5000000, 8);

		SysCtlDelay(100);
		SSIAdvModeSet(SSI0_BASE,SSI_ADV_MODE_READ_WRITE);
				SysCtlDelay(1000);

		SSIEnable(SSI0_BASE);


		GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_3,0); //set the enable pin to on.

}

void ConfigureTC(uint8_t TCnum){

	while (setAddress(TCnum)==(-1 | -2) ){
		SysCtlDelay(12000);
	}

	uint32_t buffer=0;
	//SSIAdvFrameHoldEnable(SSI0_BASE);
	SSIDataPut(BASE, 0x80);//address
	 SSIDataPut(BASE, 0x80); //data for address 0x80
	 SSIDataPut(BASE, 0x03); //data for next address
	SSIAdvDataPutFrameEnd(BASE, 0x00);//data for final address

	 SysCtlDelay(100000);
	 SSIAdvFrameHoldDisable(BASE);
	 SysCtlDelay(100000);
/*
	 SSIAdvFrameHoldEnable(BASE);
	 SSIDataPut(BASE, 0x82);
	 SSIAdvDataPutFrameEnd(BASE, 0x00);
	  SSIAdvFrameHoldDisable(BASE);*/
	  //sysCtlDelay(100000);
 //------------Clearing read buffer
	 while(SSIDataGetNonBlocking(SSI0_BASE,&buffer)!=0){
//			   UARTprintf("flushing-buffer; value in buffer after write is = %2x\n",temp3);
			}
	 SysCtlDelay(500000);
}

float Get_Temperature(uint8_t TCnum){
	//TODO add addressing

	switch(TCnum){

		case 0:
			return TC0;


		case 1:
			return TC1;

		case 2:
			return TC2;

		case 3:
			return TC3;


	}
}
float ReadTCTemp(uint8_t TCnum){ //send cmd to read first register
	while (setAddress(TCnum)==(-1 | -2) ){
		SysCtlDelay(12000);
	}


	uint32_t buffer=0;
	uint32_t high_byte=0;
	uint32_t mid_byte =0;
	uint32_t low_byte=0;
	int16_t temp;

	 SSIAdvFrameHoldEnable(BASE);
	 SSIDataPut(BASE, 0x0C); //send cmd to read first register
	 SSIDataGet(BASE,&buffer);
	 SSIDataPut(BASE, 0x00);
	 SSIDataPut(BASE, 0x00);
	 SSIDataPut(BASE, 0x00);

	 SSIDataGet(BASE,&high_byte);
	 SSIDataGet(BASE,&mid_byte);
	 SSIDataGet(BASE,&low_byte);
	 SSIAdvFrameHoldDisable(BASE);
	 temp = ((high_byte&0x80)<<8)+ ((high_byte & 0b01111111)<<4) + (mid_byte >> 4);

	 if (temp<0){return temp;} //if temperature is negative then need to do 2's complement so for now, return the non decimal value

	 return  (float)temp + ((mid_byte & 0x0f)*0.0625+ (low_byte*.00024414063)); // only works for positive temperatures
}

float ReadCJTemp(uint8_t TCnum){ //measure the the cold junction temperature temperature
	while (setAddress(TCnum)==(-1 | -2) ){
		SysCtlDelay(12000);
	}

	uint32_t buffer=0;
	uint32_t high_byte=0;
	uint32_t low_byte=0;
	int16_t temp;

	SSIAdvFrameHoldEnable(BASE);
	 SSIDataPut(BASE, 0x0A); //read cold junction temperature. aka the chip's internal temperature
	 SSIDataGet(BASE,&buffer);
	 SSIDataPut(BASE, 0x00);
	 SSIDataPut(BASE, 0x00);
	 SSIAdvFrameHoldDisable(BASE);
	 SSIDataGet(BASE,&high_byte);
	 SSIDataGet(BASE,&low_byte);
	 temp = high_byte;
	 if (temp<0){return temp;}//if temperature is negative then need to do 2's complement so for now, return the non decimal value
return  temp ;//+ low_byte * .015625; // only works for positive temperatures
}

uint8_t ReadFault(uint8_t TCnum){ //measure the the thermo couple temperature
	while (setAddress(TCnum)==(-1 | -2) ){
		SysCtlDelay(12000);
	}

	uint32_t buffer=0;


	SSIAdvFrameHoldEnable(BASE);
	 SSIDataPut(BASE, 0x0F); //read cold junction temperature. aka the chip's temperature
	 SSIDataGet(BASE,&buffer);
	 SSIDataPut(BASE, 0x00);
	 SSIAdvFrameHoldDisable(BASE);
	 SSIDataGet(BASE,&buffer);


return  (uint8_t) buffer;
}

int8_t setAddress(uint8_t TCnum){
/*
 * S3 = PH0
 * S2 = PH1
 * S1 = PK6
 * S0 = PK7
 * EN = PK3
 * GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4,0);
 */
	if (TCnum>7){
		return -2;
	}

	 if (SSIBusy(SSI0_BASE)){
		return -1;
	 }


	 GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_7|GPIO_PIN_6,0);
	 GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_1|GPIO_PIN_0,0);





	 TCnum=15-TCnum; //remove if corrected SPI FS output on multiplexer
	 if (TCnum & 0b1000){
		 GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_0,0xff);
	 }

	 if (TCnum & 0b0100){
		 GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_1,0xff);
	 }

	 if (TCnum & 0b0010){
		 GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_6,0xff);
	 }

	 if (TCnum & 0b0001){
		 GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_7,0xff);
	 }

	 return 0;
}




