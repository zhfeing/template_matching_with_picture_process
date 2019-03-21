#include "templatematchui.h"

TemplateMatchUi::TemplateMatchUi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TemplateMatchUi)
{
    ifEdge = false;
    ifMulityAnswer = false;
    threshodPercent = 0.9;
    ui->setupUi(this);
    connect(ui->Okbutton, SIGNAL(clicked(bool)),
            this, SLOT(clickedOK()));
    connect(ui->cancelButton, SIGNAL(clicked(bool)),
            parent, SLOT(stopShowTemplPic()));
    connect(this, SIGNAL(openTemplatePicture()),
            parent, SLOT(openTemplatePicture()));
    connect(parent, SIGNAL(toTemplate_OpenPictureSucceed()),
            this, SLOT(openPictureSucceed()));
    connect(this, SIGNAL(getChooseMode(TemplateMatchUi::TemplateMatchMode, bool, bool, float)),
            parent, SLOT(getChooseMode(TemplateMatchUi::TemplateMatchMode, bool, bool, float)));
    connect(ui->choosePercentSpinBox, SIGNAL(valueChanged(double)),
            this, SLOT(changePercent(double)));
}

TemplateMatchUi::~TemplateMatchUi()
{
    delete ui;
}

void TemplateMatchUi::on_mulityResultCheckBox_clicked(bool checked)
{
    ifMulityAnswer = checked;
    if(checked)
    {
        ui->threshodLable->setEnabled(true);
        ui->choosePercentSpinBox->setEnabled(true);
    }
    else
    {
        ui->threshodLable->setEnabled(false);
        ui->choosePercentSpinBox->setEnabled(false);
    }
}

void TemplateMatchUi::on_edgeModeCheckBox_clicked(bool checked)
{
    ifEdge = checked;
}

void TemplateMatchUi::on_openTemplateButton_clicked()
{
    emit openTemplatePicture();
}

void TemplateMatchUi::on_crossCorrlationButton_clicked(bool checked)
{
    if(checked)
    {
        mode = CROSS_CORRELATION;
        ui->Okbutton->setEnabled(true);
        ui->edgeModeCheckBox->setEnabled(true);
        ui->mulityResultCheckBox->setEnabled(true);
    }
}

void TemplateMatchUi::on_absButton_clicked(bool checked)
{
    if(checked)
    {
        mode = ABS;
        ui->Okbutton->setEnabled(true);
        ui->edgeModeCheckBox->setEnabled(true);
        ui->mulityResultCheckBox->setEnabled(true);
    }
}

void TemplateMatchUi::on_fftButton_clicked(bool checked)
{
    if(checked)
    {
        mode = FFT;
        ui->Okbutton->setEnabled(true);
        ui->edgeModeCheckBox->setEnabled(false);
        ui->mulityResultCheckBox->setEnabled(false);
        ui->threshodLable->setEnabled(false);
        ui->choosePercentSpinBox->setEnabled(false);
    }
}

void TemplateMatchUi::clickedOK()
{
    this->close();
    emit getChooseMode(mode, ifMulityAnswer, ifEdge, threshodPercent);
}

void TemplateMatchUi::clickedCancel()
{
    this->close();
}

void TemplateMatchUi::openPictureSucceed()
{
    ui->absButton->setEnabled(true);
    ui->crossCorrlationButton->setEnabled(true);
    ui->edgeModeCheckBox->setEnabled(true);
    ui->fftButton->setEnabled(true);
    ui->label->setEnabled(true);
    ui->label_2->setEnabled(true);

    ui->mulityResultCheckBox->setEnabled(true);
    ui->openTemplateButton->setEnabled(false);
}

void TemplateMatchUi::on_cancelButton_clicked()
{
    emit stopShowTemplPic();
    clickedCancel();
}

void TemplateMatchUi::changePercent(double p)
{
    threshodPercent = p;
}
