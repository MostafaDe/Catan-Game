//
// Created by apadana on ۰۳/۰۷/۲۰۲۱.
//

#ifndef SETTINGUPGOOGLETEST_BOARD_H
#define SETTINGUPGOOGLETEST_BOARD_H

#include <vector>
#include <map>
using namespace std;
#include "UnitOfBoard.h"
#include "Land.h"
#include "Iron.h"

#include "Color.h"
#define SIZE 150
class Board {

public:
    virtual void setRandomNumberToLands() = 0;

    virtual bool BuildHouse(int postion) = 0;
    virtual bool BuildRoad(int postion ) = 0;
    virtual bool BuilBigCity(int postion) =0;
    virtual bool BuildTown(int postion) = 0;
    virtual bool BuildBridge(int postion) = 0;
    virtual vector<map<Color,int>> calculateScore(int SumOfDices) = 0;



protected:
   vector<UnitOfBoard*>  units;
   map<int,Land> randomNumbersToLands;
   bool graphOfUnits[SIZE][SIZE];


};


#endif //SETTINGUPGOOGLETEST_BOARD_H
