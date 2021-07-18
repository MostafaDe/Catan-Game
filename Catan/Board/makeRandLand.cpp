#include "Board/makeRandLand.h"
makeRandLand::makeRandLand(int number, int ir, int sh, int ro, int wh, int tr,int de, vector<vector<int>> mnei) {


	number_postion = number;
	number_palce_iron = ir;
	number_palce_rock = ro;
	number_palce_sheep = sh;
	number_palce_tree = tr;
	number_palce_whear = wh;
	number_desert = de;
	neiberhod = mnei;
	
	vector <int> x(number_postion, 0);
	while (number_desert != 0)
	{
		int y;
		y = rand() % number_postion;
		if (x[y] == 0) {
			x[y] = 2;
			number_desert--;

			result_resurce[y + 1] = "desert";

		}
	}


	while (number_palce_iron != 0)
	{
		int y;
		y = rand() % number_postion;
		if (x[y] == 0) {
			x[y] = 1;
			number_palce_iron--;

            result_resurce[y + 1] = "brick";

		}
	}
	while (number_palce_rock != 0)
	{
		int y;
		y = rand() % number_postion;
		if (x[y] == 0) {
			x[y] = 1;
			number_palce_rock--;
			string g;
			g = "rock";
			string m;
			m = g;
            result_resurce[y + 1] = "rock";

		}
	}
	while (number_palce_tree != 0)
	{
		int y;
		y = rand() % number_postion;
		if (x[y] == 0) {
			x[y] = 1;
			number_palce_tree--;
			string g;
			g = "tree";
			string m;
			m = g;
			result_resurce[y + 1] = m;

		}
	}
	while (number_palce_sheep != 0)
	{
		int y;
		y = rand() % number_postion;
		if (x[y] == 0) {
			x[y] = 1;
			number_palce_sheep--;
		
			

			result_resurce[y + 1] = "sheep";

		}
	}
	while (number_palce_whear != 0)
	{
		int y;
		y = rand() % number_postion;
		if (x[y] == 0) {
			x[y] = 1;
			number_palce_whear--;
			string g;
			g = "whear";
			string m;
			m = g;
            result_resurce[y + 1] ="wheat";

		}
	}

	


	check_rand = x;




}
map <int, string> makeRandLand::get_land_position() {
	
	
	return result_resurce;
}

bool makeRandLand::check_adjacent(int number, vector<int> spcial_number) {

	vector<int> adj;
	
	//cout << "xxxx" << number;
	for (int i = 0; i < neiberhod.size(); i++) {
		if (number == neiberhod[i][0]) {


			adj.push_back(neiberhod[i][1]);
			//cout << "mmm" << neiberhod[i][1]<<"\n";

		}
		else if (number == neiberhod[i][1]) {


			adj.push_back(neiberhod[i][0]);
		///cout << "mmm" << neiberhod[i][0] << "\n";

		}
		


	}
	//cout << "mmmddd" << spcial_number.size() <<"\n";
	
	for (int j = 0; j < spcial_number.size(); j++) {
		for (int i = 0; i < adj.size(); i++) {

			//cout << "mmmssss" << spcial_number[j] << "\n";
			if (adj[i] > 0 && adj[i] == spcial_number[j]) {


				return 0;
			}




		}

	}
	//cout << "mmmzzzzzzzz" << "\n";
	return 1;
}







map <int, int > makeRandLand::get_land_number_guss() {
	
	vector<int> number_dice;
	number_dice.push_back(0);
	number_dice.push_back(0);
	number_dice.push_back(2);
	for (int i = 0; i < 4; i++) {

		number_dice.push_back(3);
	}
	
	number_dice.push_back(0);
	
	for (int i = 0; i < 4; i++) {

		number_dice.push_back(3);
	}
	
	
	number_dice.push_back(1);

	vector<int> exp;

	int i = 2;
	
	

	int j=6;



	while (j != 9)
	{

		while (number_dice[j] != 0)
		{
			int y;
			y = rand() % number_postion;
			if (check_rand[y] != 2 && check_rand[y] != 3) {
				if (j != 6 && j != 8) {
					check_rand[y] = 3;
					number_dice[j]--;
					result_dice[y + 1] = j;
				}

				else if (check_adjacent(y + 1, exp)) {
					exp.push_back(y+1);
					check_rand[y] = 3;
					number_dice[j]--;
					result_dice[y + 1] = j;




				}




			}



		}
		
		j++;


	}






	
	



	
	while (i != 13)
	{

		while (number_dice[i] != 0)
		{
			int y;
			y = rand() % number_postion;
			if (check_rand[y] != 2&&check_rand[y]!=3) {
				if (i != 6 && i != 8) {
					check_rand[y] = 3;
					number_dice[i]--;
					result_dice[y + 1] = i;
				}

				else if(check_adjacent(y+1,exp))  {
					exp.push_back(y);
					check_rand[y] = 3;
					number_dice[i]--;
					result_dice[y + 1] = i;

					


				}




			}



		}
		i++;




	}


	
	
	
	
	return result_dice;
}
