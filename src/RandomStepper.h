// RandomStepper.h

#ifndef _RANDOMSTEPPER_h
#define _RANDOMSTEPPER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	#include <Step.h>
#else
	#include "WProgram.h"
#endif

class RandomStepper
{
public:
	RandomStepper(Step stepper);
	int execute(unsigned long currentMillis);
private:
	Step _stepper;
	long _randomTime;
};

#endif

