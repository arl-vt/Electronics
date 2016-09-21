/*
 * QEI.c
 *
 *  Created on: Aug 26, 2016
 *      Author: thpesek
 */


#include "QEI.h"

void EncStartup(void){
	SysCtlPeripheralEnable(SYSCTL_PERIPH_QEI0);
	QEIConfigure(QEI0_BASE,QEI_CONFIG_CAPTURE_A_B | QEI_CONFIG_NO_RESET | QEI_CONFIG_QUADRATURE,10000000);
	QEIEnable(QEI0_BASE);
	QEIVelocityConfigure(QEI0_BASE,QEI_VELDIV_1,1800000);

	QEIVelocityEnable(QEI0_BASE);
}

int32_t EncPOS(void){
	return  QEIPositionGet(QEI0_BASE);
}


int32_t EncVel(void){
	return QEIDirectionGet(QEI0_BASE) *QEIVelocityGet(QEI0_BASE);

}
