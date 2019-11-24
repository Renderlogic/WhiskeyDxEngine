/* 
 * File:   ArgRouter.cpp
 * Author: pdarkstone
 * 
 * Created on September 21, 2019, 1:30 PM
 */
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <map>
#include "ArgRouter.h"

using namespace std;

void ArgRouter::Route(int argCount, char **argVector) {
    for (int i = 1; i < argCount; i++) {
        if (argVector[i] == "skipCuda") {
            this->skipHardwareSubsystem = true;
        }
    }
}