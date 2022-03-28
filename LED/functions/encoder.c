/*
 * encoder.c
 *
 *  Created on: 3 Mar 2022
 *      Author: stein
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "encoder.h"

char dir0;
char dir1;
long clockcount;
float timediff;
long clockcount1;
float timediff1;



