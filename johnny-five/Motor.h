/*
  Motor.h - Library for handle Motor.
  Created by Patrick Tedeschi, December, 2015.

  Depends on Adafruit Motor shield
  https://github.com/adafruit/Adafruit-Motor-Shield-library
*/
#ifndef Motor_h
#define Motor_h

#include <Arduino.h>
#include <AFMotor.h>

class Motor
{
  private:

  public:
    Motor();
    void setSpeed(int speed);
    void forward();
    void backward();
    void left();
    void right();
    void shutdown();
};

#endif
