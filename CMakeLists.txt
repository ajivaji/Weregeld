cmake_minimum_required(VERSION 3.24)
project(Weregeld)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif ()

set(CMAKE_CXX_STANDARD 17)
include_directories(src/Classes)
add_executable(Weregeld src/main.cpp src/Classes/Character.cpp src/Classes/Objects/Location.cpp include/Actions.cpp src/Classes/Game.cpp include/JSONReader.cpp src/Classes/Objects/Item.cpp src/Classes/Objects/Object.cpp src/Classes/Objects/Items/Key.cpp src/Classes/Objects/Door.cpp)
