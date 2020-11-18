#include <avr/io.h>

#include <stdio.h>

#include "serial.h"

void uart_init(void) {
	UBRR0H = (unsigned char)(UBRR >> 8);
	UBRR0L = (unsigned char)(UBRR);
	UCSR0A = 0;
	UCSR0B = (1 << TXEN0 | 1 << RXEN0);
	UCSR0C = (1 << UCSZ01 | 1 << UCSZ00);

}

void UART_TxChar(char data) {
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

void UART_TxString(char text[]) {
	int i = 0;

	while (i < 255) {
		if (text[i] == '\0') break;
		UART_TxChar(text[i]);
		i++;
	}
}
