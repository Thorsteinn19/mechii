/*
 * encoder.c
 *
 *  Created on: 3 Mar 2022
 *      Author: stein
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "encoder.h"
#include "serial.h"

char dir0;
char dir1;
long clockcount;
long clockcount1;
static char onoff;
long movave[10]={0,0,0,0,0,0,0,0,0,0};
static int avepos=0;
long movave2[10]={0,0,0,0,0,0,0,0,0,0};
static int avepos2=0;

void encoder1init(){
	// Utilize attatch interrupt on pin D4
	clockcount1=0;
	onoff=0;
	TIMSK2 |= (1<<TOIE2);
	TCCR2B=0x01;
	PCICR|=(1<<PCIE2);
	PCMSK2|=(1<<PCINT20);

}

void encoder0init(){
	// Utilize pin D2 on arduino with external interrupt
	clockcount=0;
	TIMSK2 |= (1<<TOIE2);
	TCCR2B=0x01;
	EICRA|=(1<<ISC01)|(1<<ISC00);
	EIMSK|=(1<< INT0);
}



ISR(PCINT2_vect){
	if (PIND & (1 << PD4)) {
	dir1=PINB&0x01;
	movave[avepos]=clockcount;
	clockcount=0;
	if (avepos==9) avepos=0;
	else avepos++;
	}
}


ISR(INT0_vect){
dir0=(PIND & (1<<PD7))>>7;
movave2[avepos2]=clockcount1;
clockcount1=0;
if (avepos2==9) avepos2=0;
else avepos2++;
}
