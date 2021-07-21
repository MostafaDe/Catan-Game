#include "RoulOfBuildBigCity.h"
RoulOfBuildBigCity::RoulOfBuildBigCity(vector<vector<int>> neiber) {


	reltion = neiber;



}


bool RoulOfBuildBigCity::check_make(vector<vector<int>> position, string color) {



	if (color == "bule") {
	
        if (check_Home(position, GameData::getBlue_house()) ){
addStractor(position,color);
			return 1;
		}
		return 0;

	}

	if (color == "red") {

        if (check_Home(position, GameData::getRed_house())) {
addStractor(position,color);
			return 1;
		}
		return 0;

	}


	if (color == "green") {

        if (check_Home(position, GameData::getGreen_house())) {
addStractor(position,color);
			return 1;
		}
		return 0;

	}
	if (color == "yellow") {

        if (check_Home(position, GameData::getYellow_house())) {
addStractor(position,color);
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





	if (color == "bule") {
		
		vector< vector<vector<int>>>home;
        home = GameData::getBlue_house();
		vector< vector<vector<int>>>bigHome;
        bigHome = GameData::getBlue_bigcity();
		for (int i = 0; i <home.size(); i++) {

			for (int j = 0; j < 3; j++) {

				if (z[0][0] == home[i][j][0] && z[0][1] == home[i][j][1]) {
					bigHome.push_back(home[i]);
					home.erase(home.begin() + i);
                    GameData::setBlue_bigcity(bigHome);
                    GameData::setBlue_house(home);
					return;
					
				}


			}




		}

	}

	if (color == "red") {

		vector< vector<vector<int>>>home;
        home = GameData::getRed_house();
		vector< vector<vector<int>>>bigHome;
        bigHome = GameData::getRed_bigcity();
		for (int i = 0; i < home.size(); i++) {

			for (int j = 0; j < 3; j++) {

				if (z[0][0] == home[i][j][0] && z[0][1] == home[i][j][1]) {
					bigHome.push_back(home[i]);
					home.erase(home.begin() + i);
                    GameData::setRed_bigcity(bigHome);
                    GameData::setRed_house(home);
					return;

				}


			}




		}

	}

	if (color == "green") {

		vector< vector<vector<int>>>home;
        home = GameData::getGreen_house();
		vector< vector<vector<int>>>bigHome;
        bigHome = GameData::getGreen_bigcity();
		for (int i = 0; i < home.size(); i++) {

			for (int j = 0; j < 3; j++) {

				if (z[0][0] == home[i][j][0] && z[0][1] == home[i][j][1]) {
					bigHome.push_back(home[i]);
					home.erase(home.begin() + i);
                    GameData::setGreen_bigcity(bigHome);
                    GameData::setGreen_house(home);
					return;

				}


			}




		}

	}



	if (color == "yellow") {

		vector< vector<vector<int>>>home;
        home = GameData::getYellow_house();
		vector< vector<vector<int>>>bigHome;
        bigHome = GameData::getYellow_bigcity();
		for (int i = 0; i < home.size(); i++) {

			for (int j = 0; j < 3; j++) {

				if (z[0][0] == home[i][j][0] && z[0][1] == home[i][j][1]) {
					bigHome.push_back(home[i]);
					home.erase(home.begin() + i);
                    GameData::setYellow_bigcity(bigHome);
                    GameData::setYellow_house(home);
					return;

				}


			}




		}

	}






}
