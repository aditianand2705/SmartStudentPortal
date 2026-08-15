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
        cout << "       SMART STUDENT PORTAL" << endl;
        cout << "========================================" << endl;

        cout << "1. Student Details" << endl;
        cout << "2. Attendance" << endl;
        cout << "3. Marks" << endl;
        cout << "4. Search Student" << endl;
        cout << "5. Sort Students by Percentage" << endl;
        cout << "6. Exit" << endl;

        cout << "----------------------------------------" << endl;
        cout << "Enter your choice: ";
        choice = getIntegerInput("Enter your choice: ");

        switch (choice) {

            case 1: {

                Student student1("1BG25IS006", "Aditi");

                cout << endl;
                cout << "Student Details" << endl;
                cout << "---------------" << endl;

                student1.display();

                break;
            }

            case 2: {

                int totalClasses;
                int attendedClasses;

                cout << endl;
                cout << "Attendance Details" << endl;
                cout << "------------------" << endl;

                totalClasses = getIntegerInput("Enter total classes: ");

                attendedClasses = getIntegerInput(
                "Enter classes attended: "
                );

                try {

                    Attendance attendance(
                        totalClasses,
                        attendedClasses
                    );

                    cout << endl;
                    attendance.displayAttendance();

                }
                catch (const invalid_argument& e) {

                    cout << "Error: " << e.what() << endl;

                }

                break;
            }

            case 3: {

                int numberOfSubjects;

                cout << endl;
                cout << "Marks Details" << endl;
                cout << "-------------" << endl;

                numberOfSubjects = getIntegerInput(
                "Enter number of subjects: "
                );

                vector<float> marks;

                for (int i = 0; i < numberOfSubjects; i++) {

                    float mark;

                    mark = getFloatInput(
                        (std::string("Enter marks for subject ") +
                         std::to_string(i + 1) +
                         ": ").c_str()
                    );

                    marks.push_back(mark);
                }

                try {

                    Marks studentMarks(marks);

                    cout << endl;
                    studentMarks.displayMarks();

                }
                catch (const invalid_argument& e) {

                    cout << "Error: " << e.what() << endl;

                }

                break;
            }

            case 4: {

                string usn;

                cout << endl;
                cout << "Search Student" << endl;
                cout << "--------------" << endl;

                cout << "Enter USN: ";
                cin >> usn;

                searchStudent(students, usn);

                break;
            }

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

            case 6:

                cout << endl;
                cout << "Thank you for using Smart Student Portal!" << endl;

                break;

            default:

                cout << endl;
                cout << "Invalid choice. Please select 1-6." << endl;
        }

    } while (choice != 6);

    return 0;
}