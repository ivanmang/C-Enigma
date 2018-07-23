//
// Created by ivan on 7/19/18.
//

#include <stdexcept>
#include "Rotors.h"
#include <iostream>
#include <cstring>
#include <iterator>
#include <algorithm>

using namespace std;


Rotors::Rotors() {
}


vector<int> Rotors::tokeniser(char* rotor_config) {
    char* rotor_token = strtok(rotor_config," ");
    int i = 0;
    while(rotor_token){
        config_map.push_back(atoi(rotor_token));
        rotor_token = strtok(NULL, " ");
        i++;
    }
    return config_map;
}




vector<int> Rotors::map_backward(vector<int> config_map) {
    if(config_map.empty()){
        return config_map;
    }
    back_map.clear();
    for(int i = 0; i < config_map.size(); i++){
        vector<int>::iterator num = find(config_map.begin(),config_map.end(), i);
        if(num != config_map.end()){
            int index = distance(config_map.begin(),num);
            back_map.push_back(index);
        }else{
            cerr << "Missing elements when rotor map backwards";
        }

    }
    //print_map(back_map);
    return back_map;
}

char Rotors::num_to_char(int num) {
    return (char) 65 + num;
}

int Rotors::char_to_num(char c) {
    return (int) c - 65;
}

char *Rotors::input_to_string(vector<int> config, char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        //print_map(rotated_map);
        //printf("input[i]: %c\n",input[i]);
        output[i] = find_char_mapped_to(input[i], config);
        //printf("output[i]: %c\n",output[i]);
        //config = rotate_config(config);
    }
    return output;
}

char Rotors::input_to_back(vector<int> config, char input) {
    vector<int> back_config = map_backward(config);
    return find_char_mapped_to(input, back_config);
}

char Rotors::find_char_mapped_to(char letter, vector<int> config) {
    if(config.empty()){
        return letter;
    }
    //Find the position of the letter
    int char_index = char_to_num(letter);
    //printf("char index %d\n",char_index);
    //Get the letter it mapped to
    for(int i = 0; i < config.size() ;i++){
        if(char_index == i){
            //printf("config[i] %d \n",config.at(i));
            return num_to_char(config.at(i));
        }
    }
}

vector<int> Rotors::rotate_config(vector<int> config) {
    if(config.empty()){
        return config;
    }
    vector<int>::iterator it;
    it = config.begin();
    int last_elem = config.back();
    config.pop_back();
    config.insert(it,last_elem);
    return config;
}

void Rotors::print_map(vector<int> config) {
    printf("The config is:");
    for (int i = 0; i < config.size(); i++) {
        printf("%d ",config.at(i));
    }
    printf("\n");
}


