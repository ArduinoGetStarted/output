/*
 * Copyright (c) 2019, ArduinoGetStarted.com. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * - Neither the name of the ArduinoGetStarted.com nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ARDUINOGETSTARTED.COM "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ARDUINOGETSTARTED.COM BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ezOutput_h
#define ezOutput_h

#include <Arduino.h>

#define BLINK_STATE_DISABLE 0
#define BLINK_STATE_DELAY   1
#define BLINK_STATE_BLINK   2

class ezOutput
{
	private:
		int _outputPin;
		int _outputState;
		int _blinkState;

		unsigned long _highTime;
		unsigned long _lowTime;
		unsigned long _startTime;
		unsigned long _blinkTimes;
		unsigned long _lastBlinkTime; // the last time the output pin was blinked
		void (* _funptr_digitalWrite)(uint8_t, uint8_t); //function pointer to digitalWrite function
		void (* _funptr_pinMode)(uint8_t, uint8_t); //function pointer to pinMode function

	public:
		/**
		 * @brief Construct a new ez Output object
		 * 
		 * @param pin The IO pin number to use
		 */
		ezOutput(int pin);

		/**
		 * @brief Construct a new ez Output object with function pointers to digitalWrite and pinMode
		 * 
		 * @param pin The IO pin number to use
		 * @param funptr_digitalWrite The digitalWrite function to use
		 * @param funptr_pinMode The pinMode function to use. Default is nullptr (in this case setting the pinMode to OUTPUT has to be done by the user)
		 */
		ezOutput(int pin, void (*funptr_digitalWrite)(uint8_t, uint8_t), void (*funptr_pinMode)(uint8_t, uint8_t) = nullptr);
		void high(void);
		void low(void);
		void toggle(void);
		void toggle(unsigned long delayTime);

		void pulse(unsigned long pulseTime);
		void pulse(unsigned long pulseTime, unsigned long delayTime);

		void blink(unsigned long lowTime, unsigned long highTime);
		void blink(unsigned long lowTime, unsigned long highTime, unsigned long delayTime);

		void blink(unsigned long lowTime, unsigned long highTime, unsigned long delayTime, long blinkTimes);
		int getState(void);
		void loop(void);
};

#endif
