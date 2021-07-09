#include "bankthread.h"
#include <QtNetwork>

BankThread::BankThread(Player* _player,int socketDescriptor, QObject *parent)

    :QThread(parent), socketDescriptor(socketDescriptor)
{
    player = _player;


}

BankThread::~BankThread()
{
    delete tcpSocket;
    delete player;
}



void BankThread::respone(QJsonObject message )
{
    if(message["kind"] == "SignUp"){
        signUp(message);
        return ;
    }
    if(message["kind"] == "LogIn"){
        logIn(message);
        return ;
    }

}

void BankThread::run()
{

    qDebug() << socketDescriptor << " started";
    tcpSocket = new QTcpSocket;
//    if (!tcpSocket->setSocketDescriptor(socketDescriptor)) {
//        emit error(tcpSocket->error());
//        return;
//    }

       tcpSocket->setSocketDescriptor(socketDescriptor);
       connect(tcpSocket,&QTcpSocket::readyRead,this,&BankThread::readyRead,Qt::DirectConnection);
       connect(tcpSocket,&QTcpSocket::disconnected,this,&BankThread::disconnected,Qt::DirectConnection);

       exec();



}

void BankThread::signUp(QJsonObject message)
{
    PlayersFile pf;
    QJsonObject jsObj;
   if( pf.addPlayer(&message))
   {
       jsObj["kind"] = "SignUp";
       jsObj["success"] = true;
       sendJson(message);
       return;
   }
       jsObj["kind"] = "SignUp";
       jsObj["success"] = false;
       jsObj["errorMessage"] = "invalid request";
       sendJson(message);



}

void BankThread::logIn(QJsonObject message)
{

}

void BankThread::sendJson(QJsonObject message)
{
    QJsonDocument jsDoc;
    jsDoc.setObject(message);
    tcpSocket->write(jsDoc.toJson());
}

void BankThread::readyRead()
{
    QString message = tcpSocket->readAll();
    qDebug() << "data recieved" << message;




    QJsonDocument doc = QJsonDocument::fromJson(message.toUtf8());
    respone(doc.object());

}

void BankThread::disconnected()
{
    qDebug() << "disconnected";
    tcpSocket->deleteLater();
    exit(0);
}
