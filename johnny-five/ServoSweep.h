/*
  ServoSweep.h - Library for handle ServoSweep funcionalities.
  Created by Patrick Tedeschi, December, 2015.

  Dependes on Servo
  https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home
*/
#ifndef ServoSweep_h
#define ServoSweep_h

#include <Arduino.h>
#include <Servo.h>

enum class Direction { CLOCKWISE, ANTICLOCKWISE };

class ServoSweep
{
  private:
    Servo _servo;
    Direction _direction;

  public:
    ServoSweep();
    void initialize(uint8_t pin);
    void sweep();
    int getDegree();
};

#endif
