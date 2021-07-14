#include "RoulOfBuildBigCity.h"
RoulOfBuildBigCity::RoulOfBuildBigCity(vector<vector<int>> neiber) {


	reltion = neiber;



}


bool RoulOfBuildBigCity::check_make(vector<vector<int>> position, string color) {
	GameData d;


	if (color == "bule") {
	
		if (check_Home(position, d.getBlue_house()) ){

			return 1;
		}
		return 0;

	}

	if (color == "red") {

		if (check_Home(position, d.getRed_house())) {

			return 1;
		}
		return 0;

	}


	if (color == "green") {

		if (check_Home(position, d.getGreen_house())) {

			return 1;
		}
		return 0;

	}
	if (color == "yellow") {

		if (check_Home(position, d.getYellow_house())) {

			return 1;
		}
		return 0;

	}




	return 0;



}
bool RoulOfBuildBigCity::check_Home(vector<vector<int>>z, vector< vector<vector<int>>>home) {



	for (int i = 0; i < home.size(); i++) {

		for (int j = 0; j < 3; j++) {

			if (z[0][0] == home[i][j][0] && z[0][1] == home[i][j][1]) {
			
				
				return 1;
			}


		}




	}

	return 0;
}


void RoulOfBuildBigCity::addStractor(vector<vector<int>>z, string color) {


	GameData d;


	if (color == "bule") {
		
		vector< vector<vector<int>>>home;
		home = d.getBlue_house();
		vector< vector<vector<int>>>bigHome;
		bigHome = d.getBlue_bigcity();
		for (int i = 0; i <home.size(); i++) {

			for (int j = 0; j < 3; j++) {

				if (z[0][0] == home[i][j][0] && z[0][1] == home[i][j][1]) {
					bigHome.push_back(home[i]);
					home.erase(home.begin() + i);
					d.setBlue_bigcity(bigHome);
					d.setBlue_house(home);
					return;
					
				}


			}




		}

	}

	if (color == "red") {

		vector< vector<vector<int>>>home;
		home = d.getRed_house();
		vector< vector<vector<int>>>bigHome;
		bigHome = d.getRed_bigcity();
		for (int i = 0; i < home.size(); i++) {

			for (int j = 0; j < 3; j++) {

				if (z[0][0] == home[i][j][0] && z[0][1] == home[i][j][1]) {
					bigHome.push_back(home[i]);
					home.erase(home.begin() + i);
					d.setRed_bigcity(bigHome);
					d.setRed_house(home);
					return;

				}


			}




		}

	}

	if (color == "green") {

		vector< vector<vector<int>>>home;
		home = d.getGreen_house();
		vector< vector<vector<int>>>bigHome;
		bigHome = d.getGreen_bigcity();
		for (int i = 0; i < home.size(); i++) {

			for (int j = 0; j < 3; j++) {

				if (z[0][0] == home[i][j][0] && z[0][1] == home[i][j][1]) {
					bigHome.push_back(home[i]);
					home.erase(home.begin() + i);
					d.setGreen_bigcity(bigHome);
					d.setGreen_house(home);
					return;

				}


			}




		}

	}



	if (color == "yellow") {

		vector< vector<vector<int>>>home;
		home = d.getYellow_house();
		vector< vector<vector<int>>>bigHome;
		bigHome = d.getYellow_bigcity();
		for (int i = 0; i < home.size(); i++) {

			for (int j = 0; j < 3; j++) {

				if (z[0][0] == home[i][j][0] && z[0][1] == home[i][j][1]) {
					bigHome.push_back(home[i]);
					home.erase(home.begin() + i);
					d.setYellow_bigcity(bigHome);
					d.setYellow_house(home);
					return;

				}


			}




		}

	}






}