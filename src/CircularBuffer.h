//
// Created by Michał Świętochowski on 18.12.2013.
// Copyright (c) 2013 Michal Swietochowski. All rights reserved.
//

#include <sstream>
#include <cmath>
#include "AbstractBuffer.h"

#ifndef __CircularBuffer_H_
#define __CircularBuffer_H_

template <typename T>
class CircularBuffer : public AbstractBuffer<T> {
    /**
     * initial size of buffer
     */
    int initialSize;
    /**
     * size of buffer
     */
    int size;
    /**
     * oldest element index
     */
    int start;
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
        this->initialSize = size;
        this->size = size;
        this->start = 0;
        this->count = 0;
        this->elements = new T[this->size];
    }

    /**
     * Copy constructor
     */
    CircularBuffer<T>(const CircularBuffer &buffer) {
        this->initialSize = buffer.getInitialSize();
        this->size = buffer.getSize();
        this->start = buffer.getStart();
        this->count = buffer.getCount();
        this->elements = new T[this->size];
        T *sourceElements = buffer.getElements();
        for (int i = 0; i <= this->count; i++) {
            this->elements[i] = sourceElements[i];
        }
    }

    /**
     * Destructor
     */
    ~CircularBuffer() {
        delete [] this->elements;
    }

    /*
     * Getters
     */
    int getInitialSize() const {
        return this->initialSize;
    }

    int getSize() const {
        return this->size;
    }

    int getStart() const {
        return this->start;
    }

    T *getElements() const {
        return this->elements;
    }

    /**
     * Write to buffer
     * @param T element
     * @return void
     */
    void write(T element) {
        if (this->isFull()) {
            if (!this->increaseBuffer()) {
                string exceptionMessage = "Cannot increase buffer size, element dropped";
                throw exceptionMessage;
            }
        }
        this->elements[this->count] = element;
        ++this->count;
    }

    /**
     * Read from buffer
     * @return Element
     */
    T *read() {
        if (isEmpty()) {
            string exceptionMessage = "Buffer is empty";
            throw exceptionMessage;
        }
        T *element = &this->elements[this->start];
        ++this->start;
        --this->count;
        this->optimizeBuffer();
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
            if (i > this->start + this->count - 1) {
                sprintf(str, "%5s", "");
            } else {
                ostringstream ss;
                ss << this->elements[i];
                sprintf(str, "%5s", ss.str().c_str());
            }
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
        bufferAsString.append("Size = ");
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
        bufferAsString.append("\n");

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

    int getSizeChangeThreshold(int size) {
        return (int) floor((double) size / 2);
    }

    /**
     * increases buffer size to fit new elements
     */
    bool increaseBuffer() {
        int newSize = this->size + this->getSizeChangeThreshold(this->size);
        T *newElements = new T[newSize];
        for (int i = 0; i < this->size; i++) {
            newElements[i] = this->elements[i];
        }
        this->elements = newElements;
        this->size = newSize;
//        cout << "  + Increased buffer size to: " << newSize << endl;
        return true;
    }

    /**
     * optimizes buffer size when there are too many empty cells
     */
    void optimizeBuffer() {
        //reset buffer if it is empty
        if (isEmpty()) {
            this->clear();
            return;
        }
        int newSize = this->getSizeChangeThreshold(this->size);
        //do not resize if it is smaller than calculated part of initial size
        if (newSize < this->getSizeChangeThreshold(this->initialSize)) {
            return;
        }
        //resize if there are less elements than calculated size
        if (this->count <= newSize) {
            T *newElements = new T[newSize];
            int end = this->start + this->count;
            int j = 0;
            for (int i = this->start; i < end; i++) {
                newElements[j++] = this->elements[i];
            }
            this->elements = newElements;
            this->size = newSize;
            this->start = 0;
//            cout << "  - Decreased buffer size to: " << newSize << endl;
        }
    }
};


#endif //__CircularBuffer_H_
