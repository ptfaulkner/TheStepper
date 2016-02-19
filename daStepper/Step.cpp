#include <Arduino.h>
#include <Servo.h>
#include "Step.h"


Step::Step(Servo servo)
{
  _servo = servo;
}

void Step::step(int minPosition, int maxPosition, int stepSize)
{
  int servoPosition = minPosition;
  
  for(servoPosition = minPosition; servoPosition <= maxPosition; servoPosition += stepSize) 
  {                                  
    _servo.write(servoPosition);              
    delay(15);                        
  } 
  for(servoPosition = maxPosition; servoPosition >= minPosition; servoPosition -= stepSize)     
  {                                
    _servo.write(servoPosition);              
    delay(15);                      
  } 
}

