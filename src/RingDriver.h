/*
 * RingDriver.h
 *
 *  Created on: 5.11.2013
 *      Author: Otto Urpelainen
 */

#ifndef RINGDRIVER_H_
#define RINGDRIVER_H_

/**
 * Controls PWM output to give correct amount of power to transistors driving
 * magnet-below subsystem's electromagnet ring.
 *
 * Currently, only controls one output pin to be used for all magnets in the
 * ring.
 */
class RingDriver {
public:
    /**
     * Initializes a new ring driver.
     *
     * @param ringSize the amount of ring magnets
     * @param ringPins array of pin numbers for magnets
     */
    RingDriver(int ringSize, int ringPins[]);

    /**
     * Initializes the driver for use. Output pins are prepared for PWM use and
     * set to zero duty cycle. This method must be the first one called.
     */
    void init();

    /**
     * Drives ring with specified duty cycles. Duty cycles is given as array of
     * 8-bit values, one value for each ring pin. Value of 0 is 0 % and 255 is
     * 100 %.
     *
     * @param dutyCycles duty cycle
     */
    void drive(int dutyCycles[]);

private:
    /**
     * Private default constructor to prevent usage.
     */
    RingDriver();

    /** Amount of output pints */
    int ringSize;

    /** Array of output pins for PWM */
    int * ringPins;
};

#endif /* RINGDRIVER_H_ */
