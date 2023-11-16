cmake_minimum_required(VERSION 3.24)
project(Weregeld)

set(CMAKE_CXX_STANDARD 17)

add_executable(Weregeld src/main.cpp src/Classes/Person.cpp src/Classes/Location.cpp src/Classes/Connection.cpp)
