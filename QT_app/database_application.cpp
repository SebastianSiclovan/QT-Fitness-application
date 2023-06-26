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

bool Database_application::verify_userData_atLogin(QString email, QString password)
{
    bool isWarning = false;
    QSqlQuery query;

    QString selectFromTable_forQuery = "SELECT * FROM users where Email = '"+ email +"' and Password= '"+ password +"'";

    if(query.exec(selectFromTable_forQuery))
    {
        int cnt_queryExecuted = 0;
        while (query.next())
        {
            cnt_queryExecuted++;
        }

        switch(cnt_queryExecuted)
        {
        case 1:
            isWarning = true;
            break;
        case 0:
            isWarning = false;
        default:
            isWarning = false;

        }

    }

    return isWarning;
}

void Database_application::database_addUserData_atRegister(std::list<QString> & user_data)
{
    QSqlQuery query;

    QString table_forQuery = "CREATE TABLE IF NOT EXISTS users ("
                             "Username VARCHAR(20),"
                             "FirstName VARCHAR(20),"
                             "LastName VARCHAR(20),"
                             "Email VARCHAR(20),"
                             "Password VARCHAR(20));";

    query.exec(table_forQuery);






    QString insertData_forQuery = "INSERT INTO users ("
                                  "Username,"
                                  "FirstName,"
                                  "LastName,"
                                  "Email,"
                                  "Password)"
                                  "VALUES (?, ?, ?, ?, ?);";

    query.prepare(insertData_forQuery);

    for (auto & element : user_data)
    {
        query.addBindValue(element);
    }



    query.exec();
}




