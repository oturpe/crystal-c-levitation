/*
 * EEPROMAnything.h
 *
 *  Created on: 18.2.2014
 *      Author: Otto Urpelainen
 *
 * Copied from Arduino forums. An extension to Arduino standard EEPROM library
 * to conveniently save values of different types.
 */

#ifndef EEPROMANYTHING_H_
#define EEPROMANYTHING_H_

#include "Arduino.h"
#include "EEPROM.h"

template <class T> int EEPROM_writeAnything(int ee, const T& value)
{
    const byte* p = (const byte*)(const void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          EEPROM.write(ee++, *p++);
    return i;
}

template <class T> int EEPROM_readAnything(int ee, T& value)
{
    byte* p = (byte*)(void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          *p++ = EEPROM.read(ee++);
    return i;
}

#endif /* EEPROMANYTHING_H_ */
