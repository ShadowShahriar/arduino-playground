/*
 * === SetRange.ino ===
 * @version 0.0.1
 * @author S. Shahriar
 * @date 2026-08-26
 * @license MIT
 * @copyright 2026 S. Shahriar <hi@shadowshahriar.dev>
 */

#include <QuickUnique.h>
QuickUnique uniqueInt(1, 10);

void setup()
{
	Serial.begin(9600);

	Serial.println(F("--- Small Range Unqiue Numbers (1 to 10) ---"));
	for (int i = 0; i < 10; i++)
	{
		Serial.println(uniqueInt.next());
		delay(500);
	}

	Serial.println(F("--- Changing Range Now (128 to 1024) ---"));

	// === Changing the range dynamically ===
	uniqueInt.setRange(128, 1024);
}

void loop()
{
	Serial.println(uniqueInt.next());
	delay(500);
}