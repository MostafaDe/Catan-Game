//
// Created by apadana on ۰۵/۰۷/۲۰۲۱.
//

#include "Bank.h"






Bank::Bank(QObject *parent)

{
//    QJsonObject jo;
//    jo["ali"] = "12346";
//    jo["hassan"] = "45645";
//    QJsonDocument jsDoc(jo);
//    QString jsString = QString::fromLatin1(jsDoc.toJson());

//    fortunes << jsString;


}

void Bank::startServer()
{
    if(!this->listen(QHostAddress::Any,8080))
        qDebug()<< "couldnt start server";
    else{
         qDebug()<< "start server";
    }
}


void Bank::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *socket = new QTcpSocket;

    socket->setSocketDescriptor(socketDescriptor);
    Player* player = new Player;
    socketToPlayers[socket] = player;
    qDebug() << "new connection";
    BankThread * bankTh = new BankThread(player,socketDescriptor,this);
    connect(bankTh,&QThread::finished,bankTh,&QThread::deleteLater);
    bankTh->start();

//static int i =0;
//i++;
//qDebug() << hasPendingConnections();

//    QPointer<QTcpSocket> tcpSocket = new QTcpSocket;


//    tcpSocket->setSocketDescriptor(socketDescriptor);

//    connect(tcpSocket, &QAbstractSocket::disconnected,
//            tcpSocket, &QObject::deleteLater);

//    connect(tcpSocket, &QAbstractSocket::destroyed,
//            this, &Bank::deleteSocket);
//    socketToPlayer[tcpSocket] = Player();


//    if(countOfLogedInPlayers() == 3){
//        #ifdef Q_OS_WIN // windows
//            Sleep(uint(TIME_TO_WAIT));
//        #else // linux,...
//            struct timespec ts = { TIME_TO_WAIT / 1000, (TIME_TO_WAIT % 1000) * 1000 * 1000 };
//            nanosleep(&ts, NULL);
//        #endif
//          if(countOfLogedInPlayers() == 3){
//           emit gameStarted(true);
//           return;
//          }
//    }




}








