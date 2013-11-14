/*
 * Controller.cpp
 *
 *  Created on: 14.11.2013
 *      Author: Otto Urpelainen
 */

#include "Arduino.h"

#include "CrystalCLevitation.h"

#include "Controller.h"

Controller::Controller(int operatingPointPin, int offsetPin, int coeffPin) :
        operatingPointPin(operatingPointPin), offsetPin(offsetPin), coeffPin(coeffPin), offset(0), coeff(1) {
}

int Controller::control(int position) {
    int positionDiff = position - operatingPoint;
    return constrain((-coeff * positionDiff) + offset,0,255);
}

void Controller::readParameters() {
    int min = CONTROLLER_OFFSET_MIN;
    int max = CONTROLLER_OFFSET_MAX;
    float raw = (float)analogRead(offsetPin);
    offset = ((max - min) / 1024.0) * (raw) + min;

    min = CONTROLLER_COEFF_MIN;
    max = CONTROLLER_COEFF_MAX;
    raw = (float)analogRead(coeffPin);
    coeff = ((max - min) / 1024.0) * (raw) + min;

    min = CONTROLLER_OP_MIN;
    max = CONTROLLER_OP_MAX;
    raw = (float)analogRead(operatingPointPin);
    operatingPoint = ((max - min) / 1024.0) * (raw) + min;

#ifdef __DEBUG
    Serial.print("#");
    Serial.print("operating point=");
    Serial.print(operatingPoint);
    Serial.print(";");
    Serial.print("offset=");
    Serial.print(offset);
    Serial.print(";");
    Serial.print("coeff=");
    Serial.print(coeff);
    Serial.println("");
#endif
}
