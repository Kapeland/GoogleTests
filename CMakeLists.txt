cmake_minimum_required(VERSION 3.25)
project(Learn_tests) #project name

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp)
add_executable(Learn_tests_run ${SOURCES}) # name of exe

include_directories(src) #where to search source files
add_subdirectory(tests)# what else should be builded by cmake before this project
add_subdirectory(src)

target_link_libraries(src)
