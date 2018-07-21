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
                back_config_map[i] = j;
            }
        }
    }
    return back_config_map;
}

char Rotors::num_to_char(int num) {
    return (char) 65 + num;
}

int Rotors::char_to_num(char c) {
    return (int) c - 65;
}

char *Rotors::input_to_string(int *config, char *input) {
    int* rotated_map = config;
    for (int i = 0; input[i] != '\0'; i++) {
        int map[26];
        print_map(rotated_map);
        printf("input[i]: %c\n",input[i]);
        output[i] = find_char_mapped_to(input[i], rotated_map);
        printf("output[i]: %c\n",output[i]);
        rotated_map = rotate_config(rotated_map,map);
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
    //printf("char index %d\n",char_index);
    //Get the letter it mapped to
    for(int i = 0; i < 26 ;i++){
        if(char_index == i){
            //printf("config[i] %d \n",config[i]);
            return num_to_char(config[i]);
        }
    }
}

int *Rotors::rotate_config(int *config, int* map) {
    print_map(map);
    for(int i = 0 ;i < 26;i++){
        map[i+1] = config[i];
        printf(" i: %d config[i]:%d map[i] %d \n",i, config[i],map[i]);
    }
    map[0] = config[25];
    print_map(map);
    return map;
}

void Rotors::print_map(int *config) {
    printf("The config is:");
    for (int i = 0; i < 26; i++) {
        printf("%d ",config[i]);
    }
    printf("\n");
}


