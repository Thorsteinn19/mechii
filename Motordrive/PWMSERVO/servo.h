/*
 * servo.h
 *
 *  Created on: 10 Feb 2022
 *      Author: stein
 */

#ifndef PWMSERVO_SERVO_H_
#define PWMSERVO_SERVO_H_

extern volatile char servoduty1;
extern volatile char servoduty2;
extern char dccommand;

void servo1_init();
void servo2_init();

void setservocycle(char data);
char getcycle();
void setdccommand(char command);
#endif /* PWMSERVO_SERVO_H_ */
