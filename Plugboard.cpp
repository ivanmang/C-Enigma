//
// Created by ivan on 7/20/18.
//

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include "Plugboard.h"

Plugboard::Plugboard(char *plug_config) {
    this->plug_config = plug_config;
}


std::vector<int> Plugboard::tokeniser() {
    char* plug_token = strtok(plug_config," ");
    int i = 0;
    while(plug_token){
        config_map.push_back(atoi(plug_token));
        plug_token = strtok(NULL, " ");
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

char *Plugboard::input_to_string(vector<int> config, char* input) {
    for(int i = 0; input[i] != '\0' ;i++){
        output[i] = find_char_mapped_to(input[i], config);
    }
    return output;
}

char Plugboard::find_char_mapped_to(char letter, vector<int> config) {
    //Find the position of the letter
    int char_index = char_to_num(letter);
    //Get the letter it mapped to
    int mapped_char = find_if_config_contain(char_index,config);
    if(mapped_char != NULL){
        return num_to_char(mapped_char);
    } else{
        //if this letter don't map to anything, return original letter
        return letter;
    }
}



int Plugboard::find_if_config_contain(int char_index, vector<int> config) {
    for(int i = 0; i < config.size() ; i+=2){
        int first = config[i];
        int second = config[i+1];
        if(first == char_index){
            return second;
        } else if(second == char_index){
            return first;
        }
    }
    return NULL;
}



