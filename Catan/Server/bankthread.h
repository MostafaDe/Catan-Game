#ifndef BANKTHREAD_H
#define BANKTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include<QJsonObject>
#include"FileHandling/playersfile.h"
#include"Player/player.h"

class BankThread

:public QThread {
    Q_OBJECT

public:
    BankThread(int socketDescriptor, QObject *parent);
  ~BankThread();

    void respone(QJsonObject message);
    void run() override;


    void  sendJson(QJsonObject message);
signals:
    void readyPlay(int socketDescriptor,QString username);
    void notReadyPlay(int socketDescriptor);
    void signUp(QJsonObject message,int socketDecriptor);
    void logIn(QString username,QString Password,int socketDescriptor);
//    void cancelReadyPlay();
    void logOut(QString username);
    void gaming(QJsonObject message,int socketDescriptor);
public slots:
    void readyRead();
    void disconnected();
//    void startGame();
    void setMessage(QJsonObject message,int _socketDescriptor);


signals:
    void error(QTcpSocket::SocketError socketError);
    void readyToPlay();


private:
    int socketDescriptor;
    QString text;
    QTcpSocket* tcpSocket;
    QString username;
    QJsonObject message;
    QJsonObject preMessage;
    bool readyToPlaying = false;

//    bool logedinB = false;
//    bool signUpB = false;
//    bool logoutB = false;
//    bool gamingB = false;


};

#endif // BANKTHREAD_H
