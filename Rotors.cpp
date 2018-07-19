//
// Created by ivan on 7/19/18.
//

#include <stdexcept>
#include "Rotors.h"
#include <iostream>

char *config;

Rotors::Rotors(char *config) {
    this->config = config;
}

char config_map[26];

void Rotors::printconfig(char *config) {
    removeSpaces(config);
    printf("%s\n",config);
    printf("%d",'A'+1);
}

char* Rotors::read_config(char *config) {
    int i = 0, j = 0;
    while (config[i]){
        if(config[i] != ' '){
            if(config[i+1] != ' '){
                config_map[i] = config[i];
            }
        }
        i++;
    }
    return config_map;
}

char *Rotors::removeSpaces(char *str) {
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
    return str;
}
