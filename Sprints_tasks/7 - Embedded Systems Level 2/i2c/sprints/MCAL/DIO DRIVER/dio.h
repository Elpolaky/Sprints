/*
 * dio.h
 *
 * Created: 4/5/2023 11:36:36 PM
 *  Author: moham
 */ 

#ifndef DIO_H_
#define DIO_H_


/*************************************************/
//					INCLUDES
/**************************************************/
#include "../../Utilities/types.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/registers.h"
#include <util/delay.h>


/*************************************************/
//					MACROS
/**************************************************/

// PORTS
typedef enum {
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
	
	}PORT_NUM;

// PINS
typedef enum{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7		
	}PIN_NUM;

// DIRECTIONS
typedef enum {
	INPUT,
	OUTPUT	
	}PIN_DIR;

// VALUE
typedef enum {
	LOW,
	HIGH
	}VALUE;

// Error Status

typedef enum {
	Dio_Ok = 0,
	Dio_PortError,
	Dio_PinError,
	Dio_ValueError,
	Dio_DirectionError,
	Dio_NullPointer,
	
} Dio_ErrorStatus;


/*************************************************/
//			 FUNCTIONS PROTOTYPES
/**************************************************/

Dio_ErrorStatus DIO_init(PORT_NUM PortNum, PIN_NUM PinNum , PIN_DIR direction);
Dio_ErrorStatus DIO_write(PORT_NUM PortNum, PIN_NUM PinNum , uint8_t value);
Dio_ErrorStatus DIO_read(PORT_NUM PortNum, PIN_NUM PinNum , uint8_t* value);
Dio_ErrorStatus DIO_toggle(PORT_NUM PortNum, PIN_NUM PinNum );


Dio_ErrorStatus DIO_Port_init(PORT_NUM PortNum, PIN_DIR direction);
Dio_ErrorStatus DIO_Port_write(PORT_NUM PortNum,  VALUE value);
void DIO_uintTesting (void);

#endif /* DIO_H_ */