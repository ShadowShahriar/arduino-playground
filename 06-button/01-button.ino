#include <OneButton.h>
#define PIN_BTN_1 15
#define PIN_BTN_2 17
#define PIN_BTN_3 19
#define PIN_BTN_4 21

OneButton btnA;
OneButton btnB;
OneButton btnC;
OneButton btnD;

void f1()
{
	Serial.println(F("Function A"));
}

void f2()
{
	Serial.println(F("Function B"));
}

void f3()
{
	Serial.println(F("Function C"));
}

void f4()
{
	Serial.println(F("Function D"));
}

void setupButtons()
{
	btnA.setup(PIN_BTN_1, INPUT_PULLUP, true);
	btnA.attachClick(f1);

	btnB.setup(PIN_BTN_2, INPUT_PULLUP, true);
	btnB.attachClick(f2);

	btnC.setup(PIN_BTN_3, INPUT_PULLUP, true);
	btnC.attachClick(f3);

	btnD.setup(PIN_BTN_4, INPUT_PULLUP, true);
	btnD.attachClick(f4);
}

void setup()
{
	Serial.begin(9600);
	Serial.println("OK");
	setupButtons();
}

void loop()
{
	btnA.tick();
	btnB.tick();
	btnC.tick();
	btnD.tick();
}