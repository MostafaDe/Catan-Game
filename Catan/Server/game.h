#ifndef GAME_H
#define GAME_H
#include"Player/player.h"
#include"Board/Board.h"
#include"Board/Board1.h"
#include<QVector>
#include<QJsonDocument>
#include<QJsonObject>
class Game
{
public:
    Game(QVector<Player> _players);
    QJsonObject doSomething(QJsonObject message,QVector<int>& socketDescriptors);
    QJsonObject stopGame(QVector<int>& socketDescriptors);
    QJsonObject getBoardInformation(QVector<int>& socketDescriptors);

private:
    QVector<Player> players;
    Board* board;

};

#endif // GAME_H
