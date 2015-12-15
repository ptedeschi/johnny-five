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
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(1000);
}

void LED::turnOn()
{
  digitalWrite(_pin, HIGH);
  delay(1000);              // wait for a second
}

void LED::turnOff()
{
  digitalWrite(_pin, LOW);
  delay(1000);              // wait for a second

}
