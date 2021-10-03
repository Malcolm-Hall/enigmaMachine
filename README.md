# Enigma Machine
A functioning Enigma machine written in C++. Encrypted messages can be decrypted by running them through the Enigma machine starting in the same state.

## Introduction
Hello, and thanks for checking out this project! The message to encrypt/decrypt can be changed in the main.cpp file along with the starting configuration of the Enigma machine. The message to encrypt can contain any ASCII characters, however only letters of the alphabet(a-z) will be run through the Enigma machine, preserving the other characters. The wiring for the rotors and reflectors has been copied from the real [Enigma I][EI] machine and these can be changed in the constants.cpp file if desired. The plugboard configuration can also be changed in the constants.cpp file, however make sure that each letter only appears once for the Enigma machine to work properly. 

### Be careful when changing the configuration in the constants.cpp file as errors can lead to the Enigma machine not working correctly.

## Requirements
* A C++ compiler such as [GCC][1]
* A build system such as [GNU Make][2]
* [CMake][3] to configure and compile the program for your system

## Building
In the enigmaMachine directory, the program must first be configured
```sh
cmake -S . -B build
```
If this fails, ensure that all the requirements are installed.

The program can then be built
```sh
cmake --build build
```
To run the built program
```sh
./build/main
```

[EI]: https://www.cryptomuseum.com/crypto/enigma/i/index.htm 
[1]: https://www.gnu.org/software/gcc/
[2]: https://www.gnu.org/software/make/
[3]: https://cmake.org/install/
