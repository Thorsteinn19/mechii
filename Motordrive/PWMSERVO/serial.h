/*
 * serial.h
 *
 *  Created on: 10 Feb 2022
 *      Author: stein
 */

#ifndef UART_SERIAL_H_
#define UART_SERIAL_H_


extern volatile char cRx[10];
extern volatile int charcounter;
void Init_Uart();
void printhexbyte(char inputchar);
char nibbletohexvalue(char nibblebyte);
void printint(int inputint);
void printlong(long inputlong);
void chartoascii(char data);
void writestring(char string[]);
void floattoascii(float datain);



#endif /* UART_SERIAL_H_ */
