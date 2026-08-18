#ifndef LOGIN_H
#define LOGIN_H

#include <string>

bool authenticateUser(
    const std::string& username,
    const std::string& password
);

#endif