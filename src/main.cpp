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

using namespace std;

int main(int argc, char *argv[])
{
//    const unsigned int BUFFER_SIZE = 10;
//    CircularBuffer buffer(BUFFER_SIZE);

    if (argc > 1) {
        if (argv[1] == string("test")) {
//            CircularBufferTest tester(buffer);
//            tester.runTests();
        } else {
            cout << "Usage:" << endl;
            cout << "buf [test]" << endl << endl;
            cout << " test - runs test on buffer classes" << endl;
        }
    } else {
//        CLI cli(buffer);
//        cli.showMenu();
    }
//    CircularBuffer bufferCopy = buffer;
//    cout << bufferCopy << endl;
    return 0;
}
