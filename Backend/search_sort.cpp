#include <iostream>
#include <algorithm>
#include "search_sort.h"

using namespace std;

void searchStudent(
    const vector<StudentRecord>& students,
    string student_id
) {

    bool found = false;

    for (const StudentRecord& student : students) {

        if (student.student_id == student_id) {

            cout << "Student Found!" << endl;
            cout << "Student ID: "
                 << student.student_id << endl;

            cout << "Student Name: "
                 << student.student_name << endl;

            cout << "Percentage: "
                 << student.percentage << "%" << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

void sortStudentsByPercentage(
    vector<StudentRecord>& students
) {

    sort(
        students.begin(),
        students.end(),
        [](const StudentRecord& a,
           const StudentRecord& b) {

            return a.percentage > b.percentage;
        }
    );
}

void displayStudents(
    const vector<StudentRecord>& students
) {

    for (const StudentRecord& student : students) {

        cout << student.student_id << "  "
             << student.student_name << "  "
             << student.percentage << "%"
             << endl;
    }
}