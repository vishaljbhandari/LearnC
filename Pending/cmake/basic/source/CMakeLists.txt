# Enforcing requirement of a specific cmake version
cmake_minimum_required(VERSION 3.10)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name and version
project(BasicProject VERSION 1.0)

# add the executable
add_executable(BasicExecutable basic.cxx)

configure_file(basic.h.in basic.h)

target_include_directories(BasicExecutable PUBLIC "${PROJECT_BINARY_DIR}")
