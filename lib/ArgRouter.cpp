/* 
 * File:   ArgRouter.cpp
 * Author: pdarkstone
 * 
 * Created on September 21, 2019, 1:30 PM
 */

#include "ArgRouter.h"

void ArgRouter::Route(int argCount, char** argVector) {
    for (int i = 1; i < count(argVector); i++) {
        if (argVector[i] == "skipCuda") {
            ArgRouter.skipHardwareSubsystem = true;
        }
    }
}