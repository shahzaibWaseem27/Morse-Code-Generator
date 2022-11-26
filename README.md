# Morse-Code-Generator
Microcontroller project B.Eng. Electronics Engineering at HSHL
 


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
	
