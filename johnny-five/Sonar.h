/*
  Sonar.h - Library for handle sonar funcionalities.
  Created by Patrick Tedeschi, December, 2015.

  Dependes on NewPing
  https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home
*/
#ifndef Sonar_h
#define Sonar_h

#include <Arduino.h>
#include <NewPing.h>

class Sonar
{
  private:
    NewPing* _newPing;

  public:
    Sonar();
    void initialize(uint8_t trigger_pin, uint8_t echo_pin, unsigned int max_cm_distance);
    int getDistance();
};

#endif
