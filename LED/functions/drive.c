/*
 * drive.c
 *
 *  Created on: 17 Mar 2022
 *      Author: stein
 */

#include "drive.h"
#include "pwm.h"
#include "serial.h"

volatile char dcspeed;
volatile char sweepbool;
volatile unsigned int angle1;
volatile unsigned int angle2;

void actionfunction(char chararray[]){

	if (chararray[0]=='v'){
			dcspeed=100*(chararray[1]-0x30)+10*(chararray[2]-0x30)+(chararray[3]-0x30);
			writestring("speedsuccessful");
	}
	else if (chararray[0]=='n'){
		if (chararray[1]=='2'){
			angle1 = 100*(chararray[2]-0x30)+10*(chararray[3]-0x30)+(chararray[4]-0x30);
			writestring("servosuccess");
		}
		else if (chararray[1]=='1'){
			unsigned int angle = 100*(chararray[2]-0x30)+10*(chararray[3]-0x30)+(chararray[4]-0x30);
			chartoascii(angle);
			writestring("servosuccess");

			}
		else if (chararray[1]=='s'){
			sweepbool=chararray[2]-0x30;
			writestring("servosuccess");
		}
	}
	else if (chararray[0]=='w'){
		pwmduty2=0;
		pwmduty4=0;
		pwmduty1=dcspeed;
		pwmduty3=dcspeed;
		writestring("forward");
		chartoascii(dcspeed);
	}
	else if (chararray[0]=='s'){
		pwmduty1=0;
		pwmduty3=0;
		pwmduty2=dcspeed;
		pwmduty4=dcspeed;
		writestring("backwards");
	}
	else if (chararray[0]=='a'){
		pwmduty3=0;
		pwmduty2=0;
		pwmduty1=dcspeed;
		pwmduty4=dcspeed;
		writestring("right");
	}
	else if (chararray[0]=='d'){
		pwmduty3=0;
		pwmduty2=0;
		pwmduty1=dcspeed;
		pwmduty4=dcspeed;
		writestring("left");
	}




}
