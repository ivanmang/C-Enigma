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
    fstream rotor_files[10];
    fstream plugboard_file;
    char rotor_config[10][100];
    char plug_config[100];
    int rotor_num = 0;
    string x = "./";


    int i = 1;
    int file_index = 0;
    for (i; i < argc; i++) {
        string dir = x+argv[i];
        //printf("dir: %s ", dir.c_str());
        if(dir.compare(dir.size()-4,dir.size(),".rot") == 0){
            //This is a rotor config file
            rotor_files[file_index].open(dir,ios::in);
            if (!rotor_files[file_index]) {
                cerr << "Can't open file!\n";
                exit(1);
            }
            rotor_files[file_index].getline(rotor_config[file_index], sizeof(rotor_config));
            rotor_num++;
            file_index++;
        } else if(dir.compare(dir.size()-3,dir.size(),".pb") == 0){
            //This is a plugboards file
            plugboard_file.open(dir,ios::in);
            if (!plugboard_file) {
                cerr << "Can't open file!\n";
                exit(1);
            }
            plugboard_file.getline(plug_config, sizeof(plug_config));
        }
    }


    string input;
    string output;
    cin >> ws >>input;

    //Config
    Plugboard *plugboard = new Plugboard();
    vector<int> plug_config_tok = plugboard->tokeniser(plug_config);


    Rotors *rotors = new Rotors();
    vector<int> config[rotor_num + 1];
    if(rotor_num > 0){
        for(int a = 0; a < rotor_num ; a++){
            vector<int> rotor_config_tok = rotors->tokeniser(rotor_config[a]);
            config[a] = rotor_config_tok;
        }
    } else {
        config[0].clear();
    }

    Reflector *reflector = new Reflector();


    for(int c = 0 ; input[c] != '\0'; c++){

        char plug_out = plugboard->find_char_mapped_to(input[c],plug_config_tok);

        char rotor_out = rotors->input_to_front(config,plug_out,rotor_num);

        char reflect_out = reflector->reflect(rotor_out);

        char rotor_back_out = rotors->input_to_back(config,reflect_out, rotor_num);

        output.push_back(plugboard->find_char_mapped_to(rotor_back_out,plug_config_tok));

        //config = rotors->rotate_config(config);

    }


    cout << output;




    return 0;
}
