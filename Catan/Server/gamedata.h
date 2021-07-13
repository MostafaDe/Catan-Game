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

    Board *getBoard() const;
    void setBoard(Board *newBoard);

    static const QMap<Color, Player> &getColorToPlayer();
    static void setColorToPlayer(const QMap<Color, Player> &newColorToPlayer);

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
    static QMap<Color,Player> colorToPlayer;

//    Q_PROPERTY(int countOfMonopolyCards READ getCountOfMonopolyCards CONSTANT)
};

#endif // GAMEDATA_H
