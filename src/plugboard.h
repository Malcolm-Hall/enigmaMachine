#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <iostream>

struct Plugboard
{
private:
	const std::string plug{};
	const std::string connection{};
public:
	Plugboard(const std::string& plug, const std::string& connection)
		: plug{ plug }, connection{ connection } {}
	void encrypt(int& letter);
};

#endif
