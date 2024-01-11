#pragma once
#include <opencv2/opencv.hpp>

class Filter_Interface {
public:
virtual void applyFilter(const cv::Mat& inputImage, int kernelSize, cv::Mat* filteredImage) {};
    virtual void applyFilter(const cv::Mat& inputImage, double Gaussian_sigma_low, double Gaussian_sigma_high, int kernelSize, cv::Mat* filteredImage) {};
    virtual void applyFilter(const cv::Mat& inputImage, cv::Mat* filteredImage) {};
    virtual void applyFilter(const cv::Mat& inputImage, int threshold_low, int threshold_high, int kernelSize, cv::Mat* filteredImage) {};
    virtual ~Filter_Interface() {}
};

class GaussianFilter : public Filter_Interface {
public:
    void applyFilter(const cv::Mat& inputImage, int kernelSize, cv::Mat* filteredImage) override;

private:
    void displayFilteredResult(const cv::Mat& inputImage, const cv::Mat& filteredImage, const std::string& windowName);
};

class LowPassFilter : public Filter_Interface {
public:
    void applyFilter(const cv::Mat& inputImage, int kernelSize, cv::Mat* filteredImage) override;

private:
    void displayFilteredResult(const cv::Mat& inputImage, const cv::Mat& filteredImage, const std::string& windowName);
};

class HighPassFilter : public Filter_Interface {
public:
    void applyFilter(const cv::Mat& inputImage, int kernelSize, cv::Mat* filteredImage) override;

private:
    void displayFilteredResult(const cv::Mat& inputImage, const cv::Mat& filteredImage, const std::string& windowName);
};

class BandPassFilter : public Filter_Interface {
public:
    void applyFilter(const cv::Mat& inputImage, double Gaussian_sigma_low, double Gaussian_sigma_high, int kernelSize, cv::Mat* filteredImage) override;

private:
    void displayFilteredResult(const cv::Mat& inputImage, const cv::Mat& filteredImage, const std::string& windowName);
};

class LaplaceFilter : public Filter_Interface {
public:
    void applyFilter(const cv::Mat& inputImage, cv::Mat* filteredImage) override;

private:
    void displayFilteredResult(const cv::Mat& inputImage, const cv::Mat& filteredImage, const std::string& windowName);
};

class RemoveNoise : public Filter_Interface {
public:
    void applyFilter(const cv::Mat& inputImage, int kernelSize, cv::Mat* filteredImage) override;

private:
    void displayFilteredResult(const cv::Mat& inputImage, const cv::Mat& filteredImage, const std::string& windowName);
};

class EdgeDetection : public Filter_Interface {
public:
    void applyFilter(const cv::Mat& inputImage, int threshold_low, int threshold_high, int kernelSize, cv::Mat* filteredImage) override;

private:
    void displayFilteredResult(const cv::Mat& inputImage, const cv::Mat& filteredImage, const std::string& windowName);
};

class SharpenImage : public Filter_Interface {
public:
    void applyFilter(const cv::Mat& inputImage, int kernelSize, cv::Mat* filteredImage) override;

private:
    void displayFilteredResult(const cv::Mat& inputImage, const cv::Mat& filteredImage, const std::string& windowName);
};

