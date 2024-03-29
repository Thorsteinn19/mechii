/*
 * serial.c
 *
 *  Created on: 10 Feb 2022
 *      Author: stein
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include "drive.h"
#include "serial.h"
#include "delay.h"
#include "pwm.h"

volatile char cRx[10];
volatile int charcounter=0;
char serialin;


void Init_Uart(){
	UBRR0H=0;
	UBRR0L = 16;
	UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
	UCSR0C=(1<<USBS0)|(3<<UCSZ00);

	for(int i=0;i<10;i++){
		cRx[i]='0';
	}
	cRx[10]='\0';
}

char nibbletohexvalue( char nibblebyte){
	nibblebyte = nibblebyte & 0x0F;

	if((nibblebyte>=0)&&(nibblebyte<10)){
		return '0'+nibblebyte;
	}
	else if (( nibblebyte >= 10) && ( nibblebyte <= 15)){
		return 'A'+(nibblebyte-10);
	}
	return '-';
}

void printhexbyte(char inputchar){
	char temps[3];
	temps[0]='0';
	temps[1]='x';
	char ln=nibbletohexvalue(inputchar);
	char hn=nibbletohexvalue(inputchar>>4);
	temps[2]=hn;
	temps[3]=ln;

	for (int i=0;i<=3;i++){
	 char	printchar=temps[i];

	UDR0=printchar;
	delay_ms(1);
	}
}


void printint(int inputint){
	char upbyte=inputint>>8;
	char lowerbyte =inputint& 0xFF;
	char tempi[5];
	tempi[0]='0';
	tempi[1]='x';
	tempi[2]=nibbletohexvalue(upbyte>>4);
	tempi[3]=nibbletohexvalue(upbyte);
	tempi[4]=nibbletohexvalue(lowerbyte>>4);
	tempi[5]=nibbletohexvalue(lowerbyte);
	for (int i=0;i<=5;i++){
	 char	printchar=tempi[i];

	UDR0=printchar;
	delay_ms(1);
	}
}
void printlong(long inputlong){
	char byte1=inputlong&0xFF;
	char byte2=(inputlong>>8)&0xFF;
	char byte3=(inputlong>>16)&0xFF;
	char byte4=(inputlong>>24)&0xFF;
	char templ[9];
	templ[0]='0';
	templ[1]='x';
	templ[2]=nibbletohexvalue(byte4>>4);
	templ[3]=nibbletohexvalue(byte4);
	templ[4]=nibbletohexvalue(byte3>>4);
	templ[5]=nibbletohexvalue(byte3);
	templ[6]=nibbletohexvalue(byte2>>4);
	templ[7]=nibbletohexvalue(byte2);
	templ[8]=nibbletohexvalue(byte1>>4);
	templ[9]=nibbletohexvalue(byte1);
	for (int i=0;i<=9;i++){
	 char	printchar=templ[i];

	UDR0=printchar;
	delay_ms(1);
	}
}

void chartoascii(char data){
	int dataint= data;
	char asciichar;
	if((0<=data) &&(data<10)){
		asciichar=data+0x30;
		UDR0=asciichar;
	}
	else if((10<=data)&&(data<100)){
		int tens=(dataint/10);
		int single=dataint-10*tens;
		UDR0=0x30+tens;
		delay_ms(1);
		UDR0=0x30+single;
	}
	else if((100<=data) && (data<256)){
		char hundreds = dataint/100;
		char tens=(dataint-100*hundreds)/10;
		char single=data-100*hundreds-10*tens;
		UDR0=0x30+hundreds;
		delay_ms(1);
		UDR0=0x30+tens;
		delay_ms(1);
		UDR0=0x30+single;
	}
}
void floattoascii(float datain){
	char asciichar;
	if((0<=datain) &&(datain<10)){
		char single=datain;
		char tenth=(datain-single)*10;
		char hundreth=(datain-single-tenth/10.0)*100;
		asciichar=single+0x30;
		UDR0=asciichar;
		delay_ms(1);
		writestring(".");
		asciichar=tenth+0x30;
		UDR0=asciichar;
		delay_ms(1);
		asciichar=hundreth+0x30;
		UDR0=asciichar;
		delay_ms(1);
	}
	else if((10<=datain)&&(datain<100)){
		char tens=(datain/10);
		char single=datain-10*tens;
		char tenth=(datain-single-10*tens)*10;
//		char hundreth=(datain-single-10*tens-tenth/10.0)*100;
		UDR0=0x30+tens;
		delay_ms(1);
		UDR0=0x30+single;
		delay_ms(1);
		writestring(".");
		asciichar=tenth+0x30;
		UDR0=asciichar;
	}
	else if((100<=datain) && (datain<1000)){
		char hundreds = datain/100;
		char tens=(datain-100*hundreds)/10;
		char single=datain-100*hundreds-10*tens;
		UDR0=0x30+hundreds;
		delay_ms(1);
		UDR0=0x30+tens;
		delay_ms(1);
		UDR0=0x30+single;
	}
	else if((1000<=datain)&&(datain<10000)){
		char thousands= datain/1000;
		char hundreds=(datain-1000*thousands)/100;
		char tens=(datain-1000*thousands-100*hundreds)/10;
		char single=datain-1000*thousands-100*hundreds-10*tens;
		UDR0=0x30+thousands;
		delay_ms(1);
		UDR0=0x30+hundreds;
		delay_ms(1);
		UDR0=0x30+tens;
		delay_ms(1);
		UDR0=0x30+single;
	}
}



void writestring(char string[]){
	for(int i=0;string[i] !='\0';++i){
		UDR0=string[i];
		delay_ms(1);
	}
}

ISR(USART_RX_vect){

	cRx[charcounter]=UDR0;

	if (cRx[charcounter]=='\n' || charcounter>9){
		actionfunction(cRx);
		writestring(cRx);
		for(int i=0;i<10;i++){
			cRx[i]='0';
		}
		cRx[10]='\0';
		charcounter=0;
	}
	else charcounter++;

}






