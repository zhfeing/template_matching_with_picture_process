#include "pictureprcess.h"

float max(const float A[], int len)
{
    const float *end = A + len;
    float max = A[0];
    for(float const *p = A; p < end; p++)
    {
        if(*p > max)
            max = *p;
    }
    return max;
}

float min(const float A[], int len)
{
    const float *end = A + len;
    float min = A[0];
    for(float const *p = A; p < end; p++)
    {
        if(*p < min)
            min = *p;
    }
    return min;
}

float findMax(const Mat& m)
{
    assert(m.type() == CV_32F);
    MatConstIterator_<float> it, end;
    float max = m.at<float>(0, 0);
    for(it = m.begin<float>(), end = m.end<float>(); it != end; it++)
    {
        if(*it > max)
            max = *it;
    }
    return max;
}

float findMin(const Mat& m)
{
    assert(m.type() == CV_32F);
    MatConstIterator_<float> it, end;
    float min = m.at<float>(0, 0);
    for(it = m.begin<float>(), end = m.end<float>(); it != end; it++)
    {
        if(*it < min)
            min = *it;
    }
    return min;
}

Point findMaxPoint(const Mat& m)
{
    assert(m.type() == CV_32F);
    float max = m.at<float>(0, 0);
    int x, y;
    x = 0;
    y = 0;
    for(int i = 0; i < m.cols; i++)
    {
        for(int j = 0; j < m.rows; j++)
        {
            if(max < m.at<float>(j, i))
            {
                max = m.at<float>(j, i);
                x = i;
                y = j;
            }
        }
    }
    return Point(x, y);
}

Point findMinPoint(const Mat& m)
{
    assert(m.type() == CV_32F);
    float min = m.at<float>(0, 0);
    int x, y;
    x = 0;
    y = 0;
    for(int i = 0; i < m.cols; i++)
    {
        for(int j = 0; j < m.rows; j++)
        {
            if(min > m.at<float>(j, i))
            {
                min = m.at<float>(j, i);
                x = i;
                y = j;
            }
        }
    }
    return Point(x, y);
}

void findMaximumPoint(const Mat& m, PointArray& arr)
{
    assert(m.type() == CV_32F);
    Mat temp;
    for(int i = 1; i < m.rows - 1; i++)
    {
        for(int j = 1; j < m.cols - 1; j++)
        {
            temp = Mat(m, Rect(j - 1, i - 1, 3, 3));
            if(findMax(temp - m.at<float>(i, j)) <= 0)//is the maxium
            {
                arr.push_back(Point(j, i));
            }
        }
    }
}

void findMinimumPoint(const Mat& m, PointArray& arr)
{
    assert(m.type() == CV_32F);
    Mat temp;
    for(int i = 1; i < m.rows - 1; i++)
    {
        for(int j = 1; j < m.cols - 1; j++)
        {
            temp = Mat(m, Rect(j - 1, i - 1, 3, 3));
            if(findMin(temp - m.at<float>(i, j)) >= 0)//is the minium
            {
                arr.push_back(Point(j, i));
            }
        }
    }
}

float getDistanceSquare(const Point& p1, const Point& p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

float getMedianValue(const Mat& scr)
{
    assert(scr.type() == CV_32F);
    Mat Scr;
    scr.copyTo(Scr);
    const int total = scr.cols*scr.rows;
    float *data = (float*)Scr.data;
    std::sort(data, data + total);
    return data[total/2];
}

void Cauculator::applyCauculator(const Mat& scr, const Mat& cauculator,
                                 Mat& dst, bool ifAbs, bool ifEdgeSetToZero = true)
{
    dst = Mat::zeros(scr.size(), CV_32F);
    int col = scr.cols;
    int row = scr.rows;
    int colT = cauculator.cols;
    int rowT = cauculator.rows;
    //center of the template
    int cx = colT/2;
    int cy = rowT/2;
    if(ifEdgeSetToZero)
    {
        for(int i = cx; i < col - cx; i++)
        {
            for(int j = cy; j < row - cy; j++)
            {
                Mat temp = Mat(scr, Rect(i - cx, j - cy, colT, rowT));
                dst.at<float>(j, i) =
                        cv::sum(temp.mul(cauculator))[0];
            }
        }
    }
    else
    {
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                for(int it = 0; it < rowT; it++)
                {
                    for(int jt = 0; jt <colT; jt++)
                    {
                        if(i - cy + it < 0 || j - cx + jt < 0 ||
                                i - cy + it >= row || j - cx + jt >= col)
                            break;
                        dst.at<float>(i, j) += scr.at<float>(i - cy + it, j - cx + jt)*
                                cauculator.at<float>(it, jt);
                    }
                }
            }
        }
    }
    if(ifAbs)
        dst = cv::abs(dst);

}

void Cauculator::LoGTemplate(Mat& t, int size, float segma)
{
    t.create(size, size, CV_32F);
    int cx = (size - 1)/2;
    int cy = (size - 1)/2;
    for(int x = 0; x < size; x++)
    {
        for(int y = 0; y < size; y++)
        {
            int nx = x - cx;
            int ny = y - cy;
            float temp = (nx*nx + ny*ny)/segma/segma;
            t.at<float>(y, x) = std::exp(-temp/2.0)*(temp - 2)/segma/segma;
        }
    }
}

void Filter::firstOrderHPF(const Mat& scr, Mat& dst)
{
    assert(scr.type() == CV_32F);
    Cauculator::applyCauculator(scr, Cauculator::FirstOrderHPF, dst, false, true);
}

void Filter::secondOrderHPF(const Mat& scr, Mat& dst)
{
    assert(scr.type() == CV_32F);
    Cauculator::applyCauculator(scr, Cauculator::SecondOrderHPF, dst, false, true);
}

void Filter::firstOrderLPF(const Mat& scr, Mat& dst)
{
    assert(scr.type() == CV_32F);
    Cauculator::applyCauculator(scr, Cauculator::FirstOrderLPF, dst, false, false);
}

void Filter::secondOrderLPF(const Mat& scr, Mat& dst)
{
    assert(scr.type() == CV_32F);
    Cauculator::applyCauculator(scr, Cauculator::SecondOrderLPF, dst, false, false);
}

void Filter::GaussFilter(const Mat& scr, Mat& dst)
{
    assert(scr.type() == CV_32F);
    Cauculator::applyCauculator(scr, Cauculator::GaussFilter, dst, false, false);
}

void Filter::medianFilter(const Mat& scr, Mat& dst)
{
    assert(scr.type() == CV_32F);
    dst = Mat::zeros(scr.size(), CV_32F);
    int col = scr.cols;
    int row = scr.rows;
    for(int i = 1; i < col - 1; i++)
    {
        for(int j = 1; j < row - 1; j++)
        {
            Mat temp = Mat(scr, Rect(i - 1, j - 1, 3, 3));
            dst.at<float>(j, i) = getMedianValue(temp);
        }
    }
}

void Edge::zerox(const Mat& scr, Mat& dst)
{
    assert(scr.type() == CV_32F);
    dst = Mat::zeros(scr.size(), CV_32F);
    for(int x = 1; x < scr.cols - 1; x++)
    {
        for(int y = 0; y < scr.rows - 1; y++)
        {
            float record[4] = {0};
            for(int i = x - 1; i <= x; i++)
                for(int j = y - 1; j <= y; j++)
                {
                    record[0] += scr.at<float>(j, i);
                }
            for(int i = x - 1; i <= x; i++)
                for(int j = y; j <= y + 1; j++)
                {
                    record[1] += scr.at<float>(j, i);
                }
            for(int i = x; i <= x + 1; i++)
                for(int j = y - 1; j <= y; j++)
                {
                    record[2] += scr.at<float>(j, i);
                }
            for(int i = x; i <= x + 1; i++)
                for(int j = y; j <= y + 1; j++)
                {
                    record[3] += scr.at<float>(j, i);
                }
            float maxR = max(record, 4);
            float minR = min(record, 4);
            const float threshold = 0;
            if(maxR > threshold && minR < -threshold)//is zeor point
                dst.at<float>(y, x) = 10;
            else
                dst.at<float>(y, x) = 0;
        }
    }
}

void Edge::findEdges(const Mat& scr, Mat& dst)
{
    Mat temp;
    LoG(scr, temp);
    zerox(temp, dst);
}

void Edge::LoG(const Mat& scr, Mat& dst)
{
    Mat GaussT;
    const int size = 5;
    const float segma = 0.866;
    Cauculator::LoGTemplate(GaussT, size, segma);
    Cauculator::applyCauculator(scr, GaussT, dst, false, true);
}

Point TemplateMatch::templateMatch(const Mat& scr, const Mat& templ,
                                   TemplateMatch::MatchMode mode, bool ifEdge)
{
    int col = scr.cols;
    int row = scr.rows;
    int colT = templ.cols;
    int rowT = templ.rows;
    //center of the template
    int cx = floor(colT/2) + 1;
    int cy = floor(rowT/2) + 1;
    Mat Scr, Templ;
    if(ifEdge)
    {
        Edge::findEdges(scr, Scr);
        Edge::findEdges(templ, Templ);
    }
    else
    {
        scr.convertTo(Scr, CV_32F);
        templ.convertTo(Templ, CV_32F);
    }

    //accumulator
    Mat accumulator;
    getAccumulator(Scr, Templ, accumulator, mode);

    Point bestPoint;
    switch (mode)
    {
    case ABS:
        bestPoint = findMinPoint(Mat(accumulator,
                                     Rect(cx, cy,
                                          col - 2*cx - 1,
                                          row - 2*cy - 1))) +
                                          Point(cx, cy);
        break;
    case CROSS_CORRELATION:
        bestPoint = findMaxPoint(Mat(accumulator,
                                     Rect(cx, cy,
                                          col - 2*cx - 1,
                                          row - 2*cy - 1))) +
                                          Point(cx, cy);
    default:
        break;
    }
    return bestPoint;
}

void TemplateMatch::templateMatch(const Mat& scr, const Mat& templ, PointArray& arr,
                   MatchMode mode, bool ifEdge, int quality, float percent)
{
    if(percent > 1) //assure that can find some point
        percent = 0.99;
    int col = scr.cols;
    int row = scr.rows;
    int colT = templ.cols;
    int rowT = templ.rows;
    //center of the template
    int cx = floor(colT/2) + 1;
    int cy = floor(rowT/2) + 1;
    Mat Scr, Templ;
    if(ifEdge)
    {
        Edge::findEdges(scr, Scr);
        Edge::findEdges(templ, Templ);
    }
    else
    {
        scr.convertTo(Scr, CV_32F);
        templ.convertTo(Templ, CV_32F);
    }

    //accumulator
    Mat accumulator;
    getAccumulator(Scr, Templ, accumulator, mode);

    PointArray pointarr;
    Point bestPoint;
    switch (mode)
    {
    case ABS:
    {
        bestPoint = findMinPoint(Mat(accumulator,
                                     Rect(cx, cy,
                                          col - 2*cx - 1,
                                          row - 2*cy - 1))) +
                                          Point(cx, cy);
        findMinimumPoint(Mat(accumulator,
                             Rect(cx, cy, col - 2*cx - 1,
                             row - 2*cy - 1)), pointarr);
        for(unsigned i = 0; i < pointarr.size(); i++)
        {
            pointarr[i] += Point(cx, cy);
        }
        float minValueThreshold = accumulator.at<float>(bestPoint)/percent;
        for(unsigned i = 0; i < pointarr.size(); i++)
        {
            //judge that mininum point is useful
            if(accumulator.at<float>(pointarr[i]) < minValueThreshold)
            {
                if(getQuality(accumulator, pointarr[i], false) <= quality)
                {
                    arr.push_back(pointarr[i]);
                }
            }
        }
    }
        break;
    case CROSS_CORRELATION:
    {
        bestPoint = findMaxPoint(Mat(accumulator,
                                     Rect(cx, cy,
                                          col - 2*cx - 1,
                                          row - 2*cy - 1))) +
                                          Point(cx, cy);
        cout<<getQuality(accumulator, bestPoint, true)<<endl;
        findMaximumPoint(Mat(accumulator,
                             Rect(cx, cy, col - 2*cx - 1,
                             row - 2*cy - 1)), pointarr);
        for(unsigned i = 0; i < pointarr.size(); i++)
        {
            pointarr[i] += Point(cx, cy);
        }
        float maxValueThreshold = accumulator.at<float>(bestPoint)*percent;
        for(unsigned i = 0; i < pointarr.size(); i++)
        {
            //judge that maxinum point is useful
            if(accumulator.at<float>(pointarr[i]) > maxValueThreshold)
            {
                if(getQuality(accumulator, pointarr[i], true) <= quality)
                {
                    arr.push_back(pointarr[i]);
                }
            }
        }
    }
        break;
    default:
        cout<<"wrong Mode"<<endl;
        abort();
        break;
    }
//    Mat A;
//    accumulator /= findMax(accumulator);
//    accumulator *= 255;
//    cv::namedWindow("hhhh", CV_NORMAL);
//    accumulator.convertTo(A, CV_8U);
//    cv::imshow("hhhh", A);
}

void TemplateMatch::getAccumulator(const Mat& scr, const Mat& templ,
                                   Mat& accumulator, MatchMode mode)
{
    assert(scr.type() == CV_32F && templ.type() == CV_32F);
    int col = scr.cols;
    int row = scr.rows;
    int colT = templ.cols;
    int rowT = templ.rows;
    //center of the template
    int cx = floor(colT/2) + 1;
    int cy = floor(rowT/2) + 1;
    accumulator = Mat::zeros(scr.size(), CV_32F);
    switch(mode)
    {
    case ABS:
    {
       for(int i = cx; i < col - cx; i++)
       {
           for(int j = cy; j < row - cy; j++)
           {
               Mat temp = Mat(scr, Rect(i - cx, j - cy, colT, rowT));
               accumulator.at<float>(j, i) =
                       cv::sum(cv::abs(templ - temp))[0];
           }
       }
    }
       break;
    case CROSS_CORRELATION:
    {
       for(int i = cx; i < col - cx; i++)
       {
           for(int j = cy; j < row - cy; j++)
           {
               const Mat temp = Mat(scr, Rect(i - cx, j - cy, colT, rowT));
               float tempAverage = cv::sum(temp)[0]/colT/rowT;
               float TemplAverage = cv::sum(templ)[0]/colT/rowT;
               accumulator.at<float>(j, i) =
                       cv::sum((temp - tempAverage).
                               mul(templ - TemplAverage))[0];
           }
       }
    }
       break;
    default:
       cout<<"wrong mode"<<endl;
       abort();
    }
}

Point TemplateMatch::templateMatch_FFT(const Mat& scr, const Mat& templ)
{
    assert(scr.type() == CV_32F && templ.type() == CV_32F);
    assert(templ.cols <= scr.cols && templ.rows <= scr.rows);
    using FFT::FComplex;
    Mat Templ, sub;
    Templ = Mat::zeros(scr.size(), CV_32F);
    sub = Mat(Templ, Rect(0, 0, templ.cols, templ.rows));
    templ.copyTo(sub);

    Mat scr_edge, templ_edge;
    Edge::findEdges(scr, scr_edge);
    Edge::findEdges(Templ, templ_edge);

    Mat scr_com, templ_com, conv_com;
    conv_com.create(scr.size(), CV_32FC(2));
    FFT::ImgFFT(scr_edge, scr_com);
    FFT::ImgFFT(templ_edge, templ_com);

    MatIterator_<FComplex> scr_com_it, templ_com_it, conv_com_it;
    const MatIterator_<FComplex> scr_com_end = scr_com.end<FComplex>();
    scr_com_it = scr_com.begin<FComplex>();
    templ_com_it = templ_com.begin<FComplex>();
    conv_com_it = conv_com.begin<FComplex>();
    for(; scr_com_it != scr_com_end; scr_com_it++, templ_com_it++, conv_com_it++)
    {
        *conv_com_it = (*scr_com_it)*FFT::conjugant(*templ_com_it);
    }
    Mat accumulator;
    FFT::ImgIFFT(conv_com, accumulator);

    return findMaxPoint(accumulator);
}

int TemplateMatch::getQuality(const Mat& m, const Point p, bool ifMax)
{
    assert(m.type() == CV_32F);
    int col = m.cols;
    int row = m.rows;
    int x = p.x;
    int y = p.y;
    int accumulator[4] = {-1, -1, -1, -1};//accumulate in four domins
    if(ifMax)
    {
        float pValueThreshold = m.at<float>(p)*0.707;
        //search from this point to the left
        for(int i = x - 1; i >= 0; i--)
        {
            if(m.at<float>(y, i) < pValueThreshold)
            {
                accumulator[0] = i;
                break;
            }
        }
        if(accumulator[0] == -1)//dose not find one
            accumulator[0] = 0;
        //search from this point to the right
        for(int i = x + 1; i < col; i++)
        {
            if(m.at<float>(y, i) < pValueThreshold)
            {
                accumulator[1] = i;
                break;
            }
        }
        if(accumulator[1] == -1)//dose not find one
            accumulator[1] = col;

        //search from this point to the top
        for(int i = y - 1; i >= 0; i--)
        {
            if(m.at<float>(i, x) < pValueThreshold)
            {
                accumulator[2] = i;
                break;
            }
        }
        if(accumulator[2] == -1)//dose not find one
            accumulator[2] = 0;
        //search from this point to the bottom
        for(int i = y + 1; i < row; i++)
        {
            if(m.at<float>(i, x) < pValueThreshold)
            {
                accumulator[3] = i;
                break;
            }
        }
        if(accumulator[3] == -1)//dose not find one
            accumulator[3] = row;
        return (accumulator[1] - accumulator[0] +
                accumulator[3] - accumulator[2])/2;
    }
    else
    {
        float pValueThreshold = m.at<float>(p)/0.707;
        //search from this point to the left
        for(int i = x - 1; i >= 0; i--)
        {
            if(m.at<float>(y, i) > pValueThreshold)
            {
                accumulator[0] = i;
                break;
            }
        }
        if(accumulator[0] == -1)//dose not find one
            accumulator[0] = 0;
        //search from this point to the right
        for(int i = x + 1; i < col; i++)
        {
            if(m.at<float>(y, i) > pValueThreshold)
            {
                accumulator[1] = i;
                break;
            }
        }
        if(accumulator[1] == -1)//dose not find one
            accumulator[1] = col;

        //search from this point to the top
        for(int i = y - 1; i >= 0; i--)
        {
            if(m.at<float>(i, x) > pValueThreshold)
            {
                accumulator[2] = i;
                break;
            }
        }
        if(accumulator[2] == -1)//dose not find one
            accumulator[2] = 0;
        //search from this point to the bottom
        for(int i = y + 1; i < row; i++)
        {
            if(m.at<float>(i, x) > pValueThreshold)
            {
                accumulator[3] = i;
                break;
            }
        }
        if(accumulator[3] == -1)//dose not find one
            accumulator[3] = row;
        return (accumulator[1] - accumulator[0] +
                accumulator[3] - accumulator[2])/2;
    }
}


//for the transpose
inline void FFT::swap(FComplex &a, FComplex &b)
{
    FComplex temp = b;
    b = a;
    a = temp;
}

//transpose the matrix
void FFT::transpose(ComImg& array_two_dim)
{
    assert(array_two_dim.size() == array_two_dim[0].size());
    const int n = array_two_dim.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(array_two_dim[i][j], array_two_dim[j][i]);
}

//resize array with two dimension
void FFT::initComImg(ComImg& comImg, const int cols, const int rows)
{
    comImg.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        comImg[i].resize(cols);
    }
}

//fft algorithm
FFT::ComArray FFT::FFT(const ComArray& a)
{
    int n = a.size();
    if (1 == n)		//base case
        return a;
    assert(n % 2 == 0);
    FComplex Wn(cos(2 * PI / n), -sin(2 * PI / n));
    FComplex W0(1, 0);
    ComArray a0(n / 2), a1(n / 2);
    for (int i = 0; i < n / 2; i++)
        a0[i] = a[2 * i];
    for (int i = 0; i < n / 2; i++)
        a1[i] = a[2 * i + 1];

    ComArray y0 = FFT(a0);
    ComArray y1 = FFT(a1);
    ComArray y(n);
    for (int k = 0; k < n / 2; k++)
    {
        y[k] = y0[k] + W0*y1[k];
        y[k + n / 2] = y0[k] - W0*y1[k];
        W0 *= Wn;
    }
    return y;
}

//only for cols and rows are a power of 2
void FFT::ImgFFT(const Mat& scr, Mat& dst_re, Mat& dst_im)
{
    assert(scr.type() == CV_32F);
    const int cols = scr.cols;
    const int rows = scr.rows;
    ComImg fft_out,picture, temp;

    MatToComImg(scr, picture, false);
    initComImg(fft_out, cols, rows);
    for (int i = 0; i < rows; i++)//row fft
    {
        fft_out[i] = FFT(picture[i]);
    }
    transpose(fft_out, temp);
    for (int i = 0; i < cols; i++)//row fft
    {
        temp[i] = FFT(temp[i]);
    }
    transpose(temp, fft_out);
    ComImgToMat(fft_out, dst_re, dst_im, false);
}

void FFT::ImgFFT(const Mat& scr, Mat& comDst)
{
    assert(scr.type() == CV_32F);
    const int cols = scr.cols;
    const int rows = scr.rows;
    ComImg fft_out,picture, temp;

    MatToComImg(scr, picture, false);
    initComImg(fft_out, cols, rows);
    for (int i = 0; i < rows; i++)//row fft
    {
        fft_out[i] = FFT(picture[i]);
    }
    transpose(fft_out, temp);
    for (int i = 0; i < cols; i++)//row fft
    {
        temp[i] = FFT(temp[i]);
    }
    transpose(temp, fft_out);
    ComImgToComMat(fft_out, comDst, false);
}

void FFT::ImgIFFT(const Mat& scr_re, const Mat& scr_im, Mat& dst)
{
    assert(scr_re.type() == CV_32F && scr_im.type() == CV_32F);
    assert(scr_re.size() == scr_im.size());
    const int cols = scr_re.cols;
    const int rows = scr_re.rows;
    ComImg fft_out, comPicture, temp;

    MatToComImg(scr_re, -scr_im, comPicture);//the conjugant of the comImg
    initComImg(fft_out, cols, rows);
    for (int i = 0; i < rows; i++)//row fft
    {
        fft_out[i] = FFT(comPicture[i]);
    }
    transpose(fft_out, temp);
    for (int i = 0; i < cols; i++)//row fft
    {
        temp[i] = FFT(temp[i]);
    }
    transpose(temp, fft_out);
    ComImgToMat(fft_out, dst);
    dst /= cols*rows;
}

//only for cols and rows are a power of 2
void FFT::ImgIFFT(const Mat& comScr, Mat& dst)
{
    assert(comScr.type() == CV_32FC(2));
    const int cols = comScr.cols;
    const int rows = comScr.rows;
    ComImg fft_out, comPicture, temp;

    MatToComImg(comScr, comPicture, true);//the conjugant of the comImg
    initComImg(fft_out, cols, rows);
    for (int i = 0; i < rows; i++)//row fft
    {
        fft_out[i] = FFT(comPicture[i]);
    }
    transpose(fft_out, temp);
    for (int i = 0; i < cols; i++)//row fft
    {
        temp[i] = FFT(temp[i]);
    }
    transpose(temp, fft_out);
    ComImgToMat(fft_out, dst);
    dst /= cols*rows;
}

void FFT::MatToComImg(const Mat& scr, ComImg& img, bool ifConjugant = false)
{
    assert(scr.type() == CV_32F || scr.type() == CV_32FC(2));
    const int cols = scr.cols;
    const int rows = scr.rows;

    initComImg(img, cols, rows);
    switch (scr.type())
    {
    case CV_32F:
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                img[i][j] = scr.at<float>(i,j);
            }
        }
        break;
    case CV_32FC(2):
        if(ifConjugant)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    img[i][j] = FComplex(scr.at<FComplex>(i,j).real(),
                                         -scr.at<FComplex>(i,j).imag());
                }
            }
            break;
        }
        else
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    img[i][j] = scr.at<FComplex>(i,j);
                }
            }
            break;
        }
    default:
        break;
    }
}

void FFT::MatToComImg(const Mat& scr_re, const Mat& scr_im, ComImg& img)
{
    assert(scr_re.type() == CV_32F && scr_im.type() == CV_32F);
    const int cols = scr_re.cols;
    const int rows = scr_re.rows;

    initComImg(img, cols, rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            img[i][j] = FComplex(scr_re.at<float>(i, j), scr_im.at<float>(i, j));
        }
    }
}

void FFT::ComImgToMat(const ComImg& scr, Mat& dst_re, Mat& dst_im, bool ifConjugate)
{
    assert(scr.size() > 0);
    const int rows = scr.size();
    const int cols = scr[0].size();

    dst_re.create(rows, cols, CV_32F);
    dst_im.create(rows, cols, CV_32F);

    if(ifConjugate)
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                dst_re.at<float>(i, j) = scr[i][j].real();
                dst_im.at<float>(i, j) = -scr[i][j].imag();
            }
        }
    }
    else
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                dst_re.at<float>(i, j) = scr[i][j].real();
                dst_im.at<float>(i, j) = scr[i][j].imag();
            }
        }
    }
}

void FFT::ComImgToMat(const ComImg& scr, Mat& dst_re)
{
    assert(scr.size() > 0);
    const int rows = scr.size();
    const int cols = scr[0].size();

    dst_re.create(rows, cols, CV_32F);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            dst_re.at<float>(i, j) = scr[i][j].real();
        }
    }
}

void FFT::ComImgToComMat(const ComImg& scr, Mat& comDst, bool ifConjugant)
{
    assert(scr.size() > 0);
    const int rows = scr.size();
    const int cols = scr[0].size();

    comDst.create(rows, cols, CV_32FC(2));

    if(ifConjugant)
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                comDst.at<FComplex>(i, j) = FComplex(scr[i][j].real(), scr[i][j].imag());
            }
        }
    }
    else
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                comDst.at<FComplex>(i, j) = scr[i][j];
            }
        }
    }
}

void FFT::transpose(const ComImg& scr, ComImg& dst)
{
    assert(scr.size() > 0);
    const int rows = scr.size();
    const int cols = scr[0].size();

    initComImg(dst, rows, cols);//the transpose convert rows and cols
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            dst[j][i] = scr[i][j];
        }
    }
}

FFT::FComplex FFT::conjugant(const FComplex c)
{
    return FComplex(c.real(), -c.imag());
}


