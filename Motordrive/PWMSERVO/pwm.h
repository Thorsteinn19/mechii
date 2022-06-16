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

// Period of servo signal 20.000 microseconds
#define PWM_TOP (39999u)
// Minimum on time for servo 500 microseconds
#define SERVO_MIN (999u)
// Maximum on time for servo 2500 microseconds
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
void pwm1off();
void pwm2off();
void pwm3off();
void pwm4off();
void pwm1on();
void pwm2on();
void pwm3on();
void pwm4on();
void pwmalloff();
#endif /* PWMSERVO_SERVO_H_ */
