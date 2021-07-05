//
// Created by apadana on ۰۵/۰۷/۲۰۲۱.
//

#include "SignUp.h"
#include <QtWidgets>
#include <QtNetwork>
SignUp::SignUp(QWidget *parent)
{
//connectToServer();


//connect(tcpSocket, &QIODevice::readyRead, this, &SignUp::read);
//connect(tcpSocket, &QAbstractSocket::errorOccurred,
//        this, &SignUp::displayError);


}
void SignUp::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(tcpSocket->errorString()));
    }


}
void SignUp::connectToServer()
{



    tcpSocket->connectToHost(QHostAddress::LocalHost,
                             8080);

}
void SignUp::read()
{

    in.startTransaction();

    QString nextFortune;
    in >>  nextFortune;
    if (!in.commitTransaction())
        return;

    if (nextFortune == currentFortune) {

//        QTimer::singleShot(0, this, &Client::requestNewFortune);
        return;
    }

    currentFortune = nextFortune;

}
