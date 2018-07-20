//
// Created by ivan on 7/20/18.
//

#include <cstdio>
#include "Reflector.h"


int* Reflector::reflect(int *config_map) {
    for(int i  =0;i<26;i++){
        config_map[i] = (i+13)%26;
        //printf("%d ",config_map[i]);
    }
    return 0;
}

Reflector::Reflector() {

}
