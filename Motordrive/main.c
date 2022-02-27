/*
 * main.c
 *
 *  Created on: 31 Jan 2022
 *      Author: stein
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "PWMSERVO/delay.h"
#include "PWMSERVO/pwm.h"
#include "PWMSERVO/serial.h"


int main(){
	Init_Uart();
	pwmall_init();
	sei();
 char test=0;
	while (1) // Loop forever
	{
		chartoascii(test);
		writestring("\n");
		UDR0=0x0D;
		printhexbyte(test);
		writestring("\n");
		UDR0=0x0D;
		printint(test);
		writestring("\n");
		UDR0=0x0D;
		printlong(test);
		writestring("\n");
		UDR0=0x0D;
		writestring("Snilldin ein \n");
		UDR0=0x0D;
		writestring("\n");
		UDR0=0x0D;
		delay_s(1);
		test++;
	}

return 0;
}

