/*
 * ADC.c
 *
 *  Created on: Aug 29, 2016
 *      Author: thpesek
 *
 */
#include "ADC.h"
void ADCSetup(void){
	/*
	 * Sets ADC to sample at 62.5 kHz with ADC_Clock_Rate = fourth; ch0 and ch 1 (PE3 and PE2)
	 */
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC1);

	ADCClockConfigSet(ADC0_BASE, ADC_CLOCK_SRC_PIOSC | ADC_CLOCK_RATE_FULL, 1);
	ADCClockConfigSet(ADC1_BASE, ADC_CLOCK_SRC_PIOSC | ADC_CLOCK_RATE_FULL, 1);

	ADCHardwareOversampleConfigure(ADC0_BASE,64);
	ADCHardwareOversampleConfigure(ADC1_BASE,64);

	ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_ALWAYS,0);
	ADCSequenceConfigure(ADC1_BASE, 0, ADC_TRIGGER_ALWAYS,0);

	ADCSequenceStepConfigure(ADC0_BASE,0,0,ADC_CTL_CH0|ADC_CTL_END);
	ADCSequenceStepConfigure(ADC1_BASE,0,0,ADC_CTL_CH1|ADC_CTL_END);

	ADCSequenceEnable(ADC0_BASE,0);
	ADCSequenceEnable(ADC1_BASE,0);

}
