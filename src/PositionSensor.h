/*
 * PositionSensor.h
 *
 *  Created on: 11.11.2013
 *      Author: Otto Urpelainen
 */

#ifndef POSITIONSENSOR_H_
#define POSITIONSENSOR_H_

class PositionSensor {
public:
    /**
     * Creates and initializes a new position sensor.
     *
     * @param sensorPin analog input pin of sensor
     */
    PositionSensor(int sensorPin);

    /**
     * Read sensor and returns position value between 0 and 1023.
     *
     * @return position value
     */
    int read();

private:
    /**
     * Private default constructor to prevent usage.
     */
    PositionSensor();

    /** Ananlog in pin of sensor. */
    int sensorPin;
};

#endif /* POSITIONSENSOR_H_ */
