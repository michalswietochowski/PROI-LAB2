//
// Created by Michał Świętochowski on 18.12.2013.
// Copyright (c) 2013 Michal Swietochowski. All rights reserved.
//

#include <sstream>
#include "AbstractBuffer.h"

#ifndef __CircularBuffer_H_
#define __CircularBuffer_H_

template <typename T>
class CircularBuffer : public AbstractBuffer<T> {
    /**
     * vector of elements
     */
    T *elements;

public:
    /**
     * Constructor
     * @param int size size of buffer
     */
    CircularBuffer<T>(int size) {
        this->size = size;
        this->start = 0;
        this->count = 0;
        this->elements = new T[this->size];
    }

    /**
     * Copy constructor
     */
    CircularBuffer<T>(const CircularBuffer &buffer) {

    }

    T *getElements() const {
        return this->elements;
    }

    /**
     * Write to buffer
     * @param T element
     * @return void
     */
    void write(T &element) {
        int end = (this->start + this->count) % this->size;
        this->elements[end] = element;

        if (this->count == this->size) {
            this->start = (this->start + 1) % this->size;
        } else {
            ++this->count;
        }
    }

    /**
     * Read from buffer
     * @return Element
     */
    T *read() {
        if (isEmpty()) {
            return NULL;
        }
        T *element = &this->elements[this->start];
        this->start = (this->start + 1) % this->size;
        --this->count;
        return element;
    }

    /**
     * Clears the buffer and resets pointers
     * @return void
     */
    void clear() {
        this->start = 0;
        this->count = 0;

        for (int i = 0; i < this->size; i++) {
            this->elements[i] = T();
        }
    }

    /**
     * Tells if buffer is empty
     * @return bool
     */
    bool isEmpty() {
        return this->count == 0;
    }

    /**
     * Tells if buffer is full
     * @return bool
     */
    bool isFull() {
        return this->count == this->size;
    }

    /**
     * Represent buffer as string to print in console
     * @return string
     */
    string toString() {
        int padding = 5, margin = 1;
        int cellWidth = padding + 2 * margin;

        //create horizontal line
        string horizontalLine = "+-------+";
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < cellWidth; j++) {
                horizontalLine.append("-");
            }
            horizontalLine.append("+");
        }
        horizontalLine.append("\n");

        //add horizontal line
        string bufferAsString = "";
        bufferAsString.append(horizontalLine);

        //indexes
        bufferAsString.append("| Index | ");

        for (int i = 0; i < this->size; i++) {
            char str[20];
            sprintf(str, "%5d", i);
            bufferAsString.append(str);
            bufferAsString.append(" | ");
        }
        bufferAsString.append("\n");
        bufferAsString.append(horizontalLine);

        //values
        bufferAsString.append("| Value | ");

        for (int i = 0; i < this->size; i++) {
            char str[20];
            ostringstream ss;
            ss << this->elements[i];
            sprintf(str, "%5s", ss.str().c_str());
            bufferAsString.append(str);
            bufferAsString.append(" | ");
        }
        bufferAsString.append("\n");
        bufferAsString.append(horizontalLine);

        //start
        bufferAsString.append("| Start | ");

        for (int i = 0; i < this->size; i++) {
            if (i == this->start) {
                bufferAsString.append("    ^");
            } else {
                bufferAsString.append("     ");
            }
            bufferAsString.append(" | ");
        }
        bufferAsString.append("\n");
        bufferAsString.append(horizontalLine);

        //size
        bufferAsString.append("\nSize = ");
        char str[20];
        sprintf(str, "%d", this->size);
        bufferAsString.append(str);

        //count
        bufferAsString.append(", Count = ");
        sprintf(str, "%d", this->count);
        bufferAsString.append(str);

        //empty
        bufferAsString.append(", Empty = ");
        if (isEmpty()) {
            bufferAsString.append("YES");
        } else {
            bufferAsString.append("NO");
        }

        //full
        bufferAsString.append(", Full = ");
        if (isFull()) {
            bufferAsString.append("YES");
        } else {
            bufferAsString.append("NO");
        }

        return bufferAsString;
    }

    /**
     * Write Element to buffer
     * @param T element
     * @return CircularBuffer&
     */
    CircularBuffer &operator += (T element) {
        this->write(element);
        return *this;
    }
};


#endif //__CircularBuffer_H_
