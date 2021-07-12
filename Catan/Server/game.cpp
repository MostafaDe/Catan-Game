#include "game.h"



Game::Game(QVector<Player> _players)
{
players = _players;


}

QJsonObject Game::doSomething(QJsonObject message, QVector<int> &socketDescriptors)
{
    QJsonObject jsObj;
    return jsObj;
}

QJsonObject Game::stopGame(QVector<int> &socketDescriptors)
{
    QJsonObject jsObj;
    return jsObj;
}

QJsonObject Game::getBoardInformation(QVector<int> &socketDescriptors)
{

    QJsonObject jsObj;
    return jsObj;

}
