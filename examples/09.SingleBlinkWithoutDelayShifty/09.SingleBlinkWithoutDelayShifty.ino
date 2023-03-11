/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 *
 * This example blinks an LED without using delay() function on a shift register using
 * Shifty https://github.com/johnnyb/Shifty as another abstraction layer. This is a non-blocking example 
 */

#include <ezOutput.h> // ezOutput library
#include <Shifty.h> // Shifty library

Shifty shiftRegister; // shift register object

// digitalWrite function for shift register because we can't use a pointer to the non-abstract class member function directly
void digitalWriteShiftRegister(uint8_t pin, uint8_t state)
{
  shiftRegister.writeBit(pin, state);
}

ezOutput led(0, digitalWriteShiftRegister);  // create ezOutput object that attach to pin 0 of the shift register and overwrites the
                                             // digitalWrite function with the one from Shifty
                                             // we don't need to overwrite pinMode because the shift register is an output by defaul

void setup() {

  shiftRegister.setBitCount(8); // 1 shift register with 8 outputs
  shiftRegister.setPins(10, 11, 12); // shift register connected to data_pin=10, clock_pin=11, latch_pin=12

  led.blink(500, 250); // 500 milliseconds ON, 250 milliseconds OFF
}

void loop() {
  led.loop(); // MUST call the led.loop() function in loop()
}