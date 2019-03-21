#ifndef TEMPLATEMATCHUI_H
#define TEMPLATEMATCHUI_H

#include <QDialog>
#include "ui_templatematchui.h"

namespace Ui {
class TemplateMatchUi;
}

class TemplateMatchUi : public QDialog
{
    Q_OBJECT

public:
    enum TemplateMatchMode
    {
        ABS, CROSS_CORRELATION, FFT
    };

    explicit TemplateMatchUi(QWidget *parent = 0);
    ~TemplateMatchUi();

signals:
    void getChooseMode(TemplateMatchUi::TemplateMatchMode mode,
                       bool ifMulityAnswer, bool ifEdge, float percent);
    void openTemplatePicture();
    void stopShowTemplPic();
private slots:
    void on_mulityResultCheckBox_clicked(bool checked);

    void on_edgeModeCheckBox_clicked(bool checked);

    void on_openTemplateButton_clicked();

    void on_crossCorrlationButton_clicked(bool checked);

    void on_absButton_clicked(bool checked);

    void on_fftButton_clicked(bool checked);

    void clickedOK();

    void clickedCancel();

    void openPictureSucceed();

    void on_cancelButton_clicked();

    void changePercent(double p);
private:
    bool ifMulityAnswer;
    bool ifEdge;
    TemplateMatchMode mode;
    float threshodPercent;

    Ui::TemplateMatchUi *ui;
};

#endif // TEMPLATEMATCHUI_H
