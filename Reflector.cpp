//
// Created by ivan on 7/20/18.
//

#include <cstdio>
#include "Reflector.h"

Reflector::Reflector() {

}

char Reflector::reflect(char input) {
        int char_index = char_to_num(input);
        int mapped_num = (char_index+13)%26;
    return num_to_char(mapped_num);
}



char Reflector::num_to_char(int num) {
    return (char) 65 + num;
}

int Reflector::char_to_num(char c) {
    return (int) c - 65;
}
