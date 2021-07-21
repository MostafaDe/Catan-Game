#pragma once
#include "gamedata.h"
#include<vector>
using namespace std;
class RoulsOfBiuldRoad 
{
public:
 RoulsOfBiuldRoad(vector<vector<int>> neeiber);
 bool check_make(vector<vector<int>>z, string colore );


private:
    void addStractor(vector<vector<int>>z, string colore);
	bool check_sequence(vector<vector<int>>z, string colore);
	bool checkFUll(vector<vector<int>>z);
	bool check_elment(vector<vector<int>>z, vector<vector<int>>z1);
    bool check_when_less2(vector<vector<int>>z, vector< vector<vector<int>>> home,vector< vector<vector<int>>> bighome);
	vector<vector<int>> reltion;
	vector< vector<vector<int>>> red_road;
	vector< vector<vector<int>>> blue_road;
	vector< vector<vector<int>>> green_road;
	vector< vector<vector<int>>> yellow_road;


	 
};

