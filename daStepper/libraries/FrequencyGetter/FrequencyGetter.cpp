#include <Arduino.h>
#include <Step.h>
#include "FrequencyGetter.h"

unsigned long _previousFrequencyRun = 0;
int _frequencyCountForDay = 0;
const int _frequenciesNeededPerDay = 6;
const unsigned long _oneHour = 3600000;
const unsigned long _eighteenHours = 64800000;

FrequencyGetter::FrequencyGetter(Step stepper) : _stepper(stepper) { }

boolean FrequencyGetter::execute(unsigned long currentMillis)
{
	if (currentMillis - _previousFrequencyRun >= _eighteenHours)
	{
		_frequencyCountForDay = 0;
	}

	if (currentMillis - _previousFrequencyRun >= _oneHour)
	{
		if (_frequencyCountForDay < _frequenciesNeededPerDay)
		{
			_frequencyCountForDay++;
			_previousFrequencyRun = currentMillis;
			_stepper.runSteps(500, 4, 1);
			return true;
		}
	}

	return false;
}
