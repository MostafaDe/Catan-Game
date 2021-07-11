//
// Created by apadana on ۰۵/۰۷/۲۰۲۱.
//

#ifndef PLAYERS_BANK_H
#define PLAYERS_BANK_H

#include <QTcpServer>

#include<QJsonDocument>
#include<QJsonObject>

#include"FileHandling/playersfile.h"
#include<QTcpSocket>
#include <QThread>
#include<QMap>
#include"bankthread.h"
#include"Player/player.h"
class Bank: public QTcpServer{
    Q_OBJECT

public:
    Bank  (QObject *parent = nullptr);
    void startServer();





public slots:

  void signUp(QJsonObject message,int socketDescriptor);
  void logIn(QString username , QString password,int socketDescriptor);

signals:
  void  sendMessage(QJsonObject message,int socketDescriptor);
protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:

       PlayersFile file;


};



#endif //PLAYERS_BANK_H
