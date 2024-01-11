// #include <gtk/gtk.h>
// #include <iostream>
// #include <opencv2/opencv.hpp>
#include <fcn_ImageLoader_interface.hpp>

using namespace std;
using namespace cv;

void GUI::run() {
        gtk_init(NULL, NULL);

        //Create the main window
        GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(window), "Image Loader Interface");
        gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
        // gtk_container_set_border_width(GTK_CONTAINER(window), 10);

        //Create table
        GtkWidget *table = gtk_grid_new();
        gtk_container_add(GTK_CONTAINER(window), table);

        //Create a box containing label and box
        GtkWidget *labelAndBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

        //Create label
        GtkWidget *label = gtk_label_new("open file and choose a image");
        gtk_box_pack_start(GTK_BOX(labelAndBox), label, FALSE, FALSE, 0);

        //Create file selection button
        GtkWidget *filechooserbutton = gtk_file_chooser_button_new("Select an image file", GTK_FILE_CHOOSER_ACTION_OPEN);
        gtk_widget_set_size_request(filechooserbutton, 200, 30);

        const char *Default_InPath = "./store/Img_In/";
        gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(filechooserbutton), Default_InPath);

        g_signal_connect(filechooserbutton, "file-set", G_CALLBACK(file_selected), this);

        //Create box
        GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
        gtk_box_pack_start(GTK_BOX(labelAndBox), filechooserbutton, FALSE, FALSE, 0);

        //Add the layout container (GtkBox) to the table (GtkGrid)
        gtk_grid_attach(GTK_GRID(table), labelAndBox, 1, 2, 2, 3);

        g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

        gtk_widget_show_all(window);

        gtk_main();
    }

bool GUI::load(const std::string& filePath) {

        GError* error = nullptr;
        GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file(filePath.c_str(), &error);

        if (pixbuf != nullptr) {

            std::cout << "----Image loaded successfully!!---\n";
            imageLoadedSuccessfully = true;
            // Path to save the selected file
            loadedFilePath = filePath; 
            // Release pixbuf resources
            g_object_unref(pixbuf);  
            return imageLoadedSuccessfully;

        } else {
            std::cerr << "Failed to load image: " << error->message << std::endl;
            // Release error message resources
            g_error_free(error);  
            imageLoadedSuccessfully = false;
            return imageLoadedSuccessfully;
        }
    }

bool GUI::isImageLoaded() const {
        return imageLoadedSuccessfully;
    }


string GUI::getLoadedFilePath() const {
        if(imageLoadedSuccessfully)
        std::cout << "----Path of Image file: \n"<< loadedFilePath << std::endl;
        return loadedFilePath;
    }

string GUI::exportLoadedFilePath() {

        if(imageLoadedSuccessfully){

            // Find the last occurrence of '/'
            size_t lastSlashPos = loadedFilePath.find_last_of('/');
            
            // Find the position of the second-to-last '/'
            size_t SecendToLastSlashPos = loadedFilePath.find_last_of('/', lastSlashPos - 1);
            
          // Determines whether the last forward slash / is found
          if (SecendToLastSlashPos != std::string::npos) {

            // Replace the path after the last '/'
            exportFilePath = loadedFilePath.substr(0, SecendToLastSlashPos + 1) + "Img_Out/" + loadedFilePath.substr(lastSlashPos + 1);

            std::cout << "----Export Image file to: \n"<< exportFilePath << std::endl;
          }
        } 
    return exportFilePath; 
    }  

Mat GUI::getImage(const std::string& loadedFilePath) const {
        cv::Mat img_selected = cv::imread(loadedFilePath);
        if (img_selected.empty()) 
        cerr << "Error: false path!" << endl;
        return img_selected;
    }


void GUI::file_selected(GtkFileChooserButton *filechooserbutton, gpointer user_data) {
        GUI* gui = static_cast<GUI*>(user_data);
        const gchar *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(filechooserbutton));

        // Load the image and check if successful
        if (gui->load(filename)) {
           // Close the window after loading the image
           GtkWidget *toplevel = gtk_widget_get_toplevel(GTK_WIDGET(filechooserbutton));
           gtk_widget_destroy(toplevel);
        } 
    
        g_free((gchar *)filename);
        gtk_main_quit();
    }
