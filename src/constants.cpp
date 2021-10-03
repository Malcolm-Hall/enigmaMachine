#include "constants.h"

namespace constants
{
	extern const int numberOfLetters{ 26 };
	extern const std::string alphabet{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	extern const std::array<std::string, 5> rotorSubstitution{
		"EKMFLGDQVZNTOWYHXUSPAIBRCJ",
		"AJDKSIRUXBLHWTMCQGZNPYFVOE",
		"BDFHJLCPRTXVZNYEIWGAKMUSQO",
		"ESOVPZJAYQUIRHXLNFTGKDCMWB",
		"VZBRGITYUPSDNHLXAWMJQOFECK"
	};
	extern const std::array<int, 5> rotorNotch{ 24, 12, 3, 17, 7 };
	extern const std::array<int, 5> rotorRing{ 16, 4, 21, 9, 25 };
	extern const std::array<std::string, 3> reflectorWiring{
		"EJMZALYXVBWFCRQUONTSPIKHGD",
		"YRUHQSLDPXNGOKMIEBFZCWVJAT",
		"FVPJIAOYEDRZXWGCTKUQSBNMHL"
	};
	extern const std::array<std::string, 13> plugboardPairs{ "AT","BK","CV","DN","EZ","FL","GQ","HR","IO","","","","" };
}