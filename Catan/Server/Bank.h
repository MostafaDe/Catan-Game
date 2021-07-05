//
// Created by apadana on ۰۵/۰۷/۲۰۲۱.
//

#ifndef PLAYERS_BANK_H
#define PLAYERS_BANK_H
#include <QStringList>
#include <QTcpServer>

#include<QJsonDocument>
#include<QJsonObject>

class Bank: public QTcpServer{
    Q_OBJECT

public:
    Bank  (QObject *parent = nullptr);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    QStringList fortunes;
};



#endif //PLAYERS_BANK_H
