/*
  Motor.cpp - Library for handle Motor.
  Created by Patrick Tedeschi, December, 2015.
*/

#include "Arduino.h"
#include "Motor.h"

AF_DCMotor _motor1(1);
AF_DCMotor _motor2(2);
AF_DCMotor _motor3(3);
AF_DCMotor _motor4(4);

Motor::Motor()
{

}

void Motor::setSpeed(int speed)
{
  _motor1.setSpeed(speed);
  _motor2.setSpeed(speed);
  _motor3.setSpeed(speed);
  _motor4.setSpeed(speed);
}

void Motor::forward()
{
  _motor1.run(FORWARD);
  _motor2.run(FORWARD);
  _motor3.run(FORWARD);
  _motor4.run(FORWARD);
}

void Motor::backward()
{
  _motor1.run(BACKWARD);
  _motor2.run(BACKWARD);
  _motor3.run(BACKWARD);
  _motor4.run(BACKWARD);
}

void Motor::left()
{
  _motor1.run(BACKWARD);
  _motor2.run(FORWARD);
  _motor3.run(BACKWARD);
  _motor4.run(FORWARD);

  delay(400); // run motors this way for 400ms

  _motor1.run(FORWARD);
  _motor2.run(FORWARD);
  _motor3.run(FORWARD);
  _motor4.run(FORWARD);
}

void Motor::right()
{
  _motor1.run(FORWARD);
  _motor2.run(BACKWARD);
  _motor3.run(FORWARD);
  _motor4.run(BACKWARD);

  delay(400); // run motors this way for 400ms

  _motor1.run(FORWARD);
  _motor2.run(FORWARD);
  _motor3.run(FORWARD);
  _motor4.run(FORWARD);
}

void Motor::shutdown()
{
  _motor1.setSpeed(0);
  _motor2.setSpeed(0);
  _motor3.setSpeed(0);
  _motor4.setSpeed(0);

  _motor1.run(RELEASE);
  _motor2.run(RELEASE);
  _motor3.run(RELEASE);
  _motor4.run(RELEASE);
}
