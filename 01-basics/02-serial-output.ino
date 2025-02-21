void setup()
{
	unsigned long baud = 9600;
	Serial.begin(baud);
	Serial.println("✅ Serial communication OK");
}

void loop()
{
	delay(1000);
	Serial.println("Hello");
}