#include <Servo.h> 
 
Servo servo;  

int minPosition = 54;
int maxPosition = 126;
int stepSize = 4;
int servoPosition = minPosition;
 
void setup() 
{ 
  servo.attach(9);
} 
 
void loop() 
{ 
  for(int i = 0; i < 1; i = i + 1)
  {
    step(); 
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
