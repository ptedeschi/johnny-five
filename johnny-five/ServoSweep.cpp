/*
  ServoSweep.cpp - Library for handle Distance.
  Created by Patrick Tedeschi, December, 2015.
*/

#include "ServoSweep.h"

#define SERVO_MIN_DEGREE 0
#define SERVO_MAX_DEGREE 180
#define SERVO_DEGREE_INTERVAL 18

ServoSweep::ServoSweep()
{

}

void ServoSweep::initialize(uint8_t pin)
{
  _servo.attach(pin);  // attaches the servo on pin 9 (SERVO_2 on the Motor Drive Shield to the servo object
  _servo.write(90); // tells the servo to position at 90-degrees ie. facing forward.
  _direction = Direction::CLOCKWISE;
}

void ServoSweep::sweep()
{
  switch (_direction)
  {
    case Direction::CLOCKWISE:
      if ( (getDegree() + SERVO_DEGREE_INTERVAL) < SERVO_MAX_DEGREE)
      {
        _servo.write(getDegree() + SERVO_DEGREE_INTERVAL);
      }
      else
      {
        _direction = Direction::ANTICLOCKWISE;
        _servo.write(getDegree() - SERVO_DEGREE_INTERVAL);
      }
      break;

    case Direction::ANTICLOCKWISE:
      if ( (getDegree() - SERVO_DEGREE_INTERVAL) > SERVO_MIN_DEGREE)
      {
        _servo.write(getDegree() - SERVO_DEGREE_INTERVAL);
      }
      else
      {
        _direction = Direction::CLOCKWISE;
        _servo.write(getDegree() + SERVO_DEGREE_INTERVAL);
      }
      break;

    default:
      break;
  }
}

int ServoSweep::getDegree()
{
  return _servo.read();
}

