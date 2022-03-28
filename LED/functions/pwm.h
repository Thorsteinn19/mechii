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

#define PWM_TOP (39999u)
#define SERVO_MIN (999u)
#define SERVO_MX (4999u)

void pwm1_init();
void pwm2_init();
void pwm3_init();
void pwm4_init();
void pwm5_init();
void pwm6_init();
void pwmall_init();
void servo_set(unsigned int deg, unsigned int max_deg);
void servo2_set(unsigned int deg,unsigned int max_deg);
#endif /* PWMSERVO_SERVO_H_ */
