/*
 * IncFile1.h
 *
 * Created: 4/6/2023 2:27:17 AM
 *  Author: moham
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include "../../MCAL/DIO DRIVER/dio.h"


/*********************************************************/
//				FUNCTIONS PROTOTYPES
/*********************************************************/

Dio_ErrorStatus LED_init(PORT_NUM portNum , PIN_NUM pinNum);
Dio_ErrorStatus LED_on (PORT_NUM portNum , PIN_NUM pinNum);
Dio_ErrorStatus LED_off(PORT_NUM portNum , PIN_NUM pinNum);
Dio_ErrorStatus LED_toggle(PORT_NUM portNum , PIN_NUM pinNum);

void LED_uintTesting(void);

#endif /* INCFILE1_H_ */