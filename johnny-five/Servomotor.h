/*
  Servomotor.h - Library for handle ServoSweep funcionalities.
  Created by Patrick Tedeschi, December, 2015.

  Dependes on Servo
  https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home
*/
#ifndef Servomotor_h
#define Servomotor_h

#include <Arduino.h>
#include <Servo.h>

enum class Direction { CLOCKWISE, ANTICLOCKWISE };
enum class Position { LEFT, CENTER, RIGHT };

class Servomotor
{
  private:
    Servo _servo;
    Direction _direction;

  public:
    Servomotor();
    void initialize(uint8_t pin);
    void sweep();
    void setPosition(Position position);
    int getDegree();
};

#endif
