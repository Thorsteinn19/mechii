/*
 * pins.h
 *
 *  Created on: 27 Jan 2022
 *      Author: stein
 */

#ifndef PINS_H_
#define PINS_H_

extern unsigned char LEDPIN;
extern int STOPTIME;
void pins(char pin);
void led_on(char pin);
void led_off(char pin);


#endif /* PINS_H_ */
