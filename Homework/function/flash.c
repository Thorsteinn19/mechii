/*
 * flash.c
 *
 *  Created on: 27 Jan 2022
 *      Author: stein
 */

#include <avr/io.h>
#include "pins.h"

void pins(char pin)
{

	DDRB|=pin;
	while(1)
	{
		PORTB|=pin;
		PORTB&=~pin;
	}

}

void led_on(char pin){
	DDRB |=pin;
	PORTB |= pin;
}

void led_off(char pin){
	DDRB|=pin;
	PORTB &= ~pin;
}
