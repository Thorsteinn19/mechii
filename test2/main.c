#include <avr/io.h>
/*
 * main.c
 *
 *  Created on: 14 Jan 2022
 *      Author: stein
 */

int main()
{
	DDRB=0x20;
	while(1)
	{
		PORTB=0X20;
		PORTB=0;
	}
	return 0;
}
