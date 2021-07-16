#include "bankthread.h"
#include <QtNetwork>
#include"banksource.h"
BankThread::BankThread(int socketDescriptor, QObject *parent)

    :QThread(parent), socketDescriptor(socketDescriptor)
{


}

BankThread::~BankThread()
{


}



void BankThread::respone(QJsonObject message )
{
    if(message["kind"] == "SignUp"){
        emit signUp(message,socketDescriptor);


        return ;
    }
    if(message["kind"] == "LogIn"){
        emit logIn(message["username"].toString(),message["password"].toString(),socketDescriptor);

        username =message["username"].toString();
        return;
    }
    if(message["kind"] == "ReadyToPlay"){
        readyToPlaying = true;
        emit readyPlay(socketDescriptor,username);
        return;
    }
    if(message["kind"] == "Game"){
        readyToPlaying = true;
        emit gaming(message,socketDescriptor);
        return;
    }
    else{
        QJsonObject js;
        js["kind"] = "invalid request";
        sendJson(js);
        return;
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
    sleep(2);
    while(preMessage == this->message)
        sleep(1);
    sendJson(this->message);
    preMessage = this->message;

}

void BankThread::disconnected()
{
    qDebug() << "disconnected";
    if(readyToPlaying)
        emit notReadyPlay(socketDescriptor);
//    if(logedin)
        emit logOut(username);
    tcpSocket->deleteLater();
    exit(0);
}

//void BankThread::startGame()
//{

//}

void BankThread::setMessage(QJsonObject _message,int _socketDescriptor)
{
    static int numberOfMessage = 0;
    numberOfMessage++;
    _message["numberOfMessage"] = numberOfMessage;
    if(socketDescriptor == _socketDescriptor){
    qDebug() << _message;
    message = _message;
}
    return;
}


