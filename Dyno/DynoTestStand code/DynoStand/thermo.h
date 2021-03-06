/*
 * thermo.h
 *
 *  Created on: Aug 24, 2016
 *      Author: thpesek
 */

#ifndef THERMO_H_
#define THERMO_H_

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
#include "driverlib/ssi.h"
#include <stdio.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/uart.h"
#include "driverlib/systick.h"
#include "driverlib/fpu.h"
#include "utils/uartstdio.h"

#define BASE SSI0_BASE


/*
 * variables
 */

float TC0;
float TC1;
float TC2;
float TC3;
float TC4;


void Setup_SPI(void);
void ConfigureTC(uint8_t TCnum);
float ReadTCTemp(uint8_t TCnum);
float ReadCJTemp(uint8_t TCnum);
uint8_t ReadFault(uint8_t TCnum);

int8_t setAddress(uint8_t TCnum);





#endif /* THERMO_H_ */
