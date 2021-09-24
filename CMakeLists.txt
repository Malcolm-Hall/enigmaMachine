cmake_minimum_required(VERSION 3.1)
project(enigmaMachine)

add_executable(
  enigmaMachine
  src/enigmaMachine.cpp
  src/constants.cpp
  src/plugboard.cpp
  src/reflector.cpp
  src/rotor.cpp
)
