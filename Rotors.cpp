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

int *Rotors::map_forward(int *config_map) {
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
