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

PositionSensor::PositionSensor(int sensorPin) : sensorPin(sensorPin) {
}

int PositionSensor::read() {
    int position = analogRead(sensorPin);

    #ifdef __DEBUG
        Serial.print("Position: ");
        Serial.println(position);
    #endif

    return position;
}
