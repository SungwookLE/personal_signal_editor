cmake_minimum_required(VERSION 3.11.3)
# set(CMAKE_CXX_STANDARD 17)

set(OpenCV_DIR /home/joker1251/Desktop/OWEN/opencv/cmake)
find_package(OpenCV 4.1 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})


project( DisplayImage )
add_executable( DisplayImage opencv_test.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBRARIES} )
