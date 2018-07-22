//
// Created by ivan on 7/20/18.
//

#ifndef C_ENIGMA_PLUGBOARD_H
#define C_ENIGMA_PLUGBOARD_H


#include <vector>
using namespace std;

class Plugboard {
private:
    char* plug_config;
    vector<int> config_map;
    char output[100];
public:
    Plugboard(char* plug_config);
    std::vector<int> tokeniser();
    char num_to_char(int num);
    int char_to_num(char c);
    char* input_to_string(vector<int> config, char* input);
    char find_char_mapped_to(char letter, vector<int> config);
    int find_if_config_contain(int char_index, vector<int> config);
};


#endif //C_ENIGMA_PLUGBOARD_H
