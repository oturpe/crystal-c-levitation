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
     */
    PositionSensor(int sensorPin);

    /**
     * Read sensor and returns position value. Values are between 0 and 1023
     * (i.e. 10-bit unsigned).
     *
     * @return position
     */
    int read();

private:
    /**
     * Private default constructor to prevent usage.
     */
    PositionSensor();

    /** Analog in pin of sensor. */
    int sensorPin;

    /** Cyclic buffer for position values. */
    int positions[POSITION_SAMPLES];

    /** Cursor to positions buffer.*/
    int positionCursor;

    /**
     * Sum of all position values in the buffer. Used to calculate rolling
     * average.
     * */
    int smoothPosition;
};

#endif /* POSITIONSENSOR_H_ */
