#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Fonts/Org_01.h>
#include <Adafruit_SSD1306.h>

// === 0.96 Inch OLED 128×64 ===
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
#define SCREEN_ADDRESS 0x3D
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void clearDisplay()
{
	display.clearDisplay();
	display.display();
}

void setupOLED()
{
	delay(SCREEN_DELAY);
	display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
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