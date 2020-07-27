/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 *
 * This example blinks LED:
 * + blink in 10 seconds and then turn off
 * + without using delay() function. This is a non-blocking example 
 */

#include <ezOutput.h> // ezOutput library

ezOutput led(7);  // create ezOutput object that attach to pin 7;


void setup() {
  led.blink(200, 200, 0, 10000); // 200 milliseconds ON, 200 milliseconds OFF, start immidiately, blink during 10000 milliseconds
}

void loop() {
  led.loop(); // MUST call the led.loop() function in loop()
}