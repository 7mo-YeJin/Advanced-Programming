#include <fcn_filters_interface.hpp>
#include <fcn_ImageLoader_interface.hpp>

using namespace std;
using namespace cv;

#define Gaussian_sigma_low 3.0
#define Gaussian_sigma_high 120.0
#define threshold_low 100
#define threshold_high 200

bool State(string & Img_Path_In, string & Img_Path_Out, bool & isImageLoaded, Mat & inputImage) {
    
    int filterChoice, kernelSize;
    Mat filteredImage;
    std::unique_ptr<Filter_Interface> Ptr_Filter_Interface;

    cout << "Choose a filter to apply:\n"
         << "1. Gaussian Filter\n"
         << "2. Low Pass Filter\n"
         << "3. High Pass Filter\n"
         << "4. Bandpass Filter\n"
         << "5. Laplace Filter\n"
         << "6. Remove  Noise\n"
         << "7. Edge  Detection\n"
         << "8. Sharpen  Image\n"
         << "-------------------"
         << "\nEnter any letter or ctrl+C to quit \n"
         << "Enter your choice (1-8): "
         << endl;
    cin >> filterChoice;
         
    // Validate the user's input
    if ((filterChoice < 1 || filterChoice > 8) && filterChoice != 0 ) {
        cerr << "Invalid choice. Exiting.\n";
        exit(EXIT_FAILURE);
    }

    if (filterChoice >=1  && filterChoice <= 8 && filterChoice != 0) {    
        cout << "Enter the kernel size for the filter: ";
        cin >> kernelSize;
            if (kernelSize % 2 == 0) {
            throw runtime_error("Error: Even kernel sizes are not allowed. Please enter an odd kernel size.");
            }
    }

    // Apply the selected filter
    try {

    while(filterChoice != 0){  

        if (isImageLoaded)
        {
            switch (filterChoice)
            {

            case 0:{
                cout << "Process is Quitting......\n";
                break;
            } 
                 
            case 1:{
                cout << "-----you chosed gaussian filter-----\n";
                Ptr_Filter_Interface = std::make_unique<GaussianFilter>();
                Ptr_Filter_Interface->applyFilter(inputImage, kernelSize, &filteredImage);
                imwrite(Img_Path_Out, filteredImage);
                break;
            }

            case 2:{
                cout << "-----you chosed low pass filter-----\n";
                Ptr_Filter_Interface = std::make_unique<LowPassFilter>();
                Ptr_Filter_Interface->applyFilter(inputImage, kernelSize, &filteredImage);
                imwrite(Img_Path_Out, filteredImage);
                break;
            }  

            case 3:{
                cout << "-----you chosed low pass filter-----\n";
                Ptr_Filter_Interface = std::make_unique<HighPassFilter>();
                Ptr_Filter_Interface->applyFilter(inputImage, kernelSize, &filteredImage);
                imwrite(Img_Path_Out, filteredImage);
                break;
            }  

            case 4:{
                cout << "-----you chosed band pass filter-----\n";
                Ptr_Filter_Interface = std::make_unique<BandPassFilter>();
                Ptr_Filter_Interface->applyFilter(inputImage, Gaussian_sigma_low, Gaussian_sigma_high, kernelSize, &filteredImage);
                imwrite(Img_Path_Out, filteredImage);
                break;
            } 

            case 5:{
                cout << "-----you chosed laplace filter-----\n";
                Ptr_Filter_Interface = std::make_unique<LaplaceFilter>();
                Ptr_Filter_Interface->applyFilter(inputImage, &filteredImage);
                imwrite(Img_Path_Out, filteredImage);
                break;
            } 

            case 6:{
                cout << "-----you chosed to remove noise-----\n";
                Ptr_Filter_Interface = std::make_unique<RemoveNoise>();
                Ptr_Filter_Interface->applyFilter(inputImage, kernelSize, &filteredImage);
                imwrite(Img_Path_Out, filteredImage);
                break;
            } 

            case 7:{
                cout << "-----you chosed edge detection-----\n";
                Ptr_Filter_Interface = std::make_unique<EdgeDetection>();
                Ptr_Filter_Interface->applyFilter(inputImage, threshold_low, threshold_high, kernelSize, &filteredImage);
                imwrite(Img_Path_Out, filteredImage);
                break;
            } 

            case 8:{
                cout << "-----you chosed to sharpe image-----\n";
                Ptr_Filter_Interface = std::make_unique<SharpenImage>();
                Ptr_Filter_Interface->applyFilter(inputImage, kernelSize, &filteredImage);
                imwrite(Img_Path_Out, filteredImage);
                break;
            } 

            default:
                break;
            }

            cout << "continue to choose a filter:\n";
            cin >> filterChoice;
                    // Validate the user's input
                     if ((filterChoice < 1 || filterChoice > 8) && filterChoice != 0) {
                         cerr << "Invalid choice. Exiting.\n";
                         exit(EXIT_FAILURE);;
                    }
            
                if ((filterChoice >=1  && filterChoice <= 8) && filterChoice != 0) {    
                    cout << "Enter the kernel size for the filter: ";
                    cin >> kernelSize;
                        if (kernelSize % 2 == 0) {
                            throw runtime_error("Error: Even kernel sizes are not allowed. Please enter an odd kernel size.");
                        }
                }
        } 
    }    
    
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
        return -1;
    }

    return 0;
}



int main(int argc, char** argv) {

    GUI gui;
    gui.run();
    bool isImageLoaded = gui.isImageLoaded();
    string Img_Path_In = gui.getLoadedFilePath();
    string Img_Path_Out = gui.exportLoadedFilePath();
    Mat inputImage = gui.getImage(Img_Path_In); 
    State(Img_Path_In, Img_Path_Out, isImageLoaded, inputImage);
    return 0;
    
}
