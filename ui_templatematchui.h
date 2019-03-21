/********************************************************************************
** Form generated from reading UI file 'templatematchui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATEMATCHUI_H
#define UI_TEMPLATEMATCHUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TemplateMatchUi
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *openTemplateButton;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QCheckBox *mulityResultCheckBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *threshodLable;
    QDoubleSpinBox *choosePercentSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *edgeModeCheckBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QRadioButton *crossCorrlationButton;
    QRadioButton *absButton;
    QRadioButton *fftButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *Okbutton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *TemplateMatchUi)
    {
        if (TemplateMatchUi->objectName().isEmpty())
            TemplateMatchUi->setObjectName(QString::fromUtf8("TemplateMatchUi"));
        TemplateMatchUi->resize(600, 320);
        TemplateMatchUi->setMinimumSize(QSize(600, 320));
        TemplateMatchUi->setMaximumSize(QSize(600, 320));
        TemplateMatchUi->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(TemplateMatchUi);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 538, 282));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        openTemplateButton = new QPushButton(layoutWidget);
        openTemplateButton->setObjectName(QString::fromUtf8("openTemplateButton"));
        openTemplateButton->setMinimumSize(QSize(0, 80));
        QFont font;
        font.setPointSize(15);
        openTemplateButton->setFont(font);
        openTemplateButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{color: rgb(255, 255, 127);\n"
"background-color: rgb(255, 85, 0);\n"
"border-color: rgb(255, 85, 100);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color: rgb(43, 43, 43);\n"
"	background-color: rgb(255, 213, 41);\n"
"}"));

        verticalLayout_4->addWidget(openTemplateButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(false);
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        mulityResultCheckBox = new QCheckBox(layoutWidget);
        mulityResultCheckBox->setObjectName(QString::fromUtf8("mulityResultCheckBox"));
        mulityResultCheckBox->setEnabled(false);
        QFont font1;
        font1.setPointSize(13);
        mulityResultCheckBox->setFont(font1);

        verticalLayout_2->addWidget(mulityResultCheckBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        threshodLable = new QLabel(layoutWidget);
        threshodLable->setObjectName(QString::fromUtf8("threshodLable"));
        threshodLable->setEnabled(false);
        threshodLable->setFont(font1);

        horizontalLayout_3->addWidget(threshodLable);

        choosePercentSpinBox = new QDoubleSpinBox(layoutWidget);
        choosePercentSpinBox->setObjectName(QString::fromUtf8("choosePercentSpinBox"));
        choosePercentSpinBox->setEnabled(false);
        choosePercentSpinBox->setFont(font1);
        choosePercentSpinBox->setMaximum(1);
        choosePercentSpinBox->setSingleStep(0.01);
        choosePercentSpinBox->setValue(0.85);

        horizontalLayout_3->addWidget(choosePercentSpinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        edgeModeCheckBox = new QCheckBox(layoutWidget);
        edgeModeCheckBox->setObjectName(QString::fromUtf8("edgeModeCheckBox"));
        edgeModeCheckBox->setEnabled(false);
        edgeModeCheckBox->setFont(font1);

        verticalLayout_2->addWidget(edgeModeCheckBox);


        verticalLayout_4->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        label->setFont(font);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        crossCorrlationButton = new QRadioButton(layoutWidget);
        crossCorrlationButton->setObjectName(QString::fromUtf8("crossCorrlationButton"));
        crossCorrlationButton->setEnabled(false);
        crossCorrlationButton->setFont(font1);

        verticalLayout->addWidget(crossCorrlationButton);

        absButton = new QRadioButton(layoutWidget);
        absButton->setObjectName(QString::fromUtf8("absButton"));
        absButton->setEnabled(false);
        absButton->setFont(font1);

        verticalLayout->addWidget(absButton);

        fftButton = new QRadioButton(layoutWidget);
        fftButton->setObjectName(QString::fromUtf8("fftButton"));
        fftButton->setEnabled(false);
        fftButton->setFont(font1);

        verticalLayout->addWidget(fftButton);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setMinimumSize(QSize(130, 50));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"color: rgb(255, 255, 127);\n"
"background-color: rgb(70, 70, 70);\n"
"border-color: rgb(170, 170, 127);\n"
"\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color: rgb(43, 43, 43);\n"
"background-color: rgb(170, 255, 255);}"));

        horizontalLayout->addWidget(cancelButton);

        Okbutton = new QPushButton(layoutWidget);
        Okbutton->setObjectName(QString::fromUtf8("Okbutton"));
        Okbutton->setEnabled(false);
        Okbutton->setMinimumSize(QSize(130, 50));
        Okbutton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{color: rgb(255, 255, 127);\n"
"background-color: rgb(255, 85, 0);\n"
"border-color: rgb(255, 85, 100);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color: rgb(43, 43, 43);\n"
"	background-color: rgb(255, 213, 41);\n"
"}"));
        Okbutton->setDefault(true);

        horizontalLayout->addWidget(Okbutton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_3);


        retranslateUi(TemplateMatchUi);

        QMetaObject::connectSlotsByName(TemplateMatchUi);
    } // setupUi

    void retranslateUi(QDialog *TemplateMatchUi)
    {
        TemplateMatchUi->setWindowTitle(QApplication::translate("TemplateMatchUi", "Dialog", 0, QApplication::UnicodeUTF8));
        openTemplateButton->setText(QApplication::translate("TemplateMatchUi", "Open a template", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TemplateMatchUi", "Accuracy Choose", 0, QApplication::UnicodeUTF8));
        mulityResultCheckBox->setText(QApplication::translate("TemplateMatchUi", "Mulity Result", 0, QApplication::UnicodeUTF8));
        threshodLable->setText(QApplication::translate("TemplateMatchUi", "Threshod", 0, QApplication::UnicodeUTF8));
        edgeModeCheckBox->setText(QApplication::translate("TemplateMatchUi", "Edge Mode", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TemplateMatchUi", "Choose a Method", 0, QApplication::UnicodeUTF8));
        crossCorrlationButton->setText(QApplication::translate("TemplateMatchUi", "C&ross Correlation", 0, QApplication::UnicodeUTF8));
        absButton->setText(QApplication::translate("TemplateMatchUi", "A&bs", 0, QApplication::UnicodeUTF8));
        fftButton->setText(QApplication::translate("TemplateMatchUi", "&FFT", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("TemplateMatchUi", "&Cancel", 0, QApplication::UnicodeUTF8));
        Okbutton->setText(QApplication::translate("TemplateMatchUi", "&OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TemplateMatchUi: public Ui_TemplateMatchUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATEMATCHUI_H
