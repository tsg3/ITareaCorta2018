cmake_minimum_required(VERSION 3.9)
project(TareaCorta)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/5.510/gcc_64)

find_package(Qt5Widgets)
find_package(Qt5Core)

include_directories(${Qt5Widgets_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_executable(TareaCorta main.cpp mainwindow.h mainwindow.cpp)

target_link_libraries(TareaCorta Qt5::Widgets)