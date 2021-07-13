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

Board *GameData::getBoard() const
{
    return board;
}

void GameData::setBoard(Board *newBoard)
{
    board = newBoard;
}

const QMap<Color, Player> &GameData::getColorToPlayer()
{
    return colorToPlayer;
}

void GameData::setColorToPlayer(const QMap<Color, Player> &newColorToPlayer)
{
    colorToPlayer = newColorToPlayer;
}
