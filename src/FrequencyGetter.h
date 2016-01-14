// FrequencyGetter.h

#ifndef _FREQUENCYGETTER_h
#define _FREQUENCYGETTER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	#include "Step.h"
#else
	#include "WProgram.h"
#endif
class FrequencyGetter
{
public:
	FrequencyGetter(Step stepper);
	boolean execute(unsigned long currentMillis);
private:
	Step _stepper;
};

#endif

