#ifndef SHOWPICTUREWIDGET_H
#define SHOWPICTUREWIDGET_H

#include "ui_showpicturewidget.h"
#include <QWidget>

namespace Ui {
class ShowPictureWidget;
}

class ShowPictureWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShowPictureWidget(QWidget *parent = 0);
    ~ShowPictureWidget();

private:
    Ui::ShowPictureWidget *ui;
};

#endif // SHOWPICTUREWIDGET_H
