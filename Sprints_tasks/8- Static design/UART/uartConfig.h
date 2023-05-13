/*
 * uartConfig.h
 *
 * Created: 5/13/2023 5:51:40 PM
 *  Author: moham
 */ 


#ifndef UARTCONFIG_H_
#define UARTCONFIG_H_

#include "uartTypes.h"

#define UART_NUM   1   // Number of UART in AVR

typedef struct
{
	EN_STATE_ENABLE	 State_Enable;
	EN_SPEED	     speed;
	EN_BAUD_RATE	 BaudRate;
	EN_PARITY		 Parity;
	EN_SYNC_MODE	 Synch;
	EN_STOP_BIT		 Stop_Bits;
	EN_DATA_BITS	 Data_Bits;
	

}ST_UART_Cfg;

extern ST_UART_Cfg Uart_Cfg[UART_NUM]

#endif /* UARTCONFIG_H_ */