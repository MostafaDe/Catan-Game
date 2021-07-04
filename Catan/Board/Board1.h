//
// Created by apadana on ۰۳/۰۷/۲۰۲۱.
//

#ifndef SETTINGUPGOOGLETEST_BOARD1_H
#define SETTINGUPGOOGLETEST_BOARD1_H
#include "Board.h"
class Board1 : private Board  {
public:
    void setRandomNumberToLands() ;

     //bool BuildHouse(int postion,Color color);
    bool BuildRoad(int postion ,Color color);
    bool BuilBigCity(int postion,Color color);
    bool BuildTown(int postion,Color color);
     bool BuildBridge(int postion,Color color);
    vector<map<Color,int>> calculateScore(int SumOfDices) ;

};


#endif //SETTINGUPGOOGLETEST_BOARD1_H
