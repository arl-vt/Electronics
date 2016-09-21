/*
 * ADC.h
 *
 *  Created on: Aug 29, 2016
 *      Author: thpesek
 */

#ifndef ADC_H_
#define ADC_H_

#include "pinout.h"
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include <stdio.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/uart.h"
#include "driverlib/systick.h"
#include "driverlib/fpu.h"
#include "utils/uartstdio.h"
#include "driverlib/adc.h"


void ADCSetup(void);



#endif /* ADC_H_ */
