/*
 * === AdvancedInterval.cpp ===
 * @version 0.0.1
 * @author S. Shahriar
 * @date 2026-08-26
 * @license MIT
 * @copyright 2026 S. Shahriar <hi@shadowshahriar.dev>
 */

#include "AdvancedInterval.h"

AdvancedInterval::AdvancedInterval(unsigned long intervalMillis, int maxRuns = -1)
{
	_interval = intervalMillis;
	_maxRuns = maxRuns;
	_previousMillis = 0;
	_pausedTime = 0;
	_runCount = 0;
	_isRunning = false;
	_isPaused = false;
	_isComplete = false;

	// === Initialize all callback slots to null ===
	for (int i = 0; i < 7; i++)
		_callbacks[i] = nullptr;
}

void AdvancedInterval::fireEvent(AdvancedIntervalEvent event)
{
	if (_callbacks[event] != nullptr)
		_callbacks[event]();
}

void AdvancedInterval::addEventListener(AdvancedIntervalEvent event, void (*callbackFunction)())
{
	_callbacks[event] = callbackFunction;
}

void AdvancedInterval::start()
{
	_previousMillis = millis();
	_isRunning = true;
	_isPaused = false;
	_isComplete = false;
	_runCount = 0;
	fireEvent(INTERVAL_START);
}

void AdvancedInterval::stop()
{
	_isRunning = false;
	_isPaused = false;
	_isComplete = false;
	_runCount = 0;
	fireEvent(INTERVAL_STOP);
}

void AdvancedInterval::pause()
{
	if (_isRunning && !_isPaused)
	{
		_pausedTime = millis() - _previousMillis;
		_isPaused = true;
		fireEvent(INTERVAL_PAUSE);
	}
}

void AdvancedInterval::resume()
{
	if (_isRunning && _isPaused)
	{
		_previousMillis = millis() - _pausedTime;
		_isPaused = false;
		fireEvent(INTERVAL_RESUME);
	}
}

void AdvancedInterval::reset()
{
	_runCount = 0;
	_isComplete = false;
	fireEvent(INTERVAL_RESET);
}

void AdvancedInterval::setInterval(unsigned long intervalMillis)
{
	_interval = intervalMillis;
}

void AdvancedInterval::setLoop(int maxRuns)
{
	_maxRuns = maxRuns;
	_isComplete = false;
}

bool AdvancedInterval::update()
{
	// === Do nothing if stopped or paused ===
	if (!_isRunning || _isPaused)
	{
		return false;
	}

	// === Check if we reached the maximum run limit ===
	if (_maxRuns >= 0 && _runCount >= _maxRuns)
	{
		if (!_isComplete)
		{
			// === Mark as complete so this only fires once ===
			_isComplete = true;
			fireEvent(INTERVAL_COMPLETE);
		}
		return false;
	}

	unsigned long currentMillis = millis();
	if (currentMillis - _previousMillis >= _interval)
	{
		_previousMillis = currentMillis;
		_runCount++;

		// === Fire the regular trigger event ===
		fireEvent(INTERVAL_TRIGGER);

		// === If this final run hits the max limit, immediately fire the complete event too ===
		if (_maxRuns >= 0 && _runCount >= _maxRuns && !_isComplete)
		{
			_isComplete = true;
			fireEvent(INTERVAL_COMPLETE);
		}

		return true;
	}

	return false;
}

bool AdvancedInterval::isRunning()
{
	return _isRunning && !_isPaused;
}

bool AdvancedInterval::isPaused()
{
	return _isPaused;
}

bool AdvancedInterval::isComplete()
{
	return _isComplete;
}

int AdvancedInterval::getRunCount()
{
	return _runCount;
}