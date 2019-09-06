/*
 * This software is merely a proof of concept.
 */

/* 
 * File:   LinuxSystemUtils.h
 * Author: Renderlogic, Inc.
 *
 * Created on September 3, 2019, 4:48 PM
 */
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

#ifndef LINUXSYSTEMUTILS_H
#define LINUXSYSTEMUTILS_H
using namespace std;

class LinuxSystemUtils {
public:
    LinuxSystemUtils();
    bool cudaCheck();
    bool checkForHyperthreading();
    unsigned int getCpuCount();
    unsigned int getCoreCount();
protected:
    
private:
    string CPU_INFO_FILE_PATH;
    bool CUDA_ENABLED;
};

#endif /* LINUXSYSTEMUTILS_H */

