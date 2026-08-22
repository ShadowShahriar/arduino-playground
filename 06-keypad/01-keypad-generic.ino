#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
byte rowPins[ROWS] = {6, 7, 8, 9};
byte colPins[COLS] = {2, 3, 4, 5};
char keys[ROWS][COLS] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	char key = keypad.getKey();
	if (key)
		Serial.println(key);
}
