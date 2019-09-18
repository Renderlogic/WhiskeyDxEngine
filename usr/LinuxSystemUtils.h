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
#include <map>
#include <ctype.h>

#ifndef LINUXSYSTEMUTILS_H
#define LINUXSYSTEMUTILS_H
using namespace std;

class LinuxSystemUtils {
public:
    string cpu_info_file_path;
    map<int, string> cpu_info_tokens;
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
    void parseCpuInfo();
protected:
private:
    void trimDirty(string &dirtyString);
    void setUnitPropertyCounts(int[]);
    void assignToHardwareStructure();
    /* @todo Add padding to protect this from an overflow attack since the size is variable and depends on user input from the main tokens map.
    /* However, since we already know the numOfElements required we can simply fix the size to 20 elements and the operation is bounded to the memory scope. 
     * To unbound this to scale dynamically according to tokens just remove the fixed 20 int literal.
     */
    int unitPropertyCounts[20]; 
};
#endif /* LINUXSYSTEMUTILS_H */

