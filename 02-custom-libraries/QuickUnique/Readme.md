# QuickUnique

This library abstracts the standard random function to return consecutive unique numbers.

## Basic Example

```cpp
#include <QuickUnique.h>

// === Goal: print unique numbers from the range from 20 to 30 (inclusive) ===
QuickUnique uniqueInt(20, 30);

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	Serial.println(uniqueInt.next());
	delay(500);
}
```

## Set Range

```cpp
#include <QuickUnique.h>
QuickUnique uniqueInt(1, 10);

void setup()
{
	Serial.begin(9600);

	Serial.println(F("--- Small Range Unqiue Numbers (1 to 10) ---"));
	for (int i = 0; i < 10; i++)
	{
		Serial.println(uniqueInt.next());
		delay(500);
	}

	Serial.println(F("--- Changing Range Now (128 to 1024) ---"));

	// === Changing the range dynamically ===
	uniqueInt.setRange(128, 1024);
}

void loop()
{
	Serial.println(uniqueInt.next());
	delay(500);
}
```
