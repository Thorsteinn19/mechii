/*
 * main.c
 *
 *  Created on: 31 Jan 2022
 *      Author: stein
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "PWMSERVO/delay.h"
#include "PWMSERVO/pwm.h"
#include "PWMSERVO/serial.h"
#include "PWMSERVO/encoder.h"
#include "PWMSERVO/drive.h"

int main(){
	Init_Uart();
	//Setting external interrupt 1
	pwmduty1=0;
	pwmduty2=0;
	pwmduty3=0;
	pwmduty4=0;
	angle1=0;
	angle2=0;
	pwmall_init();
	encoder0init();
	encoder1init();
	sei();
	unsigned int counter1=0;
	unsigned int counter2=180;
	char dir=0;
	while(1){

		if(sweepbool){
			if (counter1==180) dir=0;
			else if (counter1==0) dir=1;
			if(dir){
				counter1++;
				counter2--;
			}
			else {
				counter1--;
				counter2++;
			}
			angle1=counter1;
			angle2=counter2;
		}

		servo_set(angle1,180);
		servo2_set(angle2,180);
		delay_ms(1);
	}
return 0;
}

