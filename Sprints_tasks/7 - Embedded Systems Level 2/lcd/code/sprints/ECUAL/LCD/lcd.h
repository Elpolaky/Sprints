/*
 * lcd.h
 *
 * Created: 4/17/2023 5:30:10 AM
 *  Author: moham
 */ 


#ifndef LCD_H_
#define LCD_H_

/*************************************************/
//					INCLUDES
/**************************************************/
#include "../../MCAL/DIO DRIVER/dio.h"
#include "../../Utilities/types.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/registers.h"
#include <util/delay.h>

/*************************************************/
//					DEFIENS
/**************************************************/
// LCD configurations
#define lcd__dio_data_port		PORT_C
#define LCD_REG_DATA_PORT		PORTC
#define lcd_dio_cmd_port		PORT_D
#define  RS						PIN_0
#define  RW						PIN_1
#define  EN						PIN_2

// COMMANDS
#define LCD_16_2_INIT			0x38
#define DISPLAY_ON_CURSOR_OFF	0x0C
#define DISPLAY_ON_CURSOR_ON	0x0E
#define INCREMENT_CURSOR		0x06
#define CLEAR_DISPLAY			0x01
#define CURSOR_HOME_POSITION	0x80

#define LCD_4_BIT_MODE			0x02
#define LCD_16_2_INIT_4_BIT		0x28


/*************************************************/
//			 FUNCTIONS PROTOTYPES
/**************************************************/

/************ LCD 8 BIT **************************/
void LCD_8_Bit_init(void);
void LCD_8_Bit_SendCommand(uint8_t a_cmd);
void LCD_8_Bit_SendChar(uint8_t a_char);
void LCD_8_Bit_SendString(uint8_t *a_string);

/************ LCD 4 BIT **************************/
void LCD_4_Bit_init(void);
void LCD_4_Bit_SendCommand(uint8_t a_cmd);
void LCD_4_Bit_SendChar(uint8_t a_char);
void LCD_4_Bit_SendString(uint8_t *a_string);

/************ CUSTOM CHARACTER **************************/
void LCD_CreatCustomCharacter(uint8_t *arr_patter , uint8_t a_position);
void LCD_clear(void);

#endif /* LCD_H_ */