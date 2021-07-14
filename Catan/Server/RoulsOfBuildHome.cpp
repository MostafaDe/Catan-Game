#include "RoulsOfBuildHome.h"
#include "gamedata.h"
RoulsOfBuildHome::RoulsOfBuildHome(vector<vector<int>> neiber) {

	reltion = neiber;

	
}

bool RoulsOfBuildHome::check_make(vector<vector<int>> position, string color) {
	//cout << "mm" << check_near_home(position);
	if (check_near_home(position) && check_home_in_road(position, color))
		return 1;

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
	
	gamedata d;
	red_road = d.red_road;
	blue_road = d.blue_road;
	green_road = d.green_road;
	yellow_road = d.yellow_road;
	
	
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
		if ((position[i][0] + 1) % 6 == 0) {

			y = 6;

		}
		else {
			y = (position[i][0] + 1) % 6;
		}

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
	/*for (int h = 0; h < 3; h++) {


		cout << "xxxxxxx"<<illegal_home[h][0] << illegal_home[h][1];
	}*/
	

 }