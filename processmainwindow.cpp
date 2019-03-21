#include "processmainwindow.h"
#include <QtGui>

ProcessMainWindow::ProcessMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProcessMainWindow)
{
    pictureEdited = false;

    ui->setupUi(this);
    setupMainWindow();
}

ProcessMainWindow::~ProcessMainWindow()
{
    delete ui;
}

void ProcessMainWindow::on_action_open_picture_triggered()
{
    openPicture();
    showPicture();
}

void ProcessMainWindow::openPicture()
{
    if(saveImg.empty() == false && pictureEdited == true)
    {
        int r = QMessageBox::warning(this, tr("Close Picture"),
                                     tr("the picture has been edited, do you want to save it?"),
                                     QMessageBox::Yes | QMessageBox::No
                                     | QMessageBox::Cancel);
        if(r == QMessageBox::Yes)
        {
            //save changes
            cv::imwrite(picturePath.toUtf8().data(), cv_showImg);
            releaseAllPictures();
        }
        else if(r == QMessageBox::No)
        {
            //close picture directly
            releaseAllPictures();
        }
        else    //clicked cancle and don't do anything
        {
            return;//don't change anything
        }
    }
    picturePath = QFileDialog::getOpenFileName(this, tr("Open a picture"),
                                              QDir::currentPath(),
                                              tr("Picture files (*.jpg *.bmp);;"));
    if(picturePath.isEmpty())//failed to open this picture
    {
       QMessageBox::warning(this, tr("Open Picture"), tr("Failed to load picture"));
       return;
    }
    if(!loadPicture(picturePath))
    {
       QMessageBox::warning(this, tr("Open Picture"), tr("Failed to load picture"));
       return;
    }
    QMessageBox::warning(this, tr("Open Picture"),
                         tr("Picture Will Be Convert To Gray Picture"));
    flushEditInterface(true);
}

bool ProcessMainWindow::loadPicture(QString &pictureName)
{
    releaseAllPictures();
    saveImg = cv::imread(pictureName.toUtf8().data(), cv::IMREAD_GRAYSCALE);

    ifResized = false;
    if((saveImg.rows >= saveImg.cols) && (saveImg.rows > 512))//too high
    {
        int r = QMessageBox::warning(this, tr("Open Picture"),
                             tr("Picture is Too Large, Do You Want To Resize?"),
                             QMessageBox::No | QMessageBox::Yes);
        if(r == QMessageBox::Yes)
        {
            pictureResizeValue = 512.0/saveImg.cols;
            cv::resize(saveImg, saveImg, cv::Size(512, saveImg.rows*512/saveImg.cols));
            ifResized = true;
        }
    }
    else if(saveImg.cols > 512)//too wide
    {
        int r = QMessageBox::warning(this, tr("Open Picture"),
                             tr("Picture is Too Large, It Will Be Resized"),
                             QMessageBox::No | QMessageBox::Yes);
        if(r == QMessageBox::Yes)
        {
            pictureResizeValue = 512.0/saveImg.rows;
            cv::resize(saveImg, saveImg, cv::Size(saveImg.cols*512/saveImg.rows, 512));
            ifResized = true;
        }
    }
    saveImg.convertTo(processImg, CV_32F);
    saveImg.copyTo(cv_showImg);
    if(processImg.empty())
    {
        return false;
    }
    if(!MatToQImage(cv_showImg, qShowImg))//bind cv::Mat to QImg
    {
        releaseAllPictures();
        return false;
    }
    processImg.convertTo(processImg, CV_32F);
    return true;
}

void ProcessMainWindow::on_openPictureButton_clicked()
{
    openPicture();
    showPicture();
}

void ProcessMainWindow::on_action_Quit_triggered()
{
    if(pictureEdited == false)
    {
        this->close();
    }
    else
    {
        if(warningPictureOpeenAndClose())
        {
            this->close();
        }
    }
}

void ProcessMainWindow::flushEditInterface(bool ifCreateEditInterface)
{
    if(ifCreateEditInterface)
    {
        ui->saveButton->setEnabled(true);
        ui->unDoButton->setEnabled(true);
        ui->sharpButton->setEnabled(true);
        ui->closePictureButton->setEnabled(true);
        ui->denoiseButton->setEnabled(true);
        ui->templateMatchButton->setEnabled(true);
        showPictureLabel->show();
        showTemplateLable->close();
    }
    else
    {
        ui->saveButton->setEnabled(false);
        ui->unDoButton->setEnabled(false);
        ui->sharpButton->setEnabled(false);
        ui->closePictureButton->setEnabled(false);
        ui->denoiseButton->setEnabled(false);
        ui->templateMatchButton->setEnabled(false);
        ui->showPictureWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: rgb(53, 53, 53);\n"
"}"));
        showPictureLabel->close();
        showTemplateLable->close();
    }
}

void ProcessMainWindow::on_closePictureButton_clicked()
{
    closePicture();
}

void ProcessMainWindow::closePicture()
{
    if(warningPictureOpeenAndClose())
    {
        flushEditInterface(false);//fflush the edit interface
    }
}

bool ProcessMainWindow::warningPictureOpeenAndClose()
{
    if(processImg.empty() && saveImg.empty())// the picture has not been opened
    {
        return true;
    }
    else    //the picture has been opened
    {
        if(pictureEdited == true)
        {
            int r = QMessageBox::warning(this, tr("Close Picture"),
                                         tr("the picture has been edited, do you want to save it?"),
                                         QMessageBox::Cancel | QMessageBox::No
                                         | QMessageBox::Yes);
            if(r == QMessageBox::Yes)
            {
                //save changes
                saveEditedImg();
                releaseAllPictures();
            }
            else if(r == QMessageBox::No)
            {
                //close picture directly
                releaseAllPictures();
            }
            else    //clicked cancle and don't do anything
            {
                return false;//don't change anything
            }
            pictureEdited = false;
        }
        else
        {
            //the picture has not been edited
            releaseAllPictures();
        }
        return true;
    }
}

bool ProcessMainWindow::showPicture(bool ifNormalize)
{
    if(processImg.empty())
        return false;
    enableShow(processImg, cv_showImg, ifNormalize);
    if(!MatToQImage(cv_showImg, qShowImg))//failed to convert the picture to QImag
    {
        QMessageBox::critical(this, "showPicture()",
                              "Failed to convert the picture to QImag!");
        return false;
    }

    ui->showPictureWidget->setAutoFillBackground(true);
    QPixmap pixmap(QPixmap::fromImage(qShowImg));

    int picHeight = qShowImg.height();
    int picWidth = qShowImg.width();
    int widHeight = ui->showPictureWidget->height();
    int widWidth = ui->showPictureWidget->width();

    float heightZoomFactor = (float)widHeight/(float)picHeight;
    float widthZoomFactor = (float)widWidth/(float)picWidth;

    QPixmap fitpixmap;
    if(heightZoomFactor < widthZoomFactor)//too high
    {
        fitpixmap = pixmap.scaled(picWidth*heightZoomFactor, widHeight,
                                      Qt::KeepAspectRatio,
                                      Qt::SmoothTransformation);
    }
    else//too low
    {
        fitpixmap = pixmap.scaled(widWidth, picHeight*widthZoomFactor,
                                      Qt::KeepAspectRatio,
                                      Qt::SmoothTransformation);
    }

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(fitpixmap));
//    ui->showPictureWidget->setStyleSheet("");
//    ui->showPictureWidget->setPalette(palette);

    showPictureLabel->setFixedSize(fitpixmap.size());
    showPictureLabel->setPixmap(fitpixmap);
    showPictureLabel->show();

    return true;
}

void ProcessMainWindow::releaseAllPictures()
{
    saveImg.release();
    cv_showImg.release();
    processImg.release();
}

bool ProcessMainWindow::saveEditedImg()
{
    if(picturePath.isEmpty() || saveImg.empty())
    {
        QMessageBox::warning(this, tr("saveEditedImg()"),
                             tr("Failed To Save Picture"));
        return false;
    }
    if(!cv::imwrite(picturePath.toUtf8().data(), cv_showImg))
    {
        QMessageBox::warning(this, tr("saveEditedImg()"),
                             tr("Failed To Save Picture"));
        return false;
    }
    return true;
}

bool ProcessMainWindow::saveEditedImg(QString savePath)
{
    if(savePath.isEmpty() || saveImg.empty())
    {
        QMessageBox::warning(this, tr("saveEditedImg()"),
                             tr("Failed To Save Picture"));
        return false;
    }
    try
    {
        if(!cv::imwrite(savePath.toUtf8().data(), cv_showImg))
        {
            QMessageBox::warning(this, tr("saveEditedImg()"),
                                 tr("Failed To Save Picture"));
            return false;
        }
    }
    catch(cv::Exception)
    {
        int rul = QMessageBox::warning(this, tr("saveEditedImg()"),
                          tr("Failed To Save Picture, Wrong File Name, "
                             "Do You Want To Change File Name Automatically"),
                          QMessageBox::Ok | QMessageBox::Cancel);
        if(rul == QMessageBox::Ok)
        {
            try
            {
                if(!cv::imwrite((savePath.toUtf8() + ".jpg").data() , cv_showImg))
                {
                    QMessageBox::warning(this, tr("saveEditedImg()"),
                                         tr("Failed To Save Picture"));
                    return false;
                }
            }
            catch(cv::Exception)
            {
                QMessageBox::warning(this, tr("saveEditedImg()"),
                                    tr("Failed To Change File Name"));
                return false;
            }
        }
        return false;
    }

    return true;
}

void ProcessMainWindow::setupMainWindow()
{
    showPictureLabel = new QLabel(ui->showPictureWidget);
    showPictureLabel->setAutoFillBackground(true);

    showTemplateLable = new QLabel(ui->showTemplateWidget);
    showTemplateLable->setAutoFillBackground(true);

    ifResized = false;
    threadPercent = 0.9;
}

void ProcessMainWindow::on_denoiseButton_clicked()
{
    Mat temp;
    Filter::medianFilter(processImg, temp);
    temp.copyTo(processImg);
    pictureEdited = true;
    if(showPicture(false))  //failed to save picture
    {
        QMessageBox::information(this, "Denoise", "Done!");
    }
    else
    {
        QMessageBox::critical(this, "Denoise", "Failed To Denoise Picture");
    }
}

void ProcessMainWindow::on_unDoButton_clicked()
{
    saveImg.convertTo(processImg, CV_32F);
    if(!showPicture())
    {
        QMessageBox::critical(this, "Undo", "Failed To Undo");
    }
}

void ProcessMainWindow::on_saveButton_clicked()
{
    cv_showImg.copyTo(saveImg);
    if(!saveEditedImg())
    {
        QMessageBox::critical(this, "Save Picture", "Failed To Save Picture");
    }
    pictureEdited = false;
}

void ProcessMainWindow::on_sharpButton_clicked()
{
    ChooseSharpOrder *choose = new ChooseSharpOrder(this);
    choose->show();
}

void ProcessMainWindow::getChooseMode
                (ChooseSharpOrder::ChooseSharpMode mode)
{
    sharpMode = mode;
    Mat temp;
    switch (mode)
    {
    case ChooseSharpOrder::firstOrder:
        Filter::firstOrderHPF(processImg, temp);
        temp = cv::abs(temp);
        processImg += temp/5.0;
        showPicture(false);
        break;
    case ChooseSharpOrder::secondOrder:
        Filter::secondOrderHPF(processImg, temp);
        temp = cv::abs(temp);
        processImg += temp/5.0;
        showPicture(false);
        break;
    default:
        QMessageBox::warning(this, "getChoose()", "Wrong Sharp Type!");
        return;
    }
    pictureEdited = true;
    QMessageBox::information(this, "Denoise", "Done!");
}

void ProcessMainWindow::getChooseMode(TemplateMatchUi::TemplateMatchMode mode,
                                      bool ifMulityAnswer, bool ifEdge, float percent)
{
    templateMatchMode = mode;
    this->ifTemplateMatchEdge = ifEdge;
    this->ifTemplateMatchMulityResult = ifMulityAnswer;
    match(processImg, templateImg, mode, ifEdge, ifMulityAnswer, percent);
    showPicture();
    pictureEdited = true;
    QMessageBox::information(this, tr("Match"), tr("Done"));
}

void ProcessMainWindow::on_action_save_as_triggered()
{
    if(cv_showImg.empty())//doesn't opened a picture
    {
        QMessageBox::warning(this, tr("Save As"), tr("No Picture Opened!"));
        return;
    }
    if(picturePath.isEmpty())
    {
        QMessageBox::critical(this, tr("Save As"),
                              tr("ERROR! Failed To Save Picture\nNo Correct Path"));
    }
    QString saveFilePath;
    saveFilePath = QFileDialog::getSaveFileName(this, tr("Save AS"),
                                                QDir::currentPath(),
                                                tr("Picture files (*.jpg *.bmp);;"));
    if(saveFilePath.isEmpty())
    {
        QMessageBox::warning(this, "Save As", "Failed To Get Save Path");
        on_action_save_as_triggered();
        return;
    }
    saveEditedImg(saveFilePath);
}

void ProcessMainWindow::on_actionAbout_triggered()
{
    //show right copy
}

void ProcessMainWindow::on_templateMatchButton_clicked()
{
    TemplateMatchUi *templateMatchDialog = new TemplateMatchUi(this);
    templateMatchDialog->show();

}

void ProcessMainWindow::openTemplatePicture()
{
    templatePath = QFileDialog::getOpenFileName(this, tr("Open a template"),
                                              QDir::currentPath(),
                                              tr("Picture files (*.jpg *.bmp);;"));
    if(templatePath.isEmpty())//failed to open this template
    {
       QMessageBox::warning(this, tr("Open Template"), tr("Failed to load template"));
       templateImg.release();
       return;
    }
    if(!loadTemplate(templatePath))
    {
       QMessageBox::warning(this, tr("Open Template"), tr("Failed to load template"));
       return;
    }
    emit toTemplate_OpenPictureSucceed();

}

bool ProcessMainWindow::loadTemplate(QString &templatePath)
{
    templateImg.release();
    templateImg = cv::imread(templatePath.toUtf8().data(), cv::IMREAD_GRAYSCALE);
    if(templateImg.empty())
    {
        return false;
    }
    if(ifResized)//the process picture had been resized
    {
        cv::resize(templateImg, templateImg,
                   cv::Size(templateImg.cols*pictureResizeValue,
                   templateImg.rows*pictureResizeValue));
    }
    if(!MatToQImage(templateImg, qShowTemplateImg))//bind cv::Mat to QImg
    {
        templateImg.release();
        return false;
    }
    showTemplate();
    templateImg.convertTo(templateImg, CV_32F);
    return true;
}

bool ProcessMainWindow::showTemplate()
{
    if(templateImg.empty() || qShowTemplateImg.isNull())
        return false;

    ui->showTemplateWidget->setAutoFillBackground(true);
    QPixmap pixmap(QPixmap::fromImage(qShowTemplateImg));

    int templHeight = qShowTemplateImg.height();
    int templWidth = qShowTemplateImg.width();
    int widHeight = ui->showTemplateWidget->height();
    int widWidth = ui->showTemplateWidget->width();

    float heightZoomFactor = (float)widHeight/(float)templHeight;
    float widthZoomFactor = (float)widWidth/(float)templWidth;

    QPixmap fitpixmap;
    if(heightZoomFactor < widthZoomFactor)//too high
    {
        fitpixmap = pixmap.scaled(templWidth*heightZoomFactor, widHeight,
                                      Qt::IgnoreAspectRatio,
                                      Qt::SmoothTransformation);
    }
    else//too low
    {
        fitpixmap = pixmap.scaled(widWidth, templHeight*widthZoomFactor,
                                      Qt::IgnoreAspectRatio,
                                      Qt::SmoothTransformation);
    }

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(fitpixmap));

    showTemplateLable->setFixedSize(fitpixmap.size());
    showTemplateLable->setPixmap(fitpixmap);
    showTemplateLable->show();

    return true;
}

void ProcessMainWindow::stopShowTemplPic()
{
    templateImg.release();
    showTemplateLable->close();
}
