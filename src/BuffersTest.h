//
// Created by Michał Świętochowski on 18.12.2013.
// Copyright (c) 2013 Michal Swietochowski. All rights reserved.
//


#ifndef __BuffersTest_H_
#define __BuffersTest_H_

#include <ctime>
#include <iomanip>
#include "AbstractBuffer.h"
#include "ListBuffer.h"
#include "CircularBuffer.h"

using namespace std;

class BuffersTest {
public:
    BuffersTest();

    void startTests();

    void resizingTest(AbstractBuffer<int> &buffer);

    void performanceTest(AbstractBuffer<int> &buffer);
    void performanceTest(AbstractBuffer<double> &buffer);
    void performanceTest(AbstractBuffer<string> &buffer);

    string formatInterval(clock_t start, clock_t end);
};


#endif //__BuffersTest_H_
