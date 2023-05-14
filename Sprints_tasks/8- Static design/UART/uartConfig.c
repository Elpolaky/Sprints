/*
 * uartCofig.c
 *
 * Created: 5/13/2023 5:51:19 PM
 *  Author: moham
 */ 
#include "uartConfig.h"

ST_UART_Cfg Uart_Cfg[UART_NUM] ={
	
	{
		TX_ENABLE , NORMAL_SPEED , BAUD_9600 , NO_PARITY , ASYNC , ONE_STOP_BIT , _8_BITS 
	},
	
	
	};