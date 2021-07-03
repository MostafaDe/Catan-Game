//
// Created by apadana on ۰۳/۰۷/۲۰۲۱.
//

#ifndef SETTINGUPGOOGLETEST_TOWN_H
#define SETTINGUPGOOGLETEST_TOWN_H

#include "Building.h"
class Town : private Building{
public:
    int  Town::getPostion() const ;

    void  Town::setPostion(int postion) ;
};


#endif //SETTINGUPGOOGLETEST_TOWN_H
