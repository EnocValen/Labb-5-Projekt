#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include <stdint.h>

#include "distanceSensor.h"
#include "serial.h"
#include "buzzer.h"

int main() {

	uart_init();
	buzzer_init();
	distanceSensor_init();
	
	char val[4];

	while (1) {

		if (distStart() < 125) { // if distance under 125 cm send to buzzer function
			loopCycle(distStart());
		}

		itoa(distStart(), val, 10); //tar int som skickas från funktionen och gör den till en char array
		UART_TxString(val);
		UART_TxString(" cm.\r\n");

	}
	return 0;
}
