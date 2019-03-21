/********************************************************************************
** Form generated from reading UI file 'choosesharporder.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSESHARPORDER_H
#define UI_CHOOSESHARPORDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseSharpOrder
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *firstOrderButton;
    QRadioButton *secondOrderButton;
    QLabel *label;

    void setupUi(QDialog *ChooseSharpOrder)
    {
        if (ChooseSharpOrder->objectName().isEmpty())
            ChooseSharpOrder->setObjectName(QString::fromUtf8("ChooseSharpOrder"));
        ChooseSharpOrder->resize(485, 170);
        ChooseSharpOrder->setMinimumSize(QSize(485, 170));
        ChooseSharpOrder->setMaximumSize(QSize(485, 170));
        layoutWidget = new QWidget(ChooseSharpOrder);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 30, 395, 120));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QFont font;
        font.setPointSize(13);
        buttonBox->setFont(font);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        firstOrderButton = new QRadioButton(layoutWidget);
        firstOrderButton->setObjectName(QString::fromUtf8("firstOrderButton"));
        firstOrderButton->setFont(font);
        firstOrderButton->setAutoExclusive(true);

        horizontalLayout->addWidget(firstOrderButton);

        secondOrderButton = new QRadioButton(layoutWidget);
        secondOrderButton->setObjectName(QString::fromUtf8("secondOrderButton"));
        secondOrderButton->setFont(font);
        secondOrderButton->setCheckable(true);
        secondOrderButton->setChecked(false);
        secondOrderButton->setAutoRepeat(false);
        secondOrderButton->setAutoExclusive(true);

        horizontalLayout->addWidget(secondOrderButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(ChooseSharpOrder);

        QMetaObject::connectSlotsByName(ChooseSharpOrder);
    } // setupUi

    void retranslateUi(QDialog *ChooseSharpOrder)
    {
        ChooseSharpOrder->setWindowTitle(QApplication::translate("ChooseSharpOrder", "Dialog", 0, QApplication::UnicodeUTF8));
        firstOrderButton->setText(QApplication::translate("ChooseSharpOrder", "&First Order", 0, QApplication::UnicodeUTF8));
        secondOrderButton->setText(QApplication::translate("ChooseSharpOrder", "S&econd Order", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ChooseSharpOrder", "Please choose sharp order", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChooseSharpOrder: public Ui_ChooseSharpOrder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSESHARPORDER_H
