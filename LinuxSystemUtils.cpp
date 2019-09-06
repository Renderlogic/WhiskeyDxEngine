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
    this->CPU_INFO_FILE_PATH = "/proc/cpuinfo";
    cout << "Fishing for BarraCUDAs... ♥ NVIDIA" << endl;
    if (cudaCheck()) {
        cout << "Caught a CUDA!";
    } else {
        cout << "No CUDA Luck this time!";
    }
}


// Stream and Parse /proc/cpuinfo to get a CPU and CORE count

unsigned int LinuxSystemUtils::getCpuCount() {
    string line;
    string cpuLabel = "physical id" + '\t';
    string coresLabel = "cpu cores" + '\t';
    string siblingsLabel = "siblings" + '\t';
    string delimiter = ":";
    cout << "2. Evaluating Processor Capabilities..." << endl;
    ifstream CpuInfoFile;
    // check the CpuInfoFile and calculate the amount of cores threads and physical processors
    // done by evaluating the various values provided by different parameters such as core IDs processor IDs (can be a physical CPU, thread (hyperthread) or core) i.e.
    // processing unit not actual CPU -> evaluate siblings for dependency accuracy from this file.
    return 0;
}

bool LinuxSystemUtils::cudaCheck() {
    this->CUDA_ENABLED = false;
    // dive into driver details or try and run system("nvidia-smi") output as XML and parse for existing cuda_version parameter and set flag.
    return this->CUDA_ENABLED;
}
