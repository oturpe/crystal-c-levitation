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
#define WAIT 1000
#define INC 5

// Smoothing of position values
#define POSITION_SAMPLES 3
#define POSITION_SAMPLE_DELAY 1

// Pins to use
#define RING_PIN 6
#define SENSOR_PIN_BOTTOM 4
#define SENSOR_PIN_TOP 3
#define CONTROLLER_PIN_OP 0
#define CONTROLLER_PIN_OFFSET 1
#define CONTROLLER_PIN_COEFF 2

// PWM control
//
// Note that different PWM pins have different base frequency and accept only
// certain scaling values. See file lib/ArduinoPwm.cpp for details
#define PWM_SCALING 8

// User input for controller parameters
#define CONTROLLER_COEFF_MIN 0.0
#define CONTROLLER_COEFF_MAX 20.0
#define CONTROLLER_OFFSET_MIN 0.0
#define CONTROLLER_OFFSET_MAX 400.0
#define CONTROLLER_OP_MIN 0.0
#define CONTROLLER_OP_MAX 120.0

// How many loop cycles between one update of controller parameters.
#define CONTROLLER_PARAM_UPDATE_INTERVAL 10

#endif /* CRYSTALCLEVITATION_H_ */
