/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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

LinuxSystemUtils::LinuxSystemUtils() {
    cout << "Initializing Linux System Utilities" << endl;
    cout << "Analyzing CPU information..." << endl;
    this->CPU_INFO_FILE_PATH = "/proc/cpuinfo";
    analyzeCpu();
    cout << "Fishing for BarraCUDAs... ♥ NVIDIA" << endl;
    if (cudaCheck()) {
        cout << "Caught a CUDA!";
    } else {
        cout << "No CUDA Luck this time!";
    }
}

// Stream and Parse /proc/cpuinfo to get a CPU and CORE count

void LinuxSystemUtils::analyzeCpu() {
    size_t pos = 0;
    string info;
    string physicalLabel = "physicalid";
    string coresLabel = "cpucores";
    string siblingsLabel = "siblings";
    string delimiter = ":";
    string label;
    ifstream CpuInfoFile(this->CPU_INFO_FILE_PATH);
    if (CpuInfoFile.is_open()) {
        cout << "Examining cpuinfo" << endl;
        while (getline(CpuInfoFile, info)) {
            while ((pos = info.find(delimiter)) != string::npos) {
                label = info.substr(0, pos);
                info.erase(0, pos + delimiter.length());
            }
            trimDirty(label);
            if (label.compare(siblingsLabel) == 0) {
                cout << "Found the siblings";
            }
            if (label.compare(coresLabel) == 0) {
                cout << "Found the siblings";
            }
        }
        CpuInfoFile.close();
    }
    return 0;
}

bool LinuxSystemUtils::cudaCheck() {
    // dive into driver details or try and run system("nvidia-smi") output as XML and parse for existing cuda_version parameter and set flag.
    return false;
}

void LinuxSystemUtils::trimDirty(string &dirtyString) {
    for (unsigned int i = 0; i < dirtyString.length(); i++) {
        if (!isalpha(dirtyString[i]) || isdigit(dirtyString[i])) {
            dirtyString.erase(i, 1);
            dirtyString.erase(remove(dirtyString.begin(), dirtyString.end(), '\t'), dirtyString.end());
        }
    }
}