/*
 * delay.h
 *
 *  Created on: 2 Feb 2022
 *      Author: stein
 */

#ifndef DELAY_H_
#define DELAY_H_

extern long int countlimit;
void delay_ms(int x);
void delay_minimum();

void delay_us(char a);
void delay_s(int s);
void pwm(char pin,int i,char time);
void sweep(char pin);

#endif /* DELAY_H_ */
