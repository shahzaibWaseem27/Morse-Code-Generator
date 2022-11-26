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
			LCD.DISPLAY(x)
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


int main(void)
{
	char morseCodes[][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
	"--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	
	char currentCharacterMorseCode[5];
   
	setPinMode(ACTUATOR_PIN, ACTUATOR_PORT, OUTPUT);
	setPinMode(2, 'C', INPUT);
	
	LCD_Init();
	

	char msg[] = "hello world";
	
    while (1) 
    {
		//traverse each character of the English message
		for(int i = 0; i < strlen(msg); i++){
			//if a character is not a space, get the morse code of the current character
			if(msg[i] != ' '){
				strcpy(currentCharacterMorseCode, morseCodes[(int) msg[i] - 97]);
				LCD_Char(msg[i]);
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
				
				_delay_ms(DELAY_BETWEEN_WORDS);
			}
    }
}
}
