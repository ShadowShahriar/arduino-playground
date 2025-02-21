void setup()
{
	unsigned long baud = 9600; // 115200
	Serial.begin(baud);
	Serial.println("✅ Serial communication OK");
}

void loop()
{
	if (Serial.available() > 0)
	{
		int data = Serial.read();
		if (data != 10 && data != 13)
			Serial.println((char)data);
	}
}