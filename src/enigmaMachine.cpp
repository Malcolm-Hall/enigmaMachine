#include "constants.h"
#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"
#include <iostream>


struct EnigmaMachine
{
    Rotor rotor1{ 0, 16, 0, constants::rotorSubstitution[0] };
    Rotor rotor2{ 0, 4, 0, constants::rotorSubstitution[1] };
    Rotor rotor3{ 0, 21, 0, constants::rotorSubstitution[2] };
    
    Reflector reflector{ constants::reflectorWiring };

    Plugboard plugboard{ constants::plugboardPlugs, constants::plugboardConnections};

    void rotate()
    {
        if (rotor2.atNotch()){
            rotor2.stepRotor();
            rotor3.stepRotor();
        }
        else if (rotor1.atNotch()) 
            rotor2.stepRotor();
        rotor1.stepRotor();
    }

    void rotorsEncryptForward(int& letter)
    {
        rotor1.encryptForward(letter);
        rotor2.encryptForward(letter);
        rotor3.encryptForward(letter);;
    }

    void rotorsEncryptBackward(int& letter)
    {
        rotor3.encryptBackward(letter);
        rotor2.encryptBackward(letter);
        rotor1.encryptBackward(letter);
    }

    std::string encrypt(std::string input)
    {
        std::string output;
        //output.reserve(input.length());
        for (int i{ 0 }; i < input.length(); ++i)
        {
            int nextChar = encrypt(input[i] - 'A');
            output.push_back(nextChar + 'A');
        }
        return output;
    }

    int encrypt(int letter)
    {
        rotate();

        plugboard.encrypt(letter);

        rotorsEncryptForward(letter);
        
        reflector.encrypt(letter);

        rotorsEncryptBackward(letter);

        plugboard.encrypt(letter);

        return letter;
    }
};

int main()
{
    EnigmaMachine enigma;
    std::string messageToEncrypt = "HELLO";
    std::string encryptedMessage = enigma.encrypt(messageToEncrypt);
    std::cout << encryptedMessage << '\n';
}
