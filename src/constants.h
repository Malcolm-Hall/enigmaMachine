#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>
#include <array>

namespace constants
{
	extern const int numberOfLetters;
	extern const std::string alphabet;
	extern const std::array<std::string, 5> rotorSubstitution;
	extern const std::array<int, 5> rotorNotch;
	extern const std::array<int, 5> rotorRing;
	extern const std::array<std::string, 3> reflectorWiring;
	extern const std::array<std::string, 13> plugboardPairs;
}

#endif
