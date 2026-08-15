#include <iostream>
#include <algorithm>
#include "search_sort.h"

using namespace std;

void searchStudent(const vector<StudentRecord>& students, string usn) {

    bool found = false;

    for (const StudentRecord& student : students) {

        if (student.usn == usn) {

            cout << "Student Found!" << endl;
            cout << "USN: " << student.usn << endl;
            cout << "Name: " << student.name << endl;
            cout << "Percentage: " << student.percentage << "%" << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

void sortStudentsByPercentage(vector<StudentRecord>& students) {

    sort(students.begin(), students.end(),
        [](const StudentRecord& a, const StudentRecord& b) {
            return a.percentage > b.percentage;
        }
    );
}

void displayStudents(const vector<StudentRecord>& students) {

    for (const StudentRecord& student : students) {

        cout << student.usn << "  "
             << student.name << "  "
             << student.percentage << "%" << endl;
    }
}