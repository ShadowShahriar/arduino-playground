/*
 * === Basic.ino ===
 * @version 0.0.1
 * @author S. Shahriar
 * @date 2026-08-26
 * @license MIT
 * @copyright 2026 S. Shahriar <hi@shadowshahriar.dev>
 */

#include <AdvancedInterval.h>

// === Create a timer that ticks every 1 second forever ===
AdvancedInterval basicTimer(1000);

void onTrigger()
{
	Serial.print(F("-> Tick! Run count is: "));
	Serial.println(basicTimer.getRunCount());
}

void setup()
{
	Serial.begin(9600);
	basicTimer.addEventListener(INTERVAL_TRIGGER, onTrigger);
	basicTimer.start();
}

void loop()
{
	basicTimer.update();
}