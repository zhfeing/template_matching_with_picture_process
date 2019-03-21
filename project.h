#ifndef PROJECT
#define PROJECT
#include "processfunction.h"
#include "templatematchui.h"
#include <QImage>
#include <QMessageBox>
#include <cmath>

using cv::Size;

bool MatToQImage(const Mat &mat, QImage &qimg);
void enableShow(const Mat &m, Mat &m_out, bool ifNormalise = false);
void match(Mat &m, Mat &templ, TemplateMatchUi::TemplateMatchMode mode,
           bool ifEdge, bool ifMultiply, float percent);
void ifSuitableForFFT(const Mat m);
Size findSuitableSizeForFFT(const Size s);
#endif // PROJECT
