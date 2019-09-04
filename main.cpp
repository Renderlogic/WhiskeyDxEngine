/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: johnjmcdonnell
 *
 * Created on September 2, 2019, 11:25 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include "LinuxSystemUtils.h"

using namespace std;
void trimDirty(string &dirtyString);

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    return 0;
}



void trimDirty(string &dirtyString) {
    for (unsigned int i = 0; i < dirtyString.length(); i++) {
        if (!isalpha(dirtyString[i]) || isdigit(dirtyString[i])) {
            dirtyString.erase(i, 1);
        }
    }
}