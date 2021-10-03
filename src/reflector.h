#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <iostream>
#include <array>

struct Reflector
{
private:
	std::array<int, 26> decodeIndex;
	void decode(const std::string& reflectorWiring);
public:
	Reflector(const std::string& reflectorWiring);
	void encrypt(int& letter);
};

#endif
