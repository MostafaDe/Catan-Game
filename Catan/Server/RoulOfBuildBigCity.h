#pragma once
#include"gamedata.h"
#include<iostream>
#include<vector>
using namespace std;
class RoulOfBuildBigCity
{
public:
	RoulOfBuildBigCity(vector<vector<int>> neeiber);
	bool check_make(vector<vector<int>>z, string colore);
	void addStractor(vector<vector<int>>z, string colore);

private:
                              
	bool check_Home(vector<vector<int>>z, vector< vector<vector<int>>>home);
	vector<vector<int>> reltion;

};

