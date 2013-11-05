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
     * @param ringPin output pin for PWM.
     */
    RingDriver(int ringPin);

    /**
     * Initializes the driver for use. Output pin is prepared for PWM use and
     * set to zero duty cycle. This method must be the first one called.
     */
    void init();

    /**
     * Drives ring with specified duty cycle. Duty cycle is given as 8-bit
     * value where 0 is 0 % and 255 is 100 %.
     *
     * @param dutyCycle duty cycle
     */
    void drive(int dutyCycle);

private:
    /**
     * Private default constructor to prevent usage.
     */
    RingDriver();

    /** Output pin for PWM */
    int ringPin;
};

#endif /* RINGDRIVER_H_ */
