/*
 * serial.h
 *
 *  Created on: 10 Feb 2022
 *      Author: stein
 */

#ifndef UART_SERIAL_H_
#define UART_SERIAL_H_


extern volatile char cRx;
extern char serialin;
void Init_Uart();
ISR(USART_RX_vect);


#endif /* UART_SERIAL_H_ */