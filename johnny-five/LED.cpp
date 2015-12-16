/*
  LED.cpp - Library for handle LED.
  Created by Patrick Tedeschi, December, 2015.
*/

#include "Arduino.h"
#include "LED.h"

LED::LED()
{

}

void LED::setPin(int pin)
{
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void LED::blink()
{
  digitalWrite(_pin, HIGH);
  delay(200);
  digitalWrite(_pin, LOW);
}

void LED::turnOn()
{
  digitalWrite(_pin, HIGH);
}

void LED::turnOff()
{
  digitalWrite(_pin, LOW);
}
