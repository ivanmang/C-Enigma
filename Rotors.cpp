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


vector<int> Rotors::tokeniser() {
    char* rotor_token = strtok(rotor_config," ");
    int i = 0;
    while(rotor_token){
        config_map[i] = atoi(rotor_token);
        rotor_token = strtok(NULL, " ");
        i++;
    }

    return config_map;
}




vector<int> Rotors::map_backward(vector<int> config_map) {
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

char *Rotors::input_to_string(vector<int> config, char *input) {
    vector<int> rotated_map = config;
    for (int i = 0; input[i] != '\0'; i++) {
        //print_map(rotated_map);
        printf("input[i]: %c\n",input[i]);
        output[i] = find_char_mapped_to(input[i], rotated_map);
        printf("output[i]: %c\n",output[i]);
        //rotated_map = rotate_config(rotated_map);
    }
    return output;
}

char *Rotors::input_to_string_back(vector<int> config, char *input) {
    vector<int> back_config = map_backward(config);
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = find_char_mapped_to(input[i], back_config);
    }
    return output;
}

char Rotors::find_char_mapped_to(char letter, vector<int> config) {
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

vector<int> Rotors::rotate_config(vector<int> config) {
    print_map(rotate_config_map);
    rotate_config_map[0] = config[25];
    for(int i = 1 ;i < 27;i++){
        printf(" i: %d config[i]:%d rotate[i] %d \n",i, config[i],rotate_config_map[i]);
        //printf("fds %d\n",config[5]);
        rotate_config_map[i] = config[i-1];
    }
    print_map(rotate_config_map);
    return rotate_config_map;
}

void Rotors::print_map(vector<int> config) {
    printf("The config is:");
    for (int i = 0; i < 26; i++) {
        printf("%d ",config[i]);
    }
    printf("\n");
}


