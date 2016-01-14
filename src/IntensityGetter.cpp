#include <Arduino.h>
#include "Step.h"
#include "IntensityGetter.h"

unsigned long previousIntensityRun = 0;
const unsigned long oneDay = 86400000;

IntensityGetter::IntensityGetter(Step stepper) : _stepper(stepper) { }

boolean IntensityGetter::execute(unsigned long currentMillis)
{
	if (currentMillis - previousIntensityRun >= oneDay)
	{
		previousIntensityRun = currentMillis;
		_stepper.runSteps(3500, 6, 2);
		return true;
	}

	return false;
}
