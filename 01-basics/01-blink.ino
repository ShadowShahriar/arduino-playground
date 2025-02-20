/*
 * =======================================
 * === Built-in LEDs in Arduino boards ===
 * =======================================
 * Nano/Leonardo/Xiao/Mini Mega - 13 (LED_BUILTIN)
 * Micro/Pro Micro - 17 (LED_BUILTIN_RX), 30 (LED_BUILTIN_TX)
 */
#define LED_PIN 13

void setup()
{
	pinMode(LED_PIN, OUTPUT);
	digitalWrite(LED_PIN, LOW);
}

void loop()
{
	digitalWrite(LED_PIN, HIGH);
	delay(2000);

	digitalWrite(LED_PIN, LOW);
	delay(1000);
}