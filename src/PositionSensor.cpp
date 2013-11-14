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
        bottomPin(bottomPin), topPin(topPin), positionCursor(0) {
    smoothPositions[BOTTOM] = 0;
    smoothPositions[TOP] = 0;
}

int* PositionSensor::read() {
    // Increment cursor
    positionCursor += 1;
    if(positionCursor == POSITION_SAMPLES) {
        positionCursor = 0;
    }

    int* currentPositions = positions[positionCursor];

    // Remove oldest values from smooth reading
    smoothPositions[BOTTOM] -= currentPositions[BOTTOM];
    smoothPositions[TOP] -= currentPositions[TOP];

    // Store new values
    currentPositions[BOTTOM] = analogRead(bottomPin);
    currentPositions[TOP] = analogRead(topPin);

    // Add new values to rolling average
    smoothPositions[BOTTOM] += currentPositions[BOTTOM];
    smoothPositions[TOP] += currentPositions[TOP];

    // Calculate rolling average
    rollingAverage[BOTTOM] = smoothPositions[BOTTOM] / POSITION_SAMPLES;
    rollingAverage[TOP] = smoothPositions[TOP] / POSITION_SAMPLES;

    return rollingAverage;
}
