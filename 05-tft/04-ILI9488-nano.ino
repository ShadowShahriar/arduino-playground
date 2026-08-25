#include <SPI.h>
#include <Adafruit_GFX.h>
#include <ILI9488.h>

// === 3.5 Inch TFT 320×480 ===
/* === SPI ===
 * TFT            Arduino Nano
 * LED        --> GPIO 7
 * SCK        --> GPIO 13
 * SDO(MISO)  --> GPIO 12
 * SDI(MOSI)  --> GPIO 11
 * CS         --> GPIO 10
 * DC         --> GPIO 9
 * RST        --> GPIO 8
 * GND        --> GND
 * VCC        --> 5V
 */

#define BRIGHTNESS 255 // === [0, 255] ===
#define LANDSCAPE false
#define FLIP true

#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8
#define TFT_BL 7
#define TFT_MS 250
ILI9488 tft = ILI9488(TFT_CS, TFT_DC, TFT_RST);

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
	tft.fillScreen(ILI9488_BLACK);
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
	tft.begin();

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
	tft.setCursor(36, 174);
	tft.print(F("YOU ARE"));
	tft.setCursor(54, 245);
	tft.print(F("GREAT!"));
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