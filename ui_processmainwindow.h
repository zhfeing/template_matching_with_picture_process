/********************************************************************************
** Form generated from reading UI file 'processmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSMAINWINDOW_H
#define UI_PROCESSMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProcessMainWindow
{
public:
    QAction *action_open_picture;
    QAction *action_save_as;
    QAction *action_Quit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *openPictureButton;
    QPushButton *closePictureButton;
    QSpacerItem *horizontalSpacer;
    QLabel *logo;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *saveButton;
    QSpacerItem *verticalSpacer_5;
    QPushButton *unDoButton;
    QSpacerItem *verticalSpacer_6;
    QPushButton *denoiseButton;
    QSpacerItem *verticalSpacer_8;
    QPushButton *sharpButton;
    QSpacerItem *verticalSpacer_9;
    QPushButton *templateMatchButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QFrame *verticalLine;
    QWidget *showPictureWidget;
    QLabel *label;
    QFrame *verticalLine_2;
    QWidget *showTemplateWidget;
    QLabel *label_2;
    QFrame *verticalLine_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menu_Help;

    void setupUi(QMainWindow *ProcessMainWindow)
    {
        if (ProcessMainWindow->objectName().isEmpty())
            ProcessMainWindow->setObjectName(QString::fromUtf8("ProcessMainWindow"));
        ProcessMainWindow->resize(1290, 947);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ProcessMainWindow->sizePolicy().hasHeightForWidth());
        ProcessMainWindow->setSizePolicy(sizePolicy);
        ProcessMainWindow->setMinimumSize(QSize(1290, 947));
        ProcessMainWindow->setMaximumSize(QSize(1290, 947));
        ProcessMainWindow->setStyleSheet(QString::fromUtf8("QMainWindow,QDialog\n"
"{\n"
"    \n"
"	color: rgb(223, 223, 223);\n"
"	background-color: rgb(255, 255, 127);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color: rgb(43, 43, 43);\n"
"	background-color: rgb(255, 213, 41);\n"
"}"));
        action_open_picture = new QAction(ProcessMainWindow);
        action_open_picture->setObjectName(QString::fromUtf8("action_open_picture"));
        action_save_as = new QAction(ProcessMainWindow);
        action_save_as->setObjectName(QString::fromUtf8("action_save_as"));
        action_Quit = new QAction(ProcessMainWindow);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        actionAbout = new QAction(ProcessMainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(ProcessMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 1308, 958));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        openPictureButton = new QPushButton(layoutWidget);
        openPictureButton->setObjectName(QString::fromUtf8("openPictureButton"));
        sizePolicy.setHeightForWidth(openPictureButton->sizePolicy().hasHeightForWidth());
        openPictureButton->setSizePolicy(sizePolicy);
        openPictureButton->setMinimumSize(QSize(120, 50));
        openPictureButton->setMaximumSize(QSize(140, 70));
        QFont font;
        font.setPointSize(13);
        openPictureButton->setFont(font);
        openPictureButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{color: rgb(255, 255, 127);\n"
"background-color: rgb(255, 85, 0);\n"
"border-color: rgb(255, 85, 100);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color: rgb(43, 43, 43);\n"
"	background-color: rgb(255, 213, 41);\n"
"}"));
        openPictureButton->setDefault(true);

        horizontalLayout->addWidget(openPictureButton);

        closePictureButton = new QPushButton(layoutWidget);
        closePictureButton->setObjectName(QString::fromUtf8("closePictureButton"));
        closePictureButton->setEnabled(false);
        sizePolicy.setHeightForWidth(closePictureButton->sizePolicy().hasHeightForWidth());
        closePictureButton->setSizePolicy(sizePolicy);
        closePictureButton->setMinimumSize(QSize(120, 50));
        closePictureButton->setMaximumSize(QSize(140, 70));
        closePictureButton->setFont(font);
        closePictureButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        closePictureButton->setDefault(false);

        horizontalLayout->addWidget(closePictureButton);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        logo = new QLabel(layoutWidget);
        logo->setObjectName(QString::fromUtf8("logo"));
        sizePolicy.setHeightForWidth(logo->sizePolicy().hasHeightForWidth());
        logo->setSizePolicy(sizePolicy);
        logo->setMinimumSize(QSize(250, 35));
        logo->setMaximumSize(QSize(270, 50));
        QFont font1;
        font1.setPointSize(20);
        logo->setFont(font1);
        logo->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(logo);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        line = new QFrame(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setMinimumSize(QSize(1214, 20));
        line->setMaximumSize(QSize(1280, 20));
        line->setSizeIncrement(QSize(1280, 0));
        line->setStyleSheet(QString::fromUtf8("color: rgb(138, 138, 138);\n"
"background-color: rgb(255, 255, 127);"));
        line->setLineWidth(3);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        saveButton = new QPushButton(layoutWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setEnabled(false);
        sizePolicy.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy);
        saveButton->setMinimumSize(QSize(100, 70));
        saveButton->setMaximumSize(QSize(100, 70));
        saveButton->setFont(font);
        saveButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        verticalLayout->addWidget(saveButton);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        unDoButton = new QPushButton(layoutWidget);
        unDoButton->setObjectName(QString::fromUtf8("unDoButton"));
        unDoButton->setEnabled(false);
        sizePolicy.setHeightForWidth(unDoButton->sizePolicy().hasHeightForWidth());
        unDoButton->setSizePolicy(sizePolicy);
        unDoButton->setMinimumSize(QSize(100, 70));
        unDoButton->setMaximumSize(QSize(100, 70));
        unDoButton->setFont(font);
        unDoButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        verticalLayout->addWidget(unDoButton);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        denoiseButton = new QPushButton(layoutWidget);
        denoiseButton->setObjectName(QString::fromUtf8("denoiseButton"));
        denoiseButton->setEnabled(false);
        sizePolicy.setHeightForWidth(denoiseButton->sizePolicy().hasHeightForWidth());
        denoiseButton->setSizePolicy(sizePolicy);
        denoiseButton->setMinimumSize(QSize(100, 70));
        denoiseButton->setMaximumSize(QSize(100, 70));
        denoiseButton->setFont(font);
        denoiseButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        verticalLayout->addWidget(denoiseButton);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_8);

        sharpButton = new QPushButton(layoutWidget);
        sharpButton->setObjectName(QString::fromUtf8("sharpButton"));
        sharpButton->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(90);
        sizePolicy1.setVerticalStretch(60);
        sizePolicy1.setHeightForWidth(sharpButton->sizePolicy().hasHeightForWidth());
        sharpButton->setSizePolicy(sizePolicy1);
        sharpButton->setMinimumSize(QSize(100, 70));
        sharpButton->setMaximumSize(QSize(100, 70));
        sharpButton->setFont(font);
        sharpButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        verticalLayout->addWidget(sharpButton);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_9);

        templateMatchButton = new QPushButton(layoutWidget);
        templateMatchButton->setObjectName(QString::fromUtf8("templateMatchButton"));
        templateMatchButton->setEnabled(false);
        sizePolicy.setHeightForWidth(templateMatchButton->sizePolicy().hasHeightForWidth());
        templateMatchButton->setSizePolicy(sizePolicy);
        templateMatchButton->setMinimumSize(QSize(100, 70));
        templateMatchButton->setMaximumSize(QSize(100, 70));
        templateMatchButton->setFont(font);
        templateMatchButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        verticalLayout->addWidget(templateMatchButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLine = new QFrame(layoutWidget);
        verticalLine->setObjectName(QString::fromUtf8("verticalLine"));
        sizePolicy.setHeightForWidth(verticalLine->sizePolicy().hasHeightForWidth());
        verticalLine->setSizePolicy(sizePolicy);
        verticalLine->setMinimumSize(QSize(20, 750));
        verticalLine->setMaximumSize(QSize(20, 750));
        verticalLine->setFont(font1);
        verticalLine->setStyleSheet(QString::fromUtf8("color: rgb(138, 138, 138);\n"
"background-color: rgb(255, 255, 127);"));
        verticalLine->setLineWidth(3);
        verticalLine->setFrameShape(QFrame::VLine);
        verticalLine->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(verticalLine);

        showPictureWidget = new QWidget(layoutWidget);
        showPictureWidget->setObjectName(QString::fromUtf8("showPictureWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(showPictureWidget->sizePolicy().hasHeightForWidth());
        showPictureWidget->setSizePolicy(sizePolicy2);
        showPictureWidget->setMinimumSize(QSize(630, 750));
        showPictureWidget->setMaximumSize(QSize(650, 800));
        showPictureWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: rgb(53, 53, 53);\n"
"}"));
        label = new QLabel(showPictureWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 111, 41));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 255);"));

        horizontalLayout_2->addWidget(showPictureWidget);

        verticalLine_2 = new QFrame(layoutWidget);
        verticalLine_2->setObjectName(QString::fromUtf8("verticalLine_2"));
        sizePolicy.setHeightForWidth(verticalLine_2->sizePolicy().hasHeightForWidth());
        verticalLine_2->setSizePolicy(sizePolicy);
        verticalLine_2->setMinimumSize(QSize(20, 760));
        verticalLine_2->setMaximumSize(QSize(20, 760));
        verticalLine_2->setFont(font1);
        verticalLine_2->setStyleSheet(QString::fromUtf8("color: rgb(138, 138, 138);\n"
"background-color: rgb(255, 255, 127);"));
        verticalLine_2->setLineWidth(3);
        verticalLine_2->setFrameShape(QFrame::VLine);
        verticalLine_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(verticalLine_2);

        showTemplateWidget = new QWidget(layoutWidget);
        showTemplateWidget->setObjectName(QString::fromUtf8("showTemplateWidget"));
        sizePolicy.setHeightForWidth(showTemplateWidget->sizePolicy().hasHeightForWidth());
        showTemplateWidget->setSizePolicy(sizePolicy);
        showTemplateWidget->setMinimumSize(QSize(371, 750));
        showTemplateWidget->setMaximumSize(QSize(420, 800));
        showTemplateWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"color: rgb(166, 166, 166);\n"
"	background-color: rgb(53, 53, 53);\n"
"}"));
        label_2 = new QLabel(showTemplateWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 0, 151, 41));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 255);"));

        horizontalLayout_2->addWidget(showTemplateWidget);

        verticalLine_3 = new QFrame(layoutWidget);
        verticalLine_3->setObjectName(QString::fromUtf8("verticalLine_3"));
        sizePolicy.setHeightForWidth(verticalLine_3->sizePolicy().hasHeightForWidth());
        verticalLine_3->setSizePolicy(sizePolicy);
        verticalLine_3->setMinimumSize(QSize(20, 750));
        verticalLine_3->setMaximumSize(QSize(20, 750));
        verticalLine_3->setFont(font1);
        verticalLine_3->setStyleSheet(QString::fromUtf8("color: rgb(138, 138, 138);\n"
"background-color: rgb(255, 255, 127);"));
        verticalLine_3->setLineWidth(3);
        verticalLine_3->setFrameShape(QFrame::VLine);
        verticalLine_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(verticalLine_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        ProcessMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProcessMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1290, 35));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menu_Help = new QMenu(menubar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        ProcessMainWindow->setMenuBar(menubar);
        QWidget::setTabOrder(sharpButton, templateMatchButton);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menu_Help->menuAction());
        menuFile->addAction(action_open_picture);
        menuFile->addAction(action_save_as);
        menuFile->addSeparator();
        menuFile->addAction(action_Quit);
        menu_Help->addAction(actionAbout);

        retranslateUi(ProcessMainWindow);

        QMetaObject::connectSlotsByName(ProcessMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ProcessMainWindow)
    {
        ProcessMainWindow->setWindowTitle(QApplication::translate("ProcessMainWindow", "Template Match", 0, QApplication::UnicodeUTF8));
        action_open_picture->setText(QApplication::translate("ProcessMainWindow", "&Open picture", 0, QApplication::UnicodeUTF8));
        action_save_as->setText(QApplication::translate("ProcessMainWindow", "&Save as", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("ProcessMainWindow", "&Quit", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("ProcessMainWindow", "&About", 0, QApplication::UnicodeUTF8));
        openPictureButton->setText(QApplication::translate("ProcessMainWindow", "Open\n"
"picture", 0, QApplication::UnicodeUTF8));
        closePictureButton->setText(QApplication::translate("ProcessMainWindow", "Close\n"
"picture", 0, QApplication::UnicodeUTF8));
        logo->setText(QApplication::translate("ProcessMainWindow", "Designed by ZHF", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("ProcessMainWindow", "Save", 0, QApplication::UnicodeUTF8));
        unDoButton->setText(QApplication::translate("ProcessMainWindow", "Undo", 0, QApplication::UnicodeUTF8));
        denoiseButton->setText(QApplication::translate("ProcessMainWindow", "Denoise", 0, QApplication::UnicodeUTF8));
        sharpButton->setText(QApplication::translate("ProcessMainWindow", "Sharp", 0, QApplication::UnicodeUTF8));
        templateMatchButton->setText(QApplication::translate("ProcessMainWindow", "Template\n"
"match", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ProcessMainWindow", "picture", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ProcessMainWindow", "template", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("ProcessMainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menu_Help->setTitle(QApplication::translate("ProcessMainWindow", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProcessMainWindow: public Ui_ProcessMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSMAINWINDOW_H
