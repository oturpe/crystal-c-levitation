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

PositionSensor::PositionSensor(int sensorPin) :
        sensorPin(sensorPin), positionCursor(0), smoothPosition(0) {
}

int PositionSensor::read() {
    // Increment cursor
    positionCursor = (positionCursor + 1) % POSITION_SAMPLES;

    // Read new value and adjust smooth reading.
    smoothPosition -= positions[positionCursor];
    positions[positionCursor] = analogRead(sensorPin);
    smoothPosition += positions[positionCursor];

    return smoothPosition / POSITION_SAMPLES;
}
