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
