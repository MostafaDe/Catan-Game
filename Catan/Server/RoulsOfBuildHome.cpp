#include "RoulsOfBuildHome.h"
#include "gamedata.h"
vector<vector<int>> RoulsOfBuildHome:: illegal_home;



RoulsOfBuildHome::RoulsOfBuildHome(vector<vector<int>> neiber) {

	reltion = neiber;

	
}

bool RoulsOfBuildHome::check_make(vector<vector<int>> position, string color) {
	//cout << "mm" << check_near_home(position);


	GameData d;

	if (d.getBlue_bigcity().size()+d.getBlue_house().size() < 2 && color == "blue") {

		if (check_near_home(position)) {
			add_structure(position, color);
			return 1;
		}
		return 0;
	}
	
	if (d.getRed_bigcity().size() + d.getRed_house().size() < 2 && color == "red") {

		if (check_near_home(position)) {
			add_structure( position,  color);
			return 1;
		}
		return 0;
	}
	
	if (d.getGreen_bigcity().size() + d.getGreen_house().size() < 2 && color == "green") {

		if (check_near_home(position)) {
			add_structure(position, color);
			return 1;
		}
		return 0;
	}
	
	if (d.getYellow_bigcity().size() + d.getYellow_house().size() < 2 && color == "yellow") {

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

		/*if (illegal_home[i][0][0] == position[0][0]) {
			if (illegal_home[i][0][1] == position[0][1]) {
				if (illegal_home[i][1][0] == position[1][0]) {
					if (illegal_home[i][1][1] == position[1][1]) {


					}


				}


			}
			




			*/


	
	
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
	
	GameData d;
	red_road = d.getRed_road();
	blue_road = d.getBlue_road();
	green_road = d.getGreen_road();
	yellow_road = d.getYellow_road();
	
	
	int x = 0;
	if (color == "red") {
		for (int i = 0; i < red_road.size(); i++) {
			x = 0;
			for (int l = 0; l < 4; l = l + 2) {
				for (int j = 0; j < 3; j++) {

					if (red_road[i][l][0] == position[i][0]) {
						x++;
					}
					if (x == 2) {

						return 1;
					}
				}
			}
		}

	}










if (color == "blue") {
	for (int i = 0; i < blue_road.size(); i++) {
		x = 0;
		for (int l = 0; l < 4; l = l + 2) {
			for (int j = 0; j < 3; j++) {

				if (blue_road[i][l][0] == position[i][0]) {
					x++;
				}
				if (x == 2) {

					return 1;
				}
			}
		}
	}

}









if (color == "green") {
	for (int i = 0; i < green_road.size(); i++) {
		x = 0;
		for (int l = 0; l < 4; l=l+2) {
			for (int j = 0; j < 3; j++) {

				if (green_road[i][l][0] == position[i][0]) {
					x++;
				}
				if (x == 2) {

					return 1;
				}
			}
		}
	}

}









if (color == "yellow") {
	for (int i = 0; i < yellow_road.size(); i++) {
		x = 0;
		for (int l = 0; l < 4; l = l + 2) {
			for (int j = 0; j < 3; j++) {

				if (yellow_road[i][l][0] == position[i][0]) {
					x++;
				}
				if (x == 2) {

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
		GameData d;
		vector< vector<vector<int>>> asim;
		asim = d.getBlue_house();
		asim.push_back(position);
		d.setBlue_house(asim);
	}
	
	if (color == "red") {
		GameData d;
		vector< vector<vector<int>>> asim;
		asim = d.getRed_house();
		asim.push_back(position);
		d.setRed_house(asim);
	}

	if (color == "yellow") {
		GameData d;
		vector< vector<vector<int>>> asim;
		asim = d.getYellow_house();
		asim.push_back(position);
		d.setYellow_house(asim);
	
	}


	if (color == "green") {
		GameData d;
		vector< vector<vector<int>>> asim;
		asim = d.getGreen_house();
		asim.push_back(position);
		d.setGreen_house(asim);
	}

	

 }