#ifndef READYTOSTART_H
#define READYTOSTART_H

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
#include<QVector>
#include"player/player.h"

class readyToStart : public QDialog
{
    Q_OBJECT

public:
    readyToStart(QTcpSocket*sock,QWidget *parent = nullptr);

    Player *getPlayer() const;
    void setPlayer(Player *newPlayer);

private slots:
    void sendMessage();
    void read();

private:
    QTcpSocket *tcpSocket = nullptr;
    QPushButton*ok,*cancel;
    Player* player;
    bool inGraphics = false;
};
#endif // READYTOSTART_H
