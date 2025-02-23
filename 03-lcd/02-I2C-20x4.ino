#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDRESS 0x27 // 0x3F
#define LCD_COLUMNS 20
#define LCD_ROWS 4
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
	lcd.print("20245103408");
	lcd.setCursor(0, 2);
	lcd.print("Kaniz Fatema");
	lcd.setCursor(0, 3);
	lcd.print("20245103154");
}

void loop()
{
}