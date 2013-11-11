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

// Test code: ramp up magnet slowly
int level = 0;
#define LEVEL_MAX 10
#define WAIT 100
#define INC 1

#define RING_PIN 11
RingDriver ringDriver(RING_PIN);

#define SENSOR_PIN 4
PositionSensor positionSensor(SENSOR_PIN);

// The setup() method runs once, when the sketch starts
void setup() {
   #ifdef __DEBUG
       Serial.begin(9600);
       Serial.println("At setup.");
   #endif

   setPwmFrequency(11,256);
   ringDriver.init();
}

// the loop() method runs over and over again, as long as the Arduino has power.
void loop() {
    delay(WAIT);

    if (level < LEVEL_MAX) {
        ringDriver.drive(level);
        level += INC;
    }

    int position = positionSensor.read();
}

int main(void) {

    init();
    setup();

    while (true) {
        loop();
    }
}
