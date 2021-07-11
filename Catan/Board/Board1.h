//
// Created by apadana on ۰۳/۰۷/۲۰۲۱.
//

#ifndef SETTINGUPGOOGLETEST_BOARD1_H
#define SETTINGUPGOOGLETEST_BOARD1_H
#include "Board.h"
class Board1 : public Board  {
public:
    
    Board1();
     //bool BuildHouse(int postion,Color color);
    bool BuildRoad(int postion ,Color color);
    bool BuilBigCity(int postion,Color color);
    bool BuildTown(int postion,Color color);
     bool BuildBridge(int postion,Color color);
     virtual vector<vector<int>> mede_neiberhod_and_get();
    vector<map<Color,int>> calculateScore(int SumOfDices) ;
      map<int,string> get_data_source();
     map<int,int> get_data_dice();

};


#endif //SETTINGUPGOOGLETEST_BOARD1_H
