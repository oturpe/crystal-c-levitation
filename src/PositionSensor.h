/*
 * PositionSensor.h
 *
 *  Created on: 11.11.2013
 *      Author: Otto Urpelainen
 */

#ifndef POSITIONSENSOR_H_
#define POSITIONSENSOR_H_

enum POSITIONS {
    BOTTOM = 0,
    TOP,
    SIZE
};

class PositionSensor {
public:
    /**
     * Creates and initializes a new position sensor.
     *
     * @param sensorPin analog input pin of sensor
     * @param resetPin digital pin for reset input
     */
    PositionSensor(int sensorPin,int resetPin);

    /**
     * Read sensor and returns position value. Values are between 0 and 1023
     * (i.e. 10-bit unsigned). If levitating object is not detected, returns
     * a negative value.
     *
     * @return position
     */
    int read();

    /**
     * Read parameters from user interface if read button is being pressed.
     * Parameters to read are:
     *
     *     1. Quiescent value.
     */
    void readParameters();

private:
    /**
     * Private default constructor to prevent usage.
     */
    PositionSensor();

    /** Analog in pin of sensor. */
    int sensorPin;

    /** Digital pin for reset. */
    int resetPin;

    /** Cyclic buffer for position values. */
    int positions[POSITION_SAMPLES];

    /** Cursor to positions buffer.*/
    int positionCursor;

    /**
     * Sum of all position values in the buffer. Used to calculate rolling
     * average.
     * */
    int smoothPosition;

    /** Reading without levitating object. */
    int resetValue;
};

#endif /* POSITIONSENSOR_H_ */
