#include <iostream>
#include <stdexcept>
#include "marks.h"

using namespace std;

Marks::Marks(vector<float> marks) {

    if (marks.empty()) {
        throw invalid_argument("Marks list cannot be empty.");
    }

    for (float mark : marks) {

        if (mark < 0 || mark > 100) {
            throw invalid_argument("Each mark must be between 0 and 100.");
        }

        subjectMarks.push_back(mark);
    }
}

float Marks::calculateTotal() {

    float total = 0;

    for (float mark : subjectMarks) {
        total += mark;
    }

    return total;
}

float Marks::calculatePercentage() {

    float total = calculateTotal();

    return total / subjectMarks.size();
}

char Marks::calculateGrade() {

    float percentage = calculatePercentage();

    if (percentage >= 90) {
        return 'A';
    }
    else if (percentage >= 80) {
        return 'B';
    }
    else if (percentage >= 70) {
        return 'C';
    }
    else if (percentage >= 60) {
        return 'D';
    }
    else if (percentage >= 50) {
        return 'E';
    }
    else {
        return 'F';
    }
}

void Marks::displayMarks() {

    cout << "Marks: ";

    for (float mark : subjectMarks) {
        cout << mark << " ";
    }

    cout << endl;

    cout << "Total Marks: "
         << calculateTotal()
         << endl;

    cout << "Percentage: "
         << calculatePercentage()
         << "%"
         << endl;

    cout << "Grade: "
         << calculateGrade()
         << endl;
}