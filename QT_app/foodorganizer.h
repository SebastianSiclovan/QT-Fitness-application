#ifndef FOODORGANIZER_H
#define FOODORGANIZER_H

#include <QDialog>

namespace Ui {
class FoodOrganizer;
}

class FoodOrganizer : public QDialog
{
    Q_OBJECT

public:
    explicit FoodOrganizer(QWidget *parent = nullptr);
    ~FoodOrganizer();

private:
    Ui::FoodOrganizer *ui;
};

#endif // FOODORGANIZER_H
