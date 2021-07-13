#pragma once
#include "rouls.h"
class rouls_of_build_home : public rouls
{
public:
    rouls_of_build_home(vector<vector<int>> neeiber);
   
    bool check_make(int position[3][2], string color);

    void add_structure(int position[3][2], string color) ;
   

private:
    vector<vector<int>>  illegal_home;
    vector<vector<int>> reltion;
    vector<vector<int>> read_road;
    vector<vector<int>> blue_road;
    vector<vector<int>> green_road;
    vector<vector<int>> yellow_road;
    bool check_home_in_road(int position[3][2], string color);
    bool check_near_home(int position[3][2]);
};

