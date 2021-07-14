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
#include"Client/readyToStart.h"

class LogIn : public QDialog
{
    Q_OBJECT

public:
    LogIn(QWidget *parent = nullptr);

private slots:
    void sendMessage();
    void enableOkButton();
    void read();

private:
    QTcpSocket *tcpSocket = nullptr;
    QLineEdit*password,*userName;
    QPushButton*ok,*cancel;
    QLabel* error_label;
    bool startGame = false;
};
#endif // LOGIN_H
