#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string usn;
    string name;

public:
    Student(string u, string n);

    void display();
};

#endif