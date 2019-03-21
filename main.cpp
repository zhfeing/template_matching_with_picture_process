#include "mainwindow.h"
#include <QApplication>
#include "pictureprcess.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    const Mat img = cv::imread("/home/zhf/桌面/img01-00.jpg", cv::IMREAD_GRAYSCALE);
    cv::namedWindow("o", CV_NORMAL);
    cv::imshow("o", img);


    Mat templ = cv::imread("/home/zhf/桌面/img01-02.jpg", cv::IMREAD_GRAYSCALE);
    cv::namedWindow("hhh", CV_NORMAL);
    templ.convertTo(templ, CV_32F);
    Mat scr;
    img.convertTo(scr, CV_32F);
//    cv::resize(scr, scr, cv::Size(512, 512));
//    cv::resize(templ, templ, cv::Size(53/4, 104/4));
//    double t = (double)cvGetTickCount();
//    //Point bestPoint;
//    //bestPoint = TemplateMatch::templateMatch_FFT(scr, templ);
//    //  算法过程
////    Point bestPoint = TemplateMatch::
////            templateMatch(scr, templ, true, TemplateMatch::ABS);
//    PointArray arr;
//    TemplateMatch::templateMatch(scr, templ, arr, TemplateMatch::CROSS_CORRELATION,
//                                 false, 8, 0.5);
//    t = (double)cvGetTickCount() - t;
//    //printf( "run time = %gms\n", t/(cvGetTickFrequency()*1000) );
//    printf( "run time = %gs\n", t/(cvGetTickFrequency()*1000000) );

//    Mat A;
////    if(bestPoint.x > 20 && bestPoint.y > 20)
////    {
////        cv::rectangle(scr, Point(bestPoint.x - 20, bestPoint.y - 20),
////                      bestPoint, cv::Scalar(255, 255, 255));
////    }

//    for(unsigned i = 0; i < arr.size(); i++)
//    {
//        Point bestPoint = arr[i];
//        if(bestPoint.x > 20 && bestPoint.y > 20)
//        {
//            A = Mat(scr, Rect(bestPoint.x - 20, bestPoint.y - 20, 20, 20));
//        }
//        else
//        {
//            A = Mat(scr, Rect(bestPoint.x, bestPoint.y, 20, 20));
//        }
//        A *= 0;
//    }

//    /*Mat A, B, C;
//    FFT::ImgFFT(scr, A, B);
//    FFT::ImgIFFT(A, B, C);
//*/
    Mat A, B, C;
    Filter::medianFilter(scr, B);
    Filter::medianFilter(B, A);
//    A /= findMax(A);
//    A *= 255;
    A.convertTo(A, CV_8U);
    cv::imshow("hhh", A);
    return a.exec();
}
