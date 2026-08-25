# AdvancedInterval

This library abstracts the non-blocking interval logic using `millis()` and provides callback functions for interval events such as start, stop, pause, resume, and reset.

```cpp
enum AdvancedIntervalEvent
{
	INTERVAL_TRIGGER, // === Fires every time the interval duration passes ===
	INTERVAL_START,	  // === Fires when start() is called ===
	INTERVAL_STOP,	  // === Fires when stop() is called ===
	INTERVAL_PAUSE,	  // === Fires when pause() is called ===
	INTERVAL_RESUME,  // === Fires when resume() is called ===
	INTERVAL_RESET,	  // === Fires when reset() is called ===
	INTERVAL_COMPLETE // === Fires when the max run count is reached ===
};
```

## Basic Usage

```cpp
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
```

## Eventful Example

```cpp
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
```
