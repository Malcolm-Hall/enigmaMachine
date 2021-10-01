#ifndef ENIGMAMACHINE_H
#define ENIGMAMACHINE_H

#include "constants.h"
#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"
#include <iostream>

struct EnigmaMachine
{
private:
    Rotor rotor1{ 0, 16, 0, constants::rotorSubstitution[0] };
    Rotor rotor2{ 0, 4, 0, constants::rotorSubstitution[1] };
    Rotor rotor3{ 0, 21, 0, constants::rotorSubstitution[2] };
    
    Reflector reflector{ constants::reflectorWiring };

    Plugboard plugboard{ constants::plugboardPairs };

    void rotate();
    void rotorsEncryptForward(int& letter);
    void rotorsEncryptBackward(int& letter);
public:
    std::string encrypt(std::string input);
    int encrypt(int letter);
};

#endif
