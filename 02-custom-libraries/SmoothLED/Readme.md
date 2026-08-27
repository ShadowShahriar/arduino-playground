# SmoothLED

This library features a non-blocking approach to animate LED brightness with various effects to achieve buttery-smooth animations.

## Bare Minimum

```cpp
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
```

## Two LEDs

```cpp
#include <SmoothLED.h>

SmoothLED led1(3);
SmoothLED led2(6);

void setup()
{
	led1.begin();
	led2.begin();

	led1.play(
		-1,
		SmoothLED::BREATHING,
		5000,
		1000,
		SmoothLED::SINE,
		SmoothLED::EASE_OUT
	);

	led2.play(
		-1,
		SmoothLED::BREATHING,
		1200,
		200,
		SmoothLED::EASE_IN_OUT,
		SmoothLED::EASE_OUT
	);
}

void loop()
{
	led1.update();
	led2.update();
}
```

## Event Listeners

```cpp
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
```

## Presets

```cpp
#include <SmoothLED.h>

SmoothLED led(3);

void setup()
{
	// === Uncomment one of them to play the preset animation ===
	led.playPreset(SmoothLED::ALIVE);
	// led.playPreset(SmoothLED::PROCESSING);
	// led.playPreset(SmoothLED::WARNING);
	// led.playPreset(SmoothLED::ERROR);
	// led.playPreset(SmoothLED::SUCCESS);
	// led.playPreset(SmoothLED::POWERDOWN);
	// led.playPreset(SmoothLED::AMBIENT);
	// led.playPreset(SmoothLED::POWERUP);
	// led.playPreset(SmoothLED::CHOKE);
	// led.playPreset(SmoothLED::PULSEIN);
	// led.playPreset(SmoothLED::PULSEOUT);
	// led.playPreset(SmoothLED::SLOWPULSE);
	// led.playPreset(SmoothLED::RAPIDPULSE);
	// led.playPreset(SmoothLED::DEEPBREATHE);
	// led.playPreset(SmoothLED::GLOW);
	// led.playPreset(SmoothLED::METEOR);
	// led.playPreset(SmoothLED::STRONGLIGHTNING);
	// led.playPreset(SmoothLED::FASTLIGHTNING);
	// led.playPreset(SmoothLED::SUNSET);
	// led.playPreset(SmoothLED::SUNRISE);
	// led.playPreset(SmoothLED::NOTIFY);
	// led.playPreset(SmoothLED::THINKING);
	// led.playPreset(SmoothLED::LOADING);
	// led.playPreset(SmoothLED::HEARTBEAT);
}

void loop()
{
	led.update();
}
```
