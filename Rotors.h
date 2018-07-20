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
    char output[100];

public:
    Rotors(char* token);
    int* tokeniser();
    char num_to_char(int num);
    int char_to_num(char c);
    int* map_backward(int* config_map);
    char* input_to_string(int* config, char* input);
    char* input_to_string_back(int* config, char* input);
    char find_char_mapped_to(char letter, int* config);

};


#endif //C_ENIGMA_ROTORS_H
