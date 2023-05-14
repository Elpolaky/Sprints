/*
 * uart.h
 *
 * Created: 5/13/2023 5:47:58 PM
 *  Author: moham
 */ 


#ifndef UART_H_
#define UART_H_


/*************************************************/
//					INCLUDES
/**************************************************/
#include "uartConfig.h"
#include "../DIO DRIVER/DIO.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/types.h"

/*************************************************/
//					MACROS
/**************************************************/
#define cpu_freq_selector  8000000

// register bits 
#define  RXEN  4
#define  TXEN  3
#define  URSEL 7
#define  UCSZ0 1
#define  UDRE  5
#define  RXC   7
#define  UCSZ1 2

#define USBS	3
#define UPM0	4
#define UPM1	5
#define UMSEL	6

#define UCSZ0	1
#define UCSZ1	2
#define UCSZ2	2

#define U2X		1

/*************************************************/
//			 FUNCTIONS PROTOTYPES
/**************************************************/
// Functions prototypes
void USART_init(void);
void USART_transmit(uint8_t data);
uint8_t USART_receive(void);
void USART_Transmit_string (char * str);
char * USART_receive_string (uint8_t *string) ;

#endif /* UART_H_ */