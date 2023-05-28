#ifndef REGISTER_INTERFACE_H
#define REGISTER_INTERFACE_H

#include "qwidget.h"


class Register_interface{

public:
    QString title_name;

protected:
    void setTitle_name(QString _title);
    Register_interface();
    virtual bool check_registerFields() =0;
    virtual bool password_security(QString & obj) =0;
    QString getTitle_name();



};

#endif // REGISTER_INTERFACE_H
