/*
 * lcd.c
 *
 * Created: 4/17/2023 5:30:24 AM
 *  Author: moham
 */ 
#include "lcd.h"

void LCD_8_Bit_init(void){
	
	for (uint8_t data_pins = 0 ; data_pins < 8 ; data_pins++)
	{
		DIO_init(lcd__dio_data_port,data_pins,OUTPUT);
	}
	
	for (uint8_t cmd_pins = 0 ; cmd_pins < 3 ; cmd_pins++)
	{
		DIO_init(lcd_dio_cmd_port,cmd_pins,OUTPUT);
	}
	 _delay_ms(20);
	 
	 LCD_8_Bit_SendCommand(LCD_16_2_INIT);
	 LCD_8_Bit_SendCommand(DISPLAY_ON_CURSOR_ON);
	 LCD_8_Bit_SendCommand(INCREMENT_CURSOR);
	 LCD_8_Bit_SendCommand(CLEAR_DISPLAY);
	 LCD_8_Bit_SendCommand(CURSOR_HOME_POSITION);
	
}

void LCD_8_Bit_SendCommand(uint8_t a_cmd){
	LCD_REG_DATA_PORT = a_cmd;
	DIO_write(lcd_dio_cmd_port,RS,LOW);
	DIO_write(lcd_dio_cmd_port,RW,LOW);
	DIO_write(lcd_dio_cmd_port,EN,HIGH);
	_delay_us(1);
	DIO_write(lcd_dio_cmd_port,EN,LOW);
	_delay_ms(3);
	
	
}
void LCD_8_Bit_SendChar(uint8_t a_char){
	LCD_REG_DATA_PORT = a_char ;	
	DIO_write(lcd_dio_cmd_port,RS,HIGH);
	DIO_write(lcd_dio_cmd_port,RW,LOW);
	DIO_write(lcd_dio_cmd_port,EN,HIGH);
	_delay_us(1);
	DIO_write(lcd_dio_cmd_port,EN,LOW);
	_delay_ms(1);
	
	
	
	
}
void LCD_8_Bit_SendString(uint8_t *a_string){
	
	uint16_ l_charchters = 0;
	for (l_charchters = 0 ; a_string[l_charchters] != 0 ; l_charchters++  )
	{
		LCD_8_Bit_SendChar(a_string[l_charchters]);
	}
	LCD_8_Bit_SendCommand(DISPLAY_ON_CURSOR_OFF);
	LCD_8_Bit_SendCommand(CURSOR_HOME_POSITION);
	
}

void LCD_8_Bit_Clear(void){
	LCD_8_Bit_SendCommand(CLEAR_DISPLAY);
	LCD_8_Bit_SendCommand(CURSOR_HOME_POSITION);

}


void LCD_4_Bit_init(void){
	
	for (uint8_t data_pins = 4 ; data_pins < 8 ; data_pins++)
	{
		DIO_init(lcd__dio_data_port,data_pins,OUTPUT);
	}
	
	
	DIO_init(lcd_dio_cmd_port,RS,OUTPUT);
	DIO_init(lcd_dio_cmd_port,RW,OUTPUT);
	DIO_init(lcd_dio_cmd_port,EN,OUTPUT);
	 _delay_ms(20);
	LCD_4_Bit_SendCommand(LCD_4_BIT_MODE);
	LCD_4_Bit_SendCommand(LCD_16_2_INIT_4_BIT);
	LCD_4_Bit_SendCommand(DISPLAY_ON_CURSOR_OFF);
	//LCD_4_Bit_SendCommand(INCREMENT_CURSOR);
	LCD_4_Bit_SendCommand(CLEAR_DISPLAY);
}

void LCD_4_Bit_SendCommand(uint8_t a_cmd){
	LCD_REG_DATA_PORT = (LCD_REG_DATA_PORT & 0x0f) | (a_cmd & 0xf0);
	DIO_write(lcd_dio_cmd_port,RS,LOW);
	DIO_write(lcd_dio_cmd_port,RW,LOW);
	DIO_write(lcd_dio_cmd_port,EN,HIGH);
	_delay_us(1);
	DIO_write(lcd_dio_cmd_port,EN,LOW);
	_delay_us(200);
	
	LCD_REG_DATA_PORT = (LCD_REG_DATA_PORT & 0x0f) | (a_cmd << 4);
	DIO_write(lcd_dio_cmd_port,RS,LOW);
	DIO_write(lcd_dio_cmd_port,RW,LOW);
	DIO_write(lcd_dio_cmd_port,EN,HIGH);
	_delay_us(1);
	DIO_write(lcd_dio_cmd_port,EN,LOW);
	_delay_ms(3);
}



void LCD_4_Bit_SendChar(uint8_t a_char){
	if(a_char!=0){
		LCD_REG_DATA_PORT = (LCD_REG_DATA_PORT & 0x0f) | (a_char & 0xf0);
		DIO_write(lcd_dio_cmd_port,RS,HIGH);
		DIO_write(lcd_dio_cmd_port,RW,LOW);
		DIO_write(lcd_dio_cmd_port,EN,HIGH);
		_delay_us(1);
		DIO_write(lcd_dio_cmd_port,EN,LOW);
		_delay_us(200);
	
		LCD_REG_DATA_PORT = (LCD_REG_DATA_PORT & 0x0f) | (a_char << 4);
		DIO_write(lcd_dio_cmd_port,RS,HIGH);
		DIO_write(lcd_dio_cmd_port,RW,LOW);
		DIO_write(lcd_dio_cmd_port,EN,HIGH);
		_delay_us(1);
		DIO_write(lcd_dio_cmd_port,EN,LOW);
		_delay_ms(2);
	
	}
}


void LCD_4_Bit_SendString(uint8_t *a_string){
	
	uint16_ l_charchters = 0;
	for (l_charchters = 0 ; a_string[l_charchters] != 0 ; l_charchters++  )
		{
			LCD_4_Bit_SendChar(a_string[l_charchters]);
		}
	LCD_4_Bit_SendCommand(DISPLAY_ON_CURSOR_OFF);
	LCD_4_Bit_SendCommand(CURSOR_HOME_POSITION);
}



void LCD_CreatCustomCharacter(uint8_t *arr_patter , uint8_t a_position){
	

	LCD_4_Bit_SendCommand(0x40 + (a_position*8));
	for(uint8_t i=0 ; i<8 ; i++){
		LCD_4_Bit_SendChar(arr_patter[i]);
	}
	
		LCD_4_Bit_SendCommand(CURSOR_HOME_POSITION);
	
}



void LCD_4_Bit_Clear(void){
	LCD_4_Bit_SendCommand(CLEAR_DISPLAY);
	LCD_4_Bit_SendCommand(CURSOR_HOME_POSITION);

}



void LCD_Write_Number(uint32 a_number)
{
	uint8_t L_Remainder=0,L_Arr[16],L_Index_i=0,L_Index_j;
	if (a_number==0)
	{
		LCD_4_Bit_SendChar('0');
	}
	while(a_number>0)
	{
		L_Remainder=a_number%10;
		L_Arr[L_Index_i]=L_Remainder+'0';    /*tp display the number it self, when we add the zero asci it shits the number to it's asci*/
		L_Index_i++;
		a_number/=10;
	}
	
	for (L_Index_j=L_Index_i;L_Index_j>0;L_Index_j--)    /*to display the array of number */
	{
		LCD_4_Bit_SendChar(L_Arr[L_Index_j-1]);
	}
}