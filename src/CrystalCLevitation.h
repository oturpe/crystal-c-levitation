/*
 * CrystalCLevitation.h
 *
 * Defines
 *
 *  Created on: 5.11.2013
 *      Author: Otto Urpelainen
 */

#ifndef CRYSTALCLEVITATION_H_
#define CRYSTALCLEVITATION_H_

// If defined, compile debug serial prints etc.
#define __DEBUG

// Test code: ramping duty cycle
#define LEVEL_MIN 0
#define LEVEL_MAX 255
#define WAIT 500
#define INC 5

// Smoothing of position values
#define POSITION_SAMPLES 3
#define POSITION_SAMPLE_DELAY 10

// Pins to use
#define RING_PIN 6
#define SENSOR_PIN 4

// PWM control
// Note that different PWM pins have different base frequency and accept only
// certain scaling values. See file lib/ArduinoPwm.cpp for details
#define PWM_SCALING 8

#endif /* CRYSTALCLEVITATION_H_ */
