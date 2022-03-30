/*
 * encoder.h
 *
 *  Created on: 3 Mar 2022
 *      Author: stein
 */

#ifndef ENCODER_H_
#define ENCODER_H_

extern char dir1;
extern char dir0;
extern long clockcount;
extern long clockcount1;
extern long movave[10];
extern long movave2[10];

void encoder1init();
void encoder0init();



#endif /* ENCODER_H_ */
