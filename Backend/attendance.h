#ifndef ATTENDANCE_H
#define ATTENDANCE_H

class Attendance {
private:
    int totalClasses;
    int attendedClasses;

public:
    Attendance(int total, int attended);

    float calculatePercentage();
    void displayAttendance();
};

#endif