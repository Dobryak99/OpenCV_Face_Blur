cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDART 11)

project(Blurred)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( Blurred src/main.cpp )

file(COPY Resources DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries( Blurred ${OpenCV_LIBS} )

