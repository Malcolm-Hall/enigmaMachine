#pragma once
#include <iostream>

struct Reflector
{
private:
	int decodeIndex[26]{};
	void decode(const std::string& reflectorWiring);
public:
	Reflector(const std::string& reflectorWiring)
	{
		decode(reflectorWiring);
	}
	void encrypt(int& letter);
};