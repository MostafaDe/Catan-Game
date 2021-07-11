#include "bankthread.h"
#include <QtNetwork>
#include"banksource.h"
BankThread::BankThread(Player* _player,int socketDescriptor, QObject *parent)

    :QThread(parent), socketDescriptor(socketDescriptor)
{
    player = _player;

}

BankThread::~BankThread()
{

    delete player;
}



void BankThread::respone(QJsonObject message )
{
    if(message["kind"] == "SignUp"){
        emit signUp(message,socketDescriptor);


        return ;
    }
    if(message["kind"] == "LogIn"){
        emit logIn(message["username"].toString(),message["password"].toString(),socketDescriptor);


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
    sleep(1);
    sendJson(this->message);

}

void BankThread::disconnected()
{
    qDebug() << "disconnected";
    tcpSocket->deleteLater();
    exit(0);
}

void BankThread::startGame()
{

}

void BankThread::setMessage(QJsonObject _message,int _socketDescriptor)
{
    if(socketDescriptor == _socketDescriptor){
    qDebug() << _message;
    message = _message;
}
    return;
}


