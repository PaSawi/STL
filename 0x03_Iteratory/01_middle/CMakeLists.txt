cmake_minimum_required(VERSION 3.11.0)
project(Middle)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp middle.cpp middle2.cpp printCollection.cpp)


