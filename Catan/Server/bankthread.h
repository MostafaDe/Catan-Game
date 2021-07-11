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
    BankThread(Player *player,int socketDescriptor, QObject *parent);
  ~BankThread();

    void respone(QJsonObject message);
    void run() override;


    void  sendJson(QJsonObject message);
signals:
    void readyPlay();
    void signUp(QJsonObject message,int socketDecriptor);
    void logIn(QString username,QString Password,int socketDescriptor);
    void cancelReadyPlay();
public slots:
    void readyRead();
    void disconnected();
    void startGame();
    void setMessage(QJsonObject message,int _socketDescriptor);


signals:
    void error(QTcpSocket::SocketError socketError);


private:
    int socketDescriptor;
    QString text;
    QTcpSocket* tcpSocket;
    Player* player;
    QJsonObject message;

};

#endif // BANKTHREAD_H
