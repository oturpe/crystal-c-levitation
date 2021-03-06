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
// Note that serial prints my take so much time that they may break operation.
// Using high debug serial speeds helps
#define __DEBUG
#define DEBUG_PRINT_BAUDRATE 57600
#define DEBUG_PRINT_INTERVAL 500
// How many loop cycles between one update of controller parameters.
#define CONTROLLER_PARAM_UPDATE_INTERVAL 2500


// Smoothing of position values
#define POSITION_SAMPLES 5

// Digital pins to use
#define RING_PIN 3
#define SENSOR_RESET_PIN 4

// Analog pins to use
#define SENSOR_PIN 4
#define CONTROLLER_PIN_OP 0
#define CONTROLLER_PIN_COEFF 2

// PWM control
//
// Note that different PWM pins have different base frequency and accept only
// certain scaling values. See file lib/ArduinoPwm.cpp for details
#define PWM_SCALING 128

#define SENSOR_QUIESCENT_TOLERANCE 10

// User input for controller parameters
#define CONTROLLER_COEFF_MIN 0.5
#define CONTROLLER_COEFF_MAX 30.0
#define CONTROLLER_OFFSET_MIN 0.0
#define CONTROLLER_OFFSET_MAX 400.0
#define CONTROLLER_OP_MIN 150.0
#define CONTROLLER_OP_MAX 300.0

#endif /* CRYSTALCLEVITATION_H_ */
