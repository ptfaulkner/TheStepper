#include <Servo.h>
#include <Step.h>
 
Servo servo;
Step stepper(servo);

int minPosition = 54;
int maxPosition = 126;
int servoPosition = minPosition;
unsigned long oneMinute = 6000;
unsigned long oneHour = 3600000;
unsigned long thirtyMinutes = 1800000;
unsigned long fourtyFiveMinutes = 2700000;
unsigned long eightyMinutes = 4800000;
 
void setup() 
{ 
  servo.attach(9);
  
  step(5, 4);
  delay(oneMinute);
  frequency();// 1
  delay(oneHour);  //pause for one hour
  frequency();// 2
  delay(oneHour);  //pause for one hour
  intensity();// 3
  delay(oneHour);  //pause for one hour
  frequency();// 4
  delay(72000);
  step(200, 4);
  delay(oneHour);  //pause for one hour
  frequency();// 5
  delay(thirtyMinutes);
  step(300, 4);
  delay(oneHour);  //pause for one hour
  frequency();// 6
  delay(eightyMinutes);
  step(750, 4);
  delay(fourtyFiveMinutes);
  step(350, 4);
  delay(thirtyMinutes);
  step(2000, 3);
} 
 
void loop() 
{ 

}

void step(int steps, int stepSize) 
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
