/*
 * === SmoothLED.h ===
 * @version 0.0.1
 * @author S. Shahriar
 * @date 2026-08-26
 * @license MIT
 * @copyright 2026 S. Shahriar <hi@shadowshahriar.dev>
 */

#ifndef SMOOTH_LED_H
#define SMOOTH_LED_H

#include <Arduino.h>

class SmoothLED
{
public:
	enum Effect
	{
		FADE_IN_OUT,
		PULSE,
		FADE_IN_THEN_OFF,
		ON_THEN_FADE_OUT,
		BREATHING
	};

	enum Easing
	{
		LINEAR,
		EASE_IN,
		EASE_OUT,
		EASE_IN_OUT,
		SINE
	};

	enum Event
	{
		ON_CYCLE,
		ON_COMPLETE
	};

	typedef void (*Callback)();

private:
	enum State
	{
		IDLE,
		FADING_IN,
		HOLDING,
		FADING_OUT
	};

	uint8_t _pin;
	uint8_t _brightness;
	Effect _effect;
	State _state;
	unsigned long _fadeInTime;
	unsigned long _fadeOutTime;
	unsigned long _holdTime;
	unsigned long _stateStart;

	bool _infinite;

	unsigned int _repeatCount;
	unsigned int _completedCycles;

	Easing _fadeInEasing;
	Easing _fadeOutEasing;

	Callback _onCycle;
	Callback _onComplete;

	void setOutput(uint8_t brightness);

	uint8_t calculateFadeIn(unsigned long elapsed, unsigned long duration);
	uint8_t calculateFadeOut(unsigned long elapsed, unsigned long duration);

	float applyEasing(float progress, Easing easing);

	void completeCycle(unsigned long now);

	void start(
		Effect effect,
		unsigned long fadeInTime = 1000,
		unsigned long fadeOutTime = 1000,
		unsigned long holdTime = 0,
		bool infinite = false,
		unsigned int repeatCount = 1,
		Easing fadeInEasing = EASE_IN_OUT,
		Easing fadeOutEasing = EASE_IN_OUT);

public:
	explicit SmoothLED(uint8_t pin);
	void begin();
	void update();
	void addEventListener(Event event, Callback cb);
	void removeEventListener(Event event);
	void play();
	void play(int loop);
	void play(
		int loop,
		unsigned long fadeInTime,
		unsigned long fadeOutTime);
	void play(
		int loop,
		Effect effect,
		unsigned long fadeInTime,
		unsigned long fadeOutTime);
	void play(
		int loop,
		Effect effect,
		unsigned long fadeInTime,
		unsigned long fadeOutTime,
		Easing fadeInEasing,
		Easing fadeOutEasing);
	void playOut(int loop, unsigned long holdTime, unsigned long fadeInTime);
	void stop();
	void on();
	void off();
	bool isRunning() const;
};
#endif