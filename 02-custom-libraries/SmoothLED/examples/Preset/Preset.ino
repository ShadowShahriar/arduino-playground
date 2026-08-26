/*
 * === Preset.ino ===
 * @version 0.0.1
 * @author S. Shahriar
 * @date 2026-08-26
 * @license MIT
 * @copyright 2026 S. Shahriar <hi@shadowshahriar.dev>
 */

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