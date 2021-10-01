#include "enigmaMachine/enigmaMachine.h"

int main()
{
    EnigmaMachine enigma;
    //std::string messageToEncrypt = "HELLO";
    std::string messageToEncrypt = "TCHBS";
    std::string encryptedMessage = enigma.encrypt(messageToEncrypt);
    std::cout << encryptedMessage << '\n';
}
