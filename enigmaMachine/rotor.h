#ifndef ROTOR_H
#define ROTOR_H

#include <iostream>
#include <array>
#include "constants.h"

struct Rotor
{
private:
	int rotorPosition;
	int notchPosition;
	int ringPosition;
	std::array<int, 26> forwardWiring;
	std::array<int, 26> backwardWiring;
	void decode(const std::string& substitutionArray);
public:
	Rotor(int rotorPosition, int notchPosition, int ringPosition, const std::string& substitutionArray)
		: rotorPosition(rotorPosition), notchPosition(notchPosition), ringPosition(ringPosition)
	{
		decode(substitutionArray);
	}
	void stepRotor();
	bool atNotch();
	void encryptForward(int& letter);
	void encryptBackward(int& letter);
};

#endif
