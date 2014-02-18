/*
 * Controller.cpp
 *
 *  Created on: 14.11.2013
 *      Author: Otto Urpelainen
 */

// Precompiled library dependencies
#include "Arduino.h"

// Source library dependencies
#include "lib/EEPROM/EEPROMAnything.h"

// Project configuration
#include "CrystalCLevitation.h"

// In-project dependencies
#include "Controller.h"

Controller::Controller(int coeffPin, int setpointPin) :
        Parameterized(sizeof(coeff) + sizeof(setpoint)), coeff(1), coeffPin(
                coeffPin), setpoint(1), setpointPin(setpointPin) {
}

int Controller::control(int position) {
    if (position < 0) {
        return 0;
    }

    int positionDiff = position - setpoint;
    return constrain(-coeff * positionDiff,0,255);
}

void Controller::readParameters() {
    int offset = getOffset();

    EEPROM_readAnything(offset,coeff);
    offset += sizeof(coeff);

    EEPROM_readAnything(offset,setpoint);
}

void Controller::updateParameters() {
    int min = CONTROLLER_COEFF_MIN;
    int max = CONTROLLER_COEFF_MAX;
    float raw = (float) analogRead(coeffPin);
    coeff = ((max - min) / 1024.0) * (raw) + min;

    min = CONTROLLER_OP_MIN;
    max = CONTROLLER_OP_MAX;
    raw = (float) analogRead(setpointPin);
    setpoint = ((max - min) / 1024.0) * (raw) + min;

#ifdef __DEBUG
    Serial.print("#");
    Serial.print("setpoint=");
    Serial.print(setpoint);
    Serial.print(";");
    Serial.print("coeff=");
    Serial.print(coeff);
    Serial.println("");
#endif
}

void Controller::writeParameters() {
    int offset = getOffset();

    EEPROM_writeAnything(offset,coeff);
    offset += sizeof(coeff);

    EEPROM_writeAnything(offset,setpoint);
}
