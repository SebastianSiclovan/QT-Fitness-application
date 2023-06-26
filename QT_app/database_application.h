#ifndef DATABASE_APPLICATION_H
#define DATABASE_APPLICATION_H

#include <QtSql>

#include <list>
#include <QDebug>


class Database_application
{
public:
    void databaseInit();
    void database_addUserData_atRegister(std::list <QString> & user_data);

    bool verify_userData_atLogin(QString email, QString password);

private:
    QSqlDatabase db;

public:
    Database_application();
};

#endif // DATABASE_APPLICATION_H
