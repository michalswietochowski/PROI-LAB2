//
// Created by Michał Świętochowski on 18.12.2013.
// Copyright (c) 2013 Michal Swietochowski. All rights reserved.
//

#include "CircularBuffer.h"

template <typename T>
CircularBuffer<T>::CircularBuffer(int size) {
    this->size = size;
    this->start = 0;
    this->count = 0;
    this->elements = new T[this->size];
}

template <typename T>
CircularBuffer<T>::CircularBuffer(const CircularBuffer &buffer) {

}

/**
 * Write to buffer
 * @param T element
 * @return void
 */
template <typename T>
void CircularBuffer<T>::write(T &element)
{
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
 * @return T*
 */
template <typename T>
T* CircularBuffer<T>::read()
{
    if (isEmpty()) {
        return NULL;
    }
    T* element = &this->elements[this->start];
    this->start = (this->start + 1) % this->size;
    --this->count;
    return element;
}

/**
 * Clears the buffer and resets pointers
 * @return void
 */
template <typename T>
void CircularBuffer<T>::clear()
{
    this->start = 0;
    this->count = 0;

    for (int i = 0; i < this->size; i++) {
        this->elements[i] = NULL;
    }
}

/**
 * Tells if buffer is empty
 * @return bool
 */
template <typename T>
bool CircularBuffer<T>::isEmpty()
{
    return this->count == 0;
}

/**
 * Tells if buffer is full
 * @return bool
 */
template <typename T>
bool CircularBuffer<T>::isFull()
{
    return this->count == this->size;
}

/**
 * Represent buffer as string to print in console
 * @return string
 */
template <typename T>
string CircularBuffer<T>::toString()
{
    int padding = 5, margin = 1;
    int cellWidth = padding + 2 * margin;

    //create horizontal line
//    string horizontalLine = "+-------+";
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < cellWidth; j++) {
//            horizontalLine.append("-");
//        }
//        horizontalLine.append("+");
//    }
//    horizontalLine.append("\n");
//
//    //add horizontal line
    string bufferAsString = "";
//    bufferAsString.append(horizontalLine);
//
//    //indexes
//    bufferAsString.append("| Index | ");
//
//    for (int i = 0; i < size; i++) {
//        char intStr[20];
//        sprintf(intStr, "%5d", i);
//        bufferAsString.append(intStr);
//        bufferAsString.append(" | ");
//    }
//    bufferAsString.append("\n");
//    bufferAsString.append(horizontalLine);
//
//    //values
//    bufferAsString.append("| Value | ");
//
//    for (int i = 0; i < size; i++) {
//        char intStr[20];
//        sprintf(intStr, "%5d", elements[i].intVal);
//        bufferAsString.append(intStr);
//        bufferAsString.append(" | ");
//    }
//    bufferAsString.append("\n");
//    bufferAsString.append(horizontalLine);
//
//    //start
//    bufferAsString.append("| Start | ");
//
//    for (int i = 0; i < size; i++) {
//        if (i == start) {
//            bufferAsString.append("    ^");
//        } else {
//            bufferAsString.append("     ");
//        }
//        bufferAsString.append(" | ");
//    }
//    bufferAsString.append("\n");
//    bufferAsString.append(horizontalLine);
//
//    //size
//    bufferAsString.append("\nSize = ");
//    char intStr[20];
//    sprintf(intStr, "%d", size);
//    bufferAsString.append(intStr);
//
//    //count
//    bufferAsString.append(", Count = ");
//    sprintf(intStr, "%d", count);
//    bufferAsString.append(intStr);
//
//    //empty
//    bufferAsString.append(", Empty = ");
//    if (isEmpty()) {
//        bufferAsString.append("YES");
//    } else {
//        bufferAsString.append("NO");
//    }
//
//    //full
//    bufferAsString.append(", Full = ");
//    if (isFull()) {
//        bufferAsString.append("YES");
//    } else {
//        bufferAsString.append("NO");
//    }

    return bufferAsString;
}