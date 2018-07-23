//
// Created by ivan on 7/20/18.
//

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include "Plugboard.h"

Plugboard::Plugboard() {
}


vector<int> Plugboard::tokeniser(char* rotor_config) {
    char* rotor_token = strtok(rotor_config," ");
    int i = 0;
    while(rotor_token){
        config_map.push_back(atoi(rotor_token));
        rotor_token = strtok(NULL, " ");
        i++;
    }
    return config_map;
}


char Plugboard::num_to_char(int num) {
    return (char) 65 + num;
}

int Plugboard::char_to_num(char c) {
    return (int) c - 65;
}


char Plugboard::find_char_mapped_to(char input, vector<int> config) {
    //Find the position of the letter
    int char_index = char_to_num(input);
    //Get the letter it mapped to
    int mapped_char = find_if_config_contain(char_index,config);
    if(mapped_char != NULL){
        return num_to_char(mapped_char);
    } else{
        //if this letter don't map to anything, return original letter
        return input;
    }
}


int Plugboard::find_if_config_contain(int char_index, vector<int> config) {
    for(int i = 0; i < config.size() ; i+=2){
        int first = config.at(i);
        int second = config.at(i+1);
        //printf("config %d %d\n",config.at(i),  config.at(i+1));
        if(first == char_index){
            return second;
        } else if(second == char_index){
            return first;
        }
    }
    return NULL;
}



