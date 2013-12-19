//
// Created by Michał Świętochowski on 18.12.2013.
// Copyright (c) 2013 Michal Swietochowski. All rights reserved.
//


#include "AbstractBuffer.h"

#ifndef __CircularBuffer_H_
#define __CircularBuffer_H_

template <typename T>
class CircularBuffer : public AbstractBuffer<T> {
public:
    /**
     * Constructor
     * @param int size size of buffer
     */
    CircularBuffer(int size);

    /**
     * Copy constructor
     */
    CircularBuffer(const CircularBuffer &buffer);

    /**
     * Write to buffer
     * @param T element
     * @return void
     */
    void write(T &element);
    /**
     * Read from buffer
     * @return Element
     */
    T* read();
    /**
     * Clears the buffer and resets pointers
     * @return void
     */
    void clear();
    /**
     * Tells if buffer is empty
     * @return bool
     */
    bool isEmpty();
    /**
     * Tells if buffer is full
     * @return bool
     */
    bool isFull();
    /**
     * Represent buffer as string to print in console
     * @return string
     */
    string toString();
};


#endif //__CircularBuffer_H_
