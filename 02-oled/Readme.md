# OLED

**OLED** stands for **Organic Light-Emitting Diode**. These devices use LED technology and use an organic material as a light emitting layer. OLEDs can produce high quality displays with **high contrasts**, **high viewing angles** and **true blacks**. This section provides sample code and wiring diagrams for various OLED modules designed for use with Arduino and ESP32 boards.

<!-- prettier-ignore-start -->
> [!IMPORTANT]
We are using the [**Adafruit GFX library**](https://github.com/adafruit/Adafruit-GFX-Library) across all the displays to provide a unified API. Although we use the same graphics library, we need to install additional hardware-specific libraries for different OLED modules. All of these OLED modules use the **I2C protocol**.
<!-- prettier-ignore-end -->

-   [**0.96" OLED module**](#096-inch-oled-module)
-   [**1.3" OLED module**](#13-inch-oled-module)
-   [**1.5" OLED module**](#15-inch-oled-module)
-   [**2.42" OLED module**](#242-inch-oled-module)

## Wiring Diagram

| OLED Module | Arduino Nano | Arduino Mega | ESP32        |
| :---------- | :----------- | :----------- | :----------- |
| **SDA**     | A4           | GPIO 20      | GPIO 21      |
| **SCL**     | A5           | GPIO 21      | GPIO 22      |
| **GND**     | GND          | GND          | GND          |
| **VCC**     | 5V           | 5V           | 5V           |
| **RES**\*   | GPIO 7       | GPIO 7       | **GPIO 5**\* |

<!-- prettier-ignore-start -->
> [!NOTE]
> The **RES** pin is only required in some variations of the 2.42" OLED module. Make sure to change the **RESET** pin to **GPIO 5** before uploading the sketch [**03-SSD1309.ino**](./03-SSD1309.ino) into an ESP32 board.
<!-- prettier-ignore-end -->

-   [📌 **Simulation with an Arduino Nano**](https://wokwi.com/projects/423486128879808513)
-   [📌 **Simulation with an Arduino Mega**](https://wokwi.com/projects/423532660172523521)
-   [📌 **Simulation with an ESP32 Dev Module**](https://wokwi.com/projects/424335911358345217)

## 0.96 inch OLED module

[📄 **01-SSD1306.ino**](./01-SSD1306.ino)

| Feature              |                                      |
| :------------------- | :----------------------------------- |
| **Driver IC**        | SSD1306                              |
| **Required Library** | [**Adafruit_SSD1306**][lib-ssd1306]  |
| **Resolution**       | 128×64                               |
| **Colors**           | Blue, White, Yellow, Dual-color      |
| **Purchase Link**    | [**📌 RoboticsBD**][roboticsbd-0-96] |

[lib-ssd1306]: https://github.com/adafruit/Adafruit_SSD1306

## 1.3 inch OLED module

[📄 **02-SH1106.ino**](./02-SH1106.ino)

| Feature              |                                     |
| :------------------- | :---------------------------------- |
| **Driver IC**        | SH1106                              |
| **Required Library** | [**Adafruit_SH110x**][lib-sh110x]   |
| **Resolution**       | 128×64                              |
| **Colors**           | Blue, White                         |
| **Purchase Link**    | [**📌 RoboticsBD**][roboticsbd-1-3] |

[lib-sh110x]: https://github.com/adafruit/Adafruit_SH110x

## 1.5 inch OLED module

📄 **04-SSD1327.ino**

| Feature              |                                        |
| :------------------- | :------------------------------------- |
| **Driver IC**        | SSD1327                                |
| **Required Library** | [**Adafruit_SSD1327**][lib-ssd1327]    |
| **Resolution**       | 128×128                                |
| **Colors**           | Blue, White, RGB                       |
| **Purchase Link**    | [**📌 ElectronicsBD**][roboticsbd-1-5] |

[lib-ssd1327]: https://github.com/adafruit/Adafruit_SSD1327

## 2.42 inch OLED module

[📄 **03-SSD1309.ino**](./01-SSD1309.ino)

| Feature              |                                      |
| :------------------- | :----------------------------------- |
| **Driver IC**        | SSD1309\* (or **SSD1306**)           |
| **Required Library** | [**Adafruit_SSD1306**][lib-ssd1306]  |
| **Resolution**       | 128×64                               |
| **Colors**           | Blue, White, Yellow                  |
| **Purchase Link**    | [**📌 RoboticsBD**][roboticsbd-2-42] |

[roboticsbd-0-96]: https://store.roboticsbd.com/arduino-shield/1328-096-inch-i2c-oled-display-white-robotics-bangladesh.html
[roboticsbd-1-3]: https://store.roboticsbd.com/display/1064-13-inch-i2c-oled-display-module-4pin-blue-robotics-bangladesh.html
[roboticsbd-1-5]: https://www.electronics.com.bd/microcontroller/1-5inch-rgb-oled-display-module-128x128-pixels
[roboticsbd-2-42]: https://store.roboticsbd.com/arduino-shield/2923-242-inch-oled-screen-lcd-display-module-128x64-iic-i2c-4pin-yellow-robotics-bangladesh.html
