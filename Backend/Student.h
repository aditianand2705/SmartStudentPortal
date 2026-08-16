#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using namespace std;

class Student
{
private:
    string student_id;
    string student_name;
    string email;
    string department;
    int semester;
    string phone;

public:
    Student(
        string student_id = "",
        string student_name = "",
        string email = "",
        string department = "",
        int semester = 0,
        string phone = ""
    );

    string getStudentId() const;
    string getStudentName() const;
    string getEmail() const;
    string getDepartment() const;
    int getSemester() const;
    string getPhone() const;

    void setStudentName(string student_name);
    void setEmail(string email);
    void setDepartment(string department);
    void setSemester(int semester);
    void setPhone(string phone);

    void display() const;
};

void addStudent(vector<Student>& students);
void viewStudents(const vector<Student>& students);
void updateStudent(vector<Student>& students);
void deleteStudent(vector<Student>& students);

void loadStudentsFromFile(vector<Student>& students);
void saveStudentsToFile(const vector<Student>& students);

#endif