/*
 * PositionSensor.cpp
 *
 *  Created on: 11.11.2013
 *      Author: Otto Urpelainen
 */

// Precompiled library dependencies
#include "Arduino.h"

// Project configuration
#include "CrystalCLevitation.h"

// In-project dependencies
#include "PositionSensor.h"

PositionSensor::PositionSensor(int sensorPin,int resetPin) :
        sensorPin(sensorPin), resetPin(resetPin), positionCursor(0), smoothPosition(0), resetValue(0) {
    pinMode(resetPin,INPUT_PULLUP);
}

int PositionSensor::read() {
    int position = analogRead(sensorPin) - resetValue;

    if (position <= SENSOR_QUIESCENT_TOLERANCE) {
        return -1;
    }

    // Increment cursor
    positionCursor = (positionCursor + 1) % POSITION_SAMPLES;

    // Read new value and adjust smooth reading.
    smoothPosition -= positions[positionCursor];
    positions[positionCursor] = position;
    smoothPosition += positions[positionCursor];

    return smoothPosition / POSITION_SAMPLES;
}

void PositionSensor::readParameters() {
    if(digitalRead(resetPin) == HIGH) {
        return;
    }

    resetValue = analogRead(sensorPin);
}
