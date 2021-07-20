#include<Server/gamedata.h>
#include<iostream>
#include<vector>
#include<map>
#include<utility>

//#include"Board/Board.h"
//#include"Board/makeRandLand.h"
using namespace std;
struct surce{
    int w=0;
    int  t=0;
    int i=0;
    int r=0;
    int sh=0;


};

class AllocateResources
{
public:
    AllocateResources(Board1 d);
    void set_dice(int number);

    vector<pair<string,map<string,int>>> get_whichPlayerGetResurse();

//void give_whearIsLand(int dice,int *collection);

private:
    Board1 B1;
    int number_dice;
    void check_available_source();
void give_whearIsLand(vector<int >&collection);
void check_homearound(int number_land);
void add_source_instructur(string s ,struct surce& x,int dob);
void set_source_player();
struct surce sred;
struct surce sblue;

struct surce sgreen;
struct surce syellow;

};
