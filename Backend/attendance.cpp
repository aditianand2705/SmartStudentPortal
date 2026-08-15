#include <iostream>
#include <stdexcept>
#include "attendance.h"

using namespace std;

Attendance::Attendance(int total, int attended) {

    if (total <= 0) {
        throw invalid_argument("Total classes must be greater than 0.");
    }

    if (attended < 0 || attended > total) {
        throw invalid_argument("Attended classes must be between 0 and total classes.");
    }

    totalClasses = total;
    attendedClasses = attended;
}

float Attendance::calculatePercentage() {
    return (static_cast<float>(attendedClasses) / totalClasses) * 100;
}

void Attendance::displayAttendance() {
    cout << "Total Classes: " << totalClasses << endl;
    cout << "Classes Attended: " << attendedClasses << endl;
    cout << "Attendance Percentage: "
         << calculatePercentage() << "%" << endl;
}