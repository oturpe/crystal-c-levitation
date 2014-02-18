/*
 * PositionSensor.h
 *
 *  Created on: 11.11.2013
 *      Author: Otto Urpelainen
 */

#ifndef POSITIONSENSOR_H_
#define POSITIONSENSOR_H_

#include "Parameterized.h"

enum POSITIONS {
    BOTTOM = 0,
    TOP,
    SIZE
};

/**
 * Class to interact with Hall effect sensor connected to a single analog in
 * pin of the microcontroller. Performs smoothing of readings and supports
 * resetting to quiescent state.
 *
 * This class is Parameterized, containing only one parameter: the quiescent
 * state reading.
 */
class PositionSensor : public Parameterized {

public:
    /**
     * Creates and initializes a new position sensor.
     *
     * @param sensorPin analog input pin of sensor
     */
    PositionSensor(int sensorPin);

    /**
     * @copydoc Parameterized::readParameters()
     */
    virtual void readParameters();

    /**
     * Read sensor and returns position value. Values are between 0 and 1023
     * (i.e. 10-bit unsigned). If levitating object is not detected, returns
     * a negative value.
     *
     * @return position
     */
    int read();

    /**
     * @copydoc Parameterized::updateParameters()
     *
     * The parameter to update is the quiescent state reading. Thus, this method
     * should be called only when levitating object is not present.
     */
    virtual void updateParameters();

    /**
     * @copydoc Parameterized::writeParameters()
     */
    virtual void writeParameters();

private:

    /**
     * Private default constructor to prevent usage.
     */
    PositionSensor();

    /** Cursor to positions buffer.*/
    int positionCursor;

    /** Cyclic buffer for position values. */
    int positions[POSITION_SAMPLES];

    /** Reading without levitating object. */
    int resetValue;

    /** Analog in pin of sensor. */
    int sensorPin;

    /**
     * Sum of all position values in the buffer. Used to calculate rolling
     * average.
     * */
    int smoothPosition;
};

#endif /* POSITIONSENSOR_H_ */
