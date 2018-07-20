//
// Created by ivan on 7/20/18.
//

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Plugboard.h"

Plugboard::Plugboard(char *plug_config) {
    this->plug_config = plug_config;
}


int* Plugboard::tokeniser() {
    char* plug_token = strtok(plug_config," ");
    int i = 0;
    while(plug_token){
        config_map[i] = atoi(plug_token);
        plug_token = strtok(NULL, " ");
        i++;
    }

    return config_map;
}

int *Plugboard::map(int *config_map, int* map) {
    for(int i = 0; i < config_map[i] != '\0'; i+=2){
        int first = config_map[i];
        int second = config_map[i+1];
        map[first] = second;
        map[second] = first;
    }
}

void Plugboard::init() {
    for(int i = 0; i<26;i++){
        char_map[i] = i;
    }
}

char Plugboard::num_to_char(int num) {
    return (char) 65 + num;
}



