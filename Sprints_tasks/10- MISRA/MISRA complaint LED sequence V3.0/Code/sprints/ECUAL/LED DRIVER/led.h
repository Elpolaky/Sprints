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

extern enu_Dio_ErrorStatus LED_init(enu_PORT_NUM portNum , enu_PIN_NUM pinNum);
extern enu_Dio_ErrorStatus LED_on (enu_PORT_NUM portNum , enu_PIN_NUM pinNum);
extern enu_Dio_ErrorStatus LED_off(enu_PORT_NUM portNum , enu_PIN_NUM pinNum);
extern enu_Dio_ErrorStatus LED_toggle(enu_PORT_NUM portNum , enu_PIN_NUM pinNum);

void LED_uintTesting(void);

#endif /* INCFILE1_H_ */