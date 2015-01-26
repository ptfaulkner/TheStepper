#include <Servo.h>
#include <Step.h>
#include <FrequencyGetter.h>

Servo servo;
Step stepper(servo, 13, 54, 126);
FrequencyGetter frequencyGetter(stepper);
int servoPosition = 54;

int ledState = LOW;
unsigned long previousFrequencyRun = 0;
unsigned long previousIntensityRun = 0;
int frequencyCountForDay = 0;
unsigned long firstRandomRun = 0;
unsigned long previousRandomRun = 0;
long randomTime;

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
  pinMode(13, OUTPUT);
  randomSeed(analogRead(0));
  randomTime = random(thirtyMinutes, eightyMinutes);
  Serial.begin(9600);
} 

void loop() 
{ 
  unsigned long currentMillis = millis();
  
  if(frequencyGetter.frequency(currentMillis))
  {
     return; 
  }
/*
  if(intensity(currentMillis))
  {
    return;
  }

  coordinateRandom(currentMillis);*/
}

boolean intensity(int currentMillis)
{
  if(currentMillis - previousIntensityRun > oneDay) 
  {
    previousIntensityRun = currentMillis;
    stepper.runSteps(3500, 6, Off);
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

    stepper.runSteps(randomSteps, randomSpeed, BlinkFast);
    
    randomTime = random(thirtyMinutes, eightyMinutes);
  }
}

