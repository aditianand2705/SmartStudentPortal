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

int main()
{
    // ========================================
    // STUDENT DATA
    // ========================================

    vector<Student> students;

loadStudentsFromFile(students);

if (students.empty())
{
    students.push_back(
        Student(
            "1BG25IS006",
            "Aditi",
            "aditi@example.com",
            "ISE",
            2,
            "9876543210"
        )
    );

    students.push_back(
        Student(
            "1BG25IS007",
            "Rahul",
            "rahul@example.com",
            "ISE",
            2,
            "9876543211"
        )
    );
}

vector<StudentRecord> studentRecords = {
    {"1BG25IS006", "Aditi", 85.75},
    {"1BG25IS007", "Rahul", 72.40}
};

    int choice;

    do
    {
        cout << endl;
        cout << "========================================" << endl;
        cout << "       SMART STUDENT MANAGEMENT" << endl;
        cout << "========================================" << endl;

        cout << "1. Add Student" << endl;
        cout << "2. View Student Details" << endl;
        cout << "3. Update Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Attendance" << endl;
        cout << "6. Marks" << endl;
        cout << "7. Search Student" << endl;
        cout << "8. Sort Students by Percentage" << endl;
        cout << "9. Save Data" << endl;
        cout << "10. Exit" << endl;

        cout << "----------------------------------------" << endl;

        choice = getIntegerInput("Enter your choice: ");

        switch (choice)
        {
            // ========================================
            // ADD STUDENT
            // ========================================

            case 1:
            {
                addStudent(students);
                break;
            }


            // ========================================
            // VIEW STUDENTS
            // ========================================

            case 2:
            {
                viewStudents(students);
                break;
            }


            // ========================================
            // UPDATE STUDENT
            // ========================================

            case 3:
            {
                updateStudent(students);
                break;
            }


            // ========================================
            // DELETE STUDENT
            // ========================================

            case 4:
            {
                deleteStudent(students);
                break;
            }


            // ========================================
            // ATTENDANCE
            // ========================================

            case 5:
            {
                string attendance_id;
                string student_id;
                string attendance_date;
                string status;

                cout << endl;
                cout << "Attendance Details" << endl;
                cout << "------------------" << endl;

                cout << "Enter Attendance ID: ";
                cin >> attendance_id;

                student_id =
                    getStudentId("Enter Student ID: ");

                attendance_date =
                    getDate(
                        "Enter Attendance Date (YYYY-MM-DD): "
                    );

                status =
                    getAttendanceStatus(
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

            case 6:
            {
                string mark_id;
                string student_id;
                string subject_id;
                float marks_obtained;

                cout << endl;
                cout << "Marks Details" << endl;
                cout << "-------------" << endl;

                cout << "Enter Mark ID: ";
                cin >> mark_id;

                student_id =
                    getStudentId("Enter Student ID: ");

                cout << "Enter Subject ID: ";
                cin >> subject_id;

                marks_obtained =
                    getFloatInput(
                        "Enter marks obtained: "
                    );

                try
                {
                    Marks studentMarks(
                        mark_id,
                        student_id,
                        subject_id,
                        marks_obtained
                    );

                    cout << endl;

                    studentMarks.displayMarks();
                }
                catch (const invalid_argument& e)
                {
                    cout << "Error: "
                         << e.what()
                         << endl;
                }

                break;
            }


            // ========================================
            // SEARCH STUDENT
            // ========================================

            case 7:
            {
                string student_id;

                cout << endl;
                cout << "Search Student" << endl;
                cout << "--------------" << endl;

                student_id =
                    getStudentId(
                        "Enter Student ID: "
                    );

                bool found = false;

                for (const Student& student : students)
                {
                    if (student.getStudentId() == student_id)
                    {
                        cout << endl;
                        cout << "Student Found!" << endl;

                        student.display();

                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "Student not found." << endl;
                }

                break;
            }


            // ========================================
            // SORT STUDENTS
            // ========================================

            case 8:
{
    cout << endl;
    cout << "Students Before Sorting" << endl;
    cout << "-----------------------" << endl;

    displayStudents(studentRecords);

    sortStudentsByPercentage(studentRecords);

    cout << endl;
    cout << "Students Sorted by Percentage" << endl;
    cout << "-----------------------------" << endl;

    displayStudents(studentRecords);

    break;
}

            // ========================================
            // SAVE DATA
            // ========================================

            case 9:
            {
                saveStudentsToFile(students);

                cout << endl;
                cout << "Data Saved Successfully!" << endl;

                break;
            }


            // ========================================
            // EXIT
            // ========================================

            case 10:
            {
                saveStudentsToFile(students);

                cout << endl;
                cout << "Thank you for using Smart Student Management!"
                     << endl;

                break;
            }


            // ========================================
            // INVALID CHOICE
            // ========================================

            default:
            {
                cout << endl;
                cout << "Invalid choice. Please select 1-10."
                     << endl;

                break;
            }
        }

    } while (choice != 10);

    return 0;
}