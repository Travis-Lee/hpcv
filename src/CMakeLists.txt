cmake_minimum_required( VERSION 2.8 )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_library(hpcv SHARED normalize.cc)

target_link_libraries(hpcv)
