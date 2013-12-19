/**
 * Warsaw University of Technology
 * The Faculty of Electronics and Information Technology
 *
 * Object-Oriented Programming Lab 2 - Abstract Buffer
 *
 * Main file
 *
 * @author Michal Swietochowski 
 */

#include <iostream>
#include "CircularBuffer.h"

using namespace std;

int main(int argc, char *argv[]) {
    const unsigned int BUFFER_SIZE = 10;
    CircularBuffer<int> intBuffer(BUFFER_SIZE);
    CircularBuffer<string> stringBuffer(BUFFER_SIZE);

    if (argc > 1) {
        if (argv[1] == string("test")) {
//            CircularBufferTest tester(intBuffer);
//            tester.runTests();
        } else {
            cout << "Usage:" << endl;
            cout << "buf [test]" << endl << endl;
            cout << " test - runs test on buffer classes" << endl;
        }
    } else {
//        CLI cli(intBuffer);
//        cli.showMenu();
    }
    cout << intBuffer + 1 << endl;
    cout << 1 + intBuffer << endl;
    cout << stringBuffer << endl;
    return 0;
}
