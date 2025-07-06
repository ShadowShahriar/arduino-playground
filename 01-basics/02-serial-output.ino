void setup()
{
	unsigned long baud = 9600;
	Serial.begin(baud);
	Serial.println(F("✅ Serial communication OK"));
}

void loop()
{
	delay(1000);
	Serial.println(F("Hello World"));
}