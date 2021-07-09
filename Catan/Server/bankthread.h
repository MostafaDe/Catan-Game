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
    void signUp(QJsonObject message);
    void logIn(QJsonObject message);
    void  sendJson(QJsonObject message);
public slots:
    void readyRead();
    void disconnected();
signals:
    void error(QTcpSocket::SocketError socketError);

private:
    int socketDescriptor;
    QString text;
    QTcpSocket* tcpSocket;
    Player* player;

};

#endif // BANKTHREAD_H
