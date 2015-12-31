
#include <Logging.h>
#include <Servo.h>
#include "Motor.h"
#include "Sonar.h"
#include "LED.h"
#include "Servomotor.h"

#define LOG_BAUD_RATE 9600
#define TRIGGER_PIN  A3  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     A5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define MIN_SAFE_DIST 20 // Sets distance at which robot stops and reverses to 10cm
#define SERVO_PIN     9
#define LED_PIN 13

Motor _motor;
Sonar _sonar;
LED _led;
Servomotor _servo;

void setup()
{
  // put your setup code here, to run once:
  Log.Init(LOG_LEVEL_DEBUG, LOG_BAUD_RATE);

  _sonar.initialize(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

  _servo.initialize(SERVO_PIN);
  _servo.setPosition(Position::CENTER);

  // initialize bot pins
  _motor.setSpeed(255);

  _motor.moveForward(); // run function to make robot move forward
}

void loop()
{
  int currentDistance = _sonar.getDistance();

  Log.Debug("Sonar distance %d\n", currentDistance);

  if (currentDistance < MIN_SAFE_DIST)
  {
    // if the current distance to object is less than the collision distance
    Log.Debug("we're about to hit something so move backwards, stop\n");

    _motor.stop();
    //_motor.release();

    _servo.setPosition(Position::LEFT);
    delay(1000);
    int left = _sonar.getDistance();

    _servo.setPosition(Position::RIGHT);
    delay(1000);
    int right = _sonar.getDistance();

    _servo.setPosition(Position::CENTER);
    delay(1000);
    int center = _sonar.getDistance();

    Log.Debug("LEFT: %d\n", left);
    Log.Debug("RIGHT: %d\n", right);
    Log.Debug("CENTER: %d\n", center);

    delay(3000);

    if (center > right && center > left)
    {
      Log.Debug("Dead end... Need to go back!!!\n");

      // Dead end
      _motor.moveBackward();
      delay(1000);

      // pick a random number from 0 to 1
      int randomSide = random(0, 2);

      if (randomSide == 0)
      {
        Log.Debug("Turn LEFT\n");

        _motor.turnLeft();
        _motor.turnLeft();
      }
      else
      {
        Log.Debug("Turn RIGHT\n");

        _motor.turnRight();
        _motor.turnRight();
      }

      _motor.moveForward();
    }
    else if (right > center && right > left)
    {
      Log.Debug("Right is a good place to go\n");

      _motor.veerRight();
      _motor.moveForward();
    }
    else if (left > center && left > right)
    {
      Log.Debug("Left is a good place to go\n");

      _motor.veerLeft();
      _motor.moveForward();
    }
  }

  // put your main code here, to run repeatedly:
  delay(500);
}

