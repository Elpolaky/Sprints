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

uint8_t key;
void app_init(void){
TIMER_0_init(NORMAL_MODE);
LCD_4_Bit_init();
I2C_init(I2C_PRESCALER_1);
LED_init(PORT_A,PIN_0);
}


void app_start(){
	uint8_t data =20 ;
	uint8_t data2 = 0 ;
	uint8_t ad1 = 0x00 ;
	uint8_t str2[17] = "1234567887654321";
	uint8_t str[16] = {};
		
	//EEPROM_Writeseq ( str2 ,&ad1);
	for (uint8_t i =0 ; i <16 ; i++)
	{
		EEPROM_Read(str+i ,ad1);
		LCD_4_Bit_SendChar(str[i]);
	}
	/*		
	 
		EEPROM_Read(str+1 ,ad1);
		LCD_4_Bit_SendChar(str[1]);
		EEPROM_Read(str+2 ,ad1);
		LCD_4_Bit_SendChar(str[2]);


//	



	
/*
	if(I2C_start()==EVENT_OK){
		
		if(I2C_addressEvent(0x10,READ)==AD_R_SENT_ACK_OK){
			
			if(I2C_receiveData(&data,NACK)== DATA_RECIEVE_NACK_OK){
				
				I2C_stop();
			}
			
		}
		

	}


	if(I2C_start()==EVENT_OK){
		
		if(I2C_addressEvent(0x10,WRITE)==AD_W_SENT_ACK_OK){
		
			if(I2C_sendData(&data)== DATA_SENT_ACK_OK){
				
				I2C_stop();
			}
			
		}
		
	}

*/
	
//	LCD_4_Bit_Clear();
	}
