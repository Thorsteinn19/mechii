/*
 * delay.c
 *
 *  Created on: 2 Feb 2022
 *      Author: stein
 */

#include "delay.h"
#include "function/pins.h"

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
void pwm(char pin,int i,char time){
	int iP=256;
	int count;
	time=16*time;
	for (count=0;count<time;count++){
	led_on(pin);
	delay_us(i);
	led_off(pin);
	delay_us(iP-i);
	}
}
void sweep(char pin){
	int iP=256;
	int i;
	for (i=0;i<iP;i++){
	pwm(pin,i,1);
	}
	for (i=256;i>0;i--){
	pwm(pin,i,1);
	}

}
