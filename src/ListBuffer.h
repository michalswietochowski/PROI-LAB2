//
// Created by Michał Świętochowski on 18.12.2013.
// Copyright (c) 2013 Michal Swietochowski. All rights reserved.
//


#include <sstream>
#include "AbstractBuffer.h"

#ifndef __ListBuffer_H_
#define __ListBuffer_H_

template <typename T>
class ListBuffer : public AbstractBuffer<T> {
    struct ListElement {
        T value;
        ListElement *next;

        ListElement() {
            this->next = 0;
        }

        ListElement(const ListElement &element) {
            this->value = element.value;
            this->next = 0;
        }

        ListElement(T element) {
            this->next = 0;
            this->value = element;
        }
    };

    ListElement *first;
    ListElement *last;

public :
    /**
     * Constructor
     * @param int size size of buffer
     */
    ListBuffer<T>(int size) {
        this->first = 0;
        this->last = 0;
        this->count = 0;
    }

    /**
     * Copy constructor
     */
    ListBuffer<T>(const ListBuffer &buffer) {
        this->first = 0;
        this->last = 0;
        this->count = 0;
        T *elements = buffer.getElements();
        int count = buffer.getCount();
        for (int i = 0; i < count; i++) {
            this->write(elements[i]);
        }
    }

    /**
     * Destructor
     */
    ~ListBuffer() {
        delete last;
        while (first) {
            ListElement *temp = first;
            first = first->next;
            delete temp;
        }
    }

    /*
     * Getters
     */
    ListElement *getFirst() const {
        return first;
    }

    ListElement *getLast() const {
        return last;
    }

    T *getElements() const {
        T *elements = new T[this->count];
        ListElement *element = first;
        int i = 0;
        while (element != NULL) {
            elements[i] = element->value;
            i++;
            element = element->next;
        }
        return elements;
    }

    /**
     * Write to buffer
     * @param T element
     * @return void
     */
    void write(T element) {
        ListElement *newElement = new ListElement(element);

        if (!first) {
            first = newElement;
            last = newElement;
        } else {
            //mala optymalizacja polegajaca na przechowywaniu wskaznika do ostatnio zapisanego elementu,
            //ale daje duze efekty wydajnosciowe w porownaniu do kazdorazowej iteracji przez cala liste
//            ListElement *last = first;
//            while (last->next != NULL) {
//                last = last->next;
//            }
            ListElement *oldLast = last;
            last->next = newElement;
            last = newElement;
        }
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
        T *element = &first->value;
        if (first->next == first) {
            first = 0;
        } else {
            first = first->next;
        }
        --this->count;
        return element;
    }

    /**
     * Clears the buffer and resets pointers
     * @return void
     */
    void clear() {
        while (first) {
            ListElement *temp = first;
            first = first->next;
            delete temp;
        }
        this->first = 0;
        this->last = 0;
        this->count = 0;
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
        return false;
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
        for (int i = 0; i < this->count; i++) {
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

        for (int i = 0; i < this->count; i++) {
            char str[20];
            sprintf(str, "%5d", i);
            bufferAsString.append(str);
            bufferAsString.append(" | ");
        }
        bufferAsString.append("\n");
        bufferAsString.append(horizontalLine);

        //values
        bufferAsString.append("| Value | ");

        if (first) {
            ListElement *element = first;
            while (element != NULL) {
                char str[20];
                ostringstream ss;
                ss << element->value;
                sprintf(str, "%5s", ss.str().c_str());
                bufferAsString.append(str);
                bufferAsString.append(" | ");
                element = element->next;
            }
        }
        bufferAsString.append("\n");
        bufferAsString.append(horizontalLine);

        if (first) {

        }
        return bufferAsString;
    }

};


#endif //__ListBuffer_H_
