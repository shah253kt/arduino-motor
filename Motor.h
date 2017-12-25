/*
Author: Ahmad Shahril Bin Mohd Ghani
Date: 23 December 2017
Description: This library is created to simplify the process of initializing motor in Arduino.
*/

#ifndef Motor_H_INCLUDED
#define Motor_H_INCLUDED

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define DIR_1 0
#define DIR_1_INVERT 1
#define DIR_2 2

class Motor
{
  public:
    Motor(byte pwmPin, byte dir1Pin);
    Motor(byte pwmPin, byte dir1Pin, byte dir2Pin);

    void setInvertMode(bool inverse);
    void inverseDirection();
    void forward(byte pwm);
    void backward(byte pwm);
    void stop();

  private:
    byte _mode, _pwmPin, _dir1Pin, _dir2Pin;
    bool _inverseDirection;

	void setDefaultValues(byte pwmPin, byte dir1Pin);
};

#endif