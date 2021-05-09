/*
  Sonar.cpp - Library for measuring distances (in cm) using a HC-SR04 rangefinder.
  Created by David Jonas, April 12, 2015.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Sonar.h"

Sonar::Sonar(int tp, int ep)
{
  triggerPin = tp;
  echoPin = ep;
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

long Sonar::getDistance()
{
  long duration;
  long distance;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}
