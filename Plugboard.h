//
// Created by ivan on 7/20/18.
//

#ifndef C_ENIGMA_PLUGBOARD_H
#define C_ENIGMA_PLUGBOARD_H


class Plugboard {
private:
    char* plug_config;
    int config_map[26];
    int char_map[26];
public:
    Plugboard(char* plug_config);
    int* map(int* config_map, int* map);
    int* tokeniser();
    void init();
    char num_to_char(int num);
};


#endif //C_ENIGMA_PLUGBOARD_H
