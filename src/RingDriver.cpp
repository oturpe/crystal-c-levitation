/*
 * RingDriver.cpp
 *
 *  Created on: 5.11.2013
 *      Author: Otto Urpelainen
 */

#include "CrystalCLevitation.h"
#include "Arduino.h"
#include "RingDriver.h"

RingDriver::RingDriver(int ringPin): ringPin(ringPin) {
}

void RingDriver::init() {
    pinMode(ringPin,OUTPUT);
    analogWrite(ringPin,0);
}

void RingDriver::drive(int dutyCycle) {
    #ifdef __DEBUG
        Serial.print("Setting duty cycle to ");
        Serial.println(dutyCycle);
    #endif

    analogWrite(ringPin,dutyCycle);
}

RingDriver::RingDriver() {
}

