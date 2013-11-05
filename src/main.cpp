#include "CrystalCLevitation.h"
#include "Arduino.h"
#include "new.h"
#include "RingDriver.h"

int level = 0;
#define LEVEL_MAX 10

#define RING_PIN 3
RingDriver ringDriver(RING_PIN);

// The setup() method runs once, when the sketch starts
void setup() {
   #ifdef __DEBUG
       Serial.begin(9600);
       Serial.println("At setup.");
   #endif

   ringDriver.init();
}

// the loop() method runs over and over again, as long as the Arduino has power.
void loop() {
    delay(250);

    if (level < LEVEL_MAX) {
        ringDriver.drive(level);
        level += 1;
    }
}

int main(void) {

    init();
    setup();

    while (true) {
        loop();
    }
}
