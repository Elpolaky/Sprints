/*
 * LED_SequenceV1.c
 *
 * Created: 4/7/2023 6:19:18 PM
 *  Author: moham
 */ 

#include "applicarion.h"

uint8_t bell[8] = {0x04, 0x0E ,0x0E ,0x0E ,0x1f ,0x00 ,0x04 ,0x00};
uint8_t bell2[8] = {0x04, 0x0E ,0x0E ,0x0E ,0x1f ,0x00 ,0x10 ,0x00};
uint8_t bell3[8] = {0x04, 0x0E ,0x0E ,0x0E ,0x1f ,0x00 ,0x01 ,0x00};
void app_init(void){

LCD_4_Bit_init();
LCD_CreatCustomCharacter(bell,0);
	
	
LCD_CreatCustomCharacter(bell2,1);
LCD_CreatCustomCharacter(bell3,2);


}

void app_start(){

LCD_4_Bit_SendChar(0);
_delay_ms(1000);
LCD_4_Bit_SendCommand(CLEAR_DISPLAY);
LCD_4_Bit_SendCommand(CURSOR_HOME_POSITION);
LCD_4_Bit_SendChar(1);
_delay_ms(1000);
LCD_4_Bit_SendCommand(CLEAR_DISPLAY);
LCD_4_Bit_SendCommand(CURSOR_HOME_POSITION);	

LCD_4_Bit_SendChar(0);
_delay_ms(1000);
LCD_4_Bit_SendCommand(CLEAR_DISPLAY);
LCD_4_Bit_SendCommand(CURSOR_HOME_POSITION);

LCD_4_Bit_SendChar(2);
_delay_ms(1000);
LCD_4_Bit_SendCommand(CLEAR_DISPLAY);
LCD_4_Bit_SendCommand(CURSOR_HOME_POSITION);

	}
