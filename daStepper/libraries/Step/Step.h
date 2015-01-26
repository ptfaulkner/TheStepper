#ifndef Step_h
#define Step_h
#include <Arduino.h>
#include <Servo.h>

class Step
{
public:
	Step(Servo servo, int ledPin, int minPosition, int maxPosition);
	void takeStep(int minPosition, int maxPosition, int stepSize);
	void runSteps(int numberOfSteps, int sizeOfStep, int ledMode);
private:
	Servo _servo;
	int _ledPin;
	int _minPosition;
	int _maxPosition;
};

#endif