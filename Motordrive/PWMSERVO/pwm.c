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
#include "encoder.h"
volatile static unsigned char pwm_ready = 0;
volatile char pwmduty1;
volatile char pwmduty2;
volatile char pwmduty3;
volatile char pwmduty4;

//Initalizing all pwm signals
void pwmall_init(){
	pwm1_init();
	pwm2_init();
	pwm3_init();
	pwm4_init();
	pwm5_init();
	pwm6_init();
	pwmalloff();

}

void pwm1_init(){
	//Digitalpin 6
	DDRD |= (1<<PORTD6);
	TCCR0A|=(1<<COM0A1)| (1<<WGM00)|(1<<WGM01); // Setup fastpwm with Clear OC0A on compare match and set at bottom

	TIMSK0 |= (1<<TOIE0);
	OCR0A = (pwmduty1/100.0)*255;
	TCCR0B|=0x01;

}

void pwm2_init(){
//Digitalpin 5
	DDRD |= (1<<PORTD5);
	TCCR0A|=(1<<COM0B1)| (1<<WGM00)|(1<<WGM01);

	TIMSK0 |= (1<<TOIE0);

	OCR0B = (pwmduty2/100.0)*255;

	TCCR0B|=0x01;
}

void pwm3_init(){
//works - Digitalpin 3
	DDRD |= (1<<PORTD3);
	TCCR2A|=(1<<COM2B1)| (1<<WGM20)|(1<<WGM21);

	TIMSK2 |= (1<<TOIE2);

	OCR2B = (pwmduty3/100.0)*255;

	TCCR2B=0x01;
}

void pwm4_init(){
// digitalpin 11
	DDRB |= (1<<PORTB3);
	TCCR2A|=(1<<COM2A1)| (1<<WGM20)|(1<<WGM21);

	TIMSK2 |= (1<<TOIE2);

	OCR2A = (pwmduty4/100.0)*255;

	TCCR2B=0x01;
}

void pwm5_init(){
// digitalpin 9 - Servo 1
	DDRB |= (1 << DDB1);

	TCCR1A |= (0b10 << COM1A0) | (0b10 << WGM10);

	TIMSK1 = (1 << TOIE1) | (1 << OCIE1A);

	OCR1AH = (SERVO_MIN & 0xFF00) >> 8;
	OCR1AL = (SERVO_MIN & 0x00FF);

	ICR1H = (PWM_TOP & 0xFF00) >> 8;
	ICR1L = (PWM_TOP & 0x00FF);


	TCCR1B = (0b11 << WGM12) | (0b010 << CS10);

}

void pwm6_init(){
// digitalpin 10 - Servo 2
	DDRB |= (1<<DDB2);
	TCCR1A |= (0b10 << COM1B0) | (0b10 << WGM10);
	TIMSK1 = (1 << TOIE1) | (1 << OCIE1A);

	OCR1BH = (SERVO_MIN & 0xFF00) >> 8;
	OCR1BL = (SERVO_MIN & 0x00FF);

	ICR1H = (PWM_TOP & 0xFF00) >> 8;
	ICR1L = (PWM_TOP & 0x00FF);

	TCCR1B = (0b11 << WGM12) | (0b010 << CS10);

}

static void update_pwm(unsigned int newvalue){
	pwm_ready = 1;
	while(pwm_ready != 0);
	OCR1AH = (newvalue & 0xFF00) >> 8;
	OCR1AL = (newvalue & 0x00FF);
}

static void update_pwm2(unsigned int newvalue){
	pwm_ready = 1;
	while(pwm_ready != 0);
	OCR1BH = (newvalue & 0xFF00) >> 8;
	OCR1BL = (newvalue & 0x00FF);
}

void servo_set(unsigned int deg,unsigned int max_deg){

	float set = (float)deg / (float)max_deg;

	set = (((float)SERVO_MX-(float)SERVO_MIN)*set) + (float)SERVO_MIN;

	unsigned int newvalue = (unsigned int)set;

	update_pwm(newvalue);

}
void servo2_set(unsigned int deg,unsigned int max_deg){

	float set = (float)deg / (float)max_deg;

	set = (((float)SERVO_MX-(float)SERVO_MIN)*set) + (float)SERVO_MIN;

	unsigned int newvalue = (unsigned int)set;

	update_pwm2(newvalue);

}

void pwm1off(){
	TCCR0A&=~(1<<COM0A1);
}

void pwm2off(){
	TCCR0A&=~(1<<COM0B1);
}
void pwm3off(){
	TCCR2A&=~(1<<COM2A1);
}

void pwm4off(){
	TCCR2A&=~(1<<COM2B1);
}
void pwm1on(){
	TCCR0A|=(1<<COM0A1);
}

void pwm2on(){
	TCCR0A|=(1<<COM0B1);
}
void pwm3on(){
	TCCR2A|=(1<<COM2A1);
}

void pwm4on(){
	TCCR2A|=(1<<COM2B1);
}

void pwmalloff(){
	pwm1off();
	pwm2off();
	pwm3off();
	pwm4off();
}

ISR(TIMER0_OVF_vect){
//	if(pwmduty1==0) TCCR0A&=~(1<<COM0A1);
//	else TCCR0A|=(1<<COM0A1);
//	if(pwmduty2==0) TCCR0A&=~(1<<COM0B1);
//	else TCCR0A|=(1<<COM0B1);


}
ISR(TIMER1_OVF_vect){
	pwm_ready = 0;
}

ISR(TIMER1_COMPA_vect){

}
ISR(TIMER2_OVF_vect){
//	if(pwmduty3==0) TCCR2A&=~(1<<COM2A1);
//	else TCCR2A|=(1<<COM2A1);
//	if(pwmduty4==0) TCCR2A&=~(1<<COM2B1);
//	else TCCR2A|=(1<<COM2B1);
	clockcount1++;
	clockcount++;
}

