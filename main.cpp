/* 
 * File:   main.cpp
 * Author: johnjmcdonnell
 *
 * Created on September 2, 2019, 11:25 PM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <map>
#include "LinuxSystemUtils.h"

/* Create structure for storing results from analyzing the hardware configuration of the current nix machine 
 for various uses throughout the application. Properties are declared to default values on the assumption the luxury
 hardware peripherals are a figment of our imagination. Could class it out but a simple tribute back to C "OOP" was inline. */
struct hardwareSystem {
    unsigned int coreCount{0};
    unsigned int cpuCount{0};
    bool isHyperthreaded{false};
    bool cudaEnabled{false};
};

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    /* Begin GNU public license jargon requirement. */
    cout << "Welcome to the \033[1;31mWhiskeyDxEngine\033[0m Proof of Concept Version." << endl;
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

    /* Create an instance of the hardware system structure and populate with system specifications. */
    LinuxSystemUtils SystemUtils;
    hardwareSystem *pThisSystem, thisSystem;
    pThisSystem = &thisSystem;
    SystemUtils.initialize(pThisSystem);
    SystemUtils.getHardwareSystemAddress();


    /* @todo
     1. Make call to ICD 'restful' URI if needed - i.e. pull most recent additions etc -- maybe to hash comparison.
     2. Parse recent 38 CRF C data (not needed VA should be using ICD-10 and appending military subset. See ICD text.
     3. Store results.
     4. Make translation class/table for ICD->VA Diagnostics.
     5. Pull over patient data from VistA - enumerate existing Dxs. 
     */

    return 0;
}

