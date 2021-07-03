//
// Created by apadana on ۰۳/۰۷/۲۰۲۱.
//

#ifndef SETTINGUPGOOGLETEST_BOARD1_H
#define SETTINGUPGOOGLETEST_BOARD1_H
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Board.h"
class Board1 : private Board  {
public:
    void setRandomNumberToLands() ;

     bool BuildHouse(int postion);
    bool BuildRoad(int postion );
    bool BuilBigCity(int postion);
    bool BuildTown(int postion);
     bool BuildBridge(int postion);
    vector<map<Color,int>> calculateScore(int SumOfDices) ;

};


#endif //SETTINGUPGOOGLETEST_BOARD1_H
