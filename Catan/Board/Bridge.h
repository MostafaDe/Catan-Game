//
// Created by apadana on ۰۳/۰۷/۲۰۲۱.
//

#ifndef SETTINGUPGOOGLETEST_BRIDGE_H
#define SETTINGUPGOOGLETEST_BRIDGE_H

#include "RoadABridge.h"
class Bridge : private RoadABridge{
public:
    int  Bridge::getPostion() const ;

    void  Bridge::setPostion(int postion) ;
};


#endif //SETTINGUPGOOGLETEST_BRIDGE_H
