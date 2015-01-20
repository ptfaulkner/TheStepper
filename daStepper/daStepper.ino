#include <Servo.h>
#include <Step.h>
 
Servo servo;
Step stepper(servo);

int minPosition = 54;
int maxPosition = 126;
int stepSize = 6;
int servoPosition = minPosition;
int timesToStep = 3500;
int steps = 0;
 
void setup() 
{ 
  servo.attach(9);
} 
 
void loop() 
{ 
  if(steps < timesToStep) 
  {
     stepper.step(minPosition, maxPosition, stepSize);
     steps++;
  }
}
