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
     * @param bottomPin analog input pin of bottom sensor
     * @param topPin analog input pin of top sensor
     */
    PositionSensor(int bottomPin, int topPin);

    /**
     * Read sensor and returns position values of both sensors. Values are
     * returned as array of two integers in order (bottom,top). Values are
     * between 0 and 1023 (i.e. 10-bit unsigned).
     *
     * Returned array is used internally by this class and should not be
     * modified by caller nor expected to be retain its values after subsequent
     * method calls.
     *
     * @return pointer to position values
     */
    int* read();

private:
    /**
     * Private default constructor to prevent usage.
     */
    PositionSensor();

    /** Analog in pin of bottom sensor. */
    int bottomPin;

    /** Analog pin of top sensor. */
    int topPin;

    /** Cyclic buffer for position values. Element at [x][y] is */
    int positions[POSITION_SAMPLES][2];

    /** Cursor to positions buffer.*/
    int positionCursor;

    /** Sum of all position values in the buffer. */
    int smoothPositions[2];

    /** Rolling average calculated from smooth positions. */
    int rollingAverage[2];
};

#endif /* POSITIONSENSOR_H_ */
