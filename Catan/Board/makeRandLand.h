#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
class makeRandLand {
public:
	makeRandLand(int number, int ir, int sh, int ro, int wh, int tr,int de, vector<vector<int>> neiberhod);
	map <int, string> get_land_position();
	map<int, int> get_land_number_guss();
	bool check_adjacent(int number_land, vector<int>n6and8);


private:

int number_postion ;
int number_palce_iron ;
int number_palce_rock ; 
int number_palce_sheep ;
int number_palce_tree ;
int number_palce_whear ;
int number_desert;
	map<int, string> result_resurce;
	map<int, int> result_dice;
	vector <int> check_rand;
	vector<vector<int>> neiberhod;
};