/*
 * === EventListener.ino ===
 * @version 0.0.1
 * @author S. Shahriar
 * @date 2026-08-26
 * @license MIT
 * @copyright 2026 S. Shahriar <hi@shadowshahriar.dev>
 */

#include <SmoothLED.h>

SmoothLED led1(3);
SmoothLED led2(6);

void ledCycleFinished()
{
	Serial.println(F("LED cycle finished!"));
}

void ledAnimationFinished()
{
	Serial.println(F("LED animation completely finished!"));
}

void setup()
{
	Serial.begin(9600);
	led1.begin();
	led2.begin();

	led1.addEventListener(SmoothLED::ON_CYCLE, ledCycleFinished);
	led2.addEventListener(SmoothLED::ON_COMPLETE, ledAnimationFinished);

	led1.playOut(-1, 0, 2000);
	led2.play(3);
}

void loop()
{
	led1.update();
	led2.update();
}