Mat Mix(Mat& I, float dx, float t2, float t3)
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
    Mat vMat, sMat;
    Mat maskMat;
    Mat hsvChannels[3];
    cvtColor(rgbMat, hsvMat, CV_RGB2HSV);
    split(hsvMat, hsvChannels);
    for (int i = 0; i < 3; i++) {
        hsvChannels[i].convertTo(hsvChannels[i], CV_64FC1, 1.0 / 255);
    }
    // 暗光增强和细节增强都用的v通道
    // 一开始
    vMat = hsvChannels[2];

    // 关于色彩增强的地方
    sMat = hsvChannels[1];
    // SLV,色彩增强是在 L 通道进行的
    // V通道进行的是  纹理增强和暗光增强
    // 全部1都为原图
    // 这个for是
    if (!(abs(t2 - 1) < 1e-6)) { // t2 不等于 1 才进行操作
        for (int i = 0; i < sMat.rows; i++) {
            for (int j = 0; j < sMat.cols; j++) {
                //0.7-1(原图）色彩：0.75-1
                sMat.at<double>(i, j) = pow(sMat.at<double>(i, j), t2);
            }
        }
    }


    maskMat = vMat > dx;
    Mat erodeElement = getStructuringElement(MORPH_RECT, Size(5, 5));
    erode(maskMat, maskMat, erodeElement);
    Mat dilateElement = getStructuringElement(MORPH_RECT, Size(5, 5));
    dilate(maskMat, maskMat, dilateElement);
    maskMat = 1 - maskMat;
    maskMat.convertTo(maskMat, CV_64FC1);
    Mat refinedMaskMat = guidefilter(Ivnew, maskMat, r, 0.000001);

    Mat vGuideMat = guidefilter(Ivnew, Ivnew, r / 2, 0.001);
    Mat vRecoverMat = Ivnew / (vGuideMat + 0.3);
    Mat rgbRecoverMat;
    Mat hsvRecoverMat;
    hsvChannels[2] = vRecoverMat;
    hsvChannels[1] = sMat;

    for (int i = 0; i < 3; i++) {
        hsvChannels[i].convertTo(hsvChannels[i], CV_8UC1, 255);
    }
    merge(hsvChannels, 3, hsvRecoverMat);
    cvtColor(hsvRecoverMat, rgbRecoverMat, CV_HSV2RGB);

    rgbMat.convertTo(rgbMat, CV_64FC1, 1.0 / 255);
    rgbRecoverMat.convertTo(rgbRecoverMat, CV_64FC1, 1.0 / 255);
    Mat refinedMaskChannels[3];
    for (int i = 0; i < 3; i++) {
        refinedMaskChannels[i] = refinedMaskMat;
    }
    Mat refinedMat;
    merge(refinedMaskChannels, 3, refinedMat);
    Mat outputMat;
    subtract(1, refinedMat, outputMat);
    outputMat = rgbMat.mul(outputMat) + rgbRecoverMat.mul(refinedMat);
    // return outputMat;
    // 好了，上面是色彩增强和暗光增强的code

    // 纹理：1.3-2.3
    rgbMat = outputMat;
    Mat hsvMat2;
    Mat vMat2;

    Mat hsvChannels2[3];
    cvtColor(rgbMat,hsvMat2,CV_RGB2HSV);
    split(hsvMat2,hsvChannels2);
    // 已经是(0到1)了，所以不用除以255操作了
    vMat2 = hsvChannels2[2];

// 导向滤波第四个参数不太懂，但是一般取的都是0.01，老谢这里取得0.3,我待会再改一下试试
// 应该就是精度
    Mat basic = guidefilter(vMat, vMat, r, 0.3);
    Mat detail = vMat - basic;
    Mat Ivnew;
    Ivnew.create(detail.size(), CV_64FC1);

    // 自己实现saturate_cast
    // Mat Ivnew = basic + t3 * detail ;
    for (int i = 0; i < detail.rows; i++) {
        for (int j = 0; j < detail.cols; j++) {
            double temp = basic.at<double>(i, j) + t3 * detail.at<double>(i, j);
            if (temp < 0)
                temp = 0;
            else if (temp > 1)
                temp = 1;
            Ivnew.at<double>(i, j) = temp;
        }
    }
    Mat rgbRecoverMat2;
    Mat hsvRecoverMat2;
    hsvChannels2[2] = Ivnew;
    merge(hsvChannels2,3,hsvRecoverMat2);
    cvtColor(hsvRecoverMat2,rgbRecoverMat2,CV_HSV2RGB);

    return rgbRecoverMat2;
}