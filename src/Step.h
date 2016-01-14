// Step.h

#ifndef _STEP_h
#define _STEP_h


#if defined(ARDUINO) && ARDUINO >= 100
        #include <Arduino.h>
        #include <Servo.h>
#else
	#include "WProgram.h"
#endif

class Step
{
public:
	Step(Servo servo, int ledPin, int minPosition, int maxPosition);
	void takeStep(int minPosition, int maxPosition, int stepSize);
	void runSteps(int numberOfSteps, int sizeOfStep, int ledMode);
private:
	Servo _servo;
	int _ledPin;
	int _minPosition;
	int _maxPosition;
};

#endif

