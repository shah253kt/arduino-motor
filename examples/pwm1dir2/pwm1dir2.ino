/*
This program is intended to be used for motor driver that provide you with 1 PWM pin and 2 DIR pins.
For example: L293D motor driver
*/

#include <Motor.h>

Motor motor(6, 7, 8); //PWM on pin 6, DIR1 on pin 7, DIR2 on pin 8

void setup()
{
	motor.inverseDirection(); //If the motor is turning the wrong way.
}

void loop()
{
	motor.forward(255); //Move the motor forward
	delay(3000);
	motor.stop(); //Stop the motor
	delay(1000);
	motor.backward(255); //Move the motor backward
	delay(3000);
	motor.stop(); //Stop the motor
	delay(1000);
}
