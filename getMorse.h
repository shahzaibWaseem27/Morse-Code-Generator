#include "string.h"

char msgMorseCode[100];


void getMsgMorseCode(char *msg){
	char morseCodes[][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
	"--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	char currentCharacterMorseCode[4];
	int i = 0;
	while(*(msg + i) != '\0'){
		if(*(msg + i) != ' '){
			strcpy(currentCharacterMorseCode, morseCodes[(int) *(msg + i) - 97]);
			strcat(msgMorseCode, currentCharacterMorseCode);
		} else strcat(msgMorseCode, "/");
		strcat(msgMorseCode, " ");
		i++;
	}
	
}