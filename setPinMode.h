#include <avr/io.h>

void setPinMode(unsigned int PIN, unsigned char PORT, unsigned int mode){
	switch(PORT){
		case 'A':
		if(mode){
			DDRA |= (1 << PIN);
			} else {
			DDRA &= ~(1 << PIN);
			PORTA |= (1 << PIN);
		}
		break;
		case 'B':
		if(mode){
			DDRB |= (1 << PIN);
			} else {
			DDRB &= ~(1 << PIN);
			PORTB |= (1 << PIN);
		}
		case 'C':
		if(mode){
			DDRC |= (1 << PIN);
			} else {
			DDRC &= ~(1 << PIN);
			PORTC |= (1 << PIN);
		}
		break;
		case 'D':
		if(mode){
			DDRD |= (1 << PIN);
			} else {
			DDRD &= ~(1 << PIN);
			PORTD |= (1 << PIN);
		}
		break;
		default:
		break;
	}
}
