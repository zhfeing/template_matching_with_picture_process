#include "choosesharporder.h"
#include <iostream>

ChooseSharpOrder::ChooseSharpOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseSharpOrder)
{
    ui->setupUi(this);
    connect(ui->firstOrderButton, SIGNAL(clicked(bool)),
            this, SLOT(chooseFirst(bool)));
    connect(ui->secondOrderButton, SIGNAL(clicked(bool)),
            this, SLOT(chooseSecond(bool)));
    connect(ui->buttonBox, SIGNAL(accepted()),
            this, SLOT(clickedOk()));
    connect(ui->buttonBox, SIGNAL(rejected()),
            this, SLOT(clickedCancle()));
    connect(this, SIGNAL(getChooseSharpMode(ChooseSharpOrder::ChooseSharpMode)),
        parent, SLOT(getChooseMode(ChooseSharpOrder::ChooseSharpMode)));
}

ChooseSharpOrder::~ChooseSharpOrder()
{
    delete ui;
}

void ChooseSharpOrder::chooseFirst(bool)
{
    chooseMode = firstOrder;
}

void ChooseSharpOrder::chooseSecond(bool)
{
    chooseMode = secondOrder;
}

void ChooseSharpOrder::clickedCancle()
{
    this->close();
}

void ChooseSharpOrder::clickedOk()
{
    this->close();
    emit getChooseSharpMode(chooseMode);
}
