#include <opencv2/opencv.hpp>


bool ReadImage (std::string & img_path, cv::Mat * img);

void applyGaussianFilter(const cv::Mat & inputImage, const int kernelSize, cv::Mat * filteredImage);

void applyLowPassFilter(const cv::Mat & inputImage, const int kernelSize, cv::Mat* filteredImage);

void applyHighPassFilter(const cv::Mat & inputImage, const int kernelSize, cv::Mat* filteredImage);

void applyBandPassFilter(const cv::Mat & inputImage, double Gaussian_sigma_low, double Gaussian_sigma_high, int kernelSize, cv::Mat* filteredImage);

void applyLaplaceFilter(const cv::Mat & inputImage,  cv::Mat* filteredImage);

void applyRemoveNoise(const cv::Mat& inputImage, const int kernelSize, cv::Mat * filteredImage);

void applyEdgeDetection(const cv::Mat& inputImage, double threshold_low, double threshold_high, const int kernelSize, cv::Mat * filteredImage);

void applySharpenImage(const cv::Mat& inputImage, const int kernelSize, cv::Mat * filteredImage);