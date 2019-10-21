/* 
 * File:   ArgRouter.h
 * Author: pdarkstone
 *
 * Created on September 21, 2019, 1:30 PM
 */

#ifndef ARGROUTER_H
#define ARGROUTER_H
#include <string>
using namespace std;

class ArgRouter {
public:
    bool skipHardwareSubsystem = false;
    void Route(int argCount, char** argVector);
};
#endif /* ARGROUTER_H */

