//
// Created by apadana on ۰۵/۰۷/۲۰۲۱.
//

#ifndef PLAYERS_BANK_H
#define PLAYERS_BANK_H

#include <QTcpServer>

#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include"FileHandling/playersfile.h"
#include<QTcpSocket>
#include <QThread>
#include<QMap>
#include<QPair>
#include"bankthread.h"
#include"Player/player.h"
#include"game.h"
class Bank: public QTcpServer{
    Q_OBJECT

public:
    Bank  (QObject *parent = nullptr);
    void startServer();
    void startTheGame();
    void stopTheGame();





public slots:

  void signUp(QJsonObject message,int socketDescriptor);
  void logIn(QString username , QString password,int socketDescriptor);
  void addReadyToPlayNumber(int socketDescriptor,QString username);
  void lowerReadyToPlayNumber(int socketDescriptor);
  void logOut(QString username);
  void gaming(QJsonObject message,int socketDescriptor);



signals:
  void  sendMessage(QJsonObject message,int socketDescriptor);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:

       PlayersFile file;
       unsigned int readyToPlayNumbers = 0;
       int multiPlayerMode = 3;

       QVector<QPair<int,Player>> socketToPlayerList;

       Game* game;

};



#endif //PLAYERS_BANK_H
