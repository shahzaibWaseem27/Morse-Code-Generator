#include <avr/interrupt.h>

uint8_t buzzerBtnFlag = 0x00;
uint8_t ledBtnFlag = 0x00;




ISR(INT4_vect){
	PORTB = ~PORTB;
	_delay_ms(50);
}

ISR(INT5_vect){
	PORTC = ~PORTC;
	_delay_ms(50);
};





