#ifndef PROCESSFUNCTION
#define PROCESSFUNCTION

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using cv::Mat;
using cv::Rect;
using cv::Point;
using cv::MatIterator_;
using cv::MatConstIterator_;
using std::cout;
using std::endl;

typedef std::vector<Point> PointArray;

namespace Cauculator
{
    void applyCauculator(const Mat& scr, const Mat& cauculator, Mat& dst, bool ifAbs, bool ifEdgeSetToZero);
    void LoGTemplate(Mat& t, int size, float segma);
    const Mat FirstOrderHPF = (cv::Mat_<float>(2, 2) <<
                         2,-1,
                        -1, 0);
    const Mat FirstOrderLPF = (cv::Mat_<float>(2, 2) <<
                         0.25, 0.25,
                         0.25, 0.25);
    const Mat SecondOrderHPF = (cv::Mat_<float>(3, 3) <<
                  -1,-1,-1,
                  -1, 8,-1,
                  -1,-1,-1);
    const Mat SecondOrderLPF = (cv::Mat_<float>(3, 3) <<
                   1, 2, 1,
                   2, 4, 2,
                   1, 2, 1)/16.0;
    const Mat Laplaze = (cv::Mat_<float>(3, 3) <<
                   0,-1, 0,
                  -1, 4,-1,
                   0,-1, 0);
    const Mat GaussFilter = (cv::Mat_<float>(5, 5) <<
                             0.002, 0.013, 0.220, 0.013, 0.002,
                             0.013, 0.060, 0.098, 0.060, 0.013,
                             0.220, 0.098, 0.162, 0.098, 0.220,
                             0.013, 0.060, 0.098, 0.060, 0.013,
                             0.002, 0.013, 0.220, 0.013, 0.002);
}
namespace Filter
{
    void firstOrderHPF(const Mat& scr, Mat& dst);
    void secondOrderHPF(const Mat& scr, Mat& dst);
    void firstOrderLPF(const Mat& scr, Mat& dst);
    void secondOrderLPF(const Mat& scr, Mat& dst);
    void GaussFilter(const Mat& scr, Mat& dst);
    void medianFilter(const Mat& scr, Mat& dst);
}
namespace Edge
{
    void zerox(const Mat& scr, Mat& dst);
    void findEdges(const Mat& scr, Mat& dst);
    void LoG(const Mat& scr, Mat& dst);
}
namespace FFT
{
    using std::complex;
    using std::vector;

    typedef complex<float> FComplex;
    typedef vector<float> FArray;
    typedef vector<FComplex> ComArray;
    typedef vector<ComArray> ComImg;

    const double PI = 3.1415926535898;
    inline void swap(FComplex &a, FComplex &b);
    void transpose(ComImg& array_two_dim);
    void initComImg(ComImg& comImg, const int cols, const int rows);
    ComArray FFT(const ComArray& a);
    void ImgFFT(const Mat& scr, Mat& dst_re, Mat& dst_im);
    void ImgFFT(const Mat& scr, Mat& comDst);
    void ImgIFFT(const Mat& scr_re, const Mat& scr_im, Mat& dst);
    void ImgIFFT(const Mat& comScr, Mat& dst);
    void MatToComImg(const Mat& scr, ComImg& img, bool ifConjugant);
    void MatToComImg(const Mat& scr_re, const Mat& scr_im, ComImg& img);
    void ComImgToMat(const ComImg& scr, Mat& dst_re, Mat& dst_im, bool ifConjugate);
    void ComImgToMat(const ComImg& scr, Mat& dst_re);
    void ComImgToComMat(const ComImg& scr, Mat& comDst, bool ifConjugant);
    void transpose(const ComImg& scr, ComImg& dst);
    FComplex conjugant(const FComplex c);
}
namespace TemplateMatch
{
    enum MatchMode
    {
        ABS, CROSS_CORRELATION
    };

    Point templateMatch(const Mat& scr, const Mat& templ, MatchMode mode, bool ifEdge);
    void templateMatch(const Mat& scr, const Mat& templ, PointArray& arr,
         MatchMode mode, bool ifEdge, int quality, float percent);
    int getQuality(const Mat& m, const Point p, bool ifMax);
    void getAccumulator(const Mat& scr, const Mat& templ,
                                       Mat& accumulator, MatchMode mode);
    Point templateMatch_FFT(const Mat& scr, const Mat& templ);
}

float max(const float A[], int len);
float min(const float A[], int len);
float findMax(const Mat& m);
float findMin(const Mat& m);
Point findMaxPoint(const Mat& m);
Point findMinPoint(const Mat& m);
void findMaximumPoint(const Mat& m, PointArray& arr);
void findMinimumPoint(const Mat& m, PointArray& arr);
float getDistanceSquare(const Point& p1, const Point& p2);
float getMedianValue(const Mat& scr);
#endif // PROCESSFUNCTION

