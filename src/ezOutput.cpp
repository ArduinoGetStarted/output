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

#include <ezOutput.h>

ezOutput::ezOutput(int pin) {
	_outputPin = pin;
	_outputState = LOW;
	_blinkState = BLINK_STATE_DISABLE;

	_highTime = 0;
	_lowTime  = 0;
	_blinkTimes  = -1;
	_lastBlinkTime = 0; 

	pinMode(_outputPin, OUTPUT);
}

void ezOutput::high(void){
	_blinkState = BLINK_STATE_DISABLE;
	_outputState = HIGH;
	digitalWrite(_outputPin, _outputState);
}

void ezOutput::low(void){
	_blinkState = BLINK_STATE_DISABLE;
	_outputState = LOW;
	digitalWrite(_outputPin, _outputState);
}

void ezOutput::toggle(void) {
	_blinkState = BLINK_STATE_DISABLE;
	_outputState = (_outputState == LOW) ? HIGH : LOW;
	digitalWrite(_outputPin, _outputState);
}

void ezOutput::toggle(unsigned long delayTime) {
	_highTime   = 0;
	_lowTime    = 0;
	_startTime  = delayTime;
	_blinkTimes = 1;
	_blinkState = BLINK_STATE_DELAY;
	_lastBlinkTime = millis();
}



void ezOutput::pulse(unsigned long pulseTime) {
	pulse(pulseTime, 0);
}
void ezOutput::pulse(unsigned long pulseTime, unsigned long delayTime) {
	_blinkState = BLINK_STATE_DISABLE;
	if(_outputState == LOW)
		blink(0, pulseTime, delayTime, 2);
	else
		blink(pulseTime, 0, delayTime, 2);
}

void ezOutput::blink(unsigned long lowTime, unsigned long highTime, unsigned long delayTime, long blinkTimes) {
	_highTime   = highTime;
	_lowTime    = lowTime;
	_startTime  = delayTime;
	_blinkTimes = blinkTimes;

	if(_blinkState == BLINK_STATE_DISABLE) {
		_blinkState = BLINK_STATE_DELAY;
		_lastBlinkTime = millis();
	}
}

void ezOutput::blink(unsigned long lowTime, unsigned long highTime, unsigned long delayTime) {
	blink(lowTime, highTime, delayTime, -1);
}

void ezOutput::blink(unsigned long lowTime, unsigned long highTime) {
	blink(lowTime, highTime, 0, -1);
}

int ezOutput::getState(void) {
	return _outputState;
}

void ezOutput::loop(void) {
	bool isBlink = false;

	if(_blinkTimes == 0)
		_blinkState = BLINK_STATE_DISABLE;

	switch(_blinkState) {
		case BLINK_STATE_DISABLE:
			return;

		case BLINK_STATE_DELAY:
			if ((unsigned long)(millis() - _lastBlinkTime) >= _startTime) {
				isBlink = true;
				_blinkState = BLINK_STATE_BLINK;
			}

			break;

		case BLINK_STATE_BLINK:
			if(_outputState == LOW && (unsigned long)(millis() - _lastBlinkTime) >= _lowTime)
				isBlink = true;
			else
			if(_outputState == HIGH && (unsigned long)(millis() - _lastBlinkTime) >= _highTime)
				isBlink = true;

			break;

		default:
			return;
	}

	if(isBlink) {
		_outputState = (_outputState == LOW) ? HIGH : LOW;
		digitalWrite(_outputPin, _outputState);
		_lastBlinkTime = millis();
		
		if(_blinkTimes > 0)
			_blinkTimes--;
	}
}

