#include "showpicturewidget.h"

ShowPictureWidget::ShowPictureWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowPictureWidget)
{
    ui->setupUi(this);
}

ShowPictureWidget::~ShowPictureWidget()
{
    delete ui;
}
