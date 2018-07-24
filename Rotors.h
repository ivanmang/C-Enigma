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
    int rotate_time = 0;

public:
    Rotors();
    vector<int> tokeniser(char* rotor_config);
    char num_to_char(int num);
    int char_to_num(char c);
    vector<int> map_backward(vector<int> config_map);
    char input_to_front(vector<int>* config, char input ,int rotor_num);
    char input_to_back(vector<int>* config, char input, int rotor_num);
    char find_char_mapped_to(char letter, vector<int> config);
    vector<int>* rotate_config(vector<int>* config);
    void print_map(vector<int> config);

};


#endif //C_ENIGMA_ROTORS_H
