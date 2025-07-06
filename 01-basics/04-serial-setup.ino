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

void setup()
{
	setupSerial();
}

void loop()
{
	delay(1000);
	Serial.println(F("Hello World"));
}
