#include "project.h"

bool MatToQImage(const Mat &mat, QImage &qimg)
{
    // 8-bits unsigned, NO. OF CHANNELS=1
    if(mat.type() == CV_8UC1)
    {
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        for (int i = 0; i < 256; i++)
            colorTable.push_back(qRgb(i, i, i));
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        qimg = QImage(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        qimg.setColorTable(colorTable);
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        qimg = QImage(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        qimg.rgbSwapped();
    }
    else
    {
        qimg = QImage();
        return false;
    }
    return true;
}

void enableShow(const Mat &m, Mat &m_out, bool ifNormalise)
{
    m.copyTo(m_out);
    m_out = cv::abs(m_out);
    if(ifNormalise)
    {
        m_out /= findMax(m_out);
        m_out *= 255;
    }
    else
    {
        MatIterator_<float>it, end;
        for(it = m_out.begin<float>(), end = m_out.end<float>(); it != end; it++)
        {
            if(*it > 255)
                *it = 255;
        }
    }
    m_out.convertTo(m_out, CV_8U);
}


void match(Mat &m, Mat &templ, TemplateMatchUi::TemplateMatchMode mode,
           bool ifEdge, bool ifMultiply, float percent)
{
    int rectx = templ.cols;
    int recty = templ.rows;
    if(mode == TemplateMatchUi::FFT)
    {
        double isPowOfTwo_w = std::log(double(m.rows))/log(2.0);
        int logSize_w = int(isPowOfTwo_w);
        double isPowOfTwo_h = std::log(double(m.cols))/log(2.0);
        int logSize_h = int(isPowOfTwo_h);
        if((isPowOfTwo_w - logSize_w) > 1e-6 || (isPowOfTwo_h - logSize_h) > 1e-6)
        {
            QMessageBox::warning(0, "FFT", "The Size Of Picture Is Not Power Of Two, "
                                           "Some Part Of Picture Will Be Ignore!");
        }
        Size newSize = findSuitableSizeForFFT(m.size());
        Point orignalPoint((m.cols - newSize.width)/2, (m.rows - newSize.height)/2);
        Mat temp = Mat(m, Rect(orignalPoint, newSize));
        Point res;
        res = TemplateMatch::templateMatch_FFT(temp, templ);
        res += orignalPoint;
        cv::Rect r;
        r = Rect(res, res + Point(rectx, recty));
        cv::rectangle(m, r, cv::Scalar(255, 255, 255), 2);
        return;
    }
    if(ifMultiply)
    {
        PointArray resultPoints;
        switch(mode)
        {
        case TemplateMatchUi::ABS:
            TemplateMatch::templateMatch(m, templ, resultPoints, TemplateMatch::ABS,
                                         ifEdge, 5, percent);
            break;
        case TemplateMatchUi::CROSS_CORRELATION:
            TemplateMatch::templateMatch(m, templ, resultPoints,
                                         TemplateMatch::CROSS_CORRELATION,
                                         ifEdge, 5, percent);
            break;
        default:
            QMessageBox::warning(0, "Match", "wrong type");
            break;
        }
        cv::Rect r;
        for(unsigned i = 0; i < resultPoints.size(); i++)
        {
            r = Rect(resultPoints[i] - Point(rectx/2, recty/2),
                     resultPoints[i] + Point(rectx/2, recty/2));
            cv::rectangle(m, r, cv::Scalar(255, 255, 255), 2);
        }
    }
    else
    {
        Point res;
        switch(mode)
        {
        case TemplateMatchUi::ABS:
            res = TemplateMatch::templateMatch(m, templ, TemplateMatch::ABS, ifEdge);
            break;
        case TemplateMatchUi::CROSS_CORRELATION:
            res = TemplateMatch::templateMatch(m, templ,
                                               TemplateMatch::CROSS_CORRELATION,
                                               ifEdge);
            break;
        default:
            QMessageBox::warning(0, "Match", "wrong type");
            break;
        }
        cv::Rect r;
        r = Rect(res - Point(rectx/2, recty/2), res + Point(rectx/2, recty/2));
        cv::rectangle(m, r, cv::Scalar(255, 255, 255), 2);
    }
}

Size findSuitableSizeForFFT(const Size s)
{
    int wid = s.width;
    int hei = s.height;
    int i;


    double isPowOfTwo = std::log(double(wid))/log(2.0);
    int logSize = int(isPowOfTwo);
    if((isPowOfTwo - logSize) > 1e-6)
    {
        for(i = 0; std::pow(2.0, i) < wid; i++)
            ;
        wid = pow(2.0, i - 1);
    }

    isPowOfTwo = std::log(double(hei))/log(2.0);
    logSize = int(isPowOfTwo);
    if((isPowOfTwo - logSize) > 1e-6)
    {
        for(i = 0; std::pow(2.0, i) < hei; i++)
            ;
        hei = pow(2.0, i - 1);
    }
    return Size(wid, hei);
}
