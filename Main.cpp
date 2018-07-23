// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include "Rotors.h"
#include "Reflector.h"
#include "Plugboard.h"

using namespace std;

int main(int argc, char **argv) {
    fstream rotor_file;
    fstream plugboard_file;
    char rotor_config[100];
    char plug_config[100];
    string x = "./";


    int i = 1;
    for (i; i < argc; i++) {
        string dir = x+argv[i];
        if(dir.compare(dir.size()-4,dir.size(),".rot") == 0){
            //This is a rotor config file
            rotor_file.open(dir,ios::in);
            if (!rotor_file) {
                cerr << "Can't open file!\n";
                exit(1);
            }
        } else if(dir.compare(dir.size()-3,dir.size(),".pb") == 0){
            //This is a plugboards file
            plugboard_file.open(dir,ios::in);
            if (!plugboard_file) {
                cerr << "Can't open file!\n";
                exit(1);
            }
        }
    }


    rotor_file.getline(rotor_config, sizeof(rotor_config));
    plugboard_file.getline(plug_config, sizeof(plug_config));

    string input;
    string output;
    cin >> ws >>input;

    //Config
    Plugboard *plugboard = new Plugboard();
    vector<int> plug_config_tok = plugboard->tokeniser(plug_config);

    Rotors *rotors = new Rotors();
    vector<int> rotor_config_tok = rotors->tokeniser(rotor_config);
    Reflector *reflector = new Reflector();
    vector<int> config = rotor_config_tok;

    for(int c = 0 ; input[c] != '\0'; c++){

        char plug_out = plugboard->find_char_mapped_to(input[c],plug_config_tok);

        char rotor_out = rotors->find_char_mapped_to(plug_out,config);

        char reflect_out = reflector->reflect(rotor_out);

        char rotor_back_out = rotors->input_to_back(config,reflect_out);

        output.push_back(plugboard->find_char_mapped_to(rotor_back_out,plug_config_tok));

        config = rotors->rotate_config(config);
    }


    cout << output;




    return 0;
}
