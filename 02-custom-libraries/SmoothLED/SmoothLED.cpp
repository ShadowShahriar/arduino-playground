/*
 * === SmoothLED.cpp ===
 * @version 0.0.1
 * @author S. Shahriar
 * @date 2026-08-26
 * @license MIT
 * @copyright 2026 S. Shahriar <hi@shadowshahriar.dev>
 */

#include "SmoothLED.h"
#include <math.h>

SmoothLED::SmoothLED(uint8_t pin)
	: _pin(pin),
	  _brightness(0),
	  _effect(FADE_IN_OUT),
	  _state(IDLE),
	  _fadeInTime(1000),
	  _fadeOutTime(1000),
	  _holdTime(0),
	  _stateStart(0),
	  _infinite(false),
	  _repeatCount(1),
	  _completedCycles(0),
	  _fadeInEasing(EASE_IN_OUT),
	  _fadeOutEasing(EASE_IN_OUT),
	  _onCycle(nullptr),
	  _onComplete(nullptr)
{
}

void SmoothLED::begin()
{
	pinMode(_pin, OUTPUT);
	setOutput(0);
}

void SmoothLED::addEventListener(Event event, Callback cb)
{
	if (event == ON_CYCLE)
		_onCycle = cb;
	else if (event == ON_COMPLETE)
		_onComplete = cb;
}

void SmoothLED::removeEventListener(Event event)
{
	if (event == ON_CYCLE)
		_onCycle = nullptr;
	else if (event == ON_COMPLETE)
		_onComplete = nullptr;
};

void SmoothLED::update()
{
	if (_state == IDLE)
		return;

	unsigned long now = millis();
	unsigned long elapsed = now - _stateStart;

	switch (_state)
	{
	case FADING_IN:
	{
		uint8_t brightness = calculateFadeIn(elapsed, _fadeInTime);
		setOutput(brightness);
		if (elapsed >= _fadeInTime)
		{
			setOutput(255);
			switch (_effect)
			{
			case FADE_IN_OUT:
			case PULSE:
			case BREATHING:
				_state = FADING_OUT;
				_stateStart = now;
				break;
			case FADE_IN_THEN_OFF:
				completeCycle(now);
				break;
			case ON_THEN_FADE_OUT:
				_state = _holdTime == 0 ? FADING_OUT : HOLDING;
				_stateStart = now;
				break;
			}
		}
		break;
	}

	case HOLDING:
	{
		setOutput(255);
		if (elapsed >= _holdTime)
		{
			_state = FADING_OUT;
			_stateStart = now;
		}
		break;
	}

	case FADING_OUT:
	{
		uint8_t brightness = calculateFadeOut(elapsed, _fadeOutTime);
		setOutput(brightness);
		if (elapsed >= _fadeOutTime)
		{
			setOutput(0);
			completeCycle(now);
		}
		break;
	}

	case IDLE:
	default:
		break;
	}
}

void SmoothLED::start(
	Effect effect,
	unsigned long fadeInTime,
	unsigned long fadeOutTime,
	unsigned long holdTime,
	bool infinite,
	unsigned int repeatCount,
	Easing fadeInEasing,
	Easing fadeOutEasing)
{
	_effect = effect;
	_fadeInTime = fadeInTime;
	_fadeOutTime = fadeOutTime;
	_holdTime = holdTime;
	_infinite = infinite;
	_repeatCount = repeatCount;
	_completedCycles = 0;
	_fadeInEasing = fadeInEasing;
	_fadeOutEasing = fadeOutEasing;

	// ! === Prevent accidental zero repetitions ===
	if (!_infinite && _repeatCount == 0)
		_repeatCount = 1;

	if (_effect == FADE_IN_THEN_OFF)
	{
		setOutput(0);
		_state = FADING_IN;
		_stateStart = millis();
		return;
	}

	if (_effect == ON_THEN_FADE_OUT)
	{
		setOutput(255);
		_stateStart = millis();
		if (_holdTime > 0)
			_state = HOLDING;
		else
			_state = FADING_OUT;
		return;
	}

	setOutput(0);
	_state = FADING_IN;
	_stateStart = millis();
}

void SmoothLED::play()
{
	start(SmoothLED::PULSE, 800, 1500, 0, true, 1, SmoothLED::EASE_OUT, SmoothLED::EASE_IN_OUT);
}

void SmoothLED::play(int loop)
{
	int infinite = (loop == -1) ? true : false;
	int count = (loop > 0) ? loop : 1;
	start(SmoothLED::PULSE, 800, 1500, 0, infinite, count, SmoothLED::EASE_OUT, SmoothLED::EASE_IN_OUT);
}

void SmoothLED::play(
	int loop,
	unsigned long fadeInTime,
	unsigned long fadeOutTime)
{
	int infinite = (loop == -1) ? true : false;
	int count = (loop > 0) ? loop : 1;
	start(SmoothLED::PULSE, fadeInTime, fadeOutTime, 0, infinite, count, SmoothLED::EASE_OUT, SmoothLED::EASE_IN_OUT);
}

void SmoothLED::play(
	int loop,
	Effect effect,
	unsigned long fadeInTime,
	unsigned long fadeOutTime)
{
	int infinite = (loop == -1) ? true : false;
	int count = (loop > 0) ? loop : 1;
	start(effect, fadeInTime, fadeOutTime, 0, infinite, count, SmoothLED::LINEAR, SmoothLED::LINEAR);
}

void SmoothLED::play(
	int loop,
	Effect effect,
	unsigned long fadeInTime,
	unsigned long fadeOutTime,
	Easing fadeInEasing,
	Easing fadeOutEasing)
{
	int infinite = (loop == -1) ? true : false;
	int count = (loop > 0) ? loop : 1;
	start(effect, fadeInTime, fadeOutTime, 0, infinite, count, fadeInEasing, fadeOutEasing);
}

void SmoothLED::playOut(int loop, unsigned long holdTime, unsigned long fadeInTime)
{
	int infinite = (loop == -1) ? true : false;
	int count = (loop > 0) ? loop : 1;
	start(SmoothLED::ON_THEN_FADE_OUT, fadeInTime, 0, holdTime, infinite, count, SmoothLED::LINEAR, SmoothLED::LINEAR);
}

void SmoothLED::completeCycle(unsigned long now)
{
	_completedCycles++;
	if (_onCycle != nullptr)
		_onCycle();

	if (_infinite)
	{
		setOutput(0);
		_state = FADING_IN;
		_stateStart = now;
		return;
	}

	if (_completedCycles >= _repeatCount)
	{
		setOutput(0);
		_state = IDLE;

		if (_onComplete != nullptr)
			_onComplete();
		return;
	}

	setOutput(0);
	_state = FADING_IN;
	_stateStart = now;
}

void SmoothLED::stop()
{
	_state = IDLE;
	setOutput(0);
}

void SmoothLED::off()
{
	_state = IDLE;
	setOutput(0);
}

void SmoothLED::on()
{
	_state = IDLE;
	setOutput(255);
}

bool SmoothLED::isRunning() const
{
	return _state != IDLE;
}

void SmoothLED::setOutput(uint8_t brightness)
{
	_brightness = brightness;
	analogWrite(_pin, _brightness);
}

uint8_t SmoothLED::calculateFadeIn(unsigned long elapsed, unsigned long duration)
{
	if (duration == 0)
		return 255;
	if (elapsed >= duration)
		return 255;

	float progress = (float)elapsed / (float)duration;
	progress = applyEasing(progress, _fadeInEasing);
	return (uint8_t)(progress * 255.0f);
}

uint8_t SmoothLED::calculateFadeOut(unsigned long elapsed, unsigned long duration)
{
	if (duration == 0)
		return 0;
	if (elapsed >= duration)
		return 0;

	float progress = (float)elapsed / (float)duration;
	progress = applyEasing(progress, _fadeOutEasing);

	float brightness = 1.0f - progress;
	return (uint8_t)(brightness * 255.0f);
}

float SmoothLED::applyEasing(float progress, Easing easing)
{
	if (progress < 0.0f)
		progress = 0.0f;
	if (progress > 1.0f)
		progress = 1.0f;

	switch (easing)
	{
	case LINEAR:
		return progress;
	case SINE:
		return -(cos(progress * PI) - 1.0f) / 2.0f;
	case EASE_IN:
		return progress * progress;
	case EASE_OUT:
	{
		float inverse = 1.0f - progress;
		return 1.0f - (inverse * inverse);
	}
	case EASE_IN_OUT:
		if (progress < 0.5f)
		{
			return 2.0f * progress * progress;
		}
		else
		{
			float inverse = -2.0f * progress + 2.0f;
			return 1.0f - (inverse * inverse) / 2.0f;
		}
	default:
		return progress;
	}
}

void SmoothLED::playPreset(Preset preset)
{
	if (preset == ALIVE)
		start(SmoothLED::BREATHING, 3000, 700, 0, true, 1, SmoothLED::SINE, SmoothLED::EASE_OUT);
	else if (preset == PROCESSING)
		start(SmoothLED::PULSE, 1200, 1200, 0, true, 1, SmoothLED::SINE, SmoothLED::SINE);
	else if (preset == WARNING)
		start(SmoothLED::FADE_IN_OUT, 100, 100, 100, false, 3, SmoothLED::EASE_OUT, SmoothLED::EASE_IN);
	else if (preset == ERROR)
		start(SmoothLED::FADE_IN_OUT, 40, 40, 50, false, 5, SmoothLED::LINEAR, SmoothLED::LINEAR);
	else if (preset == SUCCESS)
		start(SmoothLED::FADE_IN_OUT, 400, 1200, 200, false, 1, SmoothLED::SINE, SmoothLED::SINE);
	else if (preset == POWERDOWN)
		start(SmoothLED::ON_THEN_FADE_OUT, 0, 3000, 1000, false, 1, SmoothLED::LINEAR, SmoothLED::SINE);
	else if (preset == AMBIENT)
		start(SmoothLED::BREATHING, 7000, 1500, 0, true, 1, SmoothLED::SINE, SmoothLED::SINE);
	else if (preset == POWERUP)
		start(SmoothLED::ON_THEN_FADE_OUT, 0, 2000, 3000, false, 1, SmoothLED::LINEAR, SmoothLED::SINE);
	else if (preset == CHOKE)
		start(SmoothLED::BREATHING, 5000, 250, 0, true, 1, SmoothLED::SINE, SmoothLED::EASE_IN);
	else if (preset == PULSEIN)
		start(SmoothLED::PULSE, 300, 1500, 0, true, 1, SmoothLED::EASE_OUT, SmoothLED::EASE_IN);
	else if (preset == PULSEOUT)
		start(SmoothLED::PULSE, 1500, 300, 0, true, 1, SmoothLED::EASE_IN, SmoothLED::EASE_OUT);
	else if (preset == SLOWPULSE)
		start(SmoothLED::PULSE, 2000, 2000, 0, true, 1, SmoothLED::SINE, SmoothLED::SINE);
	else if (preset == RAPIDPULSE)
		start(SmoothLED::PULSE, 100, 100, 0, true, 1, SmoothLED::EASE_IN_OUT, SmoothLED::EASE_IN_OUT);
	else if (preset == DEEPBREATHE)
		start(SmoothLED::BREATHING, 10000, 2500, 0, true, 1, SmoothLED::SINE, SmoothLED::SINE);
	else if (preset == GLOW)
		start(SmoothLED::BREATHING, 6000, 2000, 0, true, 1, SmoothLED::SINE, SmoothLED::SINE);
	else if (preset == METEOR)
		start(SmoothLED::FADE_IN_OUT, 50, 500, 0, false, 1, SmoothLED::EASE_OUT, SmoothLED::EASE_IN);
	else if (preset == STRONGLIGHTNING)
		start(SmoothLED::FADE_IN_OUT, 5, 150, 5, false, 1, SmoothLED::LINEAR, SmoothLED::EASE_IN);
	else if (preset == FASTLIGHTNING)
		start(SmoothLED::FADE_IN_OUT, 20, 100, 20, false, 1, SmoothLED::EASE_OUT, SmoothLED::EASE_IN);
	else if (preset == SUNSET)
		start(SmoothLED::ON_THEN_FADE_OUT, 0, 8000, 0, false, 1, SmoothLED::LINEAR, SmoothLED::SINE);
	else if (preset == SUNRISE)
		start(SmoothLED::FADE_IN_THEN_OFF, 8000, 0, 0, false, 1, SmoothLED::SINE, SmoothLED::LINEAR);
	else if (preset == NOTIFY)
		start(SmoothLED::FADE_IN_OUT, 100, 800, 0, false, 1, SmoothLED::EASE_OUT, SmoothLED::EASE_IN);
	else if (preset == THINKING)
		start(SmoothLED::PULSE, 1000, 1000, 0, true, 1, SmoothLED::SINE, SmoothLED::SINE);
	else if (preset == LOADING)
		start(SmoothLED::PULSE, 500, 500, 0, true, 1, SmoothLED::EASE_IN_OUT, SmoothLED::EASE_IN_OUT);
	else if (preset == HEARTBEAT)
		start(SmoothLED::FADE_IN_OUT, 120, 250, 150, false, 3, SmoothLED::EASE_OUT, SmoothLED::EASE_IN);
}