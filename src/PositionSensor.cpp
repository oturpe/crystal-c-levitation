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

PositionSensor::PositionSensor(int bottomPin, int topPin) :
        bottomPin(bottomPin), topPin(topPin) {
}

int* PositionSensor::read() {
    positions[BOTTOM] = 0;
    positions[TOP] = 0;

    for (int i = 0; i < POSITION_SAMPLES; i++) {
        positions[BOTTOM] += analogRead(bottomPin);
        positions[TOP] += analogRead(topPin);

        delay(POSITION_SAMPLE_DELAY);
    }

    positions[BOTTOM] /= POSITION_SAMPLES;
    positions[TOP] /= POSITION_SAMPLES;

    return positions;
}
