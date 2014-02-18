/*
 * Parameterized.h
 *
 *  Created on: 17.2.2014
 *      Author: Otto Urpelainen
 */

#ifndef PARAMETERIZED_H_
#define PARAMETERIZED_H_

/**
 * Abstract class representing something that has parameters persisted in
 * eeprom between power-offs.
 *
 * This class works using a specific eeprom memory model. All memory is
 * reserved sequentially and each Parameterized object must know on
 * initialization the amount of eeprom bytes it needs. This amount expected to
 * be passed to Parameterized constructor at initialization time by subclass
 * constructor. Method allocateEeprom()
 * contains some helpers for memory management, but currently the user is
 * responsible for the following memory management tasks.
 *
 * 1. Calling allocateEeprom() for each Parameterized object before using other
 *    eeprom methods.
 * 2. Ensuring that allocateEeprom() calls happen for the same objects in the
 *    same order between different runs. Otherwise the memory offsets do not
 *    match and wrong data is loaded.
 */
class Parameterized {

public:

    /**
     * Destructor.
     */
    virtual ~Parameterized();

    /**
     * Allocates space in eeprom for this object. This method expects that
     * the whole eeprom is allocated sequentially. Reference to address of
     * first free byte is passed in. Upon return, it is updated to still
     * contain the address of first free byte after allocation.
     *
     * @param offset address of first free byte for allocation (in/out)
     */
    void allocateEeprom(int & offset);

    /**
     * Read parameters from eeprom addresses allocated previously. To work
     * correctly, eeprom must have been previously filled with values with
     * writeParameters() method.
     */
    virtual void readParameters() = 0;

    /**
     * Updates parameters from whichever source they are retrieved (usually
     * some user interface part) and saves them locally to object itself. Method
     * allocateEeprom() must be called before this method can be used.
     */
    virtual void updateParameters() = 0;

     /**
     * Save parameters to eeprom addressed allocated previously for later
     * reading with readParameters() method. Method allocateEeprom() must be
     * called before this method can be used.
     */
    virtual void writeParameters() = 0;

protected:

    /**
     * Constructs new Parameterized instance.
     *
     * Protected constructor to prevent direct instantiation. This constructor
     * should be called only by subclass constructors.
     */
    Parameterized(int dataSize);

    /**
     * Returns eeprom address offset of this instance.
     *
     * @return offset
     */
    inline int getOffset();

private:

    /** Number of bytes reserved for these parameters. */
    int dataSize;

    /** First byte of eeprom for these parameters. */
    int offset;
};

#include "Parameterized.inl"

#endif /* PARAMETERIZED_H_ */
