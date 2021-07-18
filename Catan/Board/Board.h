//
// Created by apadana on ۰۳/۰۷/۲۰۲۱.
//

#ifndef SETTINGUPGOOGLETEST_BOARD_H
#define SETTINGUPGOOGLETEST_BOARD_H
#include"Board/makeRandLand.h"
#include <vector>
#include <map>
using namespace std;

#include<QJsonObject>
//#include "Color.h"
#include<QString>
#define SIZE 150
class Board {

public:
//    virtual void setRandomNumberToLands() = 0;

//    virtual bool BuildHouse(int postion) = 0;
//    virtual bool BuildRoad(int postion ) = 0;
//    virtual bool BuilBigCity(int postion) =0;
//    virtual bool BuildTown(int postion) = 0;
//    virtual bool BuildBridge(int postion) = 0;
//    virtual vector<map<Color,int>> calculateScore(int SumOfDices) = 0;
    virtual vector<vector<int>> mede_neiberhod_and_get()=0;//vectori of array 2d 
    virtual QJsonObject get_board_information()=0;
    virtual  map<int, string > get_deta_resurse()=0;
    virtual  map<int, int> get_date_dice()=0;
protected:
 //  vector<UnitOfBoard*>  units;
//   map<int,Land> randomNumbersToLands;
   //bool graphOfUnits[SIZE][SIZE];
   map<int, string >deta_resurse;
   map<int, int> date_dice;


};


#endif //SETTINGUPGOOGLETEST_BOARD_H
