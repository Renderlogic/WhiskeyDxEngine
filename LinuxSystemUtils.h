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
    /* pointer to the hardware system profile data structure in main global space for use within this class */
    struct hardwareSystem *pSystemMemAddress;
    /**
     * 
     * @return memory address aka pointer to the hardware system profile data structure
     */
    struct hardwareSystem* getHardwareSystemAddress();
    /**
     * Will call all necessary methods for the SystemUtils object and populate the hardwareSystem structure
     * @param pThisSystem entry point to pass hardwareSystem aka hardware profile structure mem address to this instance.
     */
    void initialize(struct hardwareSystem *pThisSystem);
    /**
     Check for and analyze all possible resources to detect a CUDA enabled card and return true if found false if not
     * assign to hardwareSystem cudaEnabled property
     * @return 
     */
    bool cudaCheck();
    void analyzeCpu();
protected:
private:
    string CPU_INFO_FILE_PATH;
    void trimDirty(string &dirtyString);
};
#endif /* LINUXSYSTEMUTILS_H */

