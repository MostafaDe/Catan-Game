#include "rouls_of_build_home.h"
rouls_of_build_home::rouls_of_build_home(vector<vector<int>> neiber) {

	reltion = neiber;
//	int z[3][2] = { {-37,4},{-33,6},{-34,2} };
	
}

bool rouls_of_build_home::check_make(int position[3][2], string color) {
	cout << "mm" << check_near_home(position);
	if (check_near_home(position) && check_home_in_road(position, color))
		return 1;

	return 0;


}

bool rouls_of_build_home::check_near_home(int position[3][2]) {
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

bool rouls_of_build_home::check_home_in_road(int position[3][2], string color) {
	int x = 0;
	if (color == "red") {
		for (int i = 0; i < read_road.size(); i++) {
			x = 0;
			for (int l = 0; l < 2; l++) {
				for (int j = 0; j < 3; j++) {

					if (read_road[i][l] == position[i][0]) {
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
		for (int l = 0; l < 2; l++) {
			for (int j = 0; j < 3; j++) {

				if (read_road[i][l] == position[i][0]) {
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
		for (int l = 0; l < 2; l++) {
			for (int j = 0; j < 3; j++) {

				if (read_road[i][l] == position[i][0]) {
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
		for (int l = 0; l < 2; l++) {
			for (int j = 0; j < 3; j++) {

				if (read_road[i][l] == position[i][0]) {
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
void rouls_of_build_home::add_structure(int position[3][2], string color) {


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