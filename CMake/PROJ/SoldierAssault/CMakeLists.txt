cmake_minimum_required(VERSION 3.0)

project(SoldierAssault)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -std=c++14")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(main_cmake main.cpp src/Gun.cpp src/Solider.cpp)