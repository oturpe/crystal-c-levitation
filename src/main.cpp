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

PositionSensor positionSensor(SENSOR_PIN);

// The setup() method runs once, when the sketch starts
void setup() {
   #ifdef __DEBUG
       Serial.begin(9600);
   #endif

   setPwmFrequency(11,256);

   ringDriver.init();

   // Header line for CSV debug output
   #ifdef __DEBUG
       Serial.println("duty cycle;position;");
   #endif
}

// the loop() method runs over and over again, as long as the Arduino has power.
void loop() {
    delay(WAIT);

    ringDriver.drive(level);
    int position = positionSensor.read();

    // Add line to CSV debug output
    #ifdef __DEBUG
        Serial.print(level);
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
