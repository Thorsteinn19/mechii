/*
 * delay.c
 *
 *  Created on: 2 Feb 2022
 *      Author: stein
 */

#include "delay.h"


void delay_ms(int x){
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");

	long int countlimit = 248+(x-1)*250;
for (long int a=0;a<=countlimit;a++){
	delay_minimum();
}
}

void delay_minimum(){
asm("nop");
asm("nop");
asm("nop");
asm("nop");
}

void delay_us(char x){
	char i;
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");

	if(x>3){
		x=x-3;
	for(i=0;i<x;i++){
		asm("nop");
		asm("nop");


	}
	asm("nop");
	asm("nop");
	}
}

void delay_s(int s){
	int i,j;

	for(i=0;i<s;i++){
		for (j=0;j<1151;j++){
			asm("nop");
		}
	delay_ms(100);
	delay_ms(100);
	delay_ms(100);
	delay_ms(100);
	delay_ms(100);
	delay_ms(100);
	delay_ms(100);
	delay_ms(100);
	delay_ms(100);
	delay_ms(99);
	}
}

