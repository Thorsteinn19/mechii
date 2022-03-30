/*
 * drive.h
 *
 *  Created on: 17 Mar 2022
 *      Author: stein
 */

#ifndef DRIVE_H_
#define DRIVE_H_


extern volatile char sweepbool;
extern volatile unsigned int angle1;
extern volatile unsigned int angle2;
void actionfunction(char chararray[]);
long averagefunc(long valuelist[10]);



#endif /* DRIVE_H_ */
