#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <string>

using namespace std;

class Attendance {
private:
    string attendance_id;
    string student_id;
    string attendance_date;
    string status;

public:
    Attendance(
        string attendance_id,
        string student_id,
        string attendance_date,
        string status
    );

    void displayAttendance();
};

#endif