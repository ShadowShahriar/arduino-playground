/*
 * === Breathing.ino ===
 * @version 0.0.1
 * @author S. Shahriar
 * @date 2026-08-26
 * @license MIT
 * @copyright 2026 S. Shahriar <hi@shadowshahriar.dev>
 */

#include <SmoothLED.h>

SmoothLED led1(3);
SmoothLED led2(6);

void setup()
{
	led1.begin();
	led2.begin();

	led1.play(-1, SmoothLED::BREATHING, 5000, 1000, SmoothLED::SINE, SmoothLED::EASE_OUT);
	led2.play(-1, SmoothLED::BREATHING, 1200, 200, SmoothLED::EASE_IN_OUT, SmoothLED::EASE_OUT);
}

void loop()
{
	led1.update();
	led2.update();
}