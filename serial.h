#ifndef SERIAL_H_
#define SERIAL_H_
#define F_CPU 16000000
#define BAUDRATE 38400
#define UBRR (F_CPU/16/BAUDRATE-1)

void uart_init(void);

void UART_TxString(char text[]);

void UART_TxChar(char data);

#endif

