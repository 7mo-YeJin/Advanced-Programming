#include <fcn_filters_interface.hpp>


using namespace std;
using namespace cv;


void GaussianFilter::applyFilter(const Mat& inputImage, int kernelSize, Mat* filteredImage) {
        // Gaussian filter
        Size kernel(kernelSize, kernelSize);
        GaussianBlur(inputImage, *filteredImage, Size(kernelSize, kernelSize), 0, 0);
        displayFilteredResult(inputImage, *filteredImage, "Filtered Image - Gaussian");
    }

void GaussianFilter::displayFilteredResult(const Mat& inputImage, const Mat& filteredImage, const string& windowName) {
        Mat fig_combined;
        hconcat(inputImage, filteredImage, fig_combined);
        imshow(windowName, fig_combined);
        waitKey(0);
        destroyAllWindows();
    }

void LowPassFilter::applyFilter(const Mat& inputImage, int kernelSize, Mat* filteredImage) {
        // Kernel of low-pass average filter
        Mat kernel = Mat::ones(kernelSize, kernelSize, CV_32F) / (float)(kernelSize * kernelSize);

        // convolution
        filter2D(inputImage, *filteredImage, -1, kernel);
        displayFilteredResult(inputImage, *filteredImage, "Filtered Image - Low Pass");
    }

void LowPassFilter::displayFilteredResult(const Mat& inputImage, const Mat& filteredImage, const string& windowName) {
        Mat fig_combined;
        hconcat(inputImage, filteredImage, fig_combined);
        imshow(windowName, fig_combined);
        waitKey(0);
        destroyAllWindows();
    }


void HighPassFilter::applyFilter(const Mat& inputImage, int kernelSize, Mat* filteredImage) {
        // Kernel of high-pass average filter
        Mat kernel = Mat::eye(kernelSize, kernelSize, CV_32F) * -1;
        kernel.at<float>(kernelSize / 2, kernelSize / 2) = kernelSize * kernelSize - 1;

        // convolution
        filter2D(inputImage, *filteredImage, -1, kernel);
        displayFilteredResult(inputImage, *filteredImage, "Filtered Image - High Pass");
    }

void HighPassFilter::displayFilteredResult(const Mat& inputImage, const Mat& filteredImage, const string& windowName) {
        Mat fig_combined;
        hconcat(inputImage, filteredImage, fig_combined);
        imshow(windowName, fig_combined);
        waitKey(0);
        destroyAllWindows();
    }


void BandPassFilter::applyFilter(const Mat& inputImage, double Gaussian_sigma_low, double Gaussian_sigma_high, int kernelSize, Mat* filteredImage) {

        Mat lowPassFiltered, highPassFiltered;

        // Create (low-pass filter)
        cv::GaussianBlur(inputImage, lowPassFiltered, Size(kernelSize, kernelSize), Gaussian_sigma_low);
        
        // Create (high-pass filter)
        cv::GaussianBlur(inputImage, highPassFiltered, Size(kernelSize, kernelSize), Gaussian_sigma_high);

        // Band-pass filter
        *filteredImage = highPassFiltered - lowPassFiltered;

        displayFilteredResult(inputImage, *filteredImage, "Filtered Image - Bandpass");
    }

void BandPassFilter::displayFilteredResult(const Mat& inputImage, const Mat& filteredImage, const string& windowName) {
        Mat fig_combined;
        hconcat(inputImage, filteredImage, fig_combined);
        imshow(windowName, fig_combined);
        waitKey(0);
        destroyAllWindows();
    }


void LaplaceFilter::applyFilter(const Mat& inputImage, Mat* filteredImage) {
        Laplacian(inputImage, *filteredImage, CV_16S);

        Mat laplaceResult;
        filteredImage->convertTo(laplaceResult, CV_8U);

        displayFilteredResult(inputImage, laplaceResult, "Filtered Image - Laplace Filter");
    }


void LaplaceFilter:: displayFilteredResult(const Mat& inputImage, const Mat& filteredImage, const string& windowName) {
        Mat fig_combined;
        hconcat(inputImage, filteredImage, fig_combined);
        imshow(windowName, fig_combined);
        waitKey(0);
        destroyAllWindows();
    }


void RemoveNoise::applyFilter(const Mat& inputImage, int kernelSize, Mat* filteredImage) {
    // Medien filter
    medianBlur(inputImage, *filteredImage, kernelSize);

    displayFilteredResult(inputImage, *filteredImage, "Filtered Image - Remove Noise");
    }

void RemoveNoise::displayFilteredResult(const Mat& inputImage, const Mat& filteredImage, const string& windowName) {
        Mat fig_combined;
        hconcat(inputImage, filteredImage, fig_combined);
        imshow(windowName, fig_combined);
        waitKey(0);
        destroyAllWindows();
    }


void EdgeDetection::applyFilter(const Mat& inputImage, int threshold_low, int threshold_high, int kernelSize, Mat* filteredImage) {
    // 使用 Canny 函数进行边缘检测
    Canny(inputImage, *filteredImage, threshold_low, threshold_high, kernelSize);

    displayFilteredResult(inputImage, *filteredImage, "Filtered Image - Edge Detection");
    }

// TODO
void EdgeDetection::displayFilteredResult(const Mat& inputImage, const Mat& filteredImage, const string& windowName) {
    Mat inputImageGray;
    Mat fig_combined;
    cvtColor(inputImage, inputImageGray, COLOR_BGR2GRAY);
    hconcat(inputImageGray, filteredImage, fig_combined);
    imshow(windowName, fig_combined);
    waitKey(0);
    destroyAllWindows();
    }

void SharpenImage::applyFilter(const Mat& inputImage, int kernelSize, Mat* filteredImage) {
    // 生成一个方形的 kernel
    Mat kernel = Mat::ones(kernelSize, kernelSize, CV_32F) * (-1);
    kernel.at<float>(kernelSize / 2, kernelSize / 2) = kernelSize * kernelSize;

    // 进行图像锐化
    filter2D(inputImage, *filteredImage, inputImage.depth(), kernel);

    displayFilteredResult(inputImage, *filteredImage, "Filtered Image - Sharpen Image");
    }

void SharpenImage::displayFilteredResult(const Mat& inputImage, const Mat& filteredImage, const string& windowName) {
        Mat fig_combined;
        hconcat(inputImage, filteredImage, fig_combined);
        imshow(windowName, fig_combined);
        waitKey(0);
        destroyAllWindows();
    }



