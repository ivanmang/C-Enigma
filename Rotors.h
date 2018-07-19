//
// Created by ivan on 7/19/18.
//

#ifndef C_ENIGMA_ROTORS_H
#define C_ENIGMA_ROTORS_H


class Rotors {

private:
    char* token;

public:
    Rotors(char* token);
    int* store_config();
    int* map_forward(int* config_map);
    int* map_backward(int* config_map);

};


#endif //C_ENIGMA_ROTORS_H
