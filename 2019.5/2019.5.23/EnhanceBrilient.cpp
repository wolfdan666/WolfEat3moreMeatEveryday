Mat EnhanceBrightness(Mat& I, float dx)
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

    Mat maskMat;

    Mat hsvChannels[3];
    cvtColor(rgbMat, hsvMat, CV_RGB2HSV);
    split(hsvMat, hsvChannels);
    for (int i = 0; i < 3; i++) {
        hsvChannels[i].convertTo(hsvChannels[i], CV_64FC1, 1.0 / 255);
    }
    vMat = hsvChannels[2];

    maskMat = vMat > dx;
    Mat erodeElement = getStructuringElement(MORPH_RECT, Size(5, 5));
    erode(maskMat, maskMat, erodeElement);
    Mat dilateElement = getStructuringElement(MORPH_RECT, Size(5, 5));
    dilate(maskMat, maskMat, dilateElement);
    maskMat = 1 - maskMat;
    maskMat.convertTo(maskMat, CV_64FC1);
    Mat refinedMaskMat = guidefilter(vMat, maskMat, r, 0.000001);

    Mat vGuideMat = guidefilter(vMat, vMat, r / 2, 0.001);
    Mat vRecoverMat = vMat / (vGuideMat + 0.3);
    Mat rgbRecoverMat;
    Mat hsvRecoverMat;
    hsvChannels[2] = vRecoverMat;
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
    return outputMat;
}