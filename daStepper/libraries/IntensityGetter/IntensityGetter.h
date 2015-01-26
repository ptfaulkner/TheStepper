#ifndef IntensityGetter_h
#define IntensityGetter_h
#include <Arduino.h>
#include <Step.h>

class IntensityGetter
{
	public:
		IntensityGetter(Step stepper);
		boolean execute(unsigned long currentMillis);
	private:
		Step _stepper;
};

#endif