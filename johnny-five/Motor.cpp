/*
  Motor.cpp - Library for handle Motor.
  Created by Patrick Tedeschi, December, 2015.
*/

#include "Arduino.h"
#include "Motor.h"

AF_DCMotor _motor1(2);
AF_DCMotor _motor2(3);

Motor::Motor()
{

}

void Motor::setSpeed(int speed)
{
  _motor1.setSpeed(speed);
  _motor2.setSpeed(speed);

  _motor1.run(RELEASE);
  _motor2.run(RELEASE);
}

void Motor::moveForward()
{
  _motor1.run(FORWARD);
  _motor2.run(FORWARD);
}

void Motor::moveBackward()
{
  _motor1.run(BACKWARD);
  _motor2.run(BACKWARD);
}

void Motor::turnLeft()
{
  _motor1.run(BACKWARD);
  _motor2.run(FORWARD);

  delay(400);  //run motors this way for 400ms
}

void Motor::turnRight()
{
  _motor1.run(FORWARD);
  _motor2.run(BACKWARD);

  delay(400);  //run motors this way for 400ms
}

void Motor::veerLeft()
{
  _motor1.run(BACKWARD);
  delay(400);
  _motor1.run(FORWARD);
  delay(400);
}

void Motor::veerRight()
{
  _motor2.run(BACKWARD);
  delay(400);
  _motor2.run(FORWARD);
  delay(400);
}

void Motor::stop()
{
  //_motor1.setSpeed(0);
  //_motor2.setSpeed(0);

  _motor1.run(RELEASE);
  _motor2.run(RELEASE);
}
