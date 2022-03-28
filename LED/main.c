#include <avr/io.h>
#include <avr/interrupt.h>
#include "functions/delay.h"
#include "functions/pwm.h"

volatile char activate=0;

//When button is pressed this is event is triggered
ISR(INT1_vect){

	activate=1;


}

int main(){
	//Setting external interrupt 1
	pwm5_init();
	//Setting external interrupt 1 registry on ATmega328P
	EICRA|=(1<<ISC11);
	EIMSK|=(1<< INT1);
	//Enable interrupt
	sei();
	//Set servo to inital position
	servo_set(180,180);
	//infinite for loop
	for(;;){

	delay_ms(100);
	//when button is triggered ISR changes activate variable to 1 entering the if.
	if (activate==1){
		//Turns the spindle
		servo_set(0,180);
		delay_s(4);
		//Turns back
		servo_set(180,180);
		delay_s(3);
		//Resets activate variable
		activate=0;
	}
	}

return 0;
}
