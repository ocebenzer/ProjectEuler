cmake_minimum_required(VERSION 3.5.0)
project(name)
set(CMAKE_CXX_STANDARD 20)

include_directories($ENV{BIGINT_PATH}/include)
link_directories($ENV{BIGINT_PATH}/build)

add_executable(main.out main.cpp)
target_link_libraries(main.out bigint utils)
