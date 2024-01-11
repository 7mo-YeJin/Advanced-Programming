#include <fcn_filters.hpp>

using namespace std;
using namespace cv;

bool ReadImage (string & img_path, Mat * img)
{
try {
    *img = imread(img_path);
    // if ((*img).empty()) {
    //     cerr << "Error: false path!" << endl;
    //     return false;
    // }
        } catch (const std::exception& e) {
        cerr << e.what() << endl;
        return -1;
    }
    return 1;
}

void applyGaussianFilter(const Mat & inputImage,const int kernelSize, Mat * filteredImage) {
    // Gaussian filter
    Size kernel(kernelSize, kernelSize);
    GaussianBlur(inputImage, *filteredImage, Size(kernelSize, kernelSize), 0, 0);

    // Display the original and filtered images in one figure
    Mat fig_combined;
    hconcat(inputImage, *filteredImage, fig_combined);
    imshow("Filtered Image - Gaussian", fig_combined);
    waitKey(0);
    destroyAllWindows();
}

void applyRemoveNoise(const Mat& inputImage, const int kernelSize, Mat * filteredImage) {
    // Medien filter
    medianBlur(inputImage, *filteredImage, kernelSize);

    // Display the original and filtered images in one figure
    Mat fig_combined;
    hconcat(inputImage, *filteredImage, fig_combined);
    imshow("Filtered Image - Remove Noise", fig_combined);
    waitKey(0);
    destroyAllWindows();
}

void applyEdgeDetection(const Mat& inputImage, double threshold_low, double threshold_high, const int kernelSize, Mat * filteredImage) {
    // 使用 Canny 函数进行边缘检测
    Canny(inputImage, *filteredImage, threshold_low, threshold_high, kernelSize);
    
    // Display the original and filtered images in one figure
    Mat inputImageGray;
    Mat fig_combined;
    cvtColor(inputImage, inputImageGray, COLOR_BGR2GRAY);
    hconcat(inputImageGray, *filteredImage, fig_combined);
    imshow("Filtered Image - EdgeDetection", fig_combined);
    waitKey(0);
    destroyAllWindows();
    
}


void applySharpenImage(const Mat& inputImage, const int kernelSize, Mat * filteredImage) {
    // 生成一个方形的 kernel
    Mat kernel = Mat::ones(kernelSize, kernelSize, CV_32F) * (-1);
    kernel.at<float>(kernelSize / 2, kernelSize / 2) = kernelSize * kernelSize;

    // 进行图像锐化
    filter2D(inputImage, *filteredImage, inputImage.depth(), kernel);

    // Display the original and filtered images in one figure
    Mat fig_combined;
    hconcat(inputImage, *filteredImage, fig_combined);
    imshow("Filtered Image - SharpenImage", fig_combined);
    waitKey(0);
    destroyAllWindows();
}


void applyLowPassFilter(const Mat & inputImage, const int kernelSize, Mat* filteredImage) {
    // Kernel of low-pass average filter
    Mat kernel = Mat::ones(kernelSize, kernelSize, CV_32F) / (float)(kernelSize * kernelSize);

    // convolution
    filter2D(inputImage, *filteredImage, -1, kernel);

    // Display the original and filtered images in one figure
    Mat fig_combined;
    hconcat(inputImage, *filteredImage, fig_combined);
    imshow("Filtered Image - Low Pass", fig_combined);
    waitKey(0);
    destroyAllWindows();
}

void applyHighPassFilter(const Mat & inputImage, const int kernelSize, Mat* filteredImage) {
    // Kernel of high-pass average filter 
    Mat kernel = Mat::eye(kernelSize, kernelSize, CV_32F) * -1;
    kernel.at<float>(kernelSize / 2, kernelSize / 2) = kernelSize * kernelSize - 1;

    // convolution
    filter2D(inputImage, *filteredImage, -1, kernel);

    // Display the original and filtered images in one figure
    Mat fig_combined;
    hconcat(inputImage, *filteredImage, fig_combined);
    imshow("Filtered Image - High Pass", fig_combined);
    waitKey(0);
    destroyAllWindows();
}


void applyBandPassFilter(const Mat & inputImage, double Gaussian_sigma_low, double Gaussian_sigma_high, int kernelSize, Mat* filteredImage) {
    // Create (low-pass filter)
    Mat lowPassFiltered;
    GaussianBlur(inputImage, lowPassFiltered, Size(kernelSize, kernelSize), Gaussian_sigma_low);

    // Create (high-pass filter)
    Mat highPassFiltered;
    GaussianBlur(inputImage, highPassFiltered, Size(kernelSize, kernelSize), Gaussian_sigma_high);

    // Band-pass filter
    *filteredImage = highPassFiltered - lowPassFiltered;

    // Display the original and filtered images in one figure
    Mat fig_combined;
    hconcat(inputImage, *filteredImage, fig_combined);
    imshow("Filtered Image - Bandpass", fig_combined);
    waitKey(0);
    destroyAllWindows();
}

void applyLaplaceFilter(const Mat & inputImage,  Mat* filteredImage) {
    
    Laplacian(inputImage, * filteredImage, CV_16S);
    
    Mat laplaceResult;
    filteredImage->convertTo(laplaceResult, CV_8U);

    Mat fig_combined;
    hconcat(inputImage, laplaceResult, fig_combined);
    imshow("Filtered Image - Laplace Filter", fig_combined);
    waitKey(0);
    destroyAllWindows();
}

