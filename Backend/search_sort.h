#ifndef SEARCH_SORT_H
#define SEARCH_SORT_H

#include <vector>
#include <string>

using namespace std;

struct StudentRecord {
    string usn;
    string name;
    float percentage;
};

void searchStudent(const vector<StudentRecord>& students, string usn);

void sortStudentsByPercentage(vector<StudentRecord>& students);

void displayStudents(const vector<StudentRecord>& students);

#endif