// Precompiled library dependencies
#include "Arduino.h"
#include "new.h"

// Source library dependencies
#include "lib/ArduinoPwm.h"

// Project configuration
#include "CrystalCLevitation.h"

// In-project dependencies
#include "PositionSensor.h"
#include "RingDriver.h"
#include "Controller.h"
#include "RecordingButtonListener.h"

RingDriver ringDriver(RING_PIN);
PositionSensor positionSensor(SENSOR_PIN);
Controller controller(CONTROLLER_PIN_OP,CONTROLLER_PIN_COEFF);
RecordingButtonListener recordingButtonListener(RECORDING_BUTTON_PIN);

int loopCount = 0;

// The setup() method runs once, when the sketch starts
void setup() {
   #ifdef __DEBUG
       Serial.begin(DEBUG_PRINT_BAUDRATE);
   #endif

   setPwmFrequency(RING_PIN,PWM_SCALING);

   ringDriver.init();

   int offset = 0;
   positionSensor.allocateEeprom(offset);
   controller.allocateEeprom(offset);

   positionSensor.readParameters();
   controller.readParameters();

   // Header line for CSV debug output
   #ifdef __DEBUG
       Serial.println("position;duty cycle;");
   #endif
}

/**
 *  Performs any actions related to recording parameters according to recording
 *  state as read from recording button listener.
 */
void record() {
    switch (recordingButtonListener.readState()) {
    case RecordingButtonListener::NOT_RECORDING:
        // Not recording, nothing to do.
        break;
    case RecordingButtonListener::START_RECORDING:
        positionSensor.updateParameters();
        break;
    case RecordingButtonListener::RECORDING:
        controller.updateParameters();
        break;
    case RecordingButtonListener::END_RECORDING:
        positionSensor.writeParameters();
        controller.writeParameters();
        break;
    default:
        // Getting here is an error, as all the different states should be
        // listed above.
        break;
    }
}

// the loop() method runs over and over again, as long as the Arduino has power.
void loop() {
    loopCount += 1;

    if(loopCount % CONTROLLER_PARAM_UPDATE_INTERVAL == 0) {
        record();
    }

    int position = positionSensor.read();
    int level = controller.control(position);

    ringDriver.drive(level);

    // Add line to CSV debug output
    #ifdef __DEBUG
        if (loopCount % DEBUG_PRINT_INTERVAL == 0) {
            Serial.print(position);
            Serial.print(";");
            Serial.print(level);
            Serial.print(";");

            Serial.println("");
        }
    #endif
}

int main(void) {

    init();
    setup();

    while (true) {
        loop();
    }
}
