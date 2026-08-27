/*
 * === Basic.ino ===
 * @version 0.0.1
 * @author S. Shahriar
 * @date 2026-08-26
 * @license MIT
 * @copyright 2026 S. Shahriar <hi@shadowshahriar.dev>
 */

#include <SmoothLED.h>

SmoothLED led(3);

void setup()
{
	led.begin();
	led.play();
}

void loop()
{
	led.update();
}