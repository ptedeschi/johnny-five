
#include <Logging.h>
#include <DCMotorBot.h>
#include <Servo.h>
#include "Sonar.h"
#include "LED.h"

#define LOG_BAUD_RATE 9600
#define TRIGGER_PIN  A3  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     A5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define MIN_SAFE_DIST 10 // Sets distance at which robot stops and reverses to 10cm
#define SERVO_PIN     9
#define LED_PIN 13

DCMotorBot _motorBot;
Servo _servo;
Sonar _sonar;
LED _led;
int pos = 0; // this sets up variables for use in the sketch (code)

void setup() {
  // put your setup code here, to run once:
  Log.Init(LOG_LEVEL_DEBUG, LOG_BAUD_RATE);

  _led.setPin(LED_PIN);

  _sonar.initialize(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

  // initialize bot pins
  _motorBot.setEnablePins(3, 5);
  _motorBot.setControlPins(2, 4, 7, 8);

  _servo.attach(SERVO_PIN);  // attaches the servo on pin 9 (SERVO_2 on the Motor Drive Shield to the servo object
  _servo.write(90); // tells the servo to position at 90-degrees ie. facing forward.
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);

  for (pos = 144; pos >= 36; pos -= 18)  // loop to sweep the servo (& sensor) from 144-degrees left to 36-degrees right at 18-degree intervals.
  {
    _servo.write(pos);
    delay(90); // wait 90ms for servo to get to position

    int currentDistance = _sonar.getDistance();

    Log.Debug("Sonar distance %d\n", currentDistance);

    if (currentDistance >= MIN_SAFE_DIST) { // if the current distance to object is less than the collision distance
      _led.turnOff();
      _motorBot.moveForward();
    }
    else
    {
      _led.turnOn();
      _motorBot.stop();
    }
  }
}

