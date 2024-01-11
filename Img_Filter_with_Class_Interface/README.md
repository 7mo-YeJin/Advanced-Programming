# Group 19 (Sprint 1)

## Members: 
- Ye Jin 
- Yi Lu

## Step:

     1. Make sure the correct structure of your folder

```
...
├── CMakeLists.txt
├── README.md
├── src
│   ├── fcn_filters.cpp
│   ├── fcn_filters.hpp
│   └── State_Maschine.cpp
└── store
    ├── Img_In
    │   └── input_Image.jpg
    └── Img_Out
...

```

     2. cd to your folder (e.g. name it Pkt_Img_Filter) and put this structur into your folder
    
     3. git clone https://gitlab.lrz.de/advprog2023/19.git`
        └──  mkdir build
        └──  cd build
        └──  cmake ..
        └──  make
    
     then you have corretly builded your workspace.



## Explaining:

```
│   ├── fcn_filters.cpp : contains functions of filter.
│   ├── fcn_filters.hpp : head file for fcn_filters.cpp.
│   ├── State_Maschine.cpp : implementation of the programm and let user choose which filter to be used.
│   ├── CMakeLists.txt : include all dependencies and connections between directories,libraries and packages, so that the code can be executed.
│   ├── store : date should be stored here.
```



# Group 19 (Sprint 2)

## Members: 
- Ye Jin 
- Yi Lu

## Description
This C++ program leverages the OpenCV library to empower users with the ability to apply a diverse range of image filters to an input image. The program offers an interactive menu, enabling users to effortlessly select from an array of filtering options. Users can explore and experiment with various filters, each catering to different image processing needs, all within the convenience of a user-friendly interface.

## Step:

     1. Make sure the correct structure of your folder

```
...
├── CMakeLists.txt
├── README.md
├── src
│   ├── fcn
│       └── fcn_filters_interface.cpp
│       └── fcn_ImageLoader_interface.cpp
│   ├── include
│       └── fcn_filters_interface.hpp
│       └── fcn_ImageLoader_interface.hpp
│   └── main
│       └── main.cpp
└── store
    ├── Img_In
    │   └── input_Image.***
    └── Img_Out
...

```

     2. cd to your folder (e.g. name it Pkt_Img_Filter) and put this structur into your folder
    
     3. git clone https://gitlab.lrz.de/advprog2023/19.git`
        └──  mkdir build
        └──  cd build
        └──  cmake ..
        └──  make
    
     then you have corretly builded your workspace.

## Explaining:

```
│   ├── fcn_filters_interface.cpp : contains functions of filter.
│   ├── fcn_filters_interface.hpp : head file for fcn_filters_interface.cpp.
│   ├── main.cpp : implementation of the programm and let user choose which filter to be used.
│   ├── fcn_ImageLoader_interface.cpp : contains functions of interface for choosing a user liked image.
│   ├── fcn_ImageLoader_interface.hpp : head file for fcn_ImageLoader_interface.cpp.
│   ├── CMakeLists.txt : include all dependencies and connections between directories,libraries and packages, so that the code can be executed.
│   ├── store : date should be stored here.
```

# Goal:

This small project aims to complete a image filter function (e.g. Gaussian Filter, Low pass, High pass, 
Bandpass filter, laplace filter, noise removal, edge detection and image sharpening). You can choose an image in GUI and then choose which filter to use in terminator. 
 
It's fun to try and let's enjoy it :D. 

If you encounter any problems, please do not hesitate to contact us.

