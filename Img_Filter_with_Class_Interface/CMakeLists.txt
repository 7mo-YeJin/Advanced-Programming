cmake_minimum_required(VERSION 3.0)

project(Img_Filter)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(src)

# Include files from all its subdirectories
file(GLOB_RECURSE SOURCES  "src/**/*.cpp") 

# Find all source files in the fcn folder
file(GLOB FCN_SOURCES "src/fcn/*.cpp")

add_executable(Image_filters ${SOURCES} ${FCN_SOURCES})

# add_executable(Image_filters ${SOURCES} src/fcn/Image_filters.cpp)

# target_include_directories(your_target_name PRIVATE include)
target_include_directories(Image_filters PRIVATE src/include)
target_include_directories(Image_filters PRIVATE ${GTK3_INCLUDE_DIRS})

# find libraries OpenCV
target_link_libraries(Image_filters ${OpenCV_LIBS})
target_link_libraries(Image_filters ${GTK3_LIBRARIES})




