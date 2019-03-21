#ifndef CHOOSESHARPORDER_H
#define CHOOSESHARPORDER_H

#include "ui_choosesharporder.h"
#include <QDialog>

namespace Ui {
class ChooseSharpOrder;
}

class ChooseSharpOrder : public QDialog
{
    Q_OBJECT

public:
    enum ChooseSharpMode
    {
        firstOrder, secondOrder
    };
    explicit ChooseSharpOrder(QWidget *parent = 0);
    ~ChooseSharpOrder();

private slots:
    void chooseFirst(bool);
    void chooseSecond(bool);
    void clickedCancle();
    void clickedOk();

signals:
    void getChooseSharpMode(ChooseSharpOrder::ChooseSharpMode mode);

private:
    Ui::ChooseSharpOrder *ui;
    ChooseSharpMode chooseMode;
};

#endif // CHOOSESHARPORDER_H
