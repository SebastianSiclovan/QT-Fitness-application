#include "database_application.h"

Database_application::Database_application()
{

}

void Database_application::databaseInit()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/QT application/app.db");
    db.open();
}

void Database_application::database_addUserData(std::list<QString> & user_data)
{
    QSqlQuery query;

    QString model_forQuery = "INSERT INTO users ("
                             "Username,"
                             "FirstName,"
                             "LastName,"
                             "Email,"
                             "Password)"
                             "VALUES (?, ?, ?, ?, ?);";

    query.prepare(model_forQuery);

    for (auto &element : user_data)
    {
        query.addBindValue(element);
    }

    query.exec();

}


