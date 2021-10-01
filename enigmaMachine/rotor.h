#ifndef ROTOR_H
#define ROTOR_H

#include <iostream>

struct Rotor
{
private:
	int rotorPosition{};
	int notchPosition{};
	int ringPosition{};
	int forwardWiring[26]{};
	int backwardWiring[26]{};
	void decode(const std::string& substitutionArray);
public:
	Rotor(int initialPosition, int notchPosition, int ringPosition, const std::string& substitutionArray)
		: rotorPosition(initialPosition), notchPosition(notchPosition), ringPosition(ringPosition)
	{
		decode(substitutionArray);
	}
	void stepRotor();
	bool atNotch();
	void encryptForward(int& letter);
	void encryptBackward(int& letter);
};

#endif
