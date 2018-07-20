//
// Created by ivan on 7/20/18.
//

#ifndef C_ENIGMA_PLUGBOARD_H
#define C_ENIGMA_PLUGBOARD_H


class Plugboard {
private:
    char* plug_config;
    int config_map[26];
    char output[100];
public:
    Plugboard(char* plug_config);
    int* tokeniser();
    char num_to_char(int num);
    int char_to_num(char c);
    char* input_to_string(int* config, char* input);
    char find_char_mapped_to(char letter, int* config);
    int find_if_config_contain(int char_index, int* config);
};


#endif //C_ENIGMA_PLUGBOARD_H
