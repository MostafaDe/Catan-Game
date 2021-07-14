#pragma once
#include<iostream>
#include<vector>
using namespace std;


class Tranlate
{

public:
	Tranlate(vector<vector<int>> neiber);
	
	vector<vector<int>> getPositionOfRoad(int a[2]);
	vector<vector<int>> getPositionOfLand(int a[3]);
	vector<vector<int>> get_to_number(int a[2]);

private:
	int convert(int x);
	vector<vector<int>> get_to_number(int a1,int a2);
	vector<int> serch(vector<vector<int>> x1, vector<vector<int>>x2);
	vector<vector<int>> related;
};

