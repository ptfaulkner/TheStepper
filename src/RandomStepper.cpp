// 
// 
// 
#include <Arduino.h>
#include <Step.h>
#include "RandomStepper.h"


const unsigned long thirtyMinutes = 1800000;
const unsigned long eightyMinutes = 4800000;
unsigned long _firstRandomRun = 0;
unsigned long _previousRandomRun = 0;

RandomStepper::RandomStepper(Step stepper) : _stepper(stepper)
{
	randomSeed(analogRead(0));
	_randomTime = random(thirtyMinutes, eightyMinutes);
}

int RandomStepper::execute(unsigned long currentMillis)
{
	Serial.println("Random");
	Serial.println(currentMillis);
	Serial.println(_previousRandomRun);
	Serial.println(_randomTime);
	if (currentMillis - _previousRandomRun >= 10000)
	{
		_previousRandomRun = currentMillis;
		long randomSteps = random(40, 80);
		long randomSpeed = random(2, 3);

		_stepper.runSteps(randomSteps, randomSpeed, 3);

		_randomTime = random(thirtyMinutes, eightyMinutes);
		return randomSteps;
	}

	return 0;
}