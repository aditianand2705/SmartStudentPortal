#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(
    string id,
    string name,
    string email,
    string department,
    int semester,
    string phone
) {
    student_id = id;
    student_name = name;
    this->email = email;
    this->department = department;
    this->semester = semester;
    this->phone = phone;
}

void Student::display() {
    cout << "Student ID: " << student_id << endl;
    cout << "Student Name: " << student_name << endl;
    cout << "Email: " << email << endl;
    cout << "Department: " << department << endl;
    cout << "Semester: " << semester << endl;
    cout << "Phone: " << phone << endl;
}