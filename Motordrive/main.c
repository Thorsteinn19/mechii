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
	servo1_init();
	sei();
	cRx=0x6D;
	serialin=48;

	while (1) // Loop forever
	{

		servoduty1=serialin-48;
	}

return 0;
}

