#ifndef SEARCH_SORT_H
#define SEARCH_SORT_H

#include <vector>
#include <string>

using namespace std;

struct StudentRecord {
    string student_id;
    string student_name;
    float percentage;
};

void searchStudent(
    const vector<StudentRecord>& students,
    string student_id
);

void sortStudentsByPercentage(
    vector<StudentRecord>& students
);

void displayStudents(
    const vector<StudentRecord>& students
);

#endif