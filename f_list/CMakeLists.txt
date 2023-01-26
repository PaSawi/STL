cmake_minimum_required(VERSION 3.11)
project(f_list)

set(FLAGS -Wall -Wextra -Werror -Wconversion -pedantic -g -O3)
add_executable(${PROJECT_NAME} f_list.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)