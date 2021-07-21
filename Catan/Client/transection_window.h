#ifndef TRANSECTION_WINDOW_H
#define TRANSECTION_WINDOW_H

#include<QDialog>
#include<QTcpSocket>
#include<QPushButton>
#include<QObject>

class transection_window:public QDialog
{
    Q_OBJECT
public:
    transection_window(QTcpSocket*sock,QString userName,int sheepG,int sheepT,int wheatT,int wheatG,int treeT,int treeG,int rockG,int rockT,int brickT,int brickG,QWidget*parent);

private:
    QPushButton*ok,*cancel;
    QTcpSocket*tcpSocket;
    void send_message(QJsonObject o);

public slots:
    void clicked_ok();
    void clicked_cancel();
};

#endif // TRANSECTION_WINDOW_H
