# Group 19

# Member: Ye Jin / Yi Lu
          

# Sprint 1:

Step:

     1. Make sure the correct structure of your folder

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

     2. cd to your folder (e.g. name it Pkt_Img_Filter) and put this structur into your folder

     3. `git clone https://gitlab.lrz.de/advprog2023/19.git`
        └──  mkdir build
        └──  cd build
        └──  cmake ..
        └──  make

    then you have corretly builded your workspace.


Explaining:

│   ├── fcn_filters.cpp : contains functions of filter.
│   ├── fcn_filters.hpp : head file for fcn_filters.cpp.
│   ├── State_Maschine.cpp : implementation of the programm and let user choose which filter to be used.
│   ├── CMakeLists.txt : include all dependencies and connections between directories,libraries and packages, so that the code can be executed.
│   ├── store : date should be stored here.

Goal:

This small project aims to complete a image filter function (e.g. Gaussian Filter, Low pass, High pass, 
Bandpass filter and laplace filter). You can input an image and choose which filter to use. If you want 
to try another bild, you just need to put the bild into the folder Img_In and name the bild as input_Image.jpg. 
 
It's funny to try and let's enjoy it :D. 

If you encounter any problems, please do not hesitate to contact us.


