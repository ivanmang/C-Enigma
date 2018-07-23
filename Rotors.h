//
// Created by ivan on 7/19/18.
//

#ifndef C_ENIGMA_ROTORS_H
#define C_ENIGMA_ROTORS_H

#include <vector>
using namespace std;

class Rotors {

private:
    vector<int> config_map;
    vector<int> back_map;
    char output[100];

public:
    Rotors();
    vector<int> tokeniser(char* rotor_config);
    char num_to_char(int num);
    int char_to_num(char c);
    vector<int> map_backward(vector<int> config_map);
    char* input_to_string(vector<int> config, char* input);
    char* input_to_string_back(vector<int> config, char* input);
    char find_char_mapped_to(char letter, vector<int> config);
    vector<int> rotate_config(vector<int> config);
    void print_map(vector<int> config);

};


#endif //C_ENIGMA_ROTORS_H
