#ifndef MARKS_H
#define MARKS_H

#include <string>
using namespace std;

class Marks {
private:
    string mark_id;
    string student_id;
    string subject_id;
    float marks_obtained;

public:
    Marks(
        string mark_id,
        string student_id,
        string subject_id,
        float marks_obtained
    );

    char calculateGrade();
    void displayMarks();
};

#endif