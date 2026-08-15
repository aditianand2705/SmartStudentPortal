#include <iostream>
#include "attendance.h"

using namespace std;

Attendance::Attendance(
    string attendance_id,
    string student_id,
    string attendance_date,
    string status
) {
    this->attendance_id = attendance_id;
    this->student_id = student_id;
    this->attendance_date = attendance_date;
    this->status = status;
}

void Attendance::displayAttendance() {

    cout << endl;
    cout << "Attendance ID: " << attendance_id << endl;
    cout << "Student ID: " << student_id << endl;
    cout << "Attendance Date: " << attendance_date << endl;
    cout << "Status: " << status << endl;
}