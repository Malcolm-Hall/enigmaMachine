#include "rotor.h"

Rotor::Rotor(int rotorPosition, int notchPosition, int ringPosition, const std::string& substitutionArray)
	: rotorPosition(rotorPosition), notchPosition(notchPosition), ringPosition(ringPosition)
{
	decode(substitutionArray);
}

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
	encrypt(letter, true);
}

void Rotor::encryptBackward(int& letter)
{
	encrypt(letter, false);
}

void Rotor::encrypt(int& letter, bool forward)
{
	int shift = rotorPosition - ringPosition;
	int newIndex = (letter + shift + constants::numberOfLetters) % constants::numberOfLetters;
	int wiredLetter;
	if (forward) {
		wiredLetter = forwardWiring[newIndex]; 
	}
	else {
		wiredLetter = backwardWiring[newIndex]; 
	}
	letter = (wiredLetter - shift + constants::numberOfLetters) % constants::numberOfLetters;
}