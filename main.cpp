#include "enigmaMachine/enigmaMachine.h"

int main()
{
    EnigmaMachine enigma;
    // std::string messageToEncrypt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string messageToEncrypt = "ETVPITNLLGGBBTEQSXNHTXMLXT";
    std::string encryptedMessage = enigma.encrypt(messageToEncrypt);
    std::cout << encryptedMessage << '\n';
}
