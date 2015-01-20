#include <Servo.h>
#include <Step.h>
 
Servo servo;
Step stepper(servo);

int minPosition = 54;
int maxPosition = 126;
int servoPosition = minPosition;
int oneMinute = 1000 * 60;
 
void setup() 
{ 
  servo.attach(9);
  
  frequency();// 1
  delay(oneMinute * 60);  //pause for one hour
  frequency();// 2
  delay(oneMinute * 60);  //pause for one hour
  intensity();// 3
  delay(oneMinute * 60);  //pause for one hour
  frequency();// 4
  delay(oneMinute * 5);
  step(200, 4);
  delay(oneMinute * 60);  //pause for one hour
  frequency();// 5
  delay(oneMinute * 30);
  step(300, 4);
  delay(oneMinute * 60);  //pause for one hour
  frequency();// 6
  delay(oneMinute * 80);
  step(750, 4);
  delay(oneMinute * 45);
  step(350, 4);
  delay(oneMinute * 30);
  step(2000, * 3);
} 
 
void loop() 
{ 

}

step(int steps, int stepSize) 
{
  for(int i = 0; i < steps; i++)
  {
    stepper.step(minPosition, maxPosition, stepSize);
  }
}

void frequency()
{
  step(500, 4);
}

void intensity()
{
  step(3500, 6);
}