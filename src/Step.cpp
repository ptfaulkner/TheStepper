#include <Arduino.h>
#include <Servo.h>
#include "Step.h"


Step::Step(Servo servo, int ledPin, int minPosition, int maxPosition)
{
	_servo = servo;
	_ledPin = ledPin;
	_minPosition = minPosition;
	_maxPosition = maxPosition;
}

void Step::takeStep(int minPosition, int maxPosition, int stepSize)
{
	int servoPosition = minPosition;

	for (servoPosition = minPosition; servoPosition <= maxPosition; servoPosition += stepSize)
	{
		_servo.write(servoPosition);
		delay(15);
	}
	for (servoPosition = maxPosition; servoPosition >= minPosition; servoPosition -= stepSize)
	{
		_servo.write(servoPosition);
		delay(15);
	}
}

void Step::runSteps(int numberOfSteps, int sizeOfStep, int ledMode)
{
	
	if (ledMode == 1)
	{
		digitalWrite(_ledPin, HIGH);
	}

	for (int i = 0; i < numberOfSteps; i++)
	{
		if (ledMode == 3)
		{
			digitalWrite(_ledPin, HIGH);
		}

		takeStep(_minPosition, _maxPosition, sizeOfStep);

		if (ledMode == 3)
		{
			digitalWrite(_ledPin, LOW);
		}
	}

	digitalWrite(_ledPin, LOW);
}
