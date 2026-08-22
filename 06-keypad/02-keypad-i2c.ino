#include <Wire.h>
#include <I2CKeyPad.h>

const uint8_t KEYPAD_ADDRESS = 0x20;
I2CKeyPad keypad(KEYPAD_ADDRESS);

char keymap[16] = {
	'1', '2', '3', 'A',
	'4', '5', '6', 'B',
	'7', '8', '9', 'C',
	'*', '0', '#', 'D'};

unsigned long lastKeyPressTime = 0;
const unsigned long debounceDelay = 250;
bool keyReleased = true;

void setup()
{
	Serial.begin(9600);
	Wire.begin();

	if (keypad.begin())
	{
		Serial.println(F("✅ I2C Keypad active."));
	}
	else
	{
		Serial.println(F("⛔ I2C Keypad error."));
		while (1)
			;
	}
}

void loop()
{
	unsigned long currentTime = millis();
	if (keypad.isPressed())
	{
		if ((currentTime - lastKeyPressTime >= debounceDelay) && keyReleased)
		{
			uint8_t index = keypad.getKey();
			char key = keymap[index];
			Serial.println(key);
			lastKeyPressTime = currentTime;
			keyReleased = false;
		}
	}
	else
	{
		keyReleased = true;
	}
}
