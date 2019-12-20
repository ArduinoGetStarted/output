/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 *
 * This example turn ON/OFF led according to state of button.
 */

#include <ezOutput.h> // ezOutput library

const int BUTTON_PIN = 7;
ezOutput led(9);  // create ezOutput object that attach to pin 9;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if(buttonState == HIGH)
    led.high();
  else
    led.low();

  Serial.println(led.getState());
}