/*
 * ParameterRecorder.h
 *
 *  Created on: 14.2.2014
 *      Author: Otto Urpelainen
 */

#ifndef PARAMETERRECORDER_H_
#define PARAMETERRECORDER_H_

#include "lib/Bounce2/Bounce2.h"

class RecordingButtonListener {

public:

    /**
     * Recording states.
     */
    enum RecordingState {
        // Potentiometers are not recorded
        NOT_RECORDING,
        // Recording just started
        START_RECORDING,
        // Recording
        RECORDING,
        // Recording just ended
        END_RECORDING
    };

    /**
     * Creates and initializes a new parameter recorder. Given digital input
     * pin is initialized as input pin with pullup activated.
     *
     * @param buttonPin digital pin of recording button.
     */
    RecordingButtonListener(int buttonPin);
    virtual ~RecordingButtonListener();

    /**
     * Reads recording button state and returns new recording state. Recording
     * starts when button is pressed and continues until it is pressed again.
     * Continuation of both recording and non-recording states are reported
     * separately from state transitions as RecordingState enumeration allows.
     *
     * Button is read using Bounce2 library.
     */
    RecordingState readState();

private:
    /** Digital pin of recording button. */
    Bounce button;

    /** Recording state. */
    RecordingState state;
};

#endif /* PARAMETERRECORDER_H_ */
