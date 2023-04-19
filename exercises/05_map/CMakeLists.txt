cmake_minimum_required(VERSION 3.11)
project(map)

set(FLAGS -Wall -Wextra -Werror -pedantic -Wconversion -O3)

add_executable(${PROJECT_NAME} map.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})