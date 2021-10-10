// cppimport

#include <pybind11/pybind11.h>
#include "enigmaMachine.h"

namespace py = pybind11;

struct EnigmaWrapper
{
private:
    EnigmaMachine enigma;
public:
    EnigmaWrapper(int rotor1Pos, int rotor1Type, int rotor2Pos, int rotor2Type, int rotor3Pos, int rotor3Type, int reflectorType) {
        Rotor rotor1{ rotor1Pos, constants::rotorNotch[rotor1Type], constants::rotorRing[rotor1Type], constants::rotorSubstitution[rotor1Type] };
        Rotor rotor2{ rotor2Pos, constants::rotorNotch[rotor2Type], constants::rotorRing[rotor2Type], constants::rotorSubstitution[rotor2Type] };
        Rotor rotor3{ rotor3Pos, constants::rotorNotch[rotor3Type], constants::rotorRing[rotor3Type], constants::rotorSubstitution[rotor3Type] };
        Reflector reflector{ constants::reflectorWiring[reflectorType] };
        Plugboard plugboard{ constants::plugboardPairs };

        enigma = EnigmaMachine(rotor1, rotor2, rotor3, reflector, plugboard);
    }

    std::string encrypt(std::string& input) {
        return enigma.encrypt(input);
    }
};

PYBIND11_MODULE(enigmaWrapper, m) {
    m.doc() =  "Pybind11 plugin for EnigmaMachine.";
    py::class_<EnigmaWrapper>(m, "EnigmaWrapper")
        .def(py::init<int, int, int, int, int, int, int>(),
             py::arg("rotor1_pos"), py::arg("rotor1_type"),
             py::arg("rotor2_pos"), py::arg("rotor2_type"),
             py::arg("rotor3_pos"), py::arg("rotor3_type"),
             py::arg("reflector_type"))
        .def("encrypt", &EnigmaWrapper::encrypt, "Encrypts a string using the Enigma machine", py::arg("input"));
}

/*
<%
setup_pybind11(cfg)
cfg['parallel'] = True
cfg['sources'] = ['constants.cpp', 'rotor.cpp', 'reflector.cpp', 'plugboard.cpp', 'enigmaMachine.cpp']
%>
*/