//
// Created by Michał Świętochowski on 18.12.2013.
// Copyright (c) 2013 Michal Swietochowski. All rights reserved.
//


#ifndef __AbstractBuffer_H_
#define __AbstractBuffer_H_

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class AbstractBuffer {
protected:
    /**
     * size of buffer
     */
    int size;
    /**
     * oldest element index
     */
    int start;
    /**
     * elements count
     */
    int count;
    /**
     * vector of elements
     */
    T *elements;

public:
    /**
    *
    */
    AbstractBuffer();
    /**
     * Constructor
     * @param int size size of buffer
     */
    AbstractBuffer(int size);

    /**
     * Copy constructor
     */
    AbstractBuffer(const AbstractBuffer &buffer);

    /*
     * Getters
     */
    int getSize() const { return size; }
    int getStart() const { return start; }
    int getCount() const { return count; }
    T* getElements() const { return elements; }

    /**
     * Write to buffer
     * @param T element
     * @return void
     */
    virtual void write(T &element) = 0;
    /**
     * Read from buffer
     * @return Element
     */
    virtual T* read() = 0;
    /**
     * Clears the buffer and resets pointers
     * @return void
     */
    virtual void clear() = 0;
    /**
     * Tells if buffer is empty
     * @return bool
     */
    virtual bool isEmpty() = 0;
    /**
     * Tells if buffer is full
     * @return bool
     */
    virtual bool isFull() = 0;
    /**
     * Represent buffer as string to print in console
     * @return string
     */
    virtual string toString() = 0;

    /**
     * Write Element to buffer
     * @param Element element
     * @return AbstractBuffer&
     */
    AbstractBuffer& operator+=(T element) {
        this->write(element);
        return *this;
    }
};

#endif //__AbstractBuffer_H_
