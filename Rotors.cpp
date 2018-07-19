//
// Created by ivan on 7/19/18.
//

#include <stdexcept>
#include "Rotors.h"
#include <iostream>
#include <cstring>

Rotors::Rotors(char *token) {
    this->token = token;
}

int config_map[25];
int new_config_map[25];

int* Rotors::store_config() {
    int i = 0;
    while(token){
        config_map[i] = atoi(token);
        token = strtok(NULL, " ");
    }
    return config_map;
}

int *Rotors::map_forward(int *config_map) {
    return config_map;
}

int *Rotors::map_backward(int *config_map) {
    for(int i = 0; i <25 ; i++){
        new_config_map[config_map[i]] = i;
    }
    return new_config_map;
}
