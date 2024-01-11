#pragma once

#include <gtk/gtk.h>
#include <iostream>
#include <opencv2/opencv.hpp>

class ImageLoader {
public:
    virtual bool load(const std::string& filePath) = 0;
    virtual ~ImageLoader() {}
};

class GUI : public ImageLoader {
public:
    void run();
    bool load(const std::string& filePath) override;
    bool isImageLoaded() const;
    std::string getLoadedFilePath() const;
    std::string exportLoadedFilePath();
    cv::Mat getImage(const std::string& loadedFilePath) const;

private:
    static void file_selected(GtkFileChooserButton *filechooserbutton, gpointer user_data);
    bool imageLoadedSuccessfully = false;
    std::string loadedFilePath; 
    std::string exportFilePath;
};





