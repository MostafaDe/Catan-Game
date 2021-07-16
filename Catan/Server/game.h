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
    QJsonObject endOfTurn(QJsonObject message ,QVector<int>& socketDescriptors);




private:


    int socketOfDealer = -1;// the player who uses transacrion to player in his turn
    QVector<int> waitingForSocketsResponse;
    QJsonObject transactionMessage;
    bool socketExistInListOfSockets(int socket,const QVector<int>& waitingForSocketsResponse);
    void  removeThisSocketFromSocketList(int socket, QVector<int>& waitingForSocketsResponse);// implement this
    void  makeDealWithTwoSockets(QJsonObject transactionMessage,int socketDealer,int socketBuyer);// implement this
    QMap<int,Player> makeColorToPlayerToSocketToPlayer();
    int getSocketOfPlayingPlayer();
    QString convertColorToString(Color color);// implement this
    bool playerCanEfordIt(QString building,Color colorOfPlayer,bool fromCards);// implement this
    void appendAllSocketsToVector(QVector<int>& sockets);// implement this
    void setWhoStartsGame();
    int multiPlayerMode;
    map<int,Color> intToColor;
    int gameFlow = 0;
    QMap<int,int> socketToSumOfdices;
    Dice dice;

};


#endif // GAME_H
//Color::Red
// Color numeOfColor = Color::;
