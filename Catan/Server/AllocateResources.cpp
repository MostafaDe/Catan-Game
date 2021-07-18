#include"AllocateResources.h"
#include"QDebug"
//#include"Board/makeRandLand.h"
#include"Board/Board1.h"
void AllocateResources::set_dice(int number)
{
    number_dice=number;

}

vector<pair<string, map<string, int> > > AllocateResources::get_whichPlayerGetResurse()
{

    //int *collection;
    vector<int> collection;
    give_whearIsLand(collection);

for(int i=0;i<collection.size();i++){


    check_homearound(collection[i]);


}
check_available_source();
set_source_player();
vector<pair<string, map<string, int> > > result;
pair<string, map<string, int> > pred;
map<string,int> mred;
mred["tree"]=sred.t;
mred["sheep"]=sred.sh;
mred["brick"]=sred.i;
mred["rock"]=sred.r;
mred["wheat"]=sred.w;
pred.first="red";
pred.second=mred;
result.push_back(pred);


pair<string, map<string, int> > pblue;
map<string,int> mblue;
mblue["tree"]=sblue.t;
mblue["sheep"]=sblue.sh;
mblue["brick"]=sblue.i;
mblue["rock"]=sblue.r;
mblue["wheat"]=sblue.w;
pblue.first="blue";
pblue.second=mblue;
result.push_back(pblue);



pair<string, map<string, int> > pgreen;
map<string,int> mgreen;
mgreen["tree"]=sgreen.t;
mgreen["sheep"]=sgreen.sh;
mgreen["brick"]=sgreen.i;
mgreen["rock"]=sgreen.r;
mgreen["wheat"]=sgreen.w;
pgreen.first="green";
pgreen.second=mgreen;
result.push_back(pgreen);




pair<string, map<string, int> > pyellow;
map<string,int> myellow;
myellow["tree"]=syellow.t;
myellow["sheep"]=syellow.sh;
myellow["brick"]=syellow.i;
myellow["rock"]=syellow.r;
myellow["wheat"]=syellow.w;
pyellow.first="yellow";
pyellow.second=myellow;
result.push_back(pyellow);






return result;



}

void AllocateResources::check_available_source()
{


    if(GameData::getCountOfSheepCards()<syellow.sh+sgreen.sh+sblue.sh+sred.sh){

        sred.sh=0;

        sgreen.sh=0;

        sblue.sh=0;

        syellow.sh=0;




    }
    else{
        GameData::setCountOfSheepCards(GameData::getCountOfSheepCards()-syellow.sh+sgreen.sh+sblue.sh+sred.sh);

        }

    if(GameData::getCountOfRockCards()<sred.r+sgreen.r+sblue.r+syellow.r){

        sred.r=0;

        sgreen.r=0;

        sblue.r=0;

        syellow.r=0;




    }

    else{
        GameData::setCountOfRockCards(GameData::getCountOfRockCards()-sred.r+sgreen.r+sblue.r+syellow.r);

        }



    if(GameData::getCountOfWoodCards()<sred.t+sgreen.t+sblue.t+syellow.t){

        sred.t=0;

        sgreen.t=0;

        sblue.t=0;

        syellow.t=0;




    }

    else{
        GameData::setCountOfWoodCards(GameData::getCountOfWoodCards()-sred.t+sgreen.t+sblue.t+syellow.t);

        }




    if(GameData::getCountOfWheatCards()<sred.w+sgreen.w+sblue.w+syellow.w){

        sred.w=0;

        sgreen.w=0;

        sblue.w=0;

        syellow.w=0;




    }
    else{
        GameData::setCountOfWheatCards(GameData::getCountOfWheatCards()-sred.w+sgreen.w+sblue.w+syellow.w);

        }


    if(GameData::getCountOfBrickCards()<sred.i+sgreen.i+sblue.i+syellow.i){

        sred.i=0;

        sgreen.i=0;

        sblue.i=0;

        syellow.i=0;




    }
    else{
        GameData::setCountOfBrickCards(GameData::getCountOfBrickCards()-sred.i+sgreen.i+sblue.i+syellow.i);

        }







}

void AllocateResources::give_whearIsLand( vector<int>collection)
{

Board1 d;

map<int,int> ser;
ser=d.get_date_dice();

//qDebug() <<collection[0] ;
for(int i=1;i<=ser.size();i++){


    if(ser[i]==number_dice){

        collection.push_back(i);

    }
}


}

void AllocateResources::check_homearound(int number_land)
{
    Board1 d;
    map<int,string> kay_source;
    kay_source=d.get_deta_resurse();




    vector<vector<vector<int>>> r;
    r=GameData::getRed_house();
    for(int i=0;i<GameData::getRed_house().size();i++){
        for(int j=0;j<3;j++){
            if(r[i][j][0]==number_land){

   add_source_instructur(kay_source[number_land],sred,1);



            }


        }




    }


    vector<vector<vector<int>>> b;
    b=GameData::getBlue_house();
    for(int i=0;i<GameData::getBlue_house().size();i++){
        for(int j=0;j<3;j++){
            if(r[i][j][0]==number_land){

   add_source_instructur(kay_source[number_land],sblue,1);



            }


        }




    }



    vector<vector<vector<int>>> g;
    g=GameData::getGreen_house();
    for(int i=0;i<GameData::getGreen_house().size();i++){
        for(int j=0;j<3;j++){
            if(r[i][j][0]==number_land){

   add_source_instructur(kay_source[number_land],sgreen,1);



            }


        }




    }






    vector<vector<vector<int>>> y;
    y=GameData::getYellow_house();
    for(int i=0;i<GameData::getYellow_house().size();i++){
        for(int j=0;j<3;j++){
            if(r[i][j][0]==number_land){

   add_source_instructur(kay_source[number_land],syellow,1);



            }


        }




    }





    vector<vector<vector<int>>> rb;
    rb=GameData::getRed_bigcity();
    for(int i=0;i<GameData::getRed_bigcity().size();i++){
        for(int j=0;j<3;j++){
            if(r[i][j][0]==number_land){

   add_source_instructur(kay_source[number_land],sred,2);



            }


        }




    }


    vector<vector<vector<int>>> bb;
    bb=GameData::getBlue_bigcity();
    for(int i=0;i<GameData::getBlue_bigcity().size();i++){
        for(int j=0;j<3;j++){
            if(r[i][j][0]==number_land){

   add_source_instructur(kay_source[number_land],sblue,2);



            }


        }




    }



    vector<vector<vector<int>>> gb;
    gb=GameData::getGreen_bigcity();
    for(int i=0;i<GameData::getGreen_bigcity().size();i++){
        for(int j=0;j<3;j++){
            if(r[i][j][0]==number_land){

   add_source_instructur(kay_source[number_land],sgreen,2);



            }


        }




    }






    vector<vector<vector<int>>> yb;
    yb=GameData::getYellow_bigcity();
    for(int i=0;i<GameData::getYellow_bigcity().size();i++){
        for(int j=0;j<3;j++){
            if(r[i][j][0]==number_land){

   add_source_instructur(kay_source[number_land],syellow,2);



            }


        }




    }

















}

void AllocateResources::add_source_instructur(string s,struct surce &x,int dob)
{

    if(s=="brick"){
        x.i=x.i+dob;

    }
    else if(s=="sheep"){
         x.sh=x.sh+dob;

    }
    else if(s=="rock"){
      x.r=x.r+dob;


    }

    else if(s=="wheat"){

         x.w=x.w+dob;
    }

    else if(s=="tree"){

         x.t=x.t+dob;

    }
   // qDebug() << x.sh;

}

void AllocateResources::set_source_player()
{


GameData::colorToPlayer[Color::Red].setCountOfBrickCards(sred.i+GameData::colorToPlayer[Color::Red].getCountOfBrickCards());
GameData::colorToPlayer[Color::Red].setCountOfWoodCards(sred.t+GameData::colorToPlayer[Color::Red].getCountOfBrickCards());
GameData::colorToPlayer[Color::Red].setCountOfSheepCards(sred.sh+GameData::colorToPlayer[Color::Red].getCountOfBrickCards());
GameData::colorToPlayer[Color::Red].setCountOfWheatCards(sred.w+GameData::colorToPlayer[Color::Red].getCountOfBrickCards());
GameData::colorToPlayer[Color::Red].setCountOfRockCards(sred.r+GameData::colorToPlayer[Color::Red].getCountOfBrickCards());


GameData::colorToPlayer[Color::Blue].setCountOfBrickCards(sblue.i+GameData::colorToPlayer[Color::Blue].getCountOfBrickCards());
GameData::colorToPlayer[Color::Blue].setCountOfWoodCards(sblue.t+GameData::colorToPlayer[Color::Blue].getCountOfBrickCards());
GameData::colorToPlayer[Color::Blue].setCountOfSheepCards(sblue.sh+GameData::colorToPlayer[Color::Blue].getCountOfBrickCards());
GameData::colorToPlayer[Color::Blue].setCountOfWheatCards(sblue.w+GameData::colorToPlayer[Color::Blue].getCountOfBrickCards());
GameData::colorToPlayer[Color::Blue].setCountOfRockCards(sblue.r+GameData::colorToPlayer[Color::Blue].getCountOfBrickCards());


GameData::colorToPlayer[Color::Green].setCountOfBrickCards(sgreen.i+GameData::colorToPlayer[Color::Green].getCountOfBrickCards());
GameData::colorToPlayer[Color::Green].setCountOfWoodCards(sgreen.t+GameData::colorToPlayer[Color::Green].getCountOfBrickCards());
GameData::colorToPlayer[Color::Green].setCountOfSheepCards(sgreen.sh+GameData::colorToPlayer[Color::Green].getCountOfBrickCards());
GameData::colorToPlayer[Color::Green].setCountOfWheatCards(sgreen.w+GameData::colorToPlayer[Color::Green].getCountOfBrickCards());
GameData::colorToPlayer[Color::Green].setCountOfRockCards(sgreen.r+GameData::colorToPlayer[Color::Green].getCountOfBrickCards());



GameData::colorToPlayer[Color::Yellow].setCountOfBrickCards(syellow.i+GameData::colorToPlayer[Color::Yellow].getCountOfBrickCards());
GameData::colorToPlayer[Color::Yellow].setCountOfWoodCards(syellow.t+GameData::colorToPlayer[Color::Yellow].getCountOfBrickCards());
GameData::colorToPlayer[Color::Yellow].setCountOfSheepCards(syellow.sh+GameData::colorToPlayer[Color::Yellow].getCountOfBrickCards());
GameData::colorToPlayer[Color::Yellow].setCountOfWheatCards(syellow.w+GameData::colorToPlayer[Color::Yellow].getCountOfBrickCards());
GameData::colorToPlayer[Color::Yellow].setCountOfRockCards(syellow.r+GameData::colorToPlayer[Color::Yellow].getCountOfBrickCards());





}
int main()
{

//m.add_source_instructur("sheep",s);



}
