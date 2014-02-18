/*
 * Parameterized.cpp
 *
 *  Created on: 17.2.2014
 *      Author: Otto Urpelainen
 */

// In-project dependencies
#include "Parameterized.h"

Parameterized::~Parameterized() {
}

Parameterized::Parameterized(int dataSize) : dataSize(dataSize) {
}

void Parameterized::allocateEeprom(int & offset) {
    this->offset = offset;
    offset += this->dataSize;
}
