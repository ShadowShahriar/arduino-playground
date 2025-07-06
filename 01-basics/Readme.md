# The Basics

This section provides sample code for basic operations such as **serial communication** and **GPIO pin manipulation**. It also includes a few useful tricks and utility functions.

1. [**Blink**](#blink)
2. [**Serial Output**](#serial-output)
3. [**Read a character from the Serial Monitor**](#read-a-character-from-the-serial-monitor)
4. [**Wait for Serial connectivity**](#wait-for-serial-connectivity)

## Blink

Blinking the **built-in LED** on the Arduino boards.

[📌 **Simulation**](https://wokwi.com/projects/423438680888402945)

[📄 **01-blink.ino**](./01-blink.ino)

| Board                                                                                                             | Built-in LED Pin | Alias                              |
| :---------------------------------------------------------------------------------------------------------------- | :--------------- | :--------------------------------- |
| Arduino&nbsp;Uno<br>Arduino&nbsp;Nano<br>Arduino&nbsp;Leonardo<br>Arduino&nbsp;Mini&nbsp;Mega<br>Xiao&nbsp;SAMD21 | **13**           | `LED_BUILTIN`                      |
| Arduino&nbsp;Pro&nbsp;Micro<br>Arduino&nbsp;Pro&nbsp;Mini                                                         | **17**, **30**   | `LED_BUILTIN_RX`, `LED_BUILTIN_TX` |

```CPP
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
```

## Serial Output

Printing **Hello World** in the Serial Monitor with a baud rate of `9600`.

[📄 **02-serial-output.ino**](./02-serial-output.ino)

> [!NOTE]
> Baud rate refers to the number of signal changes that occur per second in a communication channel. It is a measure of the signaling speed in a digital communication system. Most commonly used baud rates `9600` and `115200`.

```CPP
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
```

## Read a character from the Serial Monitor

The Arduino IDE includes a text field above its serial monitor, where we can read the single character that has been typed. This character is received in its ASCII representation, so we need to typecast it to a `char` in order to display it in the Serial Monitor.

[📄 **03-serial-read-char.ino**](./03-serial-read-char.ino)

```CPP
void setup()
{
  unsigned long baud = 9600; // 115200
  Serial.begin(baud);
  Serial.println(F("✅ Serial communication OK"));
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
```

## Wait for Serial connectivity

In certain situations, the serial monitor does not start immediately when the Arduino board is plugged in. As a result, some of the serial output may be lost. To address this, we print **10** new lines with a delay of **100 ms** before displaying any useful information.

[📄 **04-serial-setup.ino**](./04-serial-setup.ino)

```CPP
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
```
