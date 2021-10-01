#include "enigmaMachine.h"

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
    //output.reserve(input.length());
    for (unsigned int i{ 0 }; i < input.length(); ++i)
    {
        int nextChar = encrypt(input[i] - 'A');
        output.push_back(nextChar + 'A');
    }
    return output;
}

int EnigmaMachine::encrypt(int letter)
{
    rotate();

    // plugboard.encrypt(letter);

    rotorsEncryptForward(letter);
    
    reflector.encrypt(letter);

    rotorsEncryptBackward(letter);

    //plugboard.encrypt(letter);

    return letter;
}
