#include <fcn_filters.hpp>

using namespace std;
using namespace cv;

#define Gaussian_sigma_low 3.0
#define Gaussian_sigma_high 120.0
#define threshold_low 100
#define threshold_high 200


bool State(string & Img_Path_In, string & Img_Path_Out) {
    
    int filterChoice, kernelSize;
    Mat filteredImage;

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

    printf("%d\n", filterChoice);
         
        // Validate the user's input
    if ((filterChoice < 1 || filterChoice > 8) && filterChoice != 0 ) {
        cerr << "Invalid choice. Exiting.\n";
        exit(EXIT_FAILURE);
    }

    if (filterChoice >=1  && filterChoice <= 8) {    
        cout << "Enter the kernel size for the filter: ";
        cin >> kernelSize;
            if (kernelSize % 2 == 0) {
            throw runtime_error("Error: Even kernel sizes are not allowed. Please enter an odd kernel size.");
            }
    }

    // Apply the selected filter
    try {

    while(filterChoice != 0){  
        Mat image;

        if (ReadImage (Img_Path_In, &image))
        {
            switch (filterChoice)
            {

            case 1:{
                cout << "-----you chosed gaussian filter-----\n";
                applyGaussianFilter(image, kernelSize, &filteredImage);
                imwrite(Img_Path_Out, filteredImage);
                break;
            }

            case 2:{
                cout << "-----you chosed low pass filter-----\n";
                applyLowPassFilter(image, kernelSize, &filteredImage);
                imwrite(Img_Path_Out, filteredImage);
                break;
            }  

            case 3:{
                cout << "-----you chosed high pass filter-----\n";
                applyHighPassFilter(image, kernelSize, &filteredImage);
                imwrite(Img_Path_Out, filteredImage);
                break;
            }  

            case 4:{
                cout << "-----you chosed band pass filter-----\n";
                applyBandPassFilter(image, Gaussian_sigma_low, Gaussian_sigma_high, kernelSize, &filteredImage);
                imwrite(Img_Path_Out, filteredImage);
                break;
            } 

            case 5:{
                cout << "-----you chosed laplace filter-----\n";
                applyLaplaceFilter(image, &filteredImage);
                imwrite(Img_Path_Out, filteredImage);
                break;
            } 

            case 6:{
                cout << "-----you chosed to remove noise-----\n";
                applyRemoveNoise(image, kernelSize, &filteredImage);
                imwrite(Img_Path_Out, filteredImage);
                break;
            } 

            case 7:{
                cout << "-----you chosed edge detection-----\n";
                applyEdgeDetection(image, threshold_low, threshold_high, kernelSize, &filteredImage);
                imwrite(Img_Path_Out, filteredImage);
                break;
            } 

            case 8:{
                cout << "-----you chosed to sharpe image-----\n";
                applySharpenImage(image, kernelSize, &filteredImage);
                imwrite(Img_Path_Out, filteredImage);
                break;
            }                         
            case 0:{
                cout << "Process is Quitting......\n";
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

    //default path
    string Img_Path_In = "./store/Img_In/input_Image.jpg";
    string Img_Path_Out = "./store/Img_Out/filtered_Img.jpg";

    State(Img_Path_In, Img_Path_Out);
    return 0;
}
