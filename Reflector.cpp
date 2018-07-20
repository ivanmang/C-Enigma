//
// Created by ivan on 7/20/18.
//

#include <cstdio>
#include "Reflector.h"

Reflector::Reflector() {

}

char* Reflector::reflect(char* input) {
    for(int i =0;input[i]!='\0';i++){
        int char_index = char_to_num(input[i]);
        int mapped_num = (char_index+13)%26;
        output[i] = num_to_char(mapped_num);
    }
    return output;
}



char Reflector::num_to_char(int num) {
    return (char) 65 + num;
}

int Reflector::char_to_num(char c) {
    return (int) c - 65;
}
