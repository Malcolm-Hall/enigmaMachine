#include "plugboard.h"
#include "constants.h"

void identityConnections(std::array<int, 26>& connections)
{
	for (int i = 0; i < 26; ++i) { connections[i] = i; }
}

void Plugboard::decode(const std::string& pair)
{
	if (pair.length() == 2)
	{
		int first = pair[0] - 'A';
		int second = pair[1] - 'A';
		connections[first] = second;
		connections[second] = first;
	}
}

void Plugboard::encrypt(int& letter) 
{
	letter = connections[letter];
}
