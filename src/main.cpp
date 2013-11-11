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
#define WAIT 100
#define INC 1
#define RING_SIZE 3

int levels[RING_SIZE] = {100,0,0};
int maxLevels[RING_SIZE] = {110,50,255};

int ringPins[3] = {9,10,11};
RingDriver ringDriver(RING_SIZE,ringPins);

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

//    if (level < LEVEL_MAX) {
//        ringDriver.drive(level);
//        level += INC;
    for(int i = 0; i < RING_SIZE; i++) {
        if(levels[i] < maxLevels[i]) {
            levels[i] += INC;
            if (levels[i] > 255) {
                levels[i] = 255;
            }
        }
    }

    int position = positionSensor.read();
    ringDriver.drive(levels);
}

int main(void) {

    init();
    setup();

    while (true) {
        loop();
    }
}
