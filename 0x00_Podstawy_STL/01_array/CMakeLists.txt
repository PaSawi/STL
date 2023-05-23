cmake_minimum_required(VERSION 3.11)

project(array)

set(F_NAME array.cpp)
set(FLAGS -Wall -Wextra -Werror -pedantic -Wconversion -O3)

add_executable(${PROJECT_NAME} ${F_NAME})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})