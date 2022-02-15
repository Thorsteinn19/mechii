/*
 * main.c
 *
 *  Created on: 31 Jan 2022
 *      Author: stein
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "PWMSERVO/delay.h"
#include "PWMSERVO/serial.h"
#include "PWMSERVO/servo.h"


int main(){
	Init_Uart();
	sei();
 char test=250;
	while (1) // Loop forever
	{
		chartoascii(test);
		printhexbyte(test);
		delay_ms(2);
		UDR0=0x0D;
		delay_ms(2);
		UDR0=0x0A;
		delay_ms(2);

		delay_s(1);
		test++;

		writestring("Snilldin ein \n");
	}

return 0;
}

