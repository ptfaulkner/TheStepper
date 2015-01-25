#include <Arduino.h>
#include <Step.h>
#include "GoalGetter.h"

unsigned long _previousFrequencyRun = 0;
int _frequencyCountForDay = 0;
const int _frequenciesNeededPerDay = 6;
const unsigned long _oneHour = 3600000;
const unsigned long _eighteenHours = 64800000;

GoalGetter::GoalGetter(Step stepper)
{
	_stepper = stepper;
}

boolean GoalGetter::Frequency(int currentMillis)
{
	if (currentMillis - _previousFrequencyRun > _eighteenHours)
	{
		_frequencyCountForDay = 0;
	}

	if (currentMillis - _previousFrequencyRun > _oneHour)
	{
		if (_frequencyCountForDay < _frequenciesNeededPerDay)
		{
			_frequencyCountForDay++;
			_previousFrequencyRun = currentMillis;
			_stepper.RunSteps(500, 4, 1);
			return true;
		}
	}

	return false;
}
