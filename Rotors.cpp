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
    config_map.clear();
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
            //cerr << "Missing elements when rotor map backwards";
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

char Rotors::input_to_front(vector<int>* config, char input, int rotor_num) {
    if(config[0].empty()){
        return input;
    }
    char output = input;
    for(int i = 0; i < rotor_num; i++){
        //print_map(config[i]);
        output = find_char_mapped_to(output,config[i]);
    }

    return output;
}

char Rotors::input_to_back(vector<int>* config, char input, int rotor_num) {
    vector<int> back_config[10];
    for(int i = 0; i < rotor_num; i++){
        back_config[i] = map_backward(config[i]);
    }
    char output = input;
    for(int i = 0; i < rotor_num; i++){
        output = find_char_mapped_to(output,back_config[rotor_num-i-1]);
    }

    return output;
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

vector<int>* Rotors::rotate_config(vector<int>* config) {
    if(config[0].empty()){
        return config;
    }
    vector<int>::iterator it;
    int rotor = 0;
    if(rotate_time % 26 == 0 && rotate_time >= 26){
        int next_rotor = rotor + 1;
        it = config[next_rotor].begin();
        int first_elem = config[next_rotor].front();
        config[next_rotor].erase(it,it+1);
        config[next_rotor].push_back(first_elem);
    }
    it = config[rotor].begin();
    int first_elem = config[rotor].front();
    config[rotor].erase(it,it+1);
    config[rotor].push_back(first_elem);
    rotate_time++;
    return config;
}



void Rotors::print_map(vector<int> config) {
    printf("The config is:");
    for (int i = 0; i < config.size(); i++) {
        printf("%d ",config.at(i));
    }
    printf("\n");
}


