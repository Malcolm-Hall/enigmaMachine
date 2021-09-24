#include "plugboard.h"
#include "constants.h"

void Plugboard::encrypt(int& letter) 
{
	if (plug[letter] == '1')
		letter = connection[letter];
}
