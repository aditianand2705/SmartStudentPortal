#include <iostream>
#include <limits>
#include "input_validation.h"

using namespace std;

int getIntegerInput(const char* message) {

    int value;

    while (true) {

        cout << message;

        if (cin >> value) {
            return value;
        }

        cout << "Invalid input. Please enter a number." << endl;

        cin.clear();

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );
    }
}

float getFloatInput(const char* message) {

    float value;

    while (true) {

        cout << message;

        if (cin >> value) {
            return value;
        }

        cout << "Invalid input. Please enter a number." << endl;

        cin.clear();

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );
    }
}