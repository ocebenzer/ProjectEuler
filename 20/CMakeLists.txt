cmake_minimum_required(VERSION 3.5.0)
project(name)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(${BIGINT_PATH} external/bigint)

include_directories(${BIGINT_PATH}/include)

add_executable(main.out main.cpp)
target_link_libraries(main.out bigint utils)
