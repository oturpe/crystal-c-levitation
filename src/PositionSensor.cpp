/*
 * PositionSensor.cpp
 *
 *  Created on: 11.11.2013
 *      Author: Otto Urpelainen
 */

#include "CrystalCLevitation.h"
#include "PositionSensor.h"
#include "Arduino.h"

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
