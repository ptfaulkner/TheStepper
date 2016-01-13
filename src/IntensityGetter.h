// IntensityGetter.h

#ifndef _INTENSITYGETTER_h
#define _INTENSITYGETTER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	#include <Step.h>
#else
	#include "WProgram.h"
#endif

class IntensityGetter
{
public:
	IntensityGetter(Step stepper);
	boolean execute(unsigned long currentMillis);
private:
	Step _stepper;
};

#endif

