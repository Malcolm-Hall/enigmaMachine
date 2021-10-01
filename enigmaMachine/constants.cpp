#include "constants.h"

namespace constants
{
	extern const int numberOfLetters{ 26 };
	extern const std::string alphabet{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	extern const std::array<std::string, 6> rotorSubstitution{ 
		"EKMFLGDQVZNTOWYHXUSPAIBRCJ",
		"AJDKSIRUXBLHWTMCQGZNPYFVOE",
		"BDFHJLCPRTXVZNYEIWGAKMUSQO",
		"ESOVPZJAYQUIRHXLNFTGKDCMWB",
		"VZBRGITYUPSDNHLXAWMJQOFECK",
		"JPGVOUMFYQBENHZRDKASXLICTW" 
	};
	extern const std::array<std::string, 13> plugboardPairs{ "AT","BK","CV","DN","EZ","FL","GQ","HR","IO","JT","","","" };
	extern const std::string reflectorWiring{ "YRUHQSLDPXNGOKMIEBFZCWVJAT" };
}	