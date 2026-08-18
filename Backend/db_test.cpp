#include <iostream>
#include <libpq-fe.h>

using namespace std;

int main() {

    const char* connectionInfo =
        "host=localhost "
        "port=5432 "
        "dbname=smart_student_management "
        "user=postgres "
        "password=hihi";

    PGconn* connection = PQconnectdb(connectionInfo);

    if (PQstatus(connection) == CONNECTION_OK) {

        cout << "PostgreSQL connected successfully!" << endl;

    }
    else {

        cout << "Connection failed!" << endl;
        cout << PQerrorMessage(connection) << endl;

    }

    PQfinish(connection);

    return 0;
}