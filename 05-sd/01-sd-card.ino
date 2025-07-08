#include <SPI.h>
#include <FS.h>
#include "SD.h"

#define SD_MISO 12
#define SD_MOSI 13
#define SD_SCLK 14
#define SD_SS 27

SPIClass spi = SPIClass(HSPI);
char cardtype[8] = "NONE";

void setupSD()
{
	spi.begin(SD_SCLK, SD_MISO, SD_MOSI, SD_SS);
	if (!SD.begin(SD_SS, spi))
	{
		Serial.println(F("⛔ SD Card failed"));
		return;
	}
	else
		Serial.println(F("✅ SD Card OK"));

	getSD();
}

void getSD()
{
	uint8_t stype = SD.cardType();
	uint64_t ssize = SD.cardSize() / (1024 * 1024);
	if (stype == CARD_NONE)
		sprintf(cardtype, "%s", "NONE");
	else if (stype == CARD_MMC)
		sprintf(cardtype, "%s", "MMC");
	else if (stype == CARD_SD)
		sprintf(cardtype, "%s", "SDSC");
	else if (stype == CARD_SDHC)
		sprintf(cardtype, "%s", "SDHC");

	Serial.printf("SD Card Type: %s\n", cardtype);
	Serial.printf("SD Card Size: %llu MB", ssize);
}

// === === === ===

void setupSerial()
{
	Serial.begin(115200);
	for (int i = 0; i < 10; i++)
	{
		delay(100);
		Serial.println(F("."));
	}
	Serial.println(F("✅ Serial OK"));
}

void setup()
{
	setupSerial();
	setupSD();
}

void loop()
{
}