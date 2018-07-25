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
    vector<int>::iterator num;
    for(int i = 0; i < config_map.size(); i++){
        num = find(config_map.begin(),config_map.end(), i);
        if(num != config_map.end()){
            int index = distance(config_map.begin(),num);
            back_map.push_back(index);
        }else{
            cerr << "Missing elements when rotor map backwards";
        }
    }
    //printf("Back map:\n");
    //print_map(back_map);
    //printf("\n\n");
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
        //printf("\n\n");
        //print_map(config[i]);
        vector<int> temp = config[i];
        back_config[i] = map_backward(temp);
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

vector<int>* Rotors::rotate_config(vector<int>* config, int rotor_num) {
    if(config[0].empty()){
        return config;
    }
    vector<int>::iterator it;
    int rotor = 0;
    if(rotor_num>1){
        int next_rotor = rotor + 1;
        it = config[next_rotor].begin();
        int first_elem1 = config[next_rotor].front();
        config[next_rotor].erase(it,it+1);
        config[next_rotor].push_back(first_elem1);
        if(rotate_time == 25){
            int next_rotor1 = rotor + 1;
            it = config[next_rotor1].begin();
            int first_elem2 = config[next_rotor1].front();
            config[next_rotor1].erase(it,it+1);
            config[next_rotor1].push_back(first_elem2);
        }
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


