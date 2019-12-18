/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 *
 * This example turn ON/OFF led according to state of button.
 */

#include <Button.h> // ezButton library
#include <Output.h> // ezOutput library

Button button(7); // create Button object that attach to pin 7;
Output led(9);    // create Output object that attach to pin 9;

void setup() {
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
}

void loop() {
  button.loop(); // MUST call the loop() function first

  if(button.isPressed)
	  led.toggle();
}