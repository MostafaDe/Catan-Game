#include "gamedata.h"

int GameData::countOfBrickCards = 20;
int GameData::countOfPointCards = 5;
int GameData::countOfRockCards = 20;
int GameData::countOfSheepCards = 20;
int GameData::countOfShowaleyeCards = 14;
int GameData::countOfWheatCards  = 20;
int GameData::countOfWoodCards = 20;
int GameData::countOfYearOfPlentyCards = 2;
int GameData::countOfMonopolyCards = 2;
int GameData::countOfRoadBuildingCards = 2;
Board* GameData::board;
QMap<Color,Player> GameData::colorToPlayer;
vector< vector<vector<int>>> GameData::red_road;
vector< vector<vector<int>>> GameData::blue_road;
vector< vector<vector<int>>> GameData::green_road;
vector< vector<vector<int>>> GameData::yellow_road;
vector< vector<vector<int>>> GameData::red_house;
vector< vector<vector<int>>> GameData::blue_house;
vector< vector<vector<int>>> GameData::green_house;
vector< vector<vector<int>>> GameData::yellow_house;
vector< vector<vector<int>>> GameData::red_bigcity;
vector< vector<vector<int>>> GameData::blue_bigcity;
vector< vector<vector<int>>> GameData::green_bigcity;
vector< vector<vector<int>>> GameData::yellow_bigcity;


GameData::GameData(QVector<QPair<int,Player>> socketToPlayerList)
{
board = new Board1;
for(auto &it:socketToPlayerList){
    colorToPlayer[it.second.getColor()] = it.second;

}


}

int GameData::getCountOfShowaleyeCards()
{
    return countOfShowaleyeCards;
}

void GameData::setCountOfShowaleyeCards(int newCountOfShowaleyeCards)
{
    countOfShowaleyeCards = newCountOfShowaleyeCards;
}

int GameData::getCountOfPointCards()
{
    return countOfPointCards;
}

void GameData::setCountOfPointCards(int newCountOfPointCards)
{
    countOfPointCards = newCountOfPointCards;
}

int GameData::getCountOfWheatCards()
{
    return countOfWheatCards;
}

void GameData::setCountOfWheatCards(int newCountOfWheatCards)
{
    countOfWheatCards = newCountOfWheatCards;
}

int GameData::getCountOfSheepCards()
{
    return countOfSheepCards;
}

void GameData::setCountOfSheepCards(int newCountOfSheepCards)
{
    countOfSheepCards = newCountOfSheepCards;
}

int GameData::getCountOfRockCards()
{
    return countOfRockCards;
}

void GameData::setCountOfRockCards(int newCountOfRockCards)
{
    countOfRockCards = newCountOfRockCards;
}

int GameData::getCountOfWoodCards()
{
    return countOfWoodCards;
}

void GameData::setCountOfWoodCards(int newCountOfWoodCards)
{
    countOfWoodCards = newCountOfWoodCards;
}

int GameData::getCountOfBrickCards()
{
    return countOfBrickCards;
}

void GameData::setCountOfBrickCards(int newCountOfBrickCards)
{
    countOfBrickCards = newCountOfBrickCards;
}

int GameData::getCountOfRoadBuildingCards()
{
    return countOfRoadBuildingCards;
}

void GameData::setCountOfRoadBuildingCards(int newCountOfRoadBuildingCards)
{
    countOfRoadBuildingCards = newCountOfRoadBuildingCards;
}

int GameData::getCountOfYearOfPlentyCards()
{
    return countOfYearOfPlentyCards;
}

void GameData::setCountOfYearOfPlentyCards(int newCountOfYearOfPlentyCards)
{
    countOfYearOfPlentyCards = newCountOfYearOfPlentyCards;
}

Board *GameData::getBoard() {
    return board;
}

void GameData::setBoard(Board *newBoard)
{
    board = newBoard;
}





void GameData::setRed_road(const vector<vector<vector<int> > > &newValue)
{
    red_road = newValue;
}

void GameData::setYellow_road(const vector<vector<vector<int> > > &newValue)
{
    yellow_road = newValue;
}

void GameData::setBlue_road(const vector<vector<vector<int> > > &newValue)
{
    blue_road = newValue;
}

void GameData::setGreen_road(const vector<vector<vector<int> > > &newValue)
{
    green_road = newValue;
}

void GameData::setRed_house(vector<vector<vector<int> > > newValue)
{
    red_house = newValue;
}

void GameData::setYellow_house(const vector<vector<vector<int> > > &newValue)
{
   yellow_house = newValue;
}

void GameData::setBlue_house(const vector<vector<vector<int> > > &newValue)
{
   blue_house = newValue;
}

void GameData::setGreen_house(const vector<vector<vector<int> > > &newValue)
{
    green_house = newValue;
}

void GameData::setRed_bigcity(const vector<vector<vector<int> > > &newValue)
{
     red_bigcity = newValue;
}

void GameData::setYellow_bigcity(const vector<vector<vector<int> > > &newValue)
{
     yellow_bigcity = newValue;
}

void GameData::setBlue_bigcity(const vector<vector<vector<int> > > &newValue)
{
     blue_bigcity = newValue;
}

void GameData::setGreen_bigcity(const vector<vector<vector<int> > > &newValue)
{
    green_bigcity = newValue;
}

vector<vector<vector<int> > > GameData::getRed_road()
{
return red_road;
}

vector<vector<vector<int> > > GameData::getGreen_road()
{
return green_road;
}

vector<vector<vector<int> > > GameData::getYellow_road()
{
return yellow_road;
}

vector<vector<vector<int> > > GameData::getBlue_road()
{
return blue_road;
}

vector<vector<vector<int> > > GameData::getRed_house()
{
return red_house;
}

vector<vector<vector<int> > > GameData::getGreen_house()
{
return green_house;
}

vector<vector<vector<int> > > GameData::getYellow_house()
{
return yellow_house;
}

vector<vector<vector<int> > > GameData::getBlue_house()
{
    return blue_house;
}

vector<vector<vector<int> > > GameData::getRed_bigcity()
{
    return red_bigcity;
}

vector<vector<vector<int> > > GameData::getGreen_bigcity()
{
    return green_bigcity;
}

vector<vector<vector<int> > > GameData::getYellow_bigcity()
{
    return yellow_bigcity;
}

vector<vector<vector<int> > > GameData::getBlue_bigcity()
{
    return blue_bigcity;
}
