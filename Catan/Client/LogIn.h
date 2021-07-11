#ifndef LOGIN_H
#define LOGIN_H

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

class LogIn : public QDialog
{
    Q_OBJECT

public:
    LogIn(QWidget *parent = nullptr);

    Player *getPlayer() const;
    void setPlayer(Player *newPlayer);
private slots:
    void sendMessage();
    void enableOkButton();
    void read();

private:
    QTcpSocket *tcpSocket = nullptr;
    QLineEdit*password,*userName;
    QPushButton*ok,*cancel;
    Player* player;
    QLabel* error_label;

};
#endif // LOGIN_H
