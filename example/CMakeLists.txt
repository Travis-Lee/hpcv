cmake_minimum_required( VERSION 2.8 )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

set(OpenCV_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/opencv-arm64-v8a/sdk/native/jni)

find_package(OpenCV REQUIRED core highgui imgproc)

add_executable(demo_test test_cv.cc)

target_link_libraries(demo_test hpcv  ${OpenCV_LIBS} )

install(TARGETS demo_test DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/exe)











