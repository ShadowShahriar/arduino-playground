// #include <SmoothLED.h>

// SmoothLED led1(3);
// // SmoothLED led2(6);

// void setup()
// {
// 	led1.begin();
// 	// led2.begin();

// 	led1.play(SmoothLED::FADE_IN_THEN_OFF, 2000, 0, 0, false, 3, SmoothLED::LINEAR, SmoothLED::EASE_OUT);
// 	// led1.play(SmoothLED::ON_THEN_FADE_OUT, 2000, 0, 5000, false, 3, SmoothLED::LINEAR, SmoothLED::EASE_OUT);
// 	// led2.play(SmoothLED::PULSE, 800, 1500, 0, true, 1, SmoothLED::EASE_OUT, SmoothLED::EASE_IN_OUT);
// }

// void loop()
// {
// 	led1.update();
// 	// led2.update();
// }

#include <SmoothLED.h>

SmoothLED led1(3);
SmoothLED led2(6);

void ledCycleFinished()
{
	Serial.println("LED cycle finished!");
}

void ledAnimationFinished()
{
	Serial.println("LED animation completely finished!");
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
	// led1.play(SmoothLED::ON_THEN_FADE_OUT, 2000, 0, 5000, false, 3, SmoothLED::LINEAR, SmoothLED::EASE_OUT);
	// led2.play(SmoothLED::PULSE, 800, 1500, 0, true, 1, SmoothLED::EASE_OUT, SmoothLED::EASE_IN_OUT);
}

void loop()
{
	led1.update();
	led2.update();
}