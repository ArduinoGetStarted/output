/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 *
 * This example blinks 3 LED:
 * + with diffent frequencies
 * + start blink at the same time
 * + without using delay() function. This is a non-blocking example 
 */

#include <ezOutput.h> // ezOutput library

ezOutput led1(7);  // create ezOutput object that attach to pin 7;
ezOutput led2(8);  // create ezOutput object that attach to pin 8;
ezOutput led3(9);  // create ezOutput object that attach to pin 9;

void setup() {
  led1.blink(500, 250); // 500 milliseconds ON, 250 milliseconds OFF
  led2.blink(250, 250); // 250 milliseconds ON, 250 milliseconds OFF
  led2.blink(100, 100); // 100 milliseconds ON, 100 milliseconds OFF
}

void loop() {
  led1.loop(); // MUST call the led1.loop() function in loop()
  led2.loop(); // MUST call the led2.loop() function in loop()
  led3.loop(); // MUST call the led3.loop() function in loop()
}