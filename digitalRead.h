#include <avr/io.h>

unsigned int digitalRead(unsigned int PIN, unsigned char PORT){
	switch(PORT){
		case 'A':
			switch(PIN){
				case 0:
					return PINA & (1 << PINA0);
					break;
				case 1:
					return PINA & (1 << PINA1);
					break;
				case 2:
					return PINA & (1 << PINA2);
					break;
				case 3:
					return PINA & (1 << PINA3);
					break;
				case 4:
					return PINA & (1 << PINA4);
					break;
				case 5:
					return PINA & (1 << PINA5);
					break;
				case 6:
					return PINA & (1 << PINA6);
					break;
				case 7:
					return PINA & (1 << PINA7);
					break;
				}
			break;
		case 'B':
			switch(PIN){
				case 0:
					return PINB & (1 << PINB0);
					break;
				case 1:
					return PINB & (1 << PINB1);
					break;
				case 2:
					return PINB & (1 << PINB2);
					break;
				case 3:
					return PINB & (1 << PINB3);
					break;
				case 4:
					return PINB & (1 << PINB4);
					break;
				case 5:
					return PINB & (1 << PINB5);
					break;
				case 6:
					return PINB & (1 << PINB6);
					break;
				case 7:
					return PINB & (1 << PINB7);
					break;
				}
			break;
		case 'C':
			switch(PIN){
				case 0:
					return PINC & (1 << PINC0);
					break;
				case 1:
					return PINC & (1 << PINC1);
					break;
				case 2:
					return PINC & (1 << PINC2);
					break;
				case 3:
					return PINC & (1 << PINC3);
					break;
				case 4:
					return PINC & (1 << PINC4);
					break;
				case 5:
					return PINC & (1 << PINC5);
					break;
				case 6:
					return PINC & (1 << PINC6);
					break;
				case 7:
					return PINC & (1 << PINC7);
					break;
				}
			break;
		case 'D':
			switch(PIN){
				case 0:
					return PIND & (1 << PIND0);
					break;
				case 1:
					return PIND & (1 << PIND1);
					break;
				case 2:
					return PIND & (1 << PIND2);
					break;
				case 3:
					return PIND & (1 << PIND3);
					break;
				case 4:
					return PIND & (1 << PIND4);
					break;
				case 5:
					return PIND & (1 << PIND5);
					break;
				case 6:
					return PIND & (1 << PIND6);
					break;
				case 7:
					return PIND & (1 << PIND7);
					break;
				}
			break;
		default:
		break;
	}
}
