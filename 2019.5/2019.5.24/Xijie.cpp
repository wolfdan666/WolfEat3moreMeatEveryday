#include<bits/stdc++.h>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat XiJie(Mat& I, float t1)
{
    int r = I.rows;
    if (I.rows > I.cols) {
        r = I.cols;
    }
    r = r / 10;
    Mat rgbMat = I;
    if (rgbMat.empty()) {
        cout << "read image failed" << endl;
        return rgbMat;
    }
    Mat hsvMat;
    Mat vMat;

    Mat hsvChannels[3];
    cvtColor(rgbMat, hsvMat, CV_RGB2HSV);
    split(hsvMat, hsvChannels);
    for (int i = 0; i < 3; i++) {
        hsvChannels[i].convertTo(hsvChannels[i], CV_64FC1, 1.0 / 255);
    }
    vMat = hsvChannels[2];

    Mat basic = guidefilter(vMat, vMat, r, 0.01);
    Mat detail = vMat - basic;
    Mat Ivnew;
    Ivnew.create(detail.size(), CV_64FC1);
    //    Mat Ivnew = basic +t1*detail;
    //1-2.5
    for (int i = 0; i < detail.rows; i++) {
        for (int j = 0; j < detail.cols; j++) {
            double temp = basic.at<double>(i, j) + t1 * detail.at<double>(i, j);
            if (temp < 0)
                temp = 0;
            else if (temp > 1)
                temp = 1;
            Ivnew.at<double>(i, j) = temp;
        }
    }

    Mat rgbRecoverMat; // rgb 结果
    Mat hsvRecoverMat; // hsv 结果
    hsvChannels[2] = Ivnew;
    for (int i = 0; i < 3; i++) {
        hsvChannels[i].convertTo(hsvChannels[i], CV_8UC1, 255);
    }
    merge(hsvChannels, 3, hsvRecoverMat);
    cvtColor(hsvRecoverMat, rgbRecoverMat, CV_HSV2RGB);

    return rgbRecoverMat;
}