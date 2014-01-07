//
// Created by Michał Świętochowski on 18.12.2013.
// Copyright (c) 2013 Michal Swietochowski. All rights reserved.
//

#include <sstream>
#include "BuffersTest.h"

BuffersTest::BuffersTest() {

}

void BuffersTest::startTests() {
    const unsigned int INITIAL_BUFFER_SIZE = 10;

    ListBuffer<int> intListBuffer(INITIAL_BUFFER_SIZE);
    CircularBuffer<int> intCircularBuffer(INITIAL_BUFFER_SIZE);

    cout << "Resizing test on ListBuffer<int>..." << endl;
    this->resizingTest(intListBuffer);
    intListBuffer.clear();
    cout << intListBuffer << endl;
    cout << "Resizing test on CircularBuffer<int>..." << endl;
    this->resizingTest(intCircularBuffer);
    cout << "Performance test on ListBuffer<int>..." << endl;
    this->performanceTest(intListBuffer);
    cout << "Performance test on CircularBuffer<int>..." << endl;
    this->performanceTest(intCircularBuffer);

    ListBuffer<double> doubleListBuffer(INITIAL_BUFFER_SIZE);
    CircularBuffer<double> doubleCircularBuffer(INITIAL_BUFFER_SIZE);

    cout << "Performance test on ListBuffer<double>..." << endl;
    this->performanceTest(doubleListBuffer);
    cout << "Performance test on CircularBuffer<double>..." << endl;
    this->performanceTest(doubleCircularBuffer);

    ListBuffer<string> stringListBuffer(INITIAL_BUFFER_SIZE);
    CircularBuffer<string> stringCircularBuffer(INITIAL_BUFFER_SIZE);

    cout << "Performance test on ListBuffer<string>..." << endl;
    this->performanceTest(stringListBuffer);
    cout << "Performance test on CircularBuffer<string>..." << endl;
    this->performanceTest(stringCircularBuffer);
}

void BuffersTest::performanceTest(AbstractBuffer<int> &buffer) {
    clock_t start, finish, pstart;
    int count = 10000000;
    try {
        start = pstart = clock();
        cout << "* Writing " << count << " elements to buffer" << endl;
        for (int i = 0; i < count; i++) {
            buffer << i;
        }
        cout << "** Elapsed time: " << formatInterval(pstart, clock()) << endl;
        pstart = clock();
        cout << "* Reading " << count << " elements from buffer" << endl;
        for (int i = 0; i < count; i++) {
            buffer.read();
        }
        finish = clock();
        cout << "** Elapsed time: " << formatInterval(pstart, finish) << endl;
        cout << "*** Test total time: " << formatInterval(start, finish) << endl << endl;
    } catch (string e) {
        cout << "Exception: " << e << endl;
    }
}

void BuffersTest::performanceTest(AbstractBuffer<double> &buffer) {
    clock_t start, finish, pstart;
    double factor = 1.134;
    int count = 10000000;
    try {
        start = pstart = clock();
        cout << "* Writing " << count << " elements to buffer" << endl;
        for (int i = 0; i < count; i++) {
            buffer << (double) i * factor;
        }
        cout << "** Elapsed time: " << formatInterval(pstart, clock()) << endl;
        pstart = clock();
        cout << "* Reading " << count << " elements from buffer" << endl;
        for (int i = 0; i < count; i++) {
            buffer.read();
        }
        finish = clock();
        cout << "** Elapsed time: " << formatInterval(pstart, finish) << endl;
        cout << "*** Test total time: " << formatInterval(start, finish) << endl << endl;
    } catch (string e) {
        cout << "Exception: " << e << endl;
    }
}

void BuffersTest::performanceTest(AbstractBuffer<string> &buffer) {
    clock_t start, finish, pstart;
    string testString = "abc";
    int count = 10000000;
    try {
        start = pstart = clock();
        cout << "* Writing " << count << " elements to buffer" << endl;
        for (int i = 0; i < count; i++) {
            stringstream ss;
            ss << testString << i;
            buffer << ss.str();
        }
        cout << "** Elapsed time: " << formatInterval(pstart, clock()) << endl;
        pstart = clock();
        cout << "* Reading " << count << " elements from buffer" << endl;
        for (int i = 0; i < count; i++) {
            buffer.read();
        }
        finish = clock();
        cout << "** Elapsed time: " << formatInterval(pstart, finish) << endl;
        cout << "*** Test total time: " << formatInterval(start, finish) << endl << endl;
    } catch (string e) {
        cout << "Exception: " << e << endl;
    }
}

void BuffersTest::resizingTest(AbstractBuffer<int> &buffer) {
    int writeCount = 18, readCount = 14;
    try {
        cout << "* Writing " << writeCount << " elements to buffer" << endl;
        for (int i = 0; i < writeCount; i++) {
            buffer << i;
        }
        cout << "Buffer preview:" << endl << buffer << endl;
        cout << "* Reading " << readCount << " elements from buffer" << endl;
        for (int i = 0; i < readCount; i++) {
            buffer.read();
        }
        cout << "Buffer preview:" << endl << buffer << endl;
    } catch (string e) {
        cout << "Exception: " << e << endl;
    }
}

string BuffersTest::formatInterval(clock_t start, clock_t end) {
    stringstream ss;
    double time = (double) (end - start) / CLOCKS_PER_SEC;
    ss << setprecision(3) << time << "s";
    return ss.str();
}
