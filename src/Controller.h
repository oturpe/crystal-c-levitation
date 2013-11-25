/*
 * Controller.h
 *
 *  Created on: 14.11.2013
 *      Author: Otto Urpelainen
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

class Controller {
public:
    /**
     * Creates and initializes a new controller for transforming position
     * values into duty cycle.
     *
     * Controller responds to user input by reading analog values from
     * potentiometers and tuning its parameters by them.
     *
     * @param setpointPin analog pin for operating point
     * @param coeffPin analog pin for coefficient
     */
    Controller(int setpointPin,int coeffPin);

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
     * Reads desired control values from input pins.
     */
    void readParameters();

private:
    /** Private default constructor to prevent usage. */
    Controller();

    /** Analog pin for reading desired setpoint. */
    int setpointPin;

    /** Analog pin for reading desired coefficient. */
    int coeffPin;

    /** Last read value of setpoint. */
    float setpoint;

    /** Last read value of coefficient. */
    float coeff;
};

#endif /* CONTROLLER_H_ */
