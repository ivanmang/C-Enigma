//
// Created by ivan on 7/19/18.
//

#include <stdexcept>
#include "Rotors.h"
#include <iostream>
#include <cstring>


Rotors::Rotors(char *rotor_config) {
    this->rotor_config = rotor_config;
}


int* Rotors::tokeniser() {
    char* rotor_token = strtok(rotor_config," ");
    int i = 0;
    while(rotor_token){
        config_map[i] = atoi(rotor_token);
        rotor_token = strtok(NULL, " ");
        i++;
    }

    return config_map;
}




int *Rotors::map_backward(int *config_map) {
    for(int i = 0; i <26 ; i++){
        for(int j = 0; j <26; j++){
            if(i == config_map[j]){
                new_config_map[i] = j;
            }
        }
    }
    return new_config_map;
}

char Rotors::num_to_char(int num) {
    return (char) 65 + num;
}

int Rotors::char_to_num(char c) {
    return (int) c - 65;
}

char *Rotors::input_to_string(int *config, char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = find_char_mapped_to(input[i], config);
    }
    return output;
}

char *Rotors::input_to_string_back(int *config, char *input) {
    int* back_config = map_backward(config);
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = find_char_mapped_to(input[i], back_config);
    }
    return output;
}

char Rotors::find_char_mapped_to(char letter, int *config) {
    //Find the position of the letter
    int char_index = char_to_num(letter);
    //Get the letter it mapped to
    for(int i = 0; config[i-1]!='\0';i++){
        if(char_index == i){
            return num_to_char(config[i]);
        }
    }
}
