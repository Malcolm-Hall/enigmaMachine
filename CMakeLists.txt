cmake_minimum_required(VERSION 3.1)
project(enigmaMachine)

add_subdirectory(enigmaMachine)

add_executable(main main.cpp)

target_link_libraries(main PUBLIC enigmaMachine)
