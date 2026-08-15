#ifndef MARKS_H
#define MARKS_H

#include <vector>

class Marks {
private:
    std::vector<float> subjectMarks;

public:
    Marks(std::vector<float> marks);

    float calculateTotal();
    float calculatePercentage();
    char calculateGrade();

    void displayMarks();
};

#endif