#ifndef GoalGetter_h
#define GoalGetter_h
#include <Arduino.h>
#include <Step.h>

class GoalGetter 
{
	public:
		GoalGetter(Step stepper);
		boolean Frequency(int currentMillis);
	private:
		Step _stepper;
};

#endif