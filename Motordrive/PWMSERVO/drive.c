/*
 * drive.c
 *
 *  Created on: 17 Mar 2022
 *      Author: stein
 */
#include <avr/interrupt.h>
#include "drive.h"
#include "pwm.h"
#include "serial.h"
#include "encoder.h"

volatile char dcspeed;
volatile char sweepbool;
volatile unsigned int angle1;
volatile unsigned int angle2;

void actionfunction(char chararray[]){

	if (chararray[0]=='v'){
			//must write all, 50%=v050
		if (chararray[2]<0x30) dcspeed=chararray[1]-0x30;
		else if (chararray[3]<0x30) dcspeed=(10*(chararray[1]-0x30)+(chararray[2]-0x30));
		else if (chararray[1]=='0') dcspeed=0;
		else dcspeed=100*(chararray[1]-0x30)+10*(chararray[2]-0x30)+(chararray[3]-0x30);

		dcspeed=(dcspeed/100.0)*255;
		if (dcspeed==0){
			pwmalloff();
		}
		else{
		OCR0A = dcspeed;
		OCR0B = dcspeed;
		OCR2A = dcspeed;
		OCR2B = dcspeed;
		}
	}
	else if (chararray[0]=='n'){
		if (chararray[1]=='2'){
			angle1 = 100*(chararray[2]-0x30)+10*(chararray[3]-0x30)+(chararray[4]-0x30);
			chartoascii(angle1);
		}
		else if (chararray[1]=='1'){
			angle2 = 100*(chararray[2]-0x30)+10*(chararray[3]-0x30)+(chararray[4]-0x30);
			chartoascii(angle2);
			writestring("servosuccess");

			}
		else if (chararray[1]=='s'){
			sweepbool=chararray[2]-0x30;
			writestring("servosuccess");
		}
	}
	else if (chararray[0]=='w'){
		//pwmduty2 off;
		pwm2off();
		//pwmduty4 off;
		pwm4off();
		//pwm1 on
		pwm1on();
		pwm3on();
	}
	else if (chararray[0]=='s'){
		//pwmduty1 off;
		pwm1off();
		//	pwmduty3 off;
		pwm3off();
		pwm2on();
		pwm4on();
	}
	else if (chararray[0]=='a'){
		pwm3off();
		pwm2off();
		pwm1on();
		pwm4on();
	}
	else if (chararray[0]=='d'){
		pwm1off();
		pwm4off();
		pwm2on();
		pwm3on();
	}
	else if (chararray[0]=='p'){
		chartoascii(dir1);
		writestring("\n");
		floattoascii(timediff1*0.0159375);
		writestring("\n");
		chartoascii(dir0);
		writestring("\n");
		floattoascii(timediff*0.0159375);
		writestring("\n");

	}

}
