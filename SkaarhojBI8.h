/*  SkaarhojBI8 library for Arduino
    Copyright (C) 2012 Kasper Skårhøj    <kasperskaarhoj@gmail.com> 

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef SkaarhojBI8_H
#define SkaarhojBI8_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Wire.h"
#include "MCP23017.h"
#include "PCA9685.h"

/**
  Version 1.0.0
	(Semantic Versioning)
**/

class SkaarhojBI8
{
  private:
	uint8_t _boardAddress;
	bool _reverseButtons;
	MCP23017 _buttonMux;
	PCA9685 _buttonLed;
	uint8_t _buttonStatus;
	uint8_t _buttonStatusLastUp;
	uint8_t _buttonStatusLastDown;

	uint8_t _colorBalanceRed[10];	
	uint8_t _colorBalanceGreen[10];
	uint8_t _defaultColorNumber;
	uint8_t _buttonColorCache[8];
	bool _B1Alt;	
	bool _debugMode;
	bool _oldBI8;

  public:
	SkaarhojBI8();
	bool begin(int address);
	bool begin(int address, bool reverseButtons);
	void usingB1alt();
	void debugMode();
	void setButtonType(uint8_t type);
	void setColorBalance(int colorNumber, int redPart, int greenPart);
	void setDefaultColor(int defaultColorNumber);
	void setButtonColor(int buttonNumber, int colorNumber);
	void setButtonColorsToDefault();
	void testSequence();
	uint8_t testSequence(int delayTime);
	
	bool buttonUp(int buttonNumber);
	bool buttonDown(int buttonNumber);
	bool buttonIsPressed(int buttonNumber);
	uint8_t buttonUpAll();
	uint8_t buttonDownAll();
	uint8_t buttonIsPressedAll();
	bool isButtonIn(int buttonNumber, uint8_t allButtonsState);
	
	
  private:
	void _writeButtonLed(int buttonNumber, int color);
	void _readButtonStatus();
	bool _validButtonNumber(int buttonNumber);
	bool _validColorNumber(int colorNumber);
	bool _validPercentage(int percentage);
};
#endif 
