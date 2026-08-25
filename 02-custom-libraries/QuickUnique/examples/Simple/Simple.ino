/*
 * === Simple.ino ===
 * @version 0.0.1
 * @author S. Shahriar
 * @date 2026-08-26
 * @license MIT
 * @copyright 2026 S. Shahriar <hi@shadowshahriar.dev>
 */

#include <QuickUnique.h>

// === Goal: print unique numbers from the range from 20 to 30 (inclusive) ===
QuickUnique uniqueInt(20, 30);

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	Serial.println(uniqueInt.next());
	delay(500);
}