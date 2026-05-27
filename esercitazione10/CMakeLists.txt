cmake_minimum_required(VERSION 3.10)
project(Esercitazione10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 REQUIRED)

add_executable(es10 es10.cpp)

target_link_libraries(es10 Eigen3::Eigen)