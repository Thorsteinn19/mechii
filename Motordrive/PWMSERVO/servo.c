/*
 * servo.c
 *
 *  Created on: 10 Feb 2022
 *      Author: stein
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "serial.h"
#include "servo.h"

volatile char servoduty1;
volatile char servoduty2;
char dccommand;

void servo1_init(){
	servoduty1=0;
	DDRD |= (1<<PORTD6);
	TCCR0A|=(1<<COM0A1)| (1<<WGM00)|(1<<WGM01); // Setup fastpwm with Clear OC0A on compare match and set at bottom

	TIMSK0 |= (1<<TOIE0);

	OCR0A = (servoduty1/100.0)*255;

	TCCR0B|=0x05;


}

void servo2_init(){
	servoduty2=0;
	DDRD |= (1<<PORTD5);
	TCCR0A|=(1<<COM0A1)| (1<<WGM00)|(1<<WGM01);

	TIMSK0 |= (1<<TOIE0);

	OCR0B = (servoduty2/100.0)*255;

	TCCR0B|=0x05;
}

ISR(TIMER0_OVF_vect){
	OCR0A = (servoduty1/100.0)*255;
	OCR0B = (servoduty2/100.0)*255;
}

void setservocycle(char data){
 servoduty1=data;
}
char getcycle(){

	return servoduty1;
}
void setdccommand(char command){
	dccommand= command;
}

