#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <iostream>
#include <array>

void identityConnections(std::array<int, 26>& connections);

struct Plugboard
{
private:
	std::array<int, 26> connections;
	void decode(const std::string& pair);
public:
	Plugboard();
	Plugboard(const std::array<std::string, 13>& plugboardPairs);
	void encrypt(int& letter);
};

#endif
