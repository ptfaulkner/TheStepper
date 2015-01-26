#ifndef FrequencyGetter_h
#define FrequencyGetter_h
#include <Arduino.h>
#include <Step.h>

class FrequencyGetter
{
	public:
		FrequencyGetter(Step stepper);
		boolean execute(unsigned long currentMillis);
	private:
		Step _stepper;
};

#endif