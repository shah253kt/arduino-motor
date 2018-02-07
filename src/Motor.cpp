/*
Author: Ahmad Shahril Bin Mohd Ghani
Date: 23 December 2017
Description: This library is created to simplify the process of initializing motor in Arduino.
*/

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Motor.h"

Motor::Motor(byte pwmPin, byte dir1Pin)
{
    _mode = DIR_1;
	setDefaultValues(pwmPin, dir1Pin);
}

Motor::Motor(byte pwmPin, byte dir1Pin, byte dir2Pin)
{
    _mode = DIR_2;
	setDefaultValues(pwmPin, dir1Pin);

    _dir2Pin = dir2Pin;
    pinMode(_dir2Pin, OUTPUT);
}

void Motor::setDefaultValues(byte pwmPin, byte dir1Pin) {
	_pwmPin = pwmPin;
    _dir1Pin = dir1Pin;
    _inverseDirection = false;

    pinMode(_pwmPin, OUTPUT);
    pinMode(_dir1Pin, OUTPUT);
}

void Motor::setInvertMode(bool inverse)
{
    if (_mode != DIR_2)
    {
        _mode = inverse ? DIR_1_INVERT : DIR_1;
    }
}

void Motor::inverseDirection()
{
    _inverseDirection = !_inverseDirection;
}

void Motor::forward(byte pwm)
{
    if (_mode == DIR_1)
    {
        digitalWrite(_dir1Pin, !_inverseDirection);
    }
    else if (_mode == DIR_1_INVERT)
    {
        digitalWrite(_dir1Pin, !_inverseDirection);
        pwm = _inverseDirection ? pwm : 255 - pwm;
    }
    else
    {
        digitalWrite(_dir1Pin, !_inverseDirection);
        digitalWrite(_dir2Pin, _inverseDirection);
    }

    analogWrite(_pwmPin, pwm);
}

void Motor::backward(byte pwm)
{
    if (_mode == DIR_1)
    {
        digitalWrite(_dir1Pin, _inverseDirection);
    }
    else if (_mode == DIR_1_INVERT)
    {
        digitalWrite(_dir1Pin, _inverseDirection);
        pwm = !_inverseDirection ? pwm : 255 - pwm;
    }
    else
    {
        digitalWrite(_dir1Pin, _inverseDirection);
        digitalWrite(_dir2Pin, !_inverseDirection);
    }

    analogWrite(_pwmPin, pwm);
}

void Motor::stop()
{
    if (_mode == DIR_1_INVERT)
    {
        digitalWrite(_dir1Pin, LOW);
    }

    analogWrite(_pwmPin, 0);
}
