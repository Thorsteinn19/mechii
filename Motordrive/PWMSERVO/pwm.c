/*
 * servo.c
 *
 *  Created on: 10 Feb 2022
 *      Author: stein
 */
#include "pwm.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include "serial.h"

volatile char pwmduty1;
volatile char pwmduty2;
volatile char pwmduty3;
volatile char pwmduty4;
volatile char pwmduty5;
volatile char pwmduty6;

void pwmall_init(){
	pwm1_init();
	pwm2_init();
	pwm3_init();
	pwm4_init();
	pwm5_init();
	pwm6_init();
}

void pwm1_init(){
	DDRD |= (1<<PORTD6);
	TCCR0A|=(1<<COM0A1)| (1<<WGM00)|(1<<WGM01); // Setup fastpwm with Clear OC0A on compare match and set at bottom

	TIMSK0 |= (1<<TOIE0);

	OCR0A = (pwmduty1/100.0)*255;

	TCCR0B|=0x05;


}

void pwm2_init(){

	DDRD |= (1<<PORTD5);
	TCCR0A|=(1<<COM0A1)| (1<<WGM00)|(1<<WGM01);

	TIMSK0 |= (1<<TOIE0);

	OCR0B = (pwmduty2/100.0)*255;

	TCCR0B|=0x05;
}

void pwm3_init(){

	DDRD |= (1<<PORTD3);
	TCCR2A|=(1<<COM2A1)| (1<<WGM00)|(1<<WGM01);

	TIMSK2 |= (1<<TOIE2);

	OCR2B = (pwmduty3/100.0)*255;

	TCCR2B|=0x05;
}

void pwm4_init(){

	DDRD |= (1<<PORTB3);
	TCCR2A|=(1<<COM2A1)| (1<<WGM00)|(1<<WGM01);

	TIMSK2 |= (1<<TOIE2);

	OCR2A = (pwmduty4/100.0)*255;

	TCCR2B|=0x05;
}

void pwm5_init(){

	DDRD |= (1<<PORTB1);
	TCCR1A|=(1<<COM1A1)| (1<<WGM10)|(1<<WGM12);

	TIMSK1 |= (1<<TOIE1);

	OCR1A = (pwmduty5/100.0)*255;

	TCCR1B|=0x05;
}

void pwm6_init(){

	DDRD |= (1<<PORTB2);
	TCCR1A|=(1<<COM1A1)| (1<<WGM10)|(1<<WGM12);

	TIMSK1 |= (1<<TOIE1);

	OCR1A = (pwmduty6/100.0)*255;

	TCCR1B|=0x05;
}

ISR(TIMER0_OVF_vect){
	OCR0A = (pwmduty1/100.0)*255;
	OCR0B = (pwmduty2/100.0)*255;

}
ISR(TIMER1_OVF_vect){
	OCR1A = (pwmduty5/100.0)*255;
	OCR1B = (pwmduty6/100.0)*255;
}
ISR(TIMER2_OVF_vect){
	OCR2A = (pwmduty5/100.0)*255;
	OCR2B = (pwmduty6/100.0)*255;
}

