// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Rotors.h"

using namespace std;

int main(int argc, char **argv) {
    fstream infile;
    char config[100];
    string dir = "./";

    int i = 1;
    for (i; i < argc - 1; i++) {
        string dir1 = dir+argv[i];
        infile.open(dir1,ios::in);
        if (!infile) {
            cerr << "Can't open file!\n";
            exit(1);
        }
    }
    infile.getline(config, sizeof(config));
    char* token = strtok(config," ");

    Rotors *rotors = new Rotors(token);
    rotors->store_config();


    return 0;
}
