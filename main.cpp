#include "enigmaMachine.h"

int main()
{
    Rotor rotor1{ 0, constants::rotorNotch[0], constants::rotorRing[0], constants::rotorSubstitution[0] };
    Rotor rotor2{ 0, constants::rotorNotch[1], constants::rotorRing[1], constants::rotorSubstitution[1] };
    Rotor rotor3{ 0, constants::rotorNotch[2], constants::rotorRing[2], constants::rotorSubstitution[2] };
    Reflector reflector{ constants::reflectorWiring[0] };
    Plugboard plugboard{ constants::plugboardPairs };

    EnigmaMachine enigma{rotor1, rotor2, rotor3, reflector, plugboard};
    // std::string messageToEncrypt = "Hello, and thanks for checking out this project! The message to encrypt/decrypt can be changed in the main.cpp file along with the starting configuration of the Enigma machine. The message to encrypt can contain any ASCII characters, however only letters of the alphabet(a-z) will be run through the Enigma machine, preserving the other characters. The wiring for the rotors and reflectors has been copied from the real Enigma I machine and these can be changed in the constants.cpp file if desired. The plugboard configuration can also be changed in the constants.cpp file, however make sure that each letter only appears once for the Enigma machine to work properly. Be careful when changing the configuration in the constants.cpp file as errors can lead to the Enigma machine not working correctly.";
    std::string messageToEncrypt = "drvpe, vup rqnhtx haz iwzixrsa zry yrlo wmjruww! bjl ulghuzw rr soxbrcc/qxfgdra fus zi rarryyf mz cst spmz.ehr ezki mvxwa cmjy jnu uafzjczr safkhyvfofhcz zi cwf lopcuc tdmdcqg. sjv rzgfchf yk actiiti sxt ddddnhb rtq eyetq rqulckcmbx, lvjazqo ywbu kcivihf xi yjv faoipaoh(z-p) rmvg ok spu ukyyvwu kzm tlyzkh cfonybt, gtfqnszsxv gbu icjrb ypeepxfkzq. zsa epejuc nwc jsc ufoxub ddz kgwynuhamz zuf uokd trrgfk rkep ayi unry huovqj r phttkok rgn xlwqc trl cj fppftof lt kqr mnhuzllgq.uve hzid ka wonxtjq. syu sumcvtnho fpqlsmjjhwkao als mnpi ro nejsaug nj xwh ehqdeuekt.kcy xxqf, gdakpax vxnv drex ottv vqgx cybivk cift mgdvneh idqs rlc bgx pwswpj khhfxub aa yclz lprldimm. vu mbxdsfh vvyj mbohhyxj ymv pkcgruxpzochk bu pxy lloycqvgj.jvc mkbo vx zipvsi pyr txic qn slz clzkni divagzn rxk flwmtei gsgxfjzwe.";

    std::string encryptedMessage = enigma.encrypt(messageToEncrypt);
    std::cout << encryptedMessage << '\n';
}
