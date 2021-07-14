#include "Tranlate.h"


Tranlate::Tranlate(vector<vector<int>> neiber) {

	related = neiber;


}

vector<vector<int>> Tranlate::getPositionOfRoad(int a[2]) {

	vector<int> x[4];
	vector<vector<int>> y;
	int z1, z2, z3;
	for (int i = 0; i < related.size(); i++) {

		if (a[0] == related[i][0] && a[1] == related[i][1]) {
			
			x[0].push_back(a[0]);
			z1 = related[i][2];
			x[0].push_back(z1);
			if ((z1 + 1) % 6 == 0) {
				x[1].push_back(a[0]);
				//z1 = related[i][2];
				x[1].push_back(6);

			}
			else {
				x[1].push_back(a[0]);
				//z1 = related[i][2];
				x[1].push_back((z1 + 1) % 6);

			}



			z1 = convert(z1);



			x[2].push_back(a[1]);
			
			x[2].push_back(z1);
			if ((z1 + 1) % 6 == 0) {
				x[3].push_back(a[1]);
				//z1 = related[i][2];
				x[3].push_back(6);

			}
			else {
				x[3].push_back(a[1]);
				//z1 = related[i][2];
				x[3].push_back((z1 + 1) % 6);

			}

			for (int j = 0; j < 4; j++) {
				y.push_back(x[j]);

			}
			return y;
		}



		if (a[0] == related[i][1] && a[1] == related[i][0]) {
			


			x[0].push_back(a[1]);
			z1 = related[i][2];
			x[0].push_back(z1);
			if ((z1 + 1) % 6 == 0) {
				x[1].push_back(a[1]);
				//z1 = related[i][2];
				x[1].push_back(6);

			}
			else {
				x[1].push_back(a[1]);
				//z1 = related[i][2];
				x[1].push_back((z1 + 1) % 6);

			}



			z1 = convert(z1);



			x[2].push_back(a[0]);

			x[2].push_back(z1);
			if ((z1 + 1) % 6 == 0) {
				x[3].push_back(a[0]);
				//z1 = related[i][2];
				x[3].push_back(6);

			}
			else {
				x[3].push_back(a[0]);
				//z1 = related[i][2];
				x[3].push_back((z1 + 1) % 6);

			}

			for (int j = 0; j < 4; j++) {
				y.push_back(x[j]);

			}
			return y;



			

		}






	}

}



int Tranlate::convert(int x) {

	if (x == 5) {


		return 2;
	}

	if (x == 2) {


		return 5;
	}

	if (x == 6) {


		return 3;
	}

	if (x == 3) {


		return 6;
	}

	if (x == 1) {


		return 4;
	}

	if (x == 4) {


		return 1;
	}



}
vector<vector<int>> Tranlate::getPositionOfLand(int a[3]) {

	vector<vector<int>> result;
	vector<int> anser1;
	anser1 = serch(get_to_number(a[0], a[1]), get_to_number(a[0], a[2]));
	

	vector<int> anser2;
	anser2 = serch(get_to_number(a[1], a[0]), get_to_number(a[1], a[2]));

	vector<int> anser3;
	anser3 = serch(get_to_number(a[2], a[1]), get_to_number(a[2], a[0]));
	result.push_back(anser1);
	result.push_back(anser2);
	result.push_back(anser3);
	return result;


}
vector<vector<int>> Tranlate::get_to_number(int a1, int a2) {




	vector<int> x[4];
	vector<vector<int>> y;
	int z1, z2, z3;
	for (int i = 0; i < related.size(); i++) {

		if (a1 == related[i][0] && a2 == related[i][1]) {
			//cout << "1\n";
			//cout << a1 << a2 <<"\n";
			x[0].push_back(a1);
			z1 = related[i][2];
			//cout << z1;
			x[0].push_back(z1);
			if ((z1 + 1) % 6 == 0) {
				x[1].push_back(a1);
				//z1 = related[i][2];
				x[1].push_back(6);

			}
			else {
				x[1].push_back(a1);
				//z1 = related[i][2];
				x[1].push_back((z1 + 1)%6);

			}



			

			for (int j = 0; j < 2; j++) {
				y.push_back(x[j]);

			}
			return y;
		}



		if (a1 == related[i][1] && a2 == related[i][0]) {
		//	cout << "12\n";
			z1 = related[i][2];
			z1 = convert(z1);

			x[0].push_back(a1);
			
			x[0].push_back(z1);
			z1 = z1 + 1;
			if (z1 % 6 == 0) {
				x[1].push_back(a1);
				//z1 = related[i][2];
				x[1].push_back(6);

			}
			else {
				x[1].push_back(a1);
				//z1 = related[i][2];
				x[1].push_back(z1 %6);

			}



			

			for (int j = 0; j < 2; j++) {
				y.push_back(x[j]);

			}
			return y;





		}






	}





}
vector<int> Tranlate::serch(vector<vector<int>> x1, vector<vector<int>>x2) {

	vector<int> anser;

	for (int i = 0; i < 2; i++) {


		for (int j = 0; j < 2; j++) {
		//	cout << x1[i][0] << x1[i][1] << "hh\n";
			//cout << x2[i][0] << x2[i][1] << "hhfff\n";

			if (x1[i][0] == x2[j][0] && x1[i][1] == x2[j][1]) {
				//cout << x1[i][0] << x1[i][1];
				anser.push_back(x1[i][0]);
				anser.push_back(x1[i][1]);
				return anser;
			}


		}
	}


}