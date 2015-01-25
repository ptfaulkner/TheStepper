#include <Servo.h>
#include <Step.h>

Servo servo;
Step stepper(servo);
int servoPosition = 54;

int ledState = LOW;
unsigned long previousFrequencyRun = 0;
unsigned long previousIntensityRun = 0;
int frequencyCountForDay = 0;
unsigned long firstRandomRun = 0;
unsigned long previousRandomRun = 0;
long randomTime;

const int ledPin =  13;
const int minPosition = 54;
const int maxPosition = 126;

const unsigned long oneDay            = 86400000;
const unsigned long eighteenHours     = 64800000;
const unsigned long fourteenHours     = 50400000;
const unsigned long eightyMinutes     =  4800000;
const unsigned long oneHour           =  3600000;
const unsigned long fourtyFiveMinutes =  2700000;
const unsigned long thirtyMinutes     =  1800000;

const int BlinkSlow = 0;
const int On = 1;
const int Off = 2;
const int BlinkFast = 3;

void setup() 
{ 
  servo.attach(9);
  pinMode(ledPin, OUTPUT);
  randomSeed(analogRead(0));
  randomTime = random(thirtyMinutes, eightyMinutes);
} 

void loop() 
{ 
  unsigned long currentMillis = millis();

  if(frequency(currentMillis))
  {
     return; 
  }

  if(intensity(currentMillis))
  {
    return;
  }

  coordinateRandom(currentMillis);
}

boolean frequency(int currentMillis)
{
  if(currentMillis - previousFrequencyRun > eighteenHours)
  {
    frequencyCountForDay = 0;
  }

  if(currentMillis - previousFrequencyRun > oneHour) {
    if(frequencyCountForDay < 6) {
      frequencyCountForDay++;
      previousFrequencyRun = currentMillis;   
      step(500, 4, On);
      return true;
    }
  }
  
  return false;   
}

boolean intensity(int currentMillis)
{
  if(currentMillis - previousIntensityRun > oneDay) {
    previousIntensityRun = currentMillis;
    step(3500, 6, Off);
    return true;
  }
  
  return false;
}

void coordinateRandom(int currentMillis)
{
  if(currentMillis - previousRandomRun > randomTime)
  {
    previousRandomRun = currentMillis;
    long randomSteps = random(40, 80);
    long randomSpeed = random(2, 3);

    step(randomSteps, randomSpeed, BlinkFast);
    
    randomTime = random(thirtyMinutes, eightyMinutes);
  }
}

void step(int steps, int stepSize, int ledMode) 
{
  if(ledMode == On)
  {
    digitalWrite(ledPin, HIGH);
  }

  for(int i = 0; i < steps; i++)
  {
    if(ledMode == BlinkFast) 
    {
      digitalWrite(ledPin, HIGH);
    }

    stepper.step(minPosition, maxPosition, stepSize);

    if(ledMode == BlinkFast) 
    {
      digitalWrite(ledPin, LOW);
    }
  }

  digitalWrite(ledPin, LOW);
}

