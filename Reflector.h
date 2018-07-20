//
// Created by ivan on 7/20/18.
//

#ifndef C_ENIGMA_REFLECTOR_H
#define C_ENIGMA_REFLECTOR_H


class Reflector {

private:
    char output[100];


public:
    Reflector();
    char* reflect(char* input);
    char num_to_char(int num);
    int char_to_num(char c);
};


#endif //C_ENIGMA_REFLECTOR_H
