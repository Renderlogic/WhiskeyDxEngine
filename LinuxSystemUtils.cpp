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
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include "LinuxSystemUtils.h"


using namespace std;

LinuxSystemUtils::LinuxSystemUtils() {
    cout << "Initializing Linux System Utilities" << endl;
    cout << "Setting CPU Information File Path" << endl;
    CPU_INFO_FILE_PATH = "/proc/cpuinfo";
    cout << "Fishing for BarraCUDAs... ♥ NVIDIA" << endl;
    if (cudaCheck()) {
        CUDA_ENABLED = true;
    } else {
        CUDA_ENABLED = false;
    }
}


// Stream and Parse /proc/cpuinfo to get a CPU and CORE count

unsigned int LinuxSystemUtils::getCpuCount() {
    string line;
    string cpuLabel = "physical id" + '\t';
    string coresLabel = "cpu cores" + '\t';
    string delimiter = ":";
    cout << "2. Evaluating Processor Capabilities..." << endl;
    ifstream CpuInfoFile;
    return 0;
}

bool LinuxSystemUtils::cudaCheck() {
    return false;
}
