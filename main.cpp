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
    
    
    cout << "Welcome to the WhiskeyDxEngine Proof of Concept Version" << endl;
    cout << "Copyright (C) 2019 Renderlogic, Inc. GPLv3" << endl;
    cout << "=========================================================================" << endl;
    cout << 
    "This program is free software: you can redistribute it and/or modify\n"
    "it under the terms of the GNU General Public License as published by\n"
    "the Free Software Foundation, either version 3 of the License, or\n"
    "(at your option) any later version.\n"
    "\n"
    "This program is distributed in the hope that it will be useful,\n"
    "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
    "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
    "GNU General Public License for more details.\n"
    "\n"
    "You should have received a copy of the GNU General Public License\n"
    "along with this program.  If not, see <https://www.gnu.org/licenses/>." << endl;
    cout << "=========================================================================" << endl;
    cout << endl;
    LinuxSystemUtils SystemUtils;
    // make call to ICD 'restful' URI if needed - i.e. pull most recent additions etc -- maybe to hash comparison
    // parse recent 38 CRF C data (not needed VA should be using ICD-10 and appending military subset
    // store results
    // make translation class/table for ICD->VA Diagnostics
    // pull over patient data from VistA - enumerate existing Diagnostic 
    return 0;
}



void trimDirty(string &dirtyString) {
    for (unsigned int i = 0; i < dirtyString.length(); i++) {
        if (!isalpha(dirtyString[i]) || isdigit(dirtyString[i])) {
            dirtyString.erase(i, 1);
        }
    }
}