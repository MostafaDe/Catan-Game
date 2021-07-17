#ifndef GAMEDATA_H
#define GAMEDATA_H
#include"Board/Board1.h"
#include"Player/player.h"
#include<QMap>
#include"Color/Color.h"
class GameData
{
public:
    GameData(QVector<QPair<int,Player>> socketToPlayerList);
    static int getCountOfMonopolyCards();

    static int getCountOfShowaleyeCards();
    static void setCountOfShowaleyeCards(int newCountOfShowaleyeCards);

    static int getCountOfPointCards();
    static void setCountOfPointCards(int newCountOfPointCards);

    static int getCountOfWheatCards();
    static void setCountOfWheatCards(int newCountOfWheatCards);

    static int getCountOfSheepCards();
    static void setCountOfSheepCards(int newCountOfSheepCards);

    static int getCountOfRockCards();
    static void setCountOfRockCards(int newCountOfRockCards);

    static int getCountOfWoodCards();
    static void setCountOfWoodCards(int newCountOfWoodCards);

    static int getCountOfBrickCards();
    static void setCountOfBrickCards(int newCountOfBrickCards);

    static int getCountOfRoadBuildingCards();
    static void setCountOfRoadBuildingCards(int newCountOfRoadBuildingCards);

    static int getCountOfYearOfPlentyCards();
    static void setCountOfYearOfPlentyCards(int newCountOfYearOfPlentyCards);

    static Board *getBoard();
    static void setBoard(Board *newBoard);




    static void setRed_road(const vector< vector<vector<int>>> &newValue);
    static void setYellow_road(const vector< vector<vector<int>>> &newValue);
    static void setBlue_road(const vector< vector<vector<int>>> &newValue);
    static void setGreen_road(const vector< vector<vector<int>>> &newValue);

    static void setRed_house(vector< vector<vector<int>>> newValue);
    static void setYellow_house(const vector< vector<vector<int>>> &newValue);
    static void setBlue_house(const vector< vector<vector<int>>> &newValue);
    static void setGreen_house(const vector< vector<vector<int>>> &newValue);

    static void setRed_bigcity(const vector< vector<vector<int>>> &newValue);
    static void setYellow_bigcity(const vector< vector<vector<int>>> &newValue);
    static void setBlue_bigcity(const vector< vector<vector<int>>> &newValue);
    static void setGreen_bigcity(const vector< vector<vector<int>>> &newValue);


    static vector< vector<vector<int>>> getRed_road();
    static vector< vector<vector<int>>> getGreen_road();
    static vector< vector<vector<int>>> getYellow_road();
    static vector< vector<vector<int>>> getBlue_road();

    static vector< vector<vector<int>>> getRed_house();
    static vector< vector<vector<int>>> getGreen_house();
    static vector< vector<vector<int>>> getYellow_house();
    static vector< vector<vector<int>>> getBlue_house();

    static vector< vector<vector<int>>> getRed_bigcity();
    static vector< vector<vector<int>>> getGreen_bigcity();
    static vector< vector<vector<int>>> getYellow_bigcity();
    static vector< vector<vector<int>>> getBlue_bigcity();



    static QMap<Color,Player> colorToPlayer;

private:
    static int countOfShowaleyeCards;
    static int countOfPointCards ;
    static int countOfWheatCards;
    static int countOfSheepCards ;
    static int countOfRockCards ;
    static int countOfWoodCards ;
    static int countOfBrickCards ;
    static int countOfRoadBuildingCards;
    static int countOfYearOfPlentyCards;
    static int countOfMonopolyCards;
    static Board *board;

    static vector< vector<vector<int>>> red_road;
    static vector< vector<vector<int>>> blue_road;
    static vector< vector<vector<int>>> green_road;
    static vector< vector<vector<int>>> yellow_road;
    static vector< vector<vector<int>>> red_house;
    static vector< vector<vector<int>>> blue_house;
    static vector< vector<vector<int>>> green_house;
    static vector< vector<vector<int>>> yellow_house;
    static vector< vector<vector<int>>> red_bigcity;
    static vector< vector<vector<int>>> blue_bigcity;
    static vector< vector<vector<int>>> green_bigcity;
    static vector< vector<vector<int>>> yellow_bigcity;




//    Q_PROPERTY(int countOfMonopolyCards READ getCountOfMonopolyCards CONSTANT)
};

#endif // GAMEDATA_H
