#include "digitalRead.h"
#include "digitalWrite.h"
#include <util/delay.h>

#define HIGH 1
#define LOW 0
#define INPUT 0
#define OUTPUT 1
#define DOT '.'
#define DASH '-'
#define ACTUATOR1_PIN 0
#define ACTUATOR1_PORT 'A'
#define ACTUATOR2_PIN 1
#define ACTUATOR2_PORT 'A'

#define DOT_DURATION 6000
#define DASH_DURATION 3*DOT_DURATION
#define DELAY_BETWEEN_DOT_OR_DASH DOT_DURATION
#define DELAY_BETWEEN_LETTERS DASH_DURATION
#define DELAY_BETWEEN_WORDS 5*DOT_DURATION


void produceMorseCode(unsigned char outputType){
	
	digitalWrite(ACTUATOR1_PIN, ACTUATOR1_PORT, HIGH);
	digitalWrite(ACTUATOR2_PIN, ACTUATOR2_PORT, HIGH);
	switch(outputType){
		case DOT:
			_delay_ms(DOT_DURATION);
			break;
		case DASH:
			_delay_ms(DASH_DURATION);
			break;
	}
	digitalWrite(ACTUATOR1_PIN, ACTUATOR1_PORT, LOW);
	digitalWrite(ACTUATOR2_PIN, ACTUATOR2_PORT, LOW);
	
}
