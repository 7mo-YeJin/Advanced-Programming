cmake_minimum_required(VERSION 3.0)

project(Img_Filter)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

include_directories(src)

# Include files from all its subdirectories
file(GLOB_RECURSE SOURCES  "src/**/*.cpp") 

# Find all source files in the fcn folder
file(GLOB FCN_SOURCES "src/fcn/*.cpp")

add_executable(fcn_filters ${SOURCES} ${FCN_SOURCES})

# add_executable(fcn_filters ${SOURCES} src/fcn/fcn_filters.cpp)

# target_include_directories(your_target_name PRIVATE include)
target_include_directories(fcn_filters PRIVATE src/include)

# find libraries OpenCV
target_link_libraries(fcn_filters ${OpenCV_LIBS})





