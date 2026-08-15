#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include <string>

int getIntegerInput(const char* message);
float getFloatInput(const char* message);

std::string getNonEmptyString(const char* message);
std::string getStudentId(const char* message);
std::string getEmail(const char* message);
std::string getPhone(const char* message);
std::string getDate(const char* message);
std::string getAttendanceStatus(const char* message);

#endif