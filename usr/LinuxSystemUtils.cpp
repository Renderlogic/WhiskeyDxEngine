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
#include <algorithm>
#include <string>
#include <ctype.h>
#include <map>
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
    cout << "Analyzing CPU Information..." << endl;
    if (parseCpuInfo()) {
        assignToHardwareStructure();
    } else {
        cout << "Hardware Check Assignment Failed!";
    }

    cout << "Fishing for BarraCUDAs... \033[1;32m♥ NVIDIA\033[0m" << endl;
    if (cudaCheck()) {
        cout << "Caught a CUDA!";
    } else {
        cout << "No CUDA Luck this time!";
    }
}

/* Stream and Parse /proc/cpuinfo to get a CPU and CORE count and assign to hardwareSystem struct */
bool LinuxSystemUtils::parseCpuInfo() {
    /* File tokens/sentinels for grabbing values during parsing loops. */
    size_t pos = 0;
    /* @todo: move this literal definition outside the class implementation and set this property externally from main or via input args. */
    string delimiter = ":";
    string currentToken;
    string currentLine;
    int numOfProcessingUnits = 0;
    /* Open the cpuinfo file and parse then assign values to a property than process into hardwareSystem struct via init. This a multipart method broken down below */
    /* Because the cpuinfo file doesn't explicitly tell us about hyperthreading and thus must derive this based on a variety of factors 
     * I have to break everything down into usable integers to perform calculations and be flexible for varying hardware setups.
     */
    ifstream CpuInfoFile(this->cpu_info_file_path);
    if (CpuInfoFile.is_open()) {
        /* Here I loop through the entire file once to gather the total number of Processing Units listed. */
        while (getline(CpuInfoFile, currentLine)) {
            while ((pos = currentLine.find(delimiter)) != string::npos) {
                currentToken = currentLine.substr(0, pos);
                currentLine.erase(0, pos + delimiter.length());
            }
            trimDirty(currentToken);
            if (currentToken == this->cpu_info_tokens[0]) {
                numOfProcessingUnits++;
            }
        }
        /* Below I create an array of X size based on two factors: the number of processing units in the file and the number of properties I wish
         * to count from the cpuinfo file -> i.e. the this->cpu_info_tokens to adjust this simply add a new entry to the mapping utilizing the trimDirty 
         * output standard.
         */
        int parsingTokenSize = this->cpu_info_tokens.size();
        int numOfElements = (numOfProcessingUnits * parsingTokenSize);
        this->numOfElements = numOfElements;
        int assignedIndex = 0;
        CpuInfoFile.clear();
        CpuInfoFile.seekg(0, ios::beg);
        while (getline(CpuInfoFile, currentLine)) {
            while ((pos = currentLine.find(delimiter)) != string::npos) {
                currentToken = currentLine.substr(0, pos);
                currentLine.erase(0, pos + delimiter.length());
            }
            trimDirty(currentToken);
            for (int i = 0; i < this->cpu_info_tokens.size(); i++) {
                /* In here I loop through the CpuInfoTokens looking for the values I wish to obtain 
                 * and assign them into their proper array element via the assignedIndex variable.
                 * This is relying heavily upon the format of this document in a top-down style. 
                 * i.e. the this->cpu_info_tokens should match the order of the file being parsed on the system.
                 */

                if (currentToken == this->cpu_info_tokens[i]) {
                    this->unitPropertyCounts[assignedIndex] = stoi(currentLine);
                    assignedIndex++;
                }
            }
        }
        CpuInfoFile.close();
        /* Ensure the assignment went A ok.*/
        if ((assignedIndex) == numOfElements) {
            cout << "All CPU Tokens have been assigned." << endl;
            return true;
        } else {
            return false;
        }

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

void LinuxSystemUtils::assignToHardwareStructure() {
    int parsingTokenSize = this->cpu_info_tokens.size();
    int currentModResult;
    for (int i = 1; i < this->numOfElements; i++) {
        currentModResult = parsingTokenSize % i;
        if (currentModResult == 0 || currentModResult == parsingTokenSize) {
            // we are beginning a new processing unit in the structure.
        }
    }
}