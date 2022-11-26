# Morse-Code-Generator
Microcontroller project B.Eng. Electronics Engineering at HSHL
 


*we need to generate Morse code on an actuator from an English sentence using the atmega128

*e.g: "hello world" should generate morse code for the letter 'h', then for 'e', and so on

*we already have the Morse code representations for each letter, stored in an array

*Morse code has 3 kinds of outputs: a short beep, a long beep, and silence

*a dot means that an actuator is turned on and then off, with a specified delay

*a dash is similar to a dot except that its delay is 3 times longer than that of a dot

*silence corresponds to a space between words in the message

*each consecutive dot or dash of the same letter should have a delay equivalent to that of a dot

*to begin producing morse code of another letter, the actuator should not be activated for the duration equivalent to 3 times that of a dot

*to represent spacing between words, the actuator should not be activated for the duration equivalent to equivalent to 7 times that of a dot

Pseudocode:<br />
<br />
LET currentCharacterMorseCode = ""<br />
LET morseCodes = [".-", "-...",    ....   ]<br />
LET msg = "hello world"<br />
<br />
FOR EACH x in msg, DO<br />
	IF x NOT EQUALS EMPTY SPACE<br />
		currentCharacterMorseCode = morseCodes[INDEX]<br />
		LCD.DISPLAY(x)<br />
		FOR EACH y in currentCharacterMorseCode, DO<br />
			IF y EQUALS DOT<br />
				produceMorseCode(DOT)<br />
			ELSE<br />
				produceMorseCode(DASH)<br />
			END IF<br />
			DELAY BETWEEN EACH DOT OR DASH<br />
		END OF LOOP<br />
		LCD.CLEAR()<br />
		DELAY BETWEEN EACH LETTER<br />
	ELSE<br />
		DELAY BETWEEN EACH WORD<br />
	END IF<br />
END OF LOOP<br />
	
