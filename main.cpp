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
#include "usr/LinuxSystemUtils.h"
#include "lib/ArgRouter.h"

/* Create structure for storing results from analyzing the hardware configuration of the current nix machine 
 for various uses throughout the application. Properties are declared to default values on the assumption the luxury
 hardware peripherals are a figment of our imagination. Could class it out but a simple tribute back to C "OOP" was inline. */
struct hardwareSystem {
    unsigned int coreCount{0};
    unsigned int cpuCount{0};
    bool isHyperthreaded{false};
    bool cudaEnabled{false};
};
void printGnuLicenseStatement();
void checkHardwareSubsystem();
using namespace std;

/*
 * 
 */
int main(int argc, char **argv) {
    ArgRouter Router;
    if (argc > 1) {
        Router.Route(argc, argv);
    }
    printGnuLicenseStatement();
    if (Router.skipHardwareSubsystem == false) {
        checkHardwareSubsystem();
    }

    /* @todo
     1. Make call to ICD 'restful' URI if needed - i.e. pull most recent additions etc -- maybe to hash comparison.
     2. Parse recent 38 CRF C data (not needed VA should be using ICD-10 and appending military subset. See ICD text.
     3. Store results.
     4. Make translation class/table for ICD->VA Diagnostics.
     5. Pull over patient data from VistA - enumerate existing Dxs. 
     */

    return 0;
}

void printGnuLicenseStatement() {
    /* Print GNU public license jargon requirement. */
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
}

void checkHardwareSubsystem() {
#ifdef __linux__ 
    /* define our parsing tokens */
    map<int, string> cpu_info_tokens{
        {0, "processor"},
        {1, "physicalid"},
        {2, "siblings"},
        {3, "coreid"},
        {4, "cpucores"}};
    LinuxSystemUtils SystemUtils;
    SystemUtils.cpu_info_file_path = "/proc/cpuinfo";
    SystemUtils.cpu_info_tokens = cpu_info_tokens;
    hardwareSystem *pThisSystem, thisSystem;
    pThisSystem = &thisSystem;
    SystemUtils.initialize(pThisSystem);
    SystemUtils.getHardwareSystemAddress();
#elif _WIN32
    cout << "Skipping windows machines for now." << endl;
#else
    cout << "Skipped Hardware Check." << endl;
#endif
}
