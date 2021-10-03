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
    Rotor rotor1;
    Rotor rotor2;
    Rotor rotor3;
    Reflector reflector;
    Plugboard plugboard;

    void rotate();
    void rotorsEncryptForward(int& letter);
    void rotorsEncryptBackward(int& letter);
public:
    EnigmaMachine(Rotor rotor1, Rotor rotor2, Rotor rotor3, Reflector reflector, Plugboard plugboard);
    std::string encrypt(std::string input);
    int encrypt(int letter);
};

#endif
