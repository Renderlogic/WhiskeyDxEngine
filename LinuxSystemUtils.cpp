/* 
 * File:   LinuxSystemUtils.cpp
 * Author: Renderlogic, Inc.
 * 
 * Created on September 3, 2019, 4:49 PM
 */

#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include "LinuxSystemUtils.h"
using namespace std;

/**
 * Initializes all the machine variables by calling respective methods
 * @param pThisSystem pointer to mains hardwareSystem thisSystem profile for decision branching
 */
void LinuxSystemUtils::initialize(struct hardwareSystem *pThisSystem) {
    cout << "Assigning Hardware Profile Structure Memory Address" << endl;
    this->pSystemMemAddress = pThisSystem;
    cout << "Initializing Linux System Utilities" << endl;
    cout << "Analyzing CPU information..." << endl;
    this->CPU_INFO_FILE_PATH = "/proc/cpuinfo";
    analyzeCpu();
    cout << "Fishing for BarraCUDAs... \033[1;32m♥ NVIDIA\033[0m" << endl;
    if (cudaCheck()) {
        cout << "Caught a CUDA!";
    } else {
        cout << "No CUDA Luck this time!";
    }
}

/* Stream and Parse /proc/cpuinfo to get a CPU and CORE count and assign to hardwareSystem struct */
void LinuxSystemUtils::analyzeCpu() {
    /* File tokens/sentinels for grabbing values during parsing loops. */
    size_t pos = 0;
    string info;
    string physicalLabel = "physicalid";
    string coresLabel = "cpucores";
    string siblingsLabel = "siblings";
    string delimiter = ":";
    string label;
    /* Open the cpuinfo file and get and assign values to the hardwareSystem struct. */
    ifstream CpuInfoFile(this->CPU_INFO_FILE_PATH);
    if (CpuInfoFile.is_open()) {
        while (getline(CpuInfoFile, info)) {
            while ((pos = info.find(delimiter)) != string::npos) {
                label = info.substr(0, pos);
                info.erase(0, pos + delimiter.length());
            }
            trimDirty(label);
            if (label.compare(siblingsLabel) == 0) {

            }
            if (label.compare(coresLabel) == 0) {

            }
            if (label.compare(physicalLabel) == 0) {

            }
        }
        CpuInfoFile.close();
    }
}

bool LinuxSystemUtils::cudaCheck() {
    /* @todo Dive into driver details or try and run system("nvidia-smi") output as XML and parse for existing cuda_version parameter and set flag. */
    return false;
}

struct hardwareSystem* LinuxSystemUtils::getHardwareSystemAddress() {
    cout << endl << "System Profile Data Structure Memory Address: " << this->pSystemMemAddress << endl;
    return this->pSystemMemAddress;
}

void LinuxSystemUtils::trimDirty(string &dirtyString) {
    for (unsigned int i = 0; i < dirtyString.length(); i++) {
        if (!isalpha(dirtyString[i]) || isdigit(dirtyString[i])) {
            dirtyString.erase(i, 1);
            dirtyString.erase(remove(dirtyString.begin(), dirtyString.end(), '\t'), dirtyString.end());
        }
    }
}