/*
 * === Fade.ino ===
 * @version 0.0.1
 * @author S. Shahriar
 * @date 2026-08-28
 * @license MIT
 * @copyright 2026 S. Shahriar <hi@shadowshahriar.dev>
 */

#include <SmoothLED.h>

SmoothLED led(2);

void setup()
{
	Serial.begin(9600);
	led.playPreset(SmoothLED::ALIVE);
}

void loop()
{
	led.update();

	if (Serial.available() > 0)
	{
		char command = Serial.read();
		if (command == 'p')
		{
			led.playPreset(SmoothLED::ALIVE);
			Serial.println(F("Playing preset."));
		}
		if (command == 'i')
		{
			led.fadeIn(1000);
			Serial.println(F("Fading in."));
		}
		if (command == 'o')
		{
			led.fadeOut(1000);
			Serial.println(F("Fading out."));
		}
	}
}