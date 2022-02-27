/*
 * servo.h
 *
 *  Created on: 10 Feb 2022
 *      Author: stein
 */

#ifndef PWMSERVO_SERVO_H_
#define PWMSERVO_SERVO_H_

extern volatile char pwmduty1;
extern volatile char pwmduty2;
extern volatile char pwmduty3;
extern volatile char pwmduty4;
extern volatile char pwmduty5;
extern volatile char pwmduty6;


void pwm1_init();
void pwm2_init();
void pwm3_init();
void pwm4_init();
void pwm5_init();
void pwm6_init();
void pwmall_init();

#endif /* PWMSERVO_SERVO_H_ */
