#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Fonts/Org_01.h>
#include <Adafruit_SH110X.h>

// === 1.3 Inch OLED 128×64 ===
/* === I2C ===
 * OLED      Arduino Nano
 * SDA   --> A4
 * SCL   --> A5
 * VCC   --> 5V
 * GND   --> GND
 */

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_DELAY 250
#define SCREEN_ADDRESS 0x3C
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void clearDisplay()
{
	display.clearDisplay();
	display.display();
}

void setupOLED()
{
	delay(SCREEN_DELAY);
	display.begin(SCREEN_ADDRESS, true);
	clearDisplay();
}

void demo()
{
	display.clearDisplay();
	display.setTextColor(1);
	display.setTextSize(3);
	display.setTextWrap(false);
	display.setFont(&Org_01);
	display.setCursor(17, 25);
	display.print("YOU'RE");
	display.setCursor(17, 47);
	display.print("GREAT!");
	display.display();
}

void setup()
{
	Serial.begin(9600);
	setupOLED();
	demo();
}

void loop()
{
}