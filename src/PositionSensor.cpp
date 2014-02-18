/*
 * PositionSensor.cpp
 *
 *  Created on: 11.11.2013
 *      Author: Otto Urpelainen
 */

// Precompiled library dependencies
#include "Arduino.h"

// Source library dependencies
#include "lib/EEPROM/EEPROMAnything.h"

// Project configuration
#include "CrystalCLevitation.h"

// In-project dependencies
#include "PositionSensor.h"

PositionSensor::PositionSensor(int sensorPin) :
        Parameterized(sizeof(resetValue)), positionCursor(
                0), resetValue(0), sensorPin(sensorPin), smoothPosition(0) {
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
    EEPROM_readAnything(getOffset(),resetValue);
}

void PositionSensor::updateParameters() {
    resetValue = analogRead(sensorPin);
}

void PositionSensor::writeParameters() {
    EEPROM_writeAnything(getOffset(),resetValue);
}
