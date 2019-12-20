/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 *
 * This example blinks an LED without using delay() function. This is a non-blocking example 
 */

#include <ezOutput.h> // ezOutput library

ezOutput led(9);  // create ezOutput object that attach to pin 9;

void setup() {
  led.blink(500, 250); // 500 milliseconds ON, 250 milliseconds OFF
}

void loop() {
  led.loop(); // MUST call the led.loop() function in loop()
}