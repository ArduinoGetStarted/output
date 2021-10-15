## Output Library for Arduino - ezOutput
This library is designed for Arduino, ESP32, ESP8266... to control the states of digital output pins (HIGH, LOW, TOGGLE, PULSE, BLINK_WITHOUT_DELAY). It is easy to use with multiple output pins to control multiple LED, relay... It is designed for not only beginners but also experienced users.

**ezOutput** stands for **easy output**, which mean that the library is easy to use.

Features
----------------------------
* Support HIGH, LOW, PULSE and TOGGLE
* Support get state of output pin
* Supports blink without delay
* All functions are non-blocking
* Easy to use with multiple output pins
* Support time offset in blink multiple output pins

Available Functions
----------------------------
* ezOutput(int pin)
* void high(void)
* void low(void)
* void toggle(void)
* void toggle(unsigned long delayTime)
* void pulse(unsigned long pulseTime)
* void pulse(unsigned long pulseTime, unsigned long delayTime)
* void blink(unsigned long lowTime, unsigned long highTime)
* void blink(unsigned long lowTime, unsigned long highTime, unsigned long delayTime)
* void blink(unsigned long lowTime, unsigned long highTime, unsigned long delayTime, long blinkTimes)
* int getState(void)
* void loop(void)
 

Available Examples
----------------------------
* [01.OnOff](https://arduinogetstarted.com/library/arduino-on-off-example)
* [02.Toggle](https://arduinogetstarted.com/library/arduino-toggle-example)
* [03.SingleBlinkWithoutDelay](https://arduinogetstarted.com/library/arduino-single-blink-without-delay-example)
* [04.SingleBlinkChangeFrequency](https://arduinogetstarted.com/library/arduino-single-blink-change-frequency-example)
* [05.MultipleBlinkWithoutDelay](https://arduinogetstarted.com/library/arduino-multiple-blink-without-delay-example)
* [06.MultipleBlinkWithOffset](https://arduinogetstarted.com/library/arduino-multiple-blink-with-offset-example)
* [07.BlinkInPeriod](https://arduinogetstarted.com/library/arduino-blink-in-period-example)
* [08.Pulse](https://arduinogetstarted.com/library/arduino-pulse-example)



How To Install the Library
----------------------------
* [ezOutput Library Installization Guide](https://arduinogetstarted.com/tutorials/arduino-output-library)

References
----------------------------
* [ezOutput Library Reference](https://arduinogetstarted.com/tutorials/arduino-output-library)
