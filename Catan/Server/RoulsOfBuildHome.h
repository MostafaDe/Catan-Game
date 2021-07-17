#pragma once
#include "gamedata.h"
#include<vector>
using namespace std;
class RoulsOfBuildHome 
{
public:
    RoulsOfBuildHome(vector<vector<int>> neeiber);

    bool check_make(vector<vector<int>> position, string color);


   

private:
   void add_structure(vector<vector<int>> position, string color) ;
   static vector<vector<int>>  illegal_home;
    vector<vector<int>> reltion;
   vector< vector<vector<int>>> red_road;
   vector< vector<vector<int>>> blue_road;
   vector< vector<vector<int>>> green_road;
   vector< vector<vector<int>>> yellow_road;
    bool check_home_in_road(vector<vector<int>> position, string color);
    bool check_near_home(vector<vector<int>> position);
};

