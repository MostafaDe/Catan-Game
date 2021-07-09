//
// Created by apadana on ۰۵/۰۷/۲۰۲۱.
//

#ifndef PLAYERS_BANK_H
#define PLAYERS_BANK_H

#include <QTcpServer>

#include<QJsonDocument>
#include<QJsonObject>


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




protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:

    QMap<QTcpSocket*,Player*> socketToPlayers;



};



#endif //PLAYERS_BANK_H
