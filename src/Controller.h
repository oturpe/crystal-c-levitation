/*
 * Controller.h
 *
 *  Created on: 14.11.2013
 *      Author: Otto Urpelainen
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

// In-project dependencies
#include "Parameterized.h"

/**
 * Transforms position values to duty cycles. Controller responds to user input
 * by reading analog values from potentiometers and tuning its parameters
 * accordingly. Control is of P-type.
 *
 * This class is Parameterized. Parameters are the coefficient and set point of
 * control.
 */
class Controller: public Parameterized {

public:
    /**
     * Creates and initializes a new controller for transforming position
     * values into duty cycle.
     *
     * @param setpointPin analog pin for operating point
     * @param coeffPin analog pin for coefficient
     */
    Controller(int coeffPin, int setpointPin);

    /**
     * Given new position value, returns duty cycle. Duty cycle is given as
     * value between 0 and 255 (i.e. 8-bit value). Negative position value
     * is interpreted as instruction to shut down the magnet, i.e. zero duty
     * cycle is returned.
     *
     * @param position position reading.
     *
     * @return duty cycle
     */
    int control(int position);

    /**
     * @copydoc Parameterized::readParameters()
     */
    virtual void readParameters();

    /**
     * @copydoc Parameterized::updateParameters()
     *
     * Parameters are coefficient and set point, which can be read at any time.
     */
    virtual void updateParameters();

    /**
     * @copydoc Parameterized::writeParameters()
     */
    virtual void writeParameters();

private:
    /** Private default constructor to prevent usage. */
    Controller();

    /** Last read value of coefficient. */
    float coeff;

    /** Analog pin for reading desired coefficient. */
    int coeffPin;

    /** Last read value of setpoint. */
    float setpoint;

    /** Analog pin for reading desired setpoint. */
    int setpointPin;
};

#endif /* CONTROLLER_H_ */
