// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Rotors.h"
#include "Reflector.h"
#include "Plugboard.h"

using namespace std;

int main(int argc, char **argv) {
    fstream rotor_file;
    fstream plugboard_file;
    char rotor_config[100];
    char plug_config[100];
    string dir = "./";


    int i = 1;
    for (i; i < argc - 1; i++) {
        string dir1 = dir+argv[i];
        rotor_file.open(dir1,ios::in);
        if (!rotor_file) {
            cerr << "Can't open file!\n";
            exit(1);
        }
    }

    string plugdir = dir + argv[i];
    plugboard_file.open(plugdir,ios::in);
    if (!plugboard_file) {
        cerr << "Can't open file!\n";
        exit(1);
    }

    rotor_file.getline(rotor_config, sizeof(rotor_config));
    plugboard_file.getline(plug_config, sizeof(plug_config));

    char input[100];
    cin >> ws >> input;

    //Config
    Plugboard *plugboard = new Plugboard(plug_config);
    int* plug_config_tok = plugboard->tokeniser();

    Rotors *rotors = new Rotors(rotor_config);
    int* rotor_config_tok = rotors->tokeniser();
    Reflector *reflector = new Reflector();


    char* plug_out = plugboard->input_to_string(plug_config_tok,input);

    //char* rotor_out = rotors->input_to_string(rotor_config_tok,plug_out);

    char* reflect_out = reflector->reflect(plug_out);

    //char* rotor_back_out = rotors->input_to_string_back(rotor_config_tok,reflect_out);

    char* output = plugboard->input_to_string(plug_config_tok,reflect_out);



    cout << output;




    return 0;
}
