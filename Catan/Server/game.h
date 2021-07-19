#ifndef GAME_H
#define GAME_H
#include"Player/player.h"
#include"Board/Board.h"
#include"Board/Board1.h"
#include<QVector>
#include<vector>
#include<QJsonDocument>
#include<QJsonObject>
#include"Board/Board1.h"
#include<QJsonArray>
#include"gamedata.h"
#include"RoulsOfBuildHome.h"
#include"RoulsOfBiuldRoad.h"
#include"RoulOfBuildBigCity.h"
#include"Tranlate.h"
#include"dice.h"
#include"AllocateResources.h"
using namespace std;
class Game
{
public:
    Game();
    QJsonObject winner(bool& iswinner,QVector<int>& socketDescriptors);
    QJsonObject stopGame(QVector<int>& socketDescriptors);
    QJsonObject getBoardInformation(QVector<int>& socketDescriptors);
    QJsonObject buildHouse(QJsonObject message ,QVector<int>& socketDescriptors);
    QJsonObject buildRoad(QJsonObject message ,QVector<int>& socketDescriptors);
    QJsonObject buildBigCity(QJsonObject message ,QVector<int>& socketDescriptors);
    QJsonObject transactionToPlayers(QJsonObject message ,QVector<int>& socketDescriptors);
    QJsonObject responseToTransactionToPlayers(QJsonObject message ,QVector<int>& socketDescriptors);
    QJsonObject transactionToBank(QJsonObject message ,QVector<int>& socketDescriptors);
    QJsonObject endOfTurn(QVector<int> &sockets);




    void setGameFlow(int newGameFlow);

private:


    int socketOfDealer = -1;
    QVector<int> waitingForSocketsResponse;
    QJsonObject transactionMessage;
    bool socketExistInListOfSockets(int socket,const QVector<int>& waitingForSocketsResponse);
    void  removeThisSocketFromSocketList(int socket, QVector<int>& waitingForSocketsResponse);
    void  makeDealWithTwoSockets(QJsonObject transactionMessage,int socketDealer,int socketBuyer);
    QMap<int,Player> makeColorToPlayerToSocketToPlayer();
    int getSocketOfPlayingPlayer();
    QString convertColorToString(Color color);
    bool playerCanEfordIt(QString building,Color colorOfPlayer);
    bool playerCanEfordTransaction(QJsonObject jsDeal,int socket);
    bool playerCanEfordTransactionToPlayers(QJsonObject jsDeal,int socket);
    void appendAllSocketsToVector(QVector<int>& sockets);
    void setWhoStartsGame();
    int multiPlayerMode;
    map<int,Color> intToColor;
    int gameFlow = 0;
    QMap<int,int> socketToSumOfdices;
    Dice dice;
    bool checkExtraConditionForTransaction(QJsonObject deal);
    bool checkSomeConditionForBuildingHouse(Color color);
    bool checkExtraConditionForEndOfTurn(Color color);

    AllocateResources alR;

};


#endif // GAME_H
//Color::Red
// Color numeOfColor = Color::;
