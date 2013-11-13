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

int level = LEVEL_MIN;

RingDriver ringDriver(RING_PIN);

PositionSensor positionSensor(SENSOR_PIN_BOTTOM,SENSOR_PIN_TOP);

// The setup() method runs once, when the sketch starts
void setup() {
   #ifdef __DEBUG
       Serial.begin(9600);
   #endif

   setPwmFrequency(RING_PIN,PWM_SCALING);

   ringDriver.init();

   // Header line for CSV debug output
   #ifdef __DEBUG
       Serial.println("duty cycle;bottom position;top position;position diff;deviation;");
   #endif
}

// the loop() method runs over and over again, as long as the Arduino has power.
void loop() {
    //delay(WAIT);

    #define POSITION_ZERO 110
    #define CONTROLLER_OFFSET 100
    #define CONTROLLER_COEFF -2

    int* positions = positionSensor.read();
    int positionDiff = positions[BOTTOM] - positions[TOP];
    int position = positionDiff - POSITION_ZERO;

    level = (CONTROLLER_COEFF * position) + CONTROLLER_OFFSET;
    if(level > 255) {
        level = 255;
    }

    ringDriver.drive(level);

    // Add line to CSV debug output
    #ifdef __DEBUG
        Serial.print(level);
        Serial.print(";");
        Serial.print(positions[BOTTOM]);
        Serial.print(";");
        Serial.print(positions[TOP]);
        Serial.print(";");
        Serial.print(positionDiff);
        Serial.print(";");
        Serial.print(position);
        Serial.print(";");

        Serial.println("");
    #endif

    // Test stuff: ramping
    if (level < LEVEL_MAX) {
        level += INC;
    }
}

int main(void) {

    init();
    setup();

    while (true) {
        loop();
    }
}
