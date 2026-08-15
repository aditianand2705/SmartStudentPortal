#include <iostream>
#include <limits>
#include <regex>
#include <cctype>

#include "input_validation.h"

using namespace std;


int getIntegerInput(const char* message) {

    int value;

    while (true) {

        cout << message;

        if (cin >> value) {
            return value;
        }

        cout << "Invalid input. Please enter a number." << endl;

        cin.clear();

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );
    }
}


float getFloatInput(const char* message) {

    float value;

    while (true) {

        cout << message;

        if (cin >> value) {

            if (value >= 0 && value <= 100) {
                return value;
            }

            cout << "Invalid marks. Enter a value between 0 and 100."
                 << endl;
        }
        else {

            cout << "Invalid input. Please enter a number."
                 << endl;

            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );
        }
    }
}


string getNonEmptyString(const char* message) {

    string value;

    while (true) {

        cout << message;
        cin >> ws;
        getline(cin, value);

        if (!value.empty()) {
            return value;
        }

        cout << "Input cannot be empty. Please try again."
             << endl;
    }
}


string getStudentId(const char* message) {

    string student_id;

    while (true) {

        cout << message;
        cin >> student_id;

        if (!student_id.empty()) {
            return student_id;
        }

        cout << "Student ID cannot be empty." << endl;
    }
}


string getDate(const char* message) {

    string date;

    regex datePattern(
        R"(^\d{4}-\d{2}-\d{2}$)"
    );

    while (true) {

        cout << message;
        cin >> date;

        if (regex_match(date, datePattern)) {
            return date;
        }

        cout << "Invalid date. Use YYYY-MM-DD format."
             << endl;
    }
}


string getAttendanceStatus(const char* message) {

    string status;

    while (true) {

        cout << message;
        cin >> status;

        if (status == "Present" ||
            status == "present" ||
            status == "P") {

            return "Present";
        }

        if (status == "Absent" ||
            status == "absent" ||
            status == "A") {

            return "Absent";
        }

        cout << "Invalid status. Enter Present or Absent."
             << endl;
    }
}


string getEmail(const char* message) {

    string email;

    regex emailPattern(
        R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)"
    );

    while (true) {

        cout << message;
        cin >> email;

        if (regex_match(email, emailPattern)) {
            return email;
        }

        cout << "Invalid email format. Please try again."
             << endl;
    }
}


string getPhone(const char* message) {

    string phone;

    while (true) {

        cout << message;
        cin >> phone;

        if (phone.length() == 10) {

            bool allDigits = true;

            for (char c : phone) {

                if (!isdigit(c)) {
                    allDigits = false;
                    break;
                }
            }

            if (allDigits) {
                return phone;
            }
        }

        cout << "Invalid phone number. Enter exactly 10 digits."
             << endl;
    }
}