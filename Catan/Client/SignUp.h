#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QTcpSocket>
#include<QByteArray>
#include<QJsonArray>
#include<QJsonObject>
#include<QLineEdit>
#include <QDataStream>
#include<QHostAddress>
#include<QMessageBox>
#include<QLabel>
#include<QGridLayout>
#include<QPushButton>
#include<QDialogButtonBox>
#include<QGuiApplication>
#include<QJsonDocument>

#include"Player/player.h"

class signUp :public QDialog
{
    Q_OBJECT

public:
    signUp(QWidget *parent = nullptr);


    Player *getPlayer() const;
    void setPlayer(Player *newPlayer);

private slots:
    void connectToServer();
    void enableOkButton();
    void read();

private:
    QTcpSocket *tcpSocket = nullptr;
    QLineEdit* name,*lastName,*password,*userName;
    QPushButton*ok,*cancel;
    Player* player;

};
#endif // SIGNUP_H
