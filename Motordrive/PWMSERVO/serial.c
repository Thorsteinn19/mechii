/*
 * serial.c
 *
 *  Created on: 10 Feb 2022
 *      Author: stein
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include "serial.h"
#include "delay.h"
#include "servo.h"


#define BUAD 9600
#define BRC ((F_CPU/16/BUAD)-1)
volatile char cRx;
char serialin;

void Init_Uart(){
	UBRR0H=0;
	UBRR0L = 16;
	UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
	UCSR0C=(1<<USBS0)|(3<<UCSZ00);

}

ISR(USART_RX_vect){

	cRx=UDR0;
	serialin=cRx;
	UDR0=cRx;
}






