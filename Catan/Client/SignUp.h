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
#include"FirstPage.h"

class signUp :public QDialog
{
    Q_OBJECT

public:
    signUp(QWidget *parent = nullptr);

private slots:
    void sendMessage();
    void enableOkButton();
    void read();

private:
    QTcpSocket *tcpSocket = nullptr;
    QLineEdit* name,*lastName,*password,*userName;
    QPushButton*ok,*cancel;
    QLabel* error_label;
};
#endif // SIGNUP_H
