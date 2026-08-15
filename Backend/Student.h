#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string student_id;
    string student_name;
    string email;
    string department;
    int semester;
    string phone;

public:
    Student(
        string id,
        string name,
        string email,
        string department,
        int semester,
        string phone
    );

    void display();
};

#endif