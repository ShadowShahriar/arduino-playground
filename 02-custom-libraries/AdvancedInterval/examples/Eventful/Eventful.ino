/*
 * === Eventful.ino ===
 * @version 0.0.1
 * @author S. Shahriar
 * @date 2026-08-26
 * @license MIT
 * @copyright 2026 S. Shahriar <hi@shadowshahriar.dev>
 */

#include <AdvancedInterval.h>

// === Create a timer that ticks every 1 second and stops after 10 ticks ===
AdvancedInterval basicTimer(1000, 10);

void onTrigger()
{
	Serial.print(F("-> Tick! Run count is: "));
	Serial.println(basicTimer.getRunCount());
}

void onStart()
{
	Serial.println(F("[Event] Timer Started!"));
}

void onPause()
{
	Serial.println(F("[Event] Timer Paused!"));
}

void onResume()
{
	Serial.println(F("[Event] Timer Resumed!"));
}

void onStop()
{
	Serial.println(F("[Event] Timer Stopped!"));
}

void onReset()
{
	Serial.println(F("[Event] Runs Reset!"));
}

void onComplete()
{
	Serial.println(F("[Event] Max runs reached! Timer Finished."));
}

void setup()
{
	Serial.begin(9600);

	basicTimer.addEventListener(INTERVAL_TRIGGER, onTrigger);
	basicTimer.addEventListener(INTERVAL_START, onStart);
	basicTimer.addEventListener(INTERVAL_PAUSE, onPause);
	basicTimer.addEventListener(INTERVAL_RESUME, onResume);
	basicTimer.addEventListener(INTERVAL_STOP, onStop);
	basicTimer.addEventListener(INTERVAL_RESET, onReset);
	basicTimer.addEventListener(INTERVAL_COMPLETE, onComplete);

	basicTimer.start();
}

void loop()
{
	basicTimer.update();

	// === Test the events by sending characters via Serial Monitor ===
	if (Serial.available() > 0)
	{
		char command = Serial.read();
		if (command == 'p')
			basicTimer.pause();
		if (command == 'r')
			basicTimer.resume();
		if (command == 's')
			basicTimer.start(); // === Restarts and resets count ===
		if (command == 'x')
			basicTimer.stop(); // === Stops completely ===
		if (command == '0')
			basicTimer.reset(); // === Clears count without stopping ===
	}
}
