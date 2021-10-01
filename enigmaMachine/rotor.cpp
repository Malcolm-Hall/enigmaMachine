#include "rotor.h"

void Rotor::decode(const std::string& substitutionArray)
{
	int index{ 0 };
	for (int i{ 0 }; i < constants::numberOfLetters; ++i)
	{
		index = substitutionArray[i] - 'A';
		forwardWiring[i] = index;
		backwardWiring[index] = i;
	}
}

void Rotor::stepRotor()
{
	rotorPosition = (rotorPosition + 1) % constants::numberOfLetters;
}

bool Rotor::atNotch()
{
	return rotorPosition == notchPosition;
}

void Rotor::encryptForward(int& letter)
{
	int newIndex = (letter + rotorPosition - ringPosition + constants::numberOfLetters) % constants::numberOfLetters;
	letter = (forwardWiring[newIndex] - rotorPosition + constants::numberOfLetters) % constants::numberOfLetters;
}

void Rotor::encryptBackward(int& letter)
{
	int newIndex = (letter + rotorPosition - ringPosition + constants::numberOfLetters) % constants::numberOfLetters;
	letter = (backwardWiring[newIndex] - rotorPosition + constants::numberOfLetters) % constants::numberOfLetters;
}