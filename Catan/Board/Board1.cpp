//
// Created by apadana on ۰۳/۰۷/۲۰۲۱.
//

#include "Board/Board1.h"
Board1::Board1() {

    makeRandLand B1(28, 7, 5, 5, 5, 5, 1,mede_neiberhod_and_get());


    deta_resurse = B1.get_land_position();
    date_dice = B1.get_land_number_guss();






}
vector<vector<int>> Board1::mede_neiberhod_and_get() {

    vector<vector<int>> x;

    vector<int> y[200];
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

    n++;
    y[n].push_back(1);
    y[n].push_back(-4);
    y[n].push_back(6);
    x.push_back(y[n]);

    n++;
    y[n].push_back(1);
    y[n].push_back(-3);
    y[n].push_back(1);
    x.push_back(y[n]);


    n++;
    y[n].push_back(1);
    y[n].push_back(-30);
    y[n].push_back(2);
    x.push_back(y[n]);

    n++;
    y[n].push_back(1);
    y[n].push_back(-29);
    y[n].push_back(3);
    x.push_back(y[n]);

    n++;
    y[n].push_back(1);
    y[n].push_back(-28);
    y[n].push_back(4);
    x.push_back(y[n]);


    n++;
    y[n].push_back(2);
    y[n].push_back(-4);
    y[n].push_back(1);
    x.push_back(y[n]);


    n++;
    y[n].push_back(2);
    y[n].push_back(-28);
    y[n].push_back(3);
    x.push_back(y[n]);


    n++;
    y[n].push_back(2);
    y[n].push_back(-27);
    y[n].push_back(4);
    x.push_back(y[n]);


    n++;
    y[n].push_back(2);
    y[n].push_back(-26);
    y[n].push_back(5);
    x.push_back(y[n]);


    n++;
    y[n].push_back(2);
    y[n].push_back(-5);
    y[n].push_back(6);
    x.push_back(y[n]);



    for (int i = 0; i < 4; i++) {

        n++;
        y[n].push_back(28);
        y[n].push_back(-26 + i);
        y[n].push_back(2 + i);
        x.push_back(y[n]);




    }


    n++;
    y[n].push_back(28);
    y[n].push_back(-6);
    y[n].push_back(1);
    x.push_back(y[n]);





    n++;
    y[n].push_back(26);
    y[n].push_back(-6);
    y[n].push_back(2);
    x.push_back(y[n]);

    n++;
    y[n].push_back(26);
    y[n].push_back(-7);
    y[n].push_back(1);
    x.push_back(y[n]);

    n++;
    y[n].push_back(26);
    y[n].push_back(-23);
    y[n].push_back(4);
    x.push_back(y[n]);





    n++;
    y[n].push_back(25);
    y[n].push_back(-7);
    y[n].push_back(2);
    x.push_back(y[n]);

    n++;
    y[n].push_back(25);
    y[n].push_back(-8);
    y[n].push_back(1);
    x.push_back(y[n]);

    n++;
    y[n].push_back(25);
    y[n].push_back(-20);
    y[n].push_back(4);
    x.push_back(y[n]);






    n++;
    y[n].push_back(24);
    y[n].push_back(-8);
    y[n].push_back(2);
    x.push_back(y[n]);

    n++;
    y[n].push_back(24);
    y[n].push_back(-9);
    y[n].push_back(1);
    x.push_back(y[n]);

    n++;
    y[n].push_back(24);
    y[n].push_back(-17);
    y[n].push_back(6);
    x.push_back(y[n]);



    n++;
    y[n].push_back(24);
    y[n].push_back(-19);
    y[n].push_back(5);
    x.push_back(y[n]);

    n++;
    y[n].push_back(24);
    y[n].push_back(-20);
    y[n].push_back(4);
    x.push_back(y[n]);







    for (int i = 0; i < 4; i++) {

        n++;
        y[n].push_back(27);
        y[n].push_back(-23 + i);
        y[n].push_back(3 + i);
        x.push_back(y[n]);




    }






    n++;
    y[n].push_back(23);
    y[n].push_back(-10);
    y[n].push_back(2);
    x.push_back(y[n]);

    n++;
    y[n].push_back(23);
    y[n].push_back(-9);
    y[n].push_back(3);
    x.push_back(y[n]);

    n++;
    y[n].push_back(23);
    y[n].push_back(-17);
    y[n].push_back(4);
    x.push_back(y[n]);



    n++;
    y[n].push_back(23);
    y[n].push_back(-16);
    y[n].push_back(5);
    x.push_back(y[n]);

    n++;
    y[n].push_back(23);
    y[n].push_back(-15);
    y[n].push_back(6);
    x.push_back(y[n]);







    n++;
    y[n].push_back(22);
    y[n].push_back(-13);
    y[n].push_back(1);
    x.push_back(y[n]);

    n++;
    y[n].push_back(22);
    y[n].push_back(-10);
    y[n].push_back(3);
    x.push_back(y[n]);

    n++;
    y[n].push_back(22);
    y[n].push_back(-11);
    y[n].push_back(2);
    x.push_back(y[n]);



    n++;
    y[n].push_back(22);
    y[n].push_back(-15);
    y[n].push_back(5);
    x.push_back(y[n]);

    n++;
    y[n].push_back(22);
    y[n].push_back(-14);
    y[n].push_back(6);
    x.push_back(y[n]);

    for (int i = 0; i < 3; i++) {

        n++;
        y[n].push_back(3 + i);
        y[n].push_back(-3 - i);
        y[n].push_back(3);
        x.push_back(y[n]);

    }

    for (int i = 0; i < 3; i++) {

        n++;
        y[n].push_back(3 + i);
        y[n].push_back(-4 - i);
        y[n].push_back(4);
        x.push_back(y[n]);

    }



    n++;
    y[n].push_back(3);
    y[n].push_back(-2);
    y[n].push_back(2);
    x.push_back(y[n]);




    n++;
    y[n].push_back(6);
    y[n].push_back(-2);
    y[n].push_back(3);
    x.push_back(y[n]);

    n++;
    y[n].push_back(6);
    y[n].push_back(-1);
    y[n].push_back(2);
    x.push_back(y[n]);


    n++;
    y[n].push_back(10);
    y[n].push_back(-1);
    y[n].push_back(3);
    x.push_back(y[n]);

    n++;
    y[n].push_back(10);
    y[n].push_back(-31);
    y[n].push_back(2);
    x.push_back(y[n]);

    n++;
    y[n].push_back(10);
    y[n].push_back(-32);
    y[n].push_back(1);
    x.push_back(y[n]);



    n++;
    y[n].push_back(15);
    y[n].push_back(-32);
    y[n].push_back(2);
    x.push_back(y[n]);

    n++;
    y[n].push_back(15);
    y[n].push_back(-33);
    y[n].push_back(1);
    x.push_back(y[n]);





    n++;
    y[n].push_back(19);
    y[n].push_back(-33);
    y[n].push_back(2);
    x.push_back(y[n]);

    n++;
    y[n].push_back(19);
    y[n].push_back(-34);
    y[n].push_back(1);
    x.push_back(y[n]);

    n++;
    y[n].push_back(19);
    y[n].push_back(-35);
    y[n].push_back(6);
    x.push_back(y[n]);



    n++;
    y[n].push_back(20);
    y[n].push_back(-36);
    y[n].push_back(6);
    x.push_back(y[n]);

    n++;
    y[n].push_back(20);
    y[n].push_back(-35);
    y[n].push_back(1);
    x.push_back(y[n]);








    n++;
    y[n].push_back(21);
    y[n].push_back(-11);
    y[n].push_back(5);
    x.push_back(y[n]);

    n++;
    y[n].push_back(21);
    y[n].push_back(-36);
    y[n].push_back(1);
    x.push_back(y[n]);

    n++;
    y[n].push_back(21);
    y[n].push_back(-12);
    y[n].push_back(6);
    x.push_back(y[n]);







    n++;
    y[n].push_back(18);
    y[n].push_back(-11);
    y[n].push_back(6);
    x.push_back(y[n]);

    n++;
    y[n].push_back(18);
    y[n].push_back(-10);
    y[n].push_back(5);
    x.push_back(y[n]);





    n++;
    y[n].push_back(14);
    y[n].push_back(-10);
    y[n].push_back(6);
    x.push_back(y[n]);

    n++;
    y[n].push_back(14);
    y[n].push_back(-9);
    y[n].push_back(5);
    x.push_back(y[n]);

    n++;
    y[n].push_back(14);
    y[n].push_back(-8);
    y[n].push_back(4);
    x.push_back(y[n]);



    n++;
    y[n].push_back(9);
    y[n].push_back(-8);
    y[n].push_back(5);
    x.push_back(y[n]);

    n++;
    y[n].push_back(9);
    y[n].push_back(-7);
    y[n].push_back(4);
    x.push_back(y[n]);



    n++;
    y[n].push_back(5);
    y[n].push_back(-7);
    y[n].push_back(5);
    x.push_back(y[n]);

    for (int i = 0; i < 8; i++) {


        n++;
        y[n].push_back(-4 - i);
        y[n].push_back(-3 - i);
        y[n].push_back(3);
        x.push_back(y[n]);



    }

    for (int i = 0; i < 4; i++) {


        n++;
        y[n].push_back(-13 - i);
        y[n].push_back(-14 - i);
        y[n].push_back(4);
        x.push_back(y[n]);


    }

    n++;
    y[n].push_back(-26);
    y[n].push_back(-5);
    y[n].push_back(1);
    x.push_back(y[n]);

    n++;
    y[n].push_back(-26);
    y[n].push_back(-6);
    y[n].push_back(6);
    x.push_back(y[n]);





    n++;
    y[n].push_back(-9);
    y[n].push_back(-17);
    y[n].push_back(5);
    x.push_back(y[n]);








    return x;



}

QJsonObject Board1::get_board_information()
{

    QJsonObject jo,j1,j2;
    for(int i=1;i<=28;i++){
QString m;
m=QString::number(i);
        j1[m]=QString::fromStdString( deta_resurse[i]);


    }
    for(int i=1;i<=28;i++){
QString m;
m=QString::number(i);
        j2[m]= date_dice[i];


    }
jo["json1"]=j1;
jo["json2"]=j2;


return jo;

}

map<int, string> Board1::get_deta_resurse()
{
    return deta_resurse;
}

map<int, int> Board1::get_date_dice()
{
    return date_dice;
}







