//
// Created by apadana on ۰۵/۰۷/۲۰۲۱.
//

#ifndef PLAYERS_SIGNUP_H
#define PLAYERS_SIGNUP_H

#include "Player/player.h"
#include "RequestAndResopnse/ReqARes.h"

QT_BEGIN_NAMESPACE
class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
QT_END_NAMESPACE
#include <QList>
#include <QFile>
#include<QJsonDocument>
#include<QJsonObject>
#include<QFile>
#include<QByteArray>
#include<QJsonArray>
#include<QJsonObject>
#include<QDialog>
#include"Player/player.h"
class SignUp :public QDialog{
Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);

private slots:
    void connectToServer();
    void read();
    void displayError(QAbstractSocket::SocketError socketError);

private:


    QTcpSocket *tcpSocket = nullptr;
    QDataStream in;
    QString currentFortune;
    QJsonObject message;



};



#endif //PLAYERS_SIGNUP_H
