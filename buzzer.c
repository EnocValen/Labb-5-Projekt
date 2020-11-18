#include <avr/io.h>
#include <util/delay.h>

#include "buzzer.h"
#include "serial.h"


void buzzer_init() 
{
    DDRD |= (1 << DDD6); //pin 6 for output
    TCCR0B = (1 << CS02); //prescaler 256
    TCCR0A = (1 << COM0A0) | (1 << WGM01); // toggle, CTC
    OCR0A = 0;
}


void loopCycle(int distance)
{


        if (distance < 20) {
            OCR0A = 70; //Lägger data till det för att få ett ljud
            char val[4];
            itoa(distance, val, 10); // makes int to char array
            UART_TxString(val); //send the char array to uart
            UART_TxString(" cm.\r\n");

        }
        else if ((distance >= 21) && (distance <= 30)) {
            OCR0A = 70;
            _delay_ms(50);
            OCR0A = 0; //stänger av ljuder
            _delay_ms(50);
            char val[4];
            itoa(distance, val, 10); 
            UART_TxString(val);
            UART_TxString(" cm.\r\n");
        }
        else if ((distance >= 31) && (distance <= 50)) {
            OCR0A = 70;
            _delay_ms(100);
            OCR0A = 0;
            _delay_ms(100);
            char val[4];
            itoa(distance, val, 10);
            UART_TxString(val);
            UART_TxString(" cm.\r\n");
        }
        else if ((distance >= 51) && (distance <= 70)) {
            OCR0A = 70;
            _delay_ms(150);
            OCR0A = 0;
            _delay_ms(150);
            char val[4];
            itoa(distance, val, 10);
            UART_TxString(val);
            UART_TxString(" cm.\r\n");
        }
        else if ((distance >= 71) && (distance <= 95)) {
            OCR0A = 70;
            _delay_ms(200);
            OCR0A = 0;
            _delay_ms(200);
            char val[4];
            itoa(distance, val, 10);
            UART_TxString(val);
            UART_TxString(" cm.\r\n");
        }
        else if ((distance >= 96) && (distance <= 125)) {
            OCR0A = 70;
            _delay_ms(300);
            OCR0A = 0;
            _delay_ms(300);
            char val[4];
            itoa(distance, val, 10);
            UART_TxString(val);
            UART_TxString(" cm.\r\n");
        }
        else {
            OCR0A = 0;
        }
    
}


