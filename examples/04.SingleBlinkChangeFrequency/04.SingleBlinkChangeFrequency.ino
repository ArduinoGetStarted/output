/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 *
 * This example blinks an LED:
 * + with frequency changed according to the state of a button
     . if button is NOT pressed, blink slowly
     . if button is pressed, blink fast
 * + without using delay() function. This is a non-blocking example 
 */

#include <ezOutput.h> // ezOutput library

const int BUTTON_PIN = 7;
ezOutput led(9);  // create ezOutput object that attach to pin 9;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  led.loop(); // MUST call the led.loop() function in loop()

  int buttonState = digitalRead(BUTTON_PIN);

  if(buttonState == HIGH) // button is not pressed
    led.blink(500, 500); // 500 milliseconds ON, 500 milliseconds OFF
  else // button is pressed
    led.blink(200, 200); // 200 milliseconds ON, 200 milliseconds OFF
}