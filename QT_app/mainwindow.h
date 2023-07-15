#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Register.h"
#include "Login.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static MainWindow & get_instance();

    // Disable copy constructor and equal assignment operator
    MainWindow(const MainWindow &) = delete;
    MainWindow& operator=(const MainWindow&) = delete;

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_2_clicked();

private:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *ui;

    Register *registerObj;
    Login *loginObj;

};
#endif // MAINWINDOW_H
