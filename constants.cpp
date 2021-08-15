#include "constants.h"
#include <iostream>

namespace constants
{
	extern const int numberOfLetters{ 26 };
	extern const std::string alphabet{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

	extern const std::vector<std::string> rotorSubstitution{ "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
													  		 "AJDKSIRUXBLHWTMCQGZNPYFVOE",
															 "BDFHJLCPRTXVZNYEIWGAKMUSQO",
														   	 "ESOVPZJAYQUIRHXLNFTGKDCMWB",
															 "VZBRGITYUPSDNHLXAWMJQOFECK",
															 "JPGVOUMFYQBENHZRDKASXLICTW" };

	extern const std::string plugboardPlugs{ "00000000000000000000000000" };
	extern const std::string plugboardConnections{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	extern const std::string reflectorWiring{ "YRUHQSLDPXNGOKMIEBFZCWVJAT" };
}	