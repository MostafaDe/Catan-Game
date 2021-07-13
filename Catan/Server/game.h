#ifndef GAME_H
#define GAME_H
#include"Player/player.h"
#include"Board/Board.h"
#include"Board/Board1.h"
#include<QVector>
#include<QJsonDocument>
#include<QJsonObject>
#include"Board/Board1.h"
class Game
{
public:
    Game();
    QJsonObject winner(bool& iswinner,QVector<int>& socketDescriptors);
    QJsonObject stopGame(QVector<int>& socketDescriptors);
    QJsonObject getBoardInformation(QVector<int>& socketDescriptors);
    QJsonObject buildHouse(QJsonObject message ,QVector<int>& socketDescriptors);
    QJsonObject buildRoad(QJsonObject message ,QVector<int>& socketDescriptors);
    QJsonObject buildBridge(QJsonObject message ,QVector<int>& socketDescriptors);
    QJsonObject transaction(QJsonObject message ,QVector<int>& socketDescriptors);
    QJsonObject buyCard(QJsonObject message ,QVector<int>& socketDescriptors);
    QJsonObject playCard(QJsonObject message ,QVector<int>& socketDescriptors);
    QJsonObject endOfTurn(QJsonObject message ,QVector<int>& socketDescriptors);
    QJsonObject movingThief(QJsonObject message ,QVector<int>& socketDescriptors);



private:


};


#endif // GAME_H
//Color::Red
// Color numeOfColor = Color::;
