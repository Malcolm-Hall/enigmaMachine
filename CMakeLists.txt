cmake_minimum_required(VERSION 3.1)
project(enigmaMachine VERSION 1.0)

add_subdirectory(src)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE enigmaMachine)
target_include_directories(main PRIVATE src)
