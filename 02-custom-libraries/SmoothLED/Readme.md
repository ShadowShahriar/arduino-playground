# SmoothLED

This library features a non-blocking approach to animate LED brightness with various effects to achieve buttery-smooth animations.

## Bare Minimum

```cpp
#include <SmoothLED.h>

SmoothLED led(3);

void setup()
{
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
