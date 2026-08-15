#include <iostream>
#include <stdexcept>
#include "marks.h"

using namespace std;

Marks::Marks(
    string mark_id,
    string student_id,
    string subject_id,
    float marks_obtained
) {
    if (marks_obtained < 0 || marks_obtained > 100) {
        throw invalid_argument(
            "Marks obtained must be between 0 and 100."
        );
    }

    this->mark_id = mark_id;
    this->student_id = student_id;
    this->subject_id = subject_id;
    this->marks_obtained = marks_obtained;
}

char Marks::calculateGrade() {

    if (marks_obtained >= 90) {
        return 'A';
    }
    else if (marks_obtained >= 80) {
        return 'B';
    }
    else if (marks_obtained >= 70) {
        return 'C';
    }
    else if (marks_obtained >= 60) {
        return 'D';
    }
    else if (marks_obtained >= 50) {
        return 'E';
    }
    else {
        return 'F';
    }
}

void Marks::displayMarks() {

    cout << "Mark ID: " << mark_id << endl;
    cout << "Student ID: " << student_id << endl;
    cout << "Subject ID: " << subject_id << endl;
    cout << "Marks Obtained: " << marks_obtained << endl;
    cout << "Grade: " << calculateGrade() << endl;
}