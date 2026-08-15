#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(string u, string n) {
    usn = u;
    name = n;
}

void Student::display() {
    cout << "USN: " << usn << endl;
    cout << "Name: " << name << endl;
}