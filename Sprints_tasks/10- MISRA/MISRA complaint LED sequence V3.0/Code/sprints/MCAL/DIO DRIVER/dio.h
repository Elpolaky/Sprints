/*
 * dio.h
 *
 * Created: 4/5/2023 11:36:36 PM
 *  Author: moham
 */ 

#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/types.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/registers.h"
#include <util/delay.h>


/*************************************************/
//					MACROS
/**************************************************/

// PORTS
typedef enum {
	PORT_A = 0,
	PORT_B,
	PORT_C,
	PORT_D
	
	}enu_PORT_NUM;

// PINS
typedef enum{
	PIN_0 = 0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7		
	}enu_PIN_NUM;

// DIRECTIONS
typedef enum {
	INPUT = 0,
	OUTPUT	
	}enu_PIN_DIR;

// VALUE
typedef enum {
	LOW = 0,
	HIGH
	}enu_VALUE;

// Error Status

typedef enum {
	Dio_Ok = 0,
	Dio_PortError,
	Dio_PinError,
	Dio_ValueError,
	Dio_DirectionError,
	Dio_NullPointer,
	
}enu_Dio_ErrorStatus;


/*************************************************/
//			 FUNCTIONS PROTOTYPES
/**************************************************/

extern enu_Dio_ErrorStatus DIO_init(enu_PORT_NUM PortNum, enu_PIN_NUM PinNum , enu_PIN_DIR direction);
extern enu_Dio_ErrorStatus DIO_write(enu_PORT_NUM PortNum, enu_PIN_NUM PinNum , uint8_t value);
extern enu_Dio_ErrorStatus DIO_read(enu_PORT_NUM PortNum, enu_PIN_NUM PinNum , uint8_t* value);
extern enu_Dio_ErrorStatus DIO_toggle(enu_PORT_NUM PortNum, enu_PIN_NUM PinNum );

void DIO_uintTesting (void);

#endif /* DIO_H_ */