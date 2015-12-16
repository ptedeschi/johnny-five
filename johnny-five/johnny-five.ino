
#include <Logging.h>
#include <DCMotorBot.h>
#include <Servo.h>
#include "Sonar.h"
#include "LED.h"
#include "ServoSweep.h"

#define LOG_BAUD_RATE 9600
#define TRIGGER_PIN  A3  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     A5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define MIN_SAFE_DIST 10 // Sets distance at which robot stops and reverses to 10cm
#define SERVO_PIN     9
#define LED_PIN 13

DCMotorBot _motorBot;
Sonar _sonar;
LED _led;
ServoSweep _servoSweep;

void setup() {
  // put your setup code here, to run once:
  Log.Init(LOG_LEVEL_DEBUG, LOG_BAUD_RATE);

  _led.setPin(LED_PIN);

  _sonar.initialize(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

  _servoSweep.initialize(SERVO_PIN);

  // initialize bot pins
  _motorBot.setEnablePins(3, 5);
  _motorBot.setControlPins(2, 4, 7, 8);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);

  int currentDistance = _sonar.getDistance();

  Log.Debug("Sonar distance %d\n", currentDistance);

  if (currentDistance >= MIN_SAFE_DIST) { // if the current distance to object is less than the collision distance
    //_led.turnOff();
    _motorBot.moveForward();
  }
  else
  {
    //_led.turnOn();
    _motorBot.stop();
  }

    _servoSweep.sweep();
    delay(15); // waits for the servo to reach the position
}

