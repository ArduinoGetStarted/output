/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 *
 * This example turn ON/OFF led according to state of button.
 */

#include <ezButton.h> // ezButton library https://arduinogetstarted.com/tutorials/arduino-button-library
#include <ezOutput.h> // ezOutput library

ezButton button(7); // create Button object that attach to pin 7;
ezOutput led(9);    // create ezOutput object that attach to pin 9;

void setup() {
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
}

void loop() {
  button.loop(); // MUST call the loop() function first

  if(button.isPressed())
    led.toggle();
}