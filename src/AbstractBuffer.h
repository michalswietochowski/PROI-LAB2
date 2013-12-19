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

public:
    /**
     *
     */
    AbstractBuffer() {

    }

    /**
     * Constructor
     * @param int size size of buffer
     */
    AbstractBuffer(int size) {

    }

    /**
     * Copy constructor
     */
    AbstractBuffer(const AbstractBuffer &buffer) {

    }

    /*
     * Getters
     */
    int getSize() const {
        return size;
    }

    int getStart() const {
        return start;
    }

    int getCount() const {
        return count;
    }

    virtual T *getElements() const = 0;

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
    virtual T *read() = 0;

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
     * @param T element
     * @return AbstractBuffer&
     */
    AbstractBuffer &operator += (T element) {
        this->write(element);
        return *this;
    }

    /**
     * Shorthand for toString() method
     * @param ostream output
     * @param AbstractBuffer& buffer
     * @return ostream&
     */
    friend ostream &operator <<(ostream &output, AbstractBuffer &buffer) {
        return output << buffer.toString();
    }

    /**
     * Read Element from buffer
     * @param AbstractBuffer buffer
     * @param T& element
     * @return T&
     */
    friend T &operator >>(AbstractBuffer &buffer, T &element) {
        if (!buffer.isEmpty()) {
            element = buffer.read();
        }
        return element;
    }

    /**
     * Write Element to buffer (other way - by << operator)
     * @param AbstractBuffer buffer
     * @param T element
     * @return AbstractBuffer
     */
    friend T &operator <<(AbstractBuffer &buffer, T element) {
        buffer += element;
        return buffer;
    }

    /**
     * Write Element to buffer (other way - by + operator)
     * @param AbstractBuffer buffer
     * @param T element
     * @return AbstractBuffer
     */
    friend AbstractBuffer &operator +(AbstractBuffer &buffer, T element) {
        buffer += element;
        return buffer;
    }

    /**
     * Write Element to buffer (other way - by + operator commutative)
     * @param Element element
     * @param AbstractBuffer buffer
     * @return AbstractBuffer
     */
    friend AbstractBuffer &operator +(T element, AbstractBuffer &buffer) {
        return buffer + element;
    }
};

#endif //__AbstractBuffer_H_
