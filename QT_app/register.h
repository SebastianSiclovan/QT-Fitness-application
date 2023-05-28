#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    bool check_registerFields();
    bool password_security(QString & obj);
    void on_pushButton_registerBtn_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
