//
// Created by ivan on 7/19/18.
//

#ifndef C_ENIGMA_ROTORS_H
#define C_ENIGMA_ROTORS_H


class Rotors {

private:
    char* rotor_config;
    int config_map[26];
    int new_config_map[26];

public:
    Rotors(char* token);
    int* tokeniser();
    int* map_forward(int* config_map);
    int* map_backward(int* config_map);

};


#endif //C_ENIGMA_ROTORS_H
