#include <Servo.h>
#include <Step.h>
 
Servo servo;
Step stepper(servo);

int minPosition = 54;
int maxPosition = 126;
int servoPosition = minPosition;
unsigned long oneMinute = 6000;
unsigned long oneHour = 3600000;
unsigned long fiveMinutes = 72000;
unsigned long thirtyMinutes = 1800000;
unsigned long fourtyFiveMinutes = 2700000;
unsigned long eightyMinutes = 4800000;
unsigned long currentMillis = 0;
unsigned long lastRunMillis = 0;
 
void setup() 
{ 
  servo.attach(9);
} 
 
void loop() 
{ 
  currentMillis = millis();
  
  if(lastRunMillis == 0 || (currentMillis - lastRunMillis) > fifteenHours) 
  {
    oneDaysGoals();
	lastRunMillis = millis();
  }
}

void oneDaysGoals() 
{  
  step(5, 4);
  delay(oneMinute);
  frequency();// 1
  delay(oneHour);  //pause for one hour
  frequency();// 2
  delay(oneHour);  //pause for one hour
  intensity();// 3
  delay(oneHour);  //pause for one hour
  frequency();// 4
  delay(fiveMinutes);
  step(200, 4);//random
  delay(oneHour);  //pause for one hour
  frequency();// 5
  delay(thirtyMinutes);
  step(1000, 4);//random
  delay(oneHour);  //pause for one hour
  frequency();// 6
  delay(eightyMinutes);
  step(1500, 4);//random
  delay(fourtyFiveMinutes);
  step(2000, 4);//random
  delay(thirtyMinutes);
  step(1500, 3);//random
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
  step(4000, 6);
}
