/*
  LED.h - Library for handle LED.
  Created by Patrick Tedeschi, December, 2015.
*/
#ifndef LED_h
#define LED_h

#include "Arduino.h"

class LED
{
  private:
    int _pin;

  public:
    LED();
    void setPin(int pin);
    void blink();
    void turnOn();
    void turnOff();
};

#endif
