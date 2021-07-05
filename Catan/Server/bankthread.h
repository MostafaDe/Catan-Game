#ifndef BANKTHREAD_H
#define BANKTHREAD_H

#include <QThread>
#include <QTcpSocket>
class BankThread

:public QThread {
    Q_OBJECT

public:
    BankThread(int socketDescriptor, const QString &fortune, QObject *parent);

    void run() override;

signals:
    void error(QTcpSocket::SocketError socketError);

private:
    int socketDescriptor;
    QString text;
};

#endif // BANKTHREAD_H
