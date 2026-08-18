#include <iostream>
#include <string>

#include "login.h"

using namespace std;

bool authenticateUser(
    const string& username,
    const string& password
) {

    // Temporary test credentials
    // These will be replaced with PostgreSQL authentication.

    if (username == "admin" &&
        password == "admin123") {

        return true;
    }

    return false;
}