#ifndef PROCESSMAINWINDOW_H
#define PROCESSMAINWINDOW_H

#include "ui_processmainwindow.h"
#include "processfunction.h"
#include "project.h"
#include "choosesharporder.h"
#include "templatematchui.h"
#include <QMainWindow>

namespace Ui {
class ProcessMainWindow;
}

class ProcessMainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit ProcessMainWindow(QWidget *parent = 0);
    ~ProcessMainWindow();

private slots:
    void on_action_open_picture_triggered();

    void on_openPictureButton_clicked();

    void on_action_Quit_triggered();

    void on_closePictureButton_clicked();

    void on_denoiseButton_clicked();

    void on_unDoButton_clicked();

    void on_saveButton_clicked();

    void on_sharpButton_clicked();

signals:
    void toTemplate_OpenPictureSucceed();

private slots:
    void getChooseMode(ChooseSharpOrder::ChooseSharpMode mode);

    void getChooseMode(TemplateMatchUi::TemplateMatchMode mode,
                       bool ifMulityAnswer, bool ifEdge, float percent);

    void on_action_save_as_triggered();

    void on_actionAbout_triggered();

    void on_templateMatchButton_clicked();

    void openTemplatePicture();

    void stopShowTemplPic();

private:
    Ui::ProcessMainWindow *ui;

    QLabel *showPictureLabel;
    QLabel *showTemplateLable;

    Mat processImg;
    Mat saveImg;
    Mat cv_showImg;
    QImage qShowImg;
    QString picturePath;
    bool pictureEdited;

    float pictureResizeValue;
    bool ifResized;
    float threadPercent;

    Mat templateImg;
    QImage qShowTemplateImg;
    QString templatePath;

    ChooseSharpOrder::ChooseSharpMode sharpMode;
    TemplateMatchUi::TemplateMatchMode templateMatchMode;
    bool ifTemplateMatchMulityResult;
    bool ifTemplateMatchEdge;

    void setupMainWindow();

    void openPicture();
    void closePicture();
    bool loadPicture(QString &pictureName);
    void flushEditInterface(bool ifCreateEditInterface);
    bool warningPictureOpeenAndClose();
    bool showPicture(bool ifNormalize = false);
    void releaseAllPictures();
    bool saveEditedImg();
    bool saveEditedImg(QString savePath);

    bool loadTemplate(QString &templatePath);
    bool showTemplate();
};

#endif // PROCESSMAINWINDOW_H
