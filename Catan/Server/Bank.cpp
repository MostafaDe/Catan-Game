//
// Created by apadana on ۰۵/۰۷/۲۰۲۱.
//

#include "Bank.h"
#include <QRandomGenerator>
#include <stdlib.h>
#include"bankthread.h"
Bank::Bank(QObject *parent)
{
    QJsonObject jo;
    jo["ali"] = "12346";
    jo["hassan"] = "45645";
    QJsonDocument jsDoc(jo);
    QString jsString = QString::fromLatin1(jsDoc.toJson());

   fortunes << jsString;
}

void Bank::incomingConnection(qintptr socketDescriptor)
{
    QString fortune = fortunes.at(QRandomGenerator::global()->bounded(int(fortunes.size())));
    BankThread *thread = new BankThread(socketDescriptor, fortune, this);
    connect(thread, &BankThread::finished, thread, &BankThread::deleteLater);
    thread->start();
}
