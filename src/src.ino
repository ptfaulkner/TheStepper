#include "RandomStepper.h"
#include "IntensityGetter.h"
#include "FrequencyGetter.h"
#include "Step.h"
#include <Servo.h>

Servo servo;
Step stepper(servo, 13, 54, 126);
FrequencyGetter frequency(stepper);
IntensityGetter intensity(stepper);
RandomStepper randomStepper(stepper);

void setup()
{
	servo.attach(9);
	pinMode(13, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
	unsigned long currentMillis = millis();

	if (frequency.execute(currentMillis))
	{
		Serial.println("Frequency");
		return;
	}

	/*if (intensity.execute(currentMillis))
	{
		Serial.println("Intensity");
		return;
	}

	randomStepper.execute(currentMillis);*/
}