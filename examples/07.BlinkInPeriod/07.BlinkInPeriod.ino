/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 *
 * This example blinks LED:
 * + blink 10 times (5 times OFF->ON, 5 times ON->OFF, interleavedly)
 * + without using delay() function. This is a non-blocking example 
 */

#include <ezOutput.h> // ezOutput library

ezOutput led(9);  // create ezOutput object that attach to pin 9;

void setup() {
  led.blink(250, 500, 0, 10); // 500 milliseconds ON, 250 milliseconds OFF, start immidiately, blink 10 times (5 times OFF->ON, 5 times ON->OFF, interleavedly)
}

void loop() {
  led.loop(); // MUST call the led.loop() function in loop()
}