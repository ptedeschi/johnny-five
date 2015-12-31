/*
  Servomotor.cpp - Library for handle Distance.
  Created by Patrick Tedeschi, December, 2015.
*/

#include "Servomotor.h"

#define SERVO_MIN_DEGREE 0
#define SERVO_MAX_DEGREE 180
#define SERVO_SWEEP_INTERVAL_DEGREE 18

int roundUp(int numToRound, int multiple)
{
  if (multiple == 0)
  {
    return numToRound;
  }

  int remainder = numToRound % multiple;

  if (remainder == 0)
  {
    return numToRound;
  }

  return numToRound + multiple - remainder;
}

Servomotor::Servomotor()
{

}

void Servomotor::initialize(uint8_t pin)
{
  _servo.attach(pin);  // attaches the servo on pin 9 (SERVO_2 on the Motor Drive Shield to the servo object
  _direction = Direction::CLOCKWISE;
}

void Servomotor::sweep()
{
  switch (_direction)
  {
    case Direction::CLOCKWISE:
      if ( (getDegree() + SERVO_SWEEP_INTERVAL_DEGREE) < SERVO_MAX_DEGREE)
      {
        _servo.write(getDegree() + SERVO_SWEEP_INTERVAL_DEGREE);
      }
      else
      {
        _direction = Direction::ANTICLOCKWISE;
        _servo.write(getDegree() - SERVO_SWEEP_INTERVAL_DEGREE);
      }
      break;

    case Direction::ANTICLOCKWISE:
      if ( (getDegree() - SERVO_SWEEP_INTERVAL_DEGREE) > SERVO_MIN_DEGREE)
      {
        _servo.write(getDegree() - SERVO_SWEEP_INTERVAL_DEGREE);
      }
      else
      {
        _direction = Direction::CLOCKWISE;
        _servo.write(getDegree() + SERVO_SWEEP_INTERVAL_DEGREE);
      }
      break;

    default:
      break;
  }
}

void Servomotor::setPosition(Position position)
{
  switch (position)
  {
    case Position::LEFT:
      {
        int centerDegree = SERVO_MAX_DEGREE / 2;
        int leftDegree = (centerDegree - SERVO_MIN_DEGREE) / 2;
        int leftDegreeRounded = roundUp(leftDegree, SERVO_SWEEP_INTERVAL_DEGREE);

        _servo.write(leftDegreeRounded);

        _direction = Direction::CLOCKWISE;
      }
      break;

    case Position::CENTER:
      {
        int centerDegree = SERVO_MAX_DEGREE / 2;
        int centerDegreeRounded = roundUp(centerDegree, SERVO_SWEEP_INTERVAL_DEGREE);

        _servo.write(centerDegreeRounded); // tells the servo to position at 90-degrees ie. facing forward.

        _direction = Direction::CLOCKWISE;
      }
      break;

    case Position::RIGHT:
      {
        int centerDegree = SERVO_MAX_DEGREE / 2;
        int rightDegree = ((SERVO_MAX_DEGREE - centerDegree) / 2) + centerDegree;
        int rightDegreeRounded = roundUp(rightDegree, SERVO_SWEEP_INTERVAL_DEGREE);

        _servo.write(rightDegreeRounded);

        _direction = Direction::ANTICLOCKWISE;
      }
      break;

    default:
      break;
  }
}

int Servomotor::getDegree()
{
  return _servo.read();
}

