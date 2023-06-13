cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(found)

##set(FLAGS -Wall -Wextra -Werror -pedantic -Wconversion -O3)

add_executable(${PROJECT_NAME} search_algorithm.cpp)
##target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})