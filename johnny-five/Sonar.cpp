/*
  Sonar.cpp - Library for handle Distance.
  Created by Patrick Tedeschi, December, 2015.
*/

#include "Sonar.h"

Sonar::Sonar()
{

}

/*
   Sets up sensor library to use the correct pins to measure distance.
*/
void Sonar::initialize(uint8_t trigger_pin, uint8_t echo_pin, unsigned int max_cm_distance)
{
  _newPing = new NewPing(trigger_pin, echo_pin, max_cm_distance);
}

int Sonar::getDistance()
{
  // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  return _newPing->ping_cm();          // Send ping, get distance in cm (0 = outside set distance range)
  //return 50;
}

