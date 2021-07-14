#pragma once
#include "gamedata.h"
class RoulsOfBiuldRoad 
{
public:

 bool check_make(vector<vector<int>>, string colore );
 void addStractor();

private:
	bool check_sequence(vector<vector<int>>z, string colore);
	bool checkFUll(vector<vector<int>>z);
	bool check_elment(vector<vector<int>>z, vector<vector<int>>z1);
	vector<vector<int>> reltion;
	vector< vector<vector<int>>> red_road;
	vector< vector<vector<int>>> blue_road;
	vector< vector<vector<int>>> green_road;
	vector< vector<vector<int>>> yellow_road;


	 
};

