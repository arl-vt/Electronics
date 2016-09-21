/*
 * QEI.h
 *
 *  Created on: Aug 26, 2016
 *      Author: thpesek
 */

#ifndef QEI_H_
#define QEI_H_
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

#include "driverlib/qei.h"


void EncStartup(void);

int32_t EncPOS(void);
int32_t EncVel(void);


#endif /* QEI_H_ */
