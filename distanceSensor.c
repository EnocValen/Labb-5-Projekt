#include <avr/io.h>
#include <util/delay.h>

#include "distanceSensor.h"

int distance;
long time;

void distanceSensor_init() {
	DDRB |= (1 << 0); //make the trigger in the distance sensor as output
	DDRB &= ~(1 << 1);//make the echo in the distance sensor as input

	PORTB &= ~((1 << 0) | (1 << 1)); //dont activate the trigger or ecco yet

	TCCR1A = 0x00; // reset the control register
	TCCR1B |= (1 << CS11); //Prescaler 8;
}

 int distStart() {
	PORTB |= (1 << 0) | (1 << 1);//start trigger, lets echo be ready
	_delay_us(10);//trigger needs 10 microseconds to send the right amount of soundwaves
	PORTB &= ~(1 << 0); //turns off trigger

	while ((PINB & (1 << 1)) == 0); // While echo is not active stay in loop
	TCNT1 = 0; // as soon as echo activates start counting
	while (PINB & (1 << 1));// While echo is still active, stay in loop
	time = TCNT1 * 0.5; // ((prescaler/F_CPU)*1000000) gets med 0,5
	distance = time / 58.0;// time divided by 58 gets me the result in centrimeters

	return distance;
}