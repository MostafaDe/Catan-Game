//
// Created by apadana on ۰۳/۰۷/۲۰۲۱.
//

#include "Board1.h"
Board1::Board1() {

    makeRandLand B1(28, 7, 5, 5, 5, 5, 1,mede_neiberhod_and_get());


    deta_resurse = B1.get_land_position();
    date_dice = B1.get_land_number_guss();






}
vector<vector<int>> Board1::mede_neiberhod_and_get() {

    vector<vector<int>> x;

    vector<int> y[150];
    y[0].push_back(1);
    y[0].push_back(2);
    y[0].push_back(5);
    x.push_back(y[0]);

    for (int i = 0; i < 18; i++) {
        y[i + 1].push_back(3 + i);
        y[i + 1].push_back(4 + i);
        y[i + 1].push_back(5);
        x.push_back(y[1 + i]);
    }


    y[19].push_back(3);
    y[19].push_back(7);
    y[19].push_back(6);
    x.push_back(y[19]);

    y[20].push_back(3);
    y[20].push_back(6);
    y[20].push_back(1);
    x.push_back(y[20]);

    int n = 20;

    n++;
    y[n].push_back(4);
    y[n].push_back(7);
    y[n].push_back(1);
    x.push_back(y[n]);

    n++;
    y[n].push_back(4);
    y[n].push_back(8);
    y[n].push_back(6);
    x.push_back(y[n]);


    n++;
    y[n].push_back(5);
    y[n].push_back(8);
    y[n].push_back(1);
    x.push_back(y[n]);

    n++;
    y[n].push_back(5);
    y[n].push_back(9);
    y[n].push_back(6);
    x.push_back(y[n]);





    n++;
    y[n].push_back(6);
    y[n].push_back(10);
    y[n].push_back(1);
    x.push_back(y[n]);

    n++;
    y[n].push_back(6);
    y[n].push_back(11);
    y[n].push_back(6);
    x.push_back(y[n]);



    n++;
    y[n].push_back(7);
    y[n].push_back(11);
    y[n].push_back(1);
    x.push_back(y[n]);

    n++;
    y[n].push_back(7);
    y[n].push_back(12);
    y[n].push_back(6);
    x.push_back(y[n]);



    n++;
    y[n].push_back(8);
    y[n].push_back(12);
    y[n].push_back(1);
    x.push_back(y[n]);

    n++;
    y[n].push_back(8);
    y[n].push_back(13);
    y[n].push_back(6);
    x.push_back(y[n]);




    n++;
    y[n].push_back(9);
    y[n].push_back(13);
    y[n].push_back(1);
    x.push_back(y[n]);

    n++;
    y[n].push_back(9);
    y[n].push_back(14);
    y[n].push_back(6);
    x.push_back(y[n]);



    n++;
    y[n].push_back(10);
    y[n].push_back(15);
    y[n].push_back(6);
    x.push_back(y[n]);
    for (int i = 0; i < 4; i++) {
        n++;
        y[n].push_back(i + 11);
        y[n].push_back(15 + i);
        y[n].push_back(1);
        x.push_back(y[n]);

        if (i != 3) {
            n++;
            y[n].push_back(i + 11);
            y[n].push_back(16 + i);
            y[n].push_back(6);
            x.push_back(y[n]);

        }



    }




    n++;
    y[n].push_back(15);
    y[n].push_back(19);
    y[n].push_back(6);
    x.push_back(y[n]);
    for (int i = 0; i < 3; i++) {
        n++;
        y[n].push_back(i + 16);
        y[n].push_back(19 + i);
        y[n].push_back(1);
        x.push_back(y[n]);
        if (i != 2) {
            n++;
            y[n].push_back(i + 16);
            y[n].push_back(20 + i);
            y[n].push_back(6);
            x.push_back(y[n]);
        }




    }







    n++;
    y[n].push_back(22);
    y[n].push_back(23);
    y[n].push_back(4);
    x.push_back(y[n]);


    n++;
    y[n].push_back(24);
    y[n].push_back(25);
    y[n].push_back(3);
    x.push_back(y[n]);

    n++;
    y[n].push_back(25);
    y[n].push_back(26);
    y[n].push_back(3);
    x.push_back(y[n]);

    n++;
    y[n].push_back(25);
    y[n].push_back(27);
    y[n].push_back(4);
    x.push_back(y[n]);

    n++;
    y[n].push_back(26);
    y[n].push_back(27);
    y[n].push_back(5);
    x.push_back(y[n]);

    n++;
    y[n].push_back(26);
    y[n].push_back(28);
    y[n].push_back(3);
    x.push_back(y[n]);





    return x;



}
 map<int,string> Board1:: get_data_source(){
  return deta_resurse;   
 }
   map<int,int> Board1:: get_data_dice(){
       
       return date_dice;
   }

