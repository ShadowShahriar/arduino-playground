#include <SPI.h>
#include <TFT_eSPI.h>

// === 3.5 Inch TFT 320×480 ===
/* === SPI ===
 * TFT       ESP32
 * LED   --> GPIO 5
 * SCK   --> GPIO 18
 * MISO  --> GPIO 19
 * MOSI  --> GPIO 23
 * CS    --> GPIO 15
 * DC    --> GPIO 2
 * RST   --> GPIO 4
 * GND   --> GND
 * VCC   --> 3V3
 */

#define BRIGHTNESS 255 // === [0, 255] ===
#define LANDSCAPE false
#define FLIP false
#define TFT_BL 5
#define TFT_MS 250

TFT_eSPI tft = TFT_eSPI();

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
	tft.fillScreen(TFT_BLACK);
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
	tft.init();

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
	background(rgb(0, 10, 20));
	tft.setTextColor(rgb(0, 100, 255));
	tft.setTextSize(6);
	tft.drawString(F("YOU ARE"), 36, 174);
	tft.drawString(F("GREAT!"), 54, 245);
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