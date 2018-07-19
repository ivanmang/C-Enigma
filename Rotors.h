//
// Created by ivan on 7/19/18.
//

#ifndef C_ENIGMA_ROTORS_H
#define C_ENIGMA_ROTORS_H


class Rotors {

private:
    char* config;

public:
    Rotors(char* config);
    void printconfig(char* config);
    char* read_config(char* config);
    char *removeSpaces(char *str);


};


#endif //C_ENIGMA_ROTORS_H
