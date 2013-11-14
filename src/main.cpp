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

RingDriver ringDriver(RING_PIN);
PositionSensor positionSensor(SENSOR_PIN_BOTTOM,SENSOR_PIN_TOP);
Controller controller(CONTROLLER_PIN_OP,CONTROLLER_PIN_OFFSET,CONTROLLER_PIN_COEFF);

int loopCount = 0;

// The setup() method runs once, when the sketch starts
void setup() {
   #ifdef __DEBUG
       Serial.begin(9600);
   #endif

   setPwmFrequency(RING_PIN,PWM_SCALING);

   ringDriver.init();

   // Header line for CSV debug output
   #ifdef __DEBUG
       Serial.println("reading diff;deviation;duty cycle;");
   #endif
}

// the loop() method runs over and over again, as long as the Arduino has power.
void loop() {
    loopCount += 1;

    if(loopCount % CONTROLLER_PARAM_UPDATE_INTERVAL == 0) {
        controller.readParameters();
    }

    #define POSITION_ZERO 100

    int* sensorReadings = positionSensor.read();
    int position = sensorReadings[BOTTOM] - sensorReadings[TOP];
    int level = controller.control(position);

    ringDriver.drive(level);

    // Add line to CSV debug output
    #ifdef __DEBUG
        //Serial.print(positions[BOTTOM]);
        //Serial.print(";");
        //Serial.print(positions[TOP]);
        //Serial.print(";");
        Serial.print(position);
        Serial.print(";");
        Serial.print(level);
        Serial.print(";");

        Serial.println("");
    #endif
}

int main(void) {

    init();
    setup();

    while (true) {
        loop();
    }
}
