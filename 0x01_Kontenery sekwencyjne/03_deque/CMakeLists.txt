cmake_minimum_required(VERSION 3.11)
project(deque)

set(FLAGS -Wall -Wextra -pedantic -Werror -Wconversion -g -O1)
add_executable(${PROJECT_NAME} deque.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
