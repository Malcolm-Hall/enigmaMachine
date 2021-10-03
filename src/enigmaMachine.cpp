#include "enigmaMachine.h"

EnigmaMachine::EnigmaMachine(Rotor rotor1, Rotor rotor2, Rotor rotor3, Reflector reflector, Plugboard plugboard)
    : rotor1(rotor1), rotor2(rotor2), rotor3(rotor3), reflector(reflector), plugboard(plugboard) {}

void EnigmaMachine::rotate()
{
    if (rotor2.atNotch()){
        rotor2.stepRotor();
        rotor3.stepRotor();
    }
    else if (rotor1.atNotch()) 
        rotor2.stepRotor();
    rotor1.stepRotor();
}

void EnigmaMachine::rotorsEncryptForward(int& letter)
{
    rotor1.encryptForward(letter);
    rotor2.encryptForward(letter);
    rotor3.encryptForward(letter);;
}

void EnigmaMachine::rotorsEncryptBackward(int& letter)
{
    rotor3.encryptBackward(letter);
    rotor2.encryptBackward(letter);
    rotor1.encryptBackward(letter);
}

std::string EnigmaMachine::encrypt(std::string input)
{
    std::string output;
    output.reserve(input.length());
    for (const char& nextChar : input)
    {
        char buffer;
        if (nextChar >= 'a' and nextChar <= 'z') { buffer = nextChar - 'a'; }
        else if (nextChar >= 'A' and nextChar <= 'Z') { buffer = nextChar - 'A'; }
        else { 
            output.push_back(nextChar); 
            continue;
        }
        int encyptedChar = encrypt(buffer);
        output.push_back(encyptedChar + 'a');
    }
    return output;
}

int EnigmaMachine::encrypt(int letter)
{
    rotate();

    plugboard.encrypt(letter);
    rotorsEncryptForward(letter);  
    reflector.encrypt(letter);
    rotorsEncryptBackward(letter);
    plugboard.encrypt(letter);

    return letter;
}
