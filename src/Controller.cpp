/*
 * Controller.cpp
 *
 *  Created on: 14.11.2013
 *      Author: Otto Urpelainen
 */

#include "Arduino.h"

#include "CrystalCLevitation.h"

#include "Controller.h"

Controller::Controller(int setpointPin, int coeffPin) :
        setpointPin(setpointPin), coeffPin(coeffPin), setpoint(1), coeff(1) {
}

int Controller::control(int position) {
    int positionDiff = position - setpoint;
    return constrain((-coeff * positionDiff) + 255,0,255);
}

void Controller::readParameters() {
    int min = CONTROLLER_COEFF_MIN;
    int max = CONTROLLER_COEFF_MAX;
    float raw = (float)analogRead(coeffPin);
    coeff = ((max - min) / 1024.0) * (raw) + min;

    min = CONTROLLER_OP_MIN;
    max = CONTROLLER_OP_MAX;
    raw = (float)analogRead(setpointPin);
    setpoint = ((max - min) / 1024.0) * (raw) + min;

#ifdef __DEBUG
    Serial.print("#");
    Serial.print("setpoint=");
    Serial.print(setpoint);
    Serial.print(";");
    Serial.print("offset=");
    Serial.print(offset);
    Serial.print(";");
    Serial.print("coeff=");
    Serial.print(coeff);
    Serial.println("");
#endif
}
