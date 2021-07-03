//
// Created by apadana on ۰۳/۰۷/۲۰۲۱.
//

#ifndef SETTINGUPGOOGLETEST_ROADABRIDGE_H
#define SETTINGUPGOOGLETEST_ROADABRIDGE_H

#include "Building.h"
class RoadABridge : private Building {
public:
    virtual int  RoadABridge::getPostion() const = 0;

    virtual void  RoadABridge::setPostion(int postion) = 0;
};


#endif //SETTINGUPGOOGLETEST_ROADABRIDGE_H
