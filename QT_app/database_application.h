#ifndef DATABASE_APPLICATION_H
#define DATABASE_APPLICATION_H

#include <QtSql>

#include <list>


class Database_application
{
public:
    void databaseInit();
    void database_addUserData(std::list <QString> & user_data);

private:
    QSqlDatabase db;

public:
    Database_application();
};

#endif // DATABASE_APPLICATION_H
