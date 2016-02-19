#ifndef Step_h
#define Step_h
#include <Arduino.h>
#include <Servo.h>

class Step 
{
  public:
    Step(Servo servo);
    void step(int minPosition, int maxPosition, int stepSize);
  private:
    Servo _servo;
};

#endif