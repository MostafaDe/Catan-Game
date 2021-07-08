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


class signUp :public QDialog
{
    Q_OBJECT

public:
    signUp(QWidget *parent = nullptr);

private slots:
    void connectToServer();
    void enableOkButton();

private:
    QTcpSocket *tcpSocket = nullptr;
    QLineEdit* name,*lastName,*password,*userName;
    QPushButton*ok,*cancel;
    void read();
};
#endif // SIGNUP_H
