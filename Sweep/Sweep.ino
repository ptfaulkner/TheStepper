#include <Servo.h> 
 
Servo servo;  

int minPosition = 54;
int maxPosition = 126;
int stepSize = 6;
int servoPosition = minPosition;
int timesToStep = 1000;
int steps = 0;
 
void setup() 
{ 
  servo.attach(9);
} 
 
void loop() 
{ 
  if(steps < timesToStep) 
  {
     step();
     steps++;
  }
}

void step()
{
  for(servoPosition = minPosition; servoPosition <= maxPosition; servoPosition += stepSize) 
  {                                  
    servo.write(servoPosition);              
    delay(15);                        
  } 
  for(servoPosition = maxPosition; servoPosition >= minPosition; servoPosition -= stepSize)     
  {                                
    servo.write(servoPosition);              
    delay(15);                      
  } 
}
