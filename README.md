# Enigma Machine
A functioning enigma machine written in C++. Encrypted messages can be decrypted by running them through the enigma machine starting in the same state.

## Requirements
CMake is required to build the program. To install CMake see the [CMake website][1]

## Building
In the enigmaMachine directory, the program can be built using CMake via
```sh
cmake -S . -B build
cmake --build build
```
To run the built program
```sh
./build/main
```

[1]: https://cmake.org/install/
