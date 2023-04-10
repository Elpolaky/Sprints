/*
 * button.h
 *
 * Created: 4/6/2023 5:10:40 AM
 *  Author: moham
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO DRIVER/dio.h"


/**************************************************/
//					MACROS
/**************************************************/

// BUTTONS CONFIG
#define BUTTON_1_PORT	PORT_C
#define BUTTON_1_PIN	PIN_1







/**************************************************/
//			 FUNCTIONS PROTOTYPES
/**************************************************/
Dio_ErrorStatus BUTTON_init(PORT_NUM portnum ,PIN_NUM pinnum);

Dio_ErrorStatus BUTTON_read(PORT_NUM portnum ,PIN_NUM pinnum, uint8_t *value);

void BUTTON_unitTesting(void);
#endif /* BUTTON_H_ */