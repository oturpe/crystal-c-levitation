/*
 * RingDriver.cpp
 *
 *  Created on: 5.11.2013
 *      Author: Otto Urpelainen
 */

#include "Arduino.h"

#include "CrystalCLevitation.h"

#include "RingDriver.h"

RingDriver::RingDriver(int ringSize,int ringPins[]): ringSize(ringSize) {
    this->ringPins = (int*) malloc(ringSize * sizeof(int));
    for(int i = 0; i < ringSize; i++) {
        this->ringPins[i] = ringPins[i];
    }
}

void RingDriver::init() {
    for(int i = 0; i < ringSize; i++) {
        pinMode(ringPins[i],OUTPUT);
        analogWrite(ringPins[i],0);
    }
}

void RingDriver::drive(int dutyCycles[]) {
    #ifdef __DEBUG
        Serial.print("Setting duty cycle to {");
        for(int i = 0; i < ringSize; i++) {
          Serial.print(dutyCycles[i]);
          Serial.print(i < ringSize-1 ? "," : "}");
        }
        Serial.println();
    #endif

    for(int i = 0; i < ringSize; i++) {
        analogWrite(ringPins[i],dutyCycles[i]);
    }
}

RingDriver::RingDriver() {
}

