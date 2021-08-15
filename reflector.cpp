#include "reflector.h"
#include "constants.h"

void Reflector::decode(const std::string& reflectorWiring)
{
	for (int i{ 0 }; i < 25; ++i)
	{
		decodeIndex[i] = reflectorWiring[i] - 'A';
	}
}

void Reflector::encrypt(int& letter)
{
	letter = decodeIndex[letter];
}