#include "RoulsOfBiuldRoad.h"


RoulsOfBiuldRoad::RoulsOfBiuldRoad(vector<vector<int>> neiber) {

	reltion = neiber;


}



bool RoulsOfBiuldRoad::check_make(vector<vector<int>>z, string color) {



    if (GameData::getBlue_road().size() < 2 && color == "blue") {

        if (check_when_less2(z, GameData::getBlue_house(),GameData::getBlue_bigcity())) {
			addStractor(z, color);
			return 1;
		}

       // qDebug() << "salm";
        return 0;

	}

    if (GameData::getRed_road().size() < 2 && color == "red") {

        if (check_when_less2(z, GameData::getRed_house(),GameData::getRed_bigcity())) {
			addStractor(z, color);
			return 1;
		}
		return 0;
	}

    if ( GameData::getGreen_road().size() < 2 && color == "green") {
        if (check_when_less2(z, GameData::GameData::getGreen_house(),GameData::getGreen_bigcity())) {
			addStractor(z, color);
			return 1;
		}
		return 0;
	
	}

    if (GameData::getYellow_road().size() < 2 && color == "yellow") {

        if (check_when_less2(z, GameData::getYellow_house(),GameData::getYellow_bigcity())) {
			addStractor(z, color);
			return 1;
		}
		return 0;
	}












    if (checkFUll(z)&& check_sequence(z, color)) {
		addStractor(z, color);
		return 1;
	}


	return 0;



}


bool RoulsOfBiuldRoad::check_when_less2(vector<vector<int>> z, vector< vector<vector<int>>> home,vector< vector<vector<int>>> bighome) {
	
for(int l=0;l<home.size();l++){
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
 //qDebug() << "salm" <<home.size()<< home[1][2][0] << home [0][2][0];

            //  qDebug() << "salm" <<home[home.size() - 1][j][0]<<z[i][0];

                if (home[l][j][0] == z[i][0] && home[l][j][1] == z[i][1]) {

                    return 1;
			}
				
			}
		}
}




for(int l=0;l<bighome.size();l++){
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
 //qDebug() << "salm" <<home.size()<< home[1][2][0] << home [0][2][0];

            //  qDebug() << "salm" <<home[home.size() - 1][j][0]<<z[i][0];

                if (bighome[l][j][0] == z[i][0] &&bighome[l][j][1] == z[i][1]) {

                    return 1;
            }

            }
        }
}






return 0;

	




}




bool RoulsOfBiuldRoad::check_sequence(vector<vector<int>> z, string color) {


    red_road = GameData::getRed_road();
    blue_road = GameData::getBlue_road();
    green_road =GameData::getGreen_road();
    yellow_road = GameData::getYellow_road();

	int x = 0;
	if (color == "red") {
		for (int i = 0; i < red_road.size(); i++) {

			

			if (check_elment(red_road[i], z)) {
				return 1;
			}



		}

	}










	if (color == "blue") {

			for (int i = 0; i < blue_road.size(); i++) {



				if (check_elment(blue_road[i], z)) {
					return 1;
				}



			}

	}









	if (color == "green") {
		for (int i = 0; i < green_road.size(); i++) {

            qDebug() << "sal";


			if (check_elment(green_road[i], z)) {
				return 1;
			}



		}

	}









	if (color == "yellow") {
		for (int i = 0; i < yellow_road.size(); i++) {



			if (check_elment(yellow_road[i], z)) {
				return 1;
			}



		}

	}

	return 0;



}
bool RoulsOfBiuldRoad::check_elment(vector<vector<int>>z, vector<vector<int>>z1) {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			if (z[i][0] == z1[j][0] && z[i][1] == z1[j][1]) {

				return 1;
			}

		}


	}
	return 0;



}
bool RoulsOfBiuldRoad::checkFUll(vector<vector<int>>z) {
//qDebug ()<< "sall"<< z[2][0];
    red_road = GameData::getRed_road();
    blue_road =GameData::getBlue_road();
    green_road = GameData::getGreen_road();
    yellow_road = GameData::getYellow_road();
	for (int i = 0; i < yellow_road.size(); i++) {
		if (yellow_road[i][0][0] == z[0][0] && yellow_road[i][3][0] == z[3][0]) {

			return 0;
		}


	}
	for (int i = 0; i < red_road.size(); i++) {
		if (red_road[i][0][0] == z[0][0] && red_road[i][3][0] == z[3][0]) {

			return 0;
		}


	}

	for (int i = 0; i < green_road.size(); i++) {
		if (green_road[i][0][0] == z[0][0] && green_road[i][3][0] == z[3][0]) {

			return 0;
		}


	}



	for (int i = 0; i < blue_road.size(); i++) {

        if (blue_road[i][0][0] == z[0][0] && blue_road[i][3][0] == z[3][0]) {
  qDebug() << "salm" << z[0][0]<< z[3][0] ;

			return 0;
		}


	}

	return 1;



}
void RoulsOfBiuldRoad::addStractor(vector<vector<int>> z, string color) {

	if (color == "blue") {

		vector< vector<vector<int>>> asim;
        asim =GameData::getBlue_road();
		asim.push_back(z);
        GameData::setBlue_road(asim);
	}

	if (color == "red") {

		vector< vector<vector<int>>> asim;
        asim = GameData::getRed_road();
		asim.push_back(z);
        GameData::setRed_road(asim);
	}

	if (color == "yellow") {

		vector< vector<vector<int>>> asim;
        asim = GameData::getYellow_road();
		asim.push_back(z);
        GameData::setYellow_road(asim);

	}


	if (color == "green") {

		vector< vector<vector<int>>> asim;
        asim = GameData::getGreen_road();
		asim.push_back(z);
        GameData::setGreen_road(asim);
	}



}
