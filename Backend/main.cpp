#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#include "Student.h"
#include "attendance.h"
#include "marks.h"
#include "search_sort.h"
#include "input_validation.h"

using namespace std;

int main() {

    // Sample student data for search and sorting
    vector<StudentRecord> students = {
        {"1BG25IS006", "Aditi", 85.75},
        {"1BG25IS007", "Rahul", 72.40},
        {"1BG25IS008", "Sneha", 94.20},
        {"1BG25IS009", "Karan", 81.50}
    };

    int choice;

    do {

        cout << endl;
        cout << "========================================" << endl;
        cout << "       SMART STUDENT MANAGEMENT" << endl;
        cout << "========================================" << endl;

        cout << "1. Student Details" << endl;
        cout << "2. Attendance" << endl;
        cout << "3. Marks" << endl;
        cout << "4. Search Student" << endl;
        cout << "5. Sort Students by Percentage" << endl;
        cout << "6. Exit" << endl;

        cout << "----------------------------------------" << endl;

        choice = getIntegerInput("Enter your choice: ");

        switch (choice) {

            // ========================================
            // STUDENT DETAILS
            // ========================================
            case 1: {

                Student student1(
                    "1BG25IS006",
                    "Aditi",
                    "aditi@example.com",
                    "ISE",
                    2,
                    "9876543210"
                );

                cout << endl;
                cout << "Student Details" << endl;
                cout << "---------------" << endl;

                student1.display();

                break;
            }

            // ========================================
            // ATTENDANCE
            // ========================================
           case 2: {

    string attendance_id;
    string student_id;
    string attendance_date;
    string status;

    cout << endl;
    cout << "Attendance Details" << endl;
    cout << "------------------" << endl;

    cout << "Enter Attendance ID: ";
    cin >> attendance_id;

    student_id = getStudentId("Enter Student ID: ");

    attendance_date = getDate(
        "Enter Attendance Date (YYYY-MM-DD): "
    );

    status = getAttendanceStatus(
        "Enter Status (Present/Absent): "
    );

    Attendance attendanceRecord(
        attendance_id,
        student_id,
        attendance_date,
        status
    );

    cout << endl;

    attendanceRecord.displayAttendance();

    break;
}

            // ========================================
            // MARKS
            // ========================================
            case 3: {

                string mark_id;
                string student_id;
                string subject_id;
                float marks_obtained;

                cout << endl;
                cout << "Marks Details" << endl;
                cout << "-------------" << endl;

                cout << "Enter Mark ID: ";
                cin >> mark_id;

                cout << "Enter Student ID: ";
                cin >> student_id;

                cout << "Enter Subject ID: ";
                cin >> subject_id;

                marks_obtained = getFloatInput(
                    "Enter marks obtained: "
                );

                try {

                    Marks studentMarks(
                        mark_id,
                        student_id,
                        subject_id,
                        marks_obtained
                    );

                    cout << endl;
                    studentMarks.displayMarks();

                }
                catch (const invalid_argument& e) {

                    cout << "Error: " << e.what() << endl;

                }

                break;
            }

            // ========================================
            // SEARCH STUDENT
            // ========================================
            case 4: {

                string student_id;

                cout << endl;
                cout << "Search Student" << endl;
                cout << "--------------" << endl;

                cout << "Enter Student ID: ";
                cin >> student_id;

                searchStudent(students, student_id);

                break;
            }

            // ========================================
            // SORT STUDENTS
            // ========================================
            case 5: {

                cout << endl;
                cout << "Students Before Sorting" << endl;
                cout << "-----------------------" << endl;

                displayStudents(students);

                sortStudentsByPercentage(students);

                cout << endl;
                cout << "Students Sorted by Percentage" << endl;
                cout << "-----------------------------" << endl;

                displayStudents(students);

                break;
            }

            // ========================================
            // EXIT
            // ========================================
            case 6:

                cout << endl;
                cout << "Thank you for using Smart Student Management!" << endl;

                break;

            default:

                cout << endl;
                cout << "Invalid choice. Please select 1-6." << endl;
        }

    } while (choice != 6);

    return 0;
}