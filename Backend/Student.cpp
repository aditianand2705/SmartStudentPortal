#include <iostream>
#include <fstream>
#include <vector>

#include "Student.h"
#include "input_validation.h"

using namespace std;


Student::Student(
    string student_id,
    string student_name,
    string email,
    string department,
    int semester,
    string phone
)
{
    this->student_id = student_id;
    this->student_name = student_name;
    this->email = email;
    this->department = department;
    this->semester = semester;
    this->phone = phone;
}


// ==============================
// GETTERS
// ==============================

string Student::getStudentId() const
{
    return student_id;
}

string Student::getStudentName() const
{
    return student_name;
}

string Student::getEmail() const
{
    return email;
}

string Student::getDepartment() const
{
    return department;
}

int Student::getSemester() const
{
    return semester;
}

string Student::getPhone() const
{
    return phone;
}


// ==============================
// SETTERS
// ==============================

void Student::setStudentName(string student_name)
{
    this->student_name = student_name;
}

void Student::setEmail(string email)
{
    this->email = email;
}

void Student::setDepartment(string department)
{
    this->department = department;
}

void Student::setSemester(int semester)
{
    this->semester = semester;
}

void Student::setPhone(string phone)
{
    this->phone = phone;
}


// ==============================
// DISPLAY STUDENT
// ==============================

void Student::display() const
{
    cout << endl;
    cout << "Student ID: " << student_id << endl;
    cout << "Student Name: " << student_name << endl;
    cout << "Email: " << email << endl;
    cout << "Department: " << department << endl;
    cout << "Semester: " << semester << endl;
    cout << "Phone: " << phone << endl;
    cout << "----------------------------------------" << endl;
}


// ==============================
// ADD STUDENT
// ==============================

void addStudent(vector<Student>& students)
{
    string student_id;
    string student_name;
    string email;
    string department;
    int semester;
    string phone;

    cout << endl;
    cout << "Add Student" << endl;
    cout << "-----------" << endl;

    student_id = getStudentId("Enter Student ID: ");

    // Check duplicate ID
    for (const Student& student : students)
    {
        if (student.getStudentId() == student_id)
        {
            cout << "Student ID already exists!" << endl;
            return;
        }
    }

    student_name = getNonEmptyString("Enter Student Name: ");
    email = getEmail("Enter Email: ");
    department = getNonEmptyString("Enter Department: ");

    semester = getIntegerInput("Enter Semester: ");

    while (semester < 1 || semester > 8)
    {
        cout << "Invalid semester. Enter a value between 1 and 8."
             << endl;

        semester = getIntegerInput("Enter Semester: ");
    }

    phone = getPhone("Enter Phone: ");

    students.push_back(
        Student(
            student_id,
            student_name,
            email,
            department,
            semester,
            phone
        )
    );

    cout << endl;
    cout << "Student Added Successfully!" << endl;
}


// ==============================
// VIEW STUDENTS
// ==============================

void viewStudents(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << endl;
        cout << "No Student Records Found!" << endl;
        return;
    }

    cout << endl;
    cout << "Student Records" << endl;
    cout << "---------------" << endl;

    for (const Student& student : students)
    {
        student.display();
    }
}


// ==============================
// UPDATE STUDENT
// ==============================

void updateStudent(vector<Student>& students)
{
    string student_id;

    cout << endl;
    cout << "Update Student" << endl;
    cout << "--------------" << endl;

    student_id = getStudentId("Enter Student ID to Update: ");

    for (Student& student : students)
    {
        if (student.getStudentId() == student_id)
        {
            string student_name;
            string email;
            string department;
            int semester;
            string phone;

            student_name =
                getNonEmptyString("Enter New Student Name: ");

            email =
                getEmail("Enter New Email: ");

            department =
                getNonEmptyString("Enter New Department: ");

            semester =
                getIntegerInput("Enter New Semester: ");

            while (semester < 1 || semester > 8)
            {
                cout << "Invalid semester. Enter a value between 1 and 8."
                     << endl;

                semester =
                    getIntegerInput("Enter New Semester: ");
            }

            phone =
                getPhone("Enter New Phone: ");

            student.setStudentName(student_name);
            student.setEmail(email);
            student.setDepartment(department);
            student.setSemester(semester);
            student.setPhone(phone);

            cout << endl;
            cout << "Record Updated Successfully!" << endl;

            return;
        }
    }

    cout << endl;
    cout << "Student Not Found!" << endl;
}


// ==============================
// DELETE STUDENT
// ==============================

void deleteStudent(vector<Student>& students)
{
    string student_id;

    cout << endl;
    cout << "Delete Student" << endl;
    cout << "--------------" << endl;

    student_id =
        getStudentId("Enter Student ID to Delete: ");

    for (auto it = students.begin();
         it != students.end();
         ++it)
    {
        if (it->getStudentId() == student_id)
        {
            students.erase(it);

            cout << endl;
            cout << "Student Deleted Successfully!" << endl;

            return;
        }
    }

    cout << endl;
    cout << "Student Not Found!" << endl;
}


// ==============================
// LOAD STUDENTS FROM FILE
// ==============================

void loadStudentsFromFile(vector<Student>& students)
{
    ifstream in("students.txt");

    if (!in)
    {
        return;
    }

    string student_id;
    string student_name;
    string email;
    string department;
    int semester;
    string phone;

    while (
        in >> student_id
        >> student_name
        >> email
        >> department
        >> semester
        >> phone
    )
    {
        students.push_back(
            Student(
                student_id,
                student_name,
                email,
                department,
                semester,
                phone
            )
        );
    }

    in.close();
}


// ==============================
// SAVE STUDENTS TO FILE
// ==============================

void saveStudentsToFile(const vector<Student>& students)
{
    ofstream out("students.txt");

    for (const Student& student : students)
    {
        out << student.getStudentId() << " "
            << student.getStudentName() << " "
            << student.getEmail() << " "
            << student.getDepartment() << " "
            << student.getSemester() << " "
            << student.getPhone()
            << endl;
    }

    out.close();
}