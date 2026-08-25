/*
 * === AdvancedInterval.h ===
 * @version 0.0.1
 * @author S. Shahriar
 * @date 2026-08-26
 * @license MIT
 * @copyright 2026 S. Shahriar <hi@shadowshahriar.dev>
 */

#ifndef ADVANCEDINTERVAL_H
#define ADVANCEDINTERVAL_H

#include <Arduino.h>
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

class AdvancedInterval
{
private:
	unsigned long _previousMillis;
	unsigned long _interval;
	unsigned long _pausedTime;

	int _maxRuns;
	int _runCount;

	bool _isRunning;
	bool _isPaused;

	// === To prevent the complete event from firing repeatedly ===
	bool _isComplete;

	// === To hold function pointers for each event ===
	void (*_callbacks[7])();

	// === Helper to run a callback if it is attached ===
	void fireEvent(AdvancedIntervalEvent event);

public:
	AdvancedInterval(unsigned long intervalMillis, int maxRuns = -1);
	void addEventListener(AdvancedIntervalEvent event, void (*callbackFunction)());
	void start();
	void stop();
	void pause();
	void resume();
	void reset();
	void setInterval(unsigned long intervalMillis);
	void setLoop(int maxRuns);
	bool update();
	bool isRunning();
	bool isPaused();
	bool isComplete();
	int getRunCount();
};

#endif