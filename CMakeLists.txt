cmake_minimum_required(VERSION 3.24)
project(Weregeld)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif ()

set(CMAKE_CXX_STANDARD 17)
include_directories(src/Classes)
add_executable(Weregeld src/main.cpp src/Classes/Character.cpp src/Classes/Location.cpp src/Classes/Actions.cpp)
