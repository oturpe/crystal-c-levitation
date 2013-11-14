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
     * @param operatingPointPin analog pin for operating point
     * @param offsetPin analog pin for offset
     * @param coeffPin analog pin for coefficient
     */
    Controller(int operatingPointPin,int offsetPin,int coeffPin);

    /**
     * Given new position value, returns duty cycle. Duty cycle is given as
     * value between 0 and 255 (i.e. 8-bit value).
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

    /** Analog pin for reading desired operating point. */
    int operatingPointPin;

    /** Analog pin for reading desired offset. */
    int offsetPin;

    /** Analog pin for reading desired coefficient. */
    int coeffPin;

    /** Last read value of operating point. */
    float operatingPoint;

    /** Last read value of desired offset. */
    float offset;

    /** Last read value of coefficient. */
    float coeff;
};

#endif /* CONTROLLER_H_ */
