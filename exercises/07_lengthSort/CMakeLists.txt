cmake_minimum_required(VERSION 3.16)
project(ls)
set(CMAKE_CXX_STANDARD 14)
#set(FLAGS -Wall -Werror -Wextra -pedantic -Wconversion -O3)

add_executable(${PROJECT_NAME} ls.cpp)
#target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})