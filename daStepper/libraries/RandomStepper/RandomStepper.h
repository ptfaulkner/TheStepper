#ifndef RandomStepper_h
#define RandomStepper_h
#include <Arduino.h>
#include <Step.h>

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