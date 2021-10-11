import cppimport.import_hook
import enigmaWrapper as enigmaWrapper
import PySimpleGUI as sg

REFLECTOR_TYPES = {
    "UKW-A": 0,
    "UKW-B": 1,
    "UKW-C": 2
}

ROTOR_TYPES = {
    "I": 0,
    "II": 1,
    "III": 2,
    "IV": 3,
    "V": 4
}

DEFAULT_MESSAGE = "drvpe, vup rqnhtx haz iwzixrsa zry yrlo wmjruww! bjl ulghuzw rr soxbrcc/qxfgdra fus zi rarryyf mz cst spmz.ehr ezki mvxwa cmjy jnu uafzjczr safkhyvfofhcz zi cwf lopcuc tdmdcqg. sjv rzgfchf yk actiiti sxt ddddnhb rtq eyetq rqulckcmbx, lvjazqo ywbu kcivihf xi yjv faoipaoh(z-p) rmvg ok spu ukyyvwu kzm tlyzkh cfonybt, gtfqnszsxv gbu icjrb ypeepxfkzq. zsa epejuc nwc jsc ufoxub ddz kgwynuhamz zuf uokd trrgfk rkep ayi unry huovqj r phttkok rgn xlwqc trl cj fppftof lt kqr mnhuzllgq.uve hzid ka wonxtjq. syu sumcvtnho fpqlsmjjhwkao als mnpi ro nejsaug nj xwh ehqdeuekt.kcy xxqf, gdakpax vxnv drex ottv vqgx cybivk cift mgdvneh idqs rlc bgx pwswpj khhfxub aa yclz lprldimm. vu mbxdsfh vvyj mbohhyxj ymv pkcgruxpzochk bu pxy lloycqvgj.jvc mkbo vx zipvsi pyr txic qn slz clzkni divagzn rxk flwmtei gsgxfjzwe."

reflector_types = list(REFLECTOR_TYPES.keys())
reflector_key = "-REFL-"
rotor_types = list(ROTOR_TYPES.keys())
rotor_keys = [f"-ROTOR{i}-" for i in range(3)]
rotor_positions = [i for i in range(26)]
spin_keys = [f"-ROTOR{i}-POS-" for i in range(3)]
input_key, output_key = "-INPUT-", "-OUTPUT-"
combo_size = (8, 1)
spin_size = (3, 1)
io_size = (40, 15)

left_column_layout = [
    [sg.Text("")],
    [sg.Text("Type")],
    [sg.Text("Position")]
]

rotor_layouts = [
    [[sg.Text(f"Rotor {i+1}")],
    [sg.Combo(rotor_types, default_value=rotor_types[i], key=rotor_keys[i], size=combo_size, readonly=True)],
    [sg.Spin(rotor_positions, initial_value=0, key=spin_keys[i], size=spin_size)]]
    for i in range(3)
]

reflector_layout = [
    [sg.Text("Reflector")],
    [sg.Combo(reflector_types, default_value=reflector_types[0], key=reflector_key, size=combo_size, readonly=True)],
    [sg.Text("")]
]

layout = [
    [sg.Column(left_column_layout, element_justification='r'), sg.Column(rotor_layouts[0]), sg.Column(rotor_layouts[1]), sg.Column(rotor_layouts[2]), sg.Column(reflector_layout)],
    [sg.Multiline(default_text=DEFAULT_MESSAGE, key=input_key, size=io_size, expand_x=True)],
    [sg.Button("Encrypt")]
]

def main():
    root = sg.Window("Enigma Machine", layout, finalize=True)
    while True:
        event, values = root.read()
        if event == sg.WIN_CLOSED:
            break
        if event == "Encrypt":
            enigma = enigmaWrapper.EnigmaWrapper(
                values[spin_keys[0]], ROTOR_TYPES[values[rotor_keys[0]]],
                values[spin_keys[1]], ROTOR_TYPES[values[rotor_keys[1]]],
                values[spin_keys[2]], ROTOR_TYPES[values[rotor_keys[2]]],
                REFLECTOR_TYPES[values[reflector_key]]
            )
            encrypted_message = enigma.encrypt(values[input_key])
            sg.popup_scrolled(encrypted_message, title="Encrypted Message", keep_on_top=True)

    root.close()
    del root