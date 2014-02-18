/*
 * ParameterRecorder.cpp
 *
 *  Created on: 14.2.2014
 *      Author: Otto Urpelainen
 */

#include "RecordingButtonListener.h"
#include "lib/Bounce2/Bounce2.h"
#include "Arduino.h"

RecordingButtonListener::RecordingButtonListener(int buttonPin) : state(NOT_RECORDING) {
    pinMode(buttonPin,INPUT_PULLUP);
    button.attach(buttonPin);
    button.interval(100);
}

RecordingButtonListener::~RecordingButtonListener() {
}

RecordingButtonListener::RecordingState RecordingButtonListener::readState() {
    bool change = button.update();
    bool buttonPressed = button.read() == LOW;

    if(change && buttonPressed) {
        if (state == RECORDING || START_RECORDING)
            state = END_RECORDING;
        else // NOT_RECORDING || END_RECORDING
            state = START_RECORDING;
    } else if (!change) {
        if(state == START_RECORDING)
            state = RECORDING;
        if(state == END_RECORDING)
            state = NOT_RECORDING;
    }

    return state;
}
