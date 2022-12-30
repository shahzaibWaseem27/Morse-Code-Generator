/*
 * Morse Code Generator.c
 *
 * Created: 11/5/2022 11:37:19 AM
 * Author : Shahzaib Waseem
 */ 

/*
	we need to generate Morse code on an actuator from an English sentence using the atmega128
	
	e.g: "hello world" should generate morse code for the letter 'h', then for 'e', and so on
	
	we already have the Morse code representations for each letter, stored in an array
	
	Morse code has 3 kinds of outputs: a short beep, a long beep, and silence
	
	a dot means that an actuator is turned on and then off, with a specified delay
	
	a dash is similar to a dot except that its delay is 3 times longer than that of a dot
	
	silence corresponds to a space between words in the message
	
	each consecutive dot or dash of the same letter should have a delay equivalent to that of a dot
	
	to begin producing morse code of another letter, the actuator should not be activated for the duration equivalent to 3 times that of a dot
	
	to represent spacing between words, the actuator should not be activated for the duration equivalent to equivalent to 7 times that of a dot
	
	Pseudocode:
	
	LET currentCharacterMorseCode = ""
	LET morseCodes = [".-", "-...",    ....   ]
	LET msg = "hello world"
	
	FOR EACH x in msg, DO
		IF x NOT EQUALS EMPTY SPACE
			currentCharacterMorseCode = morseCodes[INDEX]
			LCD.display(x)
			FOR EACH y in currentCharacterMorseCode, DO
				IF y EQUALS DOT
					produceMorseCode(DOT)
				ELSE
					produceMorseCode(DASH)
				END IF
				DELAY BETWEEN EACH DOT OR DASH
			END OF LOOP
			LCD.CLEAR()
			DELAY BETWEEN EACH LETTER
		ELSE
			DELAY BETWEEN EACH WORD
		END IF
	END OF LOOP
	
*/


#define F_CPU 1000000UL
#include <avr/io.h>
#include "string.h"
#include "produceMorse.h"
#include "setPinMode.h"
#include "LCD.h"
#include "ISRs.h"

int main(void)
{
	char morseCodes[][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
	"--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	
	char currentCharacterMorseCode[5];
	
	char display[16];
	display[1] = ' ';
	display[2] = '-';
	display[3] = '>';
	display[4] = ' ';
	
   
	setPinMode(ACTUATOR1_PIN, ACTUATOR1_PORT, OUTPUT);
	setPinMode(ACTUATOR2_PIN, ACTUATOR2_PORT, OUTPUT);
	DDRE = 0x00;
	DDRB = 0xFF;
	DDRC = 0xFF;
	
	LCD_Init();
	
	EIMSK |= (1 << INT4);
	EIMSK |= (1 << INT5);

	EICRB |= (1 << ISC40) | (1 << ISC41);
	EICRB |= (1 << ISC50) | (1 << ISC51);

	sei();

	char msg[] = "me hungry";
	
	
	
    while (1) 
    {
		//traverse each character of the English message
		for(int i = 0; i < strlen(msg); i++){
			//if a character is not a space, get the morse code of the current character
			if(msg[i] != ' '){
				strcpy(currentCharacterMorseCode, morseCodes[(int) msg[i] - 97]);
				
				getLCDString(msg[i], currentCharacterMorseCode, display);
				
				LCD_String(display);
				//_delay_ms(2000);
				//traverse this morse code
				for(int j = 0; j < strlen(currentCharacterMorseCode); j++){
					if(currentCharacterMorseCode[j] == '.'){
						//if current character in the morse code is a dot, produce a dot morse code on the actuator
						
						produceMorseCode(DOT);
						
					} else {
						//else produce a dash morse code
					
						produceMorseCode(DASH);
						
					}
					_delay_ms(DELAY_BETWEEN_DOT_OR_DASH);
				}
				LCD_Clear();
				_delay_ms(DELAY_BETWEEN_LETTERS);
				
			} else {
				//else, keep the actuator low for the duration corresponding to a space between words
				//LCD_String("space");
				_delay_ms(DELAY_BETWEEN_WORDS);
				//LCD_Clear();
			}
    }
}
}