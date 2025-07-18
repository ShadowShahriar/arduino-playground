#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// === 16x2 LCD Module ===
/* === I2C ===
 * OLED      Arduino Nano
 * SDA   --> A4
 * SCL   --> A5
 * VCC   --> 5V
 * GND   --> GND
 */

#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void setup()
{
	lcd.init();
	lcd.clear();
	lcd.backlight();
	delay(250);

	lcd.setCursor(0, 0);
	lcd.print("Shadman Shahriar");
	lcd.setCursor(0, 1);
	lcd.print("CSE / 53 (Sec 1)");
}

void loop()
{
}