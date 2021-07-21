#include "RoulsOfBuildHome.h"
#include "gamedata.h"
vector<vector<int>> RoulsOfBuildHome:: illegal_home;



RoulsOfBuildHome::RoulsOfBuildHome(vector<vector<int>> neiber) {

	reltion = neiber;

	
}

bool RoulsOfBuildHome::check_make(vector<vector<int>> position, string color) {
	//cout << "mm" << check_near_home(position);




    if (GameData::getBlue_bigcity().size()+GameData::getBlue_house().size() < 2 && color == "blue") {

		if (check_near_home(position)) {
			add_structure(position, color);
			return 1;
		}
		return 0;
	}


    if (GameData::getRed_bigcity().size() + GameData::getRed_house().size() < 2 && color == "red") {

		if (check_near_home(position)) {
			add_structure( position,  color);
			return 1;
		}
		return 0;
	}

	
    if (GameData::getGreen_bigcity().size() + GameData::getGreen_house().size() < 2 && color == "green") {

		if (check_near_home(position)) {
			add_structure(position, color);
			return 1;
		}
		return 0;
	}
	
    if (GameData::getYellow_bigcity().size() + GameData::getYellow_house().size() < 2 && color == "yellow") {

		if (check_near_home(position)) {
			add_structure(position, color);
			return 1;
		}
		return 0;
	}
	
	
	
	

	
	if (check_near_home(position) && check_home_in_road(position, color)) {

        add_structure(position, color);
		return 1;
	}
	return 0;


}

bool RoulsOfBuildHome::check_near_home(vector<vector<int>> position) {
	//cout << "ss" << illegal_home.size()<< "\n";


    for (int i = 0; i < illegal_home.size(); i++) {




	
	
		for (int j = 0; j < 3; j++) {
			//cout << "hhhhh" << illegal_home[i][0] << illegal_home[i][1] << "\n";
				if (illegal_home[i][0] == position[j][0]&&illegal_home[i][1]==position[j][1]) {

					return 0;
			


			}


		}

		





	}



	return 1;
}

bool RoulsOfBuildHome::check_home_in_road(vector<vector<int>> position, string color) {
	

    red_road = GameData::getRed_road();
    blue_road = GameData::getBlue_road();
    green_road = GameData::getGreen_road();
    yellow_road = GameData::getYellow_road();
	
	
	int x = 0;
    if (color == "red") {
 for (int j = 0; j < 3; j++) {
        for (int i = 0; i < red_road.size(); i++) {

            x = 0;
            for (int l = 0; l < 4;l++) {

//qDebug()<< "hastan"<< position[j][0] <<position[j][1] << red_road[i][l][0]<<red_road[i][l][1]  ;
                    if (red_road[i][l][0] == position[j][0]&& red_road[i][l][1] == position[j][1]) {
                        return 1;
                    }

                }
            }
        }

    }










if (color == "blue") {

    for (int j = 0; j < 3; j++) {
    for (int i = 0; i < blue_road.size(); i++) {

        x = 0;
        for (int l = 0; l < 4;l++) {


                if (blue_road[i][l][0] == position[j][0]&& blue_road[i][l][1] == position[j][1]) {
                    return 1;
                }

            }
        }
    }

}









if (color == "green") {
    x = 0;
    for (int j = 0; j < 3; j++) {
      for (int i = 0; i < green_road.size(); i++) {
    for (int l = 0; l < 4;l++) {


            if (green_road[i][l][0] == position[j][0]&& green_road[i][l][1] == position[j][1]) {
                return 1;
            }

        }
    }
}

}









if (color == "yellow") {

     for (int j = 0; j < 3; j++) {
    for (int i = 0; i < yellow_road.size(); i++) {

        x = 0;
        for (int l = 0; l < 4;l++) {


                if (yellow_road[i][l][0] == position[j][0]&& yellow_road[i][l][1] == position[j][1]) {
                    return 1;
                }

            }
        }
    }

}



return 0;




}
void RoulsOfBuildHome::add_structure(vector<vector<int>> position, string color) {


	vector<int> x;
	x.push_back(position[0][0]);
	x.push_back(position[0][1]);
	 
	illegal_home.push_back(x);

	for (int i = 0; i < 3; i++) {
		vector<int> x;
		int y = 0, z = 0;
		
		y = position[i][0];
		if ((position[i][1] + 1) % 6 == 0) {

			z = 6;

		}
		else {
			z = (position[i][1] + 1) % 6;
		}
		
	    x.push_back(y);
		x.push_back(z);

		illegal_home.push_back(x);

	}
	
	if (color == "blue") {

		vector< vector<vector<int>>> asim;
        asim = GameData::getBlue_house();
		asim.push_back(position);
        GameData::setBlue_house(asim);
	}
	
	if (color == "red") {

		vector< vector<vector<int>>> asim;
        asim = GameData::getRed_house();
		asim.push_back(position);
        GameData::setRed_house(asim);
	}

	if (color == "yellow") {

		vector< vector<vector<int>>> asim;
        asim = GameData::getYellow_house();
		asim.push_back(position);
        GameData::setYellow_house(asim);
	
	}


	if (color == "green") {

		vector< vector<vector<int>>> asim;
        asim = GameData::getGreen_house();
		asim.push_back(position);
        GameData::setGreen_house(asim);
	}

	

 }
