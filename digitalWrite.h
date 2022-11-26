#include <avr/io.h>

void digitalWrite(unsigned int PIN, unsigned char PORT, unsigned int mode){
	switch(PORT){
		case 'A':
		if(mode){
			PORTA |= (1 << PIN);
			} else {
			PORTA &= ~(1 << PIN);
		}
		break;
		case 'B':
		if(mode){
			PORTB |= (1 << PIN);
			} else {
			PORTB &= ~(1 << PIN);
		}
		case 'C':
		if(mode){
			PORTC |= (1 << PIN);
			} else {
			PORTC &= ~(1 << PIN);
		}
		break;
		case 'D':
		if(mode){
			PORTD |= (1 << PIN);
			} else {
			PORTD &= ~(1 << PIN);
		}
		break;
		default:
		break;
	}
}

