#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <Fonts/Org_01.h>

// === 2.8 Inch TFT 240×320 ===
/* === SPI ===
 * TFT       ESP32
 * LED   --> GPIO 7
 * SCK   --> GPIO 13
 * MISO  --> GPIO 12
 * MOSI  --> GPIO 11
 * CS    --> GPIO 10
 * DC    --> GPIO 9
 * RST   --> GPIO 8
 * GND   --> GND
 * VCC   --> 3V3
 */

#define LANDSCAPE false
#define FLIP false
#define BRIGHTNESS 255 // === [0, 255] ===
#define TFT_BL 7	   // === backlight pin ===
#define TFT_DC 9	   // === data/command pin ===
#define TFT_RST 8	   // === reset pin ===
#define TFT_CS 10	   // === chip select pin ===
#define TFT_MS 250	   // === delay before initializing the display ===
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void background(uint16_t color)
{
	tft.fillScreen(color);
}

uint16_t rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return tft.color565(r, g, b);
}

void clearDisplay()
{
	tft.fillScreen(ST77XX_BLACK);
}

void backlight(int brightness)
{
	int val = constrain(brightness, 0, 255);
	analogWrite(TFT_BL, val);
}

void backlightOff()
{
	digitalWrite(TFT_BL, 0);
}

void backlightOn()
{
	backlight(BRIGHTNESS);
}

void setupTFT()
{
	pinMode(TFT_BL, OUTPUT);
	backlight(BRIGHTNESS);
	delay(TFT_MS);
	tft.init(240, 320);
	tft.invertDisplay(false);

	int rotate = 0;
	if (LANDSCAPE && FLIP)
		rotate = 3;
	else if (FLIP)
		rotate = 2;
	else if (LANDSCAPE)
		rotate = 1;
	tft.setRotation(rotate);

	clearDisplay();
	Serial.println(F("✅ TFT OK"));
}

// === === === === === === === === === === ===

void setupSerial()
{
	Serial.begin(9600);
	for (int i = 0; i < 10; i++)
	{
		delay(100);
		Serial.println(F("."));
	}
	Serial.println(F("✅ Serial OK"));
}

void demo()
{
	background(rgb(6, 10, 20));
	tft.setTextWrap(false);
	tft.setTextColor(rgb(0, 0, 255));
	tft.setTextSize(5);
	tft.setFont(&Org_01);
	tft.setCursor(40, 180);
	tft.print(F("GREAT!"));

	tft.setTextColor(rgb(255, 0, 0));
	tft.setTextSize(5);
	tft.setCursor(15, 139);
	tft.print(F("YOU ARE"));
}

void setup()
{
	setupSerial();
	setupTFT();
	demo();
}

void loop()
{
}